#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[308];
    int numberBoats_;

    int numberBoats() const;
};
#endif
int TribeTacticalAIModule::numberBoats() const {
#ifdef TAITACMD_SHARED_CONTEXT
    return this->boats.numberValue;
#else
    return this->numberBoats_;
#endif
}
