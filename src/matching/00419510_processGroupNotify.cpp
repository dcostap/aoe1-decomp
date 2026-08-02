// VA: 00419510 UnitAIModule::processGroupNotify
// aiuaimod.cpp lines 5191-5250
// Attempt log:
// - Reconstructed the play-status/playbook/phase/trigger ownership from the original
//   offsets and direct-call set; replacing the stale unrelated placeholder.
// - Hoisted the natural play/phase locals and used the packet's do-while trigger scan;
//   those spellings alone stayed in the same 199-byte basin.
// - Materializing trigger->value1Value before the AIPlayStatus::group call preserved
//   its live EDI compare value, triggered the original delayed callee-save layout,
//   and produced an exact 209-byte match under the default flags.

struct NotifyEvent {
    int caller;                    // +0x00
    int recipient;                 // +0x04
    int mType;                     // +0x08
    int data1;                     // +0x0C
};

class AIPlayPhaseTrigger {
public:
    unsigned char typeValue;       // +0x00
    char gap_01[3];
    int value1Value;               // +0x04
    int value2Value;               // +0x08
    unsigned char phaseValue;      // +0x0C
    unsigned char nextPhaseValue;  // +0x0D
    char gap_0E[2];
    int randomnessValue;           // +0x10
};

class AIPlayPhase {
public:
    char gap_00[0x50];
    AIPlayPhaseTrigger triggers[3];

    AIPlayPhaseTrigger* trigger(int index);
};

class AIPlay {
public:
    AIPlayPhase* phase(int index);
};

class AIPlayBook {
public:
    AIPlay* play(int index);
};

class AIPlayStatus {
public:
    char gap_00[0x190];
    int playNumberValue;              // +0x190
    char gap_194[0x24];
    unsigned char currentPhaseValue; // +0x1B8
    char gap_1B9[3];
    int savedAttackerValue;           // +0x1BC

    unsigned char group(int id);
};

class AIPlayBookOwnerWorld {
public:
    char gap_00[0xA0];
    AIPlayBook* playbook;             // +0xA0
};

class AIPlayBookOwner {
public:
    char gap_00[0x3C];
    AIPlayBookOwnerWorld* world;      // +0x3C
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    AIPlayBookOwner* owner;            // +0x0C
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void processGroupNotify(NotifyEvent* param_1);

    RGE_Static_Object* objectValue;    // +0x04
    int moodValue;                      // +0x08
    int objectCategoryValue;            // +0x0C
    int orderQueueSizeValue;            // +0x10
    int orderQueueMaxSizeValue;         // +0x14
    void* orderQueueValue;              // +0x18
    int notifyQueueSizeValue;            // +0x1C
    int notifyQueueMaxSizeValue;         // +0x20
    void* notifyQueueValue;              // +0x24
    int currentOrderValue;              // +0x28
    int currentOrderPriorityValue;       // +0x2C
    int currentActionValue;              // +0x30
    int currentTargetValue;              // +0x34
    int currentTargetTypeValue;          // +0x38
    float currentTargetXValue;            // +0x3C
    float currentTargetYValue;            // +0x40
    float currentTargetZValue;            // +0x44
    float desiredTargetDistanceValue;     // +0x48
    int defendTargetValue;               // +0x4C
    int lastOrderValue;                  // +0x50
    int lastActionValue;                 // +0x54
    int lastTargetValue;                 // +0x58
    int lastTargetTypeValue;             // +0x5C
    int* attackingUnitsValue;            // +0x60
    int attackingUnitsNumberValue;       // +0x64
    int attackingUnitsDesiredValue;      // +0x68
    int attackingUnitsMaximumValue;      // +0x6C
    char waypointGap[0x80];              // +0x70
    int waypointQueueSizeValue;          // +0xF0
    unsigned long lastUpdateTimeValue;   // +0xF4
    unsigned long idleTimerValue;        // +0xF8
    unsigned long adjustedIdleTimeoutValue; // +0xFC
    unsigned long idleTimeoutValue;      // +0x100
    unsigned long secondaryTimerValue;   // +0x104
    unsigned long lookAroundTimerValue;  // +0x108
    unsigned long lookAroundTimeoutValue;// +0x10C
    float lastWorldPositionX;            // +0x110
    float lastWorldPositionY;            // +0x114
    float lastWorldPositionZ;            // +0x118
    char gap_11C[4];                     // +0x11C
    float defenseBufferValue;            // +0x120
    int* importantObjects;               // +0x124
    int numberImportantObjects;          // +0x128
    AIPlayStatus* playStatus;          // +0x12C

    int selectNewPlayPhase(int phase, int param_2);
};

void UnitAIModule::processGroupNotify(NotifyEvent* param_1)
{
    AIPlay* play;
    AIPlayPhase* phase;

    if (this->playStatus != 0 &&
        (play = this->objectValue->owner->world->playbook->play(
            this->playStatus->playNumberValue)) != 0 &&
        (phase = play->phase(this->playStatus->currentPhaseValue)) != 0 &&
        param_1->mType == 500) {
        this->playStatus->savedAttackerValue = param_1->caller;
        int i = 0;
        do {
            AIPlayPhaseTrigger* trigger = phase->trigger(i);
            if (trigger != 0 && trigger->typeValue != 0) {
                if (trigger->typeValue == 5) {
                    this->selectNewPlayPhase(trigger->nextPhaseValue, 0);
                } else if (trigger->typeValue == 4) {
                    int value1 = trigger->value1Value;
                    if (value1 == this->playStatus->group(param_1->recipient)) {
                        this->selectNewPlayPhase(trigger->nextPhaseValue, 0);
                    }
                }
            }
            ++i;
        } while (i < 3);
    }
}
