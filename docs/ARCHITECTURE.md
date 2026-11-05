# Bellhaven — Python-First Hybrid Runtime Contract

**Status:** design/implementation target. Existing prototype partially implements this but is **not gameplay-verified**.

## Single spatial truth

Use the approved 48×36 planning grid (16×16 planning cells) and 8 interior grids, but match the rendered artwork through a **visual alignment tool**. Baked images are not collision maps by themselves. The painter and collision editor must share a transformation between world pixel `(x,y)` and game map location. Never infer collision from arbitrary tile codes once the art has diverged from the grid. Use a feet-anchored (not torso-anchored) player collision shape.

## Layers, in draw order

1. **Baked static scenery:** approved original town art, architecture, fixed roofs, bridges, ground, vegetation, waterbanks and interior furniture silhouettes.
2. **Semantic world mask:** per-pixel or fine-resolution walk polygons rasterized to a shared collision data structure; distinguishing `SOLID`, `WALKABLE`, `WATER`, `STAIRS`, `BRIDGE`, `EXIT`, `OCCLUDE`. A multi-tile building exterior cannot be crossed regardless of decorative pixel colors. Debug overlays must show exactly the mask used by runtime.
3. **Trigger/hotspot manifests:** immutable ids, map ids, world/approach coordinates, facing, radius, accessible stand point, dialogue/action id, priority, progression guards. A trigger must correspond to an obvious visual affordance. Door has both outside stand position and inside spawn/return point.
4. **Animated overlays:** deterministic frame sequences (fountain, water, lamps, chimney smoke, fae glow), finite bounding rectangles and optional local palette treatment. No blanket animated clutter.
5. **Player/NPC/pet sprites:** consistent world scale, feet depth sort and foreground occlusion; walk animations tied to distance moved, not a fixed sprite tick independent of motion. Static baked villagers cannot additionally spawn live sprites at the same position.
6. **UI layer:** on-demand small interact prompt and readable dialogue box constrained to 240×160, without permanent screen-filling debug text.

## Data interchange

One validated machine-readable source should drive Python and C generation. Proposed files: `scene.json`, `collision.rle`/mask, `doors.json`, `hotspots.json`, `actors.json`, `ambient.json`, `sprite_manifest.json`; generated C tables are outputs, not a second editable truth. Include artwork provenance/license and a SHA-256 manifest. Scene renderer and GBA use *the same* world coordinates and interaction precedence.

## Runtime rules

- Python desktop frontend is a **debuggable playtest harness**, not a real GBA emulator. Prefer the already shared `world.c` simulation; avoid maintaining separate logic.
- True GBA target: ARMv4T, native 240×160, RGB555 and correct VRAM/OAM allocation. Mode 4 8-bit indexed bitmap may be retained if it passes actual VRAM, palette, cartridge and sprite compositing checks. Do not transfer PC-only memory assumptions to the GBA.
- Movement: independent from frame rendering, deterministic input handling, correct speed when held; interpolate character/camera position over a tile without sweeping through solids. Interaction only when standing on an accessible approach spot and facing the object. Track actual physics bounds.

## Validation examples

- Draw a test path into the Copper Kettle Inn roof, cliff edge, tree trunk, fountain and river: each MUST stop at physical bounds in **Python and mGBA**.
- Approach every painted doorway from the normal town spawn and press A: MUST open the expected room; leave room and return to the correct exterior foot point.
- Start a conversation with an NPC placed on an open path, not a bush/roof: correct dialogue text and closing behavior; screen remains legible.
- Record held-key locomotion at 59.73 Hz and evaluate elapsed time and walk cycle by frames; no sluggishness or unnatural frame stutter.
- Validate display, art scale and text at genuine **1× 240×160** and again enlarged by nearest-neighbor for review.

## Known discrepancy

The Bellhaven baked illustration was generated independently of the 48×36 walkable grid; Patch 04 added coarse artist-annotated rectangles rather than a comprehensive art-aligned mask. This is the current top priority and cannot be closed by marking generic grid reachability as passed.