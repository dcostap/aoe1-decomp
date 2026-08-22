// VA: 00403590 RGE_Action_Gather::update (1620B)
// PDB source: ACT_GATH.cpp
// Attempt log:
// try 1: natural switch/state reconstruction from packet; exact action/object/player field offsets and observed virtual slots.
// try 2: corrected state/object virtual surfaces; build reached 1612 bytes, frame 8 vs 0xc.
// try 3: widened RGE_Static_Object/RGE_Action_Object vtables; frame reached exact 0xc and size 1620.
// try 4: restored target-owner mismatch guard; longest aligned run improved to 91, but switch body remains structurally divergent.
// try 5: corrected gather state numbering and action virtual slots; no metric improvement.
// try 6: added typed gather/action methods and natural FPU locals; calls remain 49 vs original 53.
// try 7: paused at budget; blocker is switch/jump-table body and missing repeated set_state/set_target virtual calls (19/22 slot 0x5c, 1/2 slot 0x138, 1/2 slot 0x1ec).
// current pass: restored the ACT_GATH switch handler order, fallback tails, static-object +0x84 setter slot, and state-7/state-8 checks; calls now match by target count and shape reached 78.21%.
// remaining: jump-table relocation/body placement and one merged +0x1ec stop call; left the typed state-machine reconstruction in scratch.
// main audit removed volatile scheduling locals and named the player-id and
// object-info fields that prior source accessed through raw displacements.
// probe: reordered both nested result switches to the binary body order and
// joined the two result-3 arms through one named player check; this moved the
// ordered call prefix from 10 to 35 and reduced the diff to 1082 bytes.
// probe: inverted the state-7 empty-holder amount test to match the original
// branch polarity; this restored the missing vslot+0x5c call count.
// probe: state-8 null guard uses target_obj2 (+0x14), as shown by the original
// load before distance_to_object; capacity naming had no emitted-code effect.
// remaining: original state-8 stop-result call is a separate vslot+0x1ec
// site, while VC5 merges it with the distance-stop path in this reconstruction.
// BINARY NOTE: both state-8 stop paths store 0xC0400000, which is -3.0f.
// managed pass: 20 meaningful probes. Binary-supported fixes retained below:
// full RGE_Task ownership, target-object state-6 turn/check, static master
// ownership, task sound and attribute fields, TU threshold globals, and the
// static-object distance-call owner. The natural result is 1620B, frame 8,
// 52/53 calls, 1144 strict-diff bytes, and 79.94% shape. A volatile modifier
// probe reached frame 0xc and 1125 diff bytes, but policy rejects fake volatile.
// Rejected probes tested case order, switch exits, aliases, class call surfaces,
// arithmetic order, local scope, conditional assignment, and timer constants.

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;
class RGE_Sprite;
class RGE_Sound { public: void play(int); };
class RGE_Action_List;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;

class RGE_Action {
public:
    virtual void v00();
    virtual int setup(RGE_Action_Object*);
    virtual int setup_file(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void v10();
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
    virtual void copy_obj_sprites(void*, void*, void*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];
    int targetType;
};

class RGE_Object_Info {
public:
    char gap_00[0x7C];
    short attribute_type;
    char gap_7E[0x66];
    float gather_multiplier;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
    char gap_12[0xD6];
    short drop_site;
    short backup_drop_site;
};

class RGE_Static_Object {
public:
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0C();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1C();
    virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2C();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3C();
    virtual void s40(); virtual void s44(); virtual void s48(); virtual void s4C();
    virtual void s50(); virtual void s54(); virtual void s58(); virtual void s5C();
    virtual void s60(); virtual void s64(); virtual void s68(); virtual void s6C();
    virtual void s70(); virtual void s74(); virtual void s78(); virtual void s7C();
    virtual void s80();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x34];
    float attribute_amount_held;
    union { void* sound; unsigned char object_state; } state_sound;
    float distance_to_object(RGE_Static_Object*);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
};

class RGE_Action_Object {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual unsigned char object_type();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual unsigned char check_attribute(short);
    virtual void v4F();
    virtual void v50();
    virtual void v51();
    virtual void notify(int, int, int, int, int, int);
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5A();
    virtual void v5B();
    virtual void v5C();
    virtual void v5D();
    virtual void v5E();
    virtual void v5F();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6A();
    virtual void v6B();
    virtual void v6C();
    virtual void v6D();
    virtual void v6E();
    virtual void v6F();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7A();
    virtual void stop_moving();
    virtual unsigned char turn_towards(RGE_Static_Object*, int, int);
    virtual unsigned char a4E();
    int id;
    RGE_Object_Info* object_data;
    RGE_Player* owner;
    char gap_10[0x34];
    float attribute_amount_held;
    union { void* sound; unsigned char object_state; } state_sound;
    float distance_to_object(RGE_Static_Object*);
};

class RGE_Task {
public:
    short task_type;
    short id;
    unsigned char is_default;
    unsigned char gap_05;
    short action_type;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char owner_type;
    unsigned char holding_attr;
    unsigned char state_building;
    unsigned char gap_13;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float gather_amount;
    float work_val2;
    float work_range;
    unsigned char search_flag;
    char gap_29[3];
    float search_wait_time;
    short work_flag;
    short work_flag2;
    void* move_sprite;
    void* work_sprite;
    void* work_sprite2;
    void* carry_sprite;
    RGE_Sound* work_sound;
    RGE_Sound* work_sound2;
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
    virtual void add_attribute_num(short, float, unsigned char);
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    short fallback_attribute;
    char gap_4E[2];
    float* attribute_table;
    int computerPlayer();
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
    char gap_04[0x80];
    float world_time_delta_seconds;
};

class RGE_Action_List {
public:
    virtual void l00(); virtual void l04(); virtual void l08();
    virtual unsigned char update();
};

class RGE_Base_Game { public: char gap_00[0x9A8]; int quick_build; };

extern RGE_Base_Game* rge_base_game;

class RGE_Action_Gather : public RGE_Action {
public:
    unsigned char update();
};

extern float DAT_0056e278;
extern double DAT_0056e280;
extern double DAT_0056e290;

unsigned char RGE_Action_Gather::update()
{
    float give_amount;
    RGE_Player* check_player;

    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0)
        this->set_target_obj(0);
    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0)
        this->set_target_obj2(0);

    if (this->target_obj != 0 && this->target_obj->state_sound.object_state >= 7)
        this->set_target_obj(0);
    if (this->target_obj2 != 0 && this->target_obj2->state_sound.object_state >= 7)
        this->set_target_obj2(0);

    RGE_Static_Object* check_obj = this->target_obj;
    if (check_obj != 0 && check_obj->owner->id != 0 &&
        check_obj->owner->id != this->obj->owner->id) {
        this->set_state(1);
        this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x261, 0, 0);
        return 4;
    }

    switch ((int)this->state) {
    case 3:
        if (this->timer < DAT_0056e280) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > DAT_0056e280) {
                this->timer = -10.0f;
                this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x261, this->targetType, 0);
                return 0;
            }
        }
        break;

    case 11:
    case 15:
        switch (this->sub_actions->update()) {
        case 4:
            this->set_target_obj(0);
            if (this->state == 11) { this->set_state(11); return 0; }
            this->set_state(15); return 0;
        case 3:
            check_player = this->obj->owner;
            goto computer_check;
        case 1:
        case 2:
        case 5:
            if (this->state == 11) { this->set_state(3); return 0; }
            goto computer_fallback;
        }
        break;

    case 4: {
        unsigned char result = this->sub_actions->update();
        switch (result) {
        case 4:
        case 5:
            this->set_target_obj(0); this->set_state(11); return 0;
        case 3:
            check_player = this->obj->owner;
            goto computer_check;
        case 1:
        case 2:
            this->set_state(6); return 0;
        }
        break;
    }

    case 6:
        if (this->target_obj == 0) { this->set_state(3); return 0; }
        if (this->obj->turn_towards(this->target_obj, 0, 0)) {
            if (this->target_obj->attribute_amount_held <= DAT_0056e278 &&
                this->obj->check_attribute((short)this->target_obj->master_obj->id) == 0) {
                this->set_target_obj(0); this->set_state(3); return 0;
            }
            this->set_state(7); return 0;
        }
        break;

    case 7: {
        float modifier;
        float max_hold;
        if (this->target_obj == 0) {
            if (this->obj->attribute_amount_held > DAT_0056e278) {
                this->set_state(8);
                return 0;
            }
            this->set_state(3);
            return 0;
        }
        if (rge_base_game->quick_build != 0)
            give_amount = this->target_obj->attribute_amount_held;
        else
            give_amount = this->task->gather_amount * this->obj->object_data->gather_multiplier * this->obj->owner->world->world_time_delta_seconds;
        if (give_amount > this->target_obj->attribute_amount_held)
            give_amount = this->target_obj->attribute_amount_held;
        short attr = this->task->attribute_type2;
        if (attr == -1) modifier = 1.0f;
        else modifier = this->obj->owner->attribute_table[attr];
        max_hold = modifier * (float)this->obj->object_data->attribute_type - this->obj->attribute_amount_held;
        if (max_hold < modifier * give_amount)
            give_amount = give_amount - (modifier * give_amount - max_hold) / modifier;
        this->target_obj->set_attribute_amount(-give_amount, 1, 1);
        this->obj->set_attribute_amount(give_amount, 1, 0);
        if (this->obj->attribute_amount_held < give_amount) {
            if (this->obj->attribute_amount_held > DAT_0056e278)
                return 0;
            if (this->obj->check_attribute((short)this->obj->object_data->attribute_type) != 0)
                return 0;
            this->set_state(8);
        }
        break;
    }

    case 8:
        if (this->timer < DAT_0056e280) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > DAT_0056e280) {
                this->timer = 0.0f; this->set_state(8); return 0;
            }
        } else {
            switch (this->sub_actions->update()) {
            case 3:
            case 4:
            case 5:
                this->timer = -3.0f;
                this->obj->stop_moving();
                return 0;
            case 1:
            case 2:
                if (this->target_obj2 == 0) { this->set_state(8); return 0; }
                if (((RGE_Static_Object*)this->obj)->distance_to_object(this->target_obj2) > DAT_0056e290) {
                    this->timer = -3.0f; this->obj->stop_moving(); return 0;
                }
                if (this->task->work_sound2 != 0) this->task->work_sound2->play(1);
                { short attr = this->task->attribute_type3; if (attr == -1) attr = this->obj->owner->fallback_attribute;
                  this->obj->owner->add_attribute_num(attr, this->obj->attribute_amount_held, 0); }
                this->obj->owner->trackUnitGather(this->obj->id, this->obj->id, (int)this->obj->attribute_amount_held);
                this->obj->set_attribute(-1, 0.0f);
                if (this->target_obj != 0) { this->set_target_obj2(0); this->set_state(4); return 0; }
                if (this->target_x != -1.0f && this->target_y != -1.0f) { this->set_state(11); return 0; }
                goto computer_fallback;
            }
        }
        break;

computer_fallback:
    if (this->obj->owner->computerPlayer() == 1) this->set_state(1);
    else this->set_state(2);
    return 0;

computer_check:
    if (check_player->computerPlayer() == 1) { this->set_state(13); return 0; }
    this->set_state(3);
    return 0;

    case 1:
        return 1;

    case 13: {
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x261, 0, 0);
        if (this->obj->owner->computerPlayer() == 1) this->set_state(1);
        else this->set_state(2);
        return 3;
    }
    }

    return 0;
}
