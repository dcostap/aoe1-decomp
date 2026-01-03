#pragma once
#include "../common.h"

class AIModuleID {
public:
    int id;                                  // 0x4
    char name[64];                           // 0x8

    AIModuleID(char* param_1, int param_2);
    virtual ~AIModuleID();
    virtual void setID(int param_1, char* param_2);
};

static_assert(sizeof(AIModuleID) == 0x48, "AIModuleID Size Mismatch");
static_assert(offsetof(AIModuleID, name) == 0x8, "AIModuleID Offset Mismatch");

class AIModuleMessage {
public:
    // 0x0 is vtable (implied by virtuals)
    int id;                                  // 0x4
    char text[128];                          // 0x8  <-- DIFFERENT than AIModuleID
    int priority;                            // 0x88
    AIModuleID sender;                       // 0x8C
    AIModuleID recipient;                    // 0xD4
    long data1;                              // 0x11C
    long data2;                              // 0x120
    long data3;                              // 0x124
    AIModuleMessage* callbackMessage;        // 0x128
    int timeStamp;                           // 0x12C
    AIModuleMessage* next;                   // 0x130
    AIModuleMessage* prev;                   // 0x134

    AIModuleMessage();
    AIModuleMessage(int param_1, int param_2, int param_3, int param_4, long param_5, long param_6, long param_7, AIModuleMessage* param_8, int param_9);
    AIModuleMessage(AIModuleMessage* param_1);
    virtual ~AIModuleMessage();
    virtual void setText(char* param_1);
    virtual void setSender(int param_1, char* param_2);
    virtual void setRecipient(int param_1, char* param_2);
};

static_assert(sizeof(AIModuleMessage) == 0x138, "AIModuleMessage Size Mismatch");
static_assert(offsetof(AIModuleMessage, prev) == 0x134, "AIModuleMessage Offset Mismatch");

class AIModule {
public:
    AIModuleID idValue;                      // 0x04
    int playerNumberValue;                   // 0x4C
    char playerNameValue[64];                // 0x50
    int runningValue;                        // 0x90
    int pausedValue;                         // 0x94
    int logHistoryValue;                     // 0x98
    int logCommonHistoryValue;               // 0x9C
    _iobuf* historyLogFile;                  // 0xA0
    char historyLogFilename[64];             // 0xA4
    int intelligenceLevelValue;              // 0xE4
    int priorityValue;                       // 0xE8
    int processFrameValue;                   // 0xEC

    virtual int loadState(char* param_1);
    virtual int saveState(char* param_1);
    virtual int gleanState(int param_1);
    AIModule();
    AIModule(char* param_1, int param_2, int param_3, void* param_4);
    virtual ~AIModule();
    virtual AIModuleID* id(AIModuleID* __return_storage_ptr__);
    virtual int idNumber();
    virtual int playerNumber();
    virtual char* playerName();
    virtual void setPlayer(int param_1, char* param_2);
    virtual void start();
    virtual void stop();
    virtual void toggleRun();
    virtual void togglePause();
    virtual void step();
    virtual int running();
    virtual int paused();
    virtual int loggingHistory();
    virtual void setLogHistory(int param_1);
    virtual void toggleLogHistory();
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int param_1);
    virtual void toggleLogCommonHistory();
    virtual void setHistoryFilename(char* param_1);
    virtual int intelligenceLevel();
    virtual int setIntelligenceLevel(int param_1);
    virtual int priority();
    virtual int setPriority(int param_1);
    virtual int incrementPriority(int param_1);
    virtual int decrementPriority(int param_1);
    virtual int sendMessage(AIModuleMessage* param_1, int param_2);
    virtual void receiveMessage(AIModuleMessage* param_1);
    virtual int processMessage(AIModuleMessage* param_1);
    virtual int update(int param_1);
    virtual void setCallbackMessage(AIModuleMessage* param_1);
    virtual int messageLimit();
    virtual void setMessageLimit(int param_1);
    virtual int callbackLimit();
    virtual void setCallbackLimit(int param_1);
    virtual int messageTimeout();
    virtual void setMessageTimeout(int param_1);
    virtual int purgeMessages(AIModuleID param_1);
    virtual int purgeMessagesWithID(AIModuleID param_1, int param_2);
    virtual int purgeMessagesWithPriorityBelow(AIModuleID param_1, int param_2);
    virtual int purgeMessagesWithData(AIModuleID param_1, int param_2, int param_3, long param_4);
    virtual int purgeCallbacks(AIModuleID param_1);
    virtual int purgeCallbacksWithID(AIModuleID param_1, int param_2);
    virtual int purgeCallbacksWithPriorityBelow(AIModuleID param_1, int param_2);
    virtual int purgeCallbacksWithData(AIModuleID param_1, int param_2, int param_3, long param_4);
    virtual void checkMessageLimit();
    virtual void checkCallbackLimit();
    virtual int filterOutMessage(AIModuleMessage* param_1);
    virtual void logHistory(char* param_1);
    virtual void logCommonHistory(char* param_1);
    virtual void logDebug(char* param_1);
    virtual int processFrame();
    virtual void incrementProcessFrame();
    virtual int timeDifference(AIModuleMessage* param_1);
};

static_assert(sizeof(AIModule) == 0xF0, "AIModule Size Mismatch");
static_assert(offsetof(AIModule, processFrameValue) == 0xEC, "AIModule Offset Mismatch");

int AIModule::loadState(char* param_1) {
    /* TODO: Stub */
//                              int __thiscall loadState(AIModule * this, char * param_1)
//              int               EAX:4          <RETURN>
//              AIModule *        ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1
//                               ?loadState@AIModule@@UAEHPAD@Z                               XREF[19]:    0056e758(*), 0056e7c0(*),
//                               AIModule::loadState                                                       0056e838(*), 0056e878(*),
//                                                                                                         0056e8b8(*), 0056e8f8(*),
//                                                                                                         0056e950(*), 0056e9a8(*),
//                                                                                                         0056e9f8(*), 0056ea38(*),
//                                                                                                         0056ea78(*), 0056eab8(*),
//                                                                                                         00575460(*), 005754c0(*),
//                                                                                                         00575530(*), 005755e8(*),
//                                                                                                         00575658(*), 005756b8(*),
//                                                                                                         005757a8(*)
//                              aimodule.h:156 (5)
//         004087f0     XOR        EAX,EAX
//         004087f2     RET        0x4
//         004087f5     ??         90h
//         004087f6     NOP
//         004087f7     NOP
//         004087f8     NOP
//         004087f9     NOP
//         004087fa     NOP
//         004087fb     NOP
//         004087fc     NOP
//         004087fd     NOP
//         004087fe     NOP
//         004087ff     NOP
    return 0;
}

int AIModule::saveState(char* param_1) {
    /* TODO: Stub */
//                              int __thiscall saveState(AIModule * this, char * param_1)
//              int               EAX:4          <RETURN>
//              AIModule *        ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1
//                               ?saveState@AIModule@@UAEHPAD@Z                               XREF[19]:    0056e75c(*), 0056e7c4(*),
//                               AIModule::saveState                                                       0056e83c(*), 0056e87c(*),
//                                                                                                         0056e8bc(*), 0056e8fc(*),
//                                                                                                         0056e954(*), 0056e9ac(*),
//                                                                                                         0056e9fc(*), 0056ea3c(*),
//                                                                                                         0056ea7c(*), 0056eabc(*),
//                                                                                                         00575464(*), 005754c4(*),
//                                                                                                         00575534(*), 005755ec(*),
//                                                                                                         0057565c(*), 005756bc(*),
//                                                                                                         005757ac(*)
//                              aimodule.h:157 (5)
//         00408800     XOR        EAX,EAX
//         00408802     RET        0x4
//         00408805     ??         90h
//         00408806     NOP
//         00408807     NOP
//         00408808     NOP
//         00408809     NOP
//         0040880a     NOP
//         0040880b     NOP
//         0040880c     NOP
//         0040880d     NOP
//         0040880e     NOP
//         0040880f     NOP
    return 0;
}

int AIModule::gleanState(int param_1) {
    /* TODO: Stub */
//                              int __thiscall gleanState(AIModule * this, int param_1)
//              int               EAX:4          <RETURN>
//              AIModule *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?gleanState@AIModule@@UAEHH@Z                                XREF[19]:    0056e760(*), 0056e7c8(*),
//                               AIModule::gleanState                                                      0056e840(*), 0056e880(*),
//                                                                                                         0056e8c0(*), 0056e900(*),
//                                                                                                         0056e958(*), 0056e9b0(*),
//                                                                                                         0056ea00(*), 0056ea40(*),
//                                                                                                         0056ea80(*), 0056eac0(*),
//                                                                                                         00575468(*), 005754c8(*),
//                                                                                                         00575538(*), 005755f0(*),
//                                                                                                         00575660(*), 005756c0(*),
//                                                                                                         005757b0(*)
//                              aimodule.h:158 (5)
//         00408810     XOR        EAX,EAX
//         00408812     RET        0x4
//         00408815     ??         90h
//         00408816     NOP
//         00408817     NOP
//         00408818     NOP
//         00408819     NOP
//         0040881a     NOP
//         0040881b     NOP
//         0040881c     NOP
//         0040881d     NOP
//         0040881e     NOP
//         0040881f     NOP
    return 0;
}

