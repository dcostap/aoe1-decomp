class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    void* scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void* param_1);

void* ConstructionAIModule::scalar_deleting_destructor(unsigned int param_1) {
    this->ConstructionAIModule::~ConstructionAIModule();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
