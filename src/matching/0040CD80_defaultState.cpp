#ifndef AOE1_AIEMOMOD_TU_CONTEXT
class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    int defaultState() const;
};
#endif

int EmotionalAIModule::defaultState() const { return 4; }
