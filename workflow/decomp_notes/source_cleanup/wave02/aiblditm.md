# Source cleanup report: `src/aiblditm.cpp`

## Commits and scope

- Module: `src/aiblditm.cpp`.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Final source commit: `85465df59c336ac9f37f49648a60f34909b5e7df`.
- Branch: `cleanup/staging-20260915-48`.
- Changed files: `src/aiblditm.cpp` and this report.
- Registry: `config/functions/src/aiblditm.cpp.json`, with `default` build flags.
- Header read only: `include/aiblditm.h`. Owner 06 retains header ownership.

The source keeps all 34 registry functions in source order. The cleanup restores
procedure-scoped PDB parameter names. It keeps types, scopes, storage, calls,
literals, evaluation order, and executable statements. It uses 1TBS braces.

## Correction history

- The initial cleanup source commit was
  `f2a2b3915c0dfadf533aa0dea139c218069674df`.
- The root correction changed only the touched full-argument constructor
  signature. It is now one readable line instead of split lines with alignment
  padding. The correction source commit is
  `85465df59c336ac9f37f49648a60f34909b5e7df`.
- No fixed 80-column wrap was imposed. No name, type, scope, call, expression,
  or statement changed in this correction.

## Evidence coverage

I inspected every VA in `config/functions/src/aiblditm.cpp.json`. I inspected
each matching packet under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0040/` for VAs
`00408190` through `004086A0`, and the original module evidence in
`C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/aiblditm.cpp.asm` and
`C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/aiblditm.cpp.decomp`.

I inspected the procedure-scoped records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB source path is `C:\msdev\work\age1_x1\aiblditm.cpp`. The complete
stack and register coverage is:

| VA | PDB procedure | Stack records | Register records |
| --- | --- | --- | --- |
| `00408190` | `BuildItem::BuildItem` | none | `this: BuildItem* @ ecx` |
| `00408220` | `BuildItem::BuildItem` | `bc: int @ +0x4`; `ti: int @ +0x8`; `bi: int @ +0xc`; `n: int @ +0x10`; `p: int @ +0x14`; `bf: int @ +0x18`; `name: char* @ +0x1c`; `x: float @ +0x20`; `y: float @ +0x24`; `z: float @ +0x28`; `tSet: int @ +0x2c`; `tOne: int @ +0x30`; `tTwo: int @ +0x34`; `pEle: int @ +0x38` | `this: BuildItem* @ ecx` |
| `004082F0` | `BuildItem::BuildItem` | `bi: BuildItem* @ +0x4` | `this: BuildItem* @ ecx` |
| `004083B0` | `BuildItem::BuildItem` | `bi: const BuildItem& @ +0x4` | `this: BuildItem* @ ecx` |
| `00408470` | `BuildItem::~BuildItem` | none | `this: BuildItem* @ ecx` |
| `00408480` | `operator==` | `one: const BuildItem& @ +0x4`; `two: const BuildItem& @ +0x8` | none |
| `004084A0` | `operator!=` | `one: const BuildItem& @ +0x4`; `two: const BuildItem& @ +0x8` | none |
| `004084C0` | `operator<` | `one: const BuildItem& @ +0x4`; `two: const BuildItem& @ +0x8` | none |
| `004084E0` | `operator>` | `one: const BuildItem& @ +0x4`; `two: const BuildItem& @ +0x8` | none |
| `00408500` | `BuildItem::buildCategory` | none | `this: const BuildItem* @ ecx` |
| `00408510` | `BuildItem::number` | none | `this: const BuildItem* @ ecx` |
| `00408520` | `BuildItem::priority` | none | `this: const BuildItem* @ ecx` |
| `00408530` | `BuildItem::inProgress` | none | `this: const BuildItem* @ ecx` |
| `00408540` | `BuildItem::built` | none | `this: const BuildItem* @ ecx` |
| `00408550` | `BuildItem::buildAttempts` | none | `this: const BuildItem* @ ecx` |
| `00408560` | `BuildItem::buildFrom` | none | `this: const BuildItem* @ ecx` |
| `00408570` | `BuildItem::terrainSet` | none | `this: const BuildItem* @ ecx` |
| `00408580` | `BuildItem::terrainAdjacency` | `v: int @ +0x4` | `this: const BuildItem* @ ecx` |
| `004085A0` | `BuildItem::placeOnElevation` | none | `this: const BuildItem* @ ecx` |
| `004085B0` | `BuildItem::setInProgress` | `p: int @ +0x4` | `this: BuildItem* @ ecx` |
| `004085C0` | `BuildItem::setBuilt` | `v: int @ +0x4` | `this: BuildItem* @ ecx` |
| `004085D0` | `BuildItem::setBuildAttempts` | `v: int @ +0x4` | `this: BuildItem* @ ecx` |
| `004085E0` | `BuildItem::incrementBuildAttempts` | none | `this: BuildItem* @ ecx` |
| `004085F0` | `BuildItem::decrementBuildAttempts` | none | `this: BuildItem* @ ecx` |
| `00408610` | `BuildItem::numberBuilds` | none | `this: BuildItem* @ ecx` |
| `00408620` | `BuildItem::incrementNumberBuilds` | none | `this: BuildItem* @ ecx` |
| `00408630` | `BuildItem::setNumberBuilds` | `v: int @ +0x4` | `this: BuildItem* @ ecx` |
| `00408640` | `BuildItem::buildCap` | none | `this: BuildItem* @ ecx` |
| `00408650` | `BuildItem::setBuildCap` | `v: int @ +0x4` | `this: BuildItem* @ ecx` |
| `00408660` | `BuildItem::skipCycles` | none | `this: BuildItem* @ ecx` |
| `00408670` | `BuildItem::incrementSkipCycles` | none | `this: BuildItem* @ ecx` |
| `00408680` | `BuildItem::setSkipCycles` | `v: int @ +0x4` | `this: BuildItem* @ ecx` |
| `00408690` | `BuildItem::permanentSkip` | none | `this: BuildItem* @ ecx` |
| `004086A0` | `BuildItem::setPermanentSkip` | `v: unsigned char @ +0x4` | `this: BuildItem* @ ecx` |

All 34 PDB records have no function-static records. They also have no local
records beyond the listed parameter records. The four cdecl operators have no
register records, as expected from their reference parameters.

The original behavior oracle is
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`,
SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved baseline object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/aiblditm.obj`,
SHA-256 `47dc6f3f98bd7442a035251b05ca0ff2af32aae811d90e3f065bc633a0e51641`.
The module has no resource lookup, so I did not inspect
`C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll` or
`C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`.

## Recovered original names

The following changed names are recovered from the PDB records:

- `00408220`: `category` to `bc`; `typeID` to `ti`; `uniqueID` to `bi`;
  `number` to `n`; `priority` to `p`; `buildFrom` to `bf`; `xSize` to `x`;
  `ySize` to `y`; `zSize` to `z`; `terrainSet` to `tSet`; `adjacency0` to
  `tOne`; `adjacency1` to `tTwo`; and `elevation` to `pEle`.
- `004082F0` and `004083B0`: `source` to `bi`.
- `00408480`, `004084A0`, `004084C0`, and `004084E0`: `left` to `one` and
  `right` to `two`.
- `00408580`: `index` to `v`.
- `004085B0`: `value` to `p`.
- `004085C0`, `004085D0`, `00408630`, `00408650`, `00408680`, and
  `004086A0`: `value` to `v`.

The constructor parameter `name` already matched its PDB spelling. The
parameterless functions already used the PDB `this` record. No invented
identifier was added. No uncertain reused-stack-slot mapping remains in this
module.

## Constants, resources, and comments

No constant or resource ID changed. No resource lookup occurs in this module.
The existing zero, negative-one, bounds, and increment literals remain
unchanged. No comment was added or removed.

The copy constructors still assign `builtValue` from the source progress slot.
The original `004082F0` packet shows the source `+0x80` load stored at the
object `+0x84` slot. This preserves the shipped behavior rather than correcting
that compatibility bug.

## Shared requests and unresolved questions

No shared definition or resource-ID request is needed. The owner-only header
`include/aiblditm.h` remains unchanged. Its parameter names do not affect the
ABI, and the source definitions now carry the PDB names.

No parameter or local mapping is unresolved. The source has no PDB-backed local
rename to force. No type, layout, declaration scope, storage duration, call
target, or symbol identity changed.

## Risk and validation

The source edits rename parameters and adjust permitted wrapping. They do not
change types, expressions, evaluation order, calls, literals, layout, or public
symbols. Parameter names do not change the ABI. The formatting change can alter
debug line records, but no executable validation was run.

Compilation, matching, audits, tests, builds, and game runs were not run, as
required for this cleanup phase.
