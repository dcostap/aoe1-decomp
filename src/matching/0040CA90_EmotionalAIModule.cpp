#ifndef AOE1_AIEMOMOD_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
};

class EmotionalAIModule : public AIModule {
public:
    virtual ~EmotionalAIModule();
};
#endif

EmotionalAIModule::~EmotionalAIModule() {
}
