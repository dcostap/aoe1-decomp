#ifndef TAIUAIMD_COMPLETE_TU
class TribeCivilianUnitAIModule {
public:
    virtual ~TribeCivilianUnitAIModule();
    int processMisc();
};
#endif

int TribeCivilianUnitAIModule::processMisc() { return 9; }
