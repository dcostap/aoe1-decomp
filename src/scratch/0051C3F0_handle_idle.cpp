// VA: 0051C3F0 TRIBE_Panel_Object::handle_idle (1568B)
// tpnl_obj.cpp
// Attempt log:
// try 1: packet-grounded natural control flow with exact field offsets, virtual slots, and typed object surfaces.
// try 2: corrected active field and object layouts; call set now matches, but frame/CFG remain short.
// try 3: added real get_action and corrected child notify slot; all 25 call targets now align.
// try 4: explored local/frame padding and source guard forms; no exact movement beyond 62% shape.
// try 5: typed the distinct pierce-armor and child notification virtual slots
// from the oracle call map; this is the only post-baseline structural lead.
// try 6: separated typed range and speed output destinations to preserve both
// getter results; retained despite frame growth because this fixes behavior.
// try 7: modeled need_redraw at +38 separately from the parent panel at +40.
// try 8: removed long-lived object/master/combat aliases and reused typed fields;
// this aligned the getter reload pattern and restored the 0x8C frame.
// try 9: kept the function-scope building pointer and saved pre-name flag;
// work_type reuse reached the best current structural result.
// best current check: 1322B diff, 72.42% shape, 0x8C frame, 25/25 calls.
// remaining structural gap: this stays in ESI rather than the oracle's EBP;
// the player guard and local stack homes still differ.
// prior pause state: meaningful code was 1413/1568B with a 0x84/0x8C frame.
// try 10: tested score-loop declaration and do-while forms; the for-loop basin
// is stable and closer to the oracle.
// try 11: tested compound and split player/object guards; none recovered the
// oracle's three null-test blocks without harming call or CFG parity.
// try 12: tested local declaration order and object aliases; register and stack
// homes stayed in the same basin or lost the 0x8C frame.
// try 13: replaced both hand-written name scans with intrinsic strcmp. This
// recovers the oracle's two-byte compare loop and sbb result, raising shape to
// 82.95%; the remaining frame is 0x90 and strict diff is 1350B.
// try 14: restored the 100-byte name buffer from the oracle's +38h stack span;
// retained despite the four-byte frame increase over the 96-byte probe.
// try 15: rewrote the player refresh as one compound guard with one shared
// action arm. Positive p-first lowering improved the probe to 1294B diff,
// 83.13% shape, and exact code size while keeping 25/25 ordered calls.
// try 16: corrected the snapshot flags: attribute and nonzero-count changes
// set changed only; zero-count changes set do_buttons. A negative guard chain
// then reached 90.53% shape and 61.89% exact-block coverage at 1331B diff.
// try 17: used direct ordered population casts instead of named temporaries.
// This recovered the proven 0x8C frame and 1568B code size; the current probe
// is 1332B diff, 85.42% shape, 66.74% exact blocks, and 25/25 calls.
// The direct population form emits pop then max in the original __ftol order.
// Captain pass: direct player-member expressions replaced the short-lived p
// alias. Grouped codegen stayed at 1332B, so the simplification is neutral.
// Captain pass: the nested equality-guard basin was tested and worsened the
// grouped diff to 1344B. The natural early-failure chain remains authoritative.
// Captain pass: including tpnl_obj_context.h under the standalone guard fixes
// validation without changing grouped output. Both checks remain 1332B apart.
// The rebuilt call map uses vslot+240 for get_pierce_armor, while the oracle
// uses vslot+244. This is a shared virtual-surface request, not a local cast.
// Final unresolved source is natural and typed, with 25/25 ordered calls.
// Structural reconstruction remains incomplete.

#ifndef AOE1_TPNL_OBJ_CONTEXT_H
#include "../../include/tpnl_obj_context.h"
#endif

#ifndef AOE1_TPNL_OBJ_CONTEXT_H
struct tagRECT;
class TDrawArea;
class RGE_Color_Table;
class RGE_Armor_Weapon_Info;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Action_Object;
class RGE_Master_Combat_Object;
class LOSTBL;
class Path;
struct XYZPoint;
struct XYPoint;
struct XYZBYTEPoint;
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" int __cdecl strcmp(const char* left, const char* right);
#pragma intrinsic(strcmp)

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int value);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void notify(TPanel*, long, unsigned long, unsigned long);
    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    void* render_area;
    long clip_left;
    long clip_top;
    long clip_right;
    long clip_bottom;
    long position_mode;
    int need_redraw; // +38
    long field_3C;
    TPanel* child; // +40
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    void* node;
    void* first_child_node;
    void* last_child_node;
    TPanel* curr_child;
    long field_64;
    long field_68;
    int active; // +6C
    long field_70;
    long have_focus;
    long field_78;
    long field_7C;
    long field_80;
    long gap_84;
    void* clip_rgn;
    long field_8C;
    long field_90;
    long field_94;
    long field_98;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long field_BC;
    long field_C0;
    long field_C4;
    long field_C8;
    long field_CC;
    long field_D0;
    long field_D4;
    long error_code;
    long field_DC;
    long field_E0;
    long field_E4;
    long field_E8;
    unsigned char field_EC;
    unsigned char field_ED;
    unsigned char field_EE;
    unsigned char field_EF;
    unsigned char field_F0;
    unsigned char gap_F1;
    unsigned char field_F2;
    unsigned char field_F3;

    long handle_idle();
};

class RGE_Object_Node { public: char gap_00[0x10]; };
class TRIBE_Player;
class RGE_Master_Combat_Object;
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    unsigned char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char gap_16[0x12];
    float los;
};
class RGE_Victory_Conditions { public: long get_victory_points(); };
class RGE_Action {
public:
    unsigned char gap_00[0x2C];
    float attribute_amount;
};
class RGE_Action_List { public: RGE_Action* get_action(); };
class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char gap_0A[2];
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
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite();
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
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual Path* findAvoidancePath(XYZPoint*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();
    long id;
    RGE_Master_Static_Object* master_obj;
    TRIBE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
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
    RGE_Object_Node* player_object_node;
    unsigned char gap_54[0x34];
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual int setup(RGE_Master_Animated_Object*, TRIBE_Player*, float, float, float);
    virtual void stop_moving();
    virtual unsigned char turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, TRIBE_Player*, float, float, float);
    virtual void work2(RGE_Static_Object*, float, float, float, unsigned char);
    virtual void set_task(short);
    virtual void setTaskByTaskID(int);
    virtual void set_action(RGE_Action*);
    virtual void set_only_action(RGE_Action*);
    virtual void set_end_action(RGE_Action*);
    virtual RGE_Task* getTask(RGE_Static_Object*, float, float, float);
    virtual int setup(RGE_Master_Action_Object*, TRIBE_Player*, float, float, float);
    unsigned char gap_88[0xF8];
    unsigned char waiting;
    unsigned char gap_181[3];
    RGE_Action_List* actions;
    unsigned char command_flag;
    unsigned char gap_189[3];
    int last_action;
    int last_action_state;
    unsigned char have_action();
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    virtual void create_action_list();
    virtual unsigned char area_attack(float, float, float, RGE_Combat_Object*, RGE_Static_Object*);
    virtual unsigned char attack(float, float, float, RGE_Combat_Object*);
    virtual unsigned char attack(RGE_Static_Object*, RGE_Combat_Object*);
    virtual unsigned char do_attack(RGE_Static_Object*, RGE_Combat_Object*, float, float, float);
    virtual void get_armor(short&, short&);
    virtual void get_weapon(short&, short&);
    virtual void get_weapon_range(float&, float&);
    virtual void get_speed_of_attack(float&, float&);
    virtual int setup_combat(RGE_Master_Combat_Object*, TRIBE_Player*, float, float, float);
    virtual void get_pierce_armor(short&, short&);
};

class TRIBE_Building_Object : public RGE_Combat_Object {
public:
    short get_construction_progress();
    int work_status(short&, short&, short&, char*, short);
    int production_queue_status(short&, short&);
};

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0x18];
    float* attributes;
    char gap_54[0xDC];
    RGE_Static_Object* object_130;
};
class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num;
    char gap_3E[2];
    TRIBE_Player** players;
};
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x3F0];
    RGE_Game_World* world;
    int playerID(int id);
};
extern RGE_Base_Game* rge_base_game;
extern float DAT_00576d84;

class TRIBE_Panel_Object : public TPanel {
public:
    void* font;
    long font_wid;
    long font_hgt;
    void* health_pic;
    void* item_pic;
    void* unit_pics;
    void* bldg_pics;
    TRIBE_Player* player;
    RGE_Static_Object* game_obj;
    unsigned long idle_time;
    unsigned long idle_interval;
    unsigned char mode;
    char gap_121[3];
    RGE_Master_Static_Object* save_obj_type;
    void* save_sprite;
    short save_attr_type;
    char gap_12E[2];
    float save_attr_amount;
    unsigned char save_object_state;
    char gap_135[3];
    float save_build_pts;
    RGE_Object_Node* save_list;
    short save_number_of_objects;
    unsigned char save_can_debark;
    unsigned char gap_143;
    float save_world_x;
    float save_world_y;
    float save_hp;
    short save_armor;
    short save_pierce_armor;
    short save_weapon;
    char gap_156[2];
    float save_weapon_range;
    float save_speed_of_attack;
    short save_work_type;
    short save_work_target;
    short save_progress;
    char save_name[100];
    unsigned char save_facet;
    unsigned char gap_1CB;
    float save_angle;
    float save_los;
    int save_pop;
    int save_max_pop;
    unsigned char save_selected_group;
    char gap_1DD[3];
    TRIBE_Player* save_owner;
    int save_age;
    unsigned char save_have_action; // +1E8
    char gap_1E9[3];
    int save_score[9];
    int save_farm_amt;
    virtual long handle_idle();
    void set_object(RGE_Static_Object*);
    void save_object_info();
};
#endif

long TRIBE_Panel_Object::handle_idle()
{
    TPanel::handle_idle();
    if (this->active == 0) return 0;

    unsigned long now = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp", 0x37C);
    if (now - this->idle_time < this->idle_interval) return 0;
    now = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp", 0x37F);
    this->idle_time = now;

    if (this->mode == 2) {
        for (int i = 1; i < 9; ++i) {
            int p = rge_base_game->playerID(i);
            if (p != 0) {
                long score = rge_base_game->world->players[p]->victory_conditions->get_victory_points();
                if (this->save_score[p] != score) {
                    if (this->need_redraw == 0) this->set_redraw(1);
                    this->save_object_info();
                    return 0;
                }
            }
        }
        return 0;
    }

    if ((this->player == 0 && this->game_obj != 0) ||
        (this->player != 0 &&
         this->player->object_130 != this->game_obj)) {
        if (this->player != 0) {
            this->set_object(this->player->object_130);
        } else {
            this->set_object(0);
        }
        return 0;
    }

    int changed = 0;
    int do_buttons = 0;
    TRIBE_Building_Object* bldg;
    short cur_val;
    short work_target;
    short orig_val;
    float cur_fval;
    short temp;
    short work_type;
    short progress_value;
    float orig_fval;
    char name[100];

    {
    RGE_Action_Object* object = (RGE_Action_Object*)this->game_obj;
    if (object == 0) goto finish;

    if (object->owner != this->save_owner) {
        changed = 1;
        do_buttons = 1;
    } else if (object->selected_group != this->save_selected_group) {
        changed = 1;
        do_buttons = 1;
    } else if (object->master_obj != this->save_obj_type) {
        changed = 1;
        do_buttons = 1;
    } else {
        short n = object->objects->number_of_objects;
        if (n == this->save_number_of_objects) {
            if (object->attribute_type_held != this->save_attr_type ||
                object->attribute_amount_held != this->save_attr_amount ||
                object->hp != this->save_hp ||
                object->objects->list != this->save_list ||
                object->master_obj->los != this->save_los ||
                object->master_obj->id == 0x2d) {
                changed = 1;
            }
        } else {
            changed = 1;
            if (n == 0 || this->save_number_of_objects == 0) do_buttons = 1;
        }
    }

    if (!changed) {
        unsigned char type = ((RGE_Action_Object*)this->game_obj)->master_obj->master_type;
        if (type >= 0x46 && type != 0x5A) {
            if (((RGE_Action_Object*)this->game_obj)->have_action() != this->save_have_action) {
                changed = 1; do_buttons = 1;
            }
            if (!changed) {
                ((RGE_Combat_Object*)this->game_obj)->get_armor(orig_val, cur_val);
                if (orig_val != this->save_armor) { changed = 1; }
                if (!changed) {
                    ((RGE_Combat_Object*)this->game_obj)->get_pierce_armor(orig_val, cur_val);
                    if (orig_val != this->save_pierce_armor) { changed = 1; }
                }
                if (!changed) {
                    ((RGE_Combat_Object*)this->game_obj)->get_weapon(orig_val, cur_val);
                    if (orig_val != this->save_weapon) { changed = 1; }
                }
                if (!changed) {
                    ((RGE_Combat_Object*)this->game_obj)->get_weapon_range(cur_fval, orig_fval);
                    if (cur_fval != this->save_weapon_range) { changed = 1; }
                }
                if (!changed) {
                    ((RGE_Combat_Object*)this->game_obj)->get_speed_of_attack(cur_fval, orig_fval);
                    if (cur_fval != this->save_speed_of_attack) { changed = 1; }
                }
            }
        }
    }

    if (changed && do_buttons) goto finish;
    bldg = (TRIBE_Building_Object*)this->game_obj;
    if (bldg->master_obj->master_type != 'P') goto finish;
    if (bldg->object_state != this->save_object_state) {
        changed = 1; do_buttons = 1;
    }
    if (!changed || !do_buttons) {
        short progress = bldg->get_construction_progress();
        if ((float)progress != this->save_build_pts) {
            changed = 1;
            if ((float)progress > 99.0f) do_buttons = 1;
        }
    }
    if (!changed || !do_buttons) {
        bldg->work_status(work_type, work_target, progress_value, name, 100);
        if (work_type != 0x67 && work_type != 0x66 && bldg->production_queue_status(work_target, temp) != 0) {
            work_type = 0x66;
            orig_fval = (float)temp;
        }
        if (work_type == this->save_work_type &&
            work_target == this->save_work_target &&
            progress_value == this->save_progress) {
            if (strcmp(name, this->save_name) == 0) {
                goto name_same;
            }
        }
        changed = 1;
        if (work_type == this->save_work_type &&
            work_target == this->save_work_target) {
            if (strcmp(name, this->save_name) == 0) {
                goto name_same;
            }
        }
        do_buttons = 1;
    }
name_same:
    ;
    }
finish:
    if ((!changed || !do_buttons) && this->game_obj->master_obj->id == 0x46) {
        if ((int)this->player->attributes[11] != this->save_pop ||
            (int)this->player->attributes[4] != this->save_max_pop) {
            changed = 1;
        }
    }
    if ((!changed || !do_buttons) &&
        bldg->owner == this->player && bldg->master_obj->id == 0x32) {
        RGE_Action* action = bldg->actions->get_action();
        if (action != 0 &&
            (int)(action->attribute_amount + bldg->attribute_amount_held -
                  DAT_00576d84) != this->save_farm_amt) {
            changed = 1;
        }
    }
    if (changed) {
        if (this->need_redraw == 0) this->set_redraw(1);
        this->save_object_info();
        if (do_buttons) this->child->notify(this, 1, 0, 0);
    }
    return 0;
}
