# ACT_make.cpp source-module preparation

## PDB ownership

The PDB source module is `C:\\msdev\\work\\age1_x1\\ACT_make.cpp`.
The normal source order is:

1. `004049B0` `RGE_Action_Make(int, RGE_Action_Object*)`, lines 30-32;
2. `00404A10` `RGE_Action_Make(RGE_Action_Object*, RGE_Task*)`, lines 37-41;
3. `00404A40` `first_in_stack(unsigned char)`, lines 45-49;
4. `00404A70` `set_state(unsigned char)`, lines 53-57; and
5. `00404A90` `update()`, lines 61-98.

`004049E0` is the compiler-generated vector-deleting destructor. `00404A00`
is the five-byte scalar destructor tail jump to `RGE_Action::~RGE_Action`.
Neither destructor has a PDB source owner. The direct source does not add a
second destructor body; the candidate keeps the scalar destructor symbol as
an external declaration and emits the weak vector-destructor fallback.

The source order and line bands are facts from
`inventory/pdb/function_source_map.csv`, `inventory/pdb/function_line_changes.csv`,
and the original ACT_make listing. The four existing exact source-bank owners
are `004049B0`, `00404A10`, `00404A40`, and `00404A70`. `00404A90` remains the
reviewed accepted-drift owner. Its original range is `00404A90-00404BA4` and
its size is 277 bytes.

## Canonical dependency closure

The missing direct derived owner header was `include/act_make.h`. It now owns
only `RGE_Action_Make` over the canonical `include/action.h` base. The derived
class adds no fields, and the header records the proven size `0x40`.

The direct module uses these canonical owners:

- `include/act_make.h` for `RGE_Action_Make` and its protected `set_state`;
- `include/action.h` for `state`, `obj`, `timer`, and `task`;
- `include/act_obj.h` and its canonical object chain for action-object fields;
- `include/m_ac_obj.h` for `RGE_Master_Action_Object::work_rate`;
- `include/task.h` for `attribute_type`, `work_val1`, and `work_flag`;
- `include/player.h` for `attributes`, `id`, `world`, and `add_attribute_num`;
- `include/world.h` for `world_time_delta_seconds`;
- `include/stat_obj.h` for object fields and `set_attribute`,
  `set_attribute_amount`, and `die_die_die`;
- `include/basegame.h` for `RGE_Base_Game::notification`; and
- `include/rge_base_game_global.h` for the reviewed `rge_base_game` symbol.

No canonical member is missing for the five normal bodies. The cast from the
canonical `RGE_Master_Static_Object*` `master_obj` field to
`RGE_Master_Action_Object*` is required to select the proven `work_rate` owner.
It is not a raw overlay. No Map, World, Player, Object, Action, Task, UnitAI,
or combat carrier is declared locally.

The observed calls retain these canonical virtual identities:

- `RGE_Action_Make::set_state` at action slot `+0x5C`;
- `RGE_Base_Game::notification` at `+0x40`;
- `RGE_Action_Object::die_die_die` at `+0x6C`;
- `RGE_Player::add_attribute_num` at `+0x80`;
- `RGE_Static_Object::set_attribute` at `+0x80`; and
- `RGE_Static_Object::set_attribute_amount` at `+0x84`.

These slot identities come from the original ACT_make listing and the
canonical owner declaration order. The direct source uses the reviewed
`rge_base_game` extern instead of an absolute storage expression.

## Candidate

The natural source is `src/act_make.cpp`. It keeps the five normal owners in
PDB order and the accepted-drift update in the same compiler-facing source.
The candidate proposal is `build/act_make_candidate_proposal.json`.
It uses `config/flags/default.rsp` and includes generated owner `004049E0`.

Direct ownership is registered. The grouped candidate reports all four normal
owners as `MATCH` with `0.0000%` difference. Generated `004049E0` matches.

## Open exactness issue

The accepted-drift update has matching body blocks and ordered calls, but its
isolated rebuild retains a 41-byte mismatch and three extra bytes. The current
review attributes this to the original split callee-save schedule. The direct
source preserves the natural body and does not add register steering.

The direct source compiled with the pinned VC5 compiler and
`config/flags/default.rsp`. The object was written to
`build/act_make_direct/act_make.obj`. A read-only object comparison found
`MATCH` with zero byte differences for `004049B0`, `00404A10`, `00404A40`,
`00404A70`, and generated `004049E0`. The accepted-drift `00404A90` retained
41 differing bytes, two boundary escapes, and zero incompatible relocation
targets. The grouped validator preserves that accepted-drift status.
