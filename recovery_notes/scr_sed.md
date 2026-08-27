# scr_sed.cpp recovery

## Source context

PDB source: `C:\msdev\work\age1_x1\scr_sed.cpp`.

The module has 47 normal owners. The PDB line order is 249 through 3670.
The nearby `004A8750` vector deleting destructor is compiler generated.
It has no source body in this module.

`TRIBE_Screen_Sed` owns 46 methods. `004AB2D0` is the module free comparator.
The final owner is `TRIBE_Screen_Sed::set_focus`.

## Recovery states

The module has 41 matching functions, five accepted-drift functions, and one scratch function.

- `004A8A60 create_drop_down`: one SIB operand order differs. Its address and effects match.
- `004A9CC0 set_scenario_mode`: one cursor register allocation differs. Its calls and effects match.
- `004AA730 set_paint_object_mode`: the player and world loads use different registers.
- `004AB670 set_unit`: VC5 exchanges ESI and EDI.
- `004AD630 command_outline`: VC5 changes zero extension and register allocation.
- `004ABCD0 action`: source behavior is recovered. Its large control-flow and codegen gap remains open.

Keep accepted-drift status unless new executable evidence shows a behavior difference.

## Migration record

The old `scr_sed_prefix` and `scr_sed_save_as` wrappers joined the 47 bodies with context macros and field aliases.
The migration moved each body into `src/scr_sed.cpp` in PDB order.
`include/scr_sed.h` now owns the module declarations.

The module source uses real panel, game, scenario, and world declarations.
It does not use wrapper macros, `.cpp` includes, fake layouts, raw vptrs, or manual virtual dispatch.

The final `/GX` candidate TU matched 33 exact owners. It retained all 30 prior exact owners.
It added `004AD270`, `004AD590`, and `004AD700` as exact owners.
The 14 observed owners stayed nonexact. No status changed during the migration.

The source-shape regression set has eight matching-status owners:
`004A81E0`, `004A94A0`, `004AA7A0`, `004AA8F0`, `004AAB60`, `004AAE20`, `004AB300`, and `004AD680`.
Their candidate differences are 428, 1191, 5, 17, 231, 1, 2, and 1 bytes.
The five accepted-drift owners and the scratch `004ABCD0` stayed nonexact as expected.

Run a candidate TU check before new exact claims. Check direct call targets and boundaries for every claimed match.
