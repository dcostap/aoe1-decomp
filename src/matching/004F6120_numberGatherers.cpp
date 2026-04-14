class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[2504];
    int numberGatherers_;

    int numberGatherers() const;
};
int TribeTacticalAIModule::numberGatherers() const { return this->numberGatherers_; }
