# Header-owned source audit

Status: complete.

This audit removes duplicate source-bank probes for header-owned and generated
functions. The original inventory and PDB records remain the evidence source.
Header source text is now the only handwritten owner for these rows.

## Final counts

| Group | Count |
| --- | ---: |
| Valid unresolved header-owned normal rows | 105 |
| Normal canonical-owner rows without duplicate probes | 6 |
| Newly classified compiler-generated rows | 29 |
| Existing intentional unclaimed exceptions before this closure | 60 |
| Normal corpus rows | 5,428 |
| Compiler-generated corpus rows | 256 |

The six normal rows remain in the normal corpus. Their standalone probes are
removed because their canonical bodies already exist:

- `00424DD0` and `00424E30`: `include/com_addr.h` (`IPAD` constructor and
  destructor).
- `00426450`, `004264A0`, `004265E0`, and `00426600`:
  `src/com_hand.cpp` with declarations in `include/com_hand.h` (`RESENDER`
  and `HOLDER` constructors and destructors).

The deleted files for these rows were duplicate probes, not source owners.
The inventory records their PDB header or source-module ownership.

`004147A0` remains a normal unresolved header-owned row. Its PDB record proves
protected `ManagedArray<int>::resize(int)` ownership, but reconstructed external
callers still depend on the current public header access. The body is in
`include/utmarray.h` under its current public access. The access debt remains
documented in `docs/utmarray_reconstruction.md`.

The four additional normal header rows are also closed:

- `0046ED40` `RGE_Player::logStatus`: `include/player.h`.
- `00540A10` `RGE_Game_World::logStatus`: `include/world.h`, protected.
- `00431F60` and `00431F80` `MsgQueue` constructor and destructor:
  `include/com_q.h`.

The PDB maps these four rows to headers. It does not prove a separate `.cpp`
source owner. The two `logStatus` definitions were removed from their module
sources. The `MsgQueue` definitions were already canonical header bodies.

The header-owned normal rows are not registered translation-unit owners. Their
current body status is unresolved unless a grouped check proves an emitting
translation-unit owner. This preserves source ownership without inventing a
`.cpp` owner.

## Canonical normal row list

The verified normal row list is:

```text
stat_obj.h: 00405D00 00405D10 00405D20 00405D30 00405D40 00405D50
00405D60 00405D70 00405D80 00405D90 00405DA0 00405DB0 00405DC0
00405DD0 00405DE0 00405DF0 00405E00 00405E10 00405E20 00405E30
00405E40 00405E50 00405E60 00405E70 00405E80 00405E90 00405EA0
00405EB0 00405EC0 00405ED0 00405EE0 00405EF0 00405F00 00405F10
00405F20 00405F30 0041A450 0041A460 0041A470 0041A480 0041A490
0041A4A0 0041A4B0 0041A4C0 0041A4D0 0041A4E0 0041A4F0 0041A500
0041A510 0041A520 0041A530 0041A540 0041A550 0041A560 0041A570
0041A580 0041A590 0041A5A0 0041A5B0 0041A5C0 0041A5D0 0041A5E0
0041A5F0 0041A600 0041A610 0041A620 0041A630 004C1CE0
panel.h: 00437110 00437230 00437240 00437250 00437260 00437270
00437280 00437290 004372A0 004372B0 00437490 004374A0 004374B0 00437610
player.h: 0046EC80 0046EC90 0046ECA0 0046ECB0 0046ECC0 0046ECD0
0046ED30 0046ED40
aimodule.h: 004087F0 00408800 00408810
dlg_list.h: 0043F320 0043F330
move_obj.h: 00405F50 00405F60
scenario.h: 0048B580 0048B590
aiuaimod.h: 004138B0
ani_obj.h: 00405F40
utmarray.h: 004147A0
world.h: 00540A10
com_q.h: 00431F60 00431F80
```

The five generated `ManagedArray<int>` rows at `00408D20`, `004DE980`,
`004DE9D0`, `004EA750`, and `004F1390` remain covered by the generated
template evidence. They are not normal rows in this list.

## Focused validation

Pinned VC5 header emission checks report `MATCH`, `0.0000%`, correct symbols,
relocations, and boundaries for the 68 `stat_obj.h` rows and the normal rows
in `panel.h`, `player.h`, `aimodule.h`, `move_obj.h`, `scenario.h`,
`aiuaimod.h`, `ani_obj.h`, `world.h`, and `com_q.h`.

The Static Object float defaults use natural `1.0f`, `0.0f`, and `-1.0f`
literals. They do not use fixed-address data carriers. `XYZPoint` keeps its
CodeView class definition after a struct forward declaration. This reproduces
the original `U` symbol tag for the by-value and reference methods. The direct
Moving Object candidate then keeps all 38 registered owners exact.

`0043F320` remains scratch by policy. `004147A0` emits the current public body,
but validation still reports the missing protected symbol. The direct Player
module retains one known migration regression at `004705A0`; its owner stays
registered and the source remains natural.

## Newly classified generated rows

The manifest adds these rows:

- `00408D20`, `004EA750`, and `004F1390`:
  `compiler_generated_template_instantiation` for `ManagedArray<int>` methods
  emitted from `include/utmarray.h`.
- `00404A00`, `00404C80`, `00406DB0`, `0041A200`, `00441A60`, `004754B0`,
  `004CCB10`, `004CCBF0`, `004CD200`, `004CDA80`, `004CE5E0`, `004CE980`,
  `004CF120`, `004D1710`, `004D2700`, `004D3970`, `004E68F0`, `00509760`,
  `0050D4A0`, `00520E20`, `0052AB80`, `0052CA20`, and `0053D3A0`:
  `compiler_generated_destructor` bodies.
- `00463BA0`, `00463BC0`, and `00463BD0`:
  `compiler_generated_static_initializer` entries for the `E4`, `E3`, and
  `E2` startup and cleanup sequence.

The 26 PDB-less rows have no PDB source file or line record. Their inventory
records and Ghidra listings show either a direct jump to the base destructor
or the static initializer sequence. This is generated evidence, not a new
normal source owner.

## Deleted-file verification

All 29 generated source-bank files named by the manifest rows were deleted.
The three generated `ManagedArray<int>` methods are covered by the exact
header method records in `docs/utmarray_reconstruction.md`.
The 23 scalar-destructor probes have matching destructor symbols and direct
base-destructor evidence in `inventory/functions/` and the original Ghidra
listings. The three `00463BA0`-`00463BD0` probes have the `E4`/`E3`/`E2`
sequence in `orig/ghidra_decomp/bucket_0463.{asm,decomp}`.

The six normal duplicate probes have named canonical owners above. No deleted
file lacks either a canonical body or generated evidence.

The 101 normal source-bank probes covered by the first audit are deleted. The
two additional scratch probes, `004147A0` and `0043F320`, are also deleted
after their reviewed bodies were confirmed in `utmarray.h` and `dlg_list.h`.
