# Vaelora — Bellhaven / Reedglass GBA vertical slice v0.5

**Date:** 2026-10-19. **Status:** real compiled GBA ROM candidate with original graphics and gameplay code; **NOT YET EMULATOR VERIFIED**. It is not the full six-region, eighteen-town RPG.

## Verified implementation changes from v0.4

- Recovered and SHA-256 verified the exact v0.4 source and 128KiB ROM from ChatGPT Library before making changes. v0.5 is a genuine modification of that recovered source, not a reimplementation.
- Fixed a **real quest blocker**: the Bellhaven north exit was triggered only at y<17, but the actual pixel collision probes cannot move above y=20. Trigger is now y<25. Pixel-accurate reachability tests catch regressions.
- Replaced the 16x16 Scuttle follower with an original **32x32, four-frame Relic Kith** (asymmetric claw, wedge shell, tuning antennae). Follower trails the player rather than sticking to a fixed screen offset.
- Added three **original 32x32 Maera portrait expressions** displayed over the dialogue panel. Dialogue is shortened to fit the available 25 glyph columns.
- Added three selectable Wayfarer coat palettes using distinct OBJ palette banks, persisted in save data.
- Implemented **GBA SRAM save/load** with 18-byte versioned payload, CRC16-CCITT validation, range checks and `SRAM_V113` cartridge save-type signature. Start menu: A save, B load, L coat. The same C codec is compiled into the GBA ROM and tested as a native host shared library. Actual cartridge/emulator SRAM behavior remains unverified.
- Fixed **menu rendering**: the HUD is now refreshed each VBlank, rather than depending on a frame counter that freezes while the menu is open.
- Improved Bellhaven paving, shop roof trims, plaza lamps, banners and glazier windows, and added Reedglass reed details. Existing five CC0 Superpowers scenery props remain integrated into live maps.
- Added reproducible GitHub-friendly embedded CC0 asset restore mechanism, plus native-size host previews including actor layers and dialogue. Host previews are **not** emulator screenshots.

## Intended controls (emulator testing pending)

| Button | Function |
|---|---|
| D-pad | Walk and face direction |
| A | Talk / interact; in Start menu: save SRAM |
| B | Attack; in Start menu: load SRAM |
| R | Scuttle Relic skill (spends 2 Echo at Reedglass gate) |
| L | Cycle coat palette (also in Start menu) |
| Start | Open/close journal and save/load menu |

Walkthrough: talk to Maera in Bellhaven, follow the north road into Reedglass Path, approach the bridge gate, use R to resonate it, defeat the Hush Shade with B, pick up the shard with A, return to Maera. The workshop can be entered from Bellhaven. **End-to-end runtime gameplay has not been tested.**

## Rebuild and tests

Requires Clang with ARMv4T backend, LLD, llvm-objcopy, Python 3 and Pillow; native C compiler for host save-codec tests.

```sh
make clean
make all
make test
```

`make all` restores CC0 prop bytes from tracked base64 metadata, regenerates original sprites/tiles/maps, generates GBA header, compiles and pads the ROM. No Pokémon source, ROM or copyrighted assets are included. The build is reproducible from tracked text files.

Output: `build/vaelora_bellhaven_v05.gba` (128KiB), native host previews in `previews/`.

## Limits / next gate

The ROM has **not** been booted in mGBA or physical hardware in this environment. No emulator executable is installed, and package index refresh timed out. Static compilation, CRC roundtrips, pixel traversal and host compositing do **not** prove emulator functionality. The next mandatory gate is emulator boot, actual screenshot capture, save/load test and full quest walkthrough. Visual polish still needs significant work.

Licensing: original Vaelora sprites, code and maps; five converted scenery props from Superpowers Asset Packs (Sparklin Labs / Pixel-boy), CC0 per included `assets/third_party/README.md` and `LICENSE.txt`. Pokémon Emerald was studied only as a reference; no Nintendo game assets or source included.
