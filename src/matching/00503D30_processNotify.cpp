// 00503D30 TribeHuntedAnimalUnitAIModule::processNotify
// PDB: taiuaimd.cpp:99-136, 256 bytes
// int __thiscall processNotify(NotifyEvent* param_1, ulong param_2)
// ret 8 (2 params)
// FLAGS: default
//
// Attempt log:
// - Baseline used the canonical caller array fields and natural growth/copy loop;
//   the arithmetic dispatch lowered to cmp/jne and was four bytes too large.
// - A switch on mType reproduced the original subtract/je dispatch and shared tail.
// - The two notification calls are one-argument thiscall virtuals at +0xEC/+0xA4;
//   typed slot surfaces removed the incorrect extra fastcall register setup.
// - UnitAIModule owns the base vptr, so the derived subobject starts at +0x04;
//   removing the duplicate gap restored all proven array offsets and exact bytes.
// Main-agent audit restored destructor slots, qualified the base dispatch, and
// replaced manual allocation calls with natural new[]/delete[]; output remains exact.
// The shared PDB surface removes fake fields and preserves the protected virtual
// symbol ?processNotify@TribeHuntedAnimalUnitAIModule@@MAEHPAUNotifyEvent@@K@Z.

#include <stdlib.h>
#include "../../include/taiuaimd_context.h"

int TribeHuntedAnimalUnitAIModule::processNotify(NotifyEvent* evt, unsigned long param_2)
{
    switch (evt->mType) {
    case 0x1F4:
    {
        if (evt->p2 <= 0) {
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        int caller = evt->caller;

    // Search for existing caller
    int i = 0;
    while (i < this->attackingUnitsValue.numberValue &&
           i < this->attackingUnitsValue.maximumSizeValue) {
        if (this->attackingUnitsValue.value[i] == caller)
            goto done;
        i++;
    }

    // Grow array if count >= capacity
    if (this->attackingUnitsValue.numberValue >
        this->attackingUnitsValue.maximumSizeValue - 1) {
        int new_cap = this->attackingUnitsValue.numberValue + 1;
        int* new_arr = new int[new_cap];
        if (new_arr) {
            int j;
            for (j = 0;
                 j < this->attackingUnitsValue.maximumSizeValue && j < new_cap;
                 j++)
                new_arr[j] = this->attackingUnitsValue.value[j];
            delete[] this->attackingUnitsValue.value;
            this->attackingUnitsValue.value = new_arr;
            this->attackingUnitsValue.maximumSizeValue = new_cap;
        }
    }

        // Add caller to end of list
        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

        goto done;
    }

    case 0x20F:
        return 2;

    default:
        return UnitAIModule::processNotify(evt, param_2);
    }

done:
    // Notify sub via vtable+0xEC
    this->objectValue->setUnderAttack(1);

    // Notify self via vtable+0xA4
    this->runAwayFromAttackers(1);

    return 3;
}
