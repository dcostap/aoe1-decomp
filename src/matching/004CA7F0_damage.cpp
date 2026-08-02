// 004CA7F0 TRIBE_Combat_Object::damage
// PDB source: t_c_obj.cpp:330-362
//
// Canonical ownership recovered from the binary and exact same-TU donors:
// RGE_Combat_Object owns owner (+0x0C) and hp (+0x30); the target owns a
// master object at +0x08 and that master has object_group at +0x14.  The
// three virtual calls use the established RGE object/player slots.
//
// Attempt log:
// baseline: natural TRIBE_Combat_Object damage wrapper with a float hp
// snapshot, the base damage call, and typed virtual calls.
// probe 2: kept DAT_00574c78 for the observed FPU operands but used the
// source literal 1.0f for add_attribute_num; the original pushes the IEEE
// immediate rather than loading the shared float global at that call site.

extern double DAT_00574c88;
extern float DAT_00574c78;

class RGE_Armor_Weapon_Info;
class RGE_Player;
class RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    unsigned char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    void* vftable;
    int id;
    RGE_Master_Static_Object* master_obj;
};

class RGE_Player {
public:
    virtual void slot_00();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1C();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2C();
    virtual void slot_30();
    virtual void slot_34();
    virtual void slot_38();
    virtual void slot_3C();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void slot_4C();
    virtual void slot_50();
    virtual void slot_54();
    virtual void slot_58();
    virtual void slot_5C();
    virtual void slot_60();
    virtual void slot_64();
    virtual void slot_68();
    virtual void slot_6C();
    virtual void slot_70();
    virtual void slot_74();
    virtual void add_attribute_num(short attribute, float amount, unsigned char flag);

    unsigned char gap_04[0x46];
    short id;
};

class RGE_Combat_Object {
public:
    virtual void slot_00();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1C();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2C();
    virtual void slot_30();
    virtual void slot_34();
    virtual void slot_38();
    virtual void slot_3C();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void slot_4C();
    virtual void slot_50();
    virtual void slot_54();
    virtual void slot_58();
    virtual void slot_5C();
    virtual void slot_60();
    virtual void slot_64();
    virtual void slot_68();
    virtual void slot_6C();
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* armor, float value, RGE_Player* player, RGE_Static_Object* target);
    virtual float calculateDamage(int param_1, RGE_Armor_Weapon_Info* armor, float value, RGE_Player* player, RGE_Static_Object* target);
    virtual void slot_78();
    virtual void slot_7C();
    virtual void slot_80();
    virtual void set_attribute_amount(float amount, unsigned char flag, unsigned char mode);
    virtual void slot_88();
    virtual void slot_8C();
    virtual void slot_90();
    virtual void slot_94();
    virtual void slot_98();
    virtual void slot_9C();
    virtual void slot_A0();
    virtual void slot_A4();
    virtual void slot_A8();
    virtual void slot_AC();
    virtual void slot_B0();
    virtual void slot_B4();
    virtual void slot_B8();
    virtual void slot_BC();
    virtual void slot_C0();
    virtual void slot_C4();
    virtual void slot_C8();
    virtual void slot_CC();
    virtual void slot_D0();
    virtual void slot_D4();
    virtual void slot_D8();
    virtual void slot_DC();
    virtual void slot_E0();
    virtual void slot_E4();
    virtual void slot_E8();
    virtual void slot_EC();
    virtual void slot_F0();
    virtual void slot_F4();
    virtual void slot_F8();
    virtual void slot_FC();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_10C();
    virtual void slot_110();
    virtual void slot_114();
    virtual void slot_118();
    virtual void slot_11C();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_12C();
    virtual void slot_130();
    virtual void slot_134();
    virtual void slot_138();
    virtual unsigned char produceWhenKilledBy(int object_group);
    virtual void slot_140();
    virtual void slot_144();
    virtual void notify(int a, int b, int c, int d, int e, int f);

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    unsigned char gap_10[0x20];
    float hp;
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* armor, float value, RGE_Player* player, RGE_Static_Object* target);
};

void TRIBE_Combat_Object::damage(int param_1, RGE_Armor_Weapon_Info* armor, float value, RGE_Player* player, RGE_Static_Object* target)
{
    float temp_hp = this->hp;

    if (this->hp >= DAT_00574c88) {
        RGE_Combat_Object::damage(param_1, armor, value, player, target);

        if (this->hp < DAT_00574c88) {
            if (this->produceWhenKilledBy((int)target->master_obj->object_group) == 0) {
                this->set_attribute_amount(0.0f, 0, 1);
            }
        }

        if (temp_hp - this->hp < DAT_00574c88) {
            this->hp = temp_hp - DAT_00574c78;
        }

        if (this->owner->id > 0 && this->hp < DAT_00574c78) {
            player->add_attribute_num(0x14, 1.0f, 0);
        }
    }
}
