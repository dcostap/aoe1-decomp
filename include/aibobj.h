#ifndef AOE1_AIBOBJ_H
#define AOE1_AIBOBJ_H


class BaseObject {
public:
    virtual ~BaseObject();

    BaseObject();
    BaseObject(int a, int category, int type, int game, char* name,
               float xSize, float ySize, float zSize,
               float xPos, float yPos, float zPos,
               int hitPt, int minHit, int maxHit);
    BaseObject(BaseObject* src);
    BaseObject(const BaseObject& src);

    BaseObject* next;                         // +0x04
    BaseObject* prev;                         // +0x08
    int numberGroupsValue;                    // +0x0C
    int* groupIDValue;                        // +0x10
    int categoryIDValue;                      // +0x14
    int typeIDValue;                          // +0x18
    int gameIDValue;                          // +0x1C
    char nameValue[64];                       // +0x20
    float xPositionValue;                     // +0x60
    float yPositionValue;                     // +0x64
    float zPositionValue;                     // +0x68
    float xSizeValue;                         // +0x6C
    float ySizeValue;                         // +0x70
    float zSizeValue;                         // +0x74
    int hitPointValue;                        // +0x78
    int minHitPointValue;                     // +0x7C
    int maxHitPointValue;                     // +0x80
    int busyValue;                            // +0x84
    int currentTaskValue;                     // +0x88
    int currentTargetValue;                   // +0x8C
    int currentTargetTypeValue;               // +0x90
    float currentTargetXPositionValue;        // +0x94
    float currentTargetYPositionValue;        // +0x98
    float currentTargetZPositionValue;        // +0x9C

    int numberGroups() const;
    int groupID(int index) const;
    int inGroup(int groupId) const;
    int addGroup(int groupId);
    int removeGroup(int groupId);
    int categoryID() const;
    int typeID() const;
    const int& gameID() const;
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
    void setXPosition(float value);
    void setYPosition(float value);
    void setZPosition(float value);
    void setXSize(float value);
    void setYSize(float value);
    void setZSize(float value);
    void setHitPoints(int value);
    void incrementHitPoints(int value);
    void decrementHitPoints(int value);
    void setMinHitPoints(int value);
    void incrementMinHitPoints(int value);
    void decrementMinHitPoints(int value);
    void setMaxHitPoints(int value);
    void incrementMaxHitPoints(int value);
    void decrementMaxHitPoints(int value);
    void setBusy(int value);
    void setCurrentTask(int value);
    void setCurrentTarget(int value);
    void setCurrentTargetType(int value);
    void setCurrentTargetPosition(float a, float b, float c);
};

typedef char aibobj_size_check[(sizeof(BaseObject) == 0xA0) ? 1 : -1];

int __cdecl operator==(const BaseObject& left, const BaseObject& right);
int __cdecl operator!=(const BaseObject& left, const BaseObject& right);
int __cdecl operator<(const BaseObject& left, const BaseObject& right);
int __cdecl operator>(const BaseObject& left, const BaseObject& right);

#endif  // AOE1_AIBOBJ_H
