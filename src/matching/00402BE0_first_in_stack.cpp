#include "../../include/act_expl_context.h"

void RGE_Action_Explore::first_in_stack(unsigned char value) {
    if (*(int*)&this->target_x == 0xBF800000) {
        set_state(3);
        return;
    }
    set_state(0x0B);
}
