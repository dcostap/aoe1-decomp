#include "../../include/act_atak_context.h"

void RGE_Action_Attack::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    if (this->move_sprite != 0) {
        if ((param_2 != 0) && (param_3 != 0) && (this->move_sprite == param_2->move_sprite)) {
            this->move_sprite = param_3->move_sprite;
        } else if (this->move_sprite ==
                   ((RGE_Master_Action_Object*)this->obj->master_obj)->move_sprite) {
            this->move_sprite = param_1->move_sprite;
        }
    }

    if (this->fight_sprite != 0) {
        if ((param_2 != 0) && (param_3 != 0) && (this->fight_sprite == param_2->work_sprite)) {
            this->fight_sprite = param_3->work_sprite;
        } else if ((param_2 != 0) && (param_3 != 0) && (this->fight_sprite == param_2->work_sprite2)) {
            this->fight_sprite = param_3->work_sprite2;
        } else if (this->fight_sprite ==
                   ((RGE_Master_Combat_Object*)this->obj->master_obj)->fight_sprite) {
            this->fight_sprite =
                ((RGE_Master_Combat_Object*)param_1)->fight_sprite;
        }
    }

    if (this->wait_sprite != 0) {
        if ((param_2 != 0) && (param_3 != 0) && (this->wait_sprite == param_2->work_sprite)) {
            this->wait_sprite = param_3->work_sprite;
            return;
        }
        if ((param_2 != 0) && (param_3 != 0) && (this->wait_sprite == param_2->work_sprite2)) {
            this->wait_sprite = param_3->work_sprite2;
            return;
        }
        if (this->wait_sprite == this->obj->master_obj->sprite) {
            this->wait_sprite = param_1->sprite;
        }
    }
}
