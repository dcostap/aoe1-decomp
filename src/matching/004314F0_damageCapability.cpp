class RGE_Armor_Weapon_Info;

class RGE_Master_Combat_Object {
public:
    unsigned char gap_00[0x108];
    short weapon_num;
    unsigned char gap_10A[0x2];
    RGE_Armor_Weapon_Info* weapon;
};

class RGE_Static_Object {
public:
        virtual void slot_00();
    virtual void slot_01();
    virtual void slot_02();
    virtual void slot_03();
    virtual void slot_04();
    virtual void slot_05();
    virtual void slot_06();
    virtual void slot_07();
    virtual void slot_08();
    virtual void slot_09();
    virtual void slot_10();
    virtual void slot_11();
    virtual void slot_12();
    virtual void slot_13();
    virtual void slot_14();
    virtual void slot_15();
    virtual void slot_16();
    virtual void slot_17();
    virtual void slot_18();
    virtual void slot_19();
    virtual void slot_20();
    virtual void slot_21();
    virtual void slot_22();
    virtual void slot_23();
    virtual void slot_24();
    virtual void slot_25();
    virtual void slot_26();
    virtual void slot_27();
    virtual void slot_28();
    virtual void slot_29();
    virtual void slot_30();
    virtual void slot_31();
    virtual void slot_32();
    virtual void slot_33();
    virtual void slot_34();
    virtual void slot_35();
    virtual void slot_36();
    virtual void slot_37();
    virtual void slot_38();
    virtual void slot_39();
    virtual void slot_40();
    virtual void slot_41();
    virtual void slot_42();
    virtual void slot_43();
    virtual void slot_44();
    virtual void slot_45();
    virtual void slot_46();
    virtual void slot_47();
    virtual void slot_48();
    virtual void slot_49();
    virtual void slot_50();
    virtual void slot_51();
    virtual void slot_52();
    virtual void slot_53();
    virtual void slot_54();
    virtual void slot_55();
    virtual void slot_56();
    virtual void slot_57();
    virtual void slot_58();
    virtual void slot_59();
    virtual float vf0F0(void* combat_object);

    int id;
    RGE_Master_Combat_Object* master_obj;
    void* owner;
};

class RGE_Combat_Object {
public:
        virtual void slot_00();
    virtual void slot_01();
    virtual void slot_02();
    virtual void slot_03();
    virtual void slot_04();
    virtual void slot_05();
    virtual void slot_06();
    virtual void slot_07();
    virtual void slot_08();
    virtual void slot_09();
    virtual void slot_10();
    virtual void slot_11();
    virtual void slot_12();
    virtual void slot_13();
    virtual void slot_14();
    virtual void slot_15();
    virtual void slot_16();
    virtual void slot_17();
    virtual void slot_18();
    virtual void slot_19();
    virtual void slot_20();
    virtual void slot_21();
    virtual void slot_22();
    virtual void slot_23();
    virtual void slot_24();
    virtual void slot_25();
    virtual void slot_26();
    virtual void slot_27();
    virtual void slot_28();
    virtual float vf074(int weapon_num, RGE_Armor_Weapon_Info* weapon, float base_damage, void* owner, RGE_Static_Object* target);
    virtual float damageCapability(RGE_Static_Object* target);
};

float RGE_Combat_Object::damageCapability(RGE_Static_Object* target) {
    float base_damage;

    base_damage = target->vf0F0(this);
    return vf074(target->master_obj->weapon_num, target->master_obj->weapon, base_damage, target->owner, target);
}
