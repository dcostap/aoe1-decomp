// VA: 0040E220 AIModule::AIModule (default ctor)
// aimodule.cpp lines 161-165
//
// Attempt log:
// - Prior scratch only initialized scalar fields and compiled to 64 bytes, missing the original inline string copy.
// - SpruceGlow MATCH: use the real layout through processFrameValue, set the vptr manually after scalar fields, and
//   call natural `strcpy(playerNameValue, "Unknown")`. VC5 inlines strcpy into the original REP string copy sequence.
// Result: MATCH locally with `python tools/check_function.py --va 0040E220`.

extern "C" char* strcpy(char* dst, const char* src);

class AIModuleID {
public:
    AIModuleID(char* str, int param);
    char gap_00[0x48];
};

class AIModule {
public:
    char vtable[4];             // +0x00
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

AIModule::AIModule() : id((char*)0x592A40, -1) {
    this->playerNumberValue = -1;
    this->runningValue = 0;
    this->pausedValue = 0;
    this->logHistoryValue = 0;
    this->logCommonHistoryValue = 0;
    this->historyLogFile = 0;
    this->intelligenceLevelValue = 5;
    this->priorityValue = 50;
    this->processFrameValue = 0;
    *(int*)this = 0x56E930;
    strcpy(this->playerNameValue, (const char*)0x57F074);
}
