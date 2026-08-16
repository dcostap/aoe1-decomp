class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *EmotionalAIModule::vector_deleting_destructor(unsigned int param_1) {
    this->EmotionalAIModule::~EmotionalAIModule();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
