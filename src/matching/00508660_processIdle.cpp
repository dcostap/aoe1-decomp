#ifndef TAIUAIMD_COMPLETE_TU
class TribeBuildingUnitAIModule {
public:
    virtual ~TribeBuildingUnitAIModule();
    int processIdle(int p0);
};
#endif

int TribeBuildingUnitAIModule::processIdle(int p0) { return 5; }
