#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[2508];
    int desiredNumberGatherers_;

    int desiredNumberGatherers() const;
};
#endif
int TribeTacticalAIModule::desiredNumberGatherers() const {
#ifdef TAITACMD_SHARED_CONTEXT
    return this->desiredNumberGatherersValue;
#else
    return this->desiredNumberGatherers_;
#endif
}
