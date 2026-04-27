// VA: 0040E830 AIModule::logCommonHistory
// aimodule.cpp lines 964-985

// attempt 1: formatted log output with conditional checks
// 165 bytes

#include <stdio.h>
#include <malloc.h>

class AIModuleID {
public:
    AIModuleID(char* str, int param);
    char gap_00[0x48];
};

class AIModule {
public:
    char vtable[4];
    AIModuleID id;
    int field_4C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_E4;
    int field_E8;
    int field_EC;

    AIModule();
    AIModule(int a, int b);
    void setLogCommonHistory(void* log_obj);
    void logCommonHistory(int param);
};

int g_someId = -1;       // at 57F9FCh
int g_logActive = 0;     // at 592A44h

void AIModule::logCommonHistory(int param) {
    if (g_someId != -1 && g_someId != field_4C) {
        return;
    }
    
    if (g_logActive == 0) return;
    
    char* buf = (char*)_alloca(0x400);
    sprintf(buf, "%s%d%s%d", "", param, "", field_4C);
}
