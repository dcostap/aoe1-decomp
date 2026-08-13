// VA: 0051B190 TRIBE_Panel_Object::draw
// tpnl_obj.cpp, lines 193-735
//
// Baseline reconstruction: the panel owns the render surface and the object
// panel owns the typed unit/building graphics and the typed combat object.  The
// source is intentionally written as the ordinary panel/object drawing code
// suggested by the original call order; the local ABI declarations below are
// the period class surfaces needed to preserve those calls and offsets.
//
// Attempt log:
// - baseline: typed panel/object reconstruction, render lock/DC sequence, and
//   named RGE/TRIBE object ownership; 3138 bytes, with the state paths still
//   structurally interleaved.
// - split the combat-state owner/resource path from the building work path;
//   this moved the call sequence to 88.6% alignment and brought the size gap
//   from -249 to -65 bytes.
// - restored the observed zero-subtraction expressions before the attribute,
//   resource, and distance ftol conversions; the rebuilt size reached 3387
//   bytes and the best positional report is 3161 differing bytes.
// - tried a narrow row-byte liveness spelling, explicit shared-tail gotos,
//   panel/building aliases, and a post-switch float reload; these either
//   worsened positional/codegen metrics or only changed tail sharing, so they
//   were rolled back.
// - moved the display-row local below the render/DC phase so it follows the
//   original ESI row lifetime and does not initialize a stack home in the
//   entry guard; this is the narrow first-block/render-call-order lead.
// - left in scratch: frame is 0x15c versus 0x158; remaining drift is chiefly
//   VC5 block/tail placement (three fewer draw_item virtual sites and two
//   fewer ftol sites), not an unresolved graphics surface, object offset, or
//   ordered call target model.

#include "../../include/game_globals.h"
#include <stdio.h>
#include <string.h>

extern float DAT_00576d80;
extern float DAT_00576d84;
extern const char s_tpnl_obj_draw[];
extern "C" void __cdecl _ASMSet_Color_Xform(int value);

// TPanel's real vtable places draw_setup/draw_finish/draw at 0x28/0x2c/0x30
// and draw_rect at 0x34.  The complete named prefix is retained here rather
// than replacing it with a raw vtable or a slot-padding shim.
class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
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
    virtual long handle_timer_command(unsigned int, long);
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
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    int position_mode;
    int need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    void* node;
    void* first_child_node;
    void* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    void* clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
};

class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;
    void* DrawSurface;
    char gap_40[0x78];

    void Clear(tagRECT*, int);
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void* GetDc(char*);
    void ReleaseDc(char*);
};

class TShape {
public:
    char gap_00[0x26];
    short id;
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char, unsigned char*);
    long shape_count();
};

class RGE_Color_Table {
public:
    char gap_00[0x26];
    short id;
    unsigned char table[0x100];
};

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
    unsigned char gap_16[0x10];
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char gap_2d[0x1f];
    short button_pict;
    unsigned char gap_4e[0x41];
    unsigned char unit_level;       // +0x8f
    unsigned char gap_90[0xde];
    short building_facet;           // +0x16e
};

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Combat_Object;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Active_Sprite_List;
class RGE_Sprite;
class RGE_Tile;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Action_Object;
class RGE_Master_Combat_Object;
class RGE_Game_World;
class RGE_Action_List;
class RGE_Action;
class RGE_Task;
class RGE_Armor_Weapon_Info;
class RGE_Active_Sprite_List;
class Production_Queue_Record;

// The named inherited virtual surface is the real RGE object hierarchy.  Only
// the methods used by this draw path have meaningful parameter declarations;
// the remaining inherited entries preserve the source class's actual order.
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual void update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save();
    virtual void teleport();
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership();
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state();
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual void calculateDamage();
    virtual void rotate();
    virtual void can_attack();
    virtual void set_attribute();
    virtual void set_attribute_amount();
    virtual void heal_int();
    virtual void heal_float();
    virtual void canRepair();
    virtual void notify_of_relation();
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle();
    virtual void spawn_death_obj();
    virtual void get_command_master();
    virtual void set_being_worked_on();
    virtual void release_being_worked_on();
    virtual void is_moving();
    virtual void get_target_obj();
    virtual void enter_obj();
    virtual void exit_obj();
    virtual void explore_terrain();
    virtual void unexplore_terrain();
    virtual void get_los_table();
    virtual void inAttackRange();
    virtual void underAttack();
    virtual void setUnderAttack();
    virtual void calc_attack_modifier();
    virtual void getSpeed();
    virtual void getAngle();
    virtual void maximumSpeed();
    virtual void rateOfFire();
    virtual void damageCapability_object();
    virtual void damageCapability();
    virtual void weaponRange();
    virtual void minimumWeaponRange();
    virtual void passableTile();
    virtual void facetToNextWaypoint();
    virtual void currentTargetID();
    virtual void currentTargetX();
    virtual void currentTargetY();
    virtual void currentTargetZ();
    virtual void setWaitingToMove();
    virtual void waitingToMove();
    virtual void actionState();
    virtual void keepGatheringWhenObjectIsOut();
    virtual void produceWhenKilledBy();
    virtual void useSameZoneDropsite();
    virtual void logDebug();
    virtual void notify();
    virtual void attack_float();
    virtual void attack_int();
    virtual void moveTo_float();
    virtual void moveTo_point();
    virtual void moveTo_int();
    virtual void moveAwayFrom();
    virtual void hunt();
    virtual void gather();
    virtual void convert();
    virtual void repair();
    virtual void build();
    virtual void trade();
    virtual void explore_int();
    virtual void enter_int();
    virtual void unload();
    virtual void transport();
    virtual void stopAction();
    virtual void pause();
    virtual void canPath_int();
    virtual void canPath_point();
    virtual void canBidirectionPath();
    virtual void canPathWithObstructions();
    virtual void canPathWithAdditionalPassability();
    virtual void findFirstTerrainAlongExceptionPath();
    virtual void canLinePath_int();
    virtual void canLinePath_point();
    virtual void firstTileAlongLine();
    virtual void userDefinedWaypoint();
    virtual void addUserDefinedWaypoint();
    virtual void removeAllUserDefinedWaypoints();
    virtual void removeUserDefinedWaypoint();
    virtual void numberUserDefinedWaypoints();
    virtual void findAvoidancePath();
    virtual void get_action_checksum();
    virtual void get_waypoint_checksum();
    virtual void setup_world();
    virtual void setup_static();
    virtual void create_object_list();
    virtual void create_sprite_list();

    long id;
    RGE_Master_Static_Object* master_obj;
    class RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    RGE_Tile* tile;
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
    char gap_54[0x30];
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual int setup_animated(RGE_Master_Animated_Object*, class RGE_Player*, float, float, float);
    virtual void stop_moving_action();
    virtual unsigned char turn_towards_action();
    virtual int setup_moving(RGE_Master_Moving_Object*, class RGE_Player*, float, float, float);
    virtual void work2_action();
    virtual void set_task(short);
    virtual void setTaskByTaskID(int);
    virtual void set_action(RGE_Task*);
    virtual void set_only_action(RGE_Task*);
    virtual void set_end_action(RGE_Task*);
    virtual RGE_Task* getTask(RGE_Static_Object*, float, float, float);
    virtual int setup_action(RGE_Master_Action_Object*, class RGE_Player*, float, float, float);

    char gap_88[0xf8];
    unsigned char waiting;
    unsigned char gap_181[3];
    RGE_Action_List* actions;
    unsigned char command_flag;
    unsigned char gap_189[3];
    int lastActionValue;
    int lastActionStateValue;
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    virtual RGE_Action_List* create_action_list();
    virtual unsigned char area_attack();
    virtual unsigned char attack_float_object();
    virtual unsigned char attack_object();
    virtual unsigned char do_attack_object();
    virtual void get_armor(short&, short&);
    virtual void get_weapon(short&, short&);
    virtual void get_weapon_range(float&, float&);
    virtual void get_speed_of_attack(float&, float&);
    virtual int setup_combat(RGE_Master_Combat_Object*, class RGE_Player*, float, float, float);

    void* VUR_Ptrs[9];
    unsigned long Unified_Map_Value;
    float attack_timer;
    unsigned char capture_flag;
    unsigned char gap_1c1[3];
};

class TRIBE_Building_Object : public RGE_Combat_Object {
public:
    virtual void cancel_object();
    virtual void get_pierce_armor(short&, short&);
    virtual void higher_check_for_cliff();
    virtual void higher_than_target();
    virtual void initUnitAI();
    virtual int setup_tribe_combat();
    virtual void take_building_attribute_from_owner();
    virtual void give_building_attribute_to_owner();
    virtual int setup_building();

    char gap_1c4[4];
    Production_Queue_Record* production_queue;
    short production_queue_size;
    short production_queue_count;
    unsigned char production_queue_enabled;
    unsigned char gap_1d1[3];
    RGE_Action_List* production_queue_actions;
    unsigned char production_queue_change_flag;
    unsigned char production_queue_auto_paused;
    short production_queue_need_attr;
    float build_pts;
    int unique_build_id;
    unsigned char culture;
    unsigned char built;
    unsigned char gap_1e6[2];
    int DoppleInstalled;
    unsigned long PriorMap1;
    unsigned long PriorMap2;
    unsigned long PriorMap3;
    long PriorTurn1;
    long PriorTurn2;
    long PriorTurn3;

    short get_construction_progress();
    void work_status(short&, short&, short&, char*, short);
    int production_queue_status(short&, short&);
};

class RGE_Object_List {
public:
    char gap_00[8];
    short number_of_objects;
    char gap_0A[2];
    RGE_Static_Object* find_by_master_id(long, float, float, unsigned char, unsigned char, RGE_Static_Object*);
};

class RGE_Action_List {
public:
    RGE_Action* get_action();
};

class RGE_Action {
public:
    char gap_00[0x2c];
    float field_2c;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num;
    char gap_3e[2];
    RGE_Player** players;
    char gap_44[0x18];
    class RGE_Scenario* scenario;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    char gap_2c[0x10];
    RGE_Game_World* world;
    char gap_40[0x04];
    char* name;
    unsigned char type;
    unsigned char gap_49;
    short id;
    short attribute_num;
    char gap_4e[2];
    float* attributes;
    char gap_54[0xb1];
    unsigned char master_player_id;
    char gap_106[2];
    RGE_Color_Table* color_table;
};

class RGE_Scenario {
public:
    char* GetPlayerName(int);
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

    char gap_04[0x3f0];
    RGE_Game_World* world;
    char gap_3f8[0x59c];
    int campaignGame_;
    char gap_998[0x288];
    int object_name_mode;

    int campaignGame();
    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Panel_Object : public TPanel {
public:
    virtual void draw();
    virtual void draw_item(int, int, int, int, int);
    void draw_score();

    void* font;
    int font_wid;
    int font_hgt;
    TShape* health_pic;
    TShape* item_pic;
    TShape* unit_pics;
    TShape** bldg_pics;
    RGE_Player* player;
    TRIBE_Building_Object* game_obj;
    float idle_time;
    float idle_interval;
    unsigned char mode;
    unsigned char gap_121[3];
};

extern "C" __declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
extern "C" __declspec(dllimport) int __stdcall SetBkMode(HDC, int);
extern "C" __declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
extern "C" __declspec(dllimport) BOOL __stdcall SelectClipRgn(HDC, HRGN);
extern "C" __declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);

void TRIBE_Panel_Object::draw()
{
    short cur_val;
    short orig_val;
    short work_type;
    short work_target;
    short progress;
    short temp;
    float cur_fval;
    float orig_fval;
    char name[100];
    char str[100];
    char work_name[100];

    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        this->need_redraw = 0;
        return;
    }

    if (this->mode == 2) {
        this->draw_score();
        return;
    }

    if (this->game_obj == 0) {
        if (this->parent_panel != 0)
            this->parent_panel->draw_rect(&this->clip_rect);
        this->need_redraw = 0;
        return;
    }

    this->draw_setup(0);
    this->render_area->Clear(&this->clip_rect, 0);

    if (this->render_area->Lock((char*)s_tpnl_obj_draw, 1) != 0) {
        short shape = this->game_obj->master_obj->button_pict;
        if (shape != -1) {
            TShape* picture;
            if (this->game_obj->master_obj->unit_level == 2) {
                unsigned char culture = this->game_obj->culture;
                shape += this->game_obj->master_obj->building_facet;
                picture = this->bldg_pics[culture];
            } else {
                picture = this->unit_pics;
            }

            if (this->game_obj->owner->color_table != 0) {
                _ASMSet_Color_Xform(
                    (this->game_obj->owner->color_table->id + 1) * 0x10);
            }

            picture->shape_draw(
                this->render_area,
                this->pnl_x + 3,
                this->pnl_y + 0x1e,
                shape,
                this->game_obj->owner->color_table != 0,
                this->game_obj->owner->color_table != 0
                    ? this->game_obj->owner->color_table->table
                    : 0);
        }

        if (this->game_obj->hp > DAT_00576d80 && this->health_pic != 0) {
            float count = (float)this->health_pic->shape_count();
            short frame = (short)(
                count - (float)this->health_pic->shape_count() * this->game_obj->hp /
                              (float)this->game_obj->master_obj->hp);
            if (frame < 0) {
                frame = 0;
            } else if (this->health_pic->shape_count() - 1 < frame) {
                frame = (short)this->health_pic->shape_count() - 1;
            }

            this->health_pic->shape_draw(
                this->render_area,
                this->pnl_x + 3,
                this->pnl_y + 0x54,
                frame,
                0,
                0);
        }

        this->render_area->Unlock((char*)s_tpnl_obj_draw);
    }

    if (this->render_area->GetDc((char*)s_tpnl_obj_draw) != 0) {
        HDC dc = this->render_area->DrawDc;
        SetBkMode(dc, 1);
        SetTextColor(dc, 0x00ffffff);
        SelectClipRgn(dc, (HRGN)this->clip_rgn);
        HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);

        if (this->game_obj->owner->id != 0) {
            if (rge_base_game->campaignGame() == 0) {
                name[0] = 0;
            } else {
                strcpy(name, this->game_obj->owner->world->scenario->GetPlayerName(
                    this->game_obj->owner->id - 1));
            }

            if (name[0] == 0) {
                rge_base_game->get_string2(
                    0x69,
                    this->game_obj->owner->master_player_id,
                    0,
                    name,
                    100);
            }

            TextOutA(dc, this->pnl_x + 3, this->pnl_y - 2,
                     name, (int)strlen(name));
        }

        if (this->game_obj->master_obj->string_id < 1) {
            str[0] = 0;
        } else {
            rge_base_game->get_string(
                this->game_obj->master_obj->string_id, str, 100);
        }

        if (str[0] == 0)
            strcpy(str, this->game_obj->master_obj->name);

        if (rge_base_game->object_name_mode == 0)
            sprintf(name, "%s", str);
        else
            sprintf(name, "%d-%s", this->game_obj->id, str);

        TextOutA(dc, this->pnl_x + 3, this->pnl_y + 0x0d,
                 name, (int)strlen(name));

        if (this->game_obj->hp > DAT_00576d80) {
            sprintf(str, "%d/%d",
                    (int)this->game_obj->hp,
                    (int)this->game_obj->master_obj->hp);
            TextOutA(dc, this->pnl_x + 3, this->pnl_y + 0x5c,
                     str, (int)strlen(str));
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc((char*)s_tpnl_obj_draw);
    }

    int row = 0;
    unsigned char level = this->game_obj->master_obj->unit_level;

    if (level == 3 || level == 4 || level == 5 || level == 6 ||
        level == 7 || level == 9) {
        if (level == 3 || level == 4) {
            this->game_obj->get_weapon(cur_val, orig_val);
            this->draw_item(0, 7, 1, orig_val, cur_val);
            row = 1;
        }

        this->game_obj->get_armor(cur_val, orig_val);
        if (cur_val > 0) {
            this->draw_item(row, 8, 1, orig_val, cur_val);
            ++row;
        }

        this->game_obj->get_pierce_armor(cur_val, orig_val);
        if (cur_val > 0) {
            this->draw_item(row, 10, 1, orig_val, cur_val);
            ++row;
        }

        if (level == 4 || level == 6) {
            this->game_obj->get_weapon_range(cur_fval, orig_fval);
            if (cur_fval > DAT_00576dac) {
                this->draw_item(row, 6, 1,
                                (int)orig_fval, (int)cur_fval);
                ++row;
            }
        }

        if (level == 6) {
            this->draw_item(row, 9, 3,
                            (int)(this->game_obj->attribute_amount_held -
                                  DAT_00576d84), 0);
            ++row;
        }

        if (this->game_obj->owner != this->player) {
            this->draw_finish();
            return;
        }

        if (level == 7) {
            this->draw_item(
                row, 4, 2,
                this->game_obj->objects->number_of_objects,
                this->game_obj->master_obj->obj_max);
            this->draw_finish();
            return;
        }

        if (level == 9) {
            if (this->game_obj->attribute_type_held == 0x11 ||
                this->game_obj->attribute_type_held == 0)
                cur_val = (short)(int)(this->game_obj->attribute_amount_held -
                                       DAT_00576d84);
            else
                cur_val = 0;
            this->draw_item(row, 2, 0, cur_val, 0);
            this->draw_finish();
            return;
        }

        if (level == 5) {
            int item_type;
            switch (this->game_obj->attribute_type_held) {
            case 0:
            case 0x0f:
            case 0x10:
            case 0x11:
                item_type = 2;
                break;
            case 1:
                item_type = 0;
                break;
            case 2:
                item_type = 1;
                break;
            case 3:
                item_type = 3;
                break;
            case 9:
                item_type = 5;
                break;
            default:
                this->draw_finish();
                return;
            }

            if ((int)(this->game_obj->attribute_amount_held - DAT_00576d84) > 0) {
                this->draw_item(row, 3, 0,
                                (int)(this->game_obj->attribute_amount_held -
                                      DAT_00576d84), 0);
            } else {
                this->draw_item(row, item_type, 4, -1, 0);
            }
            this->draw_finish();
            return;
        }

        if ((int)(this->game_obj->attribute_amount_held - DAT_00576d84) < 1) {
            this->draw_finish();
            return;
        }

        int item_type;
        switch (this->game_obj->attribute_type_held) {
        case 0:
        case 0x0f:
        case 0x10:
        case 0x11:
            item_type = 2;
            break;
        case 1:
            item_type = 0;
            break;
        case 2:
            item_type = 1;
            break;
        case 3:
            item_type = 3;
            break;
        case 9:
            item_type = 5;
            break;
        default:
            this->draw_finish();
            return;
        }
        this->draw_item(row, item_type, 0,
                        (int)(this->game_obj->attribute_amount_held -
                              DAT_00576d84), 0);
        this->draw_finish();
        return;
    }

    if (level == 1) {
        int item_type;
        switch (this->game_obj->attribute_type_held) {
        case 0:
        case 0x0f:
        case 0x10:
        case 0x11:
            item_type = 2;
            break;
        case 1:
            item_type = 0;
            break;
        case 2:
            item_type = 1;
            break;
        case 3:
            item_type = 3;
            break;
        case 9:
            item_type = 5;
            break;
        default:
            this->draw_finish();
            return;
        }
        this->draw_item(
            0, item_type, 0,
            (int)(this->game_obj->attribute_amount_held - DAT_00576d84),
            0);
        this->draw_finish();
        return;
    }

    if (level == 2 || level == 8) {
        if (this->game_obj->master_obj->master_type == 'P') {
            this->game_obj->work_status(
                work_type, work_target, progress, work_name, 100);

            if (work_type != 0x67 && work_type != 0x66 &&
                this->game_obj->production_queue_status(work_target, temp) != 0) {
                work_type = 0x66;
                progress = temp;
            }

            if (this->game_obj->object_state != 0 &&
                (this->game_obj->owner != this->player ||
                 (work_type != 0x67 && work_type != 0x66))) {
                this->game_obj->get_weapon(cur_val, orig_val);
                if (cur_val > 0) {
                    this->draw_item(0, 7, 1, orig_val, cur_val);
                    row = 1;
                }
                this->game_obj->get_weapon_range(cur_fval, orig_fval);
                if ((int)cur_fval > 0) {
                    this->draw_item(row, 6, 1,
                                    (int)orig_fval, (int)cur_fval);
                    ++row;
                }
            }

            if (this->game_obj->owner == this->player) {
                if (this->game_obj->object_state == 0) {
                    this->draw_item(row, 9, 3,
                                    this->game_obj->get_construction_progress(), 0);
                    ++row;
                } else if (work_type == 0x67 || work_type == 0x66) {
                    this->draw_item(row, 9, 3, progress, 0);
                    ++row;
                } else {
                    if (this->game_obj->master_obj->id == 0x46) {
                        int value = (int)(this->player->attributes[4] +
                                          this->player->attributes[11]);
                        int max_value = (int)this->player->attributes[32];
                        if (max_value < value)
                            value = max_value;
                        int current_value = (int)this->player->attributes[11];
                        this->draw_item(row, 4, 2, current_value, value);
                        ++row;
                    }

                    if (this->game_obj->master_obj->id == 0x32) {
                        RGE_Action* action = this->game_obj->actions->get_action();
                        if (action != 0)
                            this->draw_item(
                                row, 2, 0,
                                (int)(action->field_2c +
                                      this->game_obj->attribute_amount_held -
                                      DAT_00576d84),
                                0);
                    }
                }
            }
        }

        if (this->game_obj->object_state != 0 &&
            this->game_obj->object_state == 2) {
            int show_resource = 0;
            if (this->game_obj->owner == this->player) {
                if (work_type != 0x67 && work_type != 0x66) {
                    if (this->game_obj->master_obj->id == 0x2d) {
                        show_resource = 1;
                    } else if (this->game_obj->master_obj->id != 0x32 &&
                               this->game_obj->attribute_type_held != -1 &&
                               (int)(this->game_obj->attribute_amount_held -
                                     DAT_00576d84) > 0) {
                        show_resource = 1;
                    }
                }
            } else if (this->game_obj->master_obj->id == 0x2d) {
                show_resource = 1;
            }

            if (show_resource) {
                short resource_type = this->game_obj->attribute_type_held;
                float resource_amount = this->game_obj->attribute_amount_held;
                if (this->game_obj->master_obj->id == 0x2d) {
                    resource_type = 9;
                    resource_amount = this->game_obj->owner->attributes[9];
                }

                int item_type;
                switch (resource_type) {
                case 0:
                case 0x0f:
                case 0x10:
                case 0x11:
                    item_type = 2;
                    break;
                case 1:
                    item_type = 0;
                    break;
                case 2:
                    item_type = 1;
                    break;
                case 3:
                    item_type = 3;
                    break;
                case 9:
                    item_type = 5;
                    break;
                default:
                    this->draw_finish();
                    return;
                }

                this->draw_item(
                    row, item_type, 0,
                    (int)(resource_amount - DAT_00576d84), 0);
                ++row;
            }
        }

        if (this->game_obj->master_obj->id == 0x2d &&
            this->game_obj->owner != this->player) {
            RGE_Player* current_player = rge_base_game->get_player();
            RGE_Static_Object* nearby = current_player->objects->find_by_master_id(
                0x2d,
                this->game_obj->world_x,
                this->game_obj->world_y,
                1,
                2,
                this->game_obj);

            if (nearby != 0) {
                float dx = nearby->world_x - this->game_obj->world_x;
                float dy = nearby->world_y - this->game_obj->world_y;
                float distance = dx * dx + dy * dy;
                distance *= DAT_00576d88;
                distance *= DAT_00576d8c;
                if (this->player->master_player_id == 0x0f)
                    distance += 1.0f;
                if (distance < DAT_00576d98)
                    distance = DAT_00576da0;
                distance *= DAT_00576da4;
                if (distance > DAT_00576da8)
                    distance = DAT_00576da8;
                this->draw_item(
                    row, 3, 2, (int)(distance - DAT_00576d84), 0x14);
            }
        }
    }

    this->draw_finish();
}
