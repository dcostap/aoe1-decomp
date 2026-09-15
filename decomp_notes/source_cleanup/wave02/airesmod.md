# `src/airesmod.cpp` cleanup report

## Delivery

- Module: `src/airesmod.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source cleanup head: `feb214c7eb6d4ed17346f4b530fc893d6860f6a6`
- Parameter recovery commit: `239fcbdfccf99122ed33a2f6650d3661a34f68ba`
- Evidence report commit: `909aa4f121da5a43806119b2f6491ee45707f03b`
- Formatting correction commit: `feb214c7eb6d4ed17346f4b530fc893d6860f6a6`
- Changed files in the source cleanup commits: `src/airesmod.cpp`, this report
- Report file: `decomp_notes/source_cleanup/wave02/airesmod.md`
- Header owner: `include/airesmod.h` remains unchanged.

The source cleanup commits restore procedure-scoped PDB parameter names. They also
move function opening braces to 1TBS form and join short calls. The formatting
correction changes whitespace only. The cleanup does not change declarations,
types, calls, statement order, literals, or storage layout.

## Evidence

The scoped PDB reference is:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- SHA-256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- PDB source path: `C:\msdev\work\age1_x1\airesmod.cpp`
- Object module path: `.\Release\airesmod.obj`

The original executable reference is:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
- SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

No resource lookup occurs in this module. No resource extraction or shared ID
request is needed.

## PDB procedure coverage

The scoped PDB has a procedure record for every registry function in this
module. It also has the compiler-generated deleting-destructor record at
`00412460`. Every record has an `ecx` register symbol named `this`. The register
type is `ResourceAIModule*`, except for the five const procedures listed below,
which use `const ResourceAIModule*`. No function-static records occur. No local
stack records occur beyond the listed parameters.

| VA | PDB procedure | Size | Stack parameters | Register type |
| --- | --- | ---: | --- | --- |
| `00412310` | `ResourceAIModule::ResourceAIModule` | 325 | `pW: void*`, `playerID: int`, `n: int`, `iV: int`, `minV: int`, `maxV: int` | `ResourceAIModule*` |
| `00412460` | `ResourceAIModule::\`scalar deleting destructor\'` | 30 | `__flags: unsigned int` | `ResourceAIModule*` |
| `00412480` | `ResourceAIModule::~ResourceAIModule` | 188 | none | `ResourceAIModule*` |
| `00412540` | `ResourceAIModule::processMessage` | 5 | `m: AIModuleMessage*` | `ResourceAIModule*` |
| `00412550` | `ResourceAIModule::update` | 5 | `timeLimit: int` | `ResourceAIModule*` |
| `00412560` | `ResourceAIModule::setCallbackMessage` | 3 | `m: AIModuleMessage*` | `ResourceAIModule*` |
| `00412570` | `ResourceAIModule::setMainDecisionAI` | 13 | `m: MainDecisionAIModule*` | `ResourceAIModule*` |
| `00412580` | `ResourceAIModule::numberResources` | 7 | none | `const ResourceAIModule*` |
| `00412590` | `ResourceAIModule::resource` | 34 | `n: int` | `const ResourceAIModule*` |
| `004125C0` | `ResourceAIModule::resourcesAvailable` | 118 | `ri: ResourceItem*` | `ResourceAIModule*` |
| `00412640` | `ResourceAIModule::unavailableResource` | 106 | `ri: ResourceItem*` | `ResourceAIModule*` |
| `004126B0` | `ResourceAIModule::minValueOfResource` | 34 | `n: int` | `const ResourceAIModule*` |
| `004126E0` | `ResourceAIModule::maxValueOfResource` | 34 | `n: int` | `const ResourceAIModule*` |
| `00412710` | `ResourceAIModule::setResource` | 81 | `n: int`, `v: int` | `ResourceAIModule*` |
| `00412770` | `ResourceAIModule::setResources` | 76 | `ri: ResourceItem*` | `ResourceAIModule*` |
| `004127C0` | `ResourceAIModule::incrementResource` | 92 | `n: int`, `v: int` | `ResourceAIModule*` |
| `00412820` | `ResourceAIModule::incrementResources` | 76 | `ri: ResourceItem*` | `ResourceAIModule*` |
| `00412870` | `ResourceAIModule::decrementResource` | 92 | `n: int`, `v: int` | `ResourceAIModule*` |
| `004128D0` | `ResourceAIModule::decrementResources` | 76 | `ri: ResourceItem*` | `ResourceAIModule*` |
| `00412920` | `ResourceAIModule::setResourceMin` | 32 | `n: int`, `v: int` | `ResourceAIModule*` |
| `00412940` | `ResourceAIModule::setResourceMax` | 32 | `n: int`, `v: int` | `ResourceAIModule*` |
| `00412960` | `ResourceAIModule::filterOutMessage` | 13 | `m: AIModuleMessage*` | `ResourceAIModule*` |
| `00412970` | `ResourceAIModule::addResourceType` | 145 | `r: int`, `t: int` | `ResourceAIModule*` |
| `00412A10` | `ResourceAIModule::isResourceType` | 178 | `r: int`, `t: int` | `ResourceAIModule*` |
| `00412AD0` | `ResourceAIModule::numberResourceTypes` | 16 | `r: int` | `ResourceAIModule*` |
| `00412AE0` | `ResourceAIModule::lowestResourceType` | 6 | none | `const ResourceAIModule*` |

The inventory labels `00412460` as a vector deleting destructor. The PDB labels
it as a scalar deleting destructor. It is compiler-generated and is not a source
function in the registry. Its PDB parameter `__flags` was not copied into the
source.

## Recovered names

All names below are recovered original names from the procedure-scoped PDB. No
new descriptive parameter or local names were invented.

- `00412310` constructor: `owner` -> `pW`; `player` -> `playerID`;
  `resourceCount` -> `n`; `initialValue` -> `iV`; `minimumValue` -> `minV`;
  `maximumValue` -> `maxV`.
- `00412540` `processMessage`: `message` -> `m`.
- `00412550` `update`: `frame` -> `timeLimit`.
- `00412560` `setCallbackMessage`: `message` -> `m`.
- `00412570` `setMainDecisionAI`: `decisionAI` -> `m`.
- `00412590` `resource`: `index` -> `n`.
- `004125C0` `resourcesAvailable`: `item` -> `ri`.
- `00412640` `unavailableResource`: `item` -> `ri`.
- `004126B0` `minValueOfResource`: `index` -> `n`.
- `004126E0` `maxValueOfResource`: `index` -> `n`.
- `00412710` `setResource`: `index` -> `n`; `value` -> `v`.
- `00412770` `setResources`: `item` -> `ri`.
- `004127C0` `incrementResource`: `resourceID` -> `n`; `value` -> `v`.
- `00412820` `incrementResources`: `item` -> `ri`.
- `00412870` `decrementResource`: `resourceID` -> `n`; `value` -> `v`.
- `004128D0` `decrementResources`: `item` -> `ri`.
- `00412920` `setResourceMin`: `index` -> `n`; `value` -> `v`.
- `00412940` `setResourceMax`: `index` -> `n`; `value` -> `v`.
- `00412960` `filterOutMessage`: `message` -> `m`.
- `00412970` `addResourceType`: `resourceIndex` -> `r`; `type` -> `t`.
- `00412A10` `isResourceType`: `resourceIndex` -> `r`; `type` -> `t`.
- `00412AD0` `numberResourceTypes`: `index` -> `r`.

The destructor, empty accessors, and `lowestResourceType` had no procedure-scoped
stack parameter names to recover. Existing local names (`bytes`, `i`, `index`,
`count`, `value`, and `newTypes`) remain unchanged. The PDB has no local records
for these procedures, so reused-stack-slot mappings remain unresolved.

The header parameter names remain owner-owned and unchanged. Definition parameter
names can differ without changing the C++ signature or ABI.

## Constants and comments

No constant was added or renamed. The constructor tag `0x3EF`, allocation
multipliers, return sentinels, and logging strings remain unchanged. No comments
were added because the module has no confirmed non-obvious constraint that needs
a source comment.

## Generation and scope notes

- Parameter names do not change release expressions, calls, types, or layout.
- Brace placement and identifier spelling can change debug line and name records.
- The generated deleting destructor remains outside the source edit.
- No header, registry, inventory, build recipe, or resource file changed.
- No shared-file request is open.

Compilation, matching, audits, and tests were not run. Builds, games, and runtime
validation were also not run.
