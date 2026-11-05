# Bellhaven — Stop-Ship Defect Register

**2026-11-06. Authoritative player feedback supersedes automated test summaries.** Baseline Repair 04 ROM SHA256 `1bd90af5cb61d577a1dba97958fbc0e15f70e2d7a0277070f2166ea47f97708c`. No replacement has passed emulator acceptance.

| ID | Priority | Observed defect | Likely cause / action | Evidence required to close |
|---|---|---|---|---|
| BH-P0-01 | P0 STOP SHIP | Player walks onto houses, roofs, trees and other scenery | Image painted separately from 48×36 collision grid; coarse patches inadequate. Visually trace/rasterize all solid art, enforce feet collision. | Input-driven emulator video/screenshots showing attempted entry blocked at representative roofs, tree trunks, cliffs and water; matching Python trace and mask. |
| BH-P0-02 | P0 STOP SHIP | Cannot enter illustrated buildings | Door trigger/approach points do not match visible door and player direction/foot position. | From spawn, open each of 8 doors and exit to correct position in emulator, capture scene transitions. |
| BH-P0-03 | P0 STOP SHIP | NPCs cannot be interacted with / no dialogue | Duplicate painted vs live actors, actor placement and selection priority. | Native emulator talks to ten outside NPCs + representative interior NPCs; correct dialogue opens/closes. |
| BH-P0-04 | P0 STOP SHIP | Player sprite ugly/inconsistent; NPCs on bushes or roofs | Prototype chibi proportions, missing painted/live actor reconciliation, unsupervised placement. | Approve sprite family at 1× native resolution; overlay audit of all actor spawn/route positions and depth anchors in emulator. |
| BH-P0-05 | P0 STOP SHIP | Walking is sluggish or awkward, not like a responsive handheld RPG | Tile-stepped motion, two gait art frames, uncertain VBlank/frame pacing. | Recorded emulator held-button movement and controlled 10–20 second loop at 59.73Hz with measured displacement; user evaluates feel. |
| BH-P1-06 | P1 | HUD/dialogue crowded or truncated at 240×160 | Too much permanent debug text, insufficient line-wrap/box size. | Screenshot showing full visible prompt and real dialogue at 1× native resolution. |
| BH-P1-07 | P1 | Interiors and props look far less polished than exterior | Simple blockout assets retained during illustrated Mode 4 conversion. | Review Glazier Workshop first: recognizable furniture with correct interaction, collision and original pixel art. |
| BH-P1-08 | P1 | Python and GBA results treated as interchangeable | Unit tests didn't reproduce actual emulator behavior; host renders mistaken for runtime proof. | CI/QA separates Python, native C, GBA emulator and user acceptance; no release without emulator evidence. |
| BH-P1-09 | P1 | No confirmed persistent save/progression | Clean reboot has no completed SRAM implementation. | SRAM save/load tests, migration specs, GBA restart and restored state on real emulator. |
| BH-P2-10 | P2 | Ambient animations are limited placeholders | Sprite timing and assets need art pass. | Later game-capture review after P0 closures; no cosmetic work before stop-ship repairs. |

## Verified scope of *prior test claims* — not release approval

Repair 04's own report lists 42 Python passes, native sanitizer success and two byte-identical ROM builds. This demonstrates build reproducibility and some logic checks **only**. It does not refute the user-observed blocked doors, poor movement or scenery clipping. Do not mark any P0 closed without fresh, matching emulator evidence.

## Next test priority

Create a small **Golden Route** from the town entrance to one shop and one NPC, with art-accurate solid masks, proper doorway alignment, consistent player scale and 4-direction animation, readable dialogue, and verified emulator recording. Expand to 8 doors only after the Golden Route works.