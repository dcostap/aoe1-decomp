# `tact_trd` cleanup report

## Delivery

- Module: `src/tact_trd.cpp`
- Report: `workflow/decomp_notes/source_cleanup/wave03/tact_trd.md`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `c33bc0d25a7640f45e242b86f40f886da538ad00`
- Changed files: the two paths above only.
- Header read but not changed: `include/tact_trd.h`

The source commits contain identifier recovery and the allowed 1TBS brace
formatting pass. The report is committed later because its source commit hash
is part of this report.

## PDB coverage

I inspected the scoped records for every normal function in this source module.
The evidence is:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2660_TRIBE_Action_Trade.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2710_TRIBE_Action_Trade.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D27A0_TRIBE_Action_Trade.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D27F0_save.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2830_first_in_stack.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2880_set_state.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D2CB0_update.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D32C0_get_move_sprite.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D32F0_get_wait_sprite.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D3330_stop.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D3340_move_to.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D33C0_work.txt`

The PDB source path for all records is
`C:\msdev\work\age1_x1\tact_trd.cpp`.
Every procedure has `this` in ECX. The PDB stack records are:

| VA | Procedure | PDB parameters | PDB locals | Change |
| --- | --- | --- | --- | --- |
| `004D2660` | file constructor | `infile`, `obj_in` | none | recovered both parameters |
| `004D2710` | target constructor | `obj_in`, `task_in`, `target_obj_in` | none | recovered all three parameters |
| `004D27A0` | coordinate constructor | `obj_in`, `task_in`, `x`, `y`, `z` | none | recovered `obj_in` and `task_in`; retained `x`, `y`, `z` |
| `004D27F0` | `save` | `outfile` | none | recovered the parameter |
| `004D2830` | `first_in_stack` | `first_time` | none | recovered the parameter |
| `004D2880` | `set_state` | `new_state` | none | recovered the parameter |
| `004D2CB0` | `update` | none | `dx` at `-0x4`; `give_amount` and `take_amount` at `-0x8`; `max_hold` at `-0x4` | recovered the proved state-7 names; retained the proved current `dx` and `take_amount` names |
| `004D32C0` | `get_move_sprite` | none | none | no forced local mapping |
| `004D32F0` | `get_wait_sprite` | none | none | no forced local mapping |
| `004D3330` | `stop` | none | none | no change needed |
| `004D3340` | `move_to` | `obj_in`, `x`, `y`, `z` | none | recovered `obj_in`; retained `x`, `y`, `z` |
| `004D33C0` | `work` | `obj_in`, `x`, `y`, `z` | none | recovered `obj_in`; retained `x`, `y`, `z` |

The PDB also records the scalar deleting destructor at `004D26E0` and the
base destructor at `004D2700`. They are compiler-generated and have no
handwritten owner in this source file.

## Identifier recovery

Recovered original spellings came from the procedure-scoped PDB records:

- `file` became `infile` in the file constructor.
- Constructor `obj`, `task`, and `target` became `obj_in`, `task_in`, and
  `target_obj_in`.
- `save` parameter `file` became `outfile`.
- `first_in_stack` parameter `param_1` became `first_time`.
- `set_state` parameter `param_1` became `new_state`.
- `move_to` and `work` parameter `obj` became `obj_in`.
- State 7 `max_amount` became PDB name `max_hold`.
- State 7 `take_amount` became PDB name `give_amount`.

The PDB records prove `dx`, `max_hold`, `give_amount`, and `take_amount`,
but they reuse stack homes. The current state-8 `take_amount` and `dx` names
remain. I did not force a mapping for state-8 `modifier` or `dy`: the PDB has
one `take_amount` home at `-0x8`, and it has no `dy` record. This preserves the
current declarations and avoids a source rewrite based on reused slots.

The current `attribute`, `modifier`, `dy`, `drop_site`, `action`, `task`, and
`task_facet` names are descriptive cleanup names from earlier recovery work.
The scoped PDB records do not prove original spellings for them. I did not
claim them as recovered originals or change their scope, type, or storage.

## Constants, resources, comments, and shared files

- No constants were added or replaced. Existing action, state, notification,
  sentinel, and floating-point literals remain unchanged.
- No resource ID is used by this module. No resource extraction was required.
- No source comment was added. Existing sparse behavior comments remain.
- No shared declaration, header, global, or resource-ID request is needed.
- No unresolved header question blocks this source change.

The edits change identifiers only. They do not change types, casts,
initialization, evaluation order, declarations, storage, layout, ABI, or
symbol identity. I did not compile the source to verify this statement.

## Validation limits

Compilation, matching, audits, and tests were not run, as required for this
cleanup phase. No build or game was run. The source diff was reviewed with Git,
and the diff check reported no whitespace errors.
