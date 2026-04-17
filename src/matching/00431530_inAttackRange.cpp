extern "C" double __cdecl sqrt(double value);
#pragma intrinsic(sqrt)

class RGE_Static_Object;

class RGE_Master_Combat_Object {
public:
    unsigned char gap_00[0x30];
    float range_30;
    float range_34;
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
    virtual void slot_70();
    virtual void slot_74();
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
    virtual float vf10C();

    int id;
    RGE_Master_Combat_Object* master_obj;

    float distance_to_object(RGE_Static_Object* obj);
    int inAttackRange(RGE_Static_Object* obj);
};

int RGE_Combat_Object::inAttackRange(RGE_Static_Object* obj) {
    float radius_distance;
    float max_distance;
    float range_x;
    float range_y;

    range_x = master_obj->range_30;
    range_y = master_obj->range_34;
    radius_distance = range_x * range_x + range_y * range_y;
    radius_distance = (float)sqrt((double)radius_distance);
    max_distance = vf10C() + radius_distance - -0.300000012f;
    if (distance_to_object(obj) <= max_distance) {
        return 1;
    }
    return 0;
}
