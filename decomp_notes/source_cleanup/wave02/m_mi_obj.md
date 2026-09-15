# Source cleanup: `m_mi_obj.cpp`

- Module: `src/m_mi_obj.cpp`
- Branch: `cleanup/staging-20260915-69`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final code commit: `6eace1abd457c9ffec3c934e521068905e5e50f9`
- Assigned header: `include/m_mi_obj.h` (read only; not changed)
- Registry: `config/functions/src/m_mi_obj.cpp.json`
- PDB source: `C:\\msdev\\work\\age1_x1\\m_mi_obj.cpp`
- PDB evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Inventory evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0045/`

## Changed files

- `src/m_mi_obj.cpp`
- `decomp_notes/source_cleanup/wave02/m_mi_obj.md`

The source commits change recovered parameter and local names. They also move
opening braces to 1TBS positions. They keep types, scopes, storage, statements,
calls, casts, literals, source order, and evaluation order.

## Root formatting correction

The prior source correction ended at code commit
`407a300caf49d7a368cbe52bbd13d8e77faac650`. Root review requested compact
signatures for every touched `setup`, `copy_obj`, `modify`, `modify_delta`, and
`modify_percent` definition. The source correction commit is
`6eace1abd457c9ffec3c934e521068905e5e50f9`.

All three `setup` overloads and the listed copy and modify definitions now use
one-line signatures where readable. I reviewed continuation indentation. The
correction changes formatting only. It keeps all tokens, types, scopes,
expressions, and behavior.

## PDB recovery coverage

All 15 procedure records associated with this module were inspected. This
includes the 14 source-owned functions and the compiler-generated vector
deleting destructor. Every record has a register `this` symbol in `ecx`.
Every source-owned stack parameter and local record was checked for type and
role before each rename. No function statics were present.

| VA | Function | PDB stack records and result |
| --- | --- | --- |
| `00451440` | copy constructor | Restored `other_object` from `source`. Kept `do_setup`. |
| `004514A0` | vector deleting destructor | Compiler-generated record. PDB records `__flags`; no source body owns this symbol. |
| `004514C0` | resource constructor | Restored `infile` from `id`. Kept `sprites`, `sounds`, and `do_setup`. |
| `00451530` | text-file constructor | Restored `infile` from `file` and `in_id` from `target_type`. Kept `sprites`, `sounds`, and `do_setup`. |
| `004515B0` | copy setup | Restored `other_object` from `source`. |
| `00451620` | binary setup | Restored `infile` from `id`. Kept `sprites` and `sounds`. |
| `004516C0` | text-file setup | Restored `infile` from `file` and `in_id` from `target_type`. Restored `temp_missile_type`, `temp_targetting_type`, `temp_missile_hit_info`, `temp_missile_die_info`, and `temp_area_effect_specials` from the existing value-suffixed locals. |
| `00451760` | destructor | No stack records. |
| `00451770` | `make_new_obj` | Restored `owner` from `player`. Kept `x`, `y`, and `z`. |
| `00451840` | `make_new_master` | No stack records. |
| `004518B0` | `copy_obj` | `source` was already the PDB name. |
| `00451910` | `modify` | Restored `amount` from `value` and `flag` from `attribute`. |
| `00451940` | `modify_delta` | Restored `amount` from `value` and `flag` from `attribute`. |
| `00451970` | `modify_percent` | Restored `amount` from `value` and `flag` from `attribute`. |
| `004519A0` | `save` | Restored `outfile` from `file_id`. |

The text-file setup PDB records reuse parameter stack offsets for temporary
values. Specifically, `in_id` and `temp_missile_hit_info` share `+0x10`,
`sounds` and `temp_missile_die_info` share `+0xC`, and `sprites` and
`temp_area_effect_specials` share `+0x8`. The source keeps the existing
declaration order, types, scopes, and storage. The renames use the PDB names
for the matching `fscanf` fields. They do not force a new stack mapping.

## Recovered and inferred names

All names listed as restored above are recovered original names from the
procedure-scoped PDB records. Existing `sprites`, `sounds`, `do_setup`, `x`,
`y`, `z`, and `source` names also agree with their PDB records.

`recycled` and `missile_source` are existing descriptive local names without
matching PDB local records. I left them unchanged. No new inferred name was
added.

The source does not rename public functions, classes, members, globals, or ABI
symbols. The matching header has unnamed declarations, so it needs no
parameter-name update.

## Constants, resources, and comments

- No constant, enum, resource ID, or shared declaration was added.
- The existing `0x3C` master type and `0x13` attribute value remain unchanged.
- No resource lookup occurs in this module. No resource extraction was needed.
- No source comment was added. Existing comments remain unchanged.
- No header request is needed from owner 08 for `include/m_mi_obj.h`.
- No request is needed for `include/resource_ids.h`.

The inventory packets under `inventory/functions/0045/` confirm the original
source spans and calls for VAs `00451440` through `004519A0`. Their original
assembly shows the same field offsets, call targets, and literal values. This
supports the decision to change names and brace placement only.

## Code-generation, type, layout, and symbol risks

- Name changes keep each recorded type, width, scope, storage duration, and
  declaration order unchanged.
- The reused-stack-slot records remain represented by the same declarations and
  existing `fscanf` argument order.
- Brace placement follows 1TBS and adds or removes no scope.
- No expression, cast, evaluation order, call target, relocation, literal,
  virtual slot, object layout, or symbol identity changed.
- Formatting can change PDB line records. This is not a byte-equality claim.

## Validation and limits

I reviewed the complete Git diff against base commit
`ef1c4d2e33bac077e7e4e21598f1c18722a721c6` and ran `git diff --check`.

Compilation, matching, audits, and tests were not run, as required for this
cleanup wave. No build, compiler, game, or runtime validation was run.
