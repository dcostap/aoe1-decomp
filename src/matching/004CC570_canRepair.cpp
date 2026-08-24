#ifndef T_C_OBJ_CONTEXT_H
class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
    short copy_id;
    short object_group;
    char gap_16[0x10];
    short hp;
};

class TRIBE_Player {
public:
    unsigned char check_obj_cost(short param_1, short* param_2, float param_3, int param_4);
};

class TRIBE_Combat_Object {
public:
    char gap_00[0x8];
    RGE_Master_Static_Object* master_obj;
    TRIBE_Player* owner;
    char gap_10[0x20];
    float hp;

    int canRepair();
};
#endif

int TRIBE_Combat_Object::canRepair() {
    float fVar1 = (float)(int)this->master_obj->hp;
    return this->owner->check_obj_cost(this->master_obj->id, (short*)0, (fVar1 - this->hp) / fVar1, 0) != 0;
}
