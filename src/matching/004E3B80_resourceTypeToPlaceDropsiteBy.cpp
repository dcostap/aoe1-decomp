// 004E3B80 TribeInformationAIModule::resourceTypeToPlaceDropsiteBy (taiinfmd.cpp:7981-8013, 260B)
// Determines which resource type needs a dropsite placed for it.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct TribeTacticalAIModule {
    char gap_00[0x194];
    int strategicNumbers[226];
    int strategicNumber(int index);
};

#endif
struct BuildAIModule {
    virtual ~BuildAIModule();
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
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    virtual int save(int);
    virtual void displayBuildList();
    virtual int loadBuildList(char*, RGE_Player*);
    virtual int numberBuiltOrInProgressItemsOfType(int a, int b);
    char gap_04[0x5BC - 4];
};

struct TribeBuildAIModule : BuildAIModule {
    void* md;
};

struct TribeMainDecisionAIModule {
    char gap_00[0x104];
    TribeBuildAIModule buildAI;
    char gap_6C4[0x1146C - 0x6C4];
    TribeTacticalAIModule tacticalAI;
};

struct InformationAIModule {
    char gap_00[0xF0];
};

#ifndef TAIINFMD_PREFIX_CONTEXT
struct TribeInformationAIModule : InformationAIModule {
    char gap_F0[0x10];
    /* +0x100 */ TribeMainDecisionAIModule* md;
    char gap_104[0x540 - 0x104];
    /* +0x540 */ int closestDropsiteValue[4];

    int resourceTypeToPlaceDropsiteBy(int param_1);
};
#endif

#endif
int TribeInformationAIModule::resourceTypeToPlaceDropsiteBy(int param_1) {
    if (param_1 == 2) return 0;

    if (!md->buildAI.numberBuiltOrInProgressItemsOfType(0x67, 0)
        && closestDropsiteValue[1] != -1)
        return 1;

    if (param_1 == 1) {
        if (closestDropsiteValue[1] != -1) {
            int n = md->tacticalAI.strategicNumber(0xA4);
            if (closestDropsiteValue[1] > n)
                return 1;
        }
        if (closestDropsiteValue[3] != -1) {
            int n = md->tacticalAI.strategicNumber(0xA6);
            if (closestDropsiteValue[3] > n)
                return 3;
        }
        if (closestDropsiteValue[0] != -1 && closestDropsiteValue[0] > 15) return 2;
        if (closestDropsiteValue[2] != -1) {
            int n = md->tacticalAI.strategicNumber(0xA5);
            if (closestDropsiteValue[2] > n)
                return 2;
        }
        return -1;
    }
    return -1;
}
