// VA: 0040E220 AIModule::AIModule (default ctor)
// aimodule.cpp lines 161-165
//
// Attempt log:
// - Prior scratch only initialized scalar fields and compiled to 64 bytes, missing the original inline string copy.
// - Use the real layout through processFrameValue and the natural string copy.
//   The authentic TU context supplies the virtual class surface.
// - Moving the scalar stores into the initializer list moved the vptr store to
//   the proven late position. A body-assignment walkback returned a 35-byte TU diff.
// BINARY NOTE: The fallback AIModuleID gap is 0x44 so the complete member is 0x48 bytes.

extern "C" char* strcpy(char* dst, const char* src);

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    virtual ~AIModuleID();
    AIModuleID(char* str, int param);
    char gap_00[0x44];
};

class AIModule {
public:
    virtual ~AIModule();
    AIModuleID idValue;         // +0x04
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

AIModule::AIModule()
    : idValue((char*)0x592A40, -1),
      playerNumberValue(-1),
      runningValue(0),
      pausedValue(0),
      logHistoryValue(0),
      logCommonHistoryValue(0),
      historyLogFile(0),
      intelligenceLevelValue(5),
      priorityValue(50),
      processFrameValue(0) {
    strcpy(this->playerNameValue, (const char*)0x57F074);
}
