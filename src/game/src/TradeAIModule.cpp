#include "../include/TradeAIModule.h"

namespace {
char kTradeAIName[] = "Trade AI";
}

// Offset: 0x00412E40
// Fully verified. Source of truth: aitrdmod.cpp.decomp @ 0x00412E40
TradeAIModule::TradeAIModule(void* param_1, int param_2) : AIModule(kTradeAIName, 0x3F2, param_2, param_1) {
    this->md = nullptr;
}

// Offset: 0x00412EA0
// Fully verified. Source of truth: aitrdmod.cpp.decomp @ 0x00412EA0
TradeAIModule::TradeAIModule(int param_1, int param_2) : AIModule(kTradeAIName, 0x3F2, param_1, nullptr) {
    (void)param_2;
    this->md = nullptr;
}

// Offset: 0x00412ED0
// Fully verified. Source of truth: aitrdmod.cpp.decomp @ 0x00412ED0
TradeAIModule::~TradeAIModule() {}

// TODO: Header model declares explicit overrides; forward to AIModule base behavior.
int TradeAIModule::loggingHistory() {
    return AIModule::loggingHistory();
}

void TradeAIModule::setLogHistory(int param_1) {
    AIModule::setLogHistory(param_1);
}

void TradeAIModule::toggleLogHistory() {
    AIModule::toggleLogHistory();
}

void TradeAIModule::setHistoryFilename(char* param_1) {
    AIModule::setHistoryFilename(param_1);
}

int TradeAIModule::loggingCommonHistory() {
    return AIModule::loggingCommonHistory();
}

void TradeAIModule::setLogCommonHistory(int param_1) {
    AIModule::setLogCommonHistory(param_1);
}

void TradeAIModule::toggleLogCommonHistory() {
    AIModule::toggleLogCommonHistory();
}

int TradeAIModule::loadState(char* param_1) {
    return AIModule::loadState(param_1);
}

int TradeAIModule::saveState(char* param_1) {
    return AIModule::saveState(param_1);
}

int TradeAIModule::gleanState(int param_1) {
    return AIModule::gleanState(param_1);
}

int TradeAIModule::processMessage(AIModuleMessage* param_1) {
    return AIModule::processMessage(param_1);
}

int TradeAIModule::update(int param_1) {
    return AIModule::update(param_1);
}

void TradeAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    AIModule::setCallbackMessage(param_1);
}

int TradeAIModule::filterOutMessage(AIModuleMessage* param_1) {
    return AIModule::filterOutMessage(param_1);
}

// Offset: 0x00412EE0
// Fully verified. Source of truth: aitrdmod.cpp.decomp @ 0x00412EE0
void TradeAIModule::setMainDecisionAI(MainDecisionAIModule* param_1) {
    this->md = param_1;
}

// Offset: 0x00412EF0
// Fully verified. Source of truth: aitrdmod.cpp.decomp @ 0x00412EF0
int TradeAIModule::save(int param_1) {
    (void)param_1;
    return 1;
}
