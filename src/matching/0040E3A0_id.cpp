// VA: 0040E3A0 id (46B, aimodule.cpp)
// AIModule::id - returns struct by value. VC5 NRVO writes to hidden output ptr.
#include <string.h>

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
    virtual ~AIModuleID();
    int id;
    int data[0x10];
};

class AIModule {
public:
    virtual ~AIModule();
    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;

    AIModuleID id() const;
};
#endif

AIModuleID AIModule::id() const {
    return this->idValue;
}
