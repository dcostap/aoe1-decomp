# TACTION.cpp source reunification

## PDB context

The PDB names `C:\\msdev\\work\\age1_x1\\TACTION.cpp` as the source module.
The five normal owners use `TRIBE_Action` and follow this source order:

| VA | PDB lines | Owner | State |
| --- | --- | --- | --- |
| 004D38E0 | 23-26 | `TRIBE_Action::TRIBE_Action(int, RGE_Action_Object*, int)` | matching |
| 004D3980 | 31-34 | `TRIBE_Action::TRIBE_Action(RGE_Action_Object*, int)` | matching |
| 004D39E0 | 38-40 | `TRIBE_Action::setup(int, RGE_Action_Object*)` | matching |
| 004D3A00 | 44-46 | `TRIBE_Action::setup(RGE_Action_Object*)` | matching |
| 004D3A10 | 50-52 | `TRIBE_Action::create_action_list(RGE_Action_Object*)` | matching |

The nearby 004D3950 vector deleting destructor is compiler generated. It is
not a handwritten owner in this module.

## Evidence

The former wrapper registered all five owners with zero positional difference.
Their exact anchors are the base constructor calls at 00407460 and 004074C0,
the base setup calls at 00407530 and 00407680, and the `TRIBE_Action_List`
constructor call at 004D0150 after allocation of 0x0C bytes.

The module header records the reviewed `RGE_Action`, `RGE_Action_List`, and
`TRIBE_Action` virtual surfaces and field ownership. This module does not use
`AIModule`, so it adds no duplicate AIModule declaration.

## Migration

`src/taction.cpp` is the compiler-facing owner for all five PDB functions. It
keeps the definitions in PDB order and uses `include/taction.h`. The former
`src/taction_tu.cpp` wrapper and five source fragments are removed.

The registered module uses `config/flags/gx.rsp`. The three former
per-function response files had the same `/O2 /Oy /GX` flags and are stale after
this direct-source move, so they are removed.
