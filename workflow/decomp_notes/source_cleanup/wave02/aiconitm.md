# `src/aiconitm.cpp` cleanup

## Delivery

- Module: `src/aiconitm.cpp`
- Slot and branch: 50, `cleanup/staging-20260915-50`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Initial source commit: `f6db0125c423506bff5f30ce20f5337d9a56fd88`
- Operator formatting correction commit: `151a911e1acea79628f543738fd3c393d7815eba`
- Constructor formatting correction commit: `891620b9264a5a6fd2f7319a3e8e9875ff860465`
- Final source commit: `891620b9264a5a6fd2f7319a3e8e9875ff860465`
- Changed files: `src/aiconitm.cpp`, this report
- The source commits contain only the assigned source file. The report is committed separately.
- The formatting corrections join the operator and constructor signatures onto readable lines. They change formatting only.

## Cleanup

Recovered procedure parameter names from the scoped PDB records. The changes only rename parameters in definitions. They preserve types, scopes, calls, expression order, casts, explicit `this->`, and storage layout.

| VA | Function | Recovered names |
| --- | --- | --- |
| `0040A820` | `ConstructionItem::ConstructionItem()` | none besides `this` |
| `0040A870` | `ConstructionItem::ConstructionItem(float, float, float, float, float, float, int, char*)` | `x`, `y`, `z`, `xs`, `ys`, `zs`, `ti`, `n` |
| `0040A8D0` | `ConstructionItem::ConstructionItem(ConstructionItem*)` | `ci` |
| `0040A910` | `ConstructionItem::ConstructionItem(const ConstructionItem&)` | `ci` |
| `0040A950` | `ConstructionItem::~ConstructionItem()` | none besides `this` |
| `0040A960` | `operator==` | `one`, `two` |
| `0040A990` | `operator!=` | `one`, `two` |
| `0040A9C0` | `operator<` | `one`, `two` |
| `0040A9E0` | `operator>` | `one`, `two` |
| `0040AA00` | `ConstructionItem::inProgress()` | none besides `this` |
| `0040AA10` | `ConstructionItem::built()` | none besides `this` |
| `0040AA20` | `ConstructionItem::buildAttempts()` | none besides `this` |
| `0040AA30` | `ConstructionItem::setInProgress(int)` | `p` |
| `0040AA40` | `ConstructionItem::setBuilt(int)` | `b` |
| `0040AA50` | `ConstructionItem::incrementBuildAttempts()` | none besides `this` |
| `0040AA60` | `ConstructionItem::decrementBuildAttempts()` | no named local in the PDB; the source has no local declaration |
| `0040AA80` | `ConstructionItem::setBuildAttempts(int)` | `v` |

All listed names are recovered PDB names. No invented names were added. The scalar deleting destructor at `0040A850` is compiler-generated and outside the source registry; its PDB record has the generated `__flags` parameter and no source definition mapping.

The scoped PDB evidence is `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`. Each listed procedure has the expected `aiconitm.obj` module record, procedure-scoped stack parameters, and `this` register record where applicable. The source-line and original-byte evidence is in the per-function inventory files under `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0040/` for VAs `0040A820`, `0040A870`, `0040A8D0`, `0040A910`, `0040A950`, `0040A960`, `0040A990`, `0040A9C0`, `0040A9E0`, `0040AA00`, `0040AA10`, `0040AA20`, `0040AA30`, `0040AA40`, `0040AA50`, `0040AA60`, and `0040AA80`. The original source path recorded by the PDB is `C:\msdev\work\age1_x1\aiconitm.cpp`.

## Constants, comments, and resources

- No constants or resource IDs changed.
- No comments were needed. The functions have direct, readable operations.
- No shared declarations were requested.

## Risk and unresolved items

No type, layout, ABI, symbol, call-target, or control-flow change was made. Parameter names are not part of the ABI. No declaration mapping remains unresolved for the source-owned procedures. The compiler-generated scalar deleting destructor remains outside the source file.

The baseline object hash is `4f6feb1c6dcc5d8fcbd1afb69584756676d75fd5b8669e1ebdc07f2943533ecd` for `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/aiconitm.obj`. The preserved baseline executable hash is `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`. The original executable evidence hash is `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90` for `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.

Compilation, builds, matching, audits, tests, and game commands were not run, as required for this cleanup phase.
