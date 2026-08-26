// TRIBE_Panel_Inven::save_info
// Syncs save_attr array with player's ability values.

extern "C" void __cdecl free(void* block);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

#include "../../include/tpnl_inv_context.h"

void TRIBE_Panel_Inven::save_info() {
    int iVar3 = 0;
    if (this->save_attr != (short*)0) {
        if (this->save_attr_num == this->player->field_4C)
            goto fill_values;
    }
    if (this->save_attr != (short*)0) {
        free(this->save_attr);
        this->save_attr = (short*)0;
    }
    this->save_attr_num = this->player->field_4C;
    this->save_attr = (short*)calloc((int)this->save_attr_num, 2);

fill_values:
    if (this->save_attr_num > iVar3) {
        do {
            int next = iVar3 + 1;
            this->save_attr[iVar3] = (short)(int)this->player->field_50[iVar3];
            iVar3 = next;
        } while (iVar3 < this->save_attr_num);
    }
}
