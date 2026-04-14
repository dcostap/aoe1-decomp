class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[260];
    int numberCivilianExplorers_;

    int numberCivilianExplorers() const;
};
int TribeTacticalAIModule::numberCivilianExplorers() const { return this->numberCivilianExplorers_; }
