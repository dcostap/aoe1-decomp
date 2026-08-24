#ifndef AOE1_AIEMOMOD_TU_CONTEXT
class Base_EmotionalAIModule {
public:
    virtual ~Base_EmotionalAIModule();
};

class EmotionalAIModule : public Base_EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
};
#endif

EmotionalAIModule::~EmotionalAIModule() {
}
