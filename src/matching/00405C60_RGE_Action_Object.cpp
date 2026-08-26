// VA: 00405C60 RGE_Action_Object::RGE_Action_Object (7-param ctor, EH-framed)
// PDB source: act_obj.cpp

#include "../../include/act_obj_context.h"

RGE_Action_Object::RGE_Action_Object(RGE_Master_Action_Object* master,
                                     RGE_Player* player,
                                     float x, float y, float z, int flag)
    : RGE_Moving_Object(master, player, x, y, z, 0)
{
    this->lastActionValue = -1;
    this->lastActionStateValue = -1;
    if (flag != 0) {
        this->setup(master, player, x, y, z);
    }
}
