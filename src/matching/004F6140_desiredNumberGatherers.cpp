class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[2508];
    int desiredNumberGatherers_;

    int desiredNumberGatherers() const;
};
int TribeTacticalAIModule::desiredNumberGatherers() const { return this->desiredNumberGatherers_; }
