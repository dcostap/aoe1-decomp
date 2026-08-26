#include "../../include/act_bird_context.h"

extern int __cdecl debug_rand(char* param_1, int param_2);

void RGE_Action_Bird::set_state(unsigned char param_1) {
    RGE_Sprite* sprite;

    this->state = param_1;
    switch (param_1) {
    case 6:
        this->timer = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x4C) * 10) / 0x7FFF + 5);
        sprite = this->task->work_sprite;
        break;

    case 4:
        this->timer = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x44) * 10) / 0x7FFF + 5);
        sprite = this->task->move_sprite;
        break;

    default:
        this->sub_actions->delete_list();
        return;
    }

    if (sprite != 0) {
        this->obj->new_sprite(sprite);
        return;
    }

    this->obj->new_sprite(this->obj->master_obj->sprite);
}
