#!/usr/bin/env python3
"""Validate original GBA 4bpp OBJ sheets. Requires Pillow.
Run: python tools/validate_sprites.py assets/sprites/manifest.json
Format checks are NOT artistic or emulator approval.
"""
import argparse
import json
from pathlib import Path
from PIL import Image

SIZES = {(8,8),(16,16),(32,32),(64,64),(16,8),(32,8),(32,16),(64,32),(8,16),(8,32),(16,32),(32,64)}

def check_sprite(s, root):
    name = s.get("id", "<unnamed>")
    required = ("file","frame_width","frame_height","columns","rows","palette_bank")
    missing = [k for k in required if k not in s]
    if missing:
        return [f"{name}: missing keys {', '.join(missing)}"]
    w,h,c,r = (s[k] for k in ("frame_width","frame_height","columns","rows"))
    if not all(isinstance(x,int) and not isinstance(x,bool) and x>0 for x in (w,h,c,r)):
        return [f"{name}: frame size, rows and columns must be positive integers"]
    errors = []
    if (w,h) not in SIZES:
        errors.append(f"{name}: {w}x{h} not a legal single GBA OBJ size")
    bank = s["palette_bank"]
    if not isinstance(bank,int) or not 0 <= bank <= 15:
        errors.append(f"{name}: palette_bank must be 0..15")
    path=Path(s["file"])
    if path.is_absolute() or ".." in path.parts:
        return errors + [f"{name}: asset path must be relative"]
    file=(root/path).resolve()
    if not file.is_file():
        return errors + [f"{name}: file not found: {path}"]
    with Image.open(file) as im:
        if im.format!="PNG":
            errors.append(f"{name}: expected PNG, got {im.format}")
        if im.mode!="P":
            errors.append(f"{name}: expected indexed PNG (mode P), got {im.mode}")
        if im.size!=(w*c,h*r):
            errors.append(f"{name}: sheet size {im.size}, expected {(w*c,h*r)}")
        if im.mode=="P":
            pixels=im.get_flattened_data() if hasattr(im,"get_flattened_data") else im.getdata()
            used=set(pixels)
            if max(used,default=0)>15:
                errors.append(f"{name}: 4bpp requires palette indices 0..15, used {max(used)}")
            alpha=im.info.get("transparency")
            ok = alpha==0 if isinstance(alpha,int) else isinstance(alpha,bytes) and bool(alpha) and alpha[0]==0
            if not ok:
                errors.append(f"{name}: PNG palette index 0 must be transparent")
    if s.get("origin")!="original":
        errors.append(f"{name}: origin must be 'original'")
    return errors

def validate(manifest, root):
    data=json.loads(Path(manifest).read_text(encoding="utf-8"))
    if data.get("schema_version")!=1: return ["manifest: schema_version must be 1"]
    if not isinstance(data.get("sprites"),list): return ["manifest: sprites must be a list"]
    errors=[]; names=set()
    for s in data["sprites"]:
        if not isinstance(s,dict):
            errors.append("manifest: all entries must be objects"); continue
        if s.get("id") in names: errors.append(f"manifest: duplicate id {s.get('id')}")
        names.add(s.get("id"))
        errors.extend(check_sprite(s,root))
    return errors

if __name__=="__main__":
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("manifest",type=Path)
    ap.add_argument("--root",type=Path,default=Path.cwd())
    a=ap.parse_args()
    issues=validate(a.manifest,a.root)
    for issue in issues: print("FAIL:",issue)
    if not issues: print("PASS: indexed sprite dimensions, palette and provenance; visual quality NOT verified")
    raise SystemExit(1 if issues else 0)
