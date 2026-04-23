class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    char gap_08[0x38];
    float world_z;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x124];
    short attack_modifier_kind;
};

class TRIBE_Building_Object {
public:
    void* vtable_ptr;
    long id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x34];
    float world_z;

    float calc_attack_modifier(RGE_Static_Object* param_1);
};

float TRIBE_Building_Object::calc_attack_modifier(RGE_Static_Object* param_1)
{
    if (this->master_obj->attack_modifier_kind < 0) {
        if (this->world_z < param_1->world_z)
            return 0.6666f;
    }
    else {
        if ((*(int (__thiscall **)(TRIBE_Building_Object*, RGE_Static_Object*))(*(void***)this)[147])(this, param_1) != 0)
            return 1.5f;
    }

    return 1.0f;
}
