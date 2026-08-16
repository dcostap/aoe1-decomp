class Base_DiplomacyAIModule {
public:
    virtual ~Base_DiplomacyAIModule();
};

class DiplomacyAIModule : public Base_DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    void* scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void* param_1);

void* DiplomacyAIModule::scalar_deleting_destructor(unsigned int param_1) {
    this->DiplomacyAIModule::~DiplomacyAIModule();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
