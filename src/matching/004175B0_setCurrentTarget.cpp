class RGE_Master_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Master_Object* master_obj;
};

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

class UnitAIModule {
public:
    char gap_00[0x4];
    RGE_Unit_Object* objectValue;
    char gap_08[0x2C];
    int currentTarget;
    int currentTargetType;
    int currentTargetX;
    int currentTargetY;
    int currentTargetZ;
    char gap_48[0x10];
    int lastTarget;
    int lastTargetType;

    void setCurrentTarget(int id, int x, int y, int z);
};

void UnitAIModule::setCurrentTarget(int id, int x, int y, int z) {
    this->lastTarget = this->currentTarget;
    this->lastTargetType = this->currentTargetType;
    this->currentTarget = id;
    this->currentTargetX = x;
    this->currentTargetY = y;
    this->currentTargetZ = z;

    RGE_Static_Object* object = this->objectValue->owner->world->object(id);
    if (object != 0) {
        this->currentTargetType = object->master_obj->object_group;
    }
}
