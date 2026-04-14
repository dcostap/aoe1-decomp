class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_0[0xF4];
    int field_F8;
    int numberObjects();
};

int MainDecisionAIModule::numberObjects() { return this->field_F8; }
