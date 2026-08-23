#ifndef COM_OBJ_ENTER_CONTEXT_H
#define COM_OBJ_ENTER_CONTEXT_H

// Shared class surface for the ordered com_obj.cpp owners in com_obj_enter_tu.cpp.
typedef unsigned char uchar;

class RGE_Action_Object;
class RGE_Task;
class RGE_Static_Object;
class RGE_Action;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x84];
    void** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    void** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

    RGE_Static_Object* object(int index);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Master_Combat_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    char gap_004[0x11C];
    float speed_of_attack;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Combat_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    int world_x;
    int world_y;
    int world_z;
    uchar gap_44[0x44];
};

class RGE_Action_List {
public:
    char gap_00[8];
    void* list;

    uchar have_action();
    RGE_Action* get_action();
    void delete_list();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void slot_14();
    virtual short func18();
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
    virtual RGE_Static_Object* func4C();

    short action_type;
    uchar gap_06[2];
    void* obj;
    uchar state;
    uchar gap_0D[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    void* sprite;
    uchar subActionValue;
    uchar gap_3D[3];
};

class RGE_Action_Enter : public RGE_Action {
public:
    virtual ~RGE_Action_Enter();
    RGE_Action_Enter(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Moving_Object();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d0a();
    virtual void d0b();
    virtual void d0c();
    virtual void d0d();
    virtual void d0e();
    virtual void d0f();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d1a();
    virtual void d1b();
    virtual void d1c();
    virtual void d1d();
    virtual void d1e();
    virtual void d1f();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d2a();
    virtual void d2b();
    virtual void d2c();
    virtual void d2d();
    virtual void d2e();
    virtual void d2f();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d3a();
    virtual void d3b();
    virtual void d3c();
    virtual void d3d();
    virtual void d3e();
    virtual void d3f();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d4a();
    virtual void d4b();
    virtual void d4c();
    virtual void d4d();
    virtual void d4e();
    virtual void d4f();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d5a();
    virtual void d5b();
    virtual void d5c();
    virtual void d5d();
    virtual void d5e();
    virtual void d5f();
    virtual int enter(int param_1, int param_2);
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d6a();
    virtual void d6b();
    virtual void d6c();
    virtual void d6d();
    virtual void d6e();
    virtual void d6f();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d7a();
    virtual void d7b();
    virtual void d7c();
    virtual void d7d();
    virtual void d7e();
    virtual void d7f();
    virtual void d80();
    virtual void d81();
    virtual void add_action(RGE_Action* action) = 0;
    virtual void d82();
    virtual RGE_Task* make_enter_task(RGE_Static_Object* obj, int x, int y, int z) = 0;

    uchar gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    uchar waiting;
    uchar gap_181[3];
    RGE_Action_List* actions;
    uchar command_flag;
    uchar gap_189[3];
    int lastActionValue;
    int lastActionStateValue;
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    uchar gap_194[0x28];
    float attack_timer;
    uchar gap_1C0[4];

    void reset_attack_timer();
    virtual int enter(int param_1, int param_2);
};

#endif
