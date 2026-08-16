// VA: 0040CE70 MainDecisionAIModule::`scalar deleting destructor'
// The generated wrapper calls the scalar destructor directly, then honors bit 0
// of the delete flags with the period global operator delete.
class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    void *vector_deleting_destructor(unsigned int flags);
};

void operator delete(void *object);

void *MainDecisionAIModule::vector_deleting_destructor(unsigned int flags) {
    this->MainDecisionAIModule::~MainDecisionAIModule();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}
