class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[308];
    int numberBoats_;

    int numberBoats() const;
};
int TribeTacticalAIModule::numberBoats() const { return this->numberBoats_; }
