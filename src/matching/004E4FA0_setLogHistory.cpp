#ifndef AOE1_TAIMDMD_CONTEXT_H
class AIModuleSub {
public:
    virtual ~AIModuleSub();
    virtual int loggingHistory();
    virtual void setLogHistory(int value);
};

class MainDecisionAIModule {
public:
    void setLogHistory(int value);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap0[0x104];
    AIModuleSub buildAI;
    char gap108[0x6C4 - 0x108];
    AIModuleSub constructionAI;
    char gap6C8[0x9DC - 0x6C8];
    AIModuleSub diplomacyAI;
    char gap9E0[0xB2C - 0x9E0];
    AIModuleSub emotionalAI;
    char gapB30[0xCEC - 0xB30];
    AIModuleSub informationAI;
    char gapCF0[0x10D7C - 0xCF0];
    AIModuleSub resourceAI;
    char gap10D80[0x10E74 - 0x10D80];
    AIModuleSub strategyAI;
    char gap10E78[0x1146C - 0x10E78];
    AIModuleSub tacticalAI;
    char gap11470[0x12478 - 0x11470];
    AIModuleSub tradeAI;

    void setLogHistory(int value);
};
#endif

void TribeMainDecisionAIModule::setLogHistory(int value)
{
    buildAI.setLogHistory(value);
    constructionAI.setLogHistory(value);
    diplomacyAI.setLogHistory(value);
    emotionalAI.setLogHistory(value);
    informationAI.setLogHistory(value);
    resourceAI.setLogHistory(value);
    strategyAI.setLogHistory(value);
    tacticalAI.setLogHistory(value);
    tradeAI.setLogHistory(value);
    MainDecisionAIModule::setLogHistory(value);
}
