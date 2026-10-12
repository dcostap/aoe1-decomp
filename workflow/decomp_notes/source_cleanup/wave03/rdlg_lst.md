# `src/rdlg_lst.cpp` cleanup report

## Scope and commits

- Module: `src/rdlg_lst.cpp`
- Header owner: owner 18 owns `include/rdlg_lst.h`; this worker did not edit it.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final commit: recorded in the delivery commit.
- Changed files:
  - `src/rdlg_lst.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/rdlg_lst.md`

The source keeps the ten handwritten functions in PDB source order. It restores
procedure-scoped PDB names and moves function braces to 1TBS style. It does not
change types, calls, literals, scopes, evaluation order, or layouts.

## Evidence identity

- Original executable:
  `orig/empiresx.exe`,
  SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Baseline report:
  `build/source-cleanup-20260915/preparation/baseline-build/report.json`.
  It records the registry route, `config/flags/default.rsp`, and the prior
  `src/rdlg_lst.cpp` SHA256
  `2ef727eceb33c4c0eb0efe349b7e568fac5dd420df11fb90aa2de87f35d73b5a`.
- Scoped PDB records:
  `inventory/pdb/scoped_symbols.json`, module object
  `.\\Release\\rdlg_lst.obj`.
- Function packets:
  `inventory/functions/0047/0047E6B0_setup.txt`,
  `0047E910_create_object_list.txt`,
  `0047EAA0_rdlg_list_compare.txt`,
  `0047E8C0_get_list_id.txt`,
  `0047EAF0_calc_list_line.txt`, and
  `0047EB60_get_cur_id.txt`.
- Registry:
  `config/functions/src/rdlg_lst.cpp.json`.

The runtime language files were not queried. This module has no fixed resource
ID lookup. Its `get_string` call receives the data-driven `string_id` field.

## PDB coverage and name recovery

All ten configured normal functions have scoped PDB records. The constructor
has parameter `name`. `setup` has parameters `parent_screen`, `info_file_in`,
`info_id_in`, `list_type_in`, and `title_in`. `create_object_list` has locals
`i`, `j`, `player`, and `end_i`. `rdlg_list_compare` has parameters `arg1` and
`arg2`. The other functions have no scoped stack symbols beyond `this`.

The source now restores these PDB names:

- `setup`: `screen` to `parent_screen`, `popup_file` to `info_file_in`,
  `popup_id` to `info_id_in`, `list_type` to `list_type_in`, and `title` to
  `title_in`.
- `create_object_list`: `num_objects` to the recovered PDB name `end_i`.
- `rdlg_list_compare`: `a` to `arg1` and `b` to `arg2`.

The existing `i`, `j`, and `player` declarations already use the recovered PDB
spellings. The inner `count` and `object_index` variables have no scoped PDB
records. They remain descriptive cleanup names, not claimed original names.
The same rule applies to existing locals such as `info`, `offset`, `index`,
`selected_id`, `list_type`, and `base_game`.

The generated scalar deleting destructor at `0047E690` is not a handwritten
source function and was not edited.

## Constants, resources, and comments

No new constants, resource names, or comments were added. Existing allocation
sizes, record strides, dialog values, CompareStringA arguments, string lookup
arguments, and sentinel values remain unchanged.

No shared-file request was sent. The header declaration has no parameter names,
and no declaration change is needed for this source-only cleanup.

## Code-generation and unresolved items

The edits rename parameters and one local, rename compare-helper parameters,
and move opening braces. They do not alter an ABI name, type, declaration
scope, cast, literal, call target, statement order, or storage layout.

The registry marks `0047E910` (`create_object_list`) as `accepted_drift`. The
existing module note records five differing bytes from local register
scheduling, with no relocation mismatch or boundary escape. This cleanup does
not claim to change that status.

The PDB does not provide original names for the current inner `count` and
`object_index` variables or the other descriptive locals listed above. No
uncertain mapping was forced.

## Validation status

Compilation, matching, audits, and tests were not run. No compiler, build,
matching, audit, test, or game command was run for this assignment.
