# Vaelora Sprite Reference Audit — 2026-10-16
**Status:** research. Five user-supplied images inspected; references remain outside the repository.

## Findings by image
| Reference | File dimensions | Specific visual lesson |
|---|---|---|
| IMG_8698.jpeg, creature sprites | 645×1238 | Recognizable creature silhouettes, strong front/back identity, distinctive anatomical features and readable evolution/body variety. |
| IMG_8697.png, walking adventurers | 448×395, indexed PNG | Repeated poses share foot anchor and anatomy; clear hair/clothing at small scale; costumes retain identical movement rig. |
| IMG_8695.jpeg, character portraits | 960×845 | Big hair silhouettes, face angle, strong costume contrast and separate mouth/eye expression strips. |
| IMG_8694.jpeg, rework/time-skip portraits | 320×455 | Better shape clusters and anatomy make more difference than random detail; preserve identity through costume/age changes. |
| IMG_8696.jpeg, portrait variants | 640×646 | Controlled expression parts, light/dark separation, instantly recognizable hair and shoulders. |

The PNG uses **241 RGB colors across the whole atlas** (not per individual character); JPEGs contain compression artifacts. None are directly suitable as a 16-color indexed GBA OBJ asset without original redrawing and export. Do not infer per-sprite palette size from whole-atlas color count.

## Design decisions proposed for Vaelora
1. Distinct silhouette at native **240×160, 1×** before added detail. A 16×32 human should still be clearly human at actual size.
2. Two shape identifiers per Kith, not merely affinity-based recoloring. Shell variants preserve species recognition while modifying material texture and body mass.
3. Animation conveys intent: idle, anticipation, key contact, follow-through, recovery. A readable four-frame attack beats many jittery frames.
4. Walk uses four directions and three clear alternating poses per direction with stable feet and item attachment anchors.
5. Facial emotion belongs in larger optional portraits; overworld emotion is conveyed by pose, timing, hair/cape and context.
6. Actor colors must contrast against Bellhaven paving, Sapphire Coast beaches, Iron-Weep metal, Thorn Choir forest and Hush-darkness.
7. Use original work only. No imported Pokémon/Fire Emblem-like reference frames, copied palettes/characters, sprite tracing or uploaded copyrighted sprite sheets.

## Why current Vaelora sprites feel weak
The older prototype prioritized simply having a sprite over silhouette and movement personality. Some proportions and details appear muddy at 1×, posing is not dramatically different across frames, and monochrome/noisy interiors blur character boundaries. This is an **art-direction and animation problem**, not a higher-resolution problem.

## Technical sources
- GBA hardware palette/object graphics: https://mgba-emu.github.io/gbatek/
- GBA legal OBJ dimensions: https://lokathor.github.io/gba-from-scratch/ex3.html
- Principles of timing and key poses: https://voidless.dev/tutorials/guides/animation-principles-for-sprites

This is analysis only; it does not certify production game sprite quality.
