// VA: 0040E220 AIModule::AIModule (default ctor)
// aimodule.cpp lines 161-165
//
// Attempt log:
// - Prior scratch only initialized scalar fields and compiled to 64 bytes, missing the original inline string copy.
// - Use the real layout through processFrameValue and the natural string copy.
//   The authentic TU context supplies the virtual class surface.

extern "C" char* strcpy(char* dst, const char* src);

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    virtual ~AIModuleID();
    AIModuleID(char* str, int param);
    char gap_00[0x48];
};

class AIModule {
public:
    virtual ~AIModule();
    AIModuleID id;              // +0x04
    int playerNumberValue;      // +0x4C
    char playerNameValue[64];   // +0x50
    int runningValue;           // +0x90
    int pausedValue;            // +0x94
    int logHistoryValue;        // +0x98
    int logCommonHistoryValue;  // +0x9C
    void* historyLogFile;       // +0xA0
    char historyLogFilename[64];// +0xA4
    int intelligenceLevelValue; // +0xE4
    int priorityValue;          // +0xE8
    int processFrameValue;      // +0xEC

    AIModule();
};
#endif

AIModule::AIModule() : idValue((char*)0x592A40, -1) {
    this->playerNumberValue = -1;
    this->runningValue = 0;
    this->pausedValue = 0;
    this->logHistoryValue = 0;
    this->logCommonHistoryValue = 0;
    this->historyLogFile = 0;
    this->intelligenceLevelValue = 5;
    this->priorityValue = 50;
    this->processFrameValue = 0;
    strcpy(this->playerNameValue, (const char*)0x57F074);
}
