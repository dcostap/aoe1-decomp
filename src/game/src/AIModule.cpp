#include "../include/AIModule.h"

#include "../include/globals.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E220
AIModule::AIModule()
    : idValue((char*)"", -1) {
    this->playerNumberValue = -1;
    this->runningValue = 0;
    this->pausedValue = 0;
    this->logHistoryValue = 0;
    this->logCommonHistoryValue = 0;
    this->historyLogFile = nullptr;
    this->intelligenceLevelValue = 5;
    this->priorityValue = 0x32;
    this->processFrameValue = 0;
    strcpy(this->playerNameValue, "Unknown");
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E2D0
AIModule::AIModule(char* param_1, int param_2, int param_3, void* param_4)
    : idValue(param_1, param_2) {
    (void)param_4;
    this->playerNumberValue = param_3;
    this->runningValue = 0;
    this->pausedValue = 0;
    this->logHistoryValue = 0;
    this->logCommonHistoryValue = 0;
    this->historyLogFile = nullptr;
    this->intelligenceLevelValue = 5;
    this->priorityValue = 0x32;
    this->processFrameValue = 0;
    strcpy(this->playerNameValue, "Unknown");
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E360
AIModule::~AIModule() {
    if ((this->logCommonHistoryValue != 0) && (commonHistoryLogFile != nullptr)) {
        fclose(commonHistoryLogFile);
        commonHistoryLogFile = nullptr;
    }
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E3A0
AIModuleID AIModule::id() const {
    AIModuleID result((char*)"", this->idValue.id);
    memcpy(result.name, this->idValue.name, sizeof(result.name));
    return result;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E3D0
int AIModule::idNumber() const {
    return this->idValue.id;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E3E0
int AIModule::playerNumber() const {
    return this->playerNumberValue;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E3F0
char* AIModule::playerName() const {
    return (char*)this->playerNameValue;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E400
void AIModule::setPlayer(int param_1, char* param_2) {
    this->playerNumberValue = param_1;
    if (param_2 != nullptr) {
        strncpy(this->playerNameValue, param_2, 0x3F);
        return;
    }
    strcpy(this->playerNameValue, "Unknown");
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E450
void AIModule::start() {
    this->runningValue = 1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E460
void AIModule::stop() {
    this->runningValue = 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E470
void AIModule::toggleRun() {
    this->runningValue = (uint)(this->runningValue == 0);
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E490
void AIModule::togglePause() {
    this->pausedValue = (uint)(this->pausedValue == 0);
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E4B0
void AIModule::step() {}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E4C0
int AIModule::running() const {
    return this->runningValue;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E4D0
int AIModule::paused() const {
    return this->pausedValue;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E4E0
int AIModule::loggingHistory() {
    return this->logHistoryValue;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E4F0
void AIModule::setLogHistory(int param_1) {
    (void)param_1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E500
void AIModule::toggleLogHistory() {}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E510
int AIModule::loggingCommonHistory() {
    return this->logCommonHistoryValue;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E520
void AIModule::setLogCommonHistory(int param_1) {
    this->logCommonHistoryValue = param_1;
    if ((param_1 != 0) && (commonHistoryLogFile == nullptr)) {
        commonHistoryLogFile = fopen("c:\\aoeai.txt", "wa");
        time_t now = 0;
        time(&now);
        char* timeText = asctime(localtime(&now));
        this->logCommonHistory((char*)"Common AI History File Started: %s", timeText);
        this->logCommonHistory((char*)"");
        return;
    }
    if ((param_1 == 0) && (commonHistoryLogFile != nullptr)) {
        fclose(commonHistoryLogFile);
        commonHistoryLogFile = nullptr;
    }
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E5C0
void AIModule::toggleLogCommonHistory() {}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E5D0
void AIModule::setHistoryFilename(char* param_1) {
    (void)param_1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x004087F0
int AIModule::loadState(char* param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x00408800
int AIModule::saveState(char* param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x00408810
int AIModule::gleanState(int param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E5E0
int AIModule::intelligenceLevel() const {
    return this->intelligenceLevelValue;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E5F0
int AIModule::setIntelligenceLevel(int param_1) {
    this->intelligenceLevelValue = param_1;
    if (param_1 < 1) {
        this->intelligenceLevelValue = 1;
        return 0;
    }
    if (10 < param_1) {
        this->intelligenceLevelValue = 10;
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E630
int AIModule::priority() const {
    return this->priorityValue;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E640
int AIModule::setPriority(int param_1) {
    this->priorityValue = param_1;
    if (param_1 < 1) {
        this->priorityValue = 1;
        return 0;
    }
    if (100 < param_1) {
        this->priorityValue = 100;
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E680
int AIModule::incrementPriority(int param_1) {
    int iVar1 = setPriority(this->priorityValue + param_1);
    return iVar1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E6A0
int AIModule::decrementPriority(int param_1) {
    int iVar1 = setPriority(this->priorityValue - param_1);
    return iVar1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E6C0
int AIModule::sendMessage(AIModuleMessage* param_1, int param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E6D0
void AIModule::receiveMessage(AIModuleMessage* param_1) {
    (void)param_1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E6E0
int AIModule::processMessage(AIModuleMessage* param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E6F0
int AIModule::update(int param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E700
void AIModule::setCallbackMessage(AIModuleMessage* param_1) {
    (void)param_1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E710
int AIModule::messageLimit() {
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E720
void AIModule::setMessageLimit(int param_1) {
    (void)param_1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E730
int AIModule::callbackLimit() {
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E740
void AIModule::setCallbackLimit(int param_1) {
    (void)param_1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E750
int AIModule::messageTimeout() {
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E760
void AIModule::setMessageTimeout(int param_1) {
    (void)param_1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E770
int AIModule::purgeMessages(AIModuleID param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E780
int AIModule::purgeMessagesWithID(AIModuleID param_1, int param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E790
int AIModule::purgeMessagesWithPriorityBelow(AIModuleID param_1, int param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E7A0
int AIModule::purgeMessagesWithData(AIModuleID param_1, int param_2, int param_3, long param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E7B0
int AIModule::purgeCallbacks(AIModuleID param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E7C0
int AIModule::purgeCallbacksWithID(AIModuleID param_1, int param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E7D0
int AIModule::purgeCallbacksWithPriorityBelow(AIModuleID param_1, int param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E7E0
int AIModule::purgeCallbacksWithData(AIModuleID param_1, int param_2, int param_3, long param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E7F0
void AIModule::checkMessageLimit() {}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E800
void AIModule::checkCallbackLimit() {}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E810
int AIModule::filterOutMessage(AIModuleMessage* param_1) {
    (void)param_1;
    return 0;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E820
void AIModule::logHistory(char* param_1, ...) {
    (void)param_1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E830
void AIModule::logCommonHistory(char* param_1, ...) {
    if (((specificAIPlayerToLog == -1) || (specificAIPlayerToLog == this->playerNumberValue)) &&
        (commonHistoryLogFile != nullptr)) {
        char textOut[1024];
        va_list args;
        va_start(args, param_1);
        vsprintf(textOut + 4, param_1, args);
        va_end(args);

        if (textOut[4] == '\0') {
            fprintf(commonHistoryLogFile, "P#%d\n", this->playerNumberValue);
        } else {
            fprintf(commonHistoryLogFile, "P#%d(%s): %s\n", this->playerNumberValue, this->playerNameValue, textOut + 4);
        }
        fflush(commonHistoryLogFile);
    }
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E8E0
void AIModule::logDebug(char* param_1, ...) {
    (void)param_1;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E8F0
int AIModule::processFrame() {
    return this->processFrameValue;
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E900
void AIModule::incrementProcessFrame() {
    int iVar1 = this->processFrameValue + 1;
    this->processFrameValue = iVar1;
    if (iVar1 == 0x7FFFFFFF) {
        this->processFrameValue = 0;
    }
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E920
int AIModule::timeDifference(AIModuleMessage* param_1) {
    (void)param_1;
    return 0;
}
