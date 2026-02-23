#pragma once
#include "common.h"

class BaseObject {
public:
    BaseObject();
    BaseObject(int param_1, int param_2, int param_3, int param_4, char* param_5, float param_6, float param_7, float param_8, float param_9, float param_10, float param_11, int param_12, int param_13, int param_14);
    BaseObject(BaseObject* param_1);
    BaseObject(const BaseObject& param_1);

    // Virtuals (best-effort)
    virtual ~BaseObject(); // vt[0] (0x0)

    int numberGroups() const;
    int groupID(int param_1) const;
    int inGroup(int param_1) const;
    int addGroup(int param_1);
    int removeGroup(int param_1);
    int categoryID() const;
    int typeID() const;
    int const& gameID() const;
    char* name();
    float xPosition() const;
    float yPosition() const;
    float zPosition() const;
    float xSize() const;
    float ySize() const;
    float zSize() const;
    int hitPoints() const;
    int minHitPoints() const;
    int maxHitPoints() const;
    int busy() const;
    int currentTask() const;
    int currentTarget() const;
    int currentTargetType() const;
    float currentTargetXPosition() const;
    float currentTargetYPosition() const;
    float currentTargetZPosition() const;
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

    BaseObject* next;
    BaseObject* prev;
    int numberGroupsValue;
    int* groupIDValue;
    int categoryIDValue;
    int typeIDValue;
    int gameIDValue;
    char nameValue[64];
    float xPositionValue;
    float yPositionValue;
    float zPositionValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int hitPointValue;
    int minHitPointValue;
    int maxHitPointValue;
    int busyValue;
    int currentTaskValue;
    int currentTargetValue;
    int currentTargetTypeValue;
    float currentTargetXPositionValue;
    float currentTargetYPositionValue;
    float currentTargetZPositionValue;
};

int operator==(const BaseObject& param_1, const BaseObject& param_2);
int operator!=(const BaseObject& param_1, const BaseObject& param_2);
int operator<(const BaseObject& param_1, const BaseObject& param_2);
int operator>(const BaseObject& param_1, const BaseObject& param_2);

static_assert(sizeof(BaseObject) == 0xA0, "Size mismatch");
