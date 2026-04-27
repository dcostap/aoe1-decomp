// VA: 0040E520 AIModule::setLogCommonHistory
// aimodule.cpp lines 365-379

// attempt 1: sets log param, opens/closes log file
// 149 bytes

#include <stdio.h>

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
};

int g_logActive = 0;
void* g_logFile = 0;
static void* g_fopenPath1 = (void*)0x57F4EC;
static void* g_fopenPath2 = (void*)0x57F4DC;

void AIModule::setLogCommonHistory(void* log_obj) {
    field_9C = (int)log_obj;
    
    if (log_obj != 0 && g_logActive == 0) {
        FILE* f = fopen("CommonHistory.log", "wt");  // approximate strings
        if (f != 0) {
            setvbuf(f, 0, 2, 0);
            g_logFile = f;
            g_logActive = 1;
        }
    } else if (log_obj == 0 && g_logActive != 0) {
        if (g_logFile != 0) {
            fclose((FILE*)g_logFile);
        }
        g_logFile = 0;
        g_logActive = 0;
    }
}
