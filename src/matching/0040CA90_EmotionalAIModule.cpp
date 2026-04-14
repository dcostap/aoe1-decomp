class Base_EmotionalAIModule {
public:
    virtual ~Base_EmotionalAIModule();
};

class EmotionalAIModule : public Base_EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
};

EmotionalAIModule::~EmotionalAIModule() {
}
