// 0040B1A0 ConstructionAIModule::save
// PDB proves tempString[257], tempInt, tempBOOL, and tempFloat.
// The function serializes two sentinel lists with 67 ordered calls.
// Natural explicit statements preserve values, call order, exits, and fault order.
// The original uses a different stack overlap. PDB names no extra object.
// Unsupported aliases, fillers, shifted arrays, and WRITE_ITEM macros stay rejected.
// This policy-clean source keeps the exact 1263-byte boundary and reduces the
// remaining displacement-only difference from 58 bytes to 48 bytes.

#include <string.h>

extern "C" void rge_write(int fd, void* src, int size);

class AIModuleMessage;

class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[64];
};

class BaseItem {
public:
    virtual ~BaseItem();
    int typeIDValue;
    int gameIDValue;
    int uniqueIDValue;
    char nameValue[64];
    float xValue;
    float yValue;
    float zValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int skipValue;

    char* name();
    int typeID();
    int gameID();
    int uniqueID();
    float x();
    float y();
    float z();
    float xSize();
    float ySize();
    float zSize();
    int skip();
};

class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

    virtual ~ConstructionItem();
    int inProgress();
    int built();
    int buildAttempts();
};

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* value);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* value);
    virtual int saveState(char* value);
    virtual int gleanState(int value);
    virtual int processMessage(AIModuleMessage* message);
    virtual int update(int value);
    virtual void setCallbackMessage(AIModuleMessage* message);
    virtual int filterOutMessage(AIModuleMessage* message);

    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

class ConstructionAIModule : public AIModule {
public:
    virtual ~ConstructionAIModule();
    int numberConstructionLotsValue;
    ConstructionItem constructionLots;
    int numberRandomConstructionLotsValue;
    ConstructionItem randomConstructionLots;
    char constructionPlanNameValue[257];
    float xReferencePointValue;
    float yReferencePointValue;
    float zReferencePointValue;
    int mapXSizeValue;
    int mapYSizeValue;
    int lastPlacementReturnCodeValue;
    virtual int save(int fd);
};

int ConstructionAIModule::save(int fd)
{
    char tempString[257];
    int tempInt;
    float tempFloat;
    int tempBOOL;
    ConstructionItem* item;

    rge_write(fd, (void*)&this->numberConstructionLotsValue, 4);
    strcpy(tempString, this->constructionPlanNameValue);
    tempInt = strlen(tempString);
    rge_write(fd, &tempInt, 4);
    rge_write(fd, tempString, strlen(tempString));
    rge_write(fd, (void*)&this->xReferencePointValue, 4);
    rge_write(fd, (void*)&this->yReferencePointValue, 4);
    rge_write(fd, (void*)&this->zReferencePointValue, 4);
    rge_write(fd, (void*)&this->mapXSizeValue, 4);
    rge_write(fd, (void*)&this->mapYSizeValue, 4);

    item = this->constructionLots.next;
    while (item != &this->constructionLots) {
        if (item == 0) break;
        strcpy(tempString, item->name());
        tempInt = strlen(tempString);
        rge_write(fd, &tempInt, 4);
        rge_write(fd, tempString, tempInt);
        tempInt = item->typeID();
        rge_write(fd, &tempInt, 4);
        tempInt = item->gameID();
        rge_write(fd, &tempInt, 4);
        tempInt = item->uniqueID();
        rge_write(fd, &tempInt, 4);
        tempFloat = item->x();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->y();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->z();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->xSize();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->ySize();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->zSize();
        rge_write(fd, &tempFloat, 4);
        tempBOOL = item->skip();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->inProgress();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->built();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->buildAttempts();
        rge_write(fd, &tempBOOL, 4);
        item = item->next;
    }

    rge_write(fd, (void*)&this->numberRandomConstructionLotsValue, 4);
    item = this->randomConstructionLots.next;
    while (item != &this->randomConstructionLots) {
        if (item == 0) return 1;
        strcpy(tempString, item->name());
        tempInt = strlen(tempString);
        rge_write(fd, &tempInt, 4);
        rge_write(fd, tempString, tempInt);
        tempInt = item->typeID();
        rge_write(fd, &tempInt, 4);
        tempInt = item->gameID();
        rge_write(fd, &tempInt, 4);
        tempInt = item->uniqueID();
        rge_write(fd, &tempInt, 4);
        tempFloat = item->x();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->y();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->z();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->xSize();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->ySize();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->zSize();
        rge_write(fd, &tempFloat, 4);
        tempBOOL = item->skip();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->inProgress();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->built();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->buildAttempts();
        rge_write(fd, &tempBOOL, 4);
        item = item->next;
    }
    return 1;
}
