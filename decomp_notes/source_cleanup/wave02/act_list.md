# Source cleanup report: `act_list.cpp`

## Delivery

- Module: `src/act_list.cpp`
- Base commit from `git rev-parse`: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit from `git rev-parse`: `75a263bac24c04c07efe53787799a33b618f0b28`
- Branch: `cleanup/staging-20260915-29`
- Changed files: `src/act_list.cpp`; this report.
- Header owner: owner 04 owns `include/act_list.h`. This worker did not edit it.

The cleanup covers all 25 procedures in `config/functions/src/act_list.cpp.json`.
The source change recovers procedure-scoped PDB names. It does not change types,
storage, declaration order, control flow, calls, literal values, or ABI symbols.
The final source commit contains the source cleanup. The report commit follows it.

## Evidence

Name evidence comes from the shared procedure-scoped PDB inventory:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- PDB source: `C:\\msdev\\work\\age1_x1\\act_list.cpp`
- Module object: `.\\Release\\act_list.obj`

I inspected all assigned function packets under:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0040/`

The packets inspected were:

- `00403EA0_RGE_Action_List.txt`
- `00403EC0_RGE_Action_List.txt`
- `00403ED0_load.txt`
- `00403F40_rehook.txt`
- `00403F60_save.txt`
- `00403FA0_delete_list.txt`
- `00403FC0_create_action.txt`
- `00404200_create_task_action.txt`
- `004044A0_inside_obj_update.txt`
- `004044F0_update.txt`
- `00404540_add_action.txt`
- `00404590_add_action_at_end.txt`
- `00404610_add_action_at_end_of_action_queue.txt`
- `00404710_remove_action.txt`
- `00404760_have_action.txt`
- `00404770_action_stop.txt`
- `00404790_action_move_to.txt`
- `004047C0_action_work.txt`
- `004047F0_attack_response.txt`
- `00404810_relation_response.txt`
- `00404840_get_action.txt`
- `00404850_get_task.txt`
- `00404860_copy_obj.txt`
- `00404890_copy_obj_sprites.txt`
- `004048C0_get_action_name.txt`

Every packet reports the original boundary, line span, and assembly. Every PDB
record for these procedures names `this` in `ecx` as `RGE_Action_List*`.
The original executable remains the behavior oracle. Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90` at:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

## Original-name recovery

The table lists every assigned function. Stack records include the PDB offset
and type. A blank stack entry means that the PDB has no stack parameter or local
record. The register record is `this` in `ecx` for every row.

| VA | Function | PDB stack records | Source result |
| --- | --- | --- | --- |
| `00403EA0` | constructor | `obj_in` `+0x4`, `RGE_Action_Object*` | Renamed `object` to recovered `obj_in`. |
| `00403EC0` | destructor | none | No parameter or local rename. |
| `00403ED0` | `load` | `infile` `+0x4`, `int`; `action_type` `-0x4`, `short` | Renamed `file` to recovered `infile`. `action_type` already matched. |
| `00403F40` | `rehook` | none | No PDB stack record. Retained `node` as an existing inferred local. |
| `00403F60` | `save` | `outfile` `+0x4`, `int`; `action_type` `+0x8`, `short` | Renamed `file` to recovered `outfile`. The PDB `action_type` record does not map safely to the existing `int zero` declaration. |
| `00403FA0` | `delete_list` | none | No parameter or local rename. |
| `00403FC0` | `create_action` | `infile` `+0x4`, `int`; `action_type` `+0x8`, `short` | Renamed `file` to recovered `infile` and `type` to recovered `action_type`. |
| `00404200` | `create_task_action` | `task` `+0x4`, `RGE_Task*`; `target_obj` `+0x8`, `RGE_Static_Object*`; `target_x` `+0xc`, `float`; `target_y` `+0x10`, `float`; `target_z` `+0x14`, `float` | Renamed `target` to recovered `target_obj`; renamed `x`, `y`, and `z` to recovered `target_x`, `target_y`, and `target_z`. |
| `004044A0` | `inside_obj_update` | none | No PDB stack record. Retained `node` and `result` as existing inferred locals. |
| `004044F0` | `update` | none | No PDB stack record. Retained `node` and `result` as existing inferred locals. |
| `00404540` | `add_action` | `action` `+0x4`, `RGE_Action*` | The source parameter already matched recovered `action`. Retained the unrecorded local `node`. |
| `00404590` | `add_action_at_end` | `action` `+0x4`, `RGE_Action*` | The source parameter already matched recovered `action`. Retained unrecorded locals `node` and `current`. |
| `00404610` | `add_action_at_end_of_action_queue` | `action` `+0x4`, `RGE_Action*`; `node` `-0x4`, `RGE_Action_Node*` | The source `action` and `node` names already matched. Retained unrecorded `current`. |
| `00404710` | `remove_action` | none | No PDB stack record. Retained `node` as an existing inferred local. |
| `00404760` | `have_action` | none | No parameter or local rename. |
| `00404770` | `action_stop` | none | No parameter or local rename. |
| `00404790` | `action_move_to` | `obj_in` `+0x4`, `RGE_Static_Object*`; `x` `+0x8`, `float`; `y` `+0xc`, `float`; `z` `+0x10`, `float` | Renamed `object` to recovered `obj_in`. The coordinate names already matched. |
| `004047C0` | `action_work` | `obj_in` `+0x4`, `RGE_Static_Object*`; `x` `+0x8`, `float`; `y` `+0xc`, `float`; `z` `+0x10`, `float` | Renamed `object` to recovered `obj_in`. The coordinate names already matched. |
| `004047F0` | `attack_response` | `attacker` `+0x4`, `RGE_Static_Object*` | Renamed `object` to recovered `attacker`. |
| `00404810` | `relation_response` | `player_id` `+0x4`, `long`; `relation` `+0x8`, `unsigned char` | Renamed `value` to recovered `player_id`. `relation` already matched. |
| `00404840` | `get_action` | none | No parameter or local rename. |
| `00404850` | `get_task` | none | No parameter or local rename. |
| `00404860` | `copy_obj` | `source` `+0x4`, `RGE_Master_Action_Object*` | Renamed `object` to recovered `source`. |
| `00404890` | `copy_obj_sprites` | `source` `+0x4`, `RGE_Master_Action_Object*`; `task` `+0x8`, `RGE_Task*`; `new_task` `+0xc`, `RGE_Task*` | Renamed `object` to recovered `source`, `source` to recovered `task`, and `dest` to recovered `new_task`. |
| `004048C0` | `get_action_name` | `action_name` `+0x4`, `char*` | Renamed `dest` to recovered `action_name`. |

The recovered spellings preserve the mixed style in the PDB. No invented
parameter name was added.

## Locals and unresolved mappings

The PDB has no local records for the following existing source names. They are
inferred cleanup names, not recovered original names:

- `00403ED0 load`: `action`, `node`, and `tail`.
- `00403F40 rehook`: `node`.
- `00403F60 save`: `node` and `zero`.
- `00404200 create_task_action`: `bird_action`, `attack_action`,
  `explore_action`, `gather_action`, and `make_action`.
- `004044A0 inside_obj_update`: `node` and `result`.
- `004044F0 update`: `node` and `result`.
- `00404540 add_action`: `node`.
- `00404590 add_action_at_end`: `node` and `current`.
- `00404610 add_action_at_end_of_action_queue`: `current`.
- `00404710 remove_action`: `node`.
- `004048C0 get_action_name`: `name`.
- `00404860 copy_obj` and `00404890 copy_obj_sprites`: `node`.

The PDB `action_type` record in `00403F60 save` is a `short` at `+0x8`.
The source uses an existing `int zero` for the two-byte terminator write.
The PDB type, offset, and optimized stack reuse do not prove that these are the
same declaration. I left `zero` unchanged and did not change its type or scope.
This is the only recorded source mapping left unresolved.

The packets also show compiler exception slots and decompiler temporaries.
Those are not source declarations. The source does not force names onto them.
The nearby padding-only records at `004041C2` and `0040496E` have no source
bodies in this module and were not edited.

## Constants, resources, comments, and formatting

No numeric constant changed. Existing action-type values `1`, `4`, `5`, `7`,
`8`, `9`, `10`, `20`, and `21`, object-state thresholds `2` and `3`, the Unit
AI action value `600`, the target sentinel `-1`, the byte mask `0xff`, and the
file-write size `2` remain unchanged. No existing header symbol proved a better
name for these values in this module, so no constant was added.

This source has no resource lookup. No resource ID is assigned, so no per-ID
text, missing block, empty slot, resource hash, language, lookup path, purpose,
or proposed cleanup name applies. The resource modules were not inspected for
this module because it contains no resource call. No resource header request is
needed.

No source comment was added. The existing source and this report provide enough
evidence for this name-only cleanup.

## Code-generation risks and review

The source edits rename parameters and update their uses. They do not change
parameter types, local types, declaration scope, storage duration, declaration
order, expression order, casts, calls, control flow, literals, function
boundaries, virtual slots, relocations, or ABI symbols. Existing explicit
`this->` expressions remain in place.

The renamed `create_task_action` coordinates remain separate `float` parameters.
The `copy_obj_sprites` names preserve the three distinct PDB parameter types.
The unresolved `save` local retains its existing `int` declaration. No reused
stack slot was split or remapped.

I reviewed the complete source diff against the exact base. The diff contains
only identifier substitutions and the line wrapping required by the longer
recovered names. No helper, wrapper, layout change, assembly, or structural
rewrite was added.

## Header and shared-file requests

Owner 04 may add these recovered names to `include/act_list.h` without changing
public types, order, virtual slots, or ABI:

```cpp
RGE_Action_List(RGE_Action_Object* obj_in);
virtual RGE_Action* create_action(int infile, short action_type);
virtual RGE_Action* create_task_action(RGE_Task* task, RGE_Static_Object* target_obj,
                                       float target_x, float target_y, float target_z);
virtual unsigned char inside_obj_update();
virtual unsigned char update();
virtual void get_action_name(char* action_name);
virtual void copy_obj(RGE_Master_Action_Object* source);
virtual void copy_obj_sprites(RGE_Master_Action_Object* source, RGE_Task* task,
                              RGE_Task* new_task);
void load(int infile);
void save(int outfile);
void add_action(RGE_Action* action);
void add_action_at_end(RGE_Action* action);
void add_action_at_end_of_action_queue(RGE_Action* action);
int action_move_to(RGE_Static_Object* obj_in, float x, float y, float z);
int action_work(RGE_Static_Object* obj_in, float x, float y, float z);
int attack_response(RGE_Static_Object* attacker);
int relation_response(long player_id, unsigned char relation);
```

`rehook`, `delete_list`, `remove_action`, `have_action`, `action_stop`,
`get_action`, and `get_task` have no PDB stack parameter names. No root-owned
header or shared declaration request is open.

## Validation

Compilation, matching, audits, and tests were not run. No build, compiler check,
game, or runtime harness was run. Only PDB and function-packet inspection,
resource-call review, Git diff review, and `git diff --check` were run.
