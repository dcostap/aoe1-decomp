#include "../../include/tact_rep_context.h"

extern float save_game_version;
extern void rge_read(int param_1, void* param_2, int param_3);

int TRIBE_Action_Repair::setup(int param_1, RGE_Action_Object* param_2) {
    int result = RGE_Action::setup(param_1, param_2);
    if (save_game_version >= 6.5f) {
        rge_read(param_1, &this->repair_field_40, 1);
    } else {
        this->repair_field_40 = 0;
    }
    return result;
}
