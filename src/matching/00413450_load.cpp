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

extern float save_game_version;

void __cdecl rge_read(int fd, void* data, int size);
void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

struct OrderEvent;

struct NotifyEvent {
    int caller;
    int recipient;
    int type;
    long p1;
    long p2;
    long p3;
    // The load path reads a 0x24-byte OrderEvent beginning at recipient;
    // the oracle's tempNotify stack window therefore spans the overlaid
    // payload through +0x27, not merely the six queue dwords.
    char loadPayloadGap[0x10];
};

struct AIPlayStatus {
    char data[0x1C8];
    AIPlayStatus();
    void load(int fd);
    void save(int fd);
};

class UnitAIModule {
public:
    void* objectValue;                          // +0x04
    int moodValue;                              // +0x08
    int objectCategoryValue;                    // +0x0C
    int orderQueueSizeValue;                    // +0x10
    int orderQueueMaxSizeValue;                 // +0x14
    void* orderQueueValue;                      // +0x18
    int notifyQueueSizeValue;                   // +0x1C
    int notifyQueueMaxSizeValue;                // +0x20
    void* notifyQueueValue;                     // +0x24
    int currentOrderValue;                      // +0x28
    int currentOrderPriorityValue;              // +0x2C
    int currentActionValue;                     // +0x30
    int currentTargetValue;                     // +0x34
    int currentTargetTypeValue;                 // +0x38
    float currentTargetXValue;                  // +0x3C
    float currentTargetYValue;                  // +0x40
    float currentTargetZValue;                  // +0x44
    float desiredTargetDistanceValue;           // +0x48
    int defendTargetValue;                      // +0x4C
    int lastOrderValue;                         // +0x50
    int lastActionValue;                        // +0x54
    int lastTargetValue;                        // +0x58
    int lastTargetTypeValue;                    // +0x5C
    int* attackingUnitsValue_value;             // +0x60
    int attackingUnitsValue_numberValue;        // +0x64
    int attackingUnitsValue_desiredNumberValue; // +0x68
    int attackingUnitsValue_maximumSizeValue;   // +0x6C
    char waypointGap[0x80];                     // +0x70 to +0xEF
    int waypointQueueSizeValue;                 // +0xF0
    unsigned long lastUpdateTimeValue;          // +0xF4
    unsigned long idleTimerValue;               // +0xF8
    unsigned long adjustedIdleTimeoutValue;     // +0xFC
    unsigned long idleTimeoutValue;             // +0x100
    unsigned long secondaryTimerValue;          // +0x104
    unsigned long lookAroundTimerValue;         // +0x108
    unsigned long lookAroundTimeoutValue;       // +0x10C
    char lastWorldPosition[0x10];               // +0x110
    float defenseBufferValue;                   // +0x120
    int* importantObjects;                      // +0x124
    int numberImportantObjects;                 // +0x128
    AIPlayStatus* playStatus;                   // +0x12C
    char stopAfterTargetKilledValue;            // +0x130

    void load(int fd);
    int addToOrderQueue(OrderEvent* event, int param);
    int addToNotifyQueue(NotifyEvent* event);
    virtual ~UnitAIModule();
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
    NotifyEvent tempNotify;

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
    rge_read(fd, &lastWorldPosition, 16);

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
            for (j = 0; j < attackingUnitsValue_numberValue; j++) {
                if (j >= attackingUnitsValue_maximumSizeValue) break;
                if (attackingUnitsValue_value[j] == local_3c)
                    goto attacking_unit_already_present;
            }

            if (attackingUnitsValue_numberValue > attackingUnitsValue_maximumSizeValue - 1) {
                int newSize = attackingUnitsValue_numberValue + 1;
                int* newArr = (int*)::operator new(newSize * 4);
                if (newArr != 0) {
                    j = 0;
                    for (j = 0; j < attackingUnitsValue_maximumSizeValue; j++) {
                        if (j >= newSize) break;
                        newArr[j] = attackingUnitsValue_value[j];
                    }
                    ::operator delete(attackingUnitsValue_value);
                    attackingUnitsValue_value = newArr;
                    attackingUnitsValue_maximumSizeValue = newSize;
                }
            }
            attackingUnitsValue_value[attackingUnitsValue_numberValue] = tempInt;
            attackingUnitsValue_numberValue = attackingUnitsValue_numberValue + 1;

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
