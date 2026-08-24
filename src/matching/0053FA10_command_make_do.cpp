// VA: 0053FA10 RGE_Main_View::command_make_do (440 bytes)
// PDB: vw_main.cpp:1439-1502
//
// Attempt log:
// - Replaced the placeholder with a period-plausible typed reconstruction from
//   the executable: selected-object filtering, target pick/command path, and
//   terrain fallback with the shared overlay/redraw cleanup.
// - Canonical ownership used here is RGE_View::player (+0x100), map screen
//   offsets (+0x130/+0x134), RGE_Base_Game::shapes (+0x5c), and the typed
//   RGE_Pick_Info layout; no raw address or compiler-steering scaffold.

#include <stdlib.h>

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class RGE_Player;
class RGE_Static_Object;
class RGE_Tile;
class RGE_Map;
class TShape;

struct RGE_Pick_Info {
    float x;                         // +0x00
    float y;                         // +0x04
    short scr_x;                     // +0x08
    short scr_y;                     // +0x0A
    RGE_Static_Object* object;       // +0x0C
    RGE_Tile* tile;                   // +0x10
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;                          // +0x04
    char gap_008[0x30];               // +0x08..+0x37
    float world_x;                    // +0x38
    float world_y;                    // +0x3C
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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float,
                                 float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, int, int, int);
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

    unsigned char get_selected_objects_to_command(
        RGE_Static_Object*** list_out, short* list_num_out,
        short min_select_level, short object_group, short object_id,
        short unit_level);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
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

    char gap_004[0xF0];
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

    void display_object_selection(int id, int duration, int select_type, int reset_type);
    void reset_overlay_sprites();
    void add_overlay_sprite(TShape* shape, int facet, int world_x, int world_y,
                            int flags, int draw_level, unsigned char* color_table,
                            int display_function, unsigned long draw_interval);

    void* cur_render_area;             // +0xF4
    int calc_draw_count;               // +0xF8
    void* world;                       // +0xFC
    RGE_Player* player;                // +0x100
    RGE_Map* map;                      // +0x104
    char gap_108[0x28];                // +0x108..+0x12F
    int map_scr_x_offset;              // +0x130
    int map_scr_y_offset;              // +0x134
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);

    char gap_004[0x58];                // +0x04..+0x5B
    TShape** shapes;                   // +0x5C
};

class RGE_Main_View : public RGE_View {
public:
    virtual int command_place_object(long, long, int);
    virtual int command_make_do(long, long, int, short);
    virtual int command_make_move(long, long);
    virtual int command_make_work(long, long);
    virtual int command_place_multi_object(long, long, long, long, int);

    RGE_Static_Object* pick_best_target(long, long, int*, short);
    unsigned char pick1(unsigned char, unsigned char, long, long,
                        RGE_Pick_Info*, RGE_Static_Object*, int);
    void fixup_pick_info(RGE_Pick_Info*);
    void reset_display_object_selection(int);
};
#endif

extern int allow_user_commands;
extern RGE_Base_Game* rge_base_game;
extern "C" void __cdecl color_log(unsigned char, unsigned char, int);

int RGE_Main_View::command_make_do(long param_1, long param_2,
                                   int param_3, short param_4)
{
    RGE_Static_Object** list;
    short list_num;
    int attacking;
    RGE_Pick_Info pick_info;
    int result;

    if (allow_user_commands != 0) {
        if (this->player->get_selected_objects_to_command(
                &list, &list_num, -1, -1, -1, -1)) {
            free(list);
            color_log(0x4C, 0xBA, 2);

            RGE_Static_Object* target = this->pick_best_target(
                param_1, param_2, &attacking, param_4);
            if (target != 0) {
                result = this->player->command_make_do(
                    target, target->world_x, target->world_y);
                if (result != 0) {
                    this->display_object_selection(target->id, 0x5DC, 2, 2);
                }
                this->reset_overlay_sprites();
                this->set_redraw(1);
                color_log(0x4C, 0x5F, 2);
                return result;
            }

            if (param_3 != 0) {
                if (this->pick1(0x28, 0, param_1, param_2,
                                &pick_info, 0, 1) == 0x33) {
                    this->fixup_pick_info(&pick_info);
                    result = this->player->command_make_move(
                        0, pick_info.x, pick_info.y);
                    if (result != 0) {
                        this->reset_display_object_selection(2);
                        this->add_overlay_sprite(
                            rge_base_game->shapes[2], 0,
                            this->map_scr_x_offset + param_1,
                            this->map_scr_y_offset + param_2,
                            0, 0x0F, 0, 2, 0x5A);
                        this->set_redraw(1);
                    }
                    color_log(0x4C, 0x5F, 2);
                    return result;
                }
            }

            this->reset_overlay_sprites();
            this->set_redraw(1);
            color_log(0x4C, 0x5F, 2);
        }
    }
    return 0;
}
