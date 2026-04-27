// target: VA 004173D0 UnitAIModule::defendObject(int,float,int)
// sibling of followObject; keep the early currentAction gate, world lookup, action/target calls, and final field stores

class RGE_Static_Object;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int index);
};

class RGE_Unit_Object_Owner {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Unit_Object {
public:
    char gap_00[0xC];
    RGE_Unit_Object_Owner* owner;
};

class RGE_Master_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Master_Object* master_obj;
    char gap_0C[0x2C];
    int world_x;
    int world_y;
    int world_z;
};

class UnitAIModule {
public:
    char gap_00[0x4];
    RGE_Unit_Object* objectValue;
    char gap_08[0x28];
    int currentActionValue;
    int currentTargetValue;
    int currentTargetTypeValue;
    int currentTargetXValue;
    int currentTargetYValue;
    int currentTargetZValue;
    float desiredTargetDistanceValue;
    int defendTargetValue;
    int lastOrderValue;
    int lastActionValue;

    void setCurrentAction(int value);
    void setCurrentTarget(int id, int x, int y, int z);
    int defendObject(int id, float distance, int allow_when_busy);
};

int UnitAIModule::defendObject(int id, float distance, int allow_when_busy) {
    RGE_Static_Object* target;

    if (allow_when_busy == 0 && this->currentActionValue != -1) {
        return 0;
    }

    target = this->objectValue->owner->world->object(id);
    if (target == 0) {
        return 0;
    }

    this->setCurrentAction(0x259);
    this->setCurrentTarget(id, target->world_x, target->world_y, target->world_z);
    this->defendTargetValue = id;
    this->desiredTargetDistanceValue = distance;
    return 1;
}
