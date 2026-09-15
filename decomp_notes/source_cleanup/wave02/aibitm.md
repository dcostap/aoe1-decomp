# Source cleanup report: `src/aibitm.cpp`

## Commits and scope

- Module: `src/aibitm.cpp`.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Final source commit: `91ed643da59fb039560bb8a4e0b3bb1531ccc4a1`.
- Branch: `cleanup/staging-20260915-47`.
- Changed files: `src/aibitm.cpp` and this report.
- Header read: `include/aibitm.h`. It was not changed.

The source keeps all 31 registry functions in source order. It keeps their
signatures, types, scopes, storage, calls, expressions, and statement order.
The source uses 1TBS braces. No structural rewrite was made.

## Evidence coverage

I inspected `config/functions/src/aibitm.cpp.json`, all 31 matching packets
under `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0040/`, and the
procedure-scoped records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB source path is `C:\msdev\work\age1_x1\aibitm.cpp`.
The PDB inventory hash is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.

The following table records every registry procedure. Member procedures have
a `this` record in `ecx`. The four operators have no register records.

| VA | PDB stack names and types | PDB register record |
| --- | --- | --- |
| `00407D80` | none | `this` in `ecx`, `BaseItem*` |
| `00407E00` | `tid` int; `gid` int; `uid` int; `n` char*; `x` float; `y` float; `z` float; `xs` float; `ys` float; `zs` float | `this` in `ecx`, `BaseItem*` |
| `00407E70` | `bi` `BaseItem*` | `this` in `ecx`, `BaseItem*` |
| `00407EF0` | `bi` `const BaseItem&` | `this` in `ecx`, `BaseItem*` |
| `00407F70` | none | `this` in `ecx`, `BaseItem*` |
| `00407F80` | `one` `const BaseItem&`; `two` `const BaseItem&` | none |
| `00407FC0` | `one` `const BaseItem&`; `two` `const BaseItem&` | none |
| `00407FE0` | `one` `const BaseItem&`; `two` `const BaseItem&` | none |
| `00408000` | `one` `const BaseItem&`; `two` `const BaseItem&` | none |
| `00408020` | none | `this` in `ecx`, `const BaseItem*` |
| `00408030` | none | `this` in `ecx`, `const BaseItem*` |
| `00408040` | none | `this` in `ecx`, `const BaseItem*` |
| `00408050` | none | `this` in `ecx`, `BaseItem*` |
| `00408060` | none | `this` in `ecx`, `const BaseItem*` |
| `00408070` | none | `this` in `ecx`, `const BaseItem*` |
| `00408080` | none | `this` in `ecx`, `const BaseItem*` |
| `00408090` | none | `this` in `ecx`, `const BaseItem*` |
| `004080A0` | none | `this` in `ecx`, `const BaseItem*` |
| `004080B0` | none | `this` in `ecx`, `const BaseItem*` |
| `004080C0` | none | `this` in `ecx`, `const BaseItem*` |
| `004080D0` | `v` int | `this` in `ecx`, `BaseItem*` |
| `004080E0` | `v` int | `this` in `ecx`, `BaseItem*` |
| `004080F0` | `v` int | `this` in `ecx`, `BaseItem*` |
| `00408100` | `n` char* | `this` in `ecx`, `BaseItem*` |
| `00408120` | `v` float | `this` in `ecx`, `BaseItem*` |
| `00408130` | `v` float | `this` in `ecx`, `BaseItem*` |
| `00408140` | `v` float | `this` in `ecx`, `BaseItem*` |
| `00408150` | `v` float | `this` in `ecx`, `BaseItem*` |
| `00408160` | `v` float | `this` in `ecx`, `BaseItem*` |
| `00408170` | `v` float | `this` in `ecx`, `BaseItem*` |
| `00408180` | `v` int | `this` in `ecx`, `BaseItem*` |

The extra `00407DE0` scalar deleting destructor is compiler-generated. It is
not a registry function or a source-owned body. Its PDB record has `this` and
`__flags`; its inventory packet has no PDB source record. I left it unchanged.

The matching packets provide the original boundaries, line spans, calls, and
bytes. For example, `00407D80_BaseItem.txt` covers `00407D80-00407DD3`, and
`00408180_setSkip.txt` covers `00408180-00408189`. The original executable
oracle is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
with SHA256
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

No direct period source was present in the inventory. The PDB names are the
name-recovery evidence. The inventory assembly confirms each use and type.

## Recovered original names

I recovered all source parameter names from the procedure-scoped PDB records:

- `00407E00`: `typeID`, `gameID`, `uniqueID`, `name`, `xSize`, `ySize`, and
  `zSize` became `tid`, `gid`, `uid`, `n`, `xs`, `ys`, and `zs`. The existing
  `x`, `y`, and `z` names already match the PDB.
- `00407E70` and `00407EF0`: `other` and `src` became `bi`.
- `00407F80`, `00407FC0`, `00407FE0`, and `00408000`: `lhs` and `rhs` became
  `one` and `two`.
- `004080D0`, `004080E0`, `004080F0`, and `00408180`: `value` became `v`.
- `00408100`: `value` became `n`.
- `00408120` through `00408170`: `value` became `v`.

These are recovered original spellings, not cleanup names. The module has no
local declarations. No invented identifier was added. No mapping remains
uncertain in the source definitions.

## Constants, comments, and resources

No constant or resource ID changed. No resource lookup occurs in this module.
The existing `-1`, zero, `0x3F`, and `63` literals remain unchanged. The two
bounded `strncpy` calls retain their original counts and call order. I added no
comment because the remaining code is direct and the source comments guide
requires sparse comments.

## Shared-file requests

The owner of `include/aibitm.h` may align declaration-only parameter names with
the recovered definitions. The requested mappings are `typeID` to `tid`,
`gameID` to `gid`, `uniqueID` to `uid`, `name` to `n`, `xSize` to `xs`,
`ySize` to `ys`, `zSize` to `zs`, both `other`/`src` to `bi`, `left`/`right` to
`one`/`two`, and setter `value` to `v` or `n` for `setName`. This request does
not change types, layouts, symbols, or ABI. No shared constant or resource
mapping request is needed.

## Risk and non-validation

The source changes only identifier tokens in function definitions and uses.
They do not change types, scopes, storage, expressions, calls, literals,
layouts, or public symbols. The expected risk is limited to debug names.
The baseline object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/aibitm.obj`,
with SHA256
`29efe13fc93735ddde2462c913ef0935ef8d708d45488b26de82c25c194ec90c`.

Compilation, matching, audits, and tests were not run. Builds and games were
also not run, as required for this cleanup phase.
