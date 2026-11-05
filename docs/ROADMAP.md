# Vaelora — Bellhaven-First Recovery Roadmap

Updated **2026-11-06**, replacing the obsolete October 16–18 sprint and unreconciled region rollout **as an active engineering schedule**. Older creative ideas remain historical proposals, not automatically deleted lore.

| Gate | Deliverable | Acceptance condition | Status |
|---|---|---|---|
| 0 | Source-of-truth / issue triage | Active private archive verified, hashes/lineage recorded, P0 failures documented | **DOCUMENTED; source still experimental** |
| 1 | Art-aligned Bellhaven scene | Python editor draws/rasterizes collision and doors on actual baked art; 1× image/mask audit | **BLOCKED; coarse masks failed user test** |
| 2 | Consistent player/NPC sprite family | Original pixels, realistic 16×24–32 chibi proportions, four-direction walk and proper feet sorting | **BLOCKED** |
| 3 | Golden Route emulator test | Can't cross inn/trees; can enter shop and exit; talks to NPC; smooth movement recorded in mGBA | **NOT PASSED** |
| 4 | All eight Bellhaven interiors | Eight aligned entrances; 27 planned indoor NPC positions and 80 items inspected, useful furnishings | **PROTOTYPE ONLY; acceptance incomplete** |
| 5 | Bellhaven village life | Pets/NPC routines, ambient overlays, readable UI, meaningful neighborhood quests | **PARTIAL EXPERIMENT** |
| 6 | Save/progression/recovery | State persists in actual emulator, recovery tested, deterministic build and full QA | **NOT VERIFIED** |
| 7 | Bellhaven player approval | Emulator evidence, representative ten-minute human playtest and resolved P0 register | **NOT APPROVED** |
| 8 | Deepwood / six-region game | Design and expand once Bellhaven meets gate 7 | **ON HOLD** |

## Recommended execution order

1. Stop shipping ROMs labelled repaired on Python tests alone.
2. Use Python to annotate real visual obstacles, doors and legal NPC feet positions against the approved baked picture. Remove collisions based on outdated architecture-only grids.
3. Build consistent chibi and movement system, then test Golden Route on actual GBA emulator with input logs, 1× captures and recorded performance.
4. Address all eight interiors and player flow; then elevate art/props and ambient animation to reference quality.
5. Implement save/progression; confirm actual user acceptance. No arbitrary commitment to hour/date delivery or 90%-visual claims.

## Development cadence

Eight existing Asia/Kolkata sessions (00/03/06/09/12/15/18/21) remain, but **highest-impact reported blocker overrides theme**. Every session should inspect latest verified candidate, make a substantive change or report no release, run appropriate tests, preserve baselines, and attach verified artifacts/defect report. No work is implied without a task actually running.