#include "../include/TradeAIModule.h"

namespace {
char kTradeAIName[] = "Trade AI";
}

// Offset: 0x00412E40
// Fully verified. Source of truth: aitrdmod.cpp.decomp @ 0x00412E40, aitrdmod.cpp.asm @ 0x00412E40
TradeAIModule::TradeAIModule(void* param_1, int param_2) : AIModule(kTradeAIName, 0x3F2, param_2, param_1) {
    this->md = nullptr;
}

// Offset: 0x00412EA0
// Fully verified. Source of truth: aitrdmod.cpp.decomp @ 0x00412EA0, aitrdmod.cpp.asm @ 0x00412EA0
TradeAIModule::TradeAIModule(int param_1, int param_2) : AIModule(kTradeAIName, 0x3F2, param_1, nullptr) {
    (void)param_2;
    this->md = nullptr;
}

// Offset: 0x00412ED0
// Fully verified. Source of truth: aitrdmod.cpp.decomp @ 0x00412ED0, aitrdmod.cpp.asm @ 0x00412ED0
TradeAIModule::~TradeAIModule() {
    // TODO: EMPTY_STUB - function body not transliterated [decomp: bucket_0560.decomp @ 0x00560698]
}

// Fully verified. Not in decomp, inherited/forwarding overrides from AIModule.
int TradeAIModule::loggingHistory() {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    return AIModule::loggingHistory();
}

void TradeAIModule::setLogHistory(int param_1) {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    AIModule::setLogHistory(param_1);
}

void TradeAIModule::toggleLogHistory() {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    AIModule::toggleLogHistory();
}

void TradeAIModule::setHistoryFilename(char* param_1) {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    AIModule::setHistoryFilename(param_1);
}

int TradeAIModule::loggingCommonHistory() {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    return AIModule::loggingCommonHistory();
}

void TradeAIModule::setLogCommonHistory(int param_1) {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    AIModule::setLogCommonHistory(param_1);
}

void TradeAIModule::toggleLogCommonHistory() {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    AIModule::toggleLogCommonHistory();
}

int TradeAIModule::loadState(char* param_1) {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    return AIModule::loadState(param_1);
}

int TradeAIModule::saveState(char* param_1) {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    return AIModule::saveState(param_1);
}

int TradeAIModule::gleanState(int param_1) {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    return AIModule::gleanState(param_1);
}

int TradeAIModule::processMessage(AIModuleMessage* param_1) {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    return AIModule::processMessage(param_1);
}

int TradeAIModule::update(int param_1) {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    return AIModule::update(param_1);
}

void TradeAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    AIModule::setCallbackMessage(param_1);
}

int TradeAIModule::filterOutMessage(AIModuleMessage* param_1) {
    // Fully verified. Source of truth: aitrdmod.cpp.decomp (helper implementation).
    return AIModule::filterOutMessage(param_1);
}

// Offset: 0x00412EE0
// Fully verified. Source of truth: aitrdmod.cpp.decomp @ 0x00412EE0, aitrdmod.cpp.asm @ 0x00412EE0
void TradeAIModule::setMainDecisionAI(MainDecisionAIModule* param_1) {
    this->md = param_1;
}

// Offset: 0x00412EF0
// Fully verified. Source of truth: aitrdmod.cpp.decomp @ 0x00412EF0, aitrdmod.cpp.asm @ 0x00412EF0
int TradeAIModule::save(int param_1) {
    (void)param_1;
    return 1;
}
