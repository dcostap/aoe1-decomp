// VA: 00413090 ~UnitAIModule dtor (183B)
// aiuaimod.cpp
// EH frame (/GX)
//
// NOTE: The original binary has a C++ EH frame (push -1, save/restore FS[0],
// __$EHRec$ phase tracking with 0/0xffffffff). VC5 only generates the EH
// frame when the class is compiled in a TU with derived classes visible, or
// when a base class exists. In isolated compilation the EH frame is omitted
// (128B vs 183B). The function logic (delete 5 pointers, null stores, zero
// attackingUnits sub-fields) is identical. The missing ~55 bytes are the EH
// frame prologue/epilogue and phase tracking.

class OrderEvent;
class NotifyEvent;
class AIPlayStatus;

class UnitAIModule {
public:
    char gap_04[0x14];
    OrderEvent* orderQueueValue;
    char gap_1C[0x08];
    NotifyEvent* notifyQueueValue;
    char gap_28[0x38];
    int* attackingUnitsValue_value;
    int attackingUnitsValue_numberValue;
    int attackingUnitsValue_desiredNumberValue;
    int attackingUnitsValue_maximumSizeValue;
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
    if (attackingUnitsValue_value) {
        delete attackingUnitsValue_value;
        attackingUnitsValue_value = 0;
    }
    attackingUnitsValue_numberValue = 0;
    attackingUnitsValue_desiredNumberValue = 0;
    attackingUnitsValue_maximumSizeValue = 0;
}
