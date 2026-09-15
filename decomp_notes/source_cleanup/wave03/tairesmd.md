# Source cleanup: `tairesmd.cpp`

## Delivery

- Module: `src/tairesmd.cpp`
- Branch: `cleanup/staging-20260915-121`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `52491598c52c1af93107adbc4c795c9fca4c205a`
- Assigned header: `include/tairesmd.h` (read only; not changed)
- Registry: `config/functions/src/tairesmd.cpp.json`
- PDB source: `C:\\msdev\\work\\age1_x1\\tairesmd.cpp`
- PDB evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Inventory evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/`

## Changed files

- `src/tairesmd.cpp`
- `decomp_notes/source_cleanup/wave03/tairesmd.md`

The source restores all supported procedure parameter names from the scoped PDB.
It applies 1TBS brace placement and removes one malformed stale status comment.
It preserves types, scopes, storage, declarations, statements, calls, constants,
casts, evaluation order, and source order.

## PDB recovery coverage

The registry selects ten normal functions. I inspected every selected original
packet and every scoped PDB stack and register record. All ten procedures have a
`this` record in `ecx`. No selected procedure has a function-static record.

| VA | Function | PDB records and result |
| --- | --- | --- |
| `004E6B40` | `TribeResourceAIModule::TribeResourceAIModule(void*, int, int, int, int, int)` | Parameters `pW` (`void*`), `playerID` (`int`), `n` (`int`), `iV` (`int`), `minV` (`int`), and `maxV` (`int`) replace `param_1` through `param_6`. The `this` register is `TribeResourceAIModule*`. |
| `004E6BA0` | `TribeResourceAIModule::TribeResourceAIModule(int, int)` | Parameters `playerID` (`int`) and `infile` (`int`) replace `param_1` and `param_2`. The `this` register is `TribeResourceAIModule*`. |
| `004E6C20` | `TribeResourceAIModule::~TribeResourceAIModule()` | No stack parameters or locals. The `this` register is `TribeResourceAIModule*`. |
| `004E6C30` | `setMainDecisionAI` | Parameter `m` (`TribeMainDecisionAIModule*`) replaces `v`. The `this` register is `TribeResourceAIModule*`. |
| `004E6C40` | `save` | Parameter `outfile` (`int`) replaces `file_handle`. The `this` register is `TribeResourceAIModule*`. |
| `004E6C60` | `numberResources` | No stack parameters or locals. The `this` register is `const TribeResourceAIModule*`. |
| `004E6C70` | `resource` | Parameter `n` (`int`) replaces `index`. The `this` register is `const TribeResourceAIModule*`. |
| `004E6CA0` | `resourcesAvailable` | Parameter `ri` (`ResourceItem*`) replaces `item`. The `this` register is `TribeResourceAIModule*`. |
| `004E6D40` | `unavailableResource` | Parameter `ri` (`ResourceItem*`) replaces `item`. The `this` register is `TribeResourceAIModule*`. |
| `004E6DD0` | `resourceName` | Parameter `i` (`int`) replaces `param_1`. The `this` register is `TribeResourceAIModule*`. |

The registry and selected packet boundaries remain:

- `004E6B40-004E6B7D`, 62 bytes, lines 30-31, `matching` before this cleanup.
- `004E6BA0-004E6C14`, 117 bytes, lines 38-40, `matching` before this cleanup.
- `004E6C20-004E6C2A`, 11 bytes, line 45, `matching` before this cleanup.
- `004E6C30-004E6C3C`, 13 bytes, lines 51-53, `matching` before this cleanup.
- `004E6C40-004E6C5D`, 30 bytes, lines 58-61, `matching` before this cleanup.
- `004E6C60-004E6C66`, 7 bytes, lines 66-68, `matching` before this cleanup.
- `004E6C70-004E6C9F`, 48 bytes, lines 73-77, `matching` before this cleanup.
- `004E6CA0-004E6D32`, 147 bytes, lines 82-110, `scratch` before this cleanup.
- `004E6D40-004E6DC5`, 134 bytes, lines 115-128, `matching` before this cleanup.
- `004E6DD0-004E6E0B`, 60 bytes, lines 133-143, `matching` before this cleanup.

The nearby `004E6B80` scalar deleting destructor is compiler-generated. It is
not a handwritten source owner and was not edited.

## Recovered and unresolved names

Recovered original spellings from the scoped PDB are:
`pW`, `playerID`, `n`, `iV`, `minV`, `maxV`, `infile`, `m`, `outfile`, `ri`, and
`i`. The source uses `ri` at both `ResourceItem*` call sites. The source uses
`n` in the `resource` parameter and preserves the PDB's mixed capitalization.

The scoped PDB has no local records for `resourcesAvailable` or
`unavailableResource`. Their existing locals `i`, `n`, and `amounts` remain
unchanged. They are not claimed as recovered original names. No declaration
mapping remains unresolved for a parameter. No local rename was forced from a
reused stack slot.

No new descriptive cleanup name was introduced. No public function, class,
member, global, or ABI symbol was renamed.

## Evidence

The selected original packets are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6B40_TribeResourceAIModule.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6BA0_TribeResourceAIModule.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6C20_TribeResourceAIModule.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6C30_setMainDecisionAI.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6C40_save.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6C60_numberResources.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6C70_resource.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6CA0_resourcesAvailable.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6D40_unavailableResource.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6DD0_resourceName.txt`

The packets provide the original boundaries, source lines, direct calls, and
Ghidra listing excerpts. The original source listing and decompiler evidence
are `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tairesmd.cpp.asm`
and `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tairesmd.cpp.decomp`.
The prior module note is
`C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/tairesmd.md`.

## Constants, resources, and comments

- No numeric constant, enum, or symbolic constant changed. Existing `0x3EF`,
  return values, widths, casts, and string literals remain unchanged.
- This module has no resource lookup or resource ID expression. No DLL lookup
  was added, and no resource extraction or resource hash is applicable.
- No new source comment was added. The malformed two-line comment before
  `resourcesAvailable` was removed because it did not state useful behavior.
- No shared resource mapping or constant declaration request exists.

## Shared-file requests and unresolved questions

The assigned header uses unnamed parameters, so it needs no name-only update.
I did not edit `include/tairesmd.h` or any other header. No shared-file request
is pending. The existing `resourcesAvailable` scratch status remains unresolved
for fresh output and semantic review; this cleanup does not promote it.

## Code-generation and behavior-sensitive points

- All executable-source changes are identifier renames or brace placement.
  The comment removal cannot alter a source expression in this module.
- Parameter types, declaration order, scopes, storage, function signatures,
  calling conventions, virtual slots, layouts, and ABI symbols are unchanged.
- The first constructor keeps all six integer and pointer parameter slots,
  including the unused `iV`, `minV`, and `maxV` declarations.
- The existing `resourcesAvailable` and `unavailableResource` local
  declarations remain unchanged because the PDB provides no local mapping.
- The explicit casts, `this->` uses, string literals, comparisons, loop shape,
  call targets, return values, and source order remain unchanged.
- 1TBS changes only opening-brace placement. No compiler or executable check
  was run, so no post-cleanup output claim is made.

## Validation and limits

I reviewed the complete diff against the base commit and ran `git diff --check`.

Compilation, matching, audits, and tests were not run, as required for this
cleanup wave. No build, compiler, game, or runtime validation was run.
