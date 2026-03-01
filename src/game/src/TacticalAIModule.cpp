#include "../include/TacticalAIModule.h"

// Fully verified. Source of truth: aitacmod.cpp.decomp @ 0x00412B50
TacticalAIModule::TacticalAIModule(void* param_1, int param_2)
    : AIModule((char*)"TacAI", 0x3F1, param_2, param_1) {}

// Fully verified. Source of truth: aitacmod.cpp.decomp @ 0x00412BA0
TacticalAIModule::~TacticalAIModule() {}

int TacticalAIModule::loggingHistory() {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    return AIModule::loggingHistory();
}

void TacticalAIModule::setLogHistory(int param_1) {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    AIModule::setLogHistory(param_1);
}

void TacticalAIModule::toggleLogHistory() {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    AIModule::toggleLogHistory();
}

void TacticalAIModule::setHistoryFilename(char* param_1) {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    AIModule::setHistoryFilename(param_1);
}

int TacticalAIModule::loggingCommonHistory() {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    return AIModule::loggingCommonHistory();
}

void TacticalAIModule::setLogCommonHistory(int param_1) {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    AIModule::setLogCommonHistory(param_1);
}

void TacticalAIModule::toggleLogCommonHistory() {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    AIModule::toggleLogCommonHistory();
}

int TacticalAIModule::loadState(char* param_1) {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    return AIModule::loadState(param_1);
}

int TacticalAIModule::saveState(char* param_1) {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    return AIModule::saveState(param_1);
}

int TacticalAIModule::gleanState(int param_1) {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    return AIModule::gleanState(param_1);
}

int TacticalAIModule::processMessage(AIModuleMessage* param_1) {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    return AIModule::processMessage(param_1);
}

int TacticalAIModule::update(int param_1) {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    return AIModule::update(param_1);
}

void TacticalAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    AIModule::setCallbackMessage(param_1);
}

int TacticalAIModule::filterOutMessage(AIModuleMessage* param_1) {
    // Fully verified. Source of truth: aitacmod.cpp.decomp (helper implementation).
    return AIModule::filterOutMessage(param_1);
}
