class RGE_Master_Object {
public:
    char gap_00[0x14];
    short object_type;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Object* master_obj;
};

class RGE_Combat_Object {
public:
    char gap_00[0x48];
    unsigned char interaction_type;
};

class TribeTowerUnitAIModule {
public:
    virtual int canAttackUnit(RGE_Static_Object* target);
    RGE_Combat_Object* object;
};

int TribeTowerUnitAIModule::canAttackUnit(RGE_Static_Object* target) {
    if (target == 0)
        return 0;
    if (target->master_obj->object_type == 1)
        return 0;
    if (this->object->interaction_type < 2)
        return 0;
    return 1;
}
