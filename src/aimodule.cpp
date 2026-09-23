#include "../include/aimodule.h"
#include "../include/game_globals.h"

#include <stdarg.h>
#include <string.h>
#include <time.h>

AIModuleID::AIModuleID(char* n, int i) {
    this->id = i;

    if (n != NULL) {
        strncpy(this->name, n, 63);
    } else {
        strcpy(this->name, "");
    }
}

AIModuleID::~AIModuleID() {}

void AIModuleID::setID(int i, char* n) {
    this->id = i;
    if (n != 0) {
        strncpy(this->name, n, 63);
        return;
    }
    strcpy(this->name, "");
}

AIModuleMessage::AIModuleMessage()
    : id(0),
      priority(0),
      sender("Sender", 0),
      recipient("Recipient", 0),
      data1(0),
      data2(0),
      data3(0),
      callbackMessage(0),
      timeStamp(0),
      next(0),
      prev(0) {
    strcpy(text, "");
}

AIModuleMessage::AIModuleMessage(int s, int r, int i, int p, long d1, long d2, long d3,
                                 AIModuleMessage* c, int t)
    : id(i),
      priority(p),
      sender("", s),
      recipient("", r),
      data1(d1),
      data2(d2),
      data3(d3),
      callbackMessage(c),
      timeStamp(t) {
    strcpy(this->text, "");
}

AIModuleMessage::AIModuleMessage(AIModuleMessage* m)
    : id(m->id),
      priority(m->priority),
      sender(m->sender.name, m->sender.id),
      recipient(m->recipient.name, m->recipient.id),
      data1(m->data1),
      data2(m->data2),
      data3(m->data3),
      callbackMessage(m->callbackMessage),
      timeStamp(m->timeStamp),
      next(0),
      prev(0) {
    this->setText(m->text);
}

AIModuleMessage::~AIModuleMessage() {
    delete this->callbackMessage;
}

void AIModuleMessage::setText(char* t) {
    if (t != 0) {
        strncpy(this->text, t, 127);
        return;
    }

    strcpy(this->text, "");
}

void AIModuleMessage::setSender(int i, char* n) {
    this->sender.setID(i, n);
}

void AIModuleMessage::setRecipient(int i, char* n) {
    this->recipient.setID(i, n);
}

AIModule::AIModule()
    : idValue("", -1),
      playerNumberValue(-1),
      runningValue(0),
      pausedValue(0),
      logHistoryValue(0),
      logCommonHistoryValue(0),
      historyLogFile(0),
      intelligenceLevelValue(5),
      priorityValue(50),
      processFrameValue(0) {
    strcpy(this->playerNameValue, "Unknown");
}

AIModule::AIModule(char* n, int i, int pN, void* pW)
    : idValue(n, i),
      playerNumberValue(pN),
      runningValue(0),
      pausedValue(0),
      logHistoryValue(0),
      logCommonHistoryValue(0),
      historyLogFile(0),
      intelligenceLevelValue(5),
      priorityValue(50),
      processFrameValue(0) {
    strcpy(playerNameValue, "");
}

struct _iobuf;
extern int __cdecl fclose(_iobuf*);

AIModule::~AIModule() {
    if (logCommonHistoryValue != 0 && commonHistoryLogFile != 0) {
        fclose(commonHistoryLogFile);
        commonHistoryLogFile = 0;
    }
}

AIModuleID AIModule::id() const {
    return this->idValue;
}

int AIModule::idNumber() const { return this->idValue.id; }

int AIModule::playerNumber() const { return this->playerNumberValue; }

char* AIModule::playerName() const { return (char*)this->playerNameValue; }

void AIModule::setPlayer(int i, char* n) {
    this->playerNumberValue = i;
    if (n != 0) {
        strncpy(this->playerNameValue, n, 63);
        return;
    }
    strcpy(this->playerNameValue, "Unknown");
}

void AIModule::start() { this->runningValue = 1; }

void AIModule::stop() { this->runningValue = 0; }

void AIModule::toggleRun() {
    if (runningValue)
        runningValue = 0;
    else
        runningValue = 1;
}

void AIModule::togglePause() {
    if (pausedValue)
        pausedValue = 0;
    else
        pausedValue = 1;
}

void AIModule::step(void) {}

int AIModule::running() const { return this->runningValue; }

int AIModule::paused() const { return this->pausedValue; }

int AIModule::loggingHistory() const { return this->logHistoryValue; }

void AIModule::setLogHistory(int v) {}

void AIModule::toggleLogHistory(void) {}

int AIModule::loggingCommonHistory() const { return this->logCommonHistoryValue; }

void AIModule::setLogCommonHistory(int v) {
    this->logCommonHistoryValue = v;
    if (v != 0 && commonHistoryLogFile == 0) {
        commonHistoryLogFile = fopen("c:\\aoeai.txt", "wa");
        time_t clock;
        time(&clock);
        this->logCommonHistory("Common AI History File Started %s", asctime(localtime(&clock)));
        this->logCommonHistory("");
        return;
    }
    if (v == 0 && commonHistoryLogFile != 0) {
        fclose(commonHistoryLogFile);
        commonHistoryLogFile = 0;
    }
}

void AIModule::toggleLogCommonHistory(void) {}

void AIModule::setHistoryFilename(char *f) {}

int AIModule::intelligenceLevel() const { return this->intelligenceLevelValue; }

int AIModule::setIntelligenceLevel(int v) {
    this->intelligenceLevelValue = v;
    if (v < 1) {
        this->intelligenceLevelValue = 1;
        return 0;
    }
    if (v > 10) {
        this->intelligenceLevelValue = 10;
        return 0;
    }
    return 1;
}

int AIModule::priority() const { return this->priorityValue; }

int AIModule::setPriority(int v) {
    priorityValue = v;
    if (v < 1) {
        priorityValue = 1;
        return 0;
    }
    if (v > 100) {
        priorityValue = 100;
        return 0;
    }
    return 1;
}

int AIModule::incrementPriority(int v) {
    return setPriority(priorityValue + v);
}

int AIModule::decrementPriority(int v) {
    return setPriority(priorityValue - v);
}

int AIModule::sendMessage(AIModuleMessage *m, int processNow) { return 0; }

void AIModule::receiveMessage(AIModuleMessage *m) {}

int AIModule::processMessage(AIModuleMessage *m) { return 0; }

int AIModule::update(int timeLimit) { return 0; }

void AIModule::setCallbackMessage(AIModuleMessage *m) {}

int AIModule::messageLimit() { return 0; }

void AIModule::setMessageLimit(int l) {}

int AIModule::callbackLimit() { return 0; }

void AIModule::setCallbackLimit(int l) {}

int AIModule::messageTimeout() { return 0; }

void AIModule::setMessageTimeout(int t) {}

int AIModule::purgeMessages(AIModuleID s) { return 0; }

int AIModule::purgeMessagesWithID(AIModuleID s, int i) {
    return 0;
}

int AIModule::purgeMessagesWithPriorityBelow(AIModuleID s, int p) {
    return 0;
}

int AIModule::purgeMessagesWithData(AIModuleID s, int i, int n, long d) {
    return 0;
}

int AIModule::purgeCallbacks(AIModuleID s) {
    return 0;
}

int AIModule::purgeCallbacksWithID(AIModuleID s, int i) { return 0; }

int AIModule::purgeCallbacksWithPriorityBelow(AIModuleID s, int p) {
    return 0;
}

int AIModule::purgeCallbacksWithData(AIModuleID s, int i, int n, long d) {
    return 0;
}

void AIModule::checkMessageLimit(void) {}

void AIModule::checkCallbackLimit(void) {}

int AIModule::filterOutMessage(AIModuleMessage *m) { return 0; }

void AIModule::logHistory(char* textIn, ...) {}

void AIModule::logCommonHistory(char* textIn, ...) {
    char textOut[1024];

    if (specificAIPlayerToLog != -1 && specificAIPlayerToLog != this->playerNumberValue) {
        return;
    }
    if (commonHistoryLogFile == 0) {
        return;
    }

    va_list args;
    va_start(args, textIn);
    vsprintf(textOut, textIn, args);
    va_end(args);

    if (strlen(textOut) != 0) {
        fprintf(commonHistoryLogFile, "P#%d %s: %s\n", this->playerNumberValue, this->idValue.name, textOut);
    } else {
        fprintf(commonHistoryLogFile, "P#%d\n", this->playerNumberValue);
    }
    fflush(commonHistoryLogFile);
}

void AIModule::logDebug(char* textIn, ...) {}

int AIModule::processFrame() { return this->processFrameValue; }

void AIModule::incrementProcessFrame() {
    int frame;

    frame = this->processFrameValue + 1;
    this->processFrameValue = frame;
    if (frame == 0x7FFFFFFF) {
        this->processFrameValue = 0;
    }
}

int AIModule::timeDifference(AIModuleMessage *m) { return 0; }
