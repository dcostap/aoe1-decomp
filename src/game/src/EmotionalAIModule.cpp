#include "../include/EmotionalAIModule.h"

#include "../include/AIModule.h"
#include "../include/globals.h"

#include <new>
#include <string.h>

namespace {
char kEmotionalAIName[] = "Emotional AI";
char kAggressive[] = "Aggressive";
char kCompassionate[] = "Compassionate";
char kDefensive[] = "Defensive";
char kFriendly[] = "Friendly";
char kPassive[] = "Passive";
char kVengeful[] = "Vengeful";

AIModule* as_ai(EmotionalAIModule* self) {
    return reinterpret_cast<AIModule*>(self);
}

void copy_state_name(char (&dest)[30], const char* src) {
    strncpy(dest, src, 0x1D);
    dest[0x1D] = '\0';
}

void initialize_state_names(EmotionalAIModule* self) {
    copy_state_name(self->stateNameValue[0], kAggressive);
    copy_state_name(self->stateNameValue[1], kCompassionate);
    copy_state_name(self->stateNameValue[2], kDefensive);
    copy_state_name(self->stateNameValue[3], kFriendly);
    copy_state_name(self->stateNameValue[4], kPassive);
    copy_state_name(self->stateNameValue[5], kVengeful);
}
}

// Offset: 0x0040C7C0
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040C7C0
EmotionalAIModule::EmotionalAIModule(void* param_1, int param_2) {
    new ((AIModule*)this) AIModule(kEmotionalAIName, 0x3EC, param_2, param_1);
    this->md = nullptr;
    for (int i = 0; i < 6; ++i) {
        this->stateValue[i] = 0x31;
    }
    initialize_state_names(this);
}

// Offset: 0x0040C920
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040C920
EmotionalAIModule::EmotionalAIModule(int param_1, int param_2) {
    new ((AIModule*)this) AIModule(kEmotionalAIName, 0x3EC, param_1, nullptr);
    this->md = nullptr;
    for (int i = 0; i < 6; ++i) {
        rge_read(param_2, &this->stateValue[i], 4);
    }
    initialize_state_names(this);
}

// Offset: 0x0040CA90
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040CA90
EmotionalAIModule::~EmotionalAIModule() {
    as_ai(this)->~AIModule();
}

// TODO: Header model declares explicit overrides; forward to AIModule base behavior.
int EmotionalAIModule::loggingHistory() {
    return as_ai(this)->loggingHistory();
}

void EmotionalAIModule::setLogHistory(int param_1) {
    as_ai(this)->setLogHistory(param_1);
}

void EmotionalAIModule::toggleLogHistory() {
    as_ai(this)->toggleLogHistory();
}

void EmotionalAIModule::setHistoryFilename(char* param_1) {
    as_ai(this)->setHistoryFilename(param_1);
}

int EmotionalAIModule::loggingCommonHistory() {
    return as_ai(this)->loggingCommonHistory();
}

void EmotionalAIModule::setLogCommonHistory(int param_1) {
    as_ai(this)->setLogCommonHistory(param_1);
}

void EmotionalAIModule::toggleLogCommonHistory() {
    as_ai(this)->toggleLogCommonHistory();
}

int EmotionalAIModule::loadState(char* param_1) {
    return as_ai(this)->loadState(param_1);
}

int EmotionalAIModule::saveState(char* param_1) {
    return as_ai(this)->saveState(param_1);
}

int EmotionalAIModule::gleanState(int param_1) {
    return as_ai(this)->gleanState(param_1);
}

int EmotionalAIModule::processMessage(AIModuleMessage* param_1) {
    return as_ai(this)->processMessage(param_1);
}

int EmotionalAIModule::update(int param_1) {
    return as_ai(this)->update(param_1);
}

void EmotionalAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    as_ai(this)->setCallbackMessage(param_1);
}

int EmotionalAIModule::filterOutMessage(AIModuleMessage* param_1) {
    return as_ai(this)->filterOutMessage(param_1);
}

// Offset: 0x0040CAA0
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040CAA0
void EmotionalAIModule::setMainDecisionAI(MainDecisionAIModule* param_1) {
    this->md = param_1;
}

// Offset: 0x0040CAB0
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040CAB0
int EmotionalAIModule::save(int param_1) {
    for (int i = 0; i < 6; ++i) {
        rge_write(param_1, &this->stateValue[i], 4);
    }
    return 1;
}

// Offset: 0x0040CAE0
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040CAE0
char* EmotionalAIModule::stateName(int param_1) {
    if ((-1 < param_1) && (param_1 < 6)) {
        return this->stateNameValue[param_1];
    }
    return nullptr;
}

// Offset: 0x0040CB10
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040CB10
int EmotionalAIModule::state(int param_1) const {
    if ((-1 < param_1) && (param_1 < 6)) {
        return this->stateValue[param_1];
    }
    return -1;
}

// Offset: 0x0040CB30
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040CB30
void EmotionalAIModule::setState(int param_1, int param_2) {
    if ((-1 < param_1) && (param_1 < 6)) {
        this->stateValue[param_1] = param_2;
    }
}

// Offset: 0x0040CB50
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040CB50
void EmotionalAIModule::incrementState(int param_1, int param_2) {
    if ((-1 < param_1) && (param_1 < 6)) {
        this->stateValue[param_1] = this->stateValue[param_1] + param_2;
    }
}

// Offset: 0x0040CB80
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040CB80
void EmotionalAIModule::decrementState(int param_1, int param_2) {
    if ((-1 < param_1) && (param_1 < 6)) {
        this->stateValue[param_1] = this->stateValue[param_1] - param_2;
    }
}

// Offset: 0x0040CBB0
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040CBB0
int EmotionalAIModule::overallState() const {
    int max_value = this->stateValue[0];
    int max_index = 0;
    for (int i = 1; i < 6; ++i) {
        if (max_value < this->stateValue[i]) {
            max_value = this->stateValue[i];
            max_index = i;
        }
    }
    return max_index;
}

// Offset: 0x0040CBE0
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040CBE0
void EmotionalAIModule::setOverallState(int param_1) {
    switch (param_1) {
    case 0:
        this->stateValue[0] = 100;
        this->stateValue[4] = 10;
        this->stateValue[1] = 10;
        this->stateValue[3] = 10;
        this->stateValue[2] = 0;
        this->stateValue[5] = 0x46;
        return;
    case 1:
        this->stateValue[0] = 10;
        this->stateValue[4] = 0x32;
        this->stateValue[1] = 100;
        this->stateValue[3] = 0x50;
        this->stateValue[2] = 0x32;
        this->stateValue[5] = 0;
        return;
    case 2:
        this->stateValue[0] = 0x14;
        this->stateValue[4] = 0x3C;
        this->stateValue[1] = 0x32;
        this->stateValue[3] = 0x32;
        this->stateValue[2] = 100;
        this->stateValue[5] = 10;
        return;
    case 3:
        this->stateValue[0] = 10;
        this->stateValue[4] = 0x32;
        this->stateValue[1] = 0x46;
        this->stateValue[3] = 100;
        this->stateValue[2] = 0x32;
        this->stateValue[5] = 0x14;
        return;
    case 4:
        this->stateValue[0] = 0x14;
        this->stateValue[4] = 100;
        this->stateValue[1] = 0x46;
        this->stateValue[3] = 0x32;
        this->stateValue[2] = 0x3C;
        this->stateValue[5] = 0;
        return;
    case 5:
        this->stateValue[0] = 0x5A;
        this->stateValue[4] = 10;
        this->stateValue[1] = 0;
        this->stateValue[3] = 0x1E;
        this->stateValue[2] = 0x32;
        this->stateValue[5] = 100;
        return;
    default:
        return;
    }
}

// Offset: 0x0040CD80
// Fully verified. Source of truth: aiemomod.cpp.decomp @ 0x0040CD80
int EmotionalAIModule::defaultState() const {
    return 4;
}
