class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[264];
    int desiredNumberCivilianExplorers_;

    int desiredNumberCivilianExplorers() const;
};
int TribeTacticalAIModule::desiredNumberCivilianExplorers() const { return this->desiredNumberCivilianExplorers_; }
