#pragma once
#include "../common.h"

class AIModuleID       {
public:
    int id;                                  // 0x4
    char name[64];                           // 0x8

    AIModuleID(char* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~AIModuleID() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // --- Non-Virtual Members ---
    void setID(int param_1, char* param_2);
};

static_assert(sizeof(AIModuleID) == 0x48, "AIModuleID Size Mismatch");
static_assert(offsetof(AIModuleID, name) == 0x8, "AIModuleID Offset Mismatch");

class AIModuleMessage       {
public:
    int id;                                  // 0x4
    char text[128];                          // 0x8
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

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~AIModuleMessage() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // --- Non-Virtual Members ---
    void setText(char* param_1);
    void setSender(int param_1, char* param_2);
    void setRecipient(int param_1, char* param_2);
};

static_assert(sizeof(AIModuleMessage) == 0x138, "AIModuleMessage Size Mismatch");
static_assert(offsetof(AIModuleMessage, prev) == 0x134, "AIModuleMessage Offset Mismatch");

class AIModule       {
public:
    AIModuleID idValue;                      // 0x4
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

    AIModule();
    AIModule(char* param_1, int param_2, int param_3, void* param_4);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~AIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual int loggingHistory(); // Ghidra: loggingHistory

    // [Slot 02] Offset 0x08 (Override)
    virtual void setLogHistory(int param_1); // Ghidra: setLogHistory

    // [Slot 03] Offset 0x0C (Override)
    virtual void toggleLogHistory(); // Ghidra: toggleLogHistory

    // [Slot 04] Offset 0x10 (Override)
    virtual void setHistoryFilename(char* param_1); // Ghidra: setHistoryFilename

    // [Slot 05] Offset 0x14 (Override)
    virtual int loggingCommonHistory(); // Ghidra: loggingCommonHistory

    // [Slot 06] Offset 0x18 (Override)
    virtual void setLogCommonHistory(int param_1); // Ghidra: setLogCommonHistory

    // [Slot 07] Offset 0x1C (Override)
    virtual void toggleLogCommonHistory(); // Ghidra: toggleLogCommonHistory

    // [Slot 08] Offset 0x20 (Override)
    virtual int loadState(char* param_1); // Ghidra: loadState

    // [Slot 09] Offset 0x24 (Override)
    virtual int saveState(char* param_1); // Ghidra: saveState

    // [Slot 10] Offset 0x28 (Override)
    virtual int gleanState(int param_1); // Ghidra: gleanState

    // [Slot 11] Offset 0x2C (Override)
    virtual int processMessage(AIModuleMessage* param_1); // Ghidra: processMessage

    // [Slot 12] Offset 0x30 (Override)
    virtual int update(int param_1); // Ghidra: update

    // [Slot 13] Offset 0x34 (Override)
    virtual void setCallbackMessage(AIModuleMessage* param_1); // Ghidra: setCallbackMessage

    // [Slot 14] Offset 0x38 (Override)
    virtual int filterOutMessage(AIModuleMessage* param_1); // Ghidra: filterOutMessage

    // --- Non-Virtual Members ---
    AIModuleID* id(AIModuleID* __return_storage_ptr__);
    int idNumber();
    int playerNumber();
    char* playerName();
    void setPlayer(int param_1, char* param_2);
    void start();
    void stop();
    void toggleRun();
    void togglePause();
    void step();
    int running();
    int paused();
    int intelligenceLevel();
    int setIntelligenceLevel(int param_1);
    int priority();
    int setPriority(int param_1);
    int incrementPriority(int param_1);
    int decrementPriority(int param_1);
    int sendMessage(AIModuleMessage* param_1, int param_2);
    void receiveMessage(AIModuleMessage* param_1);
    int messageLimit();
    void setMessageLimit(int param_1);
    int callbackLimit();
    void setCallbackLimit(int param_1);
    int messageTimeout();
    void setMessageTimeout(int param_1);
    int purgeMessages(AIModuleID param_1);
    int purgeMessagesWithID(AIModuleID param_1, int param_2);
    int purgeMessagesWithPriorityBelow(AIModuleID param_1, int param_2);
    int purgeMessagesWithData(AIModuleID param_1, int param_2, int param_3, long param_4);
    int purgeCallbacks(AIModuleID param_1);
    int purgeCallbacksWithID(AIModuleID param_1, int param_2);
    int purgeCallbacksWithPriorityBelow(AIModuleID param_1, int param_2);
    int purgeCallbacksWithData(AIModuleID param_1, int param_2, int param_3, long param_4);
    void checkMessageLimit();
    void checkCallbackLimit();
    void logHistory(char* param_1);
    void logCommonHistory(char* param_1);
    void logDebug(char* param_1);
    int processFrame();
    void incrementProcessFrame();
    int timeDifference(AIModuleMessage* param_1);
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

