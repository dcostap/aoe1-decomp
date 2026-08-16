class AIModule {
public:
    ~AIModule();
    virtual void *scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *AIModule::scalar_deleting_destructor(unsigned int param_1) {
    AIModule *self = this;
    this->~AIModule();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return self;
}
