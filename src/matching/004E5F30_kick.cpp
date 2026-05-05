// VA: 004E5F30 TribeMainDecisionAIModule::kick (100 B)
// PDB source: taimdmd.cpp lines 821-832

void logCommonHistory(char* this_as_str, const char* format, ...);

class TribeBuildAIModuleBase {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
};

class TribeBuildAIModule : public TribeBuildAIModuleBase {
public:
    void skipNextBuildListItem();
    int insert(int a, int b, int c);
    virtual void vf40();
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0x104];
    TribeBuildAIModule buildAI;

    void kick(int param_1);
};

void TribeMainDecisionAIModule::kick(int param_1)
{
    logCommonHistory((char*)this, "Got a kick=%d.", param_1);
    if (param_1 == 1) {
        this->buildAI.skipNextBuildListItem();
    }
    if (param_1 == 2) {
        this->buildAI.insert(0x53, 1, -1);
    }
    if (param_1 == 3) {
        logCommonHistory((char*)this, "Current Build list is:");
        this->buildAI.vf40();
    }
}
