# Quality Gates and Definition of Done

## G0 — Narrative and design integrity
- Canon/approved/proposed ideas are separated.
- Every central rule has gameplay expression; no contradictions with consent, Hush, Lantern and material physics.
- Named characters have goals, conflicts, relationships and evolving local consequences.
- All 18 town concepts have unique functions and story hooks; travel graph tested for connectivity *and story-gated reachability*.

## G1 — Visual readability (mandatory before engine content scale-up)
- Native 240x160 captures at **1x** demonstrate recognizable player, readable Kith, town architecture, walkable ground, interactable doors and paths.
- Consistent palette, tile scale, light/dark contrast, 16x16 metatiles and 16x32 character silhouette. No oversized permanent UI obscuring the overworld.
- Scenes are evaluated by comparison of actual *gameplay at native resolution*, not marketing mockups or 4x-only previews.
- All shipped artwork must be original. Internal Emerald benchmarks must remain separate.

## G2 — Engine functionality
- Deterministic camera and scrolling; dual map layers and foreground occlusion.
- Passability and interaction flags; warps, scripted objects and NPCs; stable animation.
- Real-time combat, input, hit detection, knockback, companion state and Chord effects work across maps.
- SRAM save/load with version migration plan; no unwinnable state or lost quest-critical items.
- Emulator validation on mGBA and representative hardware performance. 59.73Hz target / frame-time instrumentation.

## G3 — Region content
- All three towns in a region have unique architecture, NPC routines, meaningful interiors, distinct music motifs and side quests.
- Routes are traversable and revisitable, Sanctum puzzles have communicated prerequisites, boss fights respect Kith ethics.
- Rewards are useful, customization persists, and the world changes visibly following story choices.

## G4 — Release testing
- Source builds reproducibly; ROM header checks; emulator startup smoke test; save/load regression test.
- Route/story progression tests, blocked-door tests, invalid Triad tests, companion respawn and material economy.
- Known limitations and repro steps published; screenshots demonstrate genuine runtime results.
