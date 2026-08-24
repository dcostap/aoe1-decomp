#ifndef AIBOBJ_CONTEXT_H
#define AIBOBJ_CONTEXT_H

// Authentic aibobj.cpp class surface used by the module owner wrapper.
// The class has one virtual destructor and a 0xA0-byte object layout.
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

    BaseObject* next;
    BaseObject* prev;
    union { int numberGroupsValue; int numberGroups_; int count; };
    union { int* groupIDValue; int* groupID_; int* groups; };
    union { int categoryIDValue; int categoryID_; };
    union { int typeIDValue; int typeID_; };
    union { int gameIDValue; int gameID_; };
    union { char nameValue[64]; char name_arr[64]; };
    union { float xPositionValue; float xPosition_; };
    union { float yPositionValue; float yPosition_; };
    union { float zPositionValue; float zPosition_; };
    union { float xSizeValue; float xSize_; };
    union { float ySizeValue; float ySize_; };
    union { float zSizeValue; float zSize_; };
    union { int hitPointValue; int hitPoints_; };
    union { int minHitPointValue; int minHitPoints_; };
    union { int maxHitPointValue; int maxHitPoints_; int field_80; };
    union { int busyValue; int busy_; };
    union { int currentTaskValue; int currentTask_; };
    union { int currentTargetValue; int currentTarget_; };
    union { int currentTargetTypeValue; int currentTargetType_; };
    union { float currentTargetXPositionValue; float currentTargetXPosition_; int field_94; };
    union { float currentTargetYPositionValue; float currentTargetYPosition_; int field_98; };
    union { float currentTargetZPositionValue; float currentTargetZPosition_; int field_9C; };

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

int __cdecl operator==(const BaseObject& left, const BaseObject& right);
int __cdecl operator!=(const BaseObject& left, const BaseObject& right);
int __cdecl operator<(const BaseObject& left, const BaseObject& right);
int __cdecl operator>(const BaseObject& left, const BaseObject& right);

typedef char aibobj_size_check[(sizeof(BaseObject) == 0xA0) ? 1 : -1];

#endif
