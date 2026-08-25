#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[260];
    int numberCivilianExplorers_;

    int numberCivilianExplorers() const;
};
#endif
int TribeTacticalAIModule::numberCivilianExplorers() const {
#ifdef TAITACMD_SHARED_CONTEXT
    return this->civilianExplorers.numberValue;
#else
    return this->numberCivilianExplorers_;
#endif
}
