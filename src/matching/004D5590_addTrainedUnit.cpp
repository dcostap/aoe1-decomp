// first pass: direct build-list lookup, status helper calls, then the AI cleanup/update tail
// if this is sticky, the remaining gap is probably just the exact member-call order around the md/tacticalAI tail
class BuildItem {
public:
    virtual ~BuildItem();
    void setInProgress(int);
    void setBuilt(int);
    void setGameID(int);
    void incrementNumberBuilds(void);
};

class BuildAIModule {
public:
    BuildItem* specificBuildListItem(int);
};

class TribeTacticalAIModule {
public:
    char pad_00[0x100C];
    void updateNeededResources(void);
};

class TribeMainDecisionAIModule {
public:
    char pad_00[0x1146C];
    TribeTacticalAIModule tacticalAI;

    void detask(int);
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char pad_00[0x5BC];
    TribeMainDecisionAIModule* md;

    int addTrainedUnit(int param_1, int param_2, int param_3, int param_4);
};

int TribeBuildAIModule::addTrainedUnit(int param_1, int param_2, int param_3, int param_4) {
    BuildItem* item;

    item = this->specificBuildListItem(param_3);
    if (item != 0) {
        item->setInProgress(0);
        item->setBuilt(1);
        item->setGameID(param_4);
        item->incrementNumberBuilds();
    }
    this->md->detask(param_2);
    this->md->tacticalAI.updateNeededResources();
    return 1;
}
