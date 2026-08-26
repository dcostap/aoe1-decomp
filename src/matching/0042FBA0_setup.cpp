#include "../com_obj_phase2_context.h"

int RGE_Combat_Object::setup(int handle, RGE_Game_World* world) {
    int i;

    for (i = 0; i < 9; ++i) {
        VUR_Ptrs[i] = 0;
    }
    Unified_Map_Value = 0;
    RGE_Action_Object::setup(handle, world);
    type = 0x32;
    rge_read(handle, &attack_timer, 4);
    if (!(save_game_version < 2.01f)) {
        rge_read(handle, &capture_flag, 1);
    }
    return 1;
}
