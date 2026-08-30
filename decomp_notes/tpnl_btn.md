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

## Scratch: 00519F40 draw

The former accepted-drift decision is invalid. The living source passes
`0x00FF00FF` to `_ASMSet_Shadowing`, but the original passes `0xFF00FF00`.
This changes behavior.

A natural corrected candidate now passes `0xFF00FF00`, restores type-0 `y`
evaluation and the pre-`SetClipRect` increments, and uses the direct
`border_frame + (is_down != 0)` expression. It preserves size, frame, 42
calls, CFG, relocations, and fault order. The focused check reports 18
positional bytes different (1.1443%), 99.81% shape similarity, and a
`CONSISTENT_REGISTER_RECOLOR` diagnostic. Keep the function in scratch until
the coordinator completes drift review.

Evidence is under `build/audits/workers/semantic-00519F40/`.

The focused validation checkpoint is `probe-058-validation`. The grouped
`tpnl_btn` validation output is under
`build/audits/workers/wave21-tpnl-btn-integrate/tpnl_btn/`.

## Rebased integration proof

The fresh grouped proof is `build/candidate_tus/tpnl_btn_integration_proof`.
All six registered exact owners report `MATCH` and `0.0000%`. The generated
deleting destructor also matches. The `draw` result remains unregistered
scratch.
