class StrategyAIModule {
public:
    virtual void* vector_deleting_destructor(unsigned int flags);
    ~StrategyAIModule();
};

extern "C" void operator_delete(void* ptr);

void* StrategyAIModule::vector_deleting_destructor(unsigned int flags) {
    StrategyAIModule* self;

    self = this;
    this->~StrategyAIModule();
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    return self;
}
