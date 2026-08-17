// VA 004CE070 TRIBE_Action_Convert::update
// tact_cnv.cpp:311-522
// Attempt log:
// 1: Natural first pass from packet asm/decompiler, with local class/vtable surfaces for observed offsets.
// 2: Fixed RGE_Player layout to expose world at +0x3c, player_id at +0x4a, elapsed at +0x84, conversion_kind at +0x105.
// 3: Fixed RGE_World fields to map +0x38/+0x3c/+0x40 map coordinates and +0x3c player/world object chain used by object lookup.
// 4: Fixed object sprite id at +0x04, type at +0x08, player at +0x0c, angle at +0x26, conversion_time at +0x30, status at +0x48.
// 5: Fixed player relation prototype from short to int so VC5 emits original movsx word [target_player+4a] before call instead of mov ax/push eax.
// 6: Matched broad top call surface: target_id and target2_id object lookups, set_target_obj(0), set_target_obj2(0), set_state(3/1), set_attribute(0x22,0), sprite calls.
// 7: Matched broad state switch semantics including nested get_action_value switches for states 4 and 11, convert gate in state 6, conversion timer/random/chance path in state 7, and state 13 sprite/return 3.
// 8: Tried keeping a saved target_obj local/volatile local to increase register pressure and recover original push ebp; nonvolatile optimized away, volatile perturbed early load order and did not recover original prologue, rolled back.
// 9: Tried /GX and /Ob0: no change from default /O2. Tried /Od and /Oy- diagnostics: both much worse and first mismatch at offset 0; custom flags removed.
// 10: Current default build has exact size 906 but broad mismatch: 772 bytes / 85.2097% positional, 358 bytes / 39.5143% edit, first mismatch offset 2 because rebuilt saves EBX/ESI/EDI but original also saves EBP.
// 11: Remaining blocker is register-pressure/local-topology in large switch/FPU path; original carries target vptr in EBP in state 7 while current standalone C never allocates EBP under /Oy.
// 12: restored the canonical RGE_Action/RGE_Static_Object/RGE_Game_World
// ownership surface from same-TU donors and the generated layout: timer/task/
// sub_actions are +2c/+30/+34, world delta is +84, and turn_towards is +1f0.
// The previous source used decompiler-shaped object fields and a turn_towards
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
// 18: Named target master ownership before the notify call; VC5 emitted the same
// code, so the local was rolled back.
// 19: Named converted target hp values before notify; VC5 emitted the same code,
// so the locals were rolled back.
// 20: Decoded the original absolute inner jump tables. State 4 maps cases
// 1/2/5 to state 3; state 11 maps 1/2 to state 6 and 4/5 to target reset.
// Ordered those source cases by the PDB handler bands; diff improved to 43.
// 21: Direct target member access was a codegen duplicate.
// 22: Same-class exact donors support int notify parameters; int and long
// surfaces emitted the same code.
// 23: A focused notify alias lab found no better emitted group.
// 24: Reversed the final notify hp arguments. The original pushes master hp,
// runs __ftol for target hp, then pushes target hp; diff improved to 19.
// 25: Removed explicit hp casts; emitted code was unchanged.
// 26: Reversed the work-rate product operands to follow the original FPU
// operand order; VC5 emitted the same code.
// 27: Reversed the conversion notification player arguments; this recovered
// the original push order and reduced the diff from 19 to 10 bytes.
// 28: Named task work and master work-rate values; this fixed their register
// colors and reduced the remaining diff to 8 bytes.
// 29: The first exact pass used a folded +0.0f addend. That source was
// superseded after the canonical ABI audit below.
// 30: Replaced generic virtual-slot declarations with canonical repository
// method names and the RGE_Master/RGE_Animated/RGE_Moving hierarchy.
// 31: The canonical surface made the natural direct work-rate expression exact.
// Removed the temporary aliases and the no-effect zero anchor.
// 32: Made Action_Object::setup a named virtual and omitted only the unobserved
// create_sprite_list slot; this preserves the proven turn_towards slot.
// Exact finish pass 2: direct field ownership, canonical call slots, 906 bytes,
// 32/32 calls, and MATCH at 0.0000%.

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
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Action;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Task;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual void* get_view_panel();
    virtual void* get_map_panel();
    virtual void* new_scenario_header(void*);
    virtual void* new_scenario_header(int);
    virtual void* new_scenario_info(int);
    virtual void notification(int msg, long p1, long p2, long zero1, long zero2);
};
extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int player_id);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, uchar, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short id, float amount, uchar zero);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
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
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player*, float, float, int*, uchar, uchar, uchar, uchar, uchar, uchar);
    virtual uchar alignment(float*, float*, RGE_Game_World*, uchar);
    virtual long calc_base_damage_ability(void*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(void*, short, short, void*, long, long, int, uchar);

    char gap_04[0x10];
    short object_group;                             // +0x14
    char gap_16[0x10];
    short hp;                                        // +0x26
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    virtual ~RGE_Master_Action_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player*, float, float, int*, uchar, uchar, uchar, uchar, uchar, uchar);
    virtual uchar alignment(float*, float*, RGE_Game_World*, uchar);
    virtual long calc_base_damage_ability(void*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(void*, short, short, void*, long, long, int, uchar);
    virtual void* create_task_list();

    char gap_28[0xBC];
    float work_rate;                                 // +0xe4
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, uchar);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, uchar);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, uchar);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, uchar);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, uchar, int);
    virtual void unexplore_terrain(RGE_Player*, uchar, int);
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual uchar underAttack();
    virtual void setUnderAttack(uchar);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual uchar facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(uchar);
    virtual uchar waitingToMove();
    virtual uchar actionState();
    virtual uchar keepGatheringWhenObjectIsOut(int);
    virtual uchar produceWhenKilledBy(int);
    virtual uchar useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int);
    virtual int gather(int, int);
    virtual int convert(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(void*, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(void*, void*, float, void*, int);
    virtual int firstTileAlongLine(void*, void*, void*, int, int, int);
    virtual void* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(void*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual void* findAvoidancePath(void*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void* create_object_list();

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

class RGE_Animated_Object : public RGE_Static_Object {
};

class RGE_Moving_Object : public RGE_Animated_Object {
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
    virtual void work2(RGE_Static_Object*, float, float, float, uchar);
    virtual void set_task(short);
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual uchar inside_obj_update();
    virtual uchar update();
};

class RGE_Task {
public:
    short task_type;
    short id;
    uchar is_default;
    char gap_05;
    short action_type;
    short object_group;
    short object_id;
    uchar combat_level;
    uchar combat_level_flag;
    short terrain_id;
    uchar owner_type;
    uchar holding_attr;
    uchar state_building;
    char gap_13;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;                                // +0x1c
    float work_val2;
    float work_range;
    uchar search_flag;
    char gap_29[3];
    float search_wait_time;
    short work_flag;
    short work_flag2;
    void* move_sprite;
    void* work_sprite;
    void* work_sprite2;
    void* carry_sprite;
    void* work_sound;
    void* work_sound2;
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
        this->obj->owner->isAlly(this->target_obj->owner->id) == 1) {
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
        case 3:
            this->set_state(13);
            return 0;
        case 4:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        }
        break;

    case 11:
        switch (this->sub_actions->update()) {
        case 4:
        case 5:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        case 3:
            this->set_state(13);
            return 0;
        case 1:
        case 2:
            this->set_state(6);
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
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        this->target_obj->notify(
            this->obj->id, this->target_obj->id, 500, this->obj->id,
            this->target_obj->hp, this->target_obj->master_obj->hp);
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
            // BINARY NOTE: Direct field ownership preserves the original x87 order.
            if (chance <= this->task->work_val1 * this->obj->master_obj->work_rate) {
                rge_base_game->notification(0x7b, this->obj->owner->id,
                                             this->target_obj->owner->id, 0, 0);
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
