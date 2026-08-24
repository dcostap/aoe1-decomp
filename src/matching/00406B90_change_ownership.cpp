#include "../../include/act_obj_context.h"

void RGE_Action_Object::change_ownership(RGE_Player* player) {
    this->stop();
    RGE_Static_Object::change_ownership(player);
    this->set_action(0);
}
