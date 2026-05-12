// VA: 004C86C0 TRIBE_Building_Object::heal (128 B)
// PDB source: t_b_obj.cpp lines 272-285
// Attempt log: see bottom

#include <string.h>

class TRIBE_Player {
public:
    unsigned char pay_obj_cost(short type, float amount, int flag);
};

class TRIBE_Combat_Object {
public:
    unsigned char heal(float amount);
};

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    void* vtable;
    int id;
    void* master_obj;
    TRIBE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;

    unsigned char heal(float amount);
};

unsigned char TRIBE_Building_Object::heal(float amount)
{
    void* master = this->master_obj;
    int maxHp = *(short*)((char*)master + 0x26);
    int healRate = *(short*)((char*)master + 0x15A);
    float amt;
    memcpy(&amt, &amount, 4);
    amt = (amt * (float)maxHp) / (float)healRate;
    if (amt + this->hp > (float)maxHp) {
        amt = (float)maxHp - this->hp;
    }
    if (this->owner->pay_obj_cost(*(short*)((char*)master + 0x10), amt / (float)(maxHp * 2), 0)) {
        return TRIBE_Combat_Object::heal(amt);
    }
    return 2;
}
