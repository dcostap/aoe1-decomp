# Twenty-worker matching wave

## Scope

The wave assigned 20 normal functions in 20 distinct natural translation units.
Each worker could edit one function and one function journal. Workers did not
change shared files, status, registration, the Git index, or commits.

All workers used the pinned VC5 toolchain. The coordinator reviewed each result
before integration.

## Exact results

The coordinator approved and registered these 12 exact owners:

- `00412100 ResourceItem operator==`;
- `004325E0 TCommunications_Sessions::IsEqualGuid`;
- `00433D40 RGE_Command::RGE_Command`;
- `00449710 compareFilenameStrings`;
- `00467A50 TEasy_Panel::set_ideal_size`;
- `004751E0 TDropDownPanel::set_tab_order`;
- `00484B50 RGE_RMM_Elevation_Generator::count_map_tiles`;
- `00498A10 TRIBE_Screen_Game::game_mode_changed`;
- `004BE1F0 TSpan_List_Manager::AddMiniList`;
- `00519D50 TRIBE_Player::scenario_postload`;
- `0052A170 TRIBE_Game::resetRandomComputerName`; and
- `00534500 RGE_View::set_player`.

Each owner reports `MATCH`, `0.0000%`, the correct symbol, a closed boundary,
and compatible relocations and direct targets.

## Accepted drift

The coordinator approved four narrow accepted-drift results:

- `004786B0 TListPanel::item_at`: two independent field loads change order.
- `00488E60 RGE_RMM_Terrain_Generator::count_map_tiles`: the commutative
  dimension loads change order.
- `004D68A0 TribeConstructionAIModule::compare`: register allocation changes
  around the same two left-first calls.
- `004D0EB0 TRIBE_Action_Make_Obj`: the implicit vptr store moves across one
  ordinary member store.

These bodies keep the same values, calls, bounds, returns, owners, and original
function boundaries. None has a wrong target or boundary escape.

## Remaining scratch

Four assigned functions remain scratch:

- `00401EC0 do_attack`: the natural translation unit does not emit the symbol.
- `0043FC70 TMessageDialog`: broad constructor scheduling drift remains.
- `0046B5E0 PathingSystem::obstruction`: broad shape drift and a boundary
  escape remain.
- `004BF6C0 mouse_left_up_action`: the rebuild omits the original unused read.

The coordinator rejected broad drift and changed fault behavior as accepted
drift.

## Shared ABI and compiler context

The wave found three shared issues:

- `TEasy_Panel::set_ideal_size` was public. PDB proves protected access.
- `compareFilenameStrings` used `const char*`. PDB proves `const void*`.
- `com_sess` lacked the VC5 `_OLE32_` context. That context selects the SDK
  four-dword GUID comparison.

The coordinator repaired each issue. Focused and grouped checks pass.

## Exact-claim reconciliation

The first sequential audit disproved nine stale exact claims. The coordinator
moved them to scratch and removed their exact registrations:

- `004348B0`, `004348F0`, `00434DC0`, `00435020`, `00435060`, and `004350A0`
  in Command;
- `004BE4B0 DeleteShape` in spanlist;
- `00524880 calc_timing_text` in tribegam; and
- `00539AA0 get_tile_picture` in View.

The audit also found no emitted `0046D830 copyPath` symbol. The coordinator
moved that row from accepted drift to scratch.

The final 20-group sequential audit compiled 750 normal functions. All 546
registered owners match. It reports no registered regression.

The first full repository audit found eight more stale exact claims outside
the assigned groups. The coordinator moved these rows to scratch:

- `004421F0 add_doppleganger_check`;
- `00473D60 TDialogPanel::setup`;
- `00485E50 generate_objects`;
- `004D9110 fullyExploredZone`;
- `004D9160 setFullyExploredZone`;
- `004E0FD0 storeAttackMemory`;
- `005327A0 handle_explore`; and
- `0053C290 RGE_Visible_Map`.

`00463BB0 $E1` remains scratch. Its grouped body has no verified original owner
symbol, so it cannot become an exact owner.

The same full audit found 23 exact natural owners without registration. The
coordinator promoted and registered all 23:

- `004350E0`, `00438060`, `00446780`, `00446800`, `00446C80`, `00446D10`;
- `0045A500`, `00460940`, `0046A810`, `0046A8E0`, `0046A9E0`, `00470F80`;
- `00473C80`, `0047E580`, `004CD210`, `004D5F00`, `004FB710`;
- `00509C60`, `00509E10`, `0050DE50`, `00514590`, `00532610`; and
- `00532CC0`.

Each row has zero byte drift, a matching owner, a closed boundary, and safe
relocations and direct targets.

## Workflow and tooling findings

The shared-source lease model prevented source conflicts. No worker staged or
committed files.

Twenty simultaneous redundant `start` calls caused session-lock queues. Some
checks, pauses, and releases timed out. Two stale leases required coordinator
cleanup.

The original sequential preclaim took 6 minutes and 5 seconds. The tool now has
`start --preclaim`, which skips metric collection and the full briefing. A smoke
preclaim took 3 seconds. A repeated same-owner start used the new fast path and
took less than 1 second.

The worker workflow now tells preclaimed workers to use `brief`, not `start`.
It also requires enough materially different natural attempts before an
unresolved return.

Coordinator review caught two source-policy issues:

- a raw three-byte record stride; and
- a redundant explicit terrain mask.

The workers corrected both issues before integration.

Several worker journals gained mixed line endings. The coordinator restored the
tracked line-ending style before commit.

## Validation

Important reports are:

- `build/audits/integration/wave20-release/report.json`;
- `build/audits/integration/wave20-final-full-release/report.json`;
- `build/audits/integration/wave20-reconciled-groups/report.json`;
- `build/audits/integration/wave20-shared-fixes/report.json`; and
- `build/audits/integration/wave20-flag-audit.json`.

The focused integration suite passed 75 tests. The target-session hardening
subset passed 37 tests. The flag audit reports zero blocking issues.
