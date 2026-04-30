// VA: 00413450 load (949B)
// aiuaimod.cpp
// EH frame (/GX) — same as ctor/dtor: VC5 only generates with full TU context
// Also has AIPlayStatus new/construct/load and dual version checks (6.93, 7.02)
// These require full TU context to match exactly.

extern float save_game_version;

void __cdecl rge_read(int fd, void* data, int size);
void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

struct AIPlayStatus {
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
    int addToOrderQueue(void* event, int param);
    int addToNotifyQueue(void* event);
    virtual ~UnitAIModule();
};

void UnitAIModule::load(int fd) {
    int i;
    int j;
    int temp;
    int tempVal;
    char tempEvent[0x24];

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

    if (save_game_version < 6.93f) {
        lookAroundTimerValue = 0;
        lookAroundTimeoutValue = 1000;
    } else {
        rge_read(fd, &lookAroundTimerValue, 4);
        rge_read(fd, &lookAroundTimeoutValue, 4);
    }

    rge_read(fd, &defendTargetValue, 4);
    rge_read(fd, &defenseBufferValue, 4);
    rge_read(fd, &lastWorldPosition, 16);

    // Read order queue
    rge_read(fd, &temp, 4);
    for (i = 0; i < temp; i++) {
        rge_read(fd, tempEvent, 0x24);
        addToOrderQueue(tempEvent, 0);
    }

    // Read notify queue
    rge_read(fd, &temp, 4);
    for (i = 0; i < temp; i++) {
        rge_read(fd, tempEvent, 0x18);
        addToNotifyQueue(tempEvent);
    }

    // Read attacking units
    rge_read(fd, &temp, 4);
    for (i = 0; i < temp; i++) {
        rge_read(fd, &tempVal, 4);
        {
            int found = 0;
            for (j = 0; j < attackingUnitsValue_numberValue; j++) {
                if (j >= attackingUnitsValue_maximumSizeValue) break;
                if (attackingUnitsValue_value[j] == tempVal) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                if (attackingUnitsValue_numberValue > attackingUnitsValue_maximumSizeValue - 1) {
                    int* newArr = (int*)::operator new((attackingUnitsValue_numberValue + 1) * 4);
                    if (newArr) {
                        for (j = 0; j < attackingUnitsValue_maximumSizeValue; j++) {
                            newArr[j] = attackingUnitsValue_value[j];
                        }
                        ::operator delete(attackingUnitsValue_value);
                        attackingUnitsValue_value = newArr;
                        attackingUnitsValue_maximumSizeValue = attackingUnitsValue_numberValue + 1;
                    }
                }
                attackingUnitsValue_value[attackingUnitsValue_numberValue] = tempVal;
                attackingUnitsValue_numberValue++;
            }
        }
    }

    // Read playStatus
    rge_read(fd, &temp, 4);
    if (temp == 1) {
        playStatus = (AIPlayStatus*)::operator new(0x1c8);
        if (playStatus != 0) {
            playStatus->load(fd);
        }
    }

    // stopAfterTargetKilled added in version 7.02
    if (save_game_version >= 7.02f) {
        rge_read(fd, (char*)this + 0x130, 1);
    }
}
