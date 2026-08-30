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
| 004D10F0 | 126-167 | `update()` | scratch; canonical owner now available |
| 004D12B0 | 171-233 | `place_obj(RGE_Static_Object**)` | matching |
| 004D1550 | 237-251 | `stop()` | matching |
| 004D15F0 | 255-268 | `get_info(short&, short&, char*, short)` | matching |

The nearby vector-deleting destructor at 004D0E90 is compiler generated. It
has no handwritten source owner. The candidate packet also lists its expected
symbol `??_ETRIBE_Action_Make_Obj@@UAEPAXI@Z` as a generated row.

## Canonical owner state

The owner-only `include/tact_mob.h` includes only the reviewed `action.h`
surface and pointer forwards for the local class. The source module consumes
the reviewed `act_obj.h`, `stat_obj.h`, `m_co_obj.h`, `world.h`, `player.h`,
`tplayer.h`, `basegame.h`, `rge_base_game_global.h`, `game_globals.h`, and
`rge_fio.h` surfaces. The source also consumes canonical `tm_co_ob.h`. The
header has no local action, list, object, world, player, or vtable carrier
declarations. The module has no raw vptr writes or raw calls.

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
`include/tm_co_ob.h`. The current owner header composes canonical
`m_co_obj.h`, uses natural `Attribute_Cost` alignment, and checks the field
offset and complete size without explicit padding fields.

`src/tact_mob.cpp` now uses that owner for both +0x15A reads. It does not use a
local field carrier or a raw offset.

The seven exact owners are now registered in `config/translation_units.json`.
The two former accepted-drift owners are scratch in
`config/source_modules/tact_mob.json`. 004D10F0 remains scratch pending a
separate owner review. 004D15F0 is now promoted only after its final target
check; this does not promote the rest of the Tact Mob chain.

The old wrapper, context, per-owner source fragments, and per-owner response
files are removed. The header cleanup invalidates the previous grouped object.

The scoped candidate check used all seven exact owners, the two accepted-drift
owners, the remaining scratch owner, and generated 004D0E90. The canonical
owner change produced these results:

- 004D15F0 `get_info`: `MATCH`, 0 bytes, owner match, 0 relocation target
  mismatches, and 0 boundary escapes. The rebuilt size is 140 bytes.
  An exact-finish walkback removed the named master pointer without changing
  the bytes, so the direct owner expression is retained.
- 004D10F0 `update`: `MISMATCH`, 281 bytes, owner match, 0 relocation target
  mismatches, and 0 boundary escapes. The rebuilt size is 442 versus 446.
- 004D1550 `stop` now uses direct owner rereads. The original reloads
  `obj->owner` for reimbursement and notification instead of keeping a
  persistent player alias. This natural change produces `MATCH`, 0 bytes,
  owner match, 0 relocation target mismatches, and 0 boundary escapes.
- Prior exact owners 004D0DD0, 004D0EF0, 004D0F70, and 004D10E0 remain
  `MATCH`, each with 0 bytes, 0 relocation target mismatches, and 0 boundary
  escapes.
- 004D12B0 `place_obj` now produces `MATCH`, 0 bytes, frame 0x18, 8/8 calls
  aligned, owner match, 0 relocation target mismatches, and 0 boundary
  escapes. The original success arm rereads
  `this->obj->owner->master_objects[this->obj_id]` for `make_new_obj`.
  Reusing the live `proto` pointer adds a vtable spill, changes the frame to
  0x1C, and returns to the 580-byte mismatch. The direct reread is therefore
  retained as the natural source form.
- Generated 004D0E90 remains `MATCH`, with 0 bytes, 0 relocation target
  mismatches, and 0 boundary escapes.
- Observed 004D0FC0 remains a 268-byte scratch mismatch. Observed
  004D10F0 remains a 281-byte scratch mismatch. 004D15F0 is promoted to
  matching after its final target check: `MATCH`, 0 bytes, owner match, 0
  relocation target mismatches, and 0 boundary escapes. The final check proves
  the direct symbol
  `?get_info@TRIBE_Action_Make_Obj@@QAEXAAF0PADF@Z`, the PDB owner
  `tact_mob.cpp:255-268`, and the body boundary `004D15F0-004D167B`.
  The post-rebase candidate report records an overload-selection comparison
  error for former accepted-drift 004D0EB0. Its status is now scratch.

The fresh direct-module audit is
`build/candidate_tus/audit_tact_mob_final/report.txt`. The post-rebase full
candidate report has 7/7 registered exact-owner matches,
0/3 observed matches, and 1/1 generated matches. The old observed comparison
error for 004D0EB0 is resolved only by selecting its decorated constructor
symbol. The fresh direct-module audit then reports 31 differing bytes for
004D0EB0 and 268 differing bytes for 004D0FC0. Both remain scratch because
the former row required a comparison-error exception and the latter has a
missing virtual call and broad call-surface drift.

The final target checks report exact 004D12B0, 004D1550, and 004D15F0 results.
Only 004D15F0 changed status in this promotion. Current main contains the
validated canonical `tm_co_ob` owner at 548cc00fc; duplicate 49b7f8550 is not
in this rebased chain.
