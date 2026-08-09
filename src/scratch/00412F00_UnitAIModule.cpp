// VA: 00412F00 UnitAIModule ctor (356B)
// aiuaimod.cpp
// EH frame (/GX)
//
// Attempt log:
// - Existing canonical typed field/allocation reconstruction has the exact
//   four-call set and correct 0x134 object layout, but the isolated TU emits
//   no original C++ EH registration and places the automatic vptr at entry.
// - Added a period-plausible derived UnitAIModule declaration under /GX; VC5
//   emitted identical code. The remaining gap is a real translation-unit /
//   constructor-context blocker: the oracle has push -1, FS chaining, a
//   phase local, delayed vptr store, and caller cleanup ret 8.
// - Retain the natural typed constructor rather than manual EH/vptr plumbing;
//   resume with the full aiuaimod.cpp class/constructor context.

class OrderEvent;
class NotifyEvent;
class AIPlayStatus;

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_category;                       // +0x14
    char gap_16[0x12];
    float defense_buffer;                        // +0x28
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;                                      // +0x04
    RGE_Master_Static_Object* master_obj;         // +0x08
};

void __cdecl setAdjustedIdleTimeout(void* this_);
void* __cdecl operator_new(unsigned int size);

class UnitAIModule {
public:
    RGE_Static_Object* objectValue;             // +0x04
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
    float lastWorldPositionX;                   // +0x110
    float lastWorldPositionY;                   // +0x114
    float lastWorldPositionZ;                   // +0x118
    char gap_11C[0x4];                          // +0x11C
    float defenseBufferValue;                   // +0x120
    int* importantObjects;                      // +0x124
    int numberImportantObjects;                 // +0x128
    AIPlayStatus* playStatus;                   // +0x12C
    char stopAfterTargetKilledValue;            // +0x130

    UnitAIModule(RGE_Static_Object* obj, int maxQueueSize);
    virtual ~UnitAIModule();
};

// The historical aiuaimod.cpp TU exposes derived UnitAIModule classes; this
// declaration is context only and emits no additional function body.
UnitAIModule::UnitAIModule(RGE_Static_Object* obj, int maxQueueSize) {
    objectValue = obj;
    moodValue = -1;
    objectCategoryValue = -1;
    orderQueueSizeValue = 0;
    orderQueueMaxSizeValue = maxQueueSize;
    notifyQueueSizeValue = 0;
    notifyQueueMaxSizeValue = maxQueueSize;
    currentOrderValue = -1;
    currentOrderPriorityValue = -1;
    currentActionValue = -1;
    currentTargetValue = -1;
    currentTargetTypeValue = -1;
    currentTargetXValue = -1.0f;
    currentTargetYValue = -1.0f;
    currentTargetZValue = -1.0f;
    desiredTargetDistanceValue = 2.0f;
    defendTargetValue = -1;
    lastOrderValue = -1;
    lastActionValue = -1;
    lastTargetValue = -1;
    lastTargetTypeValue = -1;

    attackingUnitsValue_value = 0;
    attackingUnitsValue_numberValue = 0;
    attackingUnitsValue_desiredNumberValue = 0;
    attackingUnitsValue_maximumSizeValue = 10;
    attackingUnitsValue_value = (int*)operator_new(0x28);

    waypointQueueSizeValue = 0;
    lastUpdateTimeValue = 0;
    idleTimerValue = 0;
    idleTimeoutValue = 3000;
    secondaryTimerValue = 0;
    lookAroundTimerValue = 0;
    lookAroundTimeoutValue = 1000;
    defenseBufferValue = 1.0f;
    importantObjects = 0;
    numberImportantObjects = 0;
    playStatus = 0;
    stopAfterTargetKilledValue = 0;

    if (obj != 0) {
        objectCategoryValue = obj->master_obj->object_category;
        defenseBufferValue = obj->master_obj->defense_buffer;
    }

    orderQueueValue = operator_new(orderQueueMaxSizeValue * 0x24);
    notifyQueueValue = operator_new(notifyQueueMaxSizeValue * 0x18);

    lastWorldPositionX = -1.0f;
    lastWorldPositionY = -1.0f;
    lastWorldPositionZ = -1.0f;

    setAdjustedIdleTimeout(this);
}
