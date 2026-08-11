// VA: 00412F00 UnitAIModule ctor (356B)
// aiuaimod.cpp
// EH frame (/GX)
//
// Attempt log:
// - The first isolated typed candidate had the right four calls and layout but
//   no EH frame. Correcting setAdjustedIdleTimeout to its proven thiscall
//   member ABI removed the spurious caller push/cleanup.
// - Modeling the proven ManagedArray<int> member with its inline scalar-delete
//   destructor restored the original EH frame, 356-byte size, phase local,
//   delayed vptr position, call-site cleanup, and exact 34-instruction tail.
// - The current natural source uses the binary-proven novtable/delayed-vptr
//   surface and the real standard operator new/member-call ABIs. Current
//   best: 356/356 bytes, 4/4 ordered calls, 92.71% shape, 121 positional
//   differing bytes; the tail from +0xF4 through +0x164 is exact.
// - Tried natural compiler-owned vptr, a declaration-only member destructor,
//   a local allocation result, register-qualified obj, and the template
//   spelling; none changed the remaining hunk. Original pushes EDI and loads
//   obj before MOV ESI,this, saves this only before the first allocation, and
//   keeps push 0x28 after the +0x38..+0x5C stores. VC5 currently moves MOV
//   ESI,this/EH-local save ahead of PUSH EDI and hoists that argument push.
// - Pausing with the best source: remaining evidence points to the original
//   aiuaimod.cpp ManagedArray/TU lifetime scheduling rather than an unresolved
//   field ownership or call ABI. No inline asm or compiler-only filler used.

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

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ~ManagedArray() {
        if (value) {
            delete value;
            value = 0;
        }
        numberValue = 0;
        desiredNumberValue = 0;
        maximumSizeValue = 0;
    }
};

void* __cdecl operator new(unsigned int size);

class __declspec(novtable) UnitAIModule {
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
    ManagedArray<int> attackingUnitsValue;      // +0x60
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

    void setAdjustedIdleTimeout();
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

    attackingUnitsValue.value = 0;
    attackingUnitsValue.numberValue = 0;
    attackingUnitsValue.desiredNumberValue = 0;
    attackingUnitsValue.maximumSizeValue = 10;
    attackingUnitsValue.value = (int*)operator new(0x28);

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

    *(void**)this = (void*)0x56EAD8;

    if (obj != 0) {
        objectCategoryValue = obj->master_obj->object_category;
        defenseBufferValue = obj->master_obj->defense_buffer;
    }

    orderQueueValue = operator new(orderQueueMaxSizeValue * 0x24);
    notifyQueueValue = operator new(notifyQueueMaxSizeValue * 0x18);

    lastWorldPositionX = -1.0f;
    lastWorldPositionY = -1.0f;
    lastWorldPositionZ = -1.0f;

    setAdjustedIdleTimeout();
}
