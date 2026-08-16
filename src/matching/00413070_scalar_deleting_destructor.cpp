class UnitAIModule {
public:
    ~UnitAIModule();
    void *scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *UnitAIModule::scalar_deleting_destructor(unsigned int param_1) {
    this->~UnitAIModule();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
