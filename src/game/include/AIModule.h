#pragma once
#include "AIModuleID.h"

class AIModule {
public:
    AIModule();
    AIModule(char* param_1, int param_2, int param_3, void* param_4);

    // Virtuals (best-effort)
    virtual ~AIModule(); // vt[0] (0x0)
    virtual int loggingHistory(); // vt[1] (0x4)
    virtual void setLogHistory(int param_1); // vt[2] (0x8)
    virtual void toggleLogHistory(); // vt[3] (0xC)
    virtual void setHistoryFilename(char* param_1); // vt[4] (0x10)
    virtual int loggingCommonHistory(); // vt[5] (0x14)
    virtual void setLogCommonHistory(int param_1); // vt[6] (0x18)
    virtual void toggleLogCommonHistory(); // vt[7] (0x1C)
    virtual int loadState(char* param_1); // vt[8] (0x20)
    virtual int saveState(char* param_1); // vt[9] (0x24)
    virtual int gleanState(int param_1); // vt[10] (0x28)
    virtual int processMessage(AIModuleMessage* param_1); // vt[11] (0x2C)
    virtual int update(int param_1); // vt[12] (0x30)
    virtual void setCallbackMessage(AIModuleMessage* param_1); // vt[13] (0x34)
    virtual int filterOutMessage(AIModuleMessage* param_1); // vt[14] (0x38)

    AIModuleID id() const;
    int idNumber() const;
    int playerNumber() const;
    char* playerName() const;
    void setPlayer(int param_1, char* param_2);
    void start();
    void stop();
    void toggleRun();
    void togglePause();
    void step();
    int running() const;
    int paused() const;
    int intelligenceLevel() const;
    int setIntelligenceLevel(int param_1);
    int priority() const;
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
    void logHistory(char* param_1, ...);
    void logCommonHistory(char* param_1, ...);
    void logDebug(char* param_1, ...);

protected:
    void checkMessageLimit();
    void checkCallbackLimit();
    int processFrame();
    void incrementProcessFrame();
    int timeDifference(AIModuleMessage* param_1);

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
static_assert(sizeof(AIModule) == 0xF0, "Size mismatch");
