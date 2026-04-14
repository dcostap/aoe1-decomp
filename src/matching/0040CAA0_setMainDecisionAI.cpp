class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    char gap_0[0xEC];
    int field_F0;
    void setMainDecisionAI(int v);
};

void EmotionalAIModule::setMainDecisionAI(int v) { this->field_F0 = v; }
