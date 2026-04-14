// TribeTowerUnitAIModule::canAttackUnit
// Checks if param is null, if obj->master_obj->object_type == 1 return 0
// Then checks self->object->interaction_type != 2 (sbb+inc idiom)
// ret 4 = 1 param

struct RGE_Master_Object {
    char gap_0[0x14];
    short object_type;
};

struct RGE_Static_Object {
    char gap_0[8];
    RGE_Master_Object* master_obj;
};

struct RGE_Combat_Object {
    char gap_0[0x48];
    unsigned char interaction_type;
};

struct UnitAIModule {
    int vtable;
    RGE_Combat_Object* object;
};

int __fastcall canAttackUnit(UnitAIModule* self, int, RGE_Static_Object* target) {
    if (target == 0)
        return 0;
    if (target->master_obj->object_type == 1)
        return 0;
    return self->object->interaction_type != 2;
}
