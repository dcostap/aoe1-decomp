#include "../include/InformationAIModule.h"

namespace {
char kInformationAIName[] = "InfAI";
}

// Offset: 0x0040CD90
// Fully verified. Source of truth: aiinfmod.cpp.decomp @ 0x0040CD90
InformationAIModule::InformationAIModule(void* param_1, int param_2)
    : AIModule(kInformationAIName, 0x3ED, param_2, param_1) {}

// Offset: 0x0040CDE0
// Fully verified. Source of truth: aiinfmod.cpp.decomp @ 0x0040CDE0
InformationAIModule::~InformationAIModule() {}

int InformationAIModule::loggingHistory() {
    return AIModule::loggingHistory();
}

void InformationAIModule::setLogHistory(int param_1) {
    AIModule::setLogHistory(param_1);
}

void InformationAIModule::toggleLogHistory() {
    AIModule::toggleLogHistory();
}

void InformationAIModule::setHistoryFilename(char* param_1) {
    AIModule::setHistoryFilename(param_1);
}

int InformationAIModule::loggingCommonHistory() {
    return AIModule::loggingCommonHistory();
}

void InformationAIModule::setLogCommonHistory(int param_1) {
    AIModule::setLogCommonHistory(param_1);
}

void InformationAIModule::toggleLogCommonHistory() {
    AIModule::toggleLogCommonHistory();
}

int InformationAIModule::loadState(char* param_1) {
    return AIModule::loadState(param_1);
}

int InformationAIModule::saveState(char* param_1) {
    return AIModule::saveState(param_1);
}

int InformationAIModule::gleanState(int param_1) {
    return AIModule::gleanState(param_1);
}

int InformationAIModule::processMessage(AIModuleMessage* param_1) {
    return AIModule::processMessage(param_1);
}

int InformationAIModule::update(int param_1) {
    return AIModule::update(param_1);
}

void InformationAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    AIModule::setCallbackMessage(param_1);
}

int InformationAIModule::filterOutMessage(AIModuleMessage* param_1) {
    return AIModule::filterOutMessage(param_1);
}
