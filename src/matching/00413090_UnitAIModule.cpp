// VA: 00413090 ~UnitAIModule dtor (183B)
// aiuaimod.cpp
// EH frame (/GX)

class OrderEvent;
class NotifyEvent;
class AIPlayStatus;

class ManagedIntArray {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ~ManagedIntArray() {
        if (value) {
            delete value;
            value = 0;
        }
        numberValue = 0;
        desiredNumberValue = 0;
        maximumSizeValue = 0;
    }
};

class UnitAIModule {
public:
    char gap_04[0x14];
    OrderEvent* orderQueueValue;
    char gap_1C[0x08];
    NotifyEvent* notifyQueueValue;
    char gap_28[0x38];
    ManagedIntArray attackingUnitsValue;
    char gap_70[0xB4];
    int* importantObjects;
    int numberImportantObjects;
    AIPlayStatus* playStatus;
    char stopAfterTargetKilled;

    virtual ~UnitAIModule();
};

UnitAIModule::~UnitAIModule() {
    if (orderQueueValue) {
        delete orderQueueValue;
        orderQueueValue = 0;
    }
    if (notifyQueueValue) {
        delete notifyQueueValue;
        notifyQueueValue = 0;
    }
    if (importantObjects) {
        delete importantObjects;
        importantObjects = 0;
    }
    if (playStatus) {
        delete playStatus;
        playStatus = 0;
    }
}
