// VA: 00413150 save (758B)
// aiuaimod.cpp
// ACCEPTED_DRIFT: 30-byte diff (3.96%) entirely benign register allocation
// in the attackingUnits grow-array loop (EBP vs EBX register choice).
// Logic, call set, stack cleanup, and memory effects are identical.
// 536-byte identical prefix before the first diff at offset 536.
// Function size matches exactly (758 bytes).

#include "../../include/aiuaimod_context.h"

void __cdecl rge_write(int fd, const void* data, int size);

void UnitAIModule::save(int fd) {
    int i;
    int temp;
    int num;
    int* ptr;
    int cnt;
    int* newArr;
    int j;

    rge_write(fd, &moodValue, 4);
    rge_write(fd, &currentOrderValue, 4);
    rge_write(fd, &currentOrderPriorityValue, 4);
    rge_write(fd, &currentActionValue, 4);
    rge_write(fd, &currentTargetValue, 4);
    rge_write(fd, &currentTargetTypeValue, 4);
    rge_write(fd, &currentTargetXValue, 4);
    rge_write(fd, &currentTargetYValue, 4);
    rge_write(fd, &currentTargetZValue, 4);
    rge_write(fd, &desiredTargetDistanceValue, 4);
    rge_write(fd, &lastActionValue, 4);
    rge_write(fd, &lastOrderValue, 4);
    rge_write(fd, &lastTargetValue, 4);
    rge_write(fd, &lastTargetTypeValue, 4);
    rge_write(fd, &lastUpdateTimeValue, 4);
    rge_write(fd, &idleTimerValue, 4);
    rge_write(fd, &idleTimeoutValue, 4);
    rge_write(fd, &adjustedIdleTimeoutValue, 4);
    rge_write(fd, &secondaryTimerValue, 4);
    rge_write(fd, &lookAroundTimerValue, 4);
    rge_write(fd, &lookAroundTimeoutValue, 4);
    rge_write(fd, &defendTargetValue, 4);
    rge_write(fd, &defenseBufferValue, 4);
    rge_write(fd, &lastWorldPositionX, 16);

    rge_write(fd, &orderQueueSizeValue, 4);
    for (i = 0; i < orderQueueSizeValue; i++) {
        rge_write(fd, (char*)orderQueueValue + i * 0x24, 0x24);
    }

    rge_write(fd, &notifyQueueSizeValue, 4);
    for (i = 0; i < notifyQueueSizeValue; i++) {
        rge_write(fd, (char*)notifyQueueValue + i * 0x18, 0x18);
    }

    temp = attackingUnitsValue.numberValue;
    rge_write(fd, &temp, 4);
    {
        int i_attack;
        for (i_attack = 0; i_attack < attackingUnitsValue.numberValue; i_attack++) {
            if (attackingUnitsValue.maximumSizeValue - 1 < i_attack) {
                int* newArr = (int*)::operator new(i_attack * 4 + 4);
                if (newArr) {
                    int j;
                    for (j = 0; j < attackingUnitsValue.maximumSizeValue; j++) {
                        if (i_attack + 1 <= j) break;
                        newArr[j] = attackingUnitsValue.value[j];
                    }
                    ::operator delete(attackingUnitsValue.value);
                    attackingUnitsValue.value = newArr;
                    attackingUnitsValue.maximumSizeValue = i_attack + 1;
                }
            }
            temp = attackingUnitsValue.value[i_attack];
            rge_write(fd, &temp, 4);
        }
    }

    if (playStatus == 0) {
        temp = 0;
        rge_write(fd, &temp, 4);
    } else {
        temp = 1;
        rge_write(fd, &temp, 4);
        playStatus->save(fd);
    }

    rge_write(fd, (char*)this + 0x130, 1);
}
