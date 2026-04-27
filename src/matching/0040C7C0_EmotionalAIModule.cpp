// 0040C7C0 EmotionalAIModule::EmotionalAIModule(void*, int)
// Source: aiemomod.cpp lines 23-33
// Size: 314 bytes, no EH
//
// Attempt log:
// Probe 1: base ctor + for loop + strcpy — 73.88% diff (no vtable write)
// Probe 2: virtual methods — layout shifted (vptr on derived but not on base)
// Probe 3: both AIModule + EmotionalAIModule have virtual methods, default flags

#include "..\..\include\game_globals.h"

char* __cdecl strcpy(char* dest, const char* src);
void* __cdecl memset(void* dest, int c, unsigned int count);

class AIModule {
public:
    // +0x00: vptr (4 bytes)
    // +0x04 to +0xEF: other AIModule fields = 0xEC bytes
    char gap_04[0xEC];

    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(class AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(class AIModuleMessage*);
    virtual int filterOutMessage(class AIModuleMessage*);

    AIModule(char* name, int size, int param2, void* param1);
};

class EmotionalAIModule : public AIModule {
public:
    int md;                   // +0xF0
    int stateValue[6];        // +0xF4
    char stateNameValue[6][30]; // +0x10C

    // Additional virtual: save(int) at vt[15]
    virtual int save(int);

    EmotionalAIModule(void* param1, int param2);
    EmotionalAIModule(int param1, int param2);
    void setOverallState(int state);
};

EmotionalAIModule::EmotionalAIModule(void* param1, int param2)
    : AIModule("Emotional AI", 0x3EC, param2, param1)
    , md(0)
{
    for (int i = 0; i < 6; i++) stateValue[i] = 49;
    strcpy(stateNameValue[0], "Aggressive");
    strcpy(stateNameValue[1], "Compassionate");
    strcpy(stateNameValue[2], "Defensive");
    strcpy(stateNameValue[3], "Friendly");
    strcpy(stateNameValue[4], "Passive");
    strcpy(stateNameValue[5], "Vengeful");
}
