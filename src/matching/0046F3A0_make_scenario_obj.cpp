// player.cpp:734-749, 102 bytes
// attempt 1: 61.8%, vtable offsets wrong (createObj at +0 vs +0x18, vfs at +0/+4/+8 vs +0x68/+0x6C/+0xB4)
// attempt 2: pad vtables to match original slot offsets
class RGE_Static_Object {
public:
    virtual void vf00_0();
    virtual void vf00_1();
    virtual void vf00_2();
    virtual void vf00_3();
    virtual void vf00_4();
    virtual void vf00_5();
    virtual void vf00_6();
    virtual void vf00_7();
    virtual void vf00_8();
    virtual void vf00_9();
    virtual void vf00_A();
    virtual void vf00_B();
    virtual void vf00_C();
    virtual void vf00_D();
    virtual void vf00_E();
    virtual void vf00_F();
    virtual void vf00_10();
    virtual void vf00_11();
    virtual void vf00_12();
    virtual void vf00_13();
    virtual void vf00_14();
    virtual void vf00_15();
    virtual void vf00_16();
    virtual void vf00_17();
    virtual void vf00_18();
    virtual void vf00_19();
    virtual void vf68();          // +0x68 (slot 26)
    virtual void vf6C();          // +0x6C (slot 27)
    virtual void vf00_28();
    virtual void vf00_29();
    virtual void vf00_2A();
    virtual void vf00_2B();
    virtual void vf00_2C();
    virtual void vf00_2D();
    virtual void vf00_2E();
    virtual void vf00_2F();
    virtual void vf00_30();
    virtual void vf00_31();
    virtual void vf00_32();
    virtual void vf00_33();
    virtual void vf00_34();
    virtual void vf00_35();
    virtual void vf00_36();
    virtual void vf00_37();
    virtual void vf00_38();
    virtual void vfB4(float);     // +0xB4 (slot 44)
};

class RGE_Master_Static_Object {
public:
    virtual void vf00_0();
    virtual void vf00_1();
    virtual void vf00_2();
    virtual void vf00_3();
    virtual void vf00_4();
    virtual void vf00_5();
    virtual void* vf18(void*, float, float, float); // +0x18 (slot 6)
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects; // +0x24

    RGE_Static_Object* make_scenario_obj(float x, float y, float z, short typeID, unsigned char objType, float param6);
};

RGE_Static_Object* RGE_Player::make_scenario_obj(float x, float y, float z, short typeID, unsigned char objType, float param6) {
    RGE_Static_Object* obj = 0;
    RGE_Master_Static_Object* master = this->master_objects[typeID];
    if (master != 0) {
        obj = (RGE_Static_Object*)master->vf18(this, x, y, z);
        if (objType >= 7) {
            obj->vf68();
        } else if (objType > 2) {
            obj->vf6C();
        } else {
            obj->vfB4(param6);
        }
    }
    return obj;
}
