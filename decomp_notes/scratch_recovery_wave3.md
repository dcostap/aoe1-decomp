# Scratch recovery wave 3

## Scope

The final accepted-drift audit leaves 67 scratch functions.
The final report classifies 17 as boundary problems and 50 as grouped mismatches.
This wave starts with ownership and boundary recovery.
It then processes behavior-risk and ordinary mismatch targets.

Do not reduce the scratch count without proof.
A completed target must become natural exact source, approved accepted drift,
a proved corpus reclassification, or a documented unresolved result.

Base commit: `c17a9da2c`.

Reference report:
`build/validation/final-accepted-drift-wave2/report.json`.

## Boundary batch

| Module | Targets |
| --- | --- |
| `basegame` | `0041E920 setup_graphics_system` |
| `com_q` | `00431D30 GetSpecificItem` |
| `m_co_obj` | `00450450 setup` |
| `pnl_scbr` | `0047AB20 set_tab_pos` |
| `point` | `0047E5D0 rotateXYByFacet` |
| `taiinfmd` | `004D6BB0`, `004DE600`, `004DEA80`, `004E2D10` |
| `taitacmd` | `004F57C0`, `00502310`, `00503070` |
| `taiuaimd` | `00504750 processNotify` |
| `tplayer` | `00518090 setupMinoan` |
| `view` | `00533AF0`, `00533E10` |
| `world` | `00542750 new_game` |

The `spanlist` assignment runs beside this batch because `DecodeLine` has a proved malformed-write counterexample.
Each module assignment includes every other scratch owner in that natural source file.

## Decision rules

1. Prove the original owner and boundary before byte tuning.
2. Review complete behavior before source edits.
3. Preserve malformed-input, exception, fault, and return-address effects.
4. Integrate exact source only when the form is natural and closure-safe.
5. Approve drift only after complete observable behavior proof.
6. Keep a documented scratch result when a real gap remains.
7. Preserve all experiments, including failed and rejected states.

## Later batches

After boundary integration, rank the remaining grouped mismatches as follows:

1. Proved corruption, exception, return-address, or dispatch risks.
2. Small natural exact candidates with complete behavior evidence.
3. Large control-flow and construction recoveries.
4. Ordinary scheduling differences with unresolved linked identities.

Run affected closures after each integration group.
Run whole-project validation after shared changes settle.

## Integrated results

- `0047E5D0 XYZ::rotateXYByFacet` is now `matching`.
  A natural expression reduction matches all 147 bytes and removes two boundary escapes.
- `0047E530 XYZ::operator+` remains scratch because invalid-reference fault order differs.
- `004BDEA0 AddShape`, `004BEAD0 DecodeLine`, and `004BEB10 take_snapshot` remain scratch.
  The unchecked DecodeLine write can corrupt differently ordered saved-register slots.
  No caller contract excludes the counterexample.
- `00450450 RGE_Master_Combat_Object::setup` remains scratch with repaired source.
  Original parameter-home scan writes restore the 557-byte extent and remove two boundary escapes.
  Later field-store fault order still differs.
- `0042CD50 GetCommInfo` is now accepted drift.
  Its only two bytes select signed versus unsigned comparison for fixed low static addresses.
- `00431D30 GetSpecificItem` remains scratch with a boundary-safe saved-EDI alias repair.
- `00533AF0 Init_Tile_Edge_Tables` and `00533E10 update_display_selected_objects` remain scratch.
  Their true owners are proved, but rebuilt paths still escape those boundaries.
- `0046FF90 create_checksum` remains scratch because two list loads can fault in a different order.
- `0047AB20 set_tab_pos` remains scratch after donor and arithmetic variants kept its boundary escape.
- `00518090 setupMinoan` remains scratch after donor-backed branch forms kept an extra pointer load.
- `00542750 RGE_Game_World::new_game` remains scratch with a one-byte boundary escape.
  PDB and exact donors reject its unused base-game alias, so the source now uses the named global directly.
- `00504750 processNotify` remains scratch after a behavior repair.
  It now reloads its object after virtual speed callbacks and preserves original coordinate access order.
  The natural form grows across four bytes of the next original owner, so it is not an exact or drift claim.
- The three `taitacmd` targets remain scratch after source repairs.
  `evaluateOpenTasks` now preserves the original tasked-ID read order.
  `taskElephantGatherers` now preserves the original initial resize and uses the natural array helper for later additions.
  The switch table in `checkForAttackResponseBuildInsertions` belongs to that function, but its return still escapes by two bytes.
- All three `fractal` targets remain scratch.
  The reachable `MakeNewLink` overflow still exposes different fault-time EDI state.
  `AddingCircle` now uses the local roles and initialization order recorded by PDB, without changing its output bytes.
- Both `tact_mob` targets remain scratch.
  The constructor has observable partial-object write-order drift, while `first_in_stack` still needs linked string proof.
