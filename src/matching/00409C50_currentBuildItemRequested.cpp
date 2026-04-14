class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x3A2];
    char field_3A6[1];
    char* currentBuildItemRequested();
};

char* BuildAIModule::currentBuildItemRequested() { return this->field_3A6; }
