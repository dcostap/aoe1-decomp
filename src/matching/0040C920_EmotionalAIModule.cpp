// 0040C920 EmotionalAIModule::EmotionalAIModule(int, int)
// Source: aiemomod.cpp lines 40-50
// Size: 367 bytes, EH prolog (needs /GX)
//
// Attempt log:
// Probe 1: /GX + rge_read loop + strcpy 6 strings, /GX flag

#include "..\..\include\game_globals.h"

char* __cdecl strcpy(char* dest, const char* src);

void __cdecl rge_read(int handle, void* buf, int size);

class AIModule {
public:
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

    virtual int save(int);

    EmotionalAIModule(void* param1, int param2);
    EmotionalAIModule(int param1, int param2);
    void setOverallState(int state);
};

EmotionalAIModule::EmotionalAIModule(int param1, int param2)
    : AIModule("Emotional AI", 0x3EC, param1, 0)
    , md(0)
{
    int* ptr = stateValue;
    int count = 6;
    do {
        rge_read(param2, ptr, 4);
        ptr++;
        count--;
    } while (count != 0);

    strcpy(stateNameValue[0], "Aggressive");
    strcpy(stateNameValue[1], "Compassionate");
    strcpy(stateNameValue[2], "Defensive");
    strcpy(stateNameValue[3], "Friendly");
    strcpy(stateNameValue[4], "Passive");
    strcpy(stateNameValue[5], "Vengeful");
}
