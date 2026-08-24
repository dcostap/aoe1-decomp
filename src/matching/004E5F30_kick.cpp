// VA: 004E5F30 TribeMainDecisionAIModule::kick (100 B)
// PDB source: taimdmd.cpp lines 821-832

#ifndef AOE1_TAIMDMD_CONTEXT_H
void logCommonHistory(char* this_as_str, const char* format, ...);

class BuildAIModule {
public:
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
};

class TribeBuildAIModule : public BuildAIModule {
public:
    void skipNextBuildListItem();
    int insert(int a, int b, int c);
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0x104];
    TribeBuildAIModule buildAI;

    void kick(int param_1);
};
#endif

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
        this->buildAI.displayBuildList();
    }
}
