class TacticalAIModule {
public:
    ~TacticalAIModule();
    void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *TacticalAIModule::vector_deleting_destructor(unsigned int param_1) {
    this->~TacticalAIModule();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
