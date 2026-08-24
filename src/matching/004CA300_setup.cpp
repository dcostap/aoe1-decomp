// VA: 004CA300 TRIBE_Combat_Object::setup
// PDB source: t_c_obj.cpp:111-146
//
// Binary-supported ownership: RGE_Static_Object supplies master_obj (+0x08),
// owner (+0x0c), attribute_amount_held (+0x44), attribute_type_held (+0x4c),
// and type (+0x4e).  RGE_Combat_Object supplies capture_flag (+0x1c0), while
// TRIBE_Combat_Object adds own_master (+0x1c4).  The declaration-only virtual
// padding preserves the observed TRIBE initUnitAI/setup slots (+0x250/+0x254).

extern float DAT_00574c7c;

#ifndef T_C_OBJ_CONTEXT_H
class RGE_Master_Combat_Object {
public:
    void* vtable_ptr;
    unsigned char master_type;
    unsigned char gap_05[0x0b];
    short id;
    unsigned char gap_12[2];
    short object_group;
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
};

class RGE_Player {
public:
    void* vtable_ptr;
    unsigned char gap_04[0x46];
    short id;
    short attribute_num;
    unsigned char gap_4e[2];
    float* attributes;
};

#define V(n) virtual void v_##n();
#define V10(p) V(p##0) V(p##1) V(p##2) V(p##3) V(p##4) V(p##5) V(p##6) V(p##7) V(p##8) V(p##9)
#define V3(p) V(p##0) V(p##1) V(p##2)
#define V4TAIL(p) V(p##4) V(p##5) V(p##6) V(p##7)

class RGE_Combat_Object {
public:
    V10(0)
    V10(1)
    V10(2)
    V10(3)
    V10(4)
    V10(5)
    V10(6)
    V10(7)
    V10(8)
    V10(9)
    V10(10)
    V10(11)
    V10(12)
    V10(13)
    V3(14)
    virtual int setup(RGE_Master_Combat_Object* master_obj, RGE_Player* player,
                      float x, float y, float z);
    V4TAIL(14)

    int id;
    RGE_Master_Combat_Object* master_obj;
    RGE_Player* owner;
    unsigned char gap_10[0x34];
    float attribute_amount_held;
    unsigned char gap_48[4];
    short attribute_type_held;
    unsigned char type;
    unsigned char gap_4f[0x171];
    unsigned char capture_flag;
    unsigned char gap_1c1[3];
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    virtual void initUnitAI();
    virtual int setup(TRIBE_Master_Combat_Object* master_obj, RGE_Player* player,
                      float x, float y, float z);

    unsigned char own_master;
};
#endif

int TRIBE_Combat_Object::setup(TRIBE_Master_Combat_Object* master_obj,
                               RGE_Player* player, float x, float y, float z)
{
    RGE_Combat_Object::setup(master_obj, player, x, y, z);

    if (this->owner->id == 0) {
        this->capture_flag = 1;
    }

    this->type = 0x46;
    this->initUnitAI();
    this->own_master = 0;

    if (this->master_obj->object_group == 4 ||
        this->master_obj->object_group == 0x15 ||
        this->master_obj->object_group == 2) {
        this->owner->attributes[0x25] -= DAT_00574c7c;
    } else if ((this->master_obj->object_group != 0x12 &&
                this->master_obj->master_type == 'F') ||
               this->master_obj->id == 0x4f ||
               this->master_obj->id == 0x45 ||
               this->master_obj->id == 0xc7) {
        this->owner->attributes[0x28] -= DAT_00574c7c;
    }

    if (this->master_obj->object_group == 0x12) {
        this->attribute_amount_held = 100.0f;
        this->attribute_type_held = 0x22;
    }

    return 1;
}

#undef V4TAIL
#undef V3
#undef V10
#undef V
