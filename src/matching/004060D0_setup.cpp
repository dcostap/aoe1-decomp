#include "../../include/act_obj_context.h"

int RGE_Action_Object::setup(RGE_Master_Action_Object* master_obj, RGE_Player* player, float x, float y, float z) {
    ((RGE_Moving_Object*)this)->RGE_Moving_Object::setup(master_obj, player, x, y, z);
    this->type = 0x28;
    this->waiting = 0;
    this->actions = this->create_action_list();
    this->command_flag = 0;
    return 1;
}
