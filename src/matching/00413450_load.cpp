// VA: 00413450 load (949B)
// aiuaimod.cpp
// EH frame (/GX) — same as ctor/dtor: VC5 only generates with full TU context
// Also has AIPlayStatus new/construct/load and dual version checks (6.93, 7.02)
// These require full TU context to match exactly.
// Attempt log:
// - Baseline: natural typed field/queue reconstruction was 59 bytes short,
//   frame 0x2C versus 0x3C, and missed the AIPlayStatus constructor call.
// - Added the binary-proven AIPlayStatus size/constructor surface and restored
//   the unconditional load after the new-expression; checking this as the
//   first structural hypothesis.
// - Separate serialized count locals, the recipient-offset event overlay, the
//   positive 6.93 version gate, and an indexed attacking-unit scan recovered
//   the original call order and block layout.
// - The local NotifyEvent payload gap is intentional: the 0x24-byte order
//   read starts at recipient and proves the larger stack window (frame 0x3C).
// - The equality edge is a binary-proven shared skip-add path. A direct
//   source label preserves that edge; replacing it with a found flag moved
//   the compiler into a broader, less faithful basin.
// - Best current check: 953 rebuilt bytes versus 949, exact frame 0x3C,
//   39/39 ordered calls, 97.29% exact-block coverage, and 44 edit cost.
//   Remaining drift starts in the inline attacking-array copy guard: VC5 emits
//   `test ebp/jle` for the current natural do/while shape while the oracle has
//   `cmp eax,ebp/jge`; the late suffix is otherwise an exact aligned island.
// - Pausing in scratch after the bounded 10 meaningful hypotheses; next lead
//   is a natural two-bound copy-loop spelling, not frame padding or volatility.
// - Replaced the grow-copy do/while with the same-TU matched ManagedArray
//   for-loop: a separate capacity guard and new-size guard reproduce the
//   binary's `cmp eax,ebp/jge` block and exact 949-byte function.
// - Exact candidate: frame, 39 ordered calls, CFG, boundary, and all 949 bytes
//   match under the existing /GX response file.

#include "../../include/aiuaimod_context.h"

extern float save_game_version;

void __cdecl rge_read(int fd, void* data, int size);

struct LoadNotifyEvent : NotifyEvent {
    char loadPayloadGap[0x10];
};

void UnitAIModule::load(int fd) {
    int numberNotifies;
    int i;
    int iVar5;
    int numberUnits;
    int tempInt_ffffffc0;
    int local_3c;
    int tempInt;
    int j;
    LoadNotifyEvent tempNotify;

    rge_read(fd, &moodValue, 4);
    rge_read(fd, &currentOrderValue, 4);
    rge_read(fd, &currentOrderPriorityValue, 4);
    rge_read(fd, &currentActionValue, 4);
    rge_read(fd, &currentTargetValue, 4);
    rge_read(fd, &currentTargetTypeValue, 4);
    rge_read(fd, &currentTargetXValue, 4);
    rge_read(fd, &currentTargetYValue, 4);
    rge_read(fd, &currentTargetZValue, 4);
    rge_read(fd, &desiredTargetDistanceValue, 4);
    rge_read(fd, &lastActionValue, 4);
    rge_read(fd, &lastOrderValue, 4);
    rge_read(fd, &lastTargetValue, 4);
    rge_read(fd, &lastTargetTypeValue, 4);
    rge_read(fd, &lastUpdateTimeValue, 4);
    rge_read(fd, &idleTimerValue, 4);
    rge_read(fd, &idleTimeoutValue, 4);
    rge_read(fd, &adjustedIdleTimeoutValue, 4);
    rge_read(fd, &secondaryTimerValue, 4);

    if (save_game_version >= 6.93f) {
        rge_read(fd, &lookAroundTimerValue, 4);
        rge_read(fd, &lookAroundTimeoutValue, 4);
    } else {
        lookAroundTimerValue = 0;
        lookAroundTimeoutValue = 1000;
    }

    rge_read(fd, &defendTargetValue, 4);
    rge_read(fd, &defenseBufferValue, 4);
    rge_read(fd, &lastWorldPositionX, 16);

    // Read order queue
    rge_read(fd, &numberNotifies, 4);
    iVar5 = 0;
    if (numberNotifies > 0) {
        do {
            rge_read(fd, &tempNotify.recipient, 0x24);
            addToOrderQueue((OrderEvent*)&tempNotify.recipient, 0);
            ++iVar5;
        } while (iVar5 < numberNotifies);
    }

    // Read notify queue
    rge_read(fd, &i, 4);
    iVar5 = 0;
    if (i > 0) {
        do {
            rge_read(fd, &tempNotify.recipient, 0x18);
            addToNotifyQueue((NotifyEvent*)&tempNotify.recipient);
            ++iVar5;
        } while (iVar5 < i);
    }

    // Read attacking units
    rge_read(fd, &tempInt_ffffffc0, 4);
    numberUnits = 0;
    if (tempInt_ffffffc0 > 0) {
        do {
            rge_read(fd, &local_3c, 4);
            tempInt = local_3c;
            for (j = 0; j < attackingUnitsValue.numberValue; j++) {
                if (j >= attackingUnitsValue.maximumSizeValue) break;
                if (attackingUnitsValue.value[j] == local_3c)
                    goto attacking_unit_already_present;
            }

            if (attackingUnitsValue.numberValue > attackingUnitsValue.maximumSizeValue - 1) {
                int newSize = attackingUnitsValue.numberValue + 1;
                int* newArr = (int*)::operator new(newSize * 4);
                if (newArr != 0) {
                    j = 0;
                    for (j = 0; j < attackingUnitsValue.maximumSizeValue; j++) {
                        if (j >= newSize) break;
                        newArr[j] = attackingUnitsValue.value[j];
                    }
                    ::operator delete(attackingUnitsValue.value);
                    attackingUnitsValue.value = newArr;
                    attackingUnitsValue.maximumSizeValue = newSize;
                }
            }
            attackingUnitsValue.value[attackingUnitsValue.numberValue] = tempInt;
            attackingUnitsValue.numberValue = attackingUnitsValue.numberValue + 1;

attacking_unit_already_present:
            numberUnits = numberUnits + 1;
        } while (numberUnits < tempInt_ffffffc0);
    }

    // Read playStatus
    rge_read(fd, &tempNotify, 4);
    if (tempNotify.caller == 1) {
        playStatus = new AIPlayStatus();
        playStatus->load(fd);
    }

    // stopAfterTargetKilled added in version 7.02
    if (save_game_version >= 7.02f) {
        rge_read(fd, &stopAfterTargetKilledValue, 1);
    }
}
