# tpnl_btn.cpp recovery note

## Context and ownership

PDB maps `C:\msdev\work\age1_x1\tpnl_btn.cpp` to seven normal bodies.
The source lines are 50-68, 74-82, 88-100, 109-317, and 320-334.

`TRIBE_Panel_Button` owns all seven bodies. It derives from the canonical
`TButtonPanel` provider. `TButtonPanel` derives from the canonical `TPanel`
provider.

The address order is `00519DA0`, `00519EA0`, `00519EE0`, `00519F40`,
`0051A570`, `0051A590`, and `0051A5B0`. The deleting destructor at
`00519E70` is compiler-generated.

The constructor, `set_text_msg`, `is_inside`, and three garrison methods are
exact anchors. They prove the class size, base relation, direct calls, and
virtual slots used by this module.

## Direct module result

`src/tpnl_btn.cpp` is the only compiler-facing owner. It uses the canonical
button, screen, and map-view providers. `is_inside` uses a typed screen cast.

The candidate `build/candidate_tus/tpnl_btn_natural_retry` reports `MATCH`
and `0.0000%` for all six exact owners. It also reports a `MATCH` for the
generated deleting destructor `00519E70`. Boundaries, direct targets, and
relocations match for each exact owner.

## Accepted drift: 00519F40 draw

Keep `draw` as accepted drift. The direct module has 559 positional bytes that
differ. The candidate confirms the same owner symbol with no relocation-target
or boundary errors.

The prior review proves the draw calls, arguments, panel stores, GDI state,
unlock calls, and returns. The residual is limited to private local homes,
register allocation, and a small CFG layout difference. Do not reopen this
status without new executable evidence.

## Rebased integration proof

The fresh grouped proof is `build/candidate_tus/tpnl_btn_integration_proof`.
All six registered exact owners report `MATCH` and `0.0000%`. The generated
deleting destructor also matches. The accepted-drift `draw` result remains
unregistered.
