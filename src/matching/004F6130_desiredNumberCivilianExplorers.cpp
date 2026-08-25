#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[264];
    int desiredNumberCivilianExplorers_;

    int desiredNumberCivilianExplorers() const;
};
#endif
int TribeTacticalAIModule::desiredNumberCivilianExplorers() const {
#ifdef TAITACMD_SHARED_CONTEXT
    return this->civilianExplorers.desiredNumberValue;
#else
    return this->desiredNumberCivilianExplorers_;
#endif
}
