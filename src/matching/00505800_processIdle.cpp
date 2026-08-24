#ifndef TAIUAIMD_COMPLETE_TU
class TribeCivilianUnitAIModule {
public:
    virtual ~TribeCivilianUnitAIModule();
    int processIdle(int p0);
};
#endif

int TribeCivilianUnitAIModule::processIdle(int p0) { return 5; }
