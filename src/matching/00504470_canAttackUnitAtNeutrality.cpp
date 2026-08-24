#ifndef TAIUAIMD_COMPLETE_TU
class TribeLionUnitAIModule {
public:
    virtual ~TribeLionUnitAIModule();
    int canAttackUnitAtNeutrality(int p0);
};
#endif

int TribeLionUnitAIModule::canAttackUnitAtNeutrality(int p0) { return 1; }
