"""Concrete sprite allocation / GBA VRAM checks, independent of artistic approval."""
import json
import re
import unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
class TestSpriteHardware(unittest.TestCase):
 def test_obj_ranges_and_alignment(self):
  hdr=(ROOT/'src/assets.h').read_text()
  defs={k:int(v) for k,v in re.findall(r'#define (OBJ_\w+) (\d+)',hdr)}
  self.assertEqual(defs['OBJ_WAYFARER'],0)
  self.assertEqual(defs['OBJ_MAERA'],96)
  self.assertEqual(defs['OBJ_KITH'],128)
  self.assertEqual(defs['OBJ_SHADE'],defs['OBJ_KITH']+4*16)
  self.assertEqual(defs['OBJ_SLASH'],defs['OBJ_SHADE']+2*4)
  self.assertEqual(defs['OBJ_MAERA_PORTRAIT'],defs['OBJ_SLASH']+2*4)
  self.assertEqual(defs['OBJ_TILE_COUNT'],defs['OBJ_MAERA_PORTRAIT']+3*16)
  self.assertLessEqual(defs['OBJ_TILE_COUNT']*32,32768)
 def test_actual_cc0_4bpp_and_palette_bytes(self):
  for name in ['garden_tree','stone_well','fountain','small_shrub','carved_column']:
   d=ROOT/'assets/third_party'
   meta=json.loads((d/(name+'.json')).read_text())
   w,h=meta['padded_size_px']
   self.assertEqual(len((d/(name+'.4bpp')).read_bytes()),w*h//2)
   self.assertEqual(len((d/(name+'.pal.bin')).read_bytes()),32)
 def test_save_signature_is_in_actual_rom(self):
  self.assertIn(b'SRAM_V113',(ROOT/'build/vaelora_bellhaven_v05.gba').read_bytes())
 def test_main_uses_generated_tile_offsets(self):
  s=(ROOT/'src/main.c').read_text()
  for name in ['OBJ_WAYFARER','OBJ_KITH','OBJ_MAERA_PORTRAIT','OBJ_SHADE','OBJ_SLASH']:
   self.assertIn(name,s)
