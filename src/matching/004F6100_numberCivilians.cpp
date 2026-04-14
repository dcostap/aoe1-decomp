class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[244];
    int numberCivilians_;

    int numberCivilians() const;
};
int TribeTacticalAIModule::numberCivilians() const { return this->numberCivilians_; }
