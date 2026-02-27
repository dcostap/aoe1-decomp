#include "../include/StrategyAIModule.h"

StrategyAIModule::StrategyAIModule(void* param_1, int param_2)
    : AIModule((char*)"Strategy AI", 0x3F0, param_2, param_1) {
    // Fully verified. Source of truth: aistrmod.cpp.decomp @ 0x00412AF0
}

// Fully verified. Source of truth: aistrmod.cpp.decomp @ 0x00412B40
StrategyAIModule::~StrategyAIModule() {}

int StrategyAIModule::loggingHistory() { return AIModule::loggingHistory(); }
void StrategyAIModule::setLogHistory(int param_1) { AIModule::setLogHistory(param_1); }
void StrategyAIModule::toggleLogHistory() { AIModule::toggleLogHistory(); }
void StrategyAIModule::setHistoryFilename(char* param_1) { AIModule::setHistoryFilename(param_1); }
int StrategyAIModule::loggingCommonHistory() { return AIModule::loggingCommonHistory(); }
void StrategyAIModule::setLogCommonHistory(int param_1) { AIModule::setLogCommonHistory(param_1); }
void StrategyAIModule::toggleLogCommonHistory() { AIModule::toggleLogCommonHistory(); }
int StrategyAIModule::loadState(char* param_1) { return AIModule::loadState(param_1); }
int StrategyAIModule::saveState(char* param_1) { return AIModule::saveState(param_1); }
int StrategyAIModule::gleanState(int param_1) { return AIModule::gleanState(param_1); }
int StrategyAIModule::processMessage(AIModuleMessage* param_1) { return AIModule::processMessage(param_1); }
int StrategyAIModule::update(int param_1) { return AIModule::update(param_1); }
void StrategyAIModule::setCallbackMessage(AIModuleMessage* param_1) { AIModule::setCallbackMessage(param_1); }
int StrategyAIModule::filterOutMessage(AIModuleMessage* param_1) { return AIModule::filterOutMessage(param_1); }
