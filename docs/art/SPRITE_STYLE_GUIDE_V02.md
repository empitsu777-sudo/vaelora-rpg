# Vaelora Sprite Style Guide v0.2
**Status: proposed**; follows user-established canon in docs/CANON.md and the 18-town world index. Original game art only.

## Vision
**Storybook fantasy + kinetic action**: cozy expressive towns, cinematic readable Kith, bold motion. Use Mario/Sonic/Contra/Metroid as animation and silhouette principles, not as assets. Establish a consistent light source (top-left), deliberate 1px perimeter edge, 2–3-tonal shading clusters and controlled outlines. No visual noise.

## Hardware and art budget
| Asset | Canvas / hardware | Minimum poses | Color policy |
|---|---|---|---|
| Wayfarer / humanoid NPC | 16×32 OBJ | 4 facings x 3 walk + 2 idle | 4bpp, index 0 transparent, max 15 visible per OBJ bank |
| Companion Kith | 32×32 OBJ (ink smaller allowed) | idle, move, signature ability, decoupling | 4bpp with explicit palette budgeting |
| Loot and HUD icons | 8×8 / 16×16 | pickup/glow optional | shared UI/item palettes |
| Elite Kith / boss | 64×64 OBJ or multiple hardware OBJs | windup, strike, recoil | multiple OBJs/palette banks audited |
| Portrait | 64×64 or tiled BG dialogue panel | neutral + 2 emotions, blink, speech | original 4bpp tiled art; palette/bank audit |

**24×24 is not a single hardware OBJ size:** use art within a 32×32 canvas. All production assets use 8×8 4bpp indexed tiles (32 bytes/tile), legal hardware shape/size pairs and separate BG/OBJ palettes. 16×32 is 256 bytes/frame before compression/reuse. Reserve OBJ palette entry 0 for transparency. No full-color JPEG exports in the ROM pipeline.

## Readability rules
- **Player:** strong head/boots contrast, visible amber Lantern, two distinct body/gear masses, hair silhouette. No pixel-noise hair.
- **NPC:** profession-specific silhouettes (Maera = glazier goggles/apron, courier = satchel, Synod scout = squared collar). Recolors alone do not establish NPC identity.
- **Kith:** two identity cues per species; retain at least one cue through all material-graft variations.
- **Customization:** cosmetic palette banks work for fabrics/hair; changed equipment shapes require frame-aligned overlay pieces at stable anchors.
- **Environment:** verify on pale stone, dark grove, water, metal, and Hush-darkness. Footprints, shadow and occlusion follow same grounding rules.
- **UI:** 8×8/16×16 clear icons with text where needed, no oversized permanent world-obscuring HUD.

## Suggested starting animation tables (to tune in-engine)
| State | Frames | Timing at ~60 GBA ticks per second | Art direction |
|---|---|---|---|
| Idle | 2 | 20–32 ticks/pose | small Lantern glow/breath; feet fixed |
| Walk | 3 per direction | 6–9 ticks/pose | stand-left-stand-right with obvious arm and foot changes |
| Dash | 2–3 per direction | 3–5 ticks/pose | forward lean, trailing dust/effect separately |
| Light melee | 4 per direction | ~3/3/5/5 ticks (starting point) | windup, impact, held contact, recovery |
| Heavy melee | 5–6 | species/weapon dependent | strong anticipation and recovery |
| Hurt | 2 | ~4–7 ticks/pose | readable recoil, controlled flash |
| Kith skill | 3–5 | material and species dependent | charge, cast/act, recoil |
| Kith decoupling | 4–6 | variable | physical shell collapses; **spirit safely returns**, never death |

**No frame count alone proves good animation.** Test at native size and gameplay speed. No frame-origin drift; do not flip asymmetrical gear blindly.

## Proposed Kith silhouettes (NOT approved designs)
- **Sproot (Verdant):** offset leaf crest + forked vine/root fist; idle leaf has delayed sway.
- **Scuttle (Relic):** squat wedge shell + large offset magnetic claw; magnetite variant is weighty, coastal variant coral-arched.
- **Galekin (Zephyr):** wing-sail triangle + curled gust-tail; anticipation is wing compression.
- **Noctil (Umbra):** dusk-moth hood + twin luminous eye lamps; wings fold like curtains.
- **Ripplet (Abyssal):** pebble-shell aquatic form + oversized curling fin; splash recoil.
- **Cindlet (Cinder):** charcoal core + branching tuning-fork flame horns; ember flare/lunge.

These preserve existing Kith names/affinities where earlier prototypes used them; the silhouettes are design experiments only.

## Required review before approval
- [ ] All actors recognizable at 1× (not just 4× preview)
- [ ] Kith distinguishable as solid one-color silhouettes
- [ ] Four-facing movement, attached item origins and feet stable
- [ ] Player/NPC/Kith not confused in five distinct terrain environments
- [ ] Attack windup/active/recovery legible at normal gameplay speed
- [ ] Asset palette, index0 transparency, dimensions and provenance validator passes
- [ ] Emulator runtime screenshots and gameplay verified, not host-only renders
- [ ] Original assets; third-party references stay outside repository

## Next focused deliverable
**Artist batch A:** original Wayfarer 4-way walk + idle/dash/attack, **Scuttle** with coral and magnetite shells (same identifying core), **Maera** overworld + 3 dialogue portrait expressions. Composite into one real native-resolution Bellhaven gameplay scene. Review visually before producing more Kith or more towns.

References: docs/art/SPRITE_REFERENCE_AUDIT_2026-10-16.md; docs/CANON.md.
