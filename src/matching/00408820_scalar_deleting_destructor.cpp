class BuildAIModule {
public:
    ~BuildAIModule();
    virtual void *scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *BuildAIModule::scalar_deleting_destructor(unsigned int param_1) {
    BuildAIModule* self;

    self = this;
    this->~BuildAIModule();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return self;
}
