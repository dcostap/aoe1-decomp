// 004C8740 TRIBE_Building_Object::set_object_state
// Source: t_b_obj.cpp lines 289-391
// Attempt log:
// - Replaced the former partial/manual-vtable scaffold with a complete typed
//   state-2 build path, state-3 doppleganger cleanup, terrain updates, tech
//   bookkeeping, and qualified base state call.
// - Baseline is intentionally period-plausible and uses real virtual/member
//   surfaces for the observed slots; no explicit vptr or raw vtable calls.
// - Corrected the inherited Static->Moving->Action->Combat->TRIBE_Combat
//   boundary and the +1C8 production-queue block before building fields.
// - Inverted the play-animation arm, used direct typed map calls, and bound
//   only positive terrain extents to DAT_005749E8; this recovered exact size,
//   ordered calls, CFG, and nearly all bytes.
// - The final two-byte drift was the terrain-object create argument order;
//   the binary pushes world_z, world_y, world_x, so the natural call is
//   create(owner, world_x, world_y, world_z). Exact after validation.

#ifndef T_B_OBJ_CONTEXT_H
typedef unsigned char uchar;

class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class RGE_Object_List;
class RGE_Static_Object;
class TRIBE_Master_Building_Object;
class TRIBE_Building_Object;
class TRIBE_Player_Tech;

extern "C" int debug_rand(char*, int);
extern "C" void debug_srand(char*, int, int);
extern int debug_random_on;
extern double DAT_005749E8;

#define VPAD1(n) virtual void vpad_##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD7(n) VPAD4(n) VPAD2(n##_4) VPAD1(n##_6)
#define VPAD15(n) VPAD8(n) VPAD4(n##_8) VPAD2(n##_12) VPAD1(n##_14)

class RGE_Sound {
public:
    void play(int value);
};

class RGE_Doppleganger_Creator {
public:
    int remove_doppleganger_check(TRIBE_Building_Object* object);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    VPAD1(ms1)
    VPAD1(ms2)
    VPAD1(ms3)
    VPAD1(ms4)
    VPAD1(ms5)
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);

    char gap_04[0x10 - 0x04];
    short id;                                      // +0x10
    char gap_12[0x18 - 0x12];
    int action_value;                              // +0x18
    char gap_1C[0x5C - 0x1C];
    float radius_x;                                // +0x5C
    float radius_y;                                // +0x60
    char gap_64[0x15A - 0x64];
    short build_time;                              // +0x15A
    char gap_15C[0x164 - 0x15C];
    RGE_Sound* completion_sound;                   // +0x164
    char gap_168[0x16C - 0x168];
    uchar connect_flag;                            // +0x16C
    uchar gap_16D;
    uchar gather_flag_copy;                        // +0x16E
    uchar gap_16F;
    uchar play_animation_flag;                     // +0x170
    short terrain_1;                               // +0x172
    short terrain_2;                               // +0x174
    char gap_176[2];
    short tech_id;                                 // +0x178
    char gap_17A[0x17C - 0x17A];
};

class TRIBE_Master_Building_Object : public RGE_Master_Static_Object {
public:
    char gap_17C[0x180 - 0x17C];
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    VPAD15(p001)
    VPAD16(p010)
    VPAD16(p020)
    VPAD16(p030)
    VPAD1(p080)
    virtual void notify_building(TRIBE_Building_Object*, int); // +0x104

    char gap_04[0x24 - 0x04];
    RGE_Master_Static_Object** object_infos;        // +0x24
    RGE_Object_List* objects;                       // +0x28
    char gap_2C[0x3C - 0x2C];
    RGE_Game_World* world;                          // +0x3C
    RGE_Doppleganger_Creator* doppleganger_creator; // +0x40
    char gap_44[0x4A - 0x44];
    short id;                                        // +0x4A
    char gap_4C[0x220 - 0x4C];
    TRIBE_Player_Tech* tech;                        // +0x220
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x24];
    RGE_Map* map;                                    // +0x28
    char gap_2C[0x40 - 0x2C];
    RGE_Player** players;                            // +0x40
    char gap_44[0x7C - 0x44];
    short sound_player_id;                           // +0x7C
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    void* list;
    RGE_Static_Object* find_by_master_id(long, float, float, uchar, uchar,
                                         RGE_Static_Object*);
};

class TRIBE_Player_Tech {
public:
    uchar do_tech(short);
    uchar undo_tech(short);
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    void set_terrain(RGE_Player*, RGE_Game_World*, int, int, long, long,
                     uchar, uchar, int);
    void request_redraw(int, int, int, int, uchar);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    VPAD15(g001)
    virtual void send(int, int, int, int, int);     // +0x40
};

extern RGE_Base_Game* rge_base_game;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    VPAD7(s001)
    VPAD4(s008)
    VPAD2(s00C)
    virtual void set_master_field(int);             // +0x38
    VPAD8(s00F)
    virtual void set_object_state(uchar);            // +0x5C
    VPAD2(s018)
    VPAD1(s01A)
    virtual void play_animation();                  // +0x6C
    VPAD16(s01C)
    VPAD8(s02C)
    VPAD2(s034)
    virtual void action_finished(RGE_Player*, int, int); // +0xD8
    virtual void action_started(RGE_Player*, int, int);  // +0xDC
    VPAD16(s038)
    VPAD16(s048)
    VPAD16(s058)
    VPAD16(s068)
    VPAD16(s078)
    VPAD8(s088)
    VPAD4(s090)
    VPAD2(s094)
    virtual void remove_from_world();               // +0x258
    virtual void finish_build();                    // +0x25C

    long id;                                         // +0x04
    TRIBE_Master_Building_Object* master_obj;       // +0x08
    RGE_Player* owner;                               // +0x0C
    char gap_10[0x35 - 0x10];
    uchar terrain_restriction;                       // +0x35
    char gap_36[0x38 - 0x36];
    float world_x;                                   // +0x38
    float world_y;                                   // +0x3C
    float world_z;                                   // +0x40
    float gap_44;
    uchar object_state;                              // +0x48
    char gap_49[0x88 - 0x49];
};

class RGE_Moving_Object : public RGE_Static_Object {
public:
    char gap_88[0xF8];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    char gap_180[0x14];
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    char gap_194[0x30];
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    char gap_1C4[4];
};

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    void* production_queue;                         // +0x1C8
    short production_queue_size;                    // +0x1CC
    short production_queue_count;                   // +0x1CE
    uchar production_queue_enabled;                 // +0x1D0
    char gap_1D1[3];
    void* production_queue_actions;                 // +0x1D4
    uchar production_queue_change_flag;             // +0x1D8
    uchar production_queue_auto_paused;              // +0x1D9
    short production_queue_need_attr;               // +0x1DA

    float build_pts;                                 // +0x1DC
    int unique_build_id;                             // +0x1E0
    char gap_1E4[0x1E5 - 0x1E4];
    uchar built;                                     // +0x1E5
    char gap_1E6[0x1E8 - 0x1E6];
    int dopple_installed;                            // +0x1E8

    void connect();
    void set_object_state(uchar);
};
#endif

void TRIBE_Building_Object::set_object_state(uchar state)
{
    uchar dopple_removed;

    uchar state_copy;
    state_copy = state;

    if (state_copy == 2) {
        this->build_pts = (float)(int)this->master_obj->build_time;

        int random_value = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\t_b_obj.cpp", 0x12B);
        int old_random = debug_random_on;
        debug_random_on = 0;

        RGE_Sound* sound = this->master_obj->completion_sound;
        if (sound != 0 && this->owner->id == this->owner->world->sound_player_id) {
            sound->play(1);
        }

        debug_random_on = old_random;
        debug_srand((char*)"C:\\msdev\\work\\age1_x1\\t_b_obj.cpp", 0x135,
                    random_value);

        this->built = 1;
        this->finish_build();

        if (this->master_obj->play_animation_flag != 0) {
            this->play_animation();
        } else {
            this->action_started(this->owner, 1, -1);
            this->action_finished(this->owner, 0, -1);
            this->set_master_field(this->master_obj->action_value);
            this->terrain_restriction = this->master_obj->gather_flag_copy;
            if (this->master_obj->connect_flag != 0) {
                this->connect();
            }
        }

        if (this->master_obj->terrain_1 > -1) {
            this->owner->object_infos[this->master_obj->terrain_1]->make_new_obj(
                this->owner, this->world_x, this->world_y, this->world_z);
        }

        if (this->master_obj->terrain_2 > -1) {
            RGE_Game_World* world = this->owner->world;
            world->map->set_terrain(
                world->players[0], world,
                (long)(this->world_x - this->master_obj->radius_x),
                (long)(this->world_y - this->master_obj->radius_y),
                (long)(this->world_x + this->master_obj->radius_x - DAT_005749E8),
                (long)(this->world_y + this->master_obj->radius_y - DAT_005749E8),
                (uchar)this->master_obj->terrain_2, 1, 0);

            this->owner->world->map->request_redraw(
                (short)(this->world_x - this->master_obj->radius_x) - 1,
                (short)(this->world_y - this->master_obj->radius_y) - 1,
                (short)(this->world_x + this->master_obj->radius_x - DAT_005749E8) + 1,
                (short)(this->world_y + this->master_obj->radius_y - DAT_005749E8) + 1,
                0);
        }

        if (this->master_obj->tech_id > -1) {
            this->owner->tech->do_tech(this->master_obj->tech_id);
        }

        rge_base_game->send(0x69, (int)this->owner->id,
                            (int)this->master_obj->id,
                            (int)(this->world_x), (int)(this->world_y));
        this->owner->notify_building(this, this->unique_build_id);
    }

    if (state_copy == 3 && this->object_state == 2) {
        this->remove_from_world();
        this->owner->doppleganger_creator->remove_doppleganger_check(this);
        this->dopple_installed = 0;
        dopple_removed = 1;
    } else {
        dopple_removed = 0;
    }

    RGE_Static_Object::set_object_state(state);

    if (dopple_removed != 0) {
        RGE_Static_Object* object = this->owner->objects->find_by_master_id(
            (long)this->master_obj->id, -1.0f, -1.0f, 1, 2, 0);
        if (object == 0) {
            if (this->master_obj->tech_id > -1) {
                this->owner->tech->undo_tech(this->master_obj->tech_id);
            }
            this->owner->tech->undo_tech(0x4A);
            this->owner->tech->undo_tech(0x4B);
            this->owner->tech->undo_tech(0x4C);
        }
    }
}
