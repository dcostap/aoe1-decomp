# `dpl_obj.cpp` wave 02 cleanup report

## Delivery

- Module: `src/dpl_obj.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `924bfa7b9fa0f715818a7af51fee8d12d0c74a2c`
- Changed files: `src/dpl_obj.cpp` and this report.
- Header request: none. Owner 09 retains `include/dpl_obj.h`.

The source commit contains only the assigned source. The report is committed after
that source commit. The worker delivery gives the full report commit hash.

## Evidence reviewed

I reviewed the source registry at:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/dpl_obj.cpp.json`

I reviewed all 15 registered function packets under:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/`

I reviewed scoped PDB data at:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The PDB source path is `C:\msdev\work\age1_x1\dpl_obj.cpp`. All 15 registered
functions have scoped PDB entries with the expected source path and module object.
The PDB records include parameters, locals, and registers where the compiler kept
them. The `this` register is `ecx` for every member function.

## PDB coverage and name recovery

| VA | Function | PDB coverage | Cleanup result |
| --- | --- | --- | --- |
| `004418A0` | `RGE_Doppleganger_Object` constructor | `tobj`, `obj_owner`, `x`, `y`, `z`, `do_setup`, `obj_to_dopple`; `this` | Recovered all listed parameter names. |
| `00441A70` | Load constructor | `infile`, `gworld`, `do_setup`, `long_val`; `this` | Recovered all listed names. The existing `int` declaration for `long_val` stayed unchanged. |
| `00441BB0` | `recycle_in_to_game` | `tobj`, `obj_owner`, `x`, `y`, `z`, `obj_to_dopple`; `this` | Recovered all listed parameter names. Renamed two non-PDB locals to `new_node` and `map_addr`. |
| `00441D30` | Master setup | `tobj`, `obj_owner`, `x`, `y`, `z`; `this` | Recovered the two supported parameter names. |
| `00441DA0` | Load setup | `infile`, `gworld`; `this` | Recovered both parameter names. |
| `00441E00` | `rehook` | `this` only | No PDB local names. Kept the existing descriptive locals. |
| `00441EB0` | `update` | `this` only | Replaced generated local names with descriptive snake_case names. |
| `00441F80` | `save` | `outfile`, `long_val`; `this` | Kept `file` and `handle`. Their current storage model does not map safely to both PDB symbols. |
| `00442050` | `validate` | `this` only | Replaced `checkVal` and `s` with `check_value` and `owner_id`. |
| `00442100` | Creator constructor | `player`, `initial_size`; `this` | Recovered `initial_size`; `player` was already present. |
| `00442180` | Creator destructor | `this` only | No source-local cleanup was needed. |
| `004421F0` | `add_doppleganger_check` | `theObj`, `UMV_addr`; `this` | Recovered both parameter names. |
| `004422B0` | `remove_doppleganger_check` | `theObj`; `this` | Recovered the parameter name. |
| `00442390` | `perform_doppleganger_checks` | `x`, `Unified_Map_Value`, `remove_me`; `this` | Recovered `Unified_Map_Value` and kept `remove_me`. Kept `i` because the PDB `x` record shares reused optimized storage. |
| `00442540` | `expand_allocations` | `grow_size`, `TLast_Map_Value`, `TObject_ids`; `this` | Recovered all supported names. Renamed two unnamed allocations to `new_objects` and `new_map_addresses`. |

The PDB also lists the scalar deleting destructor at `00441A40` and the trivial
object destructor at `00441A60`. These entries have no handwritten source owner.
They remain outside this source edit.

Recovered names retain PDB spelling, including `theObj`, `UMV_addr`,
`Unified_Map_Value`, `TLast_Map_Value`, and `TObject_ids`. New names describe
known local roles and use snake_case. The new descriptive names are
`new_node`, `map_addr`, `map_draw_level`, `map_value`,
`non_mutual_visible_mask`, `remove_visible_bits`, `check_value`, `owner_id`,
`new_objects`, and `new_map_addresses`.

The `save` procedure has PDB names `outfile` and `long_val`. The current source
uses one parameter named `file` for the serialized value and a local named `handle`
for the file handle. A forced rename would change the declaration mapping. The
current names stay in place. The `perform_doppleganger_checks` PDB record names
an `int x`, but the optimized stack record is reused for another value. The source
keeps `i` for the loop index.

## Constants, resources, and comments

No resource lookup or resource ID changed. No resource request is needed.

No existing symbol proves the local object type value `0x19`, the master-object
index `0xf3`, or the visibility mask `0x7fff` in this module. These values remain
unchanged. No header declaration was added.

No new source comment was needed. The code has no proven lifetime or compatibility
constraint that a short comment would explain better than the recovered names.

## Code-generation and behavior notes

The edit changes parameter and local identifiers and source formatting. It applies
1TBS to every function definition. It joins short parameter lists where useful.
It keeps types, casts, expression order, scopes, calls, literals, and storage
operations unchanged.
It does not change layouts, declarations in headers, or symbol identity.

The registry lists `00441BB0` and `004421F0` as `accepted_drift`. Existing module
notes record the two-byte LEA register recolor at `00441BB0`. This cleanup does not
claim to remove that drift or prove new byte equality.

`git diff --check` passed. Evidence extraction and full Git diff review ran.
Compilation, matching, audits, and tests were not run, as required for this wave.
