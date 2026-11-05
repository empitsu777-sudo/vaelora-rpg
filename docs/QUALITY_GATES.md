# Vaelora — Release Quality Gates (revised after failed player tests)

**Policy:** A green Python suite and deterministic GBA ROM are necessary but **not sufficient**. If a player can walk through a tree/roof, fail the release regardless of test count. Repair 04 is **STOP-SHIP**.

## G0 — Source, privacy and canon

- Verify latest accessible source ZIP and ROM SHA-256, test manifest, lineage and protected recovery copy.
- Respect approved lore (`docs/CANON.md`), original IP, the 30-hour target, six-region/18-settlement design scope and Bellhaven-only active work.
- This GitHub repo is public: do not upload proprietary ROM/source bundles, unlicensed pixels or user emulator screenshots without the owner's approval and privacy review.

## G1 — Native-resolution art fidelity

- Actual **GBA emulator** screenshot at 240×160 (1×) showing player, landmarks, door and NPC at accurate scale. Compare with approved Bellhaven illustration; no percentage/fidelity claim without reproducible assessment.
- Player and NPCs share a coherent pixel density, feet anchor, outline, palette and occlusion. No sprites visibly spawning inside trees, roofs, walls, water or floral hedges.
- No duplicate baked/live characters. No permanent oversize or clipped debug HUD.

## G2 — True gameplay and collision

- **Golden Route gate:** from a reproducible spawn, walk to one door, attempt to cross an adjacent solid roof/tree/water boundary (blocked), enter a visible door, leave, speak to an NPC, close dialogue; all on actual emulator input with frame capture.
- **Scale-up gate:** only after Golden Route passes: verify 8/8 door round trips, reachable interior items, outdoor interaction hotspots and actor placement on visual paths. Run collision trace against actual baked image, not only 16×16 planning-grid connectivity.
- Record held-button walk, acceleration/camera, 4-direction frames and measured gameplay motion at 59.73Hz; no slow/unresponsive controls or broken direction-dependent interaction.

## G3 — Engineering and persistence

- Python playtest and GBA C source share one world/manifest; no divergent behavior. Unit tests, native sanitizer, full asset regen, memory/palette/OAM budgets and byte-identical **two clean ARMv4T builds**.
- Real mGBA (or equivalent) boot, input routes, screenshot/frame logs, RAM behavior. If emulator is unavailable, status is **NOT VERIFIED / NO NEW RELEASE**.
- Save/load and migration must be demonstrated before calling persistence implemented; do not carry legacy SRAM assumptions into clean reboot without explicit migration design and tests.

## G4 — Player acceptance and release

- Every P0 issue in `docs/DEFECT_REGISTER.md` must have a reproducible emulator-level proof of closure and a new actual user playtest verdict. User negative feedback immediately reopens a gate.
- Release documentation states precise source hash, ROM hash, tool versions, test commands, screenshots provenance, failures, regression status, known defects and recovery path.
- **Pass means approved playable candidate**; **fail means experimental source snapshot only**. Never rename an experimental build to polished release merely because a tool compiled.

## Scope control

No Deepwood/other-region expansion or large story feature implementation before Bellhaven Golden Route acceptance. Polished interactive Bellhaven first; future 30-hour scope later.