# teffects.cpp source-module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\teffects.cpp`.
- Source: `src/teffects.cpp`.
- Header: `include/teffects.h`.
- Flags: `config/flags/default.rsp`.
- PDB source lines: 22 to 114.

## Ownership and order

The module has four normal owners.  Their PDB source order is:

1. `0050D460` `TRIBE_Effects::TRIBE_Effects(int)`, lines 22-23.
2. `0050D4B0` `TRIBE_Effects::TRIBE_Effects(char*)`, lines 29-30.
3. `0050D4D0` `TRIBE_Effects::do_effect(short, RGE_Player*)`, lines 36-77.
4. `0050D550` `TRIBE_Effects::do_tech_effect(short, RGE_Player*)`, lines 83-114.

The nearby `0050D480` vector-deleting destructor is compiler-generated.  It is
not a normal source owner.

All four owners were matching-bank sources before this migration.  Their
pre-migration checks reported `MATCH` with `0.0000%` positional difference.
The captain did not run a post-migration compiler or checker under the Terra
captain contract.  The lead must validate the direct source module.

## Layout and call surface

`RGE_Effects` uses the reviewed `effects_context.h` declaration.  This keeps
the `effects` pointer at `+0x04`, `effect_num` at `+0x08`, and the object size
at `0x0C` without copying that layout into this module header.

The effect loop keeps the binary-proven record stride of `0x2C`, command stride
of `0x0C`, and kind values `0x65` and `0x66`.  The `0x66` arm converts the
record float through `__ftol` and calls `TRIBE_Player::tech_abling` with zero.

The header declares only the direct `TRIBE_Player::tech_abling(long,
unsigned char)` call surface.  It does not copy the complete player layout.

## Cross-shard request

No shared layout file was changed.  The coordinator should later expose one
reviewed `TRIBE_Player::tech_abling(long, unsigned char)` declaration from the
canonical player ABI header.  Current evidence is the direct target
`00513DA0`, the `__thiscall` receiver in `ECX`, and matching calls from this
module and `tscenaro.cpp`.

Affected modules are `teffects.cpp`, `tplayer.cpp`, and `tscenaro.cpp`.
Validate the change by rebuilding those modules, checking the decorated direct
target `?tech_abling@TRIBE_Player@@QAEXJE@Z`, and rerunning their registered
owners.  Do not add a copied player layout to this module as a shortcut.
