#include "../include/aimodule.h"

#include <stdarg.h>
#include <string.h>
#include <time.h>

AIModuleID::AIModuleID(char* name_str, int id_value) {
    this->id = id_value;

    if (name_str != NULL) {
        strncpy(this->name, name_str, 0x3F);
    } else {
        strcpy(this->name, "");
    }
}

AIModuleID::~AIModuleID() {}

void AIModuleID::setID(int param_1, char* param_2) {
    this->id = param_1;
    if (param_2 != 0) {
        strncpy(this->name, param_2, 0x3F);
        return;
    }
    strcpy(this->name, "");
}

AIModuleMessage::AIModuleMessage()
    : id(0),
      priority(0),
      sender((char*)0x57F4B0, 0),
      recipient((char*)0x57F4A4, 0),
      data1(0),
      data2(0),
      data3(0),
      callbackMessage(0),
      timeStamp(0),
      next(0),
      prev(0)
{
    strcpy(text, (char*)0x592A40);
}

AIModuleMessage::AIModuleMessage(int sender_id, int recipient_id, int msg_id, int msg_priority,
                                 long p5, long p6, long p7, AIModuleMessage* callback, int timestamp)
    : id(msg_id),
      priority(msg_priority),
      sender((char*)0x592A40, sender_id),
      recipient((char*)0x592A40, recipient_id),
      data1(p5),
      data2(p6),
      data3(p7),
      callbackMessage(callback),
      timeStamp(timestamp)
{
    strcpy(this->text, (char*)0x592A40);
}

AIModuleMessage::AIModuleMessage(AIModuleMessage* other)
    : id(other->id),
      priority(other->priority),
      sender(other->sender.name, other->sender.id),
      recipient(other->recipient.name, other->recipient.id),
      data1(other->data1),
      data2(other->data2),
      data3(other->data3),
      callbackMessage(other->callbackMessage),
      timeStamp(other->timeStamp),
      next(0),
      prev(0)
{
    this->setText(other->text);
}

AIModuleMessage::~AIModuleMessage()
{
    delete this->callbackMessage;
}

void AIModuleMessage::setText(char* text)
{
    if (text != 0) {
        strncpy(this->text, text, 0x7F);
        return;
    }

    strcpy(this->text, "");
}

void AIModuleMessage::setSender(int a, char* b) {
    this->sender.setID(a, b);
}

void AIModuleMessage::setRecipient(int a, char* b) {
    this->recipient.setID(a, b);
}

AIModule::AIModule()
    : idValue((char*)0x592A40, -1),
      playerNumberValue(-1),
      runningValue(0),
      pausedValue(0),
      logHistoryValue(0),
      logCommonHistoryValue(0),
      historyLogFile(0),
      intelligenceLevelValue(5),
      priorityValue(50),
      processFrameValue(0) {
    strcpy(this->playerNameValue, (const char*)0x57F074);
}

AIModule::AIModule(char* name, int id, int player, void* owner)
    : idValue(name, id),
      playerNumberValue(player),
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
extern _iobuf* DAT_00592A44;

AIModule::~AIModule() {
    if (logCommonHistoryValue != 0 && DAT_00592A44 != 0) {
        fclose(DAT_00592A44);
        DAT_00592A44 = 0;
    }
}

AIModuleID AIModule::id() const {
    return this->idValue;
}

int AIModule::idNumber() const { return this->idValue.id; }

int AIModule::playerNumber() const { return this->playerNumberValue; }

char* AIModule::playerName() const { return (char*)this->playerNameValue; }

extern char s_Unknown[];

void AIModule::setPlayer(int playerNumber, char* playerName) {
    this->playerNumberValue = playerNumber;
    if (playerName != 0) {
        strncpy(this->playerNameValue, playerName, 0x3F);
        return;
    }
    strcpy(this->playerNameValue, s_Unknown);
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

void AIModule::step(void)
{
}

int AIModule::running() const { return this->runningValue; }

int AIModule::paused() const { return this->pausedValue; }

int AIModule::loggingHistory() const { return this->logHistoryValue; }

void AIModule::setLogHistory(int a) {}

void AIModule::toggleLogHistory(void)
{
}

int AIModule::loggingCommonHistory() const { return this->logCommonHistoryValue; }

extern FILE* commonHistoryLogFile;
extern char emptyString[];

void AIModule::setLogCommonHistory(int on)
{
    this->logCommonHistoryValue = on;
    FILE* f = commonHistoryLogFile;
    if (on != 0) {
        if (f == 0) {
            commonHistoryLogFile = fopen("c:\\aoeai.txt", "wa");
            time_t t;
            time(&t);
            this->logCommonHistory("Common AI History File Started %s", asctime(localtime(&t)));
            this->logCommonHistory(emptyString);
            return;
        }
    }
    if (this->logCommonHistoryValue == 0) {
        if (f != 0) {
            fclose(f);
            commonHistoryLogFile = 0;
        }
    }
}

void AIModule::toggleLogCommonHistory(void)
{
}

void AIModule::setHistoryFilename(char *a) {}

int AIModule::intelligenceLevel() const { return this->intelligenceLevelValue; }

int AIModule::setIntelligenceLevel(int param_1) {
    this->intelligenceLevelValue = param_1;
    if (param_1 < 1) {
        this->intelligenceLevelValue = 1;
        return 0;
    }
    if (param_1 > 10) {
        this->intelligenceLevelValue = 10;
        return 0;
    }
    return 1;
}

int AIModule::priority() const { return this->priorityValue; }

int AIModule::setPriority(int value) {
    priorityValue = value;
    if (value < 1) {
        priorityValue = 1;
        return 0;
    }
    if (value > 100) {
        priorityValue = 100;
        return 0;
    }
    return 1;
}

int AIModule::incrementPriority(int delta) {
    return setPriority(priorityValue + delta);
}

int AIModule::decrementPriority(int delta) {
    return setPriority(priorityValue - delta);
}

int AIModule::sendMessage(AIModuleMessage *a, int b) { return 0; }

void AIModule::receiveMessage(AIModuleMessage *a) {}

int AIModule::processMessage(AIModuleMessage *a) { return 0; }

int AIModule::update(int a) { return 0; }

void AIModule::setCallbackMessage(AIModuleMessage *a) {}

int AIModule::messageLimit() { return 0; }

void AIModule::setMessageLimit(int a) {}

int AIModule::callbackLimit() { return 0; }

void AIModule::setCallbackLimit(int a) {}

int AIModule::messageTimeout() { return 0; }

void AIModule::setMessageTimeout(int a) {}

int AIModule::purgeMessages(AIModuleID p) { return 0; }

int AIModule::purgeMessagesWithID(AIModuleID p, int id) {
    return 0;
}

int AIModule::purgeMessagesWithPriorityBelow(AIModuleID p, int priority) {
    return 0;
}

int AIModule::purgeMessagesWithData(AIModuleID id, int type, int priority, long data) {
    return 0;
}

int AIModule::purgeCallbacks(AIModuleID p) {
    return 0;
}

int AIModule::purgeCallbacksWithID(AIModuleID p, int id) { return 0; }

int AIModule::purgeCallbacksWithPriorityBelow(AIModuleID p, int priority) {
    return 0;
}

int AIModule::purgeCallbacksWithData(AIModuleID id, int type, int priority, long data) {
    return 0;
}

void AIModule::checkMessageLimit(void)
{
}

void AIModule::checkCallbackLimit(void)
{
}

int AIModule::filterOutMessage(AIModuleMessage *a) { return 0; }

void AIModule::logHistory(char*, ...)
{
}

void AIModule::logCommonHistory(char* fmt, ...)
{
    char textOut[1024];

    if (*(int*)0x57F9FC != -1 && *(int*)0x57F9FC != this->playerNumberValue) {
        return;
    }
    if (*(FILE**)0x592A44 == 0) {
        return;
    }

    va_list args;
    va_start(args, fmt);
    vsprintf(textOut, fmt, args);
    va_end(args);

    if (strlen(textOut) != 0) {
        fprintf(*(FILE**)0x592A44, "P#%d %s: %s\n", this->playerNumberValue, this->idValue.name, textOut);
    } else {
        fprintf(*(FILE**)0x592A44, "P#%d\n", this->playerNumberValue);
    }
    fflush(*(FILE**)0x592A44);
}

void AIModule::logDebug(char*, ...)
{
}

int AIModule::processFrame() { return this->processFrameValue; }

void AIModule::incrementProcessFrame() {
    int frame;

    frame = this->processFrameValue + 1;
    this->processFrameValue = frame;
    if (frame == 0x7FFFFFFF) {
        this->processFrameValue = 0;
    }
}

int AIModule::timeDifference(AIModuleMessage *a) { return 0; }
