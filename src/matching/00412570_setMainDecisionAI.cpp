class ResourceAIModule {
public:
    virtual ~ResourceAIModule();
    char gap_0[0xEC];
    int field_F0;
    void setMainDecisionAI(int v);
};

void ResourceAIModule::setMainDecisionAI(int v) { this->field_F0 = v; }
