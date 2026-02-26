#include "../include/TribeMainDecisionAIModule.h"

#include <cstring>

class TribeBuildAIModule {
public:
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
};

TribeMainDecisionAIModule::TribeMainDecisionAIModule(void* param_1, int player_number, char* player_name, TRIBE_Player* player, char* ai1, char* ai2, char* ai3) {
    (void)param_1;
    (void)player_number;
    (void)player_name;
    (void)ai1;
    (void)ai2;
    (void)ai3;

    this->aiPlayer = player;
    this->firstUpdate = 1;
    this->veryFirstUpdate = 1;
    this->updateDelay = player_number;
    this->lastDiplomacyUpdateTime = 0;
    this->lastTacticalUpdateTime = 0;
    this->lastTributeChatTime = 0;
    this->tributeChatTimeout = 0;
    this->waitingOnTribute = 0;
    this->tributeExpirationTimeout = 0;
    this->tributeAddressed = 0;
    this->tributeAmount = 0;
    this->decidedInitialDiplomacy = 0;
    this->requiredDiplomacyTributeAmount = 0;
    std::memset(this->tributeGiven, 0, sizeof(this->tributeGiven));
    std::memset(this->buildAI, 0, sizeof(this->buildAI));
    std::memset(this->constructionAI, 0, sizeof(this->constructionAI));
    std::memset(this->diplomacyAI, 0, sizeof(this->diplomacyAI));
    std::memset(this->emotionalAI, 0, sizeof(this->emotionalAI));
    std::memset(this->informationAI, 0, sizeof(this->informationAI));
    std::memset(this->resourceAI, 0, sizeof(this->resourceAI));
    std::memset(this->strategyAI, 0, sizeof(this->strategyAI));
    std::memset(this->tacticalAI, 0, sizeof(this->tacticalAI));
    std::memset(this->tradeAI, 0, sizeof(this->tradeAI));
    ((TribeBuildAIModule*)this->buildAI)->setMainDecisionAI(this);
}

TribeMainDecisionAIModule::TribeMainDecisionAIModule(int player_number, char* player_name, TRIBE_Player* player, int fd) {
    (void)player_number;
    (void)player_name;
    (void)fd;

    this->aiPlayer = player;
    this->firstUpdate = 0;
    this->veryFirstUpdate = 0;
    this->updateDelay = player_number;
    this->lastDiplomacyUpdateTime = 0;
    this->lastTacticalUpdateTime = 0;
    this->lastTributeChatTime = 0;
    this->tributeChatTimeout = 0;
    this->waitingOnTribute = 0;
    this->tributeExpirationTimeout = 0;
    this->tributeAddressed = 0;
    this->tributeAmount = 0;
    this->decidedInitialDiplomacy = 0;
    this->requiredDiplomacyTributeAmount = 0;
    std::memset(this->tributeGiven, 0, sizeof(this->tributeGiven));
    std::memset(this->buildAI, 0, sizeof(this->buildAI));
    std::memset(this->constructionAI, 0, sizeof(this->constructionAI));
    std::memset(this->diplomacyAI, 0, sizeof(this->diplomacyAI));
    std::memset(this->emotionalAI, 0, sizeof(this->emotionalAI));
    std::memset(this->informationAI, 0, sizeof(this->informationAI));
    std::memset(this->resourceAI, 0, sizeof(this->resourceAI));
    std::memset(this->strategyAI, 0, sizeof(this->strategyAI));
    std::memset(this->tacticalAI, 0, sizeof(this->tacticalAI));
    std::memset(this->tradeAI, 0, sizeof(this->tradeAI));
    ((TribeBuildAIModule*)this->buildAI)->setMainDecisionAI(this);
}

TribeMainDecisionAIModule::~TribeMainDecisionAIModule() {}

int TribeMainDecisionAIModule::loggingHistory() { return 0; }
void TribeMainDecisionAIModule::setLogHistory(int param_1) {
    MainDecisionAIModule::setLogHistory(param_1);
}
void TribeMainDecisionAIModule::toggleLogHistory() {}
void TribeMainDecisionAIModule::setHistoryFilename(char* param_1) {
    MainDecisionAIModule::setHistoryFilename(param_1);
}
int TribeMainDecisionAIModule::loggingCommonHistory() { return 0; }
void TribeMainDecisionAIModule::setLogCommonHistory(int param_1) {
    MainDecisionAIModule::setLogCommonHistory(param_1);
}
void TribeMainDecisionAIModule::toggleLogCommonHistory() {}
int TribeMainDecisionAIModule::loadState(char* param_1) { (void)param_1; return 1; }
int TribeMainDecisionAIModule::saveState(char* param_1) { (void)param_1; return 1; }
int TribeMainDecisionAIModule::gleanState(int param_1) { (void)param_1; return 1; }
int TribeMainDecisionAIModule::processMessage(AIModuleMessage* param_1) { (void)param_1; return 1; }
int TribeMainDecisionAIModule::update(int param_1) { (void)param_1; return 1; }
void TribeMainDecisionAIModule::setCallbackMessage(AIModuleMessage* param_1) { (void)param_1; }
int TribeMainDecisionAIModule::filterOutMessage(AIModuleMessage* param_1) { (void)param_1; return 0; }
int TribeMainDecisionAIModule::save(int param_1) { (void)param_1; return 1; }
int TribeMainDecisionAIModule::addObject(RGE_Static_Object* param_1) { (void)param_1; return 1; }
int TribeMainDecisionAIModule::removeObject(int param_1) { (void)param_1; return 1; }
int TribeMainDecisionAIModule::objectGroupThatCanPerformAction(int param_1) { (void)param_1; return -1; }
int TribeMainDecisionAIModule::canPerformAction(int param_1, int param_2) { (void)param_1; (void)param_2; return 0; }

