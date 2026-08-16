class ResearchAIModule {
public:
    ~ResearchAIModule();
    virtual void *scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *ResearchAIModule::scalar_deleting_destructor(unsigned int param_1) {
    this->~ResearchAIModule();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
