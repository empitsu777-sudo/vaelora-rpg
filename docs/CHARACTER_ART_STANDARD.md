# Bellhaven character and NPC art standard — 2026-11-06
Status: APPROVED DIRECTION / IMPLEMENTATION NOT YET VERIFIED

The user-supplied six-region Vaelora moodboard and Bellhaven illustration are the visual authority. Replace generic blocky chibi figures; recolouring them is insufficient. Original art only.

## Required sprite system
- Shared perspective, lighting, palette, scale and ground-contact anchor for player, NPCs, children, shopkeepers, elders, pets and goats.
- Compact, expressive chibis with readable hair, individual outfits, layered clothing, detailed silhouettes and soft pixel shading. Avoid oversized blocky heads and rectangular bodies.
- Keep the 16x32 technical canvas if GBA ABI requires it; tune the visible silhouette against native 240x160 game art.
- Four genuinely distinct facings (front/back/left/right); three distinct walking poses per facing plus idle, stable feet anchor, responsive held-button movement.
- Unique role-based NPC silhouettes, not random palette swaps. Animals must use coherent proportions and believable walk/idle animation.
- No duplicated baked NPCs: remove them from background or restore clean patches.
- Each NPC manifest entry needs coordinates, feet anchor, facing, dialogue, interaction reach, movement zone and collision. Never spawn on roofs, foliage, water, cliffs or furniture.

## Required sequence
1. Audit `tools/paint_live_chibis.py` and sprite pipeline. Current sprites are REJECTED baseline.
2. Create player + two distinctive NPCs + one pet replacement atlas with native-resolution HOST preview and request art approval.
3. Integrate into Python pipeline and GBA renderer; capture real EMULATOR 4-facing walk.
4. Prove Golden Route: blocked scenery, enter/exit one door, talk to one NPC.
5. Expand to 10 exterior NPCs, 27 interior NPCs and pets only after approval.

Any generic placeholder, mismatched scale, jittering feet, duplicated baked sprite, NPC embedded in scenery or broken dialogue is STOP-SHIP. Do not claim game code is updated without actual ROM/emulator evidence.
