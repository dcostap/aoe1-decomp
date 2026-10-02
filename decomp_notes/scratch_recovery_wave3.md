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
- `00477AF0 delete_character` remains scratch with a nine-byte final field-load-order difference.
  Its local declarations now follow the PDB order without changing emitted bytes.
- All three `rmm_elev` targets remain scratch.
  The first two lack complete malformed-map proof, and `link_stack_randomly` retains an alias-sensitive load-order difference.
- Both `rmm_terr` targets remain scratch.
  Natural forms did not change their code, and `count_map_tiles` still reverses dimension load order.
- `004490E0 RGE_Effects` remains scratch.
  Its five-byte compare/store reorder is safe for ordinary construction, but allocation-failure and unusual count states remain unproved.
- `004CC4C0 heal` remains scratch because nine x87-related bytes still lack complete numeric and exception-state proof.
- `004786B0 item_at` remains scratch because its two field reads can fault in a different order on an invalid receiver.
- `0041E920 setup_graphics_system` remains scratch with a proved six-byte epilogue escape.
  Its locals now use PDB-supported byte types, and its allocation pointer starts at the natural allocation site.
- `00485480 chance` remains scratch.
  It writes the low byte of its `land_type` stack home, and a malformed receiver can expose the remaining read-order difference.
- All five `taiinfmd` targets remain scratch.
  The constructor now follows PDB quadrant-loop order and matches its 1,182-byte owner boundary.
  Twelve bytes still differ, while the other four targets need further source or container evidence.
- `0048E400 set_mode` remains scratch because `itoa` argument setup has an unresolved stack-fault order difference.
  Its player-count local now uses the PDB `long` type without changing output bytes.
- `004862B0 place_avoid_objects` remains scratch.
  A malformed player array can fault before or after the original first argument push.
- `0043A070 DibFromBitmap` remains scratch.
  Current source preserves known allocation and cleanup bugs, but GDI write extent and failure paths remain unproved.
- Promoted `004407A0 TribeSendMessageDialog` to `accepted_drift`.
  Three complete reviews agree on calls, fields, EH, cleanup, failure paths, and the original partial-object hazard.
  Residual bytes are register allocation, zero encodings, and dependent branch displacements.
- Both `map.cpp` targets remain scratch.
  `load_terrain_obj_types` has an unresolved PDB parameter-home conflict.
  `place_terrain_object` preserves known order, but malformed virtual-callee cleanup remains unknown.
- `0046B680 decrementObstruction` remains scratch.
  Original code reads both arguments before saving registers, so invalid stack arguments can expose different fault-time state.
- Promoted repaired `00533240 handle_points_highest_attribute` to `accepted_drift`.
  The independent review confirms the greater-peer exit, unordered x87 equality, signed loop bound, owner, and boundary.
  Its 21 byte differences only exchange registers.
- `00531750 RGE_Victory_Conditions` and `005324A0 handle_destroy_all` remain scratch.
  Invalid objects can change field-read fault order, and malformed list nodes can alter saved EBP at failure.
