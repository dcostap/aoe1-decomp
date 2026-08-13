// VA: 00503600 TribeTacticalAIModule::saveTheTown
// PDB source: taitacmd.cpp:13342-13444
// __thiscall
// Attempt log:
// - Replaced the parked raw-pointer scaffold with the typed same-TU ownership
//   model: md, aiPlayer, soldiers, playersToAttack, target objects, and groups.
// - The baseline follows the binary call bands: group rescue, soldier scan,
//   then civilian reinforcement. It keeps the two inline ManagedArray growth
//   sites because the executable contains all three growth blocks.
// - Shared the binary LAB_00503954 soldier attack path with a count-only label;
//   this restored all 52 ordered calls, the 0x24 frame, and a +11-byte size gap.
// - Final gap is local coordinate-conversion scheduling at the first mismatch;
//   no further source-shape lead is retained in this bounded pass.

typedef unsigned long ulong;

extern "C" ulong debug_timeGetTime(char* file, int line);
extern int __ftol();
extern void* operator_new(unsigned int size);
extern void operator_delete(void* block);

struct XYPoint {
    int x;
    int y;
};

struct XYZPoint {
    int x;
    int y;
    int z;
};

struct Waypoint {
    float x;
    float y;
    float z;
    int facetToNextWaypoint;
};

class ManagedArrayInt {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index)
    {
        if (index > this->maximumSizeValue - 1) {
            int newSize = index + 1;
            int* newValue = (int*)operator_new(newSize * 4);
            if (newValue != 0) {
                int i;
                for (i = 0; i < this->maximumSizeValue && i < newSize; i++)
                    newValue[i] = this->value[i];
                operator_delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }
        return this->value[index];
    }
};

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Player;
class TribeTacticalAIModule;
class TribeMainDecisionAIModule;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
};

class UnitAIModule {
public:
    int currentAction();
    int currentTarget();
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    VPAD64(0)
    VPAD2(64)
    virtual float command(int, int, int, int, int);
    VPAD32(66)
    VPAD2(98)
    virtual int move(XYZPoint, float);

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;

    UnitAIModule* unitAI();
    float distance_to_object(RGE_Static_Object* object);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;

    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1256C - 0x104];
    RGE_Player* aiPlayer;
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[0x160];
    TacticalAIGroup* next;
    TacticalAIGroup* previous;
    int commanderValue;

    int commander();
    void setTarget(int id);
    void setTargetType(int type);
    void setTargetLocation(float x, float y, float z);
    void setAction(int action);
    void task(TribeTacticalAIModule*, TribeMainDecisionAIModule*, int, int, int);
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;
    ManagedArrayInt civilians;
    ManagedArrayInt civilianExplorers;
    ManagedArrayInt soldiers;
    ManagedArrayInt ungroupedSoldiers;
    ManagedArrayInt boats;
    char gap_138[0x194 - 0x138];
    int sn[0xE2];
    char gap_51C[0xD28 - 0x51C];
    ManagedArrayInt playersToAttack;

    TacticalAIGroup* readyAndIdleGroup(int type, int maxDistance,
                                        XYPoint& point);
    int civilian(XYPoint&, int, int, int, int, int);
    int taskAttacker(int, float, float, int, int, Waypoint*, int, int, int);

    void saveTheTown(int objectID);
};

void TribeTacticalAIModule::saveTheTown(int objectID)
{
    ulong entryTime = debug_timeGetTime((char*)0x5880C0, 0x3420);
    RGE_Static_Object* targetObject = this->md->object(objectID);

    if (targetObject != 0) {
        XYPoint objectPosition;
        objectPosition.x = (int)targetObject->world_x;
        objectPosition.y = (int)targetObject->world_y;

        TacticalAIGroup* group = this->readyAndIdleGroup(
            100, this->sn[0x14], objectPosition);
        if (group == 0)
            group = this->readyAndIdleGroup(
                0x67, this->sn[0x14], objectPosition);

        if (group != 0) {
            int commanderID = group->commander();
            RGE_Static_Object* commanderObject =
                this->md->player->world->object(commanderID);
            if (commanderObject != 0) {
                XYZPoint point;
                point.x = (int)targetObject->world_x;
                point.y = (int)targetObject->world_y;
                point.z = (int)targetObject->world_z;
                float commandResult = commanderObject->command(
                    objectID, 0, 1, -1, -1);
                if (commanderObject->move(point, commandResult) == 1) {
                    group->setTarget(objectID);
                    group->setTargetType(
                        (int)targetObject->master_obj->id);
                    group->setTargetLocation(
                        targetObject->world_x, targetObject->world_y,
                        targetObject->world_z);
                    group->setAction(2);
                    group->task(this, this->md, 2, 1, 0);
                    return;
                }
            }
        }

        int count = 0;
        int entryCount = 0;
        if (this->soldiers.numberValue > 0) {
            do {
                if (entryCount > 5)
                    break;
                if (count > 1 &&
                    debug_timeGetTime((char*)0x5880C0, 0x3447) -
                            entryTime > 10)
                    return;

                RGE_Static_Object* object = this->md->aiPlayer->world->object(
                    this->soldiers[count]);
                if (object != 0 && object->unitAI() != 0) {
                    if (object->unitAI()->currentAction() == 600) {
                        if (object->unitAI()->currentTarget() == -1)
                            goto trySoldier;
                        if (object->unitAI()->currentTarget() ==
                            targetObject->id)
                            goto countSoldier;

                        RGE_Static_Object* currentTarget =
                            this->md->player->world->object(
                                object->unitAI()->currentTarget());
                        if (currentTarget != 0 &&
                            this->playersToAttack[0] ==
                                currentTarget->owner->id)
                            goto countSoldier;
                    } else {
                        goto trySoldier;
                    }

trySoldier:
                    {
                        if (object->distance_to_object(targetObject) <
                            25.0f) {
                        XYZPoint point;
                        point.x = (int)targetObject->world_x;
                        point.y = (int)targetObject->world_y;
                        point.z = (int)targetObject->world_z;
                        float commandResult = object->command(
                            targetObject->id, 0, 1, -1, -1);
                        if (object->move(point, commandResult) != 0) {
                            if (this->taskAttacker(
                                    this->soldiers[count],
                                    targetObject->world_x,
                                    targetObject->world_y, targetObject->id,
                                    (int)targetObject->owner->id, 0, 0, -1,
                                    0) == 1)
                                entryCount++;
                        }
                    }
                    }
                }

countSoldier:
                count++;
            } while (count < this->soldiers.numberValue);
        }

        int unitID = this->civilian(
            objectPosition, 1, 700, -1000, -1000, 1);
        while (unitID != -1 && entryCount < 6) {
            RGE_Static_Object* object = this->md->object(unitID);
            if (object == 0)
                return;

            XYZPoint point;
            point.x = (int)targetObject->world_x;
            point.y = (int)targetObject->world_y;
            point.z = (int)targetObject->world_z;
            float commandResult = object->command(
                objectID, 0, 1, -1, -1);
            if (object->move(point, commandResult) == 0)
                return;

            this->taskAttacker(unitID, targetObject->world_x,
                               targetObject->world_y, objectID,
                               (int)targetObject->owner->id, 0, 0, -1, 0);
            entryCount++;
            unitID = this->civilian(
                objectPosition, 1, 700, 0x2C9, 0x2C9, 1);
        }
    }
}
