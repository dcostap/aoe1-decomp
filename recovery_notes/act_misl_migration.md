# ACT_misl.cpp source-module migration

## Result

The complete canonical owner chain is now available. `include/m_co_obj.h`,
`include/com_obj.h`, `include/misl_obj.h`, and `include/m_mi_obj.h` own the
master-combat, combat, missile, and master-missile classes.

This packet is rebased onto current `main`. It reunifies `ACT_misl.cpp` into
`src/act_misl.cpp` and declares `RGE_Action_Missile` in `include/act_misl.h`.
The old context header, wrapper, and fragment owners are removed.

The first candidate compile exposed two source issues: the canonical master
speed field was protected, and the canonical collision node field is `node`,
not `object`. Commit `60a5de34c` corrected the field accesses. Commit
`2cfa42f31` then published `speed` as a public PDB-correct field, and
`7e6eeecdf` removed the temporary friend declaration.

The resumed grouped candidate validation completed with no comparison errors.
All five exact owners matched. Both compiler-generated destructors matched.
The two observed owners remain mismatches under their reviewed statuses.

## PDB source order and ownership

The PDB source is
`C:\\msdev\\work\\age1_x1\\ACT_misl.cpp`. The normal owners are in this
order:

1. `00404BB0` `RGE_Action_Missile::RGE_Action_Missile(int, RGE_Action_Object*)`,
   126 bytes, matching.
2. `00404C90` `RGE_Action_Missile::RGE_Action_Missile(
   RGE_Action_Object*, RGE_Static_Object*, RGE_Static_Object*, float, float,
   float)`, 126 bytes, matching.
3. `00404D10` `RGE_Action_Missile::first_in_stack(unsigned char)`, 62 bytes,
   matching.
4. `00404D50` `RGE_Action_Missile::intercept(float&, float&, float&)`,
   85 bytes, matching.
5. `00404DB0` `RGE_Action_Missile::set_state(unsigned char)`, 805 bytes,
   scratch.
6. `004050F0` `RGE_Action_Missile::update()`, 955 bytes, accepted drift.
7. `004054B0` `RGE_Action_Missile::save(int)`, 94 bytes, matching.

`004050D5` is a three-byte padding/data-dispatch neighborhood inside
`set_state`. It is not a source owner. `00404C60` and `00404C80` are
compiler-generated destructor COMDATs. They have no source-bank body here.

The current source owner is `src/act_misl.cpp`. The source module keeps the
five matching owners, the scratch `00404DB0` owner, and the accepted-drift
`004050F0` owner in PDB order.

## Available canonical dependencies

The source recovery will use these owner headers when the complete dependency
surface is available:

- `include/action.h` for `RGE_Action` and its virtual order;
- `include/act_obj.h` for `RGE_Action_Object`;
- `include/move_obj.h` and `include/ani_obj.h` for the moving-object chain;
- `include/m_co_obj.h` for `RGE_Master_Combat_Object`;
- `include/com_obj.h` for `RGE_Combat_Object`;
- `include/misl_obj.h` for `RGE_Missile_Object`;
- `include/m_mi_obj.h` for `RGE_Master_Missile_Object`;
- `include/stat_obj.h` for `RGE_Static_Object` and collision records;
- `include/m_s_obj.h` for `RGE_Master_Static_Object`;
- `include/m_ac_obj.h` for `RGE_Master_Action_Object`;
- `include/player.h` for `RGE_Player`;
- `include/map.h` and `include/world.h` for map/world owners.

All four headers are canonical owner surfaces. No context header or substitute
class is required by `src/act_misl.cpp`.

## Canonical owner closure

The canonical chain is now complete:

- `include/m_co_obj.h` owns `RGE_Master_Combat_Object` at size `0x148`;
- `include/com_obj.h` owns `RGE_Combat_Object` over `RGE_Action_Object` at
  size `0x1C4`;
- `include/misl_obj.h` owns `RGE_Missile_Object` over `RGE_Combat_Object` at
  size `0x1C8`.
- `include/m_mi_obj.h` owns `RGE_Master_Missile_Object` over
  `RGE_Master_Combat_Object` at size `0x154`.

The combat header owns the `VUR_Ptrs[9]`, `Unified_Map_Value`, `attack_timer`,
and `capture_flag` tail at `+0x194`, `+0x1B8`, `+0x1BC`, and `+0x1C0`. It also
preserves `area_attack` at virtual slot `+0x21C`, the two `attack` overloads at
`+0x220` and `+0x224`, and `do_attack` at `+0x228`. The missile header owns
`max_range` at `+0x1C4`, `missile_move()`, and
`make_object_collision_list(float)`.

The ACT_misl call sites compare `max_range` at `004051FC`, call
`missile_move()` at `0040528E`, call `make_object_collision_list(float)` at
`0040530B`, and call the combat `do_attack` slot at `004052CB`, `004052F2`, and
`0040541C`. Main commits `04e1b281c`, `889cc533f`, and `2034f859c` publish the
canonical missile and Master Missile owner surfaces.

The Master Missile owner has this exact tail:

The owner is `RGE_Master_Combat_Object` derived, with size `0x154`. Its exact
tail is:

- `unsigned char missile_type` at `+0x148`;
- `unsigned char targetting_type` at `+0x149`;
- `unsigned char missile_hit_info` at `+0x14A`;
- `unsigned char missile_die_info` at `+0x14B`;
- `unsigned char area_effect_specials` at `+0x14C`;
- three bytes of padding at `+0x14D`;
- `float ballistics_ratio` at `+0x150`.

`ACT_misl.cpp` reads `targetting_type` at `00404E3B`, `missile_type` at
`00404F8F` and `004051BF`, `ballistics_ratio` at `00405026` and `0040506C`,
and `missile_hit_info` at `00405330`. The other tail fields are proven by the
`RGE_Master_Missile_Object` layout inventory but are not read by this module.

No named `RGE_Master_Missile_Object` method is called by `ACT_misl.cpp`. The
owner still needs its original inherited virtual order and its constructors
and `setup` overloads. The inventory records these exact methods:

- virtual destructor, `copy_obj`, `modify`, `modify_delta`, `modify_percent`,
  `save`, `make_new_obj`, `make_new_master`, `check_placement`, `alignment`,
  `calc_base_damage_ability`, `play_command_sound`, `play_move_sound`,
  `draw`, and `create_task_list`;
- constructors for default, copy, integer/resource, and file/resource forms;
- `setup(RGE_Master_Missile_Object*)`, `setup(int,RGE_Sprite**,RGE_Sound**)`,
  and `setup(FILE*,RGE_Sprite**,RGE_Sound**,short)`.

Evidence: `inventory/classes/dumps/RGE_Master_Missile_Object.txt`,
`orig/ghidra_decomp/act_misl.cpp.asm`, and the original vtable records.

## Natural source proposal

The final owner now uses one source module in PDB order. It includes
`act_misl.h`, `act_obj.h`, `m_mi_obj.h`, `misl_obj.h`, `player.h`, `rge_fio.h`,
`stat_obj.h`, and `world.h`. It defines no local owner classes and uses no
context header.

## Validation plan

The grouped candidate result is:

- exact: 5 of 5 matched, with zero diff bytes, zero relocation target
  mismatches, and zero boundary escapes;
- observed: `00404DB0` differs by 210 bytes (26.0869%), and `004050F0`
  differs by 319 bytes (33.4031%); both retain matching ownership,
  relocations, and boundaries;
- generated: `00404C60` and `00404C80` both matched with zero diff bytes;
- compiled: 7 of 9 rows matched; comparison errors: 0;
- full-module exact: false because the two observed rows are not exact.
