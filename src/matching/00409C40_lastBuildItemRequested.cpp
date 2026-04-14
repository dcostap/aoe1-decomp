class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x2A1];
    char field_2A5[1];
    char* lastBuildItemRequested();
};

char* BuildAIModule::lastBuildItemRequested() { return this->field_2A5; }
