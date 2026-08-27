# tact_dar.cpp source reunification

## Result

The source module has one compiler-facing owner at `src/tact_dar.cpp`.
The source follows the PDB order. This packet does not change function status.

The old context header copied action, object, map, world, player, list, and
master layouts. The owner header now includes only `action.h` and forwards the
pointer types used by its public declarations. Full dependencies are private
to `src/tact_dar.cpp`.

## PDB order and statuses

The PDB source is `C:\\msdev\\work\\age1_x1\\tact_dar.cpp`.

| VA | PDB lines | owner | status |
| --- | ---: | --- | --- |
| `004CE530` | 32-37 | `TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(int, RGE_Action_Object*)` | matching |
| `004CE5F0` | 42-48 | `TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)` | matching |
| `004CE670` | 53-61 | `TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*, float, float, float)` | matching |
| `004CE6D0` | 65-69 | `TRIBE_Action_Discovery_Artifact::save(int)` | matching |
| `004CE700` | 73-76 | `TRIBE_Action_Discovery_Artifact::first_in_stack(unsigned char)` | matching |
| `004CE720` | 80-92 | `TRIBE_Action_Discovery_Artifact::set_state(unsigned char)` | matching |
| `004CE740` | 96-121 | `TRIBE_Action_Discovery_Artifact::update()` | accepted_drift |
| `004CE7A0` | 125-165 | `TRIBE_Action_Discovery_Artifact::check_objects()` | matching |

`004CE5C0` is the compiler-generated vector deleting destructor. `004CE5E0`
is the compiler-generated destructor body. Neither is a handwritten source
owner.

## Canonical ownership

`include/tact_dar.h` owns only `TRIBE_Action_Discovery_Artifact`. The base
action and all referenced game classes come from canonical owner headers in the
source file. The module adds only its `flags` pointer at `+0x40`.

The map scan uses `RGE_Object_Node::node`, which is the canonical list-node
member. No discovery-specific layout remains.

The two named globals use `game_globals.h`. `DAT_00575078` has no named shared
owner and remains a narrow source-local declaration for its shipped read-only
reference. File I/O uses the canonical `rge_fio.h` declarations.

## Migration effects

The former `tact_dar_context.h` and wrapper are removed. The eight handwritten
definitions now live in `src/tact_dar.cpp`. The source-module configuration
records all eight original statuses. The translation-unit registry records the
seven matching owners; accepted drift remains source-module-owned but is not an
exact owner.

## Scoped validation

Final scoped checks for `004CE530`, `004CE5F0`, and `004CE7A0` returned
`MATCH` with `0.0000%`. No grouped or repository-wide validation ran.
