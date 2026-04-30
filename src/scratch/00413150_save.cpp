// VA: 00413150 save (758B)
// aiuaimod.cpp

class OrderEvent;
class NotifyEvent;

struct AIPlayStatus {
    void save(int fd);
};

void __cdecl rge_write(int fd, const void* data, int size);

class UnitAIModule {
public:
    // +0x00: vfptr (implicit, compiler-generated)
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

    void save(int fd);
    virtual ~UnitAIModule();
};

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
    rge_write(fd, &lastWorldPosition, 16);

    rge_write(fd, &orderQueueSizeValue, 4);
    for (i = 0; i < orderQueueSizeValue; i++) {
        rge_write(fd, (char*)orderQueueValue + i * 0x24, 0x24);
    }

    rge_write(fd, &notifyQueueSizeValue, 4);
    for (i = 0; i < notifyQueueSizeValue; i++) {
        rge_write(fd, (char*)notifyQueueValue + i * 0x18, 0x18);
    }

    temp = attackingUnitsValue_numberValue;
    rge_write(fd, &temp, 4);
    {
        int i_attack;
        for (i_attack = 0; i_attack < attackingUnitsValue_numberValue; i_attack++) {
            if (attackingUnitsValue_maximumSizeValue - 1 < i_attack) {
                int* newArr = (int*)::operator new(i_attack * 4 + 4);
                if (newArr) {
                    int j;
                    for (j = 0; j < attackingUnitsValue_maximumSizeValue; j++) {
                        if (i_attack + 1 <= j) break;
                        newArr[j] = attackingUnitsValue_value[j];
                    }
                    ::operator delete(attackingUnitsValue_value);
                    attackingUnitsValue_value = newArr;
                    attackingUnitsValue_maximumSizeValue = i_attack + 1;
                }
            }
            temp = attackingUnitsValue_value[i_attack];
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
