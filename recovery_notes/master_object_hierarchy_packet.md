# Master-object hierarchy packet

## Scope

This packet sets canonical base ownership. It does not change a header.

## Canonical base chain

| Class | Owner | Base | Size | Added storage |
|---|---|---|---:|---|
| `RGE_Master_Static_Object` | `m_s_obj` | none | `0xB8` | Complete static master record. |
| `RGE_Master_Animated_Object` | `m_an_obj` | Static | `0xBC` | `speed` at `+0xB8`. |
| `RGE_Master_Moving_Object` | `m_mo_obj` | Animated | `0xD8` | Move and run sprites, turn and trail fields. |
| `RGE_Master_Action_Object` | `m_ac_obj` | Moving | `0xFC` | Task list, task defaults, rates, sounds, run pattern. |
| `RGE_Master_Combat_Object` | `m_co_obj` | Action | `0x148` | Fight sprite, armor, weapons, ranges, combat state. |
| `RGE_Master_Missile_Object` | `m_mi_obj` | Combat | `0x154` | Missile flags at `+0x148` and ballistics at `+0x150`. |
| `RGE_Master_Doppleganger_Object` | `m_dg_obj` | Animated | `0xBC` | Derived factory overload only. |

The sizes are from PDB class records and owner header checks.

## Static owner

`m_s_obj.h` owns the full `0xB8` record. Key fields are master type `+0x04`,
name `+0x08`, ID words `+0x0C..+0x14`, sprite pointers `+0x18..+0x20`,
radii `+0x30..+0x38`, sound pointers `+0x3C..+0x44`, damage data `+0x93..+0x94`,
help IDs `+0x98..+0xA0`, recyclable `+0xA4`, and draw data `+0xA8..+0xB4`.

The virtual prefix is destructor, copy, modify, modify delta, modify percent,
save, make object, make master, placement, alignment, damage ability, command
sound, move sound, and draw. All calls use `__thiscall`.

The PDB vtable ownership is also fixed. In the Combat vtable at `005704c0`,
Combat owns slots 0-7 and slot 10 (`calc_base_damage_ability`). Static owns
slots 8, 9, and 13 (`check_placement`, `alignment`, and `draw`). Action owns
slots 11, 12, and 14 (`play_command_sound`, `play_move_sound`, and
`create_task_list`). The Missile vtable at `00570560` has the same inherited
owners at slots 8-14. These slots are not Combat or Missile source owners.

Exact anchors are `00452120`, `00452170`, `004521A0`, and `00452FA0`.

## Derived owners

Animated adds `speed`. Moving adds `move_sprite`, `run_sprite`, `turn_speed`,
size class, trail IDs, trail options, trail spacing, and movement algorithm.

Action adds `tasks` at `+0xD8`, default task, search radius, work rate, drop
sites, task-by-group, command sound, move sound, and run pattern. Its size is
`0xFC`. It overrides both inherited sound slots. It introduces
`create_task_list` after the inherited prefix. `getTaskByTaskID(int)` is const.

Combat adds fight sprite at `+0xFC`. It adds armor and weapon records,
weapon range, area range, speed of attack, missile ID, hit chance, offsets,
and original combat values. It owns `calc_base_damage_ability` at slot 10 and
inherits the other slots after `make_new_master`. It ends at `+0x148`.

Missile adds five byte flags at `+0x148` and `ballistics_ratio` at `+0x150`.
It inherits `create_task_list` from Action through Combat. The PDB has no
Missile `create_task_list` owner, and Missile adds no virtual slot.
Doppleganger derives directly from Animated. It does not derive from Combat.

## Constructors and virtual additions

Each owner uses these `__thiscall` constructor forms:

- `(Derived*, int do_setup)`;
- `(int id, RGE_Sprite**, RGE_Sound**, int do_setup)`;
- `(FILE*, RGE_Sprite**, RGE_Sound**, short id, int do_setup)`.

Derived destructors are virtual. The inherited virtual prefix stays in order.
Action adds `create_task_list` at slot `+0x38`. Combat and Missile inherit it.
Neither class adds a new slot. Doppleganger adds the five-argument
`make_new_obj` overload.

Exact constructor and destructor anchors are:

- Animated: `0044F9C0`, `0044FA40`, `0044FAB0`, `0044FBF0`.
- Moving: `00451A20`, `00451AA0`, `00451B10`, `00451DE0`.
- Action: 19 exact anchors, including `0044F070`, `0044F0F0`, `0044F160`,
  and `0044F4D0`.
- Combat: `0044FE40`, `0044FEC0`, `0044FF30`, `00450680`.
- Missile: `00451440`, `004514C0`, `00451530`, `00451760`.
- Doppleganger: `004510C0`, `00451140`, `004511B0`, `004512C0`.

## Consumer rule

Each derived header must include its canonical base header. It declares its own
fields, constructors, owner-implemented overrides, and new virtuals. Do not
copy a base class. Do not edit `m_ac_obj.h` until Terra 4 applies this packet.
