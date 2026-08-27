# Missile action ABI packet

## Exact symbols

The original FPO symbols prove these declarations.

- `00404C90` is `RGE_Action_Missile(RGE_Action_Object*, RGE_Static_Object*, RGE_Static_Object*, float, float, float)`.
- `00404540` is `void RGE_Action_List::add_action(RGE_Action*)`.
- `0045A740` is `RGE_Missile_Object(RGE_Master_Combat_Object*, RGE_Player*, float, float, float, int)`.
- `0045A870` is `int RGE_Missile_Object::setup(RGE_Master_Combat_Object*, RGE_Player*, float, float, float)`.

`RGE_Action_Missile` derives from `RGE_Action`.

A `RGE_Master_Missile_Object*` caller converts to its `RGE_Master_Combat_Object*` base. The missile object constructor does not take the derived master type.

## Fanout

Apply these declarations to these owner modules:

- `ACT_misl.cpp`
- `act_list.cpp`
- `misl_obj.cpp`
- `m_mi_obj.cpp`

Do not add local action, list, object, or master-class substitutes.
