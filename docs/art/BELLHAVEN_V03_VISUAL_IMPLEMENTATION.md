# Bellhaven visual and interaction slice v0.3 — 2026-10-16

**Status:** EXPERIMENT / pending player visual acceptance and emulator validation.
**Genre:** original top-down GBA action-adventure RPG, not a Pokémon-style turn-based monster collector.

## Delivered locally (verified from source and build)
An original 640×448 town canvas (40×28 logical 16×16 units) has four identifiable shops/homes, a central brass Bastion Spire, copper Chime Hearth, cobblestone plaza, hanging signs, gardens, trees, a river and bridge. The C prototype implements a native 240×160 moving viewport, position collision, three NPCs, a shard-collection quest, three player coat palettes and four-facing, three-pose walking art, contextual conversations, a Kith follower and a compact HUD.

- **Build:** Clang ARMv4T/LLD generated a 524,288-byte .gba cartridge.
- **Tests:** valid ROM header/checksum, palette and art dimensions, reachable NPCs / shard / Hearth / Spire; reproducible deterministic build SHA-256: `ce30951e509b01f4fde4ae81891b5e68c4d4d93491e9f2374a8f74a18c8fb354`.
- **Not tested:** boot/play input in mGBA or physical GBA; visual UI accuracy in running emulator. Rendered host previews are *not* emulator screenshots.

## Visual strategy learned from reference material
The limitation is not 240×160 itself: prior Vaelora v0.2 hid a repetitive field beneath a large permanent HUD. A readable town depends on recognizable architecture, shadow geometry, landmarks, safe walking routes, small expressive 16×32 character sprites, and clear signposting. A 4bpp 8×8 tile/16×16 metatile renderer with separate foreground and ground layers is the **final production target**. The v0.3 self-contained visual slice uses Mode4 8bpp bitmap for rapid aesthetic iteration, and cannot scale to all 18 towns unchanged.

## UI and controls currently implemented
D-pad movement; B held dash; A contextual talk/inspection; Start equipment/help overlay (not working inventory); Select journal/help overlay; R coat recolor (not persistent); L toggle illustrated Kith follower (not AI). Main screen has a top status strip and short bottom objective, not a giant permanent text banner.

## Original scene acceptance criteria
- At native 1×, player immediately distinguishes glass shop, inn, other service buildings, central Spire, Hearth and the river bridge.
- Avatar and NPCs have legible head/body separation and contrast against walkable paving.
- Dynamic popups appear only during dialogue or opening menu; traversable screen remains largely visible.
- No lifted Pokémon art, maps, sounds, data or game engine code.
- Approval is based on actual runtime screenshot and controls test; don't infer quality from compile alone.

## Next steps
1. Perform a real mGBA boot, camera/palette/VRAM test, dialogue and quest walkthrough.
2. Improve building architecture, detail density and sprite animation, with 1× screenshots reviewed by the player.
3. Convert image to compact 4bpp 8×8 tiles + 16×16 logical metatiles and foreground occlusion; supply scripts and tests.
4. Add first enterable Glass Shop and real equipment/inventory loop.
5. Make this prototype a **reproducible GitHub source commit** before treating it as the canonical game engine. Complete source ZIP exists as a separately delivered conversation artifact; text design notes alone are not code synced to GitHub.

## Research sources
- pret/pokeemerald sprite formatting (4bpp, per-sprite palette and frame tables): https://github-wiki-see.page/m/pret/pokeemerald/wiki/Adding-new-event-object-or-overworld-sprites-%28updated-for-INCGFX%29
- Game Boy UI community: https://www.reddit.com/r/Gameboy/comments/zw3nya/
- Art consistency feedback on a real-time Emerald battle experiment: https://www.reddit.com/r/GameboyAdvance/comments/1wl21s3/

**Canon safety:** all previously approved Kith/Lantern/Hush laws and 18 settlement names remain intact; the shard quest, artwork and UX controls are prototypes, not locked story canon.
