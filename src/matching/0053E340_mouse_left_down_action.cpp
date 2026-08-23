// VA 0053E340 RGE_Main_View::mouse_left_down_action
// vw_main.cpp:461-630
//
// Behavior-first reconstruction from the original switch and same-TU donors.
// The render area, pick record, world/player ownership, and virtual command
// surfaces use the period layout.  The source does not use decompiler offsets.
//
// Attempt log:
// - Prior scratch source had direct helper calls and incorrect player/object
//   fields.  It was not a canonical behavior baseline.
// - Current baseline: restored RGE_View/TPanel render-area ownership, the
//   master-object placement path, selected-object checks, and start-scroll
//   command dispatch from the original ordered call list.
// - Structural probe: kept the local-player and scenario-player placement
//   arms separate.  This restored both alignment and command-place call sites,
//   exact size, and call-target parity.  Broader block order still differs.
// - Nested the paused and allowed-mode guards to restore the shared false
//   return path used by the original.
// - Ordered switch arms by the PDB line bands: selection, placement, scroll,
//   drag, then the default capture path.  This restored all ordered calls.
// - Binary stack offsets identify player+0x130 as the selected object and
//   pick_info.object as the picked static object.  The decompiler tile label
//   was not canonical ownership.
// - Direct object reloads improve the case-15 and case-18 block shape.  The
//   exact donor reference ABI for get_frame produced no useful movement.
// - Widened master_obj_id's local to int; this restored the original size and
//   reduced the strict diff from 755 to 585 bytes.
// - Removed the fallback command-player alias.  Repeated named world/player
//   access restored the original reload topology and reduced the diff to 27.
// - A typed four-short frame aggregate, with max_y before max_x, reduced the
//   remaining local-output drift to 17 bytes.  The candidate stays in scratch.
// - Sustained probe pass: 32 meaningful source, ABI, layout, liveness, and
//   context hypotheses were tested.  The clean aggregate source was best then.
// - A branch-local RGE_Base_Game* alias reduced the strict diff from 17 to 4
//   bytes and made all 30 relocations safe, but it did not fix the frame loads.
//   The alias is retained in the exact source because its one use preserves the
//   original global receiver load after set_player.
// - Separate short locals, arrays, field permutations, pointer/reference
//   get_frame forms, Windows/stdlib headers, receiver scopes, and volatile
//   outputs were worse or codegen duplicates.  Exact donor 004C3B30 confirms
//   the natural get_frame ABI and output order, but not this target's homes.
// - Exact finish: the original reads pick_info.scr_x/scr_y for both point
//   deltas.  Replacing frame.max_x/max_y removed the last four bytes.
// - Exact walkback: branch-local frame references and point/frame declaration
//   reordering were incidental.  Standalone short locals are the clearest
//   exact form.  The tagRECT declaration preserves the period API context.
// - Second pass: 14 meaningful hypotheses, first exact checkpoint at diff 0,
//   reduced exact source retained after independent walkbacks.
// - Canonical cleanup: named RGE_Player, TPanel, RGE_View, and RGE_Game_World
//   surfaces replaced macro slots and the manual world vtable field.  Named
//   world fields preserve players at +0x40 and the exact bytes.
// - Canonical reduction: removing RGE_View's trailing named slots changed 26
//   bytes.  The full donor-supported inherited surface remains required.
// - Grouped exact finish: direct period Win32 declarations preserve the VC5
//   scheduling that the Windows header changed. The donor pointer form of
//   get_frame remains exact in standalone and PDB-ordered grouped builds.

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
extern "C" void __cdecl color_log(unsigned char, unsigned char, int);
extern "C" __declspec(dllimport) int __stdcall ClientToScreen(void*, void*);
extern "C" __declspec(dllimport) int __stdcall ScreenToClient(void*, void*);

struct tagPOINT {
    long x;
    long y;
};

// BINARY NOTE: vw_main.cpp uses the period Windows API type context here.
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawSystem {
public:
    char gap_00[0x479];
    unsigned char screen_mode;
};

class TDrawArea {
public:
    TDrawSystem* draw_system;
    void* wnd;
};

class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Tile;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Object_Node;
class XYZBYTEPoint;
class RGE_Master_Player;
class RGE_Player_Info;
class RGE_Sound;
class RGE_Scenario;
class RGE_Map;
class TSound_Driver;
class TCommunications_Handler;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class RGE_Active_Sprite_List {
public:
    unsigned char get_lowest_draw_level();
};

class RGE_Sprite {
public:
    unsigned char get_lowest_draw_level();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    char gap_1C[0x2C];
    unsigned char object_state;

    int get_frame(short*, short*, short*, short*);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(
        RGE_Player*, float, float, int*, unsigned char, unsigned char,
        unsigned char, unsigned char, unsigned char, unsigned char);
    virtual unsigned char alignment(
        float*, float*, RGE_Game_World*, unsigned char);

    char gap_04[0x0C];
    short id;
    short copy_id;
    short object_group;
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void*);
    virtual unsigned char data_load_terrain_tables(char*);
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
    virtual void data_load_players_type(short, short, void*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short,
                               RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual unsigned char init_player_type(int, short, unsigned char);
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info*);
    virtual unsigned char new_random_game(RGE_Player_Info*);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(RGE_Player_Info*);
    virtual unsigned char load_scenario(char*, RGE_Player_Info*);
    virtual void load_scenario1(int, RGE_Player_Info*);
    virtual void load_scenario2(int, RGE_Player_Info*);
    virtual void load_scenario3(int, RGE_Player_Info*);
    virtual void load_scenario4(int, RGE_Player_Info*);
    virtual void load_scenario5(int, RGE_Player_Info*);
    virtual void load_scenario6(int, RGE_Player_Info*);
    virtual void load_scenario7(int, RGE_Player_Info*);
    virtual void load_scenario8(int, RGE_Player_Info*);
    virtual void logStatus(void*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char load_game(char*);
    virtual unsigned char new_game(RGE_Player_Info*, int);
    virtual unsigned char new_scenario(RGE_Player_Info*, int);
    virtual unsigned char save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual unsigned char save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(unsigned char);
    virtual void scenario_init(RGE_Game_World*);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    unsigned char gap_1F;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    short gap_2E;
    RGE_Sound** sounds;
    short sprite_num;
    short gap_36;
    RGE_Sprite** sprites;
    short player_num;
    short gap_3E;
    RGE_Player** players;
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
    virtual void sendUnitAIOrder(int, int, int, int, int,
                                 float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int,
                                float, float, float, float, int, int, int);
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
    virtual unsigned char command_place_object(
        short, float, float, float);

    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x22];
    short id;
    char gap_4C[0xE4];
    RGE_Static_Object* selected_obj;

    void unselect_object();
    void select_one_object(RGE_Static_Object*);
    int select_one_object(RGE_Static_Object*, int);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);

    char gap_04[0x1AC];
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    char gap_1BC[0x240];
    short master_obj_id;

    int get_paused();
    RGE_Player* get_player();
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
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

    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0xD0];

    void capture_mouse();
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

    TDrawArea* cur_render_area;
    int calc_draw_count;
    RGE_Game_World* world;
    RGE_Player* player;
    char gap_104[0x70];
    RGE_Static_Object* movable_object;
    char gap_178[0x1E8];
};

extern RGE_Base_Game* rge_base_game;

class RGE_Main_View : public RGE_View {
public:
    TPanel* map_view;
    unsigned long last_mouse_scroll_time;
    int mouse_scrolling;
    long mouse_last_x;
    long mouse_last_y;
    unsigned long last_key_scroll_time;
    int key_scrolling;
    RGE_Player* save_player;

    long mouse_left_down_action(long, long, int, int);
    unsigned char pick1(unsigned char, unsigned char, long, long,
                        RGE_Pick_Info*, RGE_Static_Object*, int);
    void fixup_pick_info(RGE_Pick_Info*);
};
#endif

long RGE_Main_View::mouse_left_down_action(long param_1, long param_2,
                                           int param_3, int param_4)
{
    short min_x;
    short min_y;
    short max_y;
    short max_x;
    tagPOINT point;
    RGE_Pick_Info pick_info;

    if (rge_base_game->get_paused() == 0) {
        int mode = rge_base_game->prog_mode;
        if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
            mode = rge_base_game->game_mode;
            color_log(0x4C, 0xBA, 1);

            switch (mode) {
            case 18:
                if (this->pick1(0x29, 0, param_1, param_2,
                                &pick_info, this->player->selected_obj, 1) == 0x34) {
                    this->player->unselect_object();
                    this->player->select_one_object(
                        (RGE_Static_Object*)pick_info.object, 1);
                    this->set_redraw(1);
                    if (((RGE_Static_Object*)pick_info.object)->sprite != 0) {
                        ((RGE_Static_Object*)pick_info.object)->get_frame(
                            &min_x, &min_y, &max_x, &max_y);
                        // ORIGINAL BUG: The shipped code subtracts the frame
                        // origin from pick_info's screen coordinates.
                        point.x = pick_info.scr_x - min_x;
                        point.y = pick_info.scr_y - min_y;
                        if (this->render_area->draw_system->screen_mode == 1) {
                            ClientToScreen(this->render_area->wnd, &point);
                        }
                        if (this->render_area->draw_system->screen_mode == 1) {
                            ScreenToClient(this->render_area->wnd, &point);
                        }
                        this->start_scroll_view(
                            4, point.x, point.y, param_3, param_4);
                    }
                }
                break;

            case 1:
                if (this->pick1(0x28, 0, param_1, param_2,
                                &pick_info, 0, 1) == 0x33) {
                    this->fixup_pick_info(&pick_info);
                    int object_id = rge_base_game->master_obj_id;
                    if (object_id != -1 &&
                        this->player->master_objects[object_id] != 0) {
                        RGE_Master_Static_Object* master =
                            this->player->master_objects[object_id];
                        master->alignment(&pick_info.x, &pick_info.y,
                                          this->world, 0);
                        this->player->command_place_object(
                            object_id, pick_info.x, pick_info.y, 0.0f);
                    } else if (object_id != -1 && this->world->players[0]
                               ->master_objects[object_id] != 0) {
                        RGE_Master_Static_Object* master =
                            this->world->players[0]->master_objects[object_id];
                        master->alignment(&pick_info.x, &pick_info.y,
                                          this->world, 0);
                        this->world->players[0]->command_place_object(
                            object_id, pick_info.x, pick_info.y, 0.0f);
                    }
                }
                break;

            case 9:
            case 10:
            case 19:
                if (this->player->selected_obj != 0) {
                    this->player->unselect_object();
                    this->set_redraw(1);
                }
                if (mode == 19) {
                    rge_base_game->set_game_mode(19, 0);
                }
                this->start_scroll_view(9, param_1, param_2, param_3, param_4);
                break;

            case 2:
            case 3:
            case 17:
                if (this->player->selected_obj != 0) {
                    this->player->unselect_object();
                    this->set_redraw(1);
                }
                // Fall through.  These modes use the same scroll command as 21.
            case 21:
                this->start_scroll_view(3, param_1, param_2, param_3, param_4);
                break;

            case 15:
                if (this->pick1(0x29, 0, param_1, param_2,
                                &pick_info, this->player->selected_obj, 1) == 0x34) {
                    if (((RGE_Static_Object*)pick_info.object)
                            ->master_obj->object_group != 0x22) {
                        unsigned char draw_level;
                        if (((RGE_Static_Object*)pick_info.object)->sprite_list != 0) {
                            draw_level = ((RGE_Static_Object*)pick_info.object)
                                ->sprite_list->get_lowest_draw_level();
                        } else if (((RGE_Static_Object*)pick_info.object)->sprite != 0) {
                            draw_level = ((RGE_Static_Object*)pick_info.object)
                                ->sprite->get_lowest_draw_level();
                        } else {
                            draw_level = 0x14;
                        }

                        this->save_player = rge_base_game->get_player();
                        rge_base_game->set_player(
                            ((RGE_Static_Object*)pick_info.object)->owner->id);
                        RGE_Base_Game* base_game = rge_base_game;
                        base_game->master_obj_id =
                            ((RGE_Static_Object*)pick_info.object)->master_obj->id;
                        this->movable_object =
                            (RGE_Static_Object*)pick_info.object;
                        ((RGE_Static_Object*)pick_info.object)->object_state = 7;
                        if (draw_level == 0) {
                            this->set_redraw(2);
                        }
                        rge_base_game->set_game_mode(8, 1);
                        if (this->movable_object->sprite != 0) {
                            this->movable_object->get_frame(
                                &min_x, &min_y, &max_x, &max_y);
                            // ORIGINAL BUG: The shipped code subtracts the
                            // frame origin from pick_info's screen coordinates.
                            point.x = pick_info.scr_x - min_x;
                            point.y = pick_info.scr_y - min_y;
                            if (this->render_area->draw_system->screen_mode == 1) {
                                ClientToScreen(this->render_area->wnd, &point);
                            }
                        }
                        this->start_scroll_view(
                            9, param_1, param_2, param_3, param_4);
                    }
                }
                break;

            default:
                this->capture_mouse();
                break;
            }

            color_log(0x4C, 0x5F, 1);
            return 1;
        }
    }
    return 0;
}
