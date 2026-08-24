// attempt 9: keep the decompiler-style int locals that produced the right SIB/base order,
// but restore the original predicate spellings (>= 4 and >= 0)

#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::give_building_attribute_to_owner() {
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;

    iVar4 = 0;
    iVar2 = 0x6A;
    iVar3 = 0x70;
    do {
        iVar1 = (int)this->pManager;
        if (*(unsigned char*)(iVar4 + 0x88 + iVar1) >= 4) {
            short amount = *(short*)(iVar2 + iVar1);
            if (amount >= 0) {
                this->owner->give_resources(amount, *(int*)(iVar3 + iVar1), 0);
            }
        }
        iVar3 = iVar3 + 4;
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 2;
    } while (iVar3 < 0x7C);
}
