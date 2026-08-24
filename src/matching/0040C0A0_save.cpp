// 0040C0A0 save: straight 10-iteration write loop over likeTable/changeableTable.
// No better lead yet; keep the source shape close to the PDB line map.

extern "C" int __cdecl rge_write(int handle, void* buffer, int count);

class MainDecisionAIModule;

#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;
    int dislikeTable[10];
    int likeTable[10];
    unsigned char changeableTable[10];

    virtual ~DiplomacyAIModule();
    virtual int save(int param_1);
};
#endif

int DiplomacyAIModule::save(int param_1) {
    unsigned char* changeableTable = this->changeableTable;
    int* likeTable = this->likeTable;
    int count = 10;

    do {
        rge_write(param_1, likeTable - 10, 4);
        rge_write(param_1, likeTable, 4);
        rge_write(param_1, changeableTable, 1);
        ++likeTable;
        ++changeableTable;
    } while (--count != 0);

    return 1;
}
