# Source cleanup report: `t_c_obj.cpp`

## Delivery

- Module: `src/t_c_obj.cpp`
- Branch: `cleanup/staging-20260915-132`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source-cleanup commit: `bf2b9f6c5d2c281741d6ebcc97fdb908447a3d45`
- Assigned header: `include/t_c_obj.h` (read only; not changed)
- Registry: `config/functions/src/t_c_obj.cpp.json`
- PDB source: `C:\\msdev\\work\\age1_x1\\t_c_obj.cpp`
- Changed files: `src/t_c_obj.cpp`; this report

The report is committed after the source-cleanup commit. The handoff response
records the final report commit hash.

The source changes restore procedure-scoped names and apply 1TBS formatting.
They do not add executable statements or declarations.

## Evidence

The name recovery uses the procedure-scoped records in
`inventory/pdb/scoped_symbols.json`. The local extraction is preserved in
`build/t_c_obj_pdb.tsv`.

I inspected the assigned function packets under
`inventory/functions/004C/`, including the packets from `004CA0F0` through
`004CC5B0`. I also inspected the original assembly and decompiler records in:

- `orig/ghidra_decomp/t_c_obj.cpp.asm`
- `orig/ghidra_decomp/t_c_obj.cpp.decomp`

The registry contains 39 normal source functions. The PDB also contains the
compiler-generated scalar deleting destructor at `004CA180`. The original
executable remains the behavior oracle.

The registry status at the base commit is 37 `matching`, one
`new_verified_logic`, and one `accepted_drift`.

## PDB recovery coverage

All 40 procedure records were inspected. Names listed as restored came from
PDB records. Names listed as retained were already supported by the source or
had no safe PDB declaration mapping.

| VA | Function | Recovery result |
| --- | --- | --- |
| `004CA0F0` | constructor | Restored `tobj`, `obj_owner`, and `do_setup`; kept `x`, `y`, and `z`. |
| `004CA180` | scalar deleting destructor | PDB records only `__flags`; this compiler-generated body has no source owner. |
| `004CA1A0` | load constructor | Restored `infile` and `gworld`; kept `do_setup`. |
| `004CA210` | destructor | No stack names. |
| `004CA300` | `setup` | Restored `tobj` and `obj_owner`; kept `x`, `y`, and `z`. |
| `004CA3E0` | load `setup` | Restored `infile`, `gworld`, and `needUnitAI`; kept `master_type`. The PDB reuses the `gworld` parameter slot for `needUnitAI`. |
| `004CA510` | `create_action_list` | No stack names. |
| `004CA570` | `save` | Restored `outfile` and `haveUnitAI`. The `haveUnitAI` PDB record is reused for both branches. |
| `004CA5F0` | `update` | No stack names. |
| `004CA640` | `modify` | Restored `amount` and `flag`. |
| `004CA700` | `transform` | Restored `obj`; kept local `old_master`. |
| `004CA740` | `set_object_state` | Restored `new_object_state`. |
| `004CA780` | `cancel_object` | No stack names. |
| `004CA790` | `die_die_die` | No stack names. |
| `004CA7F0` | `damage` | Restored `weapon_num`, `damage`, `attack_modifier`, `attacking_player`, `attackingObject`, and `temp_hp`. |
| `004CA8C0` | `change_ownership` | Restored `new_owner`. |
| `004CAA00` | `calc_attack_modifier` | Kept PDB-supported parameter `target`; no local PDB name required. |
| `004CAA50` | `attack` | Restored `attacker`; kept `target`. |
| `004CAAA0` | `do_attack` | Kept `target`, `attacker`, `x`, `y`, and `z`; restored local `attack_modifier`. |
| `004CAC10` | `get_armor` | Restored output names `cur_armor_in` and `orig_armor_in`. |
| `004CAC80` | `get_pierce_armor` | Restored output names `cur_armor_in` and `orig_armor_in`. |
| `004CACE0` | `reposition_artifact` | Restored local `x`; the other PDB names were already present. |
| `004CB040` | `can_debark` | No stack names. |
| `004CB060` | `hunt` | Restored `targetID` and `unconditional`. |
| `004CB1B0` | `convert` | Restored `targetID` and `unconditional`. |
| `004CB300` | command `heal` | Restored `targetID` and `unconditional`. |
| `004CB450` | `repair` | Restored `targetID` and `unconditional`. |
| `004CB5C0` | `build` | Restored `targetID` and `unconditional`. |
| `004CB710` | `trade` | Restored `targetID` and `unconditional`. |
| `004CB860` | `keepGatheringWhenObjectIsOut` | Restored `oType`. |
| `004CB880` | `produceWhenKilledBy` | Restored `oGroup`. |
| `004CB8B0` | `useSameZoneDropsite` | No stack names. |
| `004CB8D0` | `initUnitAI` | No stack names. |
| `004CBD30` | `lines_intersect` | Restored `a_x1`, `a_y1`, `a_x2`, `a_y2`, `b_x1`, `b_y1`, `b_x2`, and `b_y2` in the declaration and definition. |
| `004CBD40` | `higher_check_for_cliff` | Restored `XTileInt`, `YTileInt`, `StartX`, `StartY`, `DestX`, `DestY`, `Map`, `LastCliffObject`, `AngleToTarget`, and `HigherCalc`. |
| `004CBEF0` | `higher_than_target` | Kept PDB-supported `target` and the existing PDB-supported local names. |
| `004CC1B0` | `area_attack` | Restored `z`, `ignore_object`, `r2`, `x1`, outer `x0`, and `ry`; kept `x`, `y`, `attacker`, `map`, `dx`, `dy`, and `attack_modifier`. |
| `004CC4C0` | float `heal` | Restored `healing`. |
| `004CC570` | `canRepair` | No stack names. |
| `004CC5B0` | `do_repair` | Restored `obj`, `task`, and `skip`; kept the other descriptive locals. |

The PDB records reuse optimized stack slots. In particular, the load `setup`,
`save`, `area_attack`, and `do_repair` records do not describe one unique
source declaration for every slot. I did not change types, scopes, storage,
or declaration arrangement to force an uncertain mapping. The PDB `x0` record
has type `short`; it maps to the outer x-bound. The inner floating-point
distance keeps the existing descriptive name `dx`. Ghidra labels that inner
value `_x0` to avoid the outer-name collision, but that label does not prove
an original source name.

## Recovered and descriptive names

Recovered names are the PDB spellings listed in the table. This includes the
mixed-case names `needUnitAI`, `haveUnitAI`, `targetID`, `oType`, `oGroup`,
`XTileInt`, `StartX`, `AngleToTarget`, and `HigherCalc`.

The source keeps existing descriptive names where the PDB has no record or
where optimized slot reuse does not prove a declaration mapping. Examples
include `master`, `old_master`, `target_master`, `repair_list`, `task_count`,
`task_list`, `current_task`, `action_type`, `action_worked`, `action`, `order`,
and `current_action`. These are cleanup names, not claims about original
source spelling.

## Constants, resources, and comments

- No constant, enum, resource ID, or resource declaration was added.
- No resource lookup occurs in this module.
- No shared-file request is needed.
- No source comment was added. The existing destructor compatibility comment remains.
- No public function, class, member, global, header declaration, or ABI symbol changed.

The existing repair handoff remains `owner->master_objects[0x9C]` in
`repair`. The existing defects remain unchanged:

- The destructor reads `master->id` before it tests `master` for null.
- `do_repair` can use the uninitialized `task` value when its task list is empty.

The second item is the renamed PDB variable formerly called `repair_task`. The
rename does not initialize it or change the empty-list path.

## Code-generation-sensitive points

- Parameter and local names changed only identifiers.
- Function definitions now use 1TBS opening braces.
- Indentation and wrapping changed in assigned source only.
- Types, casts, scopes, storage duration, statements, expressions, literals,
  strings, calls, call order, and source order remain unchanged.
- No helper, wrapper, structural rewrite, bug fix, or modernization was made.

The cleanup can change debug line records. Compiler output, relocations, call
targets, and program data remain unvalidated because the requested checks were
deferred.

## Review and validation

I reviewed the complete Git diff against the base commit and ran
`git diff --check`. The review found only identifier, indentation, wrapping,
and brace-placement changes. I did not run a compiler or build command.

Compilation, matching, audits, and tests were **NOT run**, as required for this
cleanup wave. No game or runtime validation was run.
