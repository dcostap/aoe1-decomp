#include "../../include/tact_hea_context.h"

void TRIBE_Action_Heal::first_in_stack(unsigned char) {
    if (this->actionObject != 0) {
        short kind = *(short*)(*(char**)((char*)this->actionObject + 8) + 0x14);
        if (kind == 0x15 || kind == 2 || kind == 0x14 || kind == 0x16) {
            return;
        }
        this->set_state(4);
        return;
    }
    this->set_state(3);
}
