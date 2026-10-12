# Source-cleanup report: `src/taiconmd.cpp`

## Scope and commits

- Module: `src/taiconmd.cpp`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source commit: `6efb1c7a205c275dece735b4e1e05f913225f992`.
- Branch: `cleanup/staging-20260915-115`.
- Changed files: `src/taiconmd.cpp` and this report.
- Read-only header: `include/taiconmd.h`. I did not edit it.
- Registry: `config/functions/src/taiconmd.cpp.json`.
- Registry flags: `gx`.

I reviewed all nine normal source functions in the registry. The source keeps
source order, types, scopes, storage, calls, literals, and control flow.

## Evidence reviewed

I read the complete source-cleanup, source-comment, resource-ID, ownership,
testing, and wave-assignment guides. I read `include/taiconmd.h` and the
existing module notes at `workflow/decomp_notes/taiconmd.md`.

I inspected the registry-selected packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/`:

- `004D5E60_TribeConstructionAIModule.txt`
- `004D5EB0_TribeConstructionAIModule.txt`
- `004D5EE0_TribeConstructionAIModule.txt`
- `004D5EF0_setMainDecisionAI.txt`
- `004D5F00_canPlace.txt`
- `004D60E0_placeStructure.txt`
- `004D6780_placeDock.txt`
- `004D6800_setBuilt.txt`
- `004D68A0_compare.txt`

I inspected the direct PDB evidence at
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB source path is `C:\msdev\work\age1_x1\taiconmd.cpp`.
Every normal procedure has `this` in `ecx`.

The PDB records these procedure spans and stack names:

| VA | Procedure | PDB lines | Stack names |
| --- | --- | --- | --- |
| `004D5E60` | constructor `(void*, int)` | 37-38 | `pW`, `pID` |
| `004D5EB0` | constructor `(int, int)` | 45-46 | `pID`, `infile` |
| `004D5EE0` | destructor | 51 | none |
| `004D5EF0` | `setMainDecisionAI` | 57-59 | `m` |
| `004D5F00` | `canPlace` | 64-105 | `bi`, `tempLots` |
| `004D60E0` | `placeStructure` | 111-333 | `bi`, `builder`, `placementState`, `startTime`, `numberTempLots`, `protoBuilder`, `tempLots`, `builderZone`, `minBuildAttempts`, `builderObj`, `maxX`, `minY`, `i`, `j` |
| `004D6780` | `placeDock` | 338-358 | `bi` |
| `004D6800` | `setBuilt` | 363-379 | `bo`, `v` |
| `004D68A0` | `compare` | 385-389 | `one`, `two` |

The PDB types support these mappings. Constructor `pW` is `void*`; constructor
and `setBuilt` integer parameters are `int`. The `placeStructure` parameters
are `BuildItem*`, `int`, `PlacementState&`, and `unsigned long`.
The `placeStructure` local `builderObj` is `RGE_Static_Object*`.
Its `builderZone` is `unsigned char`. Its counters are `int`.
The `canPlace` `tempLots` local is `ConstructionItem`.

The PDB also lists the compiler-generated scalar deleting destructor at
`004D5E90`. Its only stack name is `__flags`; it has `this` in `ecx`.
It has no handwritten source body and was not edited.

## Original-name recovery

The source now uses all reliably mapped original names from the scoped PDB.
The names retain their original mixed and terse spelling.

| VA | Recovered original name | Previous source name | Evidence and use |
| --- | --- | --- | --- |
| `004D5E60` | `pW` | `owner` | PDB stack offset `+0x4`, `void*`; passed to the base constructor. |
| `004D5E60` | `pID` | `player` | PDB stack offset `+0x8`, `int`; passed to the base constructor. |
| `004D5EB0` | `pID` | `player` | PDB stack offset `+0x4`, `int`; passed to the base constructor. |
| `004D5EB0` | `infile` | `file` | PDB stack offset `+0x8`, `int`; passed to the base constructor. |
| `004D5EF0` | `m` | `value` | PDB stack offset `+0x4`, `TribeMainDecisionAIModule*`; stored in `md`. |
| `004D60E0` | `bi` | `item` | PDB stack offset `+0x4`, `BuildItem*`; used for type, size, ID, and placement calls. |
| `004D60E0` | `builder` | `builder_id` | PDB stack offset `+0x8`, `int`; passed to object lookup and placement calls. |
| `004D60E0` | `placementState` | `state` | PDB stack offset `+0xc`, `PlacementState&`; passed unchanged to placement calls. |
| `004D60E0` | `startTime` | `time` | PDB stack offset `+0x10`, `unsigned long`; passed unchanged to placement calls. |
| `004D60E0` | `builderObj` | `builder` | PDB stack offset `-0x90`, `RGE_Static_Object*`; used for zone lookup. |
| `004D60E0` | `i` | `x` | PDB stack offset `-0x9c`, `int`; outer grid-loop counter. |
| `004D60E0` | `j` | `y` | PDB stack offset `-0xa0`, `int`; inner grid-loop counter. |
| `004D6780` | `bi` | `item` | PDB stack offset `+0x4`, `BuildItem*`; passed to `placeDock`. |
| `004D6800` | `bo` | `object` | PDB stack offset `+0x4`, `RGE_Static_Object*`; source object for the lot match. |
| `004D6800` | `v` | `built` | PDB stack offset `+0x8`, `int`; passed to `ConstructionItem::setBuilt`. |
| `004D68A0` | `one` | `left` | PDB stack offset `+0x4`, `ConstructionItem*`; first `buildAttempts` receiver. |
| `004D68A0` | `two` | `right` | PDB stack offset `+0x8`, `ConstructionItem*`; second `buildAttempts` receiver. |

These names already matched the PDB and remain unchanged: `bi` and `tempLots`
in `004D5F00`; `tempLots`, `protoBuilder`, `builderZone`, `numberTempLots`,
`minBuildAttempts`, `maxX`, and `minY` in `004D60E0`.

The source has no reliable PDB mapping for several existing descriptive
locals. I left them unchanged:

- `004D5F00`: `current` and `end`.
- `004D60E0`: `dock`, `current`, `minX`, `maxY`, `copy`, both `result` locals,
  `best`, `candidate`, `selected`, `old`, and `next`.
- `004D6780`: `result` and `tail`.
- `004D6800`: the list cursor `item`.
- `004D68A0`: `leftAttempts`.

The packets provide decompiler names such as `pCVar5`, `iVar4`, and `param_1`.
Those names are not original-name evidence. I did not copy them.
The PDB records optimized and reused stack homes. I did not force a mapping
for a local without a matching scoped record. No new invented identifier was
added.

The declaration in `include/taiconmd.h` remains read-only. Its parameter names
remain unchanged in this commit. Source definitions may use the recovered
names without changing the ABI.

## Constants, resources, and comments

No resource lookup occurs in this module. No resource ID was changed or added.
I did not run resource extraction because this source has no resource ID use.
No resource mapping request is needed.

No numeric constant changed. The source keeps all type IDs, sentinel values,
map bounds, allocation size, passability argument, and placement arguments.
The existing `PlacementOk` and `PlacementFailed` names remain from
`include/aiconmod.h`; their enum values were not changed.
The `useInfluencePlacement` global and its literal comparison remain unchanged.

I retained the comment in `compare` and updated only its wording for the
recovered `one` and `two` names:

```cpp
// Read the first candidate before the second. A null first candidate faults first.
```

The original packet at `004D68A0` loads the first pointer and calls
`buildAttempts` before it loads the second pointer. The comment records that
proven fault order. No other comment was added.

## Formatting and code-generation risks

I applied 1TBS braces to all function definitions. I joined short signatures
and calls where practical. I changed no executable token except identifier
spelling. I preserved declarations, types, scopes, storage, statement order,
casts, explicit `this->`, calls, literals, and fault order.

Parameter and local names do not change the public symbol or ABI. Formatting
can change debug line records. The comment edit can also change line records.
No line-dependent macro occurs in this source. Generated code, data,
relocations, and direct-target identity remain unvalidated.

The registry keeps its existing claims. In particular, `004D60E0` remains
`new_verified_logic`, while `004D5F00` and `004D68A0` remain `accepted_drift`.
This cleanup does not promote or weaken any claim.

## Shared-file requests and unresolved questions

- `include/taiconmd.h` is owned by owner 13 and was not edited.
  Owner 13 may align declaration parameter names with the recovered source
  names in a separate header commit. This is non-blocking.
- Root owns `include/resource_ids.h` and all other shared headers.
  This module has no new shared declaration or resource mapping request.
- The original source names for the unrecorded locals listed above remain
  unresolved. Their current descriptive names are retained.
- The registry status and accepted-drift questions remain outside this pass.

## Validation status

I ran only evidence inspection and Git diff review. I ran `git diff --check`.
Compilation, matching, audits, and tests were not run. I did not build or run
the game.
