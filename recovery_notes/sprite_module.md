# sprite.cpp source module

- PDB source: `C:\\msdev\\work\\age1_x1\\sprite.cpp`.
- Source: `src/sprite.cpp`.
- Header: `include/sprite.h`.
- The source keeps all 22 normal owners in PDB order.
- The module uses `/O2 /Oy /GX` from `config/flags/004C0960_get_frame.rsp`.

## Module merge

The source moved every sprite owner into one natural C++ module. The header now
owns the sprite, shape, sound, picture-list, color-table, clip-list, and active
sprite layouts used by this source.

The merge removes the owner wrapper, the `sprite_get_frame_tu.cpp` wrapper, all
sprite function fragments, and the old context headers. It does not tune source
for byte output.

The translation-unit manifest keeps the 13 reviewed exact owners registered.
The other nine owners keep their reviewed module states. Temporary exactness
regressions after the merge are expected until grouped recovery runs again.

## Integration audit

The 2026-08-27 grouped compile covered all 22 owners. All 13 registered owners
still match. The five accepted-drift owners keep their reviewed classifications:
`004BF790` has 227 differing bytes, `004BFA20` has 142, `004C00E0` has 93,
`004C0B70` has 37, and `004C0D80` has 33. Each has matching calls,
relocations, and boundary evidence for its reviewed scope.

The merge introduces two local context regressions. `004C0720 shadow_draw`
has two SIB-register bytes changed, and `004C0C90 hit_test` has two changed
bytes. Both remain `matching` in the module manifest with this regression
record. Exact repair resumes after the final source context is fixed.

`004C01A0 do_draw` remains `scratch` with 375 differing bytes. `004C1080
update` remains `verified_logic`; its grouped rebuild is 125 bytes with 75
strict differences and a two-byte reachable boundary escape. Its old shared
double-zero declaration is absent from the current global surface. The main
agent must review that cross-shard dependency before exact repair.
