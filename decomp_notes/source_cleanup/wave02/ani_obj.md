# `src/ani_obj.cpp` cleanup report

## Scope and commits

- Module: `src/ani_obj.cpp`
- Header owner: owner 09 owns `include/ani_obj.h`; this worker did not edit it.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final commit: see the full Git hash in the delivery record.
- Changed files:
  - `src/ani_obj.cpp`
  - `decomp_notes/source_cleanup/wave02/ani_obj.md`

The source keeps the ten handwritten functions in PDB source order. It restores
procedure-scoped PDB parameter names and moves function braces to 1TBS style.
It does not change types, calls, literals, scopes, evaluation order, or layouts.

Evidence identity used during review:

- Original executable:
  `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
  SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Baseline report:
  `build/source-cleanup-20260915/preparation/baseline-build/report.json`.
  It records the registry route, `config/flags/gx.rsp`, and the prior
  `src/ani_obj.cpp` SHA256 `f25e8dcf88a0d57a71decc43cd494652016ffa2d303710a3d941d8e96ae92fe6`.
- Resource inputs were not queried because this module has no resource lookup.
  Their reviewed file hashes are `runtime/language.dll`:
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`,
  `runtime/languagex.dll`:
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, and
  original `XPack/languagex.dll`:
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

## PDB coverage and name recovery

The source registry packet `config/functions/src/ani_obj.cpp.json` selects these
functions. The scoped PDB record is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Every assigned source function has a scoped PDB record: 10 of 10. Each record
has the `this` register in `ecx`. No function-static or local PDB records exist
for these ten functions.

| VA | Function | PDB source span | Scoped stack symbols |
| --- | --- | --- | --- |
| `0041A150` | first constructor | `ani_obj.cpp:29-32` | `+0x4 tobj`, `+0x8 obj_owner`, `+0xc x`, `+0x10 y`, `+0x14 z`, `+0x18 do_setup` |
| `0041A210` | second constructor | `ani_obj.cpp:38-41` | `+0x4 infile`, `+0x8 gworld`, `+0xc do_setup` |
| `0041A280` | `recycle_in_to_game` | `ani_obj.cpp:46-51` | `+0x4 tobj`, `+0x8 obj_owner`, `+0xc x`, `+0x10 y`, `+0x14 z` |
| `0041A2C0` | master-based `setup` | `ani_obj.cpp:55-63` | `+0x4 tobj`, `+0x8 obj_owner`, `+0xc x`, `+0x10 y`, `+0x14 z` |
| `0041A310` | file-based `setup` | `ani_obj.cpp:67-75` | `+0x4 infile`, `+0x8 gworld` |
| `0041A350` | `update` | `ani_obj.cpp:79-125` | none; no parameters beyond `this` |
| `0041A3D0` | `save` | `ani_obj.cpp:129-134` | `+0x4 outfile` |
| `0041A400` | `transform` | `ani_obj.cpp:138-140` | `+0x4 obj` |
| `0041A410` | `set_being_worked_on` | `ani_obj.cpp:145-147` | `+0x4 work_obj`, `+0x8 action_type`, `+0xc attack_flag` |
| `0041A430` | `release_being_worked_on` | `ani_obj.cpp:152-160` | `+0x4 caller` |

The exact PDB types match the source declarations: the pointer parameters use
the recorded master, player, world, action, and static-object types; `x`, `y`,
and `z` are `float`; `do_setup` and file handles are `int`; `action_type` is
`short`; and `attack_flag` is `unsigned char`.

The names above are recovered originals from the PDB, not new descriptive
names. The prior source used these substitutes: `master`, `player`, `id`,
`world`, `file`, `action`, `mode`, `flag`, `object`, and `master` in the
relevant declarations. The PDB records prove each replacement by stack offset,
type, and procedure ownership.

`update` has existing descriptive locals `result`, `state`, `master`,
`animating`, and `game_world`. The scoped PDB record has no local symbols, so
these names remain unchanged. Their storage mapping is not claimed as PDB
recovery. No uncertain reused stack-slot mapping was forced.

The compiler-generated scalar deleting destructor at `0041A1E0` and destructor
at `0041A200` are adjacent records without handwritten source bodies. The inline
`getSpeed` definition is emitted from `src/act_obj.cpp` by the header declaration
and is outside this source owner. Neither was edited.

## Constants, resources, and comments

No resource lookup occurs in this module. No resource ID request is needed.
No new constants or comments were added. Existing values remain unchanged:
`0x14` is the animated object type written at `0041A2E7` and `0041A323` in the
original packet; update states `3`, `4`, and `5`, and speed reset `0.0f` remain
as in the source and original assembly packets. No existing symbol was replaced
without proof.

The source uses no header declaration that needs a parameter-name change for
correctness. Therefore, no request was sent to header owner 09.

## Code-generation and unresolved items

The edits rename parameters and change opening-brace placement only. They do
not alter an ABI name, type, declaration scope, call target, cast, literal,
statement order, or storage layout. Brace movement can change debug line
metadata, but no line-dependent macro occurs in this file. The compiler output
was not checked in this wave.

Unresolved: the PDB does not name the five `update` locals. Existing descriptive
names remain because their uses are clear, but they are not claimed as recovered
original names. No other declaration mapping remains unresolved.

## Validation status

Compilation, matching, audits, and tests were not run. No compiler, build,
matching, audit, test, or game command was run for this assignment.
