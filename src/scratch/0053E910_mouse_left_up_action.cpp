// 0053E910 RGE_Main_View::mouse_left_up_action (2252 bytes)
// PDB: vw_main.cpp (RGE_Main_View::mouse_left_up_action), lines 681-1076
//
// long __thiscall RGE_Main_View::mouse_left_up_action(long x, long y, int key, int flags)
// ret 10h cleanup (4 stack params, thiscall). Returns 0 or 1.
//
// Attempt log:
//   prior candidate: exact size/frame but rejected because it used synthetic
//     virtual padding/manual dispatch views and omitted three ordered
//     interface-style-2 calls (unselect_object, select_object, set_redraw).
//   probe 12 (baseline): rebuilt the canonical named TPanel/RGE_View/
//     RGE_Main_View, RGE_Base_Game, RGE_Player, RGE_Static_Object, sprite,
//     map, and visible-map surfaces from the generated original-header facts.
//     Natural delete/destroy/rotate calls replace manual virtual surfaces.
//   probe 13 (ABI): restored the real overloaded TPanel set_rect declaration;
//     inherited set_redraw/end_scroll/command virtual indices then aligned.
//   probe 14 (liveness): shared zero and typed null locals were const-folded;
//     rolled back as diagnostic-only codegen attempts.
//   probe 15 (control-flow): duplicated the interface-style-2 selected and
//     unselected success arms, including their own set_redraw and coordinate
//     stores. This restored all three missing calls and exact 72/72 call-site
//     order while preserving the natural branch behavior.
//   probes 16-19: function-scope ret/pick_info and zero-basin variants were
//     unchanged; the mode-mode zero expression was rejected as noncanonical.
//   follow-up probes: standard-header contexts, shared zero locals, parameter
//     result reuse, direct pick arguments, and interface-tail labels were all
//     restored after emitting no improvement. The duplicated interface arms
//     are required for the 72-call sequence; a common redraw tail loses calls.
//
// Current state: canonical source, size 2252/2252, frame 0x14/0x14, calls
//   72/72 ordered and target-aligned, shape 92.85%, strict diff 1974 bytes.
// Remaining evidence-backed drift is the early EBX zero/register-zero basin,
// the result-byte home ([esp+2Ch] rebuilt vs [esp+30h] original), and a small
// number of CFG/epilogue scheduling differences. No synthetic virtual slots,
// raw vptr fields/stores, fake volatility, or inline assembly remain.
// Next lead: only a genuinely source-supported TU/variable-lifetime fact should
// be tried; otherwise this is a clean documented structural pause.


extern "C" void __cdecl color_log(unsigned char a, unsigned char b, int c);
extern "C" void __cdecl free(void*);

extern int allow_user_commands;        // 0x0058631C

class TShape;

class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;   // 0x0062C574

class RGE_Tile;
class RGE_Static_Object;
class RGE_Player;
class RGE_Sprite;
class RGE_Active_Sprite_Node;

class RGE_Prog_Info {
public:
    char gap_00[0x8DC];
    short interface_style;             // +0x8DC
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[0x8DB4];
    unsigned char map_visible_flag;    // +0x8DB8
};

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;       // +0x00
    void* world;                       // +0x04
    RGE_Player* player;                // +0x08
    RGE_Map* map;                      // +0x0C
    unsigned char* visible_map;        // +0x10
    int width;                         // +0x14
    int height;                        // +0x18
    int explored;                      // +0x1C
    int total;                         // +0x20
    unsigned long visible_mask;        // +0x24
    unsigned long visible_mask_invert; // +0x28
    unsigned long explored_mask;       // +0x2C
    unsigned long explored_mask_invert;// +0x30
    unsigned long checksum;            // +0x34
    unsigned char get_visible(int x, int y);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x89];
    unsigned char select_level;        // +0x8D
};

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* sprite);
    virtual void update(float x, float y);
    virtual void draw(short, short, short, short, short, void*, void*);
    virtual void normal_draw(short, short, short, void*, void*);
    virtual void shadow_draw(short, short, short, void*, void*, unsigned char);
    virtual unsigned char is_animating(RGE_Sprite* sprite);
    virtual void set_frame(RGE_Sprite* sprite, short frame_number);
    virtual unsigned char frame_passed(RGE_Sprite* sprite, short frame_number);
    virtual unsigned char looped(RGE_Sprite* sprite);
    virtual short get_facetindex(RGE_Sprite* sprite, short facet);
    virtual unsigned char load_node(int id, unsigned char flag, RGE_Sprite** sprite);

    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;
    unsigned char get_lowest_draw_level();
};

class RGE_Sprite {
public:
    char gap_00[0x29];
    unsigned char draw_level;          // +0x29
    unsigned char get_lowest_draw_level();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
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
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual void rotate(long);

    long id;                                // +0x04
    RGE_Master_Static_Object* master_obj;   // +0x08
    RGE_Player* owner;                      // +0x0C
    RGE_Sprite* sprite;                     // +0x10
    RGE_Sprite* old_sprite;                 // +0x14
    RGE_Active_Sprite_List* sprite_list;    // +0x18
    void* tile;                             // +0x1C
    void* inside_obj;                       // +0x20
    void* objects;                          // +0x24
    short screen_x_offset;                  // +0x28
    short screen_y_offset;                  // +0x2A
    short shadow_x_offset;                  // +0x2C
    short shadow_y_offset;                  // +0x2E
    float hp;                               // +0x30
    unsigned char curr_damage_percent;      // +0x34
    unsigned char facet;                    // +0x35
    unsigned char selected;                 // +0x36
    unsigned char selected_group;           // +0x37
    float world_x;                          // +0x38
    float world_y;                          // +0x3C
    float world_z;                          // +0x40
    float attribute_amount_held;            // +0x44
    unsigned char object_state;             // +0x48
};

struct RGE_Pick_Info {
    float x;                               // +0x00
    float y;                               // +0x04
    short scr_x;                           // +0x08
    short scr_y;                           // +0x0A
    RGE_Static_Object* object;             // +0x0C
    RGE_Tile* tile;                        // +0x10
};

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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float,
                                 int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float,
                                int, int, int);
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
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                 unsigned char, float);
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
    virtual void command_add_waypoint(float, float, float);

    char gap_04[0x34];
    RGE_Visible_Map* visible;              // +0x38
    char gap_3C[0xE];
    short id;                              // +0x4A
    char gap_4C[0xE4];
    RGE_Static_Object* selected_obj;       // +0x130
    char gap_134[0x68];
    short sel_count;                       // +0x19C

    void unselect_object();
    int select_object(RGE_Static_Object* obj);
    void select_one_object(RGE_Static_Object* obj);
    int select_one_object(RGE_Static_Object* obj, int play_sound);
    void unselect_one_object(RGE_Static_Object* obj);
    unsigned char get_select_level();
    unsigned char get_selected_objects_to_command(
        RGE_Static_Object*** out_list, short* out_count,
        short min_select_level, short object_group, short object_id, short unit_level);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int mode, int sub_mode);
    virtual void set_player(short id);

    char gap_04[0x8];
    RGE_Prog_Info* prog_info;              // +0x0C
    char gap_10[0x4C];
    TShape** shapes;                       // +0x5C
    char gap_60[0x150];
    int prog_mode;                         // +0x1B0
    int game_mode;                         // +0x1B4
    int sub_game_mode;                     // +0x1B8

    int get_paused();
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
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
    virtual void draw_rect(void*);
    virtual void draw_offset(long, long, void*);
    virtual void draw_rect2(void*);
    virtual void draw_offset2(long, long, void*);
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
    virtual void get_true_render_rect(void*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0xB0];
    void release_mouse();
};

class RGE_View : public TPanel {
public:
    virtual int pick_through_fog(RGE_Static_Object*);
    virtual int pick_weight(RGE_Static_Object*, int);
    virtual int start_scroll_view(unsigned char, long, long, int, int);
    virtual int handle_scroll_view(long, long);
    virtual void end_scroll_view();
    virtual int do_paint(long, long, long, long, int);
    virtual void draw_multi_object_outline();

    void add_overlay_sprite(TShape* shape, int facet, int world_x, int world_y, int flags,
                            int draw_level, unsigned char* color_table, int displayfunction,
                            unsigned long draw_time_interval);

    void* cur_render_area;                  // +0xF4
    int calc_draw_count;                    // +0xF8
    void* world;                            // +0xFC
    RGE_Player* player;                     // +0x100
    RGE_Map* map;                           // +0x104
    char gap_108[0x28];
    int map_scr_x_offset;                   // +0x130
    int map_scr_y_offset;                   // +0x134
    char gap_138[0xC];
    long sel_col1;                          // +0x144
    long sel_row1;                          // +0x148
    long sel_col2;                          // +0x14C
    long sel_row2;                          // +0x150
    char gap_154[0x14];
    unsigned char scroll_action;            // +0x168
    char gap_169[0x3];
    long mouse_last_x;                      // +0x16C
    long mouse_last_y;                      // +0x170
    RGE_Static_Object* movable_object;      // +0x174
    char gap_178[0x1E8];
};

class RGE_Main_View : public RGE_View {
public:
    virtual int command_place_object(long x, long y, int mode);
    virtual int command_make_do(long x, long y, int mode, short flag);
    virtual int command_make_move(long x, long y);
    virtual int command_make_work(long x, long y);
    virtual int command_place_multi_object(long a, long b, long c, long d, int mode);

    TPanel* map_view;                       // +0x360
    unsigned long last_mouse_scroll_time;  // +0x364
    int mouse_scrolling;                    // +0x368
    long mouse_last_x;                      // +0x36C
    long mouse_last_y;                      // +0x370
    unsigned long last_key_scroll_time;    // +0x374
    int key_scrolling;                      // +0x378
    RGE_Player* save_player;                // +0x37C

    unsigned char pick1(unsigned char cmd, unsigned char small, long x, long y,
                        RGE_Pick_Info* out, RGE_Static_Object* exclude, int alt);
    void fixup_pick_info(RGE_Pick_Info* info);
    void reset_display_object_selection(int mode);

    virtual long mouse_left_up_action(long x, long y, int key, int flags);
};

long RGE_Main_View::mouse_left_up_action(long x, long y, int key, int flags)
{
    int mode = rge_base_game->prog_mode;
    RGE_Pick_Info pick_info;

    if (mode != 4 && mode != 6 && mode != 7 && mode != 5) {
        return 0;
    }

    color_log(0x4C, 0x16, 1);

        if (this->scroll_action) {
            this->end_scroll_view();

            if (rge_base_game->game_mode == 0x15) {
                this->command_place_multi_object(this->sel_col1, this->sel_row1,
                    this->sel_col2, this->sel_row2, key == 0 && flags == 0);
            }

            if (rge_base_game->game_mode == 8) {
                this->command_place_object(x, y, 1);
                if (rge_base_game->sub_game_mode == 1) {
                    this->movable_object->object_state = 2;
                    this->movable_object = 0;
                    rge_base_game->set_game_mode(0xF, 0);
                    if (this->save_player) {
                        rge_base_game->set_player(this->save_player->id);
                        this->save_player = 0;
                    }
                }
            }
            goto done;
        }

        this->release_mouse();

        if (rge_base_game->get_paused()) {
            color_log(0x4C, 0x5F, 1);
            return 0;
        }

        int game_mode;
        game_mode = rge_base_game->game_mode;

        if ((flags || key) && game_mode != 7 && game_mode != 0x15) {
            if (this->pick1(0x29, 2, x, y, &pick_info, 0, 0) == 0x34) {
                if (pick_info.object->selected & 1) {
                    this->player->unselect_one_object(pick_info.object);
                } else {
                    if (this->player->selected_obj &&
                        (this->player->selected_obj->owner != this->player ||
                         this->player->get_select_level() != pick_info.object->master_obj->select_level)) {
                        this->player->unselect_object();
                    }
                    if (key) {
                        this->player->select_one_object(pick_info.object, 1);
                    } else {
                        this->player->select_object(pick_info.object);
                    }
                }
                this->set_redraw(1);
            }

            if (key || rge_base_game->prog_info->interface_style == 2) {
                goto done;
            }
        }

        switch (game_mode) {
        case 4:
            this->command_make_move(x, y);
            break;

        case 5:
            this->command_make_work(x, y);
            break;

        case 7:
            if (key == 0 && flags == 0) {
                this->command_place_object(x, y, 1);
            } else {
                this->command_place_object(x, y, 0);
            }
            break;

        case 8:
            this->command_place_object(x, y, 1);
            if (rge_base_game->sub_game_mode == 1) {
                this->movable_object->object_state = 2;
                this->movable_object = 0;
                rge_base_game->set_game_mode(0xF, 0);
                if (this->save_player) {
                    rge_base_game->set_player(this->save_player->id);
                    this->save_player = 0;
                }
            }
            break;

        case 0xE:
            if (this->pick1(0x29, 0, x, y, &pick_info, this->player->selected_obj, 1) == 0x34) {
                unsigned char level;
                if (pick_info.object->sprite_list) {
                    level = pick_info.object->sprite_list->get_lowest_draw_level();
                } else if (pick_info.object->sprite) {
                    level = pick_info.object->sprite->get_lowest_draw_level();
                } else {
                    level = 0x14;
                }
                if (rge_base_game->prog_mode == 7) {
                    if (pick_info.object) {
                        delete pick_info.object;
                    }
                } else {
                    pick_info.object->destroy_obj();
                }
                if (level == 0) {
                    this->set_redraw(2);
                }
            }
            break;

        case 0x10:
            if (this->pick1(0x29, 1, x, y, &pick_info, this->player->selected_obj, 1) == 0x34) {
                if (this->parent_panel) {
                    this->parent_panel->action((TPanel*)this, 0x10, (unsigned long)pick_info.object, 0);
                    this->player->select_one_object(pick_info.object, 1);
                    this->set_redraw(1);
                }
                rge_base_game->set_game_mode(0, 0);
            }
            break;

        case 0x14:
            if (this->pick1(0x29, 2, x, y, &pick_info, this->player->selected_obj, 1) == 0x34) {
                pick_info.object->rotate(1);
            }
            break;

        case 0:
        case 6:
            unsigned char ret;
            if (game_mode == 6) {
                rge_base_game->set_game_mode(0, 0);
            }

            if (rge_base_game->prog_info->interface_style == 2) {
                RGE_Static_Object* exclude;
                if (x == this->mouse_last_x && y == this->mouse_last_y) {
                    exclude = this->player->selected_obj;
                } else {
                    exclude = 0;
                }
                ret = this->pick1(0x29, 2, x, y, &pick_info, exclude, 0);
                this->mouse_last_x = -1;
                this->mouse_last_y = -1;
                if (ret == 0x34) {
                    if (pick_info.object->selected & 1) {
                        if (this->player->sel_count <= 1) {
                            break;
                        }
                        this->player->unselect_object();
                        this->player->select_one_object(pick_info.object, 1);
                        this->set_redraw(1);
                        this->mouse_last_x = x;
                        this->mouse_last_y = y;
                    } else {
                        this->player->unselect_object();
                        this->player->select_object(pick_info.object);
                        this->set_redraw(1);
                        this->mouse_last_x = x;
                        this->mouse_last_y = y;
                    }
                    break;
                }
                this->player->unselect_object();
                this->set_redraw(1);
                break;
            }

            ret = this->pick1(0x2A, 1, x, y, &pick_info,
                (x == this->mouse_last_x && y == this->mouse_last_y) ? this->player->selected_obj : 0, 1);

            if (ret == 0x34 && x == this->mouse_last_x && y == this->mouse_last_y &&
                pick_info.object != this->player->selected_obj) {
                this->player->unselect_object();
                this->set_redraw(1);
            }

            this->mouse_last_x = -1;
            this->mouse_last_y = -1;

            if (ret == 0x34) {
                if (rge_base_game->prog_mode != 5 && this->player->sel_count > 0 &&
                    rge_base_game->prog_mode != 7) {
                    if (this->command_make_do(x, y, 0, -1)) {
                        return 1;
                    }
                }

                if (pick_info.object->selected & 1) {
                    if (this->player->sel_count <= 1) {
                        return 1;
                    }
                    this->player->unselect_object();
                    this->player->select_one_object(pick_info.object, 1);
                    this->set_redraw(1);
                    this->mouse_last_x = x;
                    this->mouse_last_y = y;
                    return 1;
                }

                if (pick_info.object->owner != this->player && this->player->sel_count != 0) {
                    if (rge_base_game->prog_mode != 5 && rge_base_game->prog_mode != 7) {
                        if (this->command_make_do(x, y, 1, -1)) {
                            goto done;
                        }
                    }
                    if (pick_info.object->master_obj->select_level >= 2) {
                        if (this->map->map_visible_flag ||
                            this->player->visible->get_visible((long)pick_info.object->world_x,
                                                               (long)pick_info.object->world_y) == 0xF) {
                            this->player->unselect_object();
                            this->player->select_object(pick_info.object);
                            this->set_redraw(1);
                            this->mouse_last_x = x;
                            this->mouse_last_y = y;
                            goto done;
                        }
                    }
                    goto LAB_F0C7;
                }

                if (pick_info.object->master_obj->select_level >= 2) {
                    if (this->map->map_visible_flag ||
                        this->player->visible->get_visible((long)pick_info.object->world_x,
                                                           (long)pick_info.object->world_y) == 0xF) {
                        this->player->unselect_object();
                        this->player->select_object(pick_info.object);
                        this->set_redraw(1);
                        this->mouse_last_x = x;
                        this->mouse_last_y = y;
                    }
                }
                goto done;
            }

        LAB_F0C7:
            if (ret == 0x33 && rge_base_game->prog_mode != 5 && rge_base_game->prog_mode != 7) {
                if (flags == 0) {
                    if (this->command_make_do(x, y, 1, -1) == 0) {
                        goto done;
                    }
                } else if (this->player->get_selected_objects_to_command((RGE_Static_Object***)&flags,
                    (short*)&key, -1, -1, -1, -1) != 0) {
                    free((void*)flags);
                    if (allow_user_commands) {
                        this->fixup_pick_info(&pick_info);
                        this->player->command_add_waypoint(pick_info.x, pick_info.y, 1.0f);
                        this->reset_display_object_selection(2);
                        this->add_overlay_sprite(rge_base_game->shapes[1], 0,
                            this->map_scr_x_offset + x, this->map_scr_y_offset + y,
                            0, 0xF, 0, 1, 0xFA);
                        this->set_redraw(1);
                    }
                }
            }
            break;
        }

done:
    color_log(0x4C, 0x5F, 1);
    return 1;
}
