# Vaelora — 18-Settlement Quest and State Matrix v0.1 (PROPOSED)
No quest may require a permanently unavailable companion or exceed three active Glass Plates. Each optional choice has the same critical-path unlock; choices alter local return state, dialogue and cosmetics rather than blocking story. Every quest must be revisitable after its Sanctum.

| Town | Quest | Lead NPC | Playable verb / dilemma | Persistent return state | Reward |
|---|---|---|---|---|---|
| Bellhaven | Q_SH1 The Note That Went Missing | Maera Vell | Compare witness clues; repair relay; free Kith | Honest repair notices | Lantern calibration |
| Reedwake | Q_SH2 A Ferry for the Forgotten | Nemi Fen | Tune water chimes; protect nesting marsh | Ferry restored; alternate schedules | Reed waterproofing; reedwake_ferry_restored |
| Prismere | Q_SH3 The Furnace Register | Iva Cress | Trace kiln marks and suspect orders | Signed kiln shifts | Cosmetic plate casing |
| Tidemark Quay | Q_SC1 Names on the Manifest | Sen Fen | Follow tides and cargo marks | Shelter and beacon repaired | Skiff pass |
| Corallume | Q_SC2 A Statue That Listens | Luma Tide | Rework an echo-stone monument | Silent or anonymized sculpture | Coral graft material |
| Moonpool Haven | Q_SC3 The Private Tide | Sister Arune | Rebuild storm warning without violating trust | Safer channel markers | Abyssal resonance |
| Ferrum Hollow | Q_IW1 The Third Shift | Orrin Vale | Stabilize tunnels; redesign work shifts | Guarded work crews | Magnetite material |
| Railspire Junction | Q_IW2 The Unsent Stop Signal | Tovan Rusk | Replay signals; repair stop system | Redundant manual bell | Rail token |
| Anvilrest | Q_IW3 Water for the Forge | Bera Flint | Route cooling water | Reworked sluices | Heat-shield fitting |
| Rootwhisper | Q_TC1 The Bridge That Refused | Aya Root | Repair runoff; negotiate bridge passage | Clean bank, restored bridge | Resin grip; root_current_restored |
| Bloomshade | Q_TC2 A Cure with Roots | Leth Mirren | Balance Verdant/Umbra growth | New flower-bed pattern | Salve recipe |
| Mourning Grove | Q_TC3 The Name Beneath Bark | Elder Fenna | Release Umbra trap; choose remembrance | Ribbons or quiet shrine | Veil weave |
| Kestrel Roost | Q_AW1 The Shortcut Above Eggs | Vesa Kestrel | Map wind, protect nests | Seasonal route flags | Wind-thread satchel |
| Skybraid | Q_AW2 A Knot in the Wind | Kori Brae | Dampen cable resonance | Bridge re-rigged | Cloak trim; orelift_repaired |
| Galeheart | Q_AW3 The Forecast Kept Quiet | Eris Gale | Restore warning chain | Farm warning kites | Zephyr weave; watchwind_lit |
| Quietwatch | Q_SB1 A Rest Is Not a Chain | Keeper Noa | Reconcile watch and sanctuary records | Sanctuary signs revised | Hush-safe lens |
| Chainfall | Q_SB2 Unfasten the Living | Iseult Thren | Free Amalgam convoy; protect bystanders | Rescue scaffolds | Safe-release tool; pilgrim_route_reopened |
| Basilica City | Q_SB3 The City That Listens | Sol Veyr | Expose relay coercion; build voluntary safeguards | Distinct bells return | Civic covenant |

## Optional route-repair flags
- `glassrail_repaired`: Prismere–Ferrum optional return commission after Returning Tide, never a required entry into Iron-Weep.
- `reedwake_ferry_restored`, `root_current_restored`, `orelift_repaired`, `pilgrim_route_reopened`, `watchwind_lit`: earned through local commissions shown above.
- All flags are **proposed**. Quest branches can change visuals and NPC trust, but cannot revoke the main six Sanctum clear flags.
- State storage target: one two-bit state per town (unresolved / restored A / restored B), plus explicit shortcut and Sanctum flags. This is a design budget, not implemented SRAM.
