// VA: 0040E2D0 AIModule::AIModule(int, int, int, int) (137 B)
// PDB source: aimodule.cpp lines 188-202
// Attempt log: see bottom

#include <string.h>

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
    virtual ~AIModuleID();
    char gap_00[0x48];
    AIModuleID(int a, char* str);
};

struct AIModule {
    virtual ~AIModule();
    AIModuleID id;          // +0x04, sizeof 0x48 → ends at +0x4C
    int field_4C;           // +0x4C
    char name[0x40];        // +0x50, string buffer
    int field_90;           // +0x90
    int field_94;           // +0x94
    int field_98;           // +0x98
    int field_9C;           // +0x9C
    int field_A0;           // +0xA0
    char gap_A4_to_E4[0x40]; // +0xA4 to +0xE3
    int field_E4;           // +0xE4
    int field_E8;           // +0xE8
    int field_EC;           // +0xEC

    AIModule();
    AIModule(int a, int b, int c, int d);
};
#endif

#ifdef AOE1_AIMODULE_TU_CONTEXT
AIModule::AIModule(char* name, int id, int player, void* owner)
    : idValue(name, id) {
#else
AIModule::AIModule(int a, int b, int c, int d) : id(a, (char*)b) {
#endif
#ifdef AOE1_AIMODULE_TU_CONTEXT
    playerNumberValue = player;
    runningValue = 0;
    pausedValue = 0;
    logHistoryValue = 0;
    logCommonHistoryValue = 0;
    historyLogFile = 0;
    intelligenceLevelValue = 5;
    priorityValue = 50;
    processFrameValue = 0;
#else
    field_4C = c;
    field_90 = 0;
    field_94 = 0;
    field_98 = 0;
    field_9C = 0;
    field_A0 = 0;
    field_E4 = 5;
    field_E8 = 50;
    field_EC = 0;
#endif
#ifndef AOE1_AIMODULE_TU_CONTEXT
    strcpy(name, "");
#else
    strcpy(playerNameValue, "");
#endif
}
