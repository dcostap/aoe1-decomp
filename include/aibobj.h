#ifndef AOE1_AIBOBJ_H
#define AOE1_AIBOBJ_H

class BaseObject {
public:
    virtual ~BaseObject();

    BaseObject();
    BaseObject(int gri, int ci, int ti, int gi, char* nm, float xs, float ys, float zs, float xp, float yp, float zp,
               int hp, int minp, int maxp);
    BaseObject(BaseObject* bo);
    BaseObject(const BaseObject& bo);

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
    int groupID(int v) const;
    int inGroup(int v) const;
    int addGroup(int v);
    int removeGroup(int v);
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
    void setXPosition(float v);
    void setYPosition(float v);
    void setZPosition(float v);
    void setXSize(float v);
    void setYSize(float v);
    void setZSize(float v);
    void setHitPoints(int v);
    void incrementHitPoints(int v);
    void decrementHitPoints(int v);
    void setMinHitPoints(int v);
    void incrementMinHitPoints(int v);
    void decrementMinHitPoints(int v);
    void setMaxHitPoints(int v);
    void incrementMaxHitPoints(int v);
    void decrementMaxHitPoints(int v);
    void setBusy(int v);
    void setCurrentTask(int v);
    void setCurrentTarget(int v);
    void setCurrentTargetType(int v);
    void setCurrentTargetPosition(float x, float y, float z);
};

typedef char aibobj_size_check[(sizeof(BaseObject) == 0xA0) ? 1 : -1];

int __cdecl operator==(const BaseObject& one, const BaseObject& two);
int __cdecl operator!=(const BaseObject& one, const BaseObject& two);
int __cdecl operator<(const BaseObject& one, const BaseObject& two);
int __cdecl operator>(const BaseObject& one, const BaseObject& two);

#endif  // AOE1_AIBOBJ_H
