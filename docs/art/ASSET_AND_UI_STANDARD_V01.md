# Vaelora GBA Art / UI Standard (proposed v0.1)

## Production art
- Display 240×160, 3:2; 8×8 hardware tiles at 4bpp; 16×16 landscape metatiles; up to sixteen 16-color BG and OBJ palettes per bank.
- Houses should have distinct roof profiles, foundation shadows, doors/windows/signage and local material motifs; each town needs its own structure, layout and centerpiece, not just a palette shift.
- Player targets 16×32, four-facing/three-walk-poses (+ dodge/attack as needed). Overworld Kith are individually sized but distinguishable at 1×. Do not copy Emerald sprites.
- Decorative world layers should be behind/overlapping the player as appropriate; hero feet and building entrance warps use precise collision geometry.
- GBA hardware OAM sprites / tile backgrounds in final engine; bitmap 8bpp prototype is a throwaway scaffold.

## Gameplay UX
- Navigation D-pad; context action A; B quick dodge/dash; L/R Kith or gear quick access once system is implemented.
- Map, quest journal, bag, equipment, crafting, Kith and settings organized by task and discoverable without cluttering play area.
- Show HP/condition and location briefly/compactly; avoid wide permanent messages and modal popups for repeated combat events.
- Give all four Chord Reactions explicit VFX symbol / cue / terrain response, not color-only indications; show why required companion or resource is unavailable.
- Review at actual 240×160 screenshot at 1× before approving every exterior, interior, player sprite, enemy and UI screen.

## Milestone gates
[ ] GBA emulator boot/capture
[ ] 1× player review of Bellhaven, services and characters
[ ] Directional frame sheet / moving follower
[ ] Enterable building + NPC conversation
[ ] 4bpp layered graphics renderer
[ ] Inventory equipment UI, persistent saved customization
[ ] One fully traversable first route + interaction/combat

This checklist is deliberately **not** marked complete from the art concept alone.
