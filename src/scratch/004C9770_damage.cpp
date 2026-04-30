// 004C9770 TRIBE_Building_Object::damage (t_b_obj.cpp:931-962)

#include <string.h>
#include <stdio.h>

class RGE_Armor_Weapon_Info;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Static_Object;

class RGE_Static_Object {
public:
    char _gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    char _gap_0C[0x24];
    float hp;
};

class RGE_Combat_Object : public RGE_Static_Object {
public:
    void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
};

class RGE_Player {
public:
    virtual void _v00();
    virtual void _v04();
    virtual void _v08();
    virtual void _v0C();
    virtual void _v10();
    virtual void _v14();
    virtual void _v18();
    virtual void _v1C();
    virtual void _v20();
    virtual void _v24();
    virtual void _v28();
    virtual void _v2C();
    virtual void _v30();
    virtual void _v34();
    virtual void _v38();
    virtual void _v3C();
    virtual void _v40();
    virtual void _v44();
    virtual void _v48();
    virtual void _v4C();
    virtual void _v50();
    virtual void _v54();
    virtual void _v58();
    virtual void _v5C();
    virtual void _v60();
    virtual void _v64();
    virtual void _v68();
    virtual void _v6C();
    virtual void _v70();
    virtual void _v74();
    virtual void something(int a1, float a2, int a3);

    char _gap_04[0x46];
    short id;
};

class TRIBE_Building_Object : public RGE_Combat_Object {
public:
    void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
};

void TRIBE_Building_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5)
{
    int saved_hp_bits = *(int*)((char*)this + 0x30);

    if (this->hp <= 0.0f) {
        return;
    }

    ((RGE_Combat_Object*)this)->damage(param_1, param_2, param_3, param_4, param_5);

    float saved_hp = *(float*)&saved_hp_bits;

    RGE_Master_Static_Object* master = param_5->master_obj;
    short group = *(short*)((char*)master + 0x14);
    short id;
    float damage_taken;

    // Sequential if-checks with je-to-handler pattern for alternate path
    if (group == 0 || group == 0x17 || group == 0x24 || group == 0x1A ||
        (id = *(short*)((char*)master + 0x10),
         id == 0x4F || id == 0x45 || id == 0xC7 || id == 0x17F || id == 0x17C))
    {
        // Alternate path
        damage_taken = saved_hp - this->hp;
        if (damage_taken < 0.1) {
            this->hp = saved_hp - 0.1f;
        }
    }
    else
    {
        // Normal path
        damage_taken = saved_hp - this->hp;
        if (damage_taken < 1.0) {
            this->hp = saved_hp - 0.1f;
        }
    }

    RGE_Player* player = *(RGE_Player**)((char*)this + 0x0C);

    if (player->id > 0 && this->hp < 1.0) {
        param_4->something(0x2B, 1.0f, 0);
    }
}
