// VA: 0040E2D0 AIModule::AIModule(int, int, int, int) (137 B)
// PDB source: aimodule.cpp lines 188-202
// Attempt log:
// - Moving the scalar stores into the initializer list moved the vptr store to
//   the proven late position. A body-assignment walkback returned a 32-byte TU diff.
// BINARY NOTE: The authentic constructor takes (char*, int, int, void*).

#include <string.h>

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
    AIModuleID idValue;               // +0x04
    int playerNumberValue;            // +0x4C
    char playerNameValue[0x40];       // +0x50
    int runningValue;                 // +0x90
    int pausedValue;                  // +0x94
    int logHistoryValue;              // +0x98
    int logCommonHistoryValue;        // +0x9C
    void* historyLogFile;             // +0xA0
    char historyLogFilename[0x40];    // +0xA4
    int intelligenceLevelValue;       // +0xE4
    int priorityValue;                // +0xE8
    int processFrameValue;            // +0xEC

    AIModule();
    AIModule(char* name, int id, int player, void* owner);
};
#endif

AIModule::AIModule(char* name, int id, int player, void* owner)
    : idValue(name, id),
      playerNumberValue(player),
      runningValue(0),
      pausedValue(0),
      logHistoryValue(0),
      logCommonHistoryValue(0),
      historyLogFile(0),
      intelligenceLevelValue(5),
      priorityValue(50),
      processFrameValue(0) {
    strcpy(playerNameValue, "");
}
