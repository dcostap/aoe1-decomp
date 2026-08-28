# scr_sed.cpp recovery

## Source context

PDB source: `C:\msdev\work\age1_x1\scr_sed.cpp`.
The module has 47 normal owners. Their source lines run from 249 through 3670.
`004A8750` is the compiler-generated vector deleting destructor.
`TRIBE_Screen_Sed` owns 46 methods. `004AB2D0` is the module free comparator.

## Migration

`include/scr_sed.h` now owns only `TRIBE_Screen_Sed` and its nested `List_Info`
record. `Pnl_scr.h` owns the screen base. The source consumes canonical panel,
control, game, world, player, scenario, map, view, object, sprite, technology,
dialog, save-screen, open-screen, registry, and sound headers. It has no
wrapper, context-selection macro, fragment include, copied foreign layout,
local vtable, or raw panel cursor. Three former alignment gaps are now compiler
alignment. The size check remains `0x948`.

The source owns all 47 normal bodies in PDB order. The translation-unit entry
registers only exact owners. Non-exact statuses retain a source note here.

## Hardening

`scenario_default_file_name` is the named 260-byte module buffer used by the
default-save path. The event ABI carries an unsigned long, but this screen
consumes its selection value as an object pointer at one documented ABI
boundary.
The diplomacy controls use one typed two-dimensional array. The action uses
separate selection coordinates, save-seed state, and text storage.
`command_new_map` passes the complete `RGE_Map_Gen_Info` record to
`RGE_Player_Info` and compares the tribe against `master_player_num`.

`set_unit_player` owns its `List_Info` and string storage with C++ arrays. The
destructor releases the arrays with matching `delete[]` operations. No source
body uses a raw global address, a diplomacy union, an action random-value
overlay, or the old map-info record overlay. The action keeps one documented
integer-to-pointer cast at the PDB-proven event ABI boundary.

## Recovery states

The natural module validation reports 36 exact functions, four accepted-drift
functions, and seven scratch functions:

- `004A8A60 create_drop_down`: the structured source differs from the shipped
  decompiler control-flow shape.
- `004A94A0 ~TRIBE_Screen_Sed`: direct typed child deletion changes the body
  and escapes its owner boundary.
- `004A9CC0 set_scenario_mode`: one cursor register allocation differs.
- `004AA730 set_paint_object_mode`: player and world loads use different
  registers.
- `004AAB60 set_player`: canonical provider calls change the natural body.
- `004AB300 set_unit_player`: canonical provider calls change the natural body.
- `004AB670 set_unit`: VC5 exchanges ESI and EDI.
- `004AB7D0 handle_idle`: canonical provider calls change the natural body.
- `004ABCD0 action`: source behavior is recovered, but its large codegen gap
  remains open.
- `004AD340 command_new_map`: canonical map and world providers change the
  natural body. The `&map_info` record is correct. The complete canonical
  record moves `land.clump_num` by two bytes, so the body remains scratch.
- `004AD630 command_outline`: VC5 changes zero extension and register
  allocation.

The accepted-drift functions retain their reviewed status. The six scratch
functions remain scratch until new executable evidence or a behavior review
resolves their natural differences.

## Provider composition

The source composes `vw_main.h`, `vw_dimap.h`, `spnl_obj.h`, `scr_sedo.h`,
`scr_save.h`, and `dlg_sedm.h`. The source uses `RGE_Map::map_generate2`,
`RGE_Scenario::save_scenario`, and the canonical `T_Scenario` API. It uses
direct typed deletion for the scenario-editor child panels.

`scr_save.h` is the full owner header for all five normal `scr_save.cpp`
bodies. `dlg_sedm.h` is the full owner header for its dialog class. They contain
no panel copies or size-only fallback classes.

## Candidate validation

Candidate: `build/scr_sed_canonical_candidate.json`.
Report: `build/candidate_tus/scr_sed_final_rebased/report.json`.

The grouped candidate compiled all 47 normal bodies and the generated vector
deleting destructor. It reports zero comparison errors. It reports zero
relocation target mismatches for every normal body. The 36 exact bodies have
zero boundary escapes. The six scratch body boundary values are recorded in
the recovery states above.
