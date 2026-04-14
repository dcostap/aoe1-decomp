class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    char gap_0[0xF0];
    int field_F4;
    int numberResources();
};

int TribeResourceAIModule::numberResources() { return this->field_F4; }
