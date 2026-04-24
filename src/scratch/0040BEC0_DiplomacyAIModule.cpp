// attempt 1: int likeTable[21]; 80 bytes, 6 short (missing explicit vtable store)
// attempt 2: short likeTable[21]; 86 bytes but wrong offsets (likeTable at +0xF4 vs +0x11C)
// attempt 3: fixed param order (param2,param1); still 80 bytes
// attempt 4: /O1 and /GX; still 80 bytes
// Left in scratch: 80 vs 86; VC5 doesn't emit explicit vtable ptr store (mov [esi], 0x56E818 = 6 bytes)
// Constructor: calls AIModule base ctor, sets md=0, loop initializes likeTable with 0x31, changeableTable with 1

class MainDecisionAIModule;

class AIModule {
public:
    AIModule(const char* name, unsigned long help_id, void* param1, int param2);
};

class DiplomacyAIModule : public AIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;
    int likeTable[21];
    unsigned char changeableTable[10];

    DiplomacyAIModule(void* param1, int param2);
};

DiplomacyAIModule::DiplomacyAIModule(void* param1, int param2)
    : AIModule("Diplomacy AI", 0x3EB, (void*)param2, (int)param1) {
    md = 0;
    int eax = 0;
    int* ecx = likeTable;
    int edi = 0x31;
    do {
        ecx[-10] = edi;
        *ecx = edi;
        changeableTable[eax] = 1;
        eax++;
        ecx++;
    } while (eax < 10);
}
