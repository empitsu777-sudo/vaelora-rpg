# Vaelora — Instructions for Coding and Development Agents

**Supersedes stale October 2026 engine/roadmap instructions for current production.** Do not override older approved metaphysics in `docs/CANON.md`; distinguish metaphysical canon, tentative world names and current engineering priorities.

## Mandate

- Work on **Bellhaven only** until visual collision, interactions, locomotion and the Python/GBA rendering contract pass the gates in `docs/QUALITY_GATES.md`.
- Project origin: private-intended original GBA game, 30-hour target, six-region/eighteen-settlement scope. No Pokémon asset/code/ROM copying; study its legibility and level-design principles only.
- Use the approved richly illustrated Bellhaven reference, **48×36 exterior grid of 16-pixel planning cells**, all eight interior layouts, 10 outdoor NPC placements, 27 indoor placements and 80 interior objects as source *targets*; confirm each against actual manifests.
- Runtime design: **baked scene art + semantic collision/occlusion + triggers/doors + interactive objects + ambient animation + original characters/pets**. Generate assets in Python; share data and world rules between Python desktop harness and ARMv4T GBA game. Do not fake functionality by saving mockups.

## Mandatory source/lineage procedure

1. Inspect `/Game/VAELORA_CLEAN_REBOOT_ACTIVE/`, identify the newest *actually accessible and verified* archive/ROM/report and compute hashes before editing. The 2026-11-05 Repair 04 ROM hash is `1bd90af5cb61d577a1dba97958fbc0e15f70e2d7a0277070f2166ea47f97708c`; its full source archive hash is `c9ba1bc877648cc0bfad7796eb9e28de22fe50a8c96675e397ca668af3475502`. Both are **stop-ship experimental**, not proof of playability.
2. Read `docs/DEFECT_REGISTER.md`. Fix the highest-impact user-observed blocker before adding decorations, quests or expansion. Do not reintroduce the discarded pre-reboot engine.
3. Modify source/assets/maps and record exact paths, hashes and intended behavior. Keep all previous ROMs and recovery copies unchanged.
4. Run concrete movement/collision and door/interaction routes from physical spawn positions against **painted geometry**, not only logical grid reachability. Test at native 240×160; log emulator input and screenshot evidence.
5. Run deterministic Python tests, native sanitizer harness, asset/graphics budgets and twice-clean ARMv4T builds when available. The ROM is not accepted without mGBA/equivalent gameplay validation.
6. Report failures/timeouts and missing emulator access plainly. Generated host captures are **not emulator screenshots**. Never claim a player-approved quality percentage.
7. Keep project source private while the GitHub repository is public. Commit only safe governance/docs to GitHub until privacy is resolved; no proprietary game archives or reference images.

## Specific visual and gameplay obligations

- **Art/collision:** draw/edit collision over the actual baked picture in a Python visual editor, with feet-space polygons/masks. Test every roof, cliff, tree crown/trunk, bush, river, bridge and transition; use passable stairways/bridges deliberately. Prevent 'walking on houses' in both Python and GBA.
- **Character proportions:** enforce one world pixel/foot-anchor convention; original readable chibi sprites, coherent outlines/palette, four facings and meaningful stride frames. Avoid drawing duplicate NPCs over painted figures. All NPCs must appear on legitimate paths, not roofs or vegetation.
- **Controls:** smooth responsive input at the GBA frame rate; test both continuous holding and repeated taps, camera behavior and no repeated unintended interactions.
- **Interactions:** screen-visible door positions must match hotspots; A opens nearby doors/dialogue, B closes; no unreachable or roof-embedded trigger. Verify indoor-outdoor transitions and dialogue in the emulator.
- **UI:** avoid permanent large or clipped debug text. Dialogues, prompts and fonts must fit the GBA 240×160 display.
- **Atmosphere:** draw unchanging scenery into baked layers; keep fountain, lantern, smoke, pets, water ripples, NPCs and interactive props as event-driven layers where appropriate. Preserve depth/occlusion.

## Release discipline

`FAILED PLAYER ACCEPTANCE` beats green unit-test badges. The current Repair 04 ROM is a **recovery baseline** only. Release requires all P0 blockers closed, zero collisions in art-aware route tests, believable sprite/movement animation at native scale, 8 doors + NPC dialogue in actual emulator, legitimate screenshot/frame logs, build hashes and a user playtest. If any gate fails: produce a QA report with **NO NEW RELEASE**.

## Work session focus, Asia/Kolkata

00:00 sprites/pets; 03:00 Python art/asset pipeline; 06:00 interiors; 09:00 art/collision exterior alignment; 12:00 NPC/dialogue/quests; 15:00 movement/controls; 18:00 integration; 21:00 reproducible builds, emulator QA. **Always prioritize top blocker over hourly theme.**