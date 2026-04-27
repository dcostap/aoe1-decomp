// VA: 00417360
// UnitAIModule::followObject(int param_1, float param_2, int param_3)
// Size: 108 bytes
// Source: aiuaimod.cpp lines 3684-3702

// Local stubs for types used by this function
class RGE_Game_World;
class RGE_Static_Object;

class RGE_Unit_Object_Owner {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Unit_Object {
public:
    char gap_00[0x0C];
    RGE_Unit_Object_Owner* owner;
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float world_x;
    float world_y;
    float world_z;
};

class UnitAIModule {
public:
    char gap_00[0x04];
    RGE_Unit_Object* objectValue;
    char gap_08[0x28];
    int currentAction;          // +0x30
    char gap_34[0x14];
    float desiredTargetDistance; // +0x48

    void setCurrentAction(int action);
    void setCurrentTarget(int id, float x, float y, float z);
    int followObject(int param_1, float param_2, int param_3);
};

// ---
// UnitAIModule::followObject
// If param_3 == 0 and this->currentAction != -1, return 0 immediately.
// Otherwise, look up the object by param_1; if null, return 0.
// Then set action to 0x264, set target to the object's world position,
// store param_2 as desiredTargetDistance, and return 1.
int UnitAIModule::followObject(int param_1, float param_2, int param_3) {
    if (param_3 == 0 && this->currentAction != -1) {
        return 0;
    }

    RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
    if (target == 0) {
        return 0;
    }

    this->setCurrentAction(0x264);
    this->setCurrentTarget(param_1, target->world_x, target->world_y, target->world_z);
    this->desiredTargetDistance = param_2;
    return 1;
}
