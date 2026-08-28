# spnl_obj.cpp source recovery

## Context

- PDB source: `C:\msdev\work\age1_x1\spnl_obj.cpp`.
- PDB line bands prove this source order: 48-52, 58, 63-70, 78-325,
  333-382, 390-397, and 406-423.
- All seven normal owners have the PDB class
  `TRIBE_Scenario_Editor_Panel_Object`.
- The constructor call, derived vptr store, panel calls, object fields, and
  GDI calls anchor the class and module.
- `004BEE10` is the compiler-generated scalar deleting destructor.

## Source model

- `src/spnl_obj.cpp` owns all seven normal bodies in PDB order.
- `include/spnl_obj.h` owns the derived panel declaration.
- `include/tpnl_obj.h` owns the base panel declaration.
- The source uses typed master-combat armor records and the building-master
  facet. It has no raw member offset or vptr write.
- `rge_base_game` uses the reviewed global provider.

## Validation

`validate_candidate_tu.py` compiled the direct module on 2026-08-28.

- Exact: `004BEDC0`, `004BEE30`, `004BEE40`, `004BF4D0`, and `004BF6E0`.
  Each reports `MATCH`, `0.0000%`, matching owner, no relocation mismatch,
  and no boundary escape.
- Generated `004BEE10` reports `MATCH`. The generated-body owner is
  unverified by design.
- Scratch `004BEE70` reports 120 differing bytes of 1577 (7.6094%). It has
  the correct owner, no relocation mismatch, and no boundary escape.
- Scratch `004BF6C0` reports 18 differing bytes. The original reads
  `prog_mode` after `release_mouse`. No source condition supports this read.
  The natural body does not model it. This is not accepted drift.
- `0051ADF0` remains `MATCH` after the base-panel provider composition.

## Open work

- Recover the remaining schedule differences in `draw` without compiler-only
  source forms.
- Find a natural source reason for the required unused `prog_mode` read in
  `mouse_left_up_action`.
