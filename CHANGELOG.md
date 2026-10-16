# Changelog

## 2026-10-16 — Uploaded sprite-sheet reference analysis and v0.2 art standard
- Inspected five user-provided sheets and documented silhouette, animation, anatomy, expressions and palette lessons in `docs/art/SPRITE_REFERENCE_AUDIT_2026-10-16.md`.
- Replaced vague sprite expectations with proposed character/Kith/portrait dimensions, palette budgets, animation timing ranges, species shape language and visual acceptance gates in `docs/art/SPRITE_STYLE_GUIDE_V02.md`.
- Added `tools/validate_sprites.py`, six regression tests, and an example indexed sprite manifest.
- **Validation:** local downloadable tool suite ran 6/6 passing format tests; no production sprite images were approved or added. Committed GitHub tool version has the same checks but has not been independently executed from a clean checkout yet.
- Kept supplied third-party image references outside GitHub. All art still must be drawn originally; no ROM or emulator testing was done in this sprite-only review.

## 2026-10-16 — Unscheduled Bellhaven visual slice (experimental)
- Created original 40×28-unit Bellhaven village art with visible storefronts, a Bastion Spire, gardens, river crossing and Hearth; native 240×160 preview.
- Compiled standalone 512KiB GBA prototype with camera, collision, brief NPC quest, dialogue, three coat variants and visible Kith follower.
- Static ROM-header, asset-size and quest reachability tests passed; deterministic clean rebuild matched prior SHA-256.
- **Not emulator tested.** Mode4 8bpp bitmap renderer is temporary; Mode0 layered 4bpp field engine, interiors, real inventory, combat and SRAM remain open.
- Technical/visual notes committed on this feature branch; full runnable source and binary are packaged as a separately delivered ZIP **not yet synchronized into GitHub**. Avoid pretending docs-only branch is a runnable project.
- World canon, six-region / 18-town plan and three-day lore sprint unchanged.

## 2026-10-15 — Repository bootstrap
- Verified connected repository access.
- Established original action-adventure RPG direction and split **user-authored immutable metaphysics** from **proposed story/world content**.
- Added canon, world index, roadmap, story seed and measurable quality gates.
- Documented 18-settlement / six-Sanctum target and October 16–18 preproduction sprint.
- **No production-quality GBA engine, assets, or ROM created in this commit.**
- **Public visibility warning:** repository currently reports PUBLIC; user can change under GitHub Settings > General > Danger Zone.
