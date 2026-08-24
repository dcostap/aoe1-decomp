#ifndef TACT_REP_CONTEXT_H
#define TACT_REP_CONTEXT_H

// Canonical declarations for the tact_rep.cpp source module.
//
// The action hierarchy and the virtual slots below follow the reviewed
// tact_hea/tact_bld surfaces.  The named slots are the slots used by the
// tact_rep owners.  Other slots are declaration-only padding slots; they do
// not create function bodies or source owners.

typedef unsigned char uchar;

class XYPoint;
class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Action_Object_Data;
class RGE_Game_World;
class RGE_Master_Action_Object;
class RGE_Object_List;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Base_Game;

class RGE_Sprite {
public:
    char gap_00[0x5E];
    short frame;
    char gap_60[0x10];
    uchar flags;
    uchar gap_71;
    short id;
};

// The action-object master carries the proven id/group fields and the
// master work rate used by update().
class RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Action_Object();
    char gap_04[0x0C];
    short id;             // +10
    short copy_id;        // +12
    short object_group;   // +14
    char gap_16[0xCE];
    float work_rate;      // +E4
};

class RGE_Action_Object_Data {
public:
    char gap_00[0x14];
    short object_type;                                  // +14
    char gap_16[2];
    RGE_Sprite* sprite;   // +18
    char gap_1C[0xF8];
    float work_range;     // +114
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();                    // +00
    virtual void vpad04();                           // +04
    virtual void vpad08();                           // +08
    virtual void vpad0C();                           // +0C
    virtual void vpad10();                           // +10
    virtual void vpad14();                           // +14
    virtual void vpad18();                           // +18
    virtual void vpad1C();                           // +1C
    virtual void vpad20();                           // +20
    virtual void vpad24();                           // +24
    virtual void vpad28();                           // +28
    virtual void vpad2C();                           // +2C
    virtual void vpad30();                           // +30
    virtual void vpad34();                           // +34
    virtual void new_sprite(RGE_Sprite*);             // +38
    virtual void vpad3C();                            // +3C
    virtual void vpad40();                            // +40
    virtual void vpad44();                            // +44
    virtual void vpad48();                            // +48
    virtual void vpad4C();                            // +4C
    virtual void vpad50();                            // +50
    virtual void vpad54();                            // +54
    virtual void vpad58();                            // +58
    virtual void vpad5C();                            // +5C
    virtual void vpad60();                            // +60
    virtual void vpad64();                            // +64
    virtual void vpad68();                            // +68
    virtual void vpad6C();                            // +6C
    virtual void vpad70();                            // +70
    virtual void vpad74();                            // +74
    virtual void vpad78();                            // +78
    virtual void vpad7C();                            // +7C
    virtual void vpad80();                            // +80
    virtual void vpad84();                            // +84
    virtual uchar heal(float);                        // +88
    virtual int heal(int, int);                       // +8C
    virtual void vpad90();                            // +90
    virtual void vpad94();                            // +94
    virtual void vpad98();                            // +98
    virtual void vpad9C();                            // +9C
    virtual void vpadA0();                            // +A0
    virtual void vpadA4();                            // +A4
    virtual void vpadA8();                            // +A8
    virtual void vpadAC();                            // +AC
    virtual void vpadB0();                            // +B0
    virtual void vpadB4();                            // +B4
    virtual void vpadB8();                            // +B8
    virtual void vpadBC();                            // +BC
    virtual void vpadC0();                            // +C0
    virtual void vpadC4();                            // +C4
    virtual void vpadC8();                            // +C8
    virtual RGE_Static_Object* get_target_obj();      // +CC
    virtual void vpadD0();                            // +D0
    virtual void vpadD4();                            // +D4
    virtual void vpadD8();                            // +D8
    virtual void vpadDC();                            // +DC
    virtual void vpadE0();                            // +E0
    virtual void vpadE4();                            // +E4
    virtual void vpadE8();                            // +E8
    virtual void vpadEC();                            // +EC
    virtual void vpadF0();                            // +F0
    virtual void vpadF4();                            // +F4
    virtual void vpadF8();                            // +F8
    virtual void vpadFC();                            // +FC
    virtual void vpad100();                           // +100
    virtual void vpad104();                           // +104
    virtual void vpad108();                           // +108
    virtual void vpad10C();                           // +10C
    virtual void vpad110();                           // +110
    virtual void vpad114();                           // +114
    virtual void vpad118();                           // +118
    virtual void vpad11C();                           // +11C
    virtual void vpad120();                           // +120
    virtual void vpad124();                           // +124
    virtual void vpad128();                           // +128
    virtual void vpad12C();                           // +12C
    virtual void vpad130();                           // +130
    virtual uchar actionState();                      // +134
    virtual void vpad138();                           // +138
    virtual void vpad13C();                           // +13C
    virtual void vpad140();                           // +140
    virtual void vpad144();                           // +144
    virtual void notify(int, int, int, long, long, long); // +148
    virtual void vpad14C();                           // +14C
    virtual void vpad150();                           // +150
    virtual int moveTo(float, float, float, float, int);  // +154
    virtual void vpad158();                           // +158
    virtual void vpad15C();                           // +15C
    virtual void vpad160();                           // +160
    virtual void vpad164();                           // +164
    virtual void vpad168();                           // +168
    virtual void vpad16C();                           // +16C
    virtual void vpad170();                           // +170
    virtual void vpad174();                           // +174
    virtual void vpad178();                           // +178
    virtual void vpad17C();                           // +17C
    virtual void vpad180();                           // +180
    virtual void vpad184();                           // +184
    virtual void vpad188();                           // +188
    virtual void vpad18C();                           // +18C
    virtual void vpad190();                           // +190
    virtual void vpad194();                           // +194
    virtual void vpad198();                           // +198
    virtual void vpad19C();                           // +19C
    virtual void vpad1A0();                           // +1A0
    virtual void vpad1A4();                           // +1A4
    virtual void vpad1A8();                           // +1A8
    virtual void vpad1AC();                           // +1AC
    virtual void vpad1B0();                           // +1B0
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int); // +1B4
    virtual void vpad1B8();                           // +1B8
    virtual void vpad1BC();                           // +1BC
    virtual void vpad1C0();                           // +1C0
    virtual void vpad1C4();                           // +1C4
    virtual void vpad1C8();                           // +1C8
    virtual void vpad1CC();                           // +1CC
    virtual void vpad1D0();                           // +1D0
    virtual void vpad1D4();                           // +1D4
    virtual void vpad1D8();                           // +1D8
    virtual void vpad1DC();                           // +1DC
    virtual void vpad1E0();                           // +1E0
    virtual void vpad1E4();                           // +1E4

    long id;                                           // +04
    union {
        RGE_Master_Action_Object* master_obj;         // +08
        RGE_Action_Object_Data* object_data;          // +08
    };
    RGE_Player* owner;                                 // +0C
    char gap_10[0x28];                                 // to +38
    float world_x;                                     // +38
    float world_y;                                     // +3C
    float world_z;                                     // +40
    float attribute_amount_held;                      // +44
    uchar object_state;                                // +48
    char gap_49[0x13B];                                // to +184
    RGE_Action_List* actions;                          // +184
    uchar command_flag;                                // +188

    void removeAllFromPathingGroup();
    float distance_to_object(RGE_Static_Object*);
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Action_Object();
    virtual int setup_animated(void*, RGE_Player*, float, float, float); // +1E8
    virtual void stop_moving();                         // +1EC
    virtual uchar turn_towards(RGE_Static_Object*, float, float); // +1F0
    virtual int setup_moving(void*, RGE_Player*, float, float, float); // +1F4
    virtual void work2(RGE_Static_Object*, float, float, float, uchar); // +1F8
    virtual void set_task(short);                       // +1FC
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x80];
    float world_time_delta_seconds;                     // +84
    RGE_Static_Object* object(int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vpad04();
    virtual void vpad08();
    virtual void vpad0C();
    virtual void vpad10();
    virtual void vpad14();
    virtual void vpad18();
    virtual int isAlly(int);                             // +1C

    char gap_04[0x24];
    RGE_Object_List* objects;                            // +28
    char gap_2C[0x10];
    RGE_Game_World* world;                               // +3C
    char gap_40[0x0A];
    short id;                                            // +4A
};

class RGE_Task {
public:
    char gap_00[0x1C];
    float work_rate;                                     // +1C
    char gap_20[4];
    float range;                                         // +24
    char gap_28[0x0C];
    RGE_Sprite* move_sprite;                             // +34
    RGE_Sprite* work_sprite;                             // +38
    RGE_Sprite* work_sprite2;                            // +3C
    RGE_Sprite* carry_sprite;                            // +40
    RGE_Sound* work_sound;                               // +44
    RGE_Sound* work_sound2;                              // +48
};

class RGE_Action_List {
public:
    virtual void vpad00();
    virtual void vpad04();
    virtual void vpad08();
    virtual uchar update();                              // +0C
    void delete_list();
    void add_action(RGE_Action*);
    RGE_Action* get_action();
};

class RGE_Sound {
public:
    void play(int);
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
    virtual void copy_obj(void*);
    virtual void copy_obj_sprites(void*, void*, void*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    short action_type;                                   // +04
    char gap_06[2];
    RGE_Action_Object* obj;                              // +08
    uchar state;                                         // +0C
    char gap_0D[3];
    RGE_Static_Object* target_obj;                       // +10
    RGE_Static_Object* target_obj2;                      // +14
    int targetID;                                        // +18
    int target2ID;                                       // +1C
    float target_x;                                      // +20
    float target_y;                                      // +24
    float target_z;                                      // +28
    float timer;                                         // +2C
    RGE_Task* task;                                      // +30
    RGE_Action_List* sub_actions;                       // +34
    RGE_Sprite* sprite;                                  // +38
    uchar subActionValue;                                // +3C
    char gap_3D[3];

    RGE_Action(int, RGE_Action_Object*, int);
    RGE_Action(RGE_Action_Object*, int);
    RGE_Action(int, int);
    void setSubAction(uchar);
    float targetX();
    float targetY();
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    float range;
};

class XYPoint {
public:
    int x;
    int y;
};

class RGE_Object_Node {
public:
    RGE_Action_Object* object;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    void* vtable_ptr;
    RGE_Object_Node* list;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void vpad04();
    virtual void vpad08();
    virtual void vpad0C();
    virtual void vpad10();
    virtual void vpad14();
    virtual void vpad18();
    virtual void vpad1C();
    virtual void vpad20();
    virtual void vpad24();
    virtual void vpad28();
    virtual void vpad2C();
    virtual void vpad30();
    virtual void vpad34();
    virtual void vpad38();
    virtual void vpad3C();
    virtual void notification(int, long, long, long, long); // +40
};

class TRIBE_Action_Repair : public RGE_Action {
public:
    TRIBE_Action_Repair(int, RGE_Action_Object*, int);
    TRIBE_Action_Repair(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Repair(int, RGE_Task*, float, float, float);

    virtual int setup(int, RGE_Action_Object*);
    virtual void save(int);
    virtual void first_in_stack(uchar);
    virtual void set_state(uchar);
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);

    void meet_target();
    union {
        uchar save_target_command_flag;                  // +40
        uchar repair_field_40;                            // setup() view
    };
};

extern float save_game_version;
extern void rge_read(int, void*, int);
extern "C" void __cdecl rge_write(int, void*, int);
extern RGE_Base_Game* rge_base_game;
extern float DAT_0057526c;
extern double DAT_00575270;
extern float DAT_00575278;
extern float DAT_0086bc08;
extern float DAT_005750e0;
extern double DAT_005750e8;

#endif
