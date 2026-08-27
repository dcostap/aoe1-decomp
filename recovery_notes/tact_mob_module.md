# tact_mob.cpp recovery notes

## PDB context

The PDB names `C:\\msdev\\work\\age1_x1\\tact_mob.cpp` as the source
module. The ten normal owners keep this address and source order:

| VA | PDB lines | Owner | State |
| --- | --- | --- | --- |
| 004D0DD0 | 31-41 | `TRIBE_Action_Make_Obj(int, RGE_Action_Object*)` | matching |
| 004D0EB0 | 48-54 | `TRIBE_Action_Make_Obj(RGE_Action_Object*, short, int, uchar)` | accepted_drift |
| 004D0EF0 | 60-65 | `~TRIBE_Action_Make_Obj()` | matching |
| 004D0F70 | 69-76 | `save(int)` | matching |
| 004D0FC0 | 79-116 | `first_in_stack(uchar)` | accepted_drift |
| 004D10E0 | 120-123 | `set_state(uchar)` | matching |
| 004D10F0 | 126-167 | `update()` | scratch; master gap |
| 004D12B0 | 171-233 | `place_obj(RGE_Static_Object**)` | matching |
| 004D1550 | 237-251 | `stop()` | matching |
| 004D15F0 | 255-268 | `get_info(short&, short&, char*, short)` | scratch; master gap |

The nearby vector-deleting destructor at 004D0E90 is compiler generated. It
has no handwritten source owner. The candidate packet also lists its expected
symbol `??_ETRIBE_Action_Make_Obj@@UAEPAXI@Z` as a generated row.

## Canonical owner state

The owner-only `include/tact_mob.h` includes only the reviewed `action.h`
surface and pointer forwards for the local class. The source module consumes
the reviewed `act_obj.h`, `stat_obj.h`, `m_co_obj.h`, `world.h`, `player.h`,
`tplayer.h`, `basegame.h`, `rge_base_game_global.h`, `game_globals.h`, and
`rge_fio.h` surfaces. The header has no local action, list, object, world,
player, or vtable carrier declarations. The module has no raw vptr writes or
raw calls.

The canonical `tplayer.h` owner publishes the required helpers and train
virtuals:

- `pay_obj_cost(short, float, int)`;
- `reimburse_obj_cost(short)`;
- virtual `cancelTrain(int, int, int, int)` at vtable offset `0x10C`;
- virtual `registerTrain(int, int, int, int)` at vtable offset `0x110`.

The +0x15A field is not owned by `RGE_Master_Static_Object` in `m_s_obj.h`,
`RGE_Master_Action_Object` in `m_ac_obj.h`, or `RGE_Master_Combat_Object` in
`m_co_obj.h`. The inventory type dump proves the true owner is
`TRIBE_Master_Combat_Object::build_pts_required`, at +0x15A, in
`include/tm_co_ob.h`, the owner header for `tm_co_ob.cpp`.

`tm_co_ob.h` currently carries a duplicate base hierarchy and an empty
`RGE_Static_Object` declaration. It cannot compose with the canonical object
and master headers used by this module. Do not add a local field shim. Keep
004D10F0 (`update`) and 004D15F0 (`get_info`) scratch until the exact
`TRIBE_Master_Combat_Object` owner surface is composable or is otherwise
published for this module.

The six unaffected exact owners remain registered in
`config/translation_units.json`. The two accepted-drift owners remain
reviewed in `config/source_modules/tact_mob.json`. The two owners that read
the +0x15A field remain scratch and are not registered.

The old wrapper, context, per-owner source fragments, and per-owner response
files are removed. The header cleanup invalidates the previous grouped object.

The scoped candidate check used
`build/candidate_tus/tact_mob.json` and the six exact owners, the two accepted
drift owners, the two scratch owners, and generated 004D0E90. It stopped before
comparison because `RGE_Master_Static_Object` has no `train_time` member at
the two scratch-owner references in `src/tact_mob.cpp` (lines 152 and 294).
The scoped grouped observed check for `tact_mob_cpp` stopped for the same two
compile errors. It compiled zero groups and produced zero comparison rows.
The full source row state remains the table above; no scratch owner is
promoted.
