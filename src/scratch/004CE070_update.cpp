// VA 004CE070 TRIBE_Action_Convert::update
// tact_cnv.cpp:311-522
// Attempt log:
// 1: Natural first pass from packet asm/decompiler, with local class/vtable surfaces for observed offsets.
// 2: Fixed RGE_Player layout to expose world at +0x3c, player_id at +0x4a, elapsed at +0x84, conversion_kind at +0x105.
// 3: Fixed RGE_World fields to map +0x38/+0x3c/+0x40 map coordinates and +0x3c player/world object chain used by object lookup.
// 4: Fixed object sprite id at +0x04, type at +0x08, player at +0x0c, angle at +0x26, conversion_time at +0x30, status at +0x48.
// 5: Fixed player relation prototype from short to int so VC5 emits original movsx word [target_player+4a] before call instead of mov ax/push eax.
// 6: Matched broad top call surface: target_id and target2_id object lookups, set_target_obj(0), vf58(0), set_state(3/1), object_command(0x22,0), sprite calls.
// 7: Matched broad state switch semantics including nested get_action_value switches for states 4 and 11, convert gate in state 6, conversion timer/random/chance path in state 7, and state 13 sprite/return 3.
// 8: Tried keeping a saved target_obj local/volatile local to increase register pressure and recover original push ebp; nonvolatile optimized away, volatile perturbed early load order and did not recover original prologue, rolled back.
// 9: Tried /GX and /Ob0: no change from default /O2. Tried /Od and /Oy- diagnostics: both much worse and first mismatch at offset 0; custom flags removed.
// 10: Current default build has exact size 906 but broad mismatch: 772 bytes / 85.2097% positional, 358 bytes / 39.5143% edit, first mismatch offset 2 because rebuilt saves EBX/ESI/EDI but original also saves EBP.
// 11: Remaining blocker is register-pressure/local-topology in large switch/FPU path; original carries target vptr in EBP in state 7 while current standalone C never allocates EBP under /Oy.
// 12: restored the canonical RGE_Action/RGE_Static_Object/RGE_Game_World
// ownership surface from same-TU donors and the generated layout: timer/task/
// sub_actions are +2c/+30/+34, world delta is +84, and turn_towards is +1f0.
// The previous source used decompiler-shaped object fields and a vslot-f0
// proxy; this probe deliberately tests the period typed hierarchy instead.
// 13: restored the repeated target null test as two ordinary guards; this
// recovered the binary's redundant test and exact pre-switch prefix.
// 14: PDB line order requires top switch cases 4, 11, 6, 7, 1, 13; this
// recovered 32/32 ordered call sites and reduced the best diff to 45 bytes.
// 15: Reordering state-4 nested cases or adding source labels was either a
// codegen duplicate or merged the two binary-proven state-13 call sites.
// 16: State-11 nested case order 4, 3, then 1/2/5 recovered exact call/CFG
// parity; remaining drift is localized nested-handler layout/FPU scheduling.
// 17: An explicit cross-switch state-3 failure goto removed one required call
// and broadly worsened layout; rolled back. Best clean source remains here.
// PAUSED: exact matching exhausted for this assignment; left in scratch with
// canonical typed source, 906-byte size, 32/32 calls, and 45 differing bytes.

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(char* file, int line);
extern float DAT_00574ff8;
extern float DAT_00574ffc;
extern float DAT_00575000;
extern float DAT_00575004;

class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Master_Action_Object;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Task;

class RGE_Base_Game {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void notification(int msg, long p1, long p2, long zero1, long zero2);
};
extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18();
    virtual int relation(long player_id);
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74();
    virtual void add_attribute_num(short id, float amount, uchar zero);
    virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90();
    virtual RGE_Static_Object* make_new_object(long id, float x, float y, float z, int zero);

    char gap_04[0x38];
    RGE_Game_World* world;                         // +0x3c
    char gap_40[0x0A];
    short id;                                       // +0x4a
    char gap_4C[0xB9];
    uchar master_player_id;                         // +0x105
};

class RGE_Game_World {
public:
    char gap_00[0x84];
    float world_time_delta_seconds;                 // +0x84
    RGE_Static_Object* object(int id);
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;                             // +0x14
    char gap_16[0x10];
    short hp;                                        // +0x26
};

class RGE_Master_Action_Object : public RGE_Master_Static_Object {
public:
    char gap_28[0xBC];
    float work_rate;                                 // +0xe4
};

class RGE_Static_Object {
public:
    virtual void vf000();
#define V(a) virtual void vf##a();
    V(004) V(008) V(00C) V(010) V(014) V(018) V(01C) V(020)
    V(024) V(028) V(02C) V(030) V(034) V(038) V(03C) V(040)
    virtual void change_ownership(RGE_Player*);
    V(048) V(04C) V(050) V(054) V(058) V(05C) V(060) V(064)
    V(068) V(06C) V(070) V(074) V(078) V(07C)
    virtual void set_attribute(short, float);       // +0x80
    V(084) V(088) V(08C) V(090)
    virtual void notify_of_relation(int, int, int, int, int); // +0x94
    V(098) V(09C) V(0A0) V(0A4) V(0A8) V(0AC) V(0B0) V(0B4)
    V(0B8) V(0BC) V(0C0) V(0C4) V(0C8) V(0CC) V(0D0) V(0D4)
    V(0D8) V(0DC) V(0E0) V(0E4) V(0E8) V(0EC) V(0F0) V(0F4)
    V(0F8) V(0FC) V(100) V(104) V(108) V(10C) V(110) V(114)
    V(118) V(11C) V(120) V(124) V(128) V(12C) V(130) V(134)
    V(138) V(13C) V(140) V(144)
    virtual void notify(int, int, int, long, long, long); // +0x148
    V(14C) V(150) V(154) V(158) V(15C) V(160) V(164) V(168)
    V(16C) V(170) V(174) V(178) V(17C) V(180) V(184) V(188)
    V(18C) V(190) V(194) V(198) V(19C) V(1A0) V(1A4) V(1A8)
    V(1AC) V(1B0) V(1B4) V(1B8) V(1BC) V(1C0) V(1C4) V(1C8)
    V(1CC) V(1D0) V(1D4) V(1D8) V(1DC) V(1E0) V(1E4)
#undef V

    long id;                                        // +0x04
    RGE_Master_Action_Object* master_obj;           // +0x08
    RGE_Player* owner;                              // +0x0c
    char gap_10[0x20];
    float hp;                                       // +0x30
    char gap_34[4];
    float world_x;                                  // +0x38
    float world_y;                                  // +0x3c
    float world_z;                                  // +0x40
    float attribute_amount_held;                    // +0x44
    uchar object_state;                             // +0x48
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual void vf1E8();
    virtual void stop_moving();                     // +0x1ec
    virtual uchar turn_towards(RGE_Static_Object*, float, float); // +0x1f0
    virtual void vf1F4(); virtual void vf1F8(); virtual void vf1FC();
};

class RGE_Action_List {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08();
    virtual uchar update();                         // +0x0c
};

class RGE_Task {
public:
    char gap_00[0x1C];
    float work_val1;                                // +0x1c
};

class RGE_Action {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual short vf18(); virtual void vf1C();
    virtual uchar vf20(); virtual uchar vf24(); virtual uchar update();
    virtual int vf2C(); virtual int vf30(RGE_Static_Object*, float, float, float);
    virtual int vf34(RGE_Static_Object*, float, float, float);
    virtual uchar vf38(RGE_Static_Object*); virtual uchar vf3C(long, uchar);
    virtual void vf40(void*); virtual void vf44(void*, void*, void*);
    virtual void vf48(char*); virtual RGE_Static_Object* vf4C();
    virtual RGE_Static_Object* vf50();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    short action_type;                              // +0x04
    char gap_06[2];
    RGE_Action_Object* obj;                         // +0x08
    uchar state;                                     // +0x0c
    char gap_0D[3];
    RGE_Static_Object* target_obj;                  // +0x10
    RGE_Static_Object* target_obj2;                 // +0x14
    int target_id;                                   // +0x18
    int target2_id;                                  // +0x1c
    float target_x;                                  // +0x20
    float target_y;                                  // +0x24
    float target_z;                                  // +0x28
    float timer;                                     // +0x2c
    RGE_Task* task;                                  // +0x30
    RGE_Action_List* sub_actions;                   // +0x34
    void* sprite;                                    // +0x38
    uchar subActionValue;                            // +0x3c
    char gap_3D[3];
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    virtual uchar update();
    uchar was_same_owner;                            // +0x40
    char gap_41[3];
    float required_range;                            // +0x44
};

uchar TRIBE_Action_Convert::update()
{
    if (this->target_id != -1) {
        if (this->obj->owner->world->object(this->target_id) == 0) {
            this->set_target_obj(0);
            this->set_state(3);
            return 0;
        }
    }

    if (this->target2_id != -1) {
        if (this->obj->owner->world->object(this->target2_id) == 0) {
            this->set_target_obj2(0);
        }
    }

    if (this->target_obj != 0 && this->target_obj->object_state != 2) {
        this->set_target_obj(0);
        this->set_state(3);
        return 0;
    }

    if (this->target_obj != 0 &&
        this->obj->owner->relation(this->target_obj->owner->id) == 1) {
        if (this->state == 7 || this->state == 6 || this->state == 4) {
            this->obj->set_attribute(0x22, 0);
        }
        this->set_state(1);
        this->obj->notify(this->obj->id, this->obj->id, 0x1fb, 0x25c, 0, 0);
        return 4;
    }

    switch (this->state) {
    case 4:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        case 3:
            this->set_state(13);
            return 0;
        case 4:
        case 5:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        }
        break;

    case 11:
        switch (this->sub_actions->update()) {
        case 4:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        case 3:
            this->set_state(13);
            return 0;
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        }
        break;

    case 6:
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        if (this->obj->turn_towards(this->target_obj, 0, 0)) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        RGE_Static_Object* target = this->target_obj;
        if (target == 0) {
            this->set_state(3);
            return 0;
        }
        target->notify(this->obj->id, target->id, 500, this->obj->id,
                       (int)target->master_obj->hp, (int)target->hp);
        this->timer = this->timer - this->obj->owner->world->world_time_delta_seconds;
        if (this->timer <= 0.0f) {
            if (this->target_obj != 0 && this->target_obj->owner->id > 0) {
                this->target_obj->owner->make_new_object(
                    0x70, this->obj->world_x, this->obj->world_y,
                    this->obj->world_z, 0);
            }
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\tact_cnv.cpp", 0x1d7);
            float chance = (float)r * DAT_00574ffc;
            RGE_Player* tplayer = this->target_obj->owner;
            if (tplayer->master_player_id == 0x10) {
                chance = chance * DAT_00575000;
            } else {
                short type = this->target_obj->master_obj->object_group;
                if (type == 0x15 || type == 2 || type == 0x14 || type == 0x16 || type == 0x12) {
                    chance = chance + chance;
                } else if (type == 0x23 || type == 0x17) {
                    chance = chance * DAT_00575004;
                }
            }
            if (chance <= this->obj->master_obj->work_rate * this->task->work_val1) {
                rge_base_game->notification(0x7b, this->target_obj->owner->id,
                                             this->obj->owner->id, 0, 0);
                this->target_obj->change_ownership(this->obj->owner);
                this->obj->owner->add_attribute_num(0x29, 1.0f, 0);
                this->obj->set_attribute(0x22, 0);
                this->set_state(3);
            }
            this->set_state(4);
            return 0;
        }
        break;
    }

    case 1:
        return 1;

    case 13:
        this->obj->notify(this->obj->id, this->obj->id, 0x1f9, 0x25c, 0, 0);
        this->set_state(2);
        return 3;
    }

    return 0;
}
