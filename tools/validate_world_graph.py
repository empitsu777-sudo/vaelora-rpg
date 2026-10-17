#!/usr/bin/env python3
"""Validate the proposed 18-town/24-route Vaelora graph; stdlib only.
Usage: python tools/validate_world_graph.py [data/world/routes_v01.json]
This checks design-data consistency, NOT playable map geometry.
"""
import json
import sys
from collections import Counter
from pathlib import Path

REGIONS = ("SH", "SC", "IW", "TC", "AW", "SB")
FLAGS = ("broken_bell_cleared", "returning_tide_cleared",
         "buried_magnet_cleared", "night_bloom_cleared",
         "open_sky_cleared", "unheard_crown_cleared")
TOWNS = {f"{r}{i}" for r in REGIONS for i in range(1, 4)}

def reachable(routes, active):
    seen = {"SH1"}
    while True:
        old = len(seen)
        for edge in routes:
            if set(edge["requires"]) <= set(active):
                if edge["a"] in seen or edge["b"] in seen:
                    seen.update((edge["a"], edge["b"]))
        if len(seen) == old:
            return seen

def validate(data):
    errors = []
    routes = data.get("routes", [])
    if len(routes) != 24: errors.append(f"expected 24 routes, got {len(routes)}")
    ids = [r.get("id") for r in routes]
    if len(set(ids)) != len(ids): errors.append("duplicate route IDs")
    if data.get("start") != "SH1": errors.append("start must be SH1")
    if data.get("sanctum_flags") != list(FLAGS): errors.append("sanctum clear order differs")
    for e in routes:
        if e.get("a") not in TOWNS or e.get("b") not in TOWNS or e.get("a") == e.get("b"):
            errors.append(f"invalid endpoints: {e.get('id')}")
        if e.get("role") not in ("main", "shortcut"): errors.append(f"invalid role: {e.get('id')}")
        if not isinstance(e.get("requires"), list): errors.append(f"invalid gate: {e.get('id')}")
    if errors: return errors
    if set(x for e in routes for x in (e["a"],e["b"])) != TOWNS:
        errors.append("not all 18 settlements appear in graph")
    if Counter(e["role"] for e in routes) != Counter({"main":18, "shortcut":6}):
        errors.append("expected 18 main and six shortcut routes")
    internal = sum(e["a"][:2] == e["b"][:2] for e in routes)
    if internal != 12: errors.append(f"expected 12 internal routes, got {internal}")
    for k in range(6):
        actual = reachable(routes, FLAGS[:k])
        expected = set(f"{r}{i}" for r in REGIONS[:k+1] for i in range(1,4))
        if actual != expected:
            errors.append(f"chapter {k}: reachable {sorted(actual)} != {sorted(expected)}")
    if reachable(routes, FLAGS) != TOWNS: errors.append("final world not connected")
    for e in routes:
        if e["role"] == "shortcut" and not e["requires"]:
            errors.append(f"shortcut {e['id']} is ungated")
    return errors

def main(path):
    data = json.loads(Path(path).read_text(encoding="utf-8"))
    issues = validate(data)
    for issue in issues: print("FAIL:", issue)
    if not issues: print("PASS: 18 settlements, 24 routes, six chapter reachability states")
    return int(bool(issues))

if __name__ == "__main__":
    path = sys.argv[1] if len(sys.argv) > 1 else "data/world/routes_v01.json"
    raise SystemExit(main(path))
