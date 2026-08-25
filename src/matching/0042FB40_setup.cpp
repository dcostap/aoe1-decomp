#ifndef RGE_COM_OBJ_SHARED_CONTEXT
#include "../com_obj_fallback_master.h"
#endif

int RGE_Combat_Object::setup(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z) {
    int i;
    float attack_timer_local;

    for (i = 0; i < 9; ++i) {
        VUR_Ptrs[i] = 0;
    }
    Unified_Map_Value = 0;
    RGE_Action_Object::setup(master_obj, player, x, y, z);
    ((unsigned char*)this)[0x4E] = 0x32;
    attack_timer_local = this->master_obj->speed_of_attack;
    attack_timer = attack_timer_local;
    capture_flag = 0;
    return 1;
}
