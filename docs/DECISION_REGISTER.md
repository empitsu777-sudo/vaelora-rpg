# Vaelora — Current Production Decision Register

**Updated:** 2026-11-06. Distinguishes established user direction from proposals and delivered features.

| Topic | Status | Decision / nuance |
|---|---|---|
| World metaphysics, Kith, Hush, voluntary bonds | Established creative canon | Keep `docs/CANON.md`; don't rewrite as a technical reboot. |
| Genre | Approved | Original top-down fairy-tale action RPG, **not** a Pokémon asset clone or monster-collecting game. |
| Full game ambition | Approved target, not implemented | Approximately **30 hours**, six distinct thematic regions, eighteen settlement roadmap. |
| Current production scope | Approved | **Bellhaven only** until verified player movement, collision, doors, dialogue and cohesive art. |
| Art reference | Approved target | User's lush six-region moodboard and richly illustrated Bellhaven town: warm coral/copper, jade foliage, lilac flowers, blue water, honey light. Image is an art target, **not automatically collision-aligned source**. |
| Town architecture | Approved planning baseline | Bellhaven **48×36 cells**, 16×16 pixels each; fountain-centered town; western stream and two bridges; north stairs; raised chapel; market, inn, Glazier Workshop and five cottages. |
| Interiors | Approved planning baseline, implemented experimentally | 8 interiors, 27 NPC planning positions, 80 object interactions. Functionality must be proven on emulator, not presumed from tests. |
| NPC / pets | Design target; incomplete runtime | One consistent chibi family with original Rowan, Sera, Tavi and residents; cats, dogs, goats, chickens etc. Avoid duplicated baked NPCs. |
| Runtime approach | Approved | Python-first **hybrid baked background + gameplay layers**, shared C logic and ARMv4T GBA build. |
| Repair 04 | **Failed player acceptance — stop ship** | User reports collision, doors, NPC positioning, movement and art faults despite automated pass. |
| Previous full eight-scene engine | Archived/superseded in active development | Recovery only. Do not silently merge its maps/trees/mechanics into the clean reboot. |
| World/index naming | Needs canonical reconciliation | `docs/WORLD_INDEX.md` contains October six-region proposals (Shatterglass Reach etc.); user's November visual-region boards feature Bellhaven, Deepwood, Mistfen, Galecrest, Stonewake and Heart of Vaelora. **Do not assert these names are already a resolved one-to-one six-region geography.** No region implementation while Bellhaven fails playtest. |
| Private IP | Required | GitHub is currently **public**; proprietary binaries, unlicensed materials and unpublished art remain outside this repo until visibility is fixed. |

## What is *not* demonstrated

- No verified full 30-hour game, finished story, approved production sprite atlas, playable regional expansion or complete persistent-save engine.
- Repair 04 had 42 passing Python tests, sanitizer harness and identical two clean builds according to its report; **none constitute an emulator gameplay pass**, and the user's contrary observed experience controls release decisions.
- Screenshots from Python or decoded game assets are HOST previews only. Only actual emulator frame captures count as GBA gameplay evidence.