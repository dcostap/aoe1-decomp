// VA: 004CF860 TRIBE_Action_Hunt::update
// PDB source: tact_hnt.cpp:384-794
// Attempt log:
// - initial bounded reconstruction from complete packet/Ghidra CFG; exact class offsets and virtual slots modeled locally.
// - validated baseline has exact 1587B size, 0xC frame, and 54/54 call-target counts,
//   but ordered calls are only 70.37% (-12/+12, 4 replacements), shape is 48.83%,
//   and strict diff is 1375B (86.6415%). Remains broad STRUCTURAL RECONSTRUCTION.
// - Direct-state and floating-global probes were no-ops or worse. Restored the
//   baseline. A late state-1 arm probe improved diff to 1282B but moved calls;
//   it was diagnostic only and was restored.
// - Original assembly proves state-8 uses target_obj2 for its distance guard,
//   target_obj after gathering, and task sound/attribute fields; fixed these owners.
// - Original jump tables prove the state-11/15 subaction arms and the state-8
//   no-state-change path; restored those behaviors and moved state 1 late.
// - Reordered the outer and nested arms from PDB line order. This raised shape
//   similarity to 88.73% and ordered-call alignment to 94.44%.
// - Original assembly proves a positive self-held state-7 path sets state 8.
//   The clean source keeps that behavior, but VC5 merges one state-3 call.
// - Twenty-two distinct hypotheses were checked. A positive-first guard gave
//   all 54 calls but added 149 bytes. It was rejected as non-natural and wide.
// - Final clean result: 1587B, 0xC frame, 53/54 calls, 1056B strict diff.
//   Remaining blocker is the merged state-12 state-3 call and block layout.
// - Follow-up probes tested shared-tail placement, state-8 case order, and
//   typed state-12 returns. They were unchanged or worse; the clean body is restored.
// - Replaced generic action and action-list placeholders with the exact donor
//   base surfaces. Emitted code is unchanged, but the source now names proven ABI.

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

#ifndef TACT_HNT_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Action;
class RGE_Task;
class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual unsigned char inside_obj_update();
    virtual unsigned char update();
};
class RGE_Sound;
class RGE_Sprite;

class RGE_Game_World {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void v_a0(); virtual void v_a4(); virtual void v_a8(); virtual void v_ac();
    virtual void v_b0(); virtual void v_b4(); virtual void v_b8(); virtual void v_bc();
    virtual void v_c0(); virtual void v_c4(); virtual void v_c8(); virtual void v_cc();
    virtual void v_d0(); virtual void v_d4(); virtual void v_d8(); virtual void v_dc();
    virtual void v_e0(); virtual void v_e4(); virtual void v_e8(); virtual void v_ec();
    virtual void v_f0(); virtual void v_f4(); virtual void v_f8(); virtual void v_fc();
    RGE_Static_Object* object(int id);
    char gap_04[0x7c];
    float world_time_delta_seconds; // +84
    char gap_88[0x20];
    float* attribute_modifiers; // +a8 (only used through known raw offsets)
};

class RGE_Player {
public:
    virtual void q00(); virtual void q04(); virtual void q08(); virtual void q0c();
    virtual void q10(); virtual void q14(); virtual void q18(); virtual void q1c();
    virtual void q20(); virtual void q24(); virtual void q28(); virtual void q2c();
    virtual void q30(); virtual void q34(); virtual void q38(); virtual void q3c();
    virtual void q40(); virtual void q44(); virtual void q48(); virtual void q4c();
    virtual void q50(); virtual void q54(); virtual void q58();
    virtual void trackUnitGather(int, int, int); // +5c
    virtual void q60(); virtual void q64(); virtual void q68(); virtual void q6c();
    virtual void q70(); virtual void q74();
    virtual void add_attribute_num(short, float, unsigned char); // +78
    virtual void update();
    char gap_04[0x38];
    RGE_Game_World* world; // +3c
    char gap_40[0x0c];
    short fallback_attribute; // +4c
    char gap_4e[2];
    float* attribute_table; // +50
    int player_id; // +54
    int computerPlayer();
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
    char gap_12[0xd6];
    short drop_site; // +e8
    short backup_drop_site; // +ea
};

class RGE_Static_Object {
public:
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c();
    virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2c();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3c();
    virtual void s40(); virtual void s44(); virtual void s48(); virtual void s4c();
    virtual void s50(); virtual void s54(); virtual void s58(); virtual void s5c();
    virtual void s60(); virtual void s64(); virtual void s68(); virtual void s6c();
    virtual void s70(); virtual void s74(); virtual void s78(); virtual void s7c();
    virtual void s80(); virtual void set_attribute_amount(float, unsigned char, unsigned char); virtual void s88(); virtual void s8c();
    int id; // +4
    RGE_Master_Static_Object* master_obj; // +8
    RGE_Player* owner; // +c
    char gap_10[0x34];
    float attribute_amount_held; // +44
    union {
        RGE_Sound* sound; // +48
        unsigned char object_state; // +48
    };
    float distance_to_object(RGE_Static_Object* other);
};

class RGE_Sound {
public:
    void play(int);
};

class RGE_Object_Info {
public:
    char gap_00[0x7c];
    short attribute_type; // +7c
    char gap_7e[0x64];
    float gather_multiplier; // +e4
};

class RGE_Action_Object {
public:
    virtual void a00();
    virtual void a01();
    virtual void a02();
    virtual void a03();
    virtual void a04();
    virtual void a05();
    virtual void a06();
    virtual void a07();
    virtual void a08();
    virtual void a09();
    virtual void a0a();
    virtual void a0b();
    virtual void a0c();
    virtual void a0d();
    virtual void a0e();
    virtual void a0f();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a1a();
    virtual void a1b();
    virtual void a1c();
    virtual void a1d();
    virtual void a1e();
    virtual void a1f();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a2a();
    virtual void a2b();
    virtual void a2c();
    virtual void a2d();
    virtual void a2e();
    virtual void a2f();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a3a();
    virtual void a3b();
    virtual void a3c();
    virtual void a3d();
    virtual void a3e();
    virtual void a3f();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a4a();
    virtual void a4b();
    virtual void a4c();
    virtual void a4d();
    virtual void a4e();
    virtual void a4f();
    virtual void a50();
    virtual void a51();
    virtual void notify(int, int, int, int, int, int);
    virtual void a53();
    virtual void a54();
    virtual void a55();
    virtual void a56();
    virtual void a57();
    virtual void a58();
    virtual void a59();
    virtual void a5a();
    virtual void a5b();
    virtual void a5c();
    virtual void a5d();
    virtual void a5e();
    virtual void a5f();
    virtual void a60();
    virtual void a61();
    virtual void a62();
    virtual void a63();
    virtual void a64();
    virtual void a65();
    virtual void a66();
    virtual void a67();
    virtual void a68();
    virtual void a69();
    virtual void a6a();
    virtual void a6b();
    virtual void a6c();
    virtual void a6d();
    virtual void a6e();
    virtual void a6f();
    virtual void a70();
    virtual void a71();
    virtual void a72();
    virtual void a73();
    virtual void a74();
    virtual void a75();
    virtual void a76();
    virtual void a77();
    virtual void a78();
    virtual void a79();
    virtual void a7a();
    virtual void stop_moving();
    virtual unsigned char turn_towards(RGE_Static_Object*, int, int);
    virtual void a7d();
    int id; // +4
    void* object_data; // +8
    RGE_Player* owner; // +c
    float distance_to_object(RGE_Static_Object*);
    char gap_10[0x34];
    float attribute_amount_held; // +44
};

class RGE_Task {
public:
    short task_type; // +00
    short id; // +02
    unsigned char is_default; // +04
    unsigned char gap_05;
    short action_type; // +06
    short object_group; // +08
    short object_id; // +0a
    unsigned char combat_level; // +0c
    unsigned char combat_level_flag; // +0d
    short terrain_id; // +0e
    unsigned char owner_type; // +10
    unsigned char holding_attr; // +11
    unsigned char state_building; // +12
    unsigned char gap_13;
    short attribute_type; // +14
    short attribute_type2; // +16
    short attribute_type3; // +18
    short attribute_type4; // +1a
    float work_val1; // +1c
    float work_val2; // +20
    float work_range; // +24
    unsigned char search_flag; // +28
    unsigned char gap_29[3];
    float search_wait_time; // +2c
    short work_flag; // +30
    short work_flag2; // +32
    RGE_Sprite* move_sprite; // +34
    RGE_Sprite* work_sprite; // +38
    RGE_Sprite* work_sprite2; // +3c
    RGE_Sprite* carry_sprite; // +40
    RGE_Sound* work_sound; // +44
    RGE_Sound* work_sound2; // +48
};

class RGE_Base_Game {
public:
    char gap_00[0x9a8];
    int quick_build; // +9a8
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
    virtual void first_in_stack(unsigned char);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual unsigned char attack_response(RGE_Static_Object*);
    virtual unsigned char relation_response(long, unsigned char);
    virtual void copy_obj(void*);
    virtual void copy_obj_sprites(void*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);
    short action_type; char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state; char gap_0d[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x, target_y, target_z, timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    void* sprite;
    unsigned char subActionValue; char gap_3d[3];
};

class TRIBE_Action_Hunt : public RGE_Action {
public:
    virtual unsigned char update();
    virtual void set_state(unsigned char);
    int targetType;
};
#endif

double DAT_00575158 = 0.0;
double DAT_00575168 = 1.0;
float DAT_00575150 = 0.0f;

unsigned char TRIBE_Action_Hunt::update()
{
    float give_amount;
    volatile float modifier;
    float max_hold;
    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0)
        this->set_target_obj(0);
    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0)
        this->set_target_obj2(0);

    RGE_Static_Object* p = this->target_obj;
    if (p != 0 && p->object_state >= 7)
        this->set_target_obj(0);
    p = this->target_obj2;
    if (p != 0 && p->object_state >= 7)
        this->set_target_obj2(0);

    switch (this->state) {
    case 3:
        if (this->timer < 0.0) {
            this->timer += *(float*)((char*)this->obj->owner->world + 0x84);
            if (this->timer > 0.0) {
                this->timer = -10.0f;
                this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x265, this->targetType, 0);
                return 0;
            }
        }
        break;
    case 11:
    case 15:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 5:
            this->set_target_obj(0);
            if (this->state == 11) { this->set_state(11); return 0; }
            this->set_state(15); return 0;
        case 4:
            if (this->state == 11) { this->set_state(3); return 0; }
            goto computer_fallback;
        case 3:
            if (this->obj->owner->computerPlayer() == 1) { this->set_state(13); return 0; }
            goto state_default;
        }
        break;
state_default:
        this->set_state(3); return 0;
    case 4:
        switch (this->sub_actions->update()) {
        case 3:
            if (this->obj->owner->computerPlayer() != 0) {
                this->set_state(13); return 0;
            }
            goto state_default;
        case 1:
        case 2:
            this->set_state(6); return 0;
        case 4:
        case 5:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        }
        break;
    case 12:
        switch (this->sub_actions->update()) {
        case 4:
            this->set_target_obj(0);
            this->set_state(11); return 0;
        case 1:
        case 2:
        case 5:
            if (this->target_obj != 0) { this->set_state(4); return 0; }
        case 3:
            this->set_state(3); return 0;
        }
        break;
    case 6:
        if (this->target_obj == 0) { this->set_state(3); return 0; }
        if (this->obj->turn_towards(this->target_obj, 0, 0)) {
            if (this->target_obj->attribute_amount_held <= DAT_00575150) {
                this->set_target_obj(0); this->set_state(3); return 0;
            }
            this->set_state(7); return 0;
        }
        goto state_default;
    case 7: {
        RGE_Static_Object* holder = this->target_obj;
        if (holder == 0) {
            holder = (RGE_Static_Object*)this->obj;
            if (holder->attribute_amount_held <= DAT_00575150)
                goto state_default;
            this->set_state(8);
            return 0;
        }
        if (rge_base_game->quick_build != 0)
            give_amount = holder->attribute_amount_held;
        else {
#ifdef TACT_HNT_SHARED_CONTEXT
            give_amount = this->task->work_val1 *
                static_cast<RGE_Master_Action_Object*>(this->obj->master_obj)->work_rate *
                *(float*)((char*)this->obj->owner->world + 0xe4);
#else
            give_amount = this->task->work_val1 *
                *(float*)((char*)this->obj->object_data + 0xe4) *
                *(float*)((char*)this->obj->owner->world + 0xe4);
#endif
        }
        if (holder->attribute_amount_held < give_amount)
            give_amount = holder->attribute_amount_held;
        short attr = this->task->attribute_type2;
        if (attr == -1) modifier = 1.0f;
        else modifier = this->obj->owner->attribute_table[attr];
#ifdef TACT_HNT_SHARED_CONTEXT
        max_hold = (float)static_cast<RGE_Master_Static_Object*>(this->obj->master_obj)->attribute_max_amount * modifier - this->obj->attribute_amount_held;
#else
        max_hold = (float)*(short*)((char*)this->obj->object_data + 0x7c) * modifier - this->obj->attribute_amount_held;
#endif
        if (max_hold < modifier * give_amount)
            give_amount = give_amount - (modifier * give_amount - max_hold) / modifier;
        holder->set_attribute_amount(-give_amount, 1, 1);
        this->obj->set_attribute_amount(give_amount, 1, 0);
        if (this->obj->attribute_amount_held <= give_amount || this->obj->attribute_amount_held <= DAT_00575150)
            this->set_state(8);
        break;
    }
    case 8:
        if (this->timer < 0.0) {
            this->timer += *(float*)((char*)this->obj->owner->world + 0x84);
            if (this->timer > 0.0) {
                this->timer = 0.0;
                this->set_target_obj2(0);
                this->set_state(8);
                return 0;
            }
        } else {
            switch (this->sub_actions->update()) {
            case 1:
            case 2:
                if (this->target_obj2 == 0) { this->set_state(8); return 0; }
                if (this->obj->distance_to_object(this->target_obj2) > DAT_00575168) {
                    this->timer = -1.5f;
                    this->obj->stop_moving();
                    return 0;
                }
                if (this->task->work_sound2 != 0) this->task->work_sound2->play(1);
                { short attr = this->task->attribute_type3; if (attr == -1) attr = this->obj->owner->fallback_attribute;
                  this->obj->owner->add_attribute_num(attr, this->obj->attribute_amount_held, 0); }
                this->obj->owner->trackUnitGather(this->obj->id, this->obj->id, (int)this->obj->attribute_amount_held);
                this->obj->set_attribute(-1, 0.0f);
                if (this->target_obj != 0) { this->set_target_obj2(0); this->set_state(4); return 0; }
                if (this->target_x != -1.0f && this->target_y != -1.0f) { this->set_state(11); return 0; }
                goto computer_fallback;
            case 3:
            case 4:
            case 5:
                this->timer = -1.5f; this->obj->stop_moving(); return 0;
            }
        }
        break;
computer_fallback:
        if (this->obj->owner->computerPlayer() == 0) {
        this->set_state(2);
        return 0;
    }
    this->set_state(1);
state_default2:
    return 0;
    case 1:
        if (this->obj->owner->computerPlayer() == 0)
            this->set_state(2);
        return 1;
    case 13:
        this->obj->notify(this->obj->id, this->obj->id, 0x1f9, 0x265, 0, 0);
        return 3;
    }
    return 0;
}
