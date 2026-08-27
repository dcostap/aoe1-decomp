#include "../../include/tact_hea.h"

// BINARY NOTE: the target object is the RGE_Action field at +0x10.
// Its master object supplies the short kind field at +0x14.
void TRIBE_Action_Heal::first_in_stack(unsigned char) {
    if (this->target_obj != 0) {
        short kind = this->target_obj->master_obj->object_group;
        if (kind == 0x15 || kind == 2 || kind == 0x14 || kind == 0x16) {
            return;
        }
        this->set_state(4);
        return;
    }
    this->set_state(3);
}
