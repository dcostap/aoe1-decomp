class ResourceAIModule {
public:
    void target_func(int p0);
    void filterOutMessage(int p);
};

void ResourceAIModule::filterOutMessage(int p) { this->target_func(p); }
