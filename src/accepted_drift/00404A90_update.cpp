// VA: 00404A90 update
// PDB source: ACT_make.cpp lines 61-98
// RGE_Action_Make::update() (277 bytes)
//
// The natural source now uses direct typed member expressions in the fatal
// guard. This matches the body blocks and reduces the positional diff to 41.
// The rebuilt function is 280 bytes, with the original size at 277 bytes.
//
// Original entry saves ESI, reads state, then saves EDI, EBP, and EBX only on
// the non-state-1 path. VC5 saves EBX, EBP, ESI, and EDI at entry in isolation.
// The remaining mismatch is this path-split callee-save sequence and its tails.
// The direct source still gives ESI=this, EDI=target, EBX=inner1, and
// EBP=game-vtable. Its body blocks at +001E..+0104 are exact.
// The action, player, static-object, and base-game declarations now use
// canonical named local surfaces. RGE_Action_Make::update overrides the
// inherited RGE_Action::update slot at +0x28. No generic virtual slots,
// raw action pointers, or source-level save/lifetime steering are used.
//
// Tested in this pass: split work-product initialization, positive fatal guard,
// switch case order, explicit default, narrow base surface, flattened object
// inheritance, case scope, game_globals.h context, and debug-context flags.
// None changed the 41-byte result. A 128-sample ambient declaration sweep also
// kept the old 182-byte alias result. Keep the direct-member source as clean.
// ACCEPTED DRIFT: all 41 changed bytes and the three extra bytes come from
// callee-save shrink wrapping. The original saves EDI, EBP, and EBX only after
// the state-1 return. The rebuild saves them at entry. Both non-state-1 bodies
// are byte-exact. Each tail restores the same registers and stack before the
// same return value. The 0x8 frame, all six calls, predicates, x87 operations,
// object effects, virtual dispatches, cleanup, and fault order match. This
// function has no SEH. Eighty-two focused probes and an ambient declaration
// sweep found no natural source form that restores the split save schedule.
// A later authentic-module lab compiled both constructors, the destructor,
// first_in_stack, set_state, and update after one shared declaration header.
// Default and /GX module builds kept the same 41-byte mismatch. /Ob0, /Ob2,
// /G5, and /GX with /Ob2 also kept it. /O1, /Os, and /G6 changed body code.

#if !defined(ACT_MAKE_CONTEXT_H) || defined(ACT_MAKE_CONTEXT_DECLARE)
class RGE_Master_Moving_Object {
public:
    virtual ~RGE_Master_Moving_Object();
    virtual void modify_delta(float, unsigned char);
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_04[0xE0];
    float work_rate;
    char gap_E8[0x14];
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x80];
    float world_time_delta_seconds;
    char gap_88[0x7C];
};

class RGE_Sprite;
class RGE_Color_Table;
class RGE_Armor_Weapon_Info;
class LOSTBL;
class TDrawArea;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Object_Node;
struct XYZBYTEPoint;
struct _iobuf;
typedef struct _iobuf FILE;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(FILE*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0x04];
    float* attributes;
    char gap_54[0x1CC];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
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
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();

    long id;
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    void* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    void* player_object_node;
    char pathingGroupMembers[0x10];
    char groupMembers[0x10];
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char gap_87;
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Animated_Object();
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    unsigned char waiting;
    char gap_181[0x03];
    RGE_Action_List* actions;
    unsigned char command_flag;
    char gap_189[0x03];
    int lastActionValue;
    int lastActionStateValue;
};

class RGE_Task {
public:
    char gap_00[0x14];
    short attribute_type;
    char gap_16[0x06];
    float work_val1;
    char gap_20[0x10];
    short work_flag;
    char gap_32[0x1A];
};

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
    virtual void notification(int, long, long, long, long);
};

extern RGE_Base_Game* rge_base_game;

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
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    unsigned short action_type;
    unsigned short gap_06;
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x03];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int target_id;
    int target2_id;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[0x03];

    RGE_Action(RGE_Action_Object*, int);
    RGE_Action(int, RGE_Action_Object*, int);
};

class RGE_Action_Make : public RGE_Action {
public:
    virtual ~RGE_Action_Make();
    RGE_Action_Make(int, RGE_Action_Object*);
    RGE_Action_Make(RGE_Action_Object*, RGE_Task*);
    virtual void first_in_stack(unsigned char);
protected:
    virtual void set_state(unsigned char);
public:
    virtual unsigned char update();
};
#endif

#ifndef ACT_MAKE_CONTEXT_DECLARATIONS_ONLY
unsigned char RGE_Action_Make::update() {
    float work;
    float old_attribute_amount;

    switch (this->state) {
    case 6:
        if (this->timer <= 0.0) {
            if (this->obj->owner->attributes[0x24] > 0.0) {
                if (this->obj->attribute_amount_held <= 0.0) {
                    rge_base_game->notification(
                        0x7E, this->obj->owner->id, this->obj->id,
                        (int)this->obj->world_x, (int)this->obj->world_y);
                    this->obj->die_die_die();
                }
                return 0;
            }
        }

        work = this->obj->master_obj->work_rate
             * this->obj->owner->world->world_time_delta_seconds;
        work *= this->task->work_val1;
        old_attribute_amount = this->obj->attribute_amount_held;

        if (this->task->work_flag) {
            this->obj->owner->add_attribute_num(
                this->task->attribute_type, work, 0);
        } else {
            this->obj->set_attribute_amount(work, 1, 1);
        }
        this->timer -= this->obj->attribute_amount_held - old_attribute_amount;

        break;

    case 1:
        return 1;
    }
    return 0;
}
#endif
