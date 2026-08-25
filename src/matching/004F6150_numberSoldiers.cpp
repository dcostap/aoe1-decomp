#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[276];
    int numberSoldiers_;

    int numberSoldiers() const;
};
#endif
int TribeTacticalAIModule::numberSoldiers() const {
#ifdef TAITACMD_SHARED_CONTEXT
    return this->soldiers.numberValue;
#else
    return this->numberSoldiers_;
#endif
}
