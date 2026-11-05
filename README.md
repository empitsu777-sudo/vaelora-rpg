# Vaelora: The Last Listening

**Private-intended, original, 30-hour fantasy action RPG targeting the Game Boy Advance.**  
**Production focus: Bellhaven only. Current status: STOP-SHIP — player-reported critical gameplay defects.**  
Updated 2026-11-06. This public repository is a *documentation and review mirror*, **not** the current playable game's source of truth.

Vaelora's premise remains **matter is frozen music**. A Wayfarer explores a six-region world, meets consenting Kith, uncovers the Hush, uses Chord abilities and restores communities. The projected six-region / 18-settlement game is a **target**, not delivered content.

## Where the active work lives

- **Active private development folder:** `/Game/VAELORA_CLEAN_REBOOT_ACTIVE/` in the project's ChatGPT Game Library, **not yet synchronized to GitHub**.
- **Latest accessible experimental baseline for review:** `Vaelora_Bellhaven_Repair04_Source_ROM_QA.zip` (archive SHA-256 `c9ba1bc877648cc0bfad7796eb9e28de22fe50a8c96675e397ca668af3475502`) and `Vaelora_Bellhaven_Repair04_Experimental.gba` (ROM SHA-256 `1bd90af5cb61d577a1dba97958fbc0e15f70e2d7a0277070f2166ea47f97708c`). Verify the actual files/hashes; newer verified candidates supersede these references.
- **Acceptance:** Repair 04 **FAILED player acceptance** despite 42 passing Python tests and clean ARM builds. The player reports walking through buildings/trees, unusable door/NPC interactions, mismatched sprites, poor movement and NPCs in scenery. Those failures take precedence over earlier test claims.
- **Do not use this repository's old October roadmap or prototypes as an alternative active engine.** Preserve them as historical design only.

## Working architecture

**Python-first hybrid illustrated-scene system:** baked original Bellhaven background art; independently authored and image-aligned walk/occlusion mask; trigger/door/object data; animated overlays; consistent four-direction chibi/NPC/pet sprites; a Python desktop playtester calling shared C world rules; an ARMv4T GBA ROM renderer. One manifest must feed both frontends. The current baked-art / collision alignment is **not good enough**. See [Architecture](docs/ARCHITECTURE.md) and [Player-reported defects](docs/DEFECT_REGISTER.md).

## Non-negotiable next gate

Prove **one playable Bellhaven neighborhood** in a real GBA emulator: player cannot enter any solid roof, tree, wall, cliff or water; movement is fluid; a door opens the correct interior; NPC interaction works; characters sit on the intended paths and share a coherent pixel scale. Only then expand to all eight buildings, 80 interior objects and additional animation. No new release without authentic emulator evidence and player acceptance.

## Read first

- [Development instructions](AGENTS.md)
- [Production decisions and canon separation](docs/DECISION_REGISTER.md)
- [Engine / art contract](docs/ARCHITECTURE.md)
- [Stop-ship defect register](docs/DEFECT_REGISTER.md)
- [Strict quality gates](docs/QUALITY_GATES.md)
- [Updated roadmap](docs/ROADMAP.md)
- [Existing lore canon](docs/CANON.md) and [world proposals](docs/WORLD_INDEX.md)
- [Changelog](CHANGELOG.md)

## Repository visibility warning

**This repository is currently PUBLIC.** Do not commit proprietary artwork, source/ROM ZIPs, personal user screenshots, unlicensed third-party assets or unreleased story details until its visibility and permissions are deliberately reviewed. GitHub repository Settings → General → Danger Zone is where an authorized owner can change visibility. This documentation PR does not change visibility.

**No code in this repository is claimed to be the present playable GBA source.** The Game Library contains the current experimental project and protected recovery archives.