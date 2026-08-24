#include "../../include/act_obj_context.h"

extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern float save_game_version;

int RGE_Action_Object::setup(int handle, RGE_Game_World* world) {
    ((RGE_Moving_Object*)this)->RGE_Moving_Object::setup(handle, world);
    this->type = 0x28;
    rge_read(handle, &this->waiting, 1);
    if (save_game_version >= 6.5f) {
        rge_read(handle, &this->command_flag, 1);
    } else {
        this->command_flag = 0;
    }
    this->actions = this->create_action_list();
    this->actions->load(handle);
    return 1;
}
