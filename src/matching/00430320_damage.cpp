class RGE_Armor_Weapon_Info;
class RGE_Player;
class RGE_Static_Object {
public:
    void* vftable;
    int id;
};

class RGE_Master_Combat_Object {
public:
    unsigned char gap_00[0x26];
    short hp;
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
    virtual void slot_84();
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
    virtual void slot_13C();
    virtual void slot_140();
    virtual void slot_144();
    virtual void vf148(int target_id, int self_id, int order, int other_id, int hp_value, int master_hp);

    int id;
    RGE_Master_Combat_Object* master_obj;
    RGE_Player* owner;
    unsigned char gap_10[0x20];
    float hp;
};

void RGE_Combat_Object::damage(int param_1, RGE_Armor_Weapon_Info* armor, float value, RGE_Player* player, RGE_Static_Object* target) {
    hp -= calculateDamage(param_1, armor, value, player, target);
    if (target != 0) {
        vf148(target->id, id, 0x1F4, target->id, (int)hp, master_obj->hp);
    }
    if (hp < 1.0) {
        hp = 0.0f;
    }
}
