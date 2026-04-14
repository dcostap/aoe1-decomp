class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[276];
    int numberSoldiers_;

    int numberSoldiers() const;
};
int TribeTacticalAIModule::numberSoldiers() const { return this->numberSoldiers_; }
