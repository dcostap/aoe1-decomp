#pragma once
#include "common.h"

class AIModule : public AIModuleID {
public:
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

    virtual int loggingHistory();                           // vt0[1]+0x4=0x40E4E0 | vt0[21]+0x54=0x40E4E0 | vt0[40]+0xA0=0x40E4E0 | vt0[55]+0xDC=0x40E4E0 | vt0[70]+0x118=0x40E4E0 | vt0[86]+0x158=0x40E4E0
    virtual void setLogHistory(int param_1);                // vt0[2]+0x8=0x40E4F0 | vt0[22]+0x58=0x40E4F0 | vt0[41]+0xA4=0x40E4F0 | vt0[56]+0xE0=0x40E4F0 | vt0[71]+0x11C=0x40E4F0 | vt0[87]+0x15C=0x40E4F0
    virtual void toggleLogHistory();                        // vt0[3]+0xC=0x40E500 | vt0[23]+0x5C=0x40E500 | vt0[42]+0xA8=0x40E500 | vt0[57]+0xE4=0x40E500 | vt0[72]+0x120=0x40E500 | vt0[88]+0x160=0x40E500
    virtual void setHistoryFilename(char* param_1);         // vt0[4]+0x10=0x40E5D0 | vt0[24]+0x60=0x40E5D0 | vt0[43]+0xAC=0x40E5D0 | vt0[58]+0xE8=0x40E5D0 | vt0[73]+0x124=0x40E5D0 | vt0[89]+0x164=0x40E5D0
    virtual int loggingCommonHistory();                     // vt0[5]+0x14=0x40E510 | vt0[25]+0x64=0x40E510 | vt0[44]+0xB0=0x40E510 | vt0[59]+0xEC=0x40E510 | vt0[74]+0x128=0x40E510 | vt0[90]+0x168=0x40E510
    virtual void setLogCommonHistory(int param_1);          // vt0[6]+0x18=0x40E520 | vt0[26]+0x68=0x40E520 | vt0[45]+0xB4=0x40E520 | vt0[60]+0xF0=0x40E520 | vt0[75]+0x12C=0x40E520 | vt0[91]+0x16C=0x40E520
    virtual void toggleLogCommonHistory();                  // vt0[7]+0x1C=0x40E5C0 | vt0[27]+0x6C=0x40E5C0 | vt0[46]+0xB8=0x40E5C0 | vt0[61]+0xF4=0x40E5C0 | vt0[76]+0x130=0x40E5C0 | vt0[92]+0x170=0x40E5C0
    virtual int loadState(char* param_1);                   // vt0[8]+0x20=0x4087F0 | vt0[28]+0x70=0x4087F0 | vt0[47]+0xBC=0x4087F0 | vt0[62]+0xF8=0x4087F0 | vt0[77]+0x134=0x4087F0 | vt0[93]+0x174=0x4087F0
    virtual int saveState(char* param_1);                   // vt0[9]+0x24=0x408800 | vt0[29]+0x74=0x408800 | vt0[48]+0xC0=0x408800 | vt0[63]+0xFC=0x408800 | vt0[78]+0x138=0x408800 | vt0[94]+0x178=0x408800
    virtual int gleanState(int param_1);                    // vt0[10]+0x28=0x408810 | vt0[30]+0x78=0x408810 | vt0[49]+0xC4=0x408810 | vt0[64]+0x100=0x408810 | vt0[79]+0x13C=0x408810 | vt0[95]+0x17C=0x408810
    virtual int processMessage(AIModuleMessage* param_1);   // vt0[11]+0x2C=0x40E6E0 | vt0[31]+0x7C=0x40E6E0 | vt0[65]+0x104=0x40E6E0 | vt0[80]+0x140=0x40E6E0 | vt0[96]+0x180=0x40E6E0
    virtual int update(int param_1);                        // vt0[12]+0x30=0x40E6F0 | vt0[32]+0x80=0x40E6F0 | vt0[66]+0x108=0x40E6F0 | vt0[81]+0x144=0x40E6F0 | vt0[97]+0x184=0x40E6F0
    virtual void setCallbackMessage(AIModuleMessage* param_1); // vt0[13]+0x34=0x40E700 | vt0[33]+0x84=0x40E700 | vt0[67]+0x10C=0x40E700 | vt0[82]+0x148=0x40E700 | vt0[98]+0x188=0x40E700
    virtual int filterOutMessage(AIModuleMessage* param_1); // vt0[14]+0x38=0x40E810 | vt0[34]+0x88=0x40E810 | vt0[68]+0x110=0x40E810 | vt0[83]+0x14C=0x40E810 | vt0[99]+0x18C=0x40E810
    AIModule();
    AIModule(char* param_1, int param_2, int param_3, void* param_4);
    ~AIModule();
    AIModuleID* id();
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

class AIModuleID {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    int id;                                  // 0x4
    char name[64];                           // 0x8

    AIModuleID(char* param_1, int param_2);
    ~AIModuleID();
    void setID(int param_1, char* param_2);
};

static_assert(sizeof(AIModuleID) == 0x48, "AIModuleID Size Mismatch");

class AIModuleMessage : public AIModuleID {
public:
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
    ~AIModuleMessage();
    void setText(char* param_1);
    void setSender(int param_1, char* param_2);
    void setRecipient(int param_1, char* param_2);
};

static_assert(sizeof(AIModuleMessage) == 0x138, "AIModuleMessage Size Mismatch");

