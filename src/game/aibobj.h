#pragma once
#include "../common.h"

class BaseObject       {
public:
    BaseObject* next;                        // 0x4
    BaseObject* prev;                        // 0x8
    int numberGroupsValue;                   // 0xC
    int* groupIDValue;                       // 0x10
    int categoryIDValue;                     // 0x14
    int typeIDValue;                         // 0x18
    int gameIDValue;                         // 0x1C
    char nameValue[64];                      // 0x20
    float xPositionValue;                    // 0x60
    float yPositionValue;                    // 0x64
    float zPositionValue;                    // 0x68
    float xSizeValue;                        // 0x6C
    float ySizeValue;                        // 0x70
    float zSizeValue;                        // 0x74
    int hitPointValue;                       // 0x78
    int minHitPointValue;                    // 0x7C
    int maxHitPointValue;                    // 0x80
    int busyValue;                           // 0x84
    int currentTaskValue;                    // 0x88
    int currentTargetValue;                  // 0x8C
    int currentTargetTypeValue;              // 0x90
    float currentTargetXPositionValue;       // 0x94
    float currentTargetYPositionValue;       // 0x98
    float currentTargetZPositionValue;       // 0x9C

    BaseObject();
    BaseObject(int param_1, int param_2, int param_3, int param_4, char* param_5, float param_6, float param_7, float param_8, float param_9, float param_10, float param_11, int param_12, int param_13, int param_14);
    BaseObject(BaseObject* param_1);
    BaseObject(BaseObject* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~BaseObject() noexcept(false); // Ghidra: `vector_deleting_destructor'

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

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void loadConstructionPlan();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void placeStructure();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void setBuilt();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void unplaceStructure();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void unplaceStructure();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void decrementBuildAttempts();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void incrementBuildAttempts();

    // --- Non-Virtual Members ---
    int numberGroups();
    int groupID(int param_1);
    int inGroup(int param_1);
    int addGroup(int param_1);
    int removeGroup(int param_1);
    int categoryID();
    int typeID();
    int* gameID();
    char* name();
    float xPosition();
    float yPosition();
    float zPosition();
    float xSize();
    float ySize();
    float zSize();
    int hitPoints();
    int minHitPoints();
    int maxHitPoints();
    int busy();
    int currentTask();
    int currentTarget();
    int currentTargetType();
    float currentTargetXPosition();
    float currentTargetYPosition();
    float currentTargetZPosition();
    void setXPosition(float param_1);
    void setYPosition(float param_1);
    void setZPosition(float param_1);
    void setXSize(float param_1);
    void setYSize(float param_1);
    void setZSize(float param_1);
    void setHitPoints(int param_1);
    void incrementHitPoints(int param_1);
    void decrementHitPoints(int param_1);
    void setMinHitPoints(int param_1);
    void incrementMinHitPoints(int param_1);
    void decrementMinHitPoints(int param_1);
    void setMaxHitPoints(int param_1);
    void incrementMaxHitPoints(int param_1);
    void decrementMaxHitPoints(int param_1);
    void setBusy(int param_1);
    void setCurrentTask(int param_1);
    void setCurrentTarget(int param_1);
    void setCurrentTargetType(int param_1);
    void setCurrentTargetPosition(float param_1, float param_2, float param_3);
};

static_assert(sizeof(BaseObject) == 0xA0, "BaseObject Size Mismatch");
static_assert(offsetof(BaseObject, currentTargetZPositionValue) == 0x9C, "BaseObject Offset Mismatch");

