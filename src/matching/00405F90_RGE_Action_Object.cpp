// VA: 00405F90 RGE_Action_Object::RGE_Action_Object (3-param ctor, EH-framed)
// PDB source: act_obj.cpp

#include "../../include/act_obj_context.h"

RGE_Action_Object::RGE_Action_Object(int id, RGE_Game_World* world, int flag)
    : RGE_Moving_Object(id, world, 0)
{
    this->lastActionValue = -1;
    this->lastActionStateValue = -1;
    if (flag != 0) {
        this->setup(id, world);
    }
}
