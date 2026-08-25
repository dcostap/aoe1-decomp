#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[2504];
    int numberGatherers_;

    int numberGatherers() const;
};
#endif
int TribeTacticalAIModule::numberGatherers() const {
#ifdef TAITACMD_SHARED_CONTEXT
    return this->numberGatherersValue;
#else
    return this->numberGatherers_;
#endif
}
