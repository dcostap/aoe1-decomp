# effects.cpp source-module recovery

The source module is `C:\\msdev\\work\\age1_x1\\effects.cpp`. The five
handwritten owners stay in PDB order:

- `004490E0` `RGE_Effects::RGE_Effects(int)` lines 21-63, 352 bytes.
- `00449260` `RGE_Effects::RGE_Effects(char*)` lines 68-129, 478 bytes.
- `00449440` `RGE_Effects::~RGE_Effects()` lines 134-149, 99 bytes.
- `004494B0` `RGE_Effects::save(int)` lines 154-180, 265 bytes.
- `004495C0` `RGE_Effects::do_effect(short, RGE_Player*)` lines 186-274,
  301 bytes.

`00449240` is the compiler-generated scalar deleting destructor between the
constructors. It has no handwritten source owner.

The two constructors remain accepted drift. Their source retains the proven
record widths (`RGE_Effect` is `0x2C`; `RGE_Effect_Command` is `0x0C`), call
order, stores, cleanup, and failure behavior. The int constructor has a
four-byte instruction-order residual. The path constructor has a localized
conditional-register-save and signed-loop-compare residual. The destructor,
save, and do_effect owners are exact.

## Cross-shard ABI needs

`RGE_Effects` has size `0x0C`, with `effects` at `+0x04` and `effect_num` at
`+0x08`. Its destructor, save, and do_effect virtual slots are `0x00`, `0x04`,
and `0x08`. This surface is proved by `inventory/classes/dumps/RGE_Effects.txt`
and the effects.cpp assembly.

The `teffects.cpp` constructors directly call the two RGE_Effects constructors
at `0050D468` and `0050D4B8`. Keep the `teffects.cpp` declaration surface ABI
compatible. This migration does not edit `include/teffects_context.h` or
`src/teffects_tu.cpp`.

`do_effect` dispatches through the RGE_Player virtual slot at `+0x78`. The
complete local RGE_Player virtual declaration remains in `src/effects.cpp`.
A future shared RGE_Player declaration needs proof against that slot and the
other player translation units. This migration does not edit shared player
headers.
