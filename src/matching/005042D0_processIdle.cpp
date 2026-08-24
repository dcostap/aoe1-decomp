#ifndef TAIUAIMD_COMPLETE_TU
class TribeElephantUnitAIModule {
public:
    virtual ~TribeElephantUnitAIModule();
    int processIdle(int p0);
};
#endif

int TribeElephantUnitAIModule::processIdle(int p0) { return 5; }
