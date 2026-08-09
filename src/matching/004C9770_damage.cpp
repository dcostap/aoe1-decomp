// 004C9770 TRIBE_Building_Object::damage (t_b_obj.cpp:931-962)
// Attempt log:
// - Baseline decompiler-shaped reconstruction was 10 bytes short because the
//   two branch-local HP reductions tail-merged.
// - Restored the normal-path one-point reduction (the special path is 0.1),
//   which reproduced the original duplicated FPU blocks and exact 246 bytes.
// - Replaced the raw HP bit shuttle with a natural pre-guard float snapshot;
//   VC5 emitted the same observed stack home.
// - Named the proven master/static-object fields and bound the observed
//   constants to their established globals without changing codegen.
// - Used the known player add_attribute_num ABI and qualified base damage call;
//   both remain exact under the default flags.

#include <string.h>
#include <stdio.h>

extern float DAT_005749f4;
extern double DAT_00574a00;
extern float DAT_00574a08;
extern double DAT_00574a10;
extern float DAT_00574a18;

class RGE_Armor_Weapon_Info;
class RGE_Player;
class RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    unsigned char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char _gap_10[0x20];
    float hp;
};

class RGE_Combat_Object : public RGE_Static_Object {
public:
    void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
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
    virtual void add_attribute_num(short attribute, float amount, unsigned char flag);

    char _gap_04[0x46];
    short id;
};

class TRIBE_Building_Object : public RGE_Combat_Object {
public:
    void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
};

void TRIBE_Building_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5)
{
    float saved_hp = this->hp;

    if (this->hp <= DAT_005749f4) {
        return;
    }

    RGE_Combat_Object::damage(param_1, param_2, param_3, param_4, param_5);

    RGE_Master_Static_Object* master = param_5->master_obj;
    short group = master->object_group;
    short id;
    float damage_taken;

    // Sequential if-checks with je-to-handler pattern for alternate path
    if (group == 0 || group == 0x17 || group == 0x24 || group == 0x1A ||
        (id = master->id,
         id == 0x4F || id == 0x45 || id == 0xC7 || id == 0x17F || id == 0x17C))
    {
        // Alternate path
        damage_taken = saved_hp - this->hp;
        if (damage_taken < DAT_00574a10) {
            this->hp = saved_hp - DAT_00574a18;
        }
    }
    else
    {
        // Normal path
        damage_taken = saved_hp - this->hp;
        if (damage_taken < DAT_00574a00) {
            this->hp = saved_hp - DAT_00574a08;
        }
    }

    RGE_Player* player = this->owner;

    if (player->id > 0 && this->hp < DAT_00574a00) {
        param_4->add_attribute_num(0x2B, 1.0f, 0);
    }
}
