class ResourceAIModule {
public:
    virtual ~ResourceAIModule();
    char gap_0[0xF0];
    int field_F4;
    int numberResources();
};

int ResourceAIModule::numberResources() { return this->field_F4; }
