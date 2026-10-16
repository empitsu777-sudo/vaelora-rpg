# Changelog

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
