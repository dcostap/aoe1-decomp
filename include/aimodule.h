#ifndef AOE1_AIMODULE_H
#define AOE1_AIMODULE_H

#include <stdio.h>

class AIModuleMessage;

class AIModuleID {
  public:
    virtual ~AIModuleID();
    AIModuleID(char* n, int i);
    void setID(int i, char* n);

    int id;
    char name[64];
};

class AIModuleMessage {
  public:
    virtual ~AIModuleMessage();
    AIModuleMessage();
    AIModuleMessage(int s, int r, int i, int p, long d1, long d2, long d3, AIModuleMessage* c, int t);
    AIModuleMessage(AIModuleMessage* m);
    void setText(char* t);
    void setSender(int i, char* n);
    void setRecipient(int i, char* n);

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
    virtual void setLogHistory(int v);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* f);
    virtual int loggingCommonHistory() const;
    virtual void setLogCommonHistory(int v);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*) {
        return 0;
    }
    virtual int saveState(char*) {
        return 0;
    }
    virtual int gleanState(int) {
        return 0;
    }
    virtual int processMessage(AIModuleMessage* m);
    virtual int update(int timeLimit);
    virtual void setCallbackMessage(AIModuleMessage* m);

    AIModule();
    AIModule(char* n, int i, int pN, void* pW);
    AIModuleID id() const;
    int idNumber() const;
    int playerNumber() const;
    char* playerName() const;
    void setPlayer(int i, char* n);
    void start();
    void stop();
    void toggleRun();
    void togglePause();
    void step();
    int running() const;
    int paused() const;
    int intelligenceLevel() const;
    int setIntelligenceLevel(int v);
    int priority() const;
    int setPriority(int v);
    int incrementPriority(int v);
    int decrementPriority(int v);
    int sendMessage(AIModuleMessage* m, int processNow);
    void receiveMessage(AIModuleMessage* m);
    int messageLimit();
    void setMessageLimit(int l);
    int callbackLimit();
    void setCallbackLimit(int l);
    int messageTimeout();
    void setMessageTimeout(int t);
    int purgeMessages(AIModuleID s);
    int purgeMessagesWithID(AIModuleID s, int i);
    int purgeMessagesWithPriorityBelow(AIModuleID s, int p);
    int purgeMessagesWithData(AIModuleID s, int i, int n, long d);
    int purgeCallbacks(AIModuleID s);
    int purgeCallbacksWithID(AIModuleID s, int i);
    int purgeCallbacksWithPriorityBelow(AIModuleID s, int p);
    int purgeCallbacksWithData(AIModuleID s, int i, int n, long d);
    void logHistory(char* textIn, ...);
    void logCommonHistory(char* textIn, ...);
    void logDebug(char* textIn, ...);

  protected:
    virtual int filterOutMessage(AIModuleMessage* m);
    void checkMessageLimit();
    void checkCallbackLimit();
    int processFrame();
    void incrementProcessFrame();
    int timeDifference(AIModuleMessage* m);

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
