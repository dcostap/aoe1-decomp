# `src/airesitm.cpp` cleanup

## Delivery

- Module: `src/airesitm.cpp`
- Header owner: owner 06, `include/airesitm.h`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `a7914437e13b44d43e1bc1470238240ae991e677`
- Changed files: `src/airesitm.cpp`, this report
- Header changes: none

The cleanup restores procedure-scoped PDB parameter names. It preserves source
order, types, expressions, declarations, calls, literals, and control flow.

## PDB coverage

I inspected all 16 functions in `config/functions/src/airesitm.cpp.json`.
The PDB source path is `C:\msdev\work\age1_x1\airesitm.cpp`.
The PDB module object is `.\\Release\\airesitm.obj` for every procedure.

| VA | PDB lines | Parameters | Locals | Registers |
| --- | ---: | --- | --- | --- |
| `00411EC0` | 26-32 | none | none | `this: ResourceItem*` in `ecx` |
| `00411F10` | 40-51 | `n: int` | none | `this: ResourceItem*` in `ecx` |
| `00411F80` | 59-70 | `n: int`, `v: int*` | none | `this: ResourceItem*` in `ecx` |
| `00411FF0` | 78-84 | `ri: const ResourceItem&` | none | `this: ResourceItem*` in `ecx` |
| `00412050` | 92-98 | `ri: ResourceItem*` | none | `this: ResourceItem*` in `ecx` |
| `004120B0` | 103-104 | none | none | `this: ResourceItem*` in `ecx` |
| `004120C0` | 109-115 | `ri: const ResourceItem&` | none | `this: ResourceItem*` in `ecx` |
| `00412100` | 120-128 | `one: const ResourceItem&`, `two: const ResourceItem&` | none | none |
| `00412140` | 133-141 | `one: const ResourceItem&`, `two: const ResourceItem&` | none | none |
| `00412180` | 146-150 | `n: int` | none | `this: const ResourceItem*` in `ecx` |
| `004121A0` | 155-159 | `n: int`, `v: int` | none | `this: ResourceItem*` in `ecx` |
| `004121C0` | 164-168 | `n: int`, `v: int` | none | `this: ResourceItem*` in `ecx` |
| `004121E0` | 173-176 | `v: int` | none | `this: ResourceItem*` in `ecx` |
| `00412200` | 181-183 | none | none | `this: const ResourceItem*` in `ecx` |
| `00412210` | 188-195 | `num: int` | none | `this: ResourceItem*` in `ecx` |
| `00412240` | 200-327 | none | `i: int` at stack `-0xc` | `this: ResourceItem*` in `ecx` |

The PDB records no function statics. It records no register locals. The two
free operators have no register parameter records, as expected for `__cdecl`.

## Name recovery

Recovered PDB names changed in the source as follows:

- `00411F10`: `count` to `n`.
- `00411F80`: `count` to `n`; `values` to `v`.
- `00411FF0`: `source` to `ri`.
- `00412050`: `source` to `ri`.
- `004120C0`: `source` to `ri`.
- `00412100`: `left` and `right` to `one` and `two`.
- `00412140`: `left` and `right` to `one` and `two`.
- `00412180`: `index` to `n`.
- `004121A0`: `index` and `value` to `n` and `v`.
- `004121C0`: `index` and `value` to `n` and `v`.
- `004121E0`: `value` to `v`.
- `00412210`: `index` to `num`.
- `00412240`: existing local `i` matches the PDB name and remains unchanged.

No new invented names were added. Existing descriptive names remain where the
PDB has no declaration record: `lhs`, `count`, loop `i`, `maxIndex`, `j`, and
`value`. Their storage mappings are not proven. I did not force a rename.

## Other cleanup categories

- Constants: none added. Existing `8`, `0`, `1`, and `-1` values remain unchanged.
- Comments: none added. The code has no comment gap that needs a source comment.
- Resource IDs: none used or changed. No resource extraction was required.
- Shared requests: none. No header edit is needed.

## Evidence

The PDB evidence is:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- SHA256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`

The per-procedure inventory packets are under:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0041/`

The inspected packets are `00411EC0_ResourceItem.txt`,
`00411F10_ResourceItem.txt`, `00411F80_ResourceItem.txt`,
`00411FF0_ResourceItem.txt`, `00412050_ResourceItem.txt`,
`004120B0_ResourceItem.txt`, `004120C0_operator.txt`,
`00412100_operator.txt`, `00412140_operator.txt`, `00412180_value.txt`,
`004121A0_setValue.txt`, `004121C0_incrementValue.txt`,
`004121E0_setAllValues.txt`, `00412200_number.txt`,
`00412210_largestValueIndex.txt`, and `00412240_sortLarge.txt`.
Their original assembly records confirm the listed boundaries, sizes, and
source line spans. No direct original source text was available.

The original executable reference is:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
- SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup object reference is:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/airesitm.obj`
- SHA256: `12ee18c8e8795154c5e228872b87bb38408c76f073ec51ac633b6669f518d34b`

## Risk and validation

The edits change identifier spelling only. They do not change types, layout,
ABI symbols, declarations, evaluation order, or executable statements.
Debug-name output can still differ after compilation. The header remains owned
by owner 06 and unchanged here.

Compilation, matching, audits, and tests were not run. Builds and game runs
were not run.
