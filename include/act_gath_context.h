#ifndef ACT_GATH_CONTEXT_H
#define ACT_GATH_CONTEXT_H

// Authentic declaration context for C:\\msdev\\work\\age1_x1\\ACT_GATH.cpp.
//
// The owner bodies in this module were recovered at different stages.  Their
// standalone probes used narrow views of the same period classes.  This file
// gives the module one canonical ABI view, while the owner files retain their
// standalone declarations when this header is not present.

typedef unsigned char uchar;

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Game_World;
class RGE_Master_Action_Object;
class RGE_Master_Static_Object;
class RGE_Object_Info;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Task_List;

struct SomeObj {
    char pad[0x08];
    int* field_08;
    char pad2[0x38];
    float field_44;
    char pad3[0x04];
    short field_4C;
};

struct SubObj {
    char pad[0x14];
    short field_14;
    char pad2[0x28];
    RGE_Sprite* field_40;
};

struct GatherUnit {
    char gap_00[0x44];
    float field_44;
    char gap_48[0x04];
    short field_4C;
};

struct MasterObject {
    char gap_00[0x10];
    short id;
};

class RGE_Sprite {
public:
    char gap_00[0x5E];
    short frame;
    char gap_60[0x10];
    uchar flags;
    char gap_71;
    short id;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
    char gap_12[0xD6];
    short drop_site;
    short backup_drop_site;
};

class RGE_Object_Info {
public:
    char gap_00[0x7C];
    short attribute_type;
    char gap_7E[0x66];
    float gather_multiplier;
};

class RGE_Task {
public:
    short task_type;
    short id;
    uchar is_default;
    uchar gap_05;
    short action_type;
    short object_group;
    short object_id;
    uchar combat_level;
    uchar combat_level_flag;
    short terrain_id;
    uchar owner_type;
    uchar holding_attr;
    uchar state_building;
    uchar gap_13;
    union {
        short attribute_type;
        short facet;
        short field_14;
    };
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float gather_amount;
    float work_val2;
    float work_range;
    uchar search_flag;
    char gap_29[3];
    float search_wait_time;
    short work_flag;
    short work_flag2;
    union {
        RGE_Sprite* move_sprite;
        RGE_Sprite* field_34;
    };
    union {
        RGE_Sprite* work_sprite;
        RGE_Sprite* field_38;
    };
    union {
        RGE_Sprite* work_sprite2;
        RGE_Sprite* field_3C;
    };
    union {
        RGE_Sprite* carry_sprite;
        RGE_Sprite* field_40;
    };
    union {
        RGE_Sound* work_sound;
        RGE_Sound* sound;
    };
    RGE_Sound* work_sound2;
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
    char gap_04[0x80];
    float world_time_delta_seconds;
};

class RGE_Object_List {
public:
    RGE_Static_Object* find_by_master_ids(long, long, float, float,
                                          uchar, uchar, RGE_Static_Object*);
};

class RGE_Player {
public:
    virtual void p00(); virtual void p04(); virtual void p08(); virtual void p0C();
    virtual void p10(); virtual void p14(); virtual void p18(); virtual void p1C();
    virtual void p20(); virtual void p24(); virtual void p28(); virtual void p2C();
    virtual void p30(); virtual void p34(); virtual void p38(); virtual void p3C();
    virtual void p40(); virtual void p44(); virtual void p48(); virtual void p4C();
    virtual void p50(); virtual void p54(); virtual void p58();
    virtual void trackUnitGather(int, int, int);
    virtual void p60(); virtual void p64(); virtual void p68(); virtual void p6C();
    virtual void p70(); virtual void p74();
    virtual void add_attribute_num(short, float, uchar);

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    short fallback_attribute;
    char gap_4E[2];
    float* attribute_table;
    class RGE_Object_List* objects;

    int computerPlayer();
};

class RGE_Sound {
public:
    void play(int param);
};

class RGE_Action_List {
public:
    virtual void l00();
    virtual void l04();
    virtual void l08();
    virtual uchar update();
    void delete_list();
    void add_action(RGE_Action* action);
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void ao01(); virtual void ao02(); virtual void ao03();
    virtual void ao04(); virtual void ao05(); virtual void ao06();
    virtual void ao07(); virtual void ao08(); virtual void ao09();
    virtual void ao0A(); virtual void ao0B(); virtual void ao0C();
    virtual void ao0D(); virtual void ao0E();
    virtual void new_sprite(RGE_Sprite*);
    virtual void ao0F(); virtual void ao10(); virtual void ao11();
    virtual void ao12(); virtual void ao13(); virtual void ao14();
    virtual void ao15(); virtual void ao16(); virtual void ao17();
    virtual void ao18(); virtual void ao19(); virtual void ao1A();
    virtual void ao1B(); virtual void ao1C(); virtual void ao1D();
    virtual void ao1E(); virtual void ao1F();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual void ao22(); virtual void ao23(); virtual void ao24();
    virtual void ao25(); virtual void ao26(); virtual void ao27();
    virtual void ao28(); virtual void ao29(); virtual void ao2A();
    virtual void ao2B(); virtual void ao2C(); virtual void ao2D();
    virtual void ao2E(); virtual void ao2F(); virtual void ao30();
    virtual void ao31(); virtual void ao32(); virtual void ao33();
    virtual void ao34(); virtual void ao35(); virtual void ao36();
    virtual void ao37(); virtual void ao38(); virtual void ao39();
    virtual void ao3A(); virtual void ao3B(); virtual void ao3C();
    virtual void ao3D(); virtual void ao3E(); virtual void ao3F();
    virtual void ao40(); virtual void ao41(); virtual void ao42();
    virtual void ao43(); virtual void ao44(); virtual void ao45();
    virtual void ao46(); virtual void ao47(); virtual void ao48();
    virtual void ao49(); virtual void ao4A(); virtual void ao4B();
    virtual void ao4C(); virtual void ao4D();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual void ao4F();
    virtual unsigned char useSameZoneDropsite();
    virtual void ao51();
    virtual void notify(int, int, int, int, int, int);
    virtual void ao53(); virtual void ao54(); virtual void ao55();
    virtual void ao56(); virtual void ao57(); virtual void ao58();
    virtual void ao59(); virtual void ao5A(); virtual void ao5B();
    virtual void ao5C(); virtual void ao5D(); virtual void ao5E();
    virtual void ao5F(); virtual void ao60(); virtual void ao61();
    virtual void ao62(); virtual void ao63(); virtual void ao64();
    virtual void ao65(); virtual void ao66(); virtual void ao67();
    virtual void ao68(); virtual void ao69(); virtual void ao6A();
    virtual void ao6B(); virtual void ao6C(); virtual void ao6D();
    virtual void ao6E(); virtual void ao6F(); virtual void ao70();
    virtual void ao71(); virtual void ao72(); virtual void ao73();
    virtual void ao74(); virtual void ao75(); virtual void ao76();
    virtual void ao77(); virtual void ao78(); virtual void ao79();
    virtual void ao7A();
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);

    int id;
    union {
        RGE_Master_Static_Object* master_obj;
        RGE_Object_Info* object_data;
    };
    RGE_Player* owner;
    char gap_10[0x28];
    union { float x; float world_x; };
    union { float y; float world_y; };
    union { float z; float world_z; };
    union { float attribute_amount_held; float amount_held; };
    union {
        void* sound;
        uchar object_state;
    } state_sound;
    short attribute_type_held;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void so01(); virtual void so02(); virtual void so03();
    virtual void so04(); virtual void so05(); virtual void so06();
    virtual void so07(); virtual void so08(); virtual void so09();
    virtual void so0A(); virtual void so0B(); virtual void so0C();
    virtual void so0D(); virtual void so0E(); virtual void so0F();
    virtual void so10(); virtual void so11(); virtual void so12();
    virtual void so13(); virtual void so14(); virtual void so15();
    virtual void so16(); virtual void so17(); virtual void so18();
    virtual void so19(); virtual void so1A(); virtual void so1B();
    virtual void so1C(); virtual void so1D(); virtual void so1E();
    virtual void so1F(); virtual void so20(); virtual void so21();
    virtual void so22(); virtual void so23(); virtual void so24();
    virtual void so25(); virtual void so26(); virtual void so27();
    virtual void so28(); virtual void so29(); virtual void so2A();
    virtual void so2B(); virtual void so2C(); virtual void so2D();
    virtual void so2E(); virtual void so2F(); virtual void so30();
    virtual void so31(); virtual void so32(); virtual void so33();
    virtual void so34(); virtual void so35(); virtual void so36();
    virtual void so37(); virtual void so38(); virtual void so39();
    virtual void so3A(); virtual void so3B(); virtual void so3C();
    virtual void so3D(); virtual void so3E(); virtual void so3F();
    virtual void so40(); virtual void so41(); virtual void so42();
    virtual void so43(); virtual void so44(); virtual void so45();
    virtual void so46(); virtual void so47(); virtual void so48();
    virtual void so49(); virtual void so4A(); virtual void so4B();
    virtual void so4C(); virtual void so4D(); virtual void so4E();
    virtual void so4F(); virtual void so50(); virtual void so51();
    virtual void so52(); virtual void so53(); virtual void so54();
    virtual void so55(); virtual void so56(); virtual void so57();
    virtual void so58(); virtual void so59(); virtual void so5A();
    virtual void so5B(); virtual void so5C(); virtual void so5D();
    virtual void so5E(); virtual void so5F(); virtual void so60();
    virtual void so61(); virtual void so62(); virtual void so63();
    virtual void so64(); virtual void so65(); virtual void so66();
    virtual void so67(); virtual void so68(); virtual void so69();
    virtual void so6A(); virtual void so6B(); virtual void so6C();
    virtual void so6D(); virtual void so6E(); virtual void so6F();
    virtual void so70(); virtual void so71(); virtual void so72();
    virtual void so73(); virtual void so74(); virtual void so75();
    virtual void so76(); virtual void so77(); virtual void so78();
    virtual void so79(); virtual void so7A(); virtual void so7B();
    virtual void so7C(); virtual void so7D(); virtual void so7E();
    virtual void so7F(); virtual void so80();

    long id;
    union {
        RGE_Master_Static_Object* master_obj;
        MasterObject* master;
        RGE_Action_Object* obj;
    };
    RGE_Player* owner;
    char gap_10[0x28];
    union { float world_x; float target_x; float x; };
    union { float world_y; float target_y; float y; };
    union { float world_z; float target_z; float z; };
    union { float attribute_amount_held; float amount_held; };
    union { void* sound; uchar object_state; } state_sound;
    char gap_49[3];
    short attribute_type_held;
    float distance_to_object(RGE_Static_Object*);
    virtual void set_attribute_amount(float, uchar, uchar);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(uchar);
    virtual uchar inside_obj_update();
    virtual uchar idle_update();
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual uchar attack_response(RGE_Static_Object*);
    virtual uchar relation_response(long, uchar);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    RGE_Action();
    RGE_Action(int, int);
    RGE_Action(int, RGE_Action_Object*, int);
    RGE_Action(RGE_Action_Object*, int);
    void setSubAction(uchar);

    short action_type;
    char gap_06[2];
    union {
        RGE_Action_Object* obj;
        SomeObj* field_08;
        GatherUnit* unit;
    };
    uchar state;
    char gap_0D[3];
    union {
        RGE_Static_Object* target_obj;
        RGE_Static_Object* gatherTarget;
    };
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    union { float target_x; float x_dest; };
    union { float target_y; float y_dest; };
    union { float target_z; float z_dest; };
    float timer;
    union {
        RGE_Task* task;
        SubObj* field_30;
    };
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    uchar subActionValue;
    char gap_3D[3];
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    float range;
};

class RGE_Action_Gather : public RGE_Action {
public:
    virtual ~RGE_Action_Gather();
    virtual void save(int);
    virtual void first_in_stack(uchar);
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual void set_state(uchar);

    RGE_Action_Gather(int, RGE_Action_Object*);
    RGE_Action_Gather(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    RGE_Action_Gather(int, RGE_Task*, float, float, float);
    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();

    union {
        int targetType;
        int gather_field_40;
        int field_40;
    };
};

class RGE_Action_VTable {
public:
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0C();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1C();
    virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2C();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3C();
    virtual void s40(); virtual void s44(); virtual void s48(); virtual void s4C();
    virtual void s50(); virtual void func54(int); virtual void func58(int); virtual void func5C(int);
};

class ActionGatherVtable {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void _v54(int); virtual void _v58(void*); virtual void _v5C(int);
};

class RGE_Base_Game {
public:
    char gap_00[0x9A8];
    int quick_build;
};

extern RGE_Base_Game* rge_base_game;
extern float DAT_0056e278;
extern double DAT_0056e280;
extern double DAT_0056e290;

void rge_read(int, void*, int);
void rge_write(int, void*, int);

#endif
