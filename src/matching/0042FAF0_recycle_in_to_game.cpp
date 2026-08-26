#include "../com_obj_phase2_context.h"

void RGE_Combat_Object::recycle_in_to_game(RGE_Master_Static_Object* master_obj, RGE_Player* player, float x, float y, float z) {
    int i;
    float attack_timer_local;

    for (i = 0; i < 9; ++i) {
        VUR_Ptrs[i] = 0;
    }
    Unified_Map_Value = 0;
    RGE_Action_Object::recycle_in_to_game(master_obj, player, x, y, z);
    attack_timer_local = this->master_obj->speed_of_attack;
    attack_timer = attack_timer_local;
}
