#pragma once
#include "common.h"

class BaseObject {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
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
    ~BaseObject();
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

