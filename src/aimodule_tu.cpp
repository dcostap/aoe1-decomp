// Authentic PDB-ordered owner wrapper for C:\\msdev\\work\\age1_x1\\aimodule.cpp.
//
// The class declarations below recover the reviewed AIModule hierarchy.  They
// keep the real virtual surfaces and object sizes in one TU context.  Individual
// owner files retain standalone declarations for focused checks.

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

struct _iobuf;
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
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);
    virtual int filterOutMessage(AIModuleMessage*);

    AIModule();
    AIModule(char*, int, int, void*);
    AIModuleID id() const;
    int idNumber() const;
    int playerNumber() const;
    char* playerName();
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
protected:
    void checkMessageLimit();
    void checkCallbackLimit();
    void logHistory(char*, ...);
    void logCommonHistory(char*, ...);
    void logDebug(char*, ...);
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

#define AOE1_AIMODULE_TU_CONTEXT 1

#include "matching/0040DD90_AIModuleID.cpp"
#include "matching/0040DE10_AIModuleID.cpp"
#include "matching/0040DE20_setID.cpp"
#include "matching/0040DE70_AIModuleMessage.cpp"
#include "matching/0040DF50_AIModuleMessage.cpp"
#include "matching/0040E030_AIModuleMessage.cpp"
#include "matching/0040E120_AIModuleMessage.cpp"
#include "matching/0040E190_setText.cpp"
#include "matching/0040E1E0_setSender.cpp"
#include "matching/0040E200_setRecipient.cpp"
#include "matching/0040E220_AIModule.cpp"
#include "matching/0040E2D0_AIModule.cpp"
#include "matching/0040E360_AIModule.cpp"
#include "matching/0040E3A0_id.cpp"
#include "matching/0040E3D0_idNumber.cpp"
#include "matching/0040E3E0_playerNumber.cpp"
#include "matching/0040E3F0_playerName.cpp"
#include "matching/0040E400_setPlayer.cpp"
#include "matching/0040E450_start.cpp"
#include "matching/0040E460_stop.cpp"
#include "matching/0040E470_toggleRun.cpp"
#include "matching/0040E490_togglePause.cpp"
#include "matching/0040E4B0_step.cpp"
#include "matching/0040E4C0_running.cpp"
#include "matching/0040E4D0_paused.cpp"
#include "matching/0040E4E0_loggingHistory.cpp"
#include "matching/0040E4F0_setLogHistory.cpp"
#include "matching/0040E500_toggleLogHistory.cpp"
#include "matching/0040E510_loggingCommonHistory.cpp"
#include "accepted_drift/0040E520_setLogCommonHistory.cpp"
#include "matching/0040E5C0_toggleLogCommonHistory.cpp"
#include "matching/0040E5D0_setHistoryFilename.cpp"
#include "matching/0040E5E0_intelligenceLevel.cpp"
#include "matching/0040E5F0_setIntelligenceLevel.cpp"
#include "matching/0040E630_priority.cpp"
#include "matching/0040E640_setPriority.cpp"
#include "matching/0040E680_incrementPriority.cpp"
#include "matching/0040E6A0_decrementPriority.cpp"
#include "matching/0040E6C0_sendMessage.cpp"
#include "matching/0040E6D0_receiveMessage.cpp"
#include "matching/0040E6E0_processMessage.cpp"
#include "matching/0040E6F0_update.cpp"
#include "matching/0040E700_setCallbackMessage.cpp"
#include "matching/0040E710_messageLimit.cpp"
#include "matching/0040E720_setMessageLimit.cpp"
#include "matching/0040E730_callbackLimit.cpp"
#include "matching/0040E740_setCallbackLimit.cpp"
#include "matching/0040E750_messageTimeout.cpp"
#include "matching/0040E760_setMessageTimeout.cpp"
#include "matching/0040E770_purgeMessages.cpp"
#include "matching/0040E780_purgeMessagesWithID.cpp"
#include "matching/0040E790_purgeMessagesWithPriorityBelow.cpp"
#include "matching/0040E7A0_purgeMessagesWithData.cpp"
#include "matching/0040E7B0_purgeCallbacks.cpp"
#include "matching/0040E7C0_purgeCallbacksWithID.cpp"
#include "matching/0040E7D0_purgeCallbacksWithPriorityBelow.cpp"
#include "matching/0040E7E0_purgeCallbacksWithData.cpp"
#include "matching/0040E7F0_checkMessageLimit.cpp"
#include "matching/0040E800_checkCallbackLimit.cpp"
#include "matching/0040E810_filterOutMessage.cpp"
#include "matching/0040E820_logHistory.cpp"
#include "matching/0040E830_logCommonHistory.cpp"
#include "matching/0040E8E0_logDebug.cpp"
#include "matching/0040E8F0_processFrame.cpp"
#include "matching/0040E900_incrementProcessFrame.cpp"
#include "matching/0040E920_timeDifference.cpp"

#undef AOE1_AIMODULE_TU_CONTEXT
