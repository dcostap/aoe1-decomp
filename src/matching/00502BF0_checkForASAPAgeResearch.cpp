#ifndef TAITACMD_SHARED_CONTEXT
// VA: 00502BF0 TribeTacticalAIModule::checkForASAPAgeResearch (347 B)
// PDB source: taitacmd.cpp
// __thiscall, void
//
// Attempt log:
// - Replaced the parked raw-offset/free-helper scaffold with the period-shaped
//   three-age research checks.  The build, resource, and tactical modules are
//   named typed members; the first two research arms intentionally keep their
//   branch-local taskResearch calls, as shown by the distinct call sites and
//   PDB line bands.

#ifndef TAITACMD_SHARED_CONTEXT
class BuildItem;
class TribeMainDecisionAIModule;

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class TribeBuildAIModule : public AIModule {
public:
    char gap_F0[0x5BC - 0xF0];
    void* md;

    int readyToResearch(int age, int mode);
    BuildItem* buildItem(int type, int category1, int category2);
};

class TribeResourceAIModule : public AIModule {
public:
    TribeMainDecisionAIModule* md;
    int numberResourcesValue;

    int resource(int type) const;
};

class MainDecisionAIModule : public AIModule {
public:
    void* player;
    char gap_F4[0x10];
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    char gap_6C4[0xCEC - 0x6C4];
    char informationAI[0x10090];
    TribeResourceAIModule resourceAI;
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    char gap_F4[0x194 - 0xF4];
    int sn[0xE2];

    int inAge(int age);
    int taskResearch(BuildItem* item);
    void checkForASAPAgeResearch();
};

#endif
void TribeTacticalAIModule::checkForASAPAgeResearch()
{
    if (this->inAge(1) != 0 && this->sn[0xB5] == 1 &&
        this->md->buildAI.readyToResearch(2, 1) != 0 &&
        this->md->resourceAI.resource(0) >= 500) {
        BuildItem* item = this->md->buildAI.buildItem(0x65, 1, 4);
        if (item != 0)
            this->taskResearch(item);
    }
    else if (this->inAge(2) != 0 && this->sn[0xB6] == 1 &&
             this->md->buildAI.readyToResearch(3, 1) != 0 &&
             this->md->resourceAI.resource(0) >= 800) {
        BuildItem* item = this->md->buildAI.buildItem(0x66, 1, 4);
        if (item != 0)
            this->taskResearch(item);
    }

    if (this->inAge(3) != 0 && this->sn[0xB7] == 1 &&
        this->md->buildAI.readyToResearch(4, 1) != 0 &&
        this->md->resourceAI.resource(0) >= 900 &&
        this->md->resourceAI.resource(3) >= 700) {
        BuildItem* item = this->md->buildAI.buildItem(0x67, 1, 4);
        if (item != 0)
            this->taskResearch(item);
    }
}
#else
void TribeTacticalAIModule::checkForASAPAgeResearch() {}
#endif
