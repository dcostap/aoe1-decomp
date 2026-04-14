class ResourceAIModule {
public:
    virtual ~ResourceAIModule();
    int lowestResourceType();
};

int ResourceAIModule::lowestResourceType() { return 1; }
