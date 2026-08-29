#ifndef AOE1_AIMODULE_H
#define AOE1_AIMODULE_H

#include <stdio.h>

class AIModuleMessage;

class AIModuleID {
public:
    virtual ~AIModuleID();
    AIModuleID(char*, int);
    void setID(int, char*);

    int id;
    char name[64];
};

class AIModuleMessage {
public:
    virtual ~AIModuleMessage();
    AIModuleMessage();
    AIModuleMessage(int, int, int, int, long, long, long, AIModuleMessage*, int);
    AIModuleMessage(AIModuleMessage*);
    void setText(char*);
    void setSender(int, char*);
    void setRecipient(int, char*);

    int id;
    char text[128];
    int priority;
    AIModuleID sender;
    AIModuleID recipient;
    long data1;
    long data2;
    long data3;
    AIModuleMessage* callbackMessage;
    int timeStamp;
    AIModuleMessage* next;
    AIModuleMessage* prev;
};

typedef char aimodule_message_size_check[(sizeof(AIModuleMessage) == 0x138) ? 1 : -1];

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory() const;
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory() const;
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*) { return 0; }
    virtual int saveState(char*) { return 0; }
    virtual int gleanState(int) { return 0; }
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);

    AIModule();
    AIModule(char*, int, int, void*);
    AIModuleID id() const;
    int idNumber() const;
    int playerNumber() const;
    char* playerName() const;
    void setPlayer(int, char*);
    void start();
    void stop();
    void toggleRun();
    void togglePause();
    void step();
    int running() const;
    int paused() const;
    int intelligenceLevel() const;
    int setIntelligenceLevel(int);
    int priority() const;
    int setPriority(int);
    int incrementPriority(int);
    int decrementPriority(int);
    int sendMessage(AIModuleMessage*, int);
    void receiveMessage(AIModuleMessage*);
    int messageLimit();
    void setMessageLimit(int);
    int callbackLimit();
    void setCallbackLimit(int);
    int messageTimeout();
    void setMessageTimeout(int);
    int purgeMessages(AIModuleID);
    int purgeMessagesWithID(AIModuleID, int);
    int purgeMessagesWithPriorityBelow(AIModuleID, int);
    int purgeMessagesWithData(AIModuleID, int, int, long);
    int purgeCallbacks(AIModuleID);
    int purgeCallbacksWithID(AIModuleID, int);
    int purgeCallbacksWithPriorityBelow(AIModuleID, int);
    int purgeCallbacksWithData(AIModuleID, int, int, long);
    void logHistory(char*, ...);
    void logCommonHistory(char*, ...);
    void logDebug(char*, ...);

protected:
    virtual int filterOutMessage(AIModuleMessage*);
    void checkMessageLimit();
    void checkCallbackLimit();
    int processFrame();
    void incrementProcessFrame();
    int timeDifference(AIModuleMessage*);

    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    FILE* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

typedef char aimodule_size_check[(sizeof(AIModule) == 0xF0) ? 1 : -1];

#endif
