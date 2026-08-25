#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[244];
    int numberCivilians_;

    int numberCivilians() const;
};
#endif
int TribeTacticalAIModule::numberCivilians() const {
#ifdef TAITACMD_SHARED_CONTEXT
    return this->civilians.numberValue;
#else
    return this->numberCivilians_;
#endif
}
