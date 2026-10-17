# Six Sanctums and the 24-Route Travel Graph — v0.1 (PROPOSED)

## Main route and unlock order
**SH1 Bellhaven → SH2 Reedwake → SH3 Prismere → SN1 Broken Bell → SC1 Tidemark Quay → SC2 Corallume → SC3 Moonpool Haven → SN2 Returning Tide → IW1 Ferrum Hollow → IW2 Railspire Junction → IW3 Anvilrest → SN3 Buried Magnet → TC1 Rootwhisper → TC2 Bloomshade → TC3 Mourning Grove → SN4 Night Bloom → AW1 Kestrel Roost → AW2 Skybraid → AW3 Galeheart → SN5 Open Sky → SB1 Quietwatch → SB2 Chainfall → SB3 Basilica City → SN6 Unheard Crown → SH1.**

Exactly **24 settlement-to-settlement routes** are defined in `data/world/routes_v01.json`: 12 within regions, six principal cross-region links (including final return road), and six optional repairable shortcuts. Sanctum access paths are dungeon entries and do not count toward the 24 settlement routes. No teleportation is assumed. Each route has two endpoint IDs, traversal mode, role and explicit unlock flags. Main chapter gates use one clear flag each; optional shortcuts require the corresponding chapter clear flag plus a local repair flag.

## Sanctum acceptance contracts
| ID | Entry | Lesson and nonlethal climax | Opens |
|---|---|---|---|
| SN1 Broken Bell | Prismere | Tune witness chimes, free a clamped Kith, offer a voluntary bond; Hearth before puzzle | `broken_bell_cleared` → coast |
| SN2 Returning Tide | Moonpool Haven | Abyssal + Relic Galvanic Lock on wet conductive metal; no arbitrary conductivity | `returning_tide_cleared` → Deepworks |
| SN3 Buried Magnet | Anvilrest | Cinder + Relic heated glass plus a fixed cooling sluice; brittle barrier shatters, Kith freed first | `buried_magnet_cleared` → Thorn |
| SN4 Night Bloom | Mourning Grove | Verdant + Umbra Parasitic Bloom balanced with measurable regrowth, no irreversible depletion | `night_bloom_cleared` → Aerie |
| SN5 Open Sky | Galeheart | Cinder + Zephyr Over-Pitch in vented chambers with safe routes and warning cues | `open_sky_cleared` → Still |
| SN6 Unheard Crown | Basilica City | Accessible Hearths permit legal Triad swaps; release every Kith before disabling anchors | `unheard_crown_cleared` → return road |

## Traversal grammar and player guidance
- Each route entrance should be visible as a clear **path, ferry, rail platform, living arch, bridge or lift**. Use landmarks and local NPC dialogue to signpost locked routes without opaque UI walls.
- Before a mandatory two-affinity puzzle, place a **Chime Hearth** with the needed Plates available through earlier voluntary encounters. The player may change only the three active Plates at a Hearth.
- Heavy abilities spend Liquid Echo; a refillable water-chime or rhythm interaction must be reachable on the near side of each critical gate. All-three-Plate Dissonance returns to the last Hearth without destroying story items.
- Travel is bidirectional after a route unlocks; unlocked routes cannot relock from optional dialogue choices. Returning to earlier towns reveals visible quest changes.
- A fallback route must exist for every optional shortcut. **No required quest depends on an optional shortcut.**
- Proposed overworld geography: Shatterglass borders Coast and Deepworks; Coast borders Deepworks and Thorn by estuary; Deepworks borders Thorn and Aerie by lift; Thorn borders Aerie and Still by pilgrim shade; Aerie borders Still; Still has a historic return road to Shatterglass. Long-distance shortcuts are actual authored route maps, not unexplained adjacency.
- Native GBA art handoff: each town needs one unique skyline, entrance composition, 2+ purposeful interiors, 1 landmark animation, readable 16×32 NPCs, sound identity and a before/after quest-state map. No assets claimed built.

## Research and adaptation
Techland's designers emphasize aligning quest purpose with recognizable environmental spaces (https://techland.net/blog/places-and-their-stories-quest-design-level-design). Nintendo's 2017 GDC systems discussion supports readable interactions between consistent rules (https://www.gamedeveloper.com/design/video-designing-i-zelda-breath-of-the-wild-i-s-unconventional-mechanics). Vaelora applies these general principles to authored, compact GBA routes, **not** to an unbounded open world.

## Open design risks
Physical map geometry and travel time have not been drawn. The six alternate routes need per-map costs and encounters. Sanctum Kith availability and Hearth placement require Oct 18 mechanics audit. History of the Seventh Interval and Synod faction structure remain unresolved; no new faction canon is invented here. Branching quest choices must be tested against save/load and all chapter flags before locking.
