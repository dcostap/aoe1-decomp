// tried the direct destructor shape; the remaining gap stayed in the vtable/immediate and member-dtor basin
// tried the same body with a small /GX rsp; that changed the prolog too much and did not close the mismatch

struct _iobuf;
class AIModuleID {
public:
    int id;
    char name[64];

    virtual ~AIModuleID();
};

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);

    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    _iobuf* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

extern _iobuf* commonHistoryLogFile;
extern int fclose(_iobuf*);

AIModule::~AIModule() {
    *(void**)this = (void*)0x0040E2B0;
    if (logCommonHistoryValue != 0 && commonHistoryLogFile != 0) {
        fclose(commonHistoryLogFile);
        commonHistoryLogFile = 0;
    }
    idValue.~AIModuleID();
}
