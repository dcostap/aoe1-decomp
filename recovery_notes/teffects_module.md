# teffects.cpp source-module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\teffects.cpp`.
- Source: `src/teffects.cpp`.
- Headers: `include/effects.h`, `include/teffects.h`, and `include/tplayer.h`.
- PDB source lines: 22 to 114.

## Ownership and order

The module has four normal owners. Their PDB source order is:

1. `0050D460` `TRIBE_Effects::TRIBE_Effects(int)`, lines 22-23.
2. `0050D4B0` `TRIBE_Effects::TRIBE_Effects(char*)`, lines 29-30.
3. `0050D4D0` `TRIBE_Effects::do_effect(short, RGE_Player*)`, lines 36-77.
4. `0050D550` `TRIBE_Effects::do_tech_effect(short, RGE_Player*)`, lines 83-114.

The nearby `0050D480` vector-deleting destructor is compiler-generated. It is
not a normal source owner.

The four owner bodies now occur in `src/teffects.cpp` in this order. The old
wrapper and per-function source files are removed. The source uses the
canonical headers directly. No context header, wrapper include, or partial
carrier declaration remains.

## Layout and call surface

`include/effects.h` owns `RGE_Effect_Command`, `RGE_Effect`, and `RGE_Effects`.
`include/teffects.h` owns the empty `TRIBE_Effects` derivation and includes the
effects owner. `include/tplayer.h` owns `TRIBE_Player` and declares
`tech_abling(long, unsigned char)`.

The module copies no effects record, player, world, or base-game layout. The
PDB class inventory proves that `TRIBE_Effects` derives from `RGE_Effects`, has
no fields of its own, and has size `0x0C`. The source now accesses the effect
array through `RGE_Effect`, its `effect_list_num` and `effect_list` fields, and
the command array through `RGE_Effect_Command`. The proven command values are
`0x65` and `0x66`. The `0x66` arm converts `change_amount` through `__ftol` and
calls `TRIBE_Player::tech_abling` with zero.

## Candidate status

This commit is a source migration candidate. It was not compiled or checked.
The global translation-unit and source-module metadata remain coordinator
owned and are unchanged in this commit. The lead must review the direct
metadata before building or validating the candidate. The lead can then check
all four owners, boundaries, relocations, and direct targets.
