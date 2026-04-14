class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_0[0x4A3];
    char field_4A7[1];
    char* nextBuildItemRequested();
};

char* BuildAIModule::nextBuildItemRequested() { return this->field_4A7; }
