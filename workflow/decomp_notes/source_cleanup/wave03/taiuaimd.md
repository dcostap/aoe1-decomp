# Source-cleanup wave 03: `src/taiuaimd.cpp`

## Handoff

- Module: `src/taiuaimd.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final module commit: `5bd2d519e42d4dac68c204e4b677e252ad8eb84c`
- Report commit: the commit that adds this report
- Changed paths:
  - `src/taiuaimd.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/taiuaimd.md`
- Branch: `cleanup/staging-20260915-124`

The assigned header, `include/taiuaimd.h`, was read only. The full source diff was reviewed.

## Evidence

The main evidence was the procedure-scoped PDB record file:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- PDB module: `.\\Release\\taiuaimd.obj`
- PDB source path: `C:\\msdev\\work\\age1_x1\\taiuaimd.cpp`

The registry and selected original packets were also checked:

- `config/functions/src/taiuaimd.cpp.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/`

All 63 registered functions were inspected. The registry maps the functions to the addresses in the `00503BB0` through `00508660` range.

## Original-name recovery

The names below are recovered original names. Each name matches its owning PDB procedure and type.

| Functions | Recovered names |
| --- | --- |
| All assigned constructors | `o`, `iQS` |
| All assigned `processNotify` methods | `nEvent`, `uTime` |
| All assigned `processIdle` methods | `doSearch` |
| Hunted animal idle | `evasiveMoveDistance`, `xDiff`, `yDiff`, `distanceDiff` |
| Predator and lion neutrality checks | `oType` |
| Lion idle | `maxReactDistance` |
| Ranged notify | `distanceDiff` |
| Ranged-2 notify | `evasiveMoveDistance`, `xDiff`, `yDiff` |
| Civilian helpers | `objectType`, `targetID`, `unconditional`, `unit`, `oType`, `orderType` |
| Priest helpers | `targetID`, `unconditional`, `orderType`, `targetID`, `unit`, `idleHeal`, `allyDistance`, `distance` |
| Trade notify | `tileX`, `tileY` |
| Fishing helpers | `objectType`, `oType` |
| Soldier helpers | `unit`, `oType`, `newX`, `newY`, `evasiveMoveDistance`, `xDiff`, `yDiff`, `distanceDiff` |
| Tower helpers | `unit`, `oType` |

The table groups repeated names. The exact owning function and address are in the PDB records and registry.

The artifact idle method had decompiler names `iVar1` and `pRVar2`. The PDB has no local records for those values. Their existing declarations were renamed to the new descriptive names `target_id` and `target`. The artifact logging local `value` was renamed to the new descriptive name `object_id`. These three names are cleanup names, not recovered original names.

No unresolved parameter mapping remains for a registered function. PDB local records can reuse stack slots. This cleanup renamed existing declarations. It did not split variables or change their scope.

## Comments, constants, and resources

No constants or resource IDs changed. No new constant or resource declaration was needed.

The cleanup removed decompiler comments, raw vtable narration, and empty comment markers. It kept the existing fixed-address notes and the useful civilian fall-through note. It added no new source comment.

## Scope and risk

The edits rename parameters and locals, remove unhelpful comments, and apply local 1TBS formatting. They preserve existing declarations, storage, and declaration order. In particular, soldier notify keeps its distinct `event` alias and uses it in the body. The edits do not change types, widths, casts, layouts, public names, calling conventions, relocations, or direct call targets.

The header was not changed. No shared-file request is open.

The source diff contains no intentional executable or data change. Compiler output and debug line records were not checked. The formatting and comment edits can change source line records.

## Correction history

- A full-diff review found that the first cleanup removed the existing `NotifyEvent* event = param_1;` declaration in `TribeSoldierUnitAIModule::processNotify`.
- The correction keeps the recovered `nEvent` parameter, restores `NotifyEvent* event = nEvent;` at the original declaration point, and restores `event` use in the body.
- The full diff was checked again for other removed or merged declarations. None were found.

## Validation status

Compilation, matching, audits, and tests were **NOT run**. No build, compiler, matching, audit, test, or game command was run. Code-generation equivalence remains unvalidated.
