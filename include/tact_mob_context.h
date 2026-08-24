#ifndef AOE1_TACT_MOB_CONTEXT_H
#define AOE1_TACT_MOB_CONTEXT_H

#include "game_globals.h"
#include <string.h>

typedef unsigned char uchar;

class RGE_Action_Object;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Master_Action_Object;
class RGE_Player;
class RGE_Static_Object;
class TRIBE_Player;
class RGE_Base_Game_Hack;
struct ObjList;

void rge_read(int, void*, int);
extern "C" void __cdecl rge_write(int, void*, int);
extern float save_game_version;
extern RGE_Base_Game_Hack* rge_base_game;
extern "C" int __cdecl debug_rand(char*, int);
extern float DAT_005751A0;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual void create_action_list();
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
    virtual void copy_obj(void*);
    virtual void copy_obj_sprites(void*, void*, void*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);

    union {
        short action_type;
        short field_04;
    };
    uchar pad_06[2];
    RGE_Action_Object* obj;
    union {
        uchar state;
        uchar field_0C;
        uchar field_C;
    };
    uchar pad_0D[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    union {
        float target_x;
        float place_x;
    };
    union {
        float target_y;
        float place_y;
    };
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    void* sprite;
    uchar subActionValue;
    uchar pad_3D[3];

    RGE_Action(RGE_Action_Object*, int);
    RGE_Action(int, RGE_Action_Object*, int);
};

class RGE_Game_World {
public:
    char gap_00[0x84];
    float world_time_delta_seconds;
};

struct RGE_Static_Object {
    void* vtable;
    union {
        int id;
        void* field_04;
    };
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual RGE_Static_Object* create(TRIBE_Player*, float, float, float);
    virtual void v1C();
    virtual uchar can_place(TRIBE_Player*, float, float, int, int, int, int, int, int, int);

    char gap_04[0x2C];
    float radius_x;
    float radius_y;
    char gap_38[0x122];
    short train_time;
};

struct RGE_Master_Static_Object_Update {
    char gap_00[0x15A];
    short train_time;
};

class RGE_Master_Action_Object {
public:
    char gap_00[0x30];
    float radius_x;
    float radius_y;
    char gap_38[0xAC];
    float work_rate;
};

class RGE_Action_Object {
public:
    void* vtable;
    union {
        int id;
        void* field_04;
    };
    union {
        RGE_Master_Action_Object* master_obj;
        RGE_Master_Action_Object* master;
    };
    union {
        TRIBE_Player* owner;
        ObjList* obj_list;
    };
    char gap_10[0x28];
    union {
        float world_x;
        float x;
    };
    union {
        float world_y;
        float y;
    };
    float world_z;
};

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6C(); virtual void v70();
    virtual void v74(); virtual void v78(); virtual void v7C(); virtual void v80();
    virtual void v84(); virtual void v88(); virtual void v8C(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9C(); virtual void vA0();
    virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual uchar command_place_object(short, float, float, float);
    virtual void vB4(); virtual void vB8(); virtual void vBC(); virtual void vC0();
    virtual void vC4(); virtual void vC8(); virtual void vCC(); virtual void vD0();
    virtual void vD4(); virtual void vD8(); virtual void vDC(); virtual void vE0();
    virtual void debug_log(const char*, int, int, int);
    virtual void vE8(); virtual void vEC(); virtual void vF0(); virtual void vF4();
    virtual void vF8(); virtual void vFC(); virtual void v100(); virtual void v104();
    virtual void v108();
    virtual void cancel_make(int, int, int, int);
    virtual void placement_success(int, int, int, int);

    char gap_04[0x20];
    union {
        RGE_Master_Static_Object_Update** objects;
        RGE_Master_Static_Object** master_objects;
    };
    char gap_28[0x14];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short player_id;
    char gap_4C[0x98];
    float work_rate;

    uchar pay_obj_cost(short, float, int);
    void reimburse_obj_cost(short);
};

class RGE_Base_Game_Hack {
public:
    virtual ~RGE_Base_Game_Hack();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void display_message(int, int, int, int, int);
    char gap_44[0x9A4];
    int quick_build;
};

class RGE_Action_Object_Hack {
public:
    virtual ~RGE_Action_Object_Hack();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6C(); virtual void v70();
    virtual void v74(); virtual void v78(); virtual void v7C(); virtual void v80();
    virtual void v84(); virtual void v88(); virtual void v8C(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9C(); virtual void vA0();
    virtual void vA4(); virtual void vA8(); virtual void vAC(); virtual void vB0();
    virtual void vB4(); virtual void vB8(); virtual void vBC(); virtual void vC0();
    virtual void vC4(); virtual void vC8(); virtual void vCC(); virtual void vD0();
    virtual void vD4(); virtual void vD8(); virtual void vDC(); virtual void vE0();
    virtual void vE4(); virtual void vE8(); virtual void vEC(); virtual void vF0();
    virtual void vF4(); virtual void vF8(); virtual void vFC(); virtual void v100();
    virtual void v104(); virtual void v108(); virtual void v10C(); virtual void v110();
    virtual void v114(); virtual void v118(); virtual void v11C(); virtual void v120();
    virtual void v124(); virtual void v128(); virtual void v12C(); virtual void v130();
    virtual void v134(); virtual void v138(); virtual void v13C(); virtual void v140();
    virtual void v144();
    virtual void slot148(int, int, int, int, int, int);
};

struct __declspec(novtable) PlayerVtbl {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27();
    virtual void d28(); virtual void d29(); virtual void d30(); virtual void d31();
    virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35();
    virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43();
    virtual void d44(); virtual void d45(); virtual void d46(); virtual void d47();
    virtual void d48(); virtual void d49(); virtual void d50(); virtual void d51();
    virtual void d52(); virtual void d53(); virtual void d54(); virtual void d55();
    virtual void d56();
    virtual void __cdecl logFn(const char*, int, int, int);
    virtual void e58(); virtual void e59(); virtual void e60(); virtual void e61();
    virtual void e62(); virtual void e63(); virtual void e64(); virtual void e65();
    virtual void e66();
    virtual void zeroFn(int, int, int, int);
};

struct __declspec(novtable) ObjVtbl {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27();
    virtual void d28(); virtual void d29(); virtual void d30(); virtual void d31();
    virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35();
    virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43();
    virtual void d44(); virtual void d45(); virtual void d46(); virtual void d47();
    virtual void d48(); virtual void d49(); virtual void d50(); virtual void d51();
    virtual void d52(); virtual void d53(); virtual void d54(); virtual void d55();
    virtual void d56(); virtual void d57(); virtual void d58(); virtual void d59();
    virtual void d60(); virtual void d61(); virtual void d62(); virtual void d63();
    virtual void d64(); virtual void d65(); virtual void d66(); virtual void d67();
    virtual void d68(); virtual void d69(); virtual void d70(); virtual void d71();
    virtual void d72(); virtual void d73(); virtual void d74(); virtual void d75();
    virtual void d76(); virtual void d77(); virtual void d78(); virtual void d79();
    virtual void d80(); virtual void d81();
    virtual void spawnFn(int, int, int, int, int, int);
};

struct __declspec(novtable) StateVtbl {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22();
    virtual void stateFn(int);
};

typedef TRIBE_Player PlayerForPay;
typedef RGE_Action_Object_Hack ObjectHack;

class TRIBE_Action_Make_Obj_Base {
public:
    virtual ~TRIBE_Action_Make_Obj_Base();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58();
    virtual void slot23(int);
};

struct ObjInfo {
    char gap_00[8];
    char* name;
    char gap_0C[0x14E];
    short work_rate;
};

struct ObjList {
    char gap_00[0x24];
    ObjInfo** entries;
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    virtual ~TRIBE_Action_Make_Obj();
    virtual void save(int);
    virtual void first_in_stack(uchar);
    virtual uchar update();
    virtual int stop();

protected:
    virtual void set_state(uchar);

public:
    union {
        short obj_id;
        unsigned short field_40;
    };
    uchar pad_42[2];
    union {
        float work_done;
        float speed;
    };
    int unique_id;
    uchar pre_paid;
    uchar pad_4D[3];

    TRIBE_Action_Make_Obj(int, RGE_Action_Object*);
    TRIBE_Action_Make_Obj(RGE_Action_Object*, short, int, uchar);
    void get_info(short&, short&, char*, short);

protected:
    uchar place_obj(RGE_Static_Object**);
};

typedef char tact_mob_action_size[(sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_mob_make_obj_size[(sizeof(TRIBE_Action_Make_Obj) == 0x50) ? 1 : -1];

#endif
