# `src/com_obj.cpp` source-cleanup report

## Scope and commits

- Module: `src/com_obj.cpp`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `81c9c0021f91a9b63fb38448f87bb51379763d67`
- Changed files: `src/com_obj.cpp` and this report.
- Branch: `cleanup/staging-20260915-222`
- Header owner: owner 25 owns `include/com_obj.h`. This worker did not edit it.
- Registry: `config/functions/src/com_obj.cpp.json`, build flags `gx`.

The original executable evidence is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The scoped PDB evidence is:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

Its SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The preserved build is under:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build`

## Original-name recovery

I reviewed all 50 handwritten functions assigned to this source. I checked the
procedure-scoped PDB stack, local, and register records for every function.
Each function has `this` in `ecx`. The PDB source path is
`C:\\msdev\\work\\age1_x1\\com_obj.cpp`.

The following parameter names are recovered from those PDB records. Names not
listed in a row were already equal to the PDB name or the function has no named
parameter record.

| VA | Function | Recovered names used in source |
| --- | --- | --- |
| `0042F930` | constructor | `tobj`, `obj_owner` |
| `0042F9E0` | constructor | `infile`, `gworld` |
| `0042FAF0` | `recycle_in_to_game` | `tobj`, `obj_owner` |
| `0042FB40` | `setup(RGE_Master_Combat_Object*, ...)` | `tobj`, `obj_owner` |
| `0042FBA0` | `setup(int, RGE_Game_World*)` | `infile`, `gworld` |
| `0042FC10` | `save` | `outfile` |
| `0042FC90` | `calc_attack_modifier` | `target` |
| `0042FCA0` | `area_attack` | `ignore_object` |
| `004300F0` | `attack(float, float, float, ...)` | `target_x`, `target_y`, `target_z` |
| `00430230` | `do_attack` | `x`, `y`, `z`; local `attack_modifier` |
| `00430320` | `damage` | `weapon_num`, `damage`, `attack_modifier`, `attacking_player`, `attackingObject` |
| `004303A0` | `calculateDamage` | `weapon_num`, `damage`, `attack_modifier`, `attacking_player`, `attackingObject` |
| `004304B0` | `get_armor` | `cur_armor_in`, `orig_armor_in` |
| `00430510` | `get_weapon` | `cur_weapon_in`, `orig_weapon_in` |
| `00430570` | `get_weapon_range` | `cur_weapon_range_in`, `orig_weapon_range_in` |
| `004305A0` | `get_speed_of_attack` | `cur_speed_of_attack_in`, `orig_speed_of_attack_in` |
| `004305D0` | `release_being_worked_on` | `caller` |
| `00430610` | `enter_obj` | `target` |
| `00430680` | `update` | locals `returnResult`, `sighted_by_player` |
| `00430810` | `copy_obj` | `source2` |
| `00430850` | `notify` | `caller`, `recipient`, `mType`, `p1`, `p2`, `p3` |
| `004308C0` | `attack(int, int)` | `targetID`, `unconditional` |
| `00430A90` | `attack(float, float, float, int)` | `unconditional` |
| `00430C10` | `moveTo(int, int)` | `targetID`, `unconditional` |
| `00430C30` | `moveTo(int, float, int)` | `targetID`, `minRange`, `unconditional` |
| `00430D50` | `moveTo(float, float, float, float, int)` | `minRange`, `unconditional` |
| `00430EC0` | `moveAwayFrom` | `targetID`, `unconditional` |
| `00430ED0` | `gather` | `targetID`, `unconditional` |
| `00431020` | `explore` | `tX`, `tY`, `unconditional` |
| `00431150` | `enter` | `targetID`, `unconditional` |
| `00431250` | `transport` | `tX`, `tY`, `tZ`, `unconditional` |
| `00431340` | `unload` | `unconditional`, `x`, `y`, `z` |
| `004314F0` | `damageCapability(RGE_Static_Object*)` | parameter `attackingUnit`, local `attackModifier` |
| `00431530` | `inAttackRange` | parameter `target`, locals `radiusDistance`, `rangeDistance` |

The remaining assigned functions have no changed PDB parameter name: the
second attack overload at `0042FF50` already used `target` and `attacker`;
`can_attack`, `reset_attack_timer`, `stopAction`, `pause`, `rateOfFire`, the
non-argument `damageCapability`, `weaponRange`, `minimumWeaponRange`, the four
current-target accessors, and `teleport` already used the PDB names or have no
parameters. The destructor and `stop` also have no named parameter record.

The source keeps the PDB's mixed spelling. This includes `obj_owner`,
`attackingObject`, `mType`, `targetID`, `tX`, and `returnResult`.

## Locals and unresolved mappings

The PDB local records that map directly to current declarations are preserved:

- `0042FCA0` records `attack_modifier`, `map`, `x1`, `x0`, `r2`, and `dy`.
- `0042FF50` and `004300F0` record `rangeDistance`, `c`, and `s`.
- `00430230` records `attack_modifier`.
- `004303A0` records `tot_armor`.
- `00430680` records `returnResult` and `sighted_by_player`.
- `004314F0` records `attackModifier`.
- `00431530` records `radiusDistance` and `rangeDistance`.

The area-attack PDB record named `ry` has type `float`, but its recorded stack
slot holds the map-row pointer in the original instructions. The current
source uses typed `short yy` and a map-row walk instead. I did not force `ry`
onto `yy` or another declaration. The PDB also does not provide reliable
names for the current `radius`, `maxx`, `maxy`, `y0`, `y1`, `xx`, `link`, and
object locals. Existing names for these locals remain descriptive cleanup
names, not recovered originals.

Other existing locals such as `attack_timer_local`, `combat_master`,
`source_master`, `weaponKind`, `armorTbl`, and `nArmor` have
no matching scoped PDB record. I did not change their scope, type, storage, or
name. The PDB `tot_armor` record shares a stack home with the `damage`
parameter through lifetime reuse. The source keeps separate declarations.

The generated global names `DAT_0056f49c`, `DAT_0056f4a0`,
`DAT_0056f4a8`, and `DAT_0056f4ac` remain unchanged. Their declarations belong
to the root-owned `game_globals` module. No shared declaration request is
open.

## Constants, resources, comments, and formatting

No numeric constant was changed. No resource lookup occurs in this module.
No resource ID or shared constant was added.

The existing comments before the repeated `get_action()` calls remain. The
original instruction packets for `00431250` and `00431340` show a second
`get_action()` call before `work()`, so these comments record a real behavior
constraint. No new comment was needed.

Opening braces for multi-line function definitions now use 1TBS style. The
source order, declarations, types, casts, scopes, expressions, calls,
control flow, and fixed debug source-line arguments remain unchanged.

## Recovered versus descriptive names

All changed parameter and local names listed above are recovered original PDB
names. No new local name was introduced. Existing descriptive names remain
unclaimed where the PDB gives no reliable mapping. The source does not rename
public functions, classes, members, globals, or ABI symbols.

## Code-generation risks

Parameter and local renames do not change ABI symbols, types, layout, storage,
call targets, relocations, or evaluation order. Brace movement can change
source debug line records. No compiler check was run. The source did not edit
the header, registry, or build recipe.

## Validation and open questions

I reviewed the complete source diff with Git. Compilation, matching, audits,
linked validation, automated tests, menus, gameplay, and a fresh build were not
run. No compiler, build, matching, audit, validation, test, or game command was
run for this assignment.

The unresolved local mapping is the PDB `ry` stack slot in `area_attack`. The
suspected generated global names listed above also need any future coordinated
shared-name review.
