#ifndef TAIBLDMD_SHARED_CONTEXT
class BuildItem { public: void setInProgress(int); void setBuilt(int); void incrementNumberBuilds(); };
class TribeTacticalAIModule { public: char pad_000[0x1146C]; void updateNeededResources(); };
class TribeMainDecisionAIModule { public: void detask(int); };
class BuildAIModule { public: BuildItem* specificBuildListItem(int); };
class TribeBuildAIModule : public BuildAIModule { public: char pad_000[0x5BC]; TribeMainDecisionAIModule* md; int addResearch(int param_1, int param_2, int param_3); };
#endif
int TribeBuildAIModule::addResearch(int param_1, int param_2, int param_3) {
    BuildItem* item = this->specificBuildListItem(param_3);
    if (item != 0) {
        item->setInProgress(0);
        item->setBuilt(1);
        item->incrementNumberBuilds();
    }
    this->md->detask(param_2);
    ((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->updateNeededResources();
    return 1;
}
