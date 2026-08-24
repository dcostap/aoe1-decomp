class RGE_Static_Object;

#ifndef AOE1_AIUAIMOD_COMPLETE_TU
class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

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

class UnitAIModule {
public:
    char gap_00[0x04];
    RGE_Unit_Object* objectValue;

    RGE_Static_Object* lookupObject(int objectId);
};
#endif

RGE_Static_Object* UnitAIModule::lookupObject(int objectId) {
    if (this->objectValue && this->objectValue->owner &&
        this->objectValue->owner->world) {
        return this->objectValue->owner->world->object(objectId);
    }
    return 0;
}
