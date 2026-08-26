// VA: 0053F3D0 RGE_Main_View::mouse_right_up_action(long,long,int,int)
// PDB source: vw_main.cpp:1157-1274
//
// Attempt log:
// - baseline reconstruction: restored the RGE_Main_View mouse-action path
//   from the executable, using the canonical player/pick-info ownership and
//   the natural interface-style/game-mode branches.  The local list pointer
//   precedes the 20-byte pick record, matching the observed stack window.
// - control-flow probes: an inverted game_mode test places the command path
//   inline and the nonzero-mode cleanup after it, matching the original CFG;
//   the remaining compiler drift is the initial mode/failure-tail placement.
//   Several equivalent guard/label spellings were tested and rolled back or
//   left only where the late failure line ordering is binary-supported.
// - final bounded state: exact frame/size and 22-call set; 21/22 ordered call
//   sites align.  Remaining drift is a broad VC5 block-layout/register basin,
//   not a proven ownership or behavior discrepancy.
// - structural recovery: split the paused and mouse-action failures into two
//   natural early guards.  This restores the original failure color_log call,
//   all 22 ordered call sites, and the original 647-byte size.  Remaining
//   drift starts at the interface-style global load and the unselect tail.
// - liveness probe: removed the second mode local and used direct program-mode
//   member tests.  This sinks the shared load after the interface-style compare;
//   the result is 9 bytes different with the same size, frame, and call order.
// - final codegen probe: a redraw after the overlay call is source-plausible,
//   but the binary emits no extra redraw call.  The otherwise natural call
//   restores the final 9-byte tail exactly.
// - Canonical slot recovery: the +78 virtual call is RGE_Static_Object::rotate
//   with a -1 direction. The prior do_right_action label used a later slot.

#include <stdlib.h>

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_Tile;
class RGE_Map;
class TShape;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class RGE_Prog_Info {
public:
    char gap_00[0x8DC];
    short interface_style;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);

    char gap_004[8];                       // +0x04..+0x0B
    RGE_Prog_Info* prog_info;              // +0x0C
    char gap_010[0x4C];                    // +0x10..+0x5B
    TShape** shapes;                       // +0x5C
    char gap_060[0x150];                   // +0x60..+0x1AF
    int prog_mode;                         // +0x1B0
    int game_mode;                         // +0x1B4

    int get_paused();
};

class RGE_Player {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void command_add_waypoint(float x, float y, float z);

    char gap_004[0x12C];                   // +0x04..+0x12F
    RGE_Static_Object* selected_obj;        // +0x130

    unsigned char get_selected_objects_to_command(
        RGE_Static_Object*** list_out, short* list_num_out,
        short min_select_level, short object_group,
        short object_id, short unit_level);
    void unselect_object();
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

    char gap_004[0xC0];
    long mouse_down_x;                     // +0xC4
    long mouse_down_y;                     // +0xC8
    int mouse_down_ctrl;                   // +0xCC
    int mouse_down_shift;                  // +0xD0
    unsigned long mouse_down_time;          // +0xD4
    int error_code;                        // +0xD8
    int z_order;                            // +0xDC
    int display_changed_count;             // +0xE0
    long help_string_id;                   // +0xE4
    long help_page_id;                     // +0xE8
    unsigned char mouse_action;            // +0xEC
    unsigned char mouse_down_button;        // +0xED
    unsigned char panel_type;              // +0xEE
    unsigned char color;                   // +0xEF
    unsigned char fill_in_background;      // +0xF0
    unsigned char clip_to_parent;          // +0xF1
    unsigned char draw_rect2_flag;         // +0xF2
    unsigned char need_restore;            // +0xF3

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

    void set_selection_area(long, long, long, long);
    void add_overlay_sprite(TShape* shape, int facet, int world_x, int world_y,
                            int flags, int draw_level, unsigned char* color_table,
                            int display_function, unsigned long draw_interval);

    void* render_area;                     // +0xF4
    int calc_draw_count;                   // +0xF8
    void* world;                           // +0xFC
    RGE_Player* player;                    // +0x100
    RGE_Map* map;                          // +0x104
    char gap_108[0x28];                    // +0x108..+0x12F
    int map_scr_x_offset;                  // +0x130
    int map_scr_y_offset;                  // +0x134
    char gap_138[0x30];                    // +0x138..+0x167
    unsigned char scroll_action;           // +0x168
};

class RGE_Main_View : public RGE_View {
public:
    virtual long mouse_right_up_action(long, long, int, int);
    virtual int command_place_object(long, long, int);
    virtual int command_make_do(long, long, int, short);
    virtual int command_make_move(long, long);
    virtual int command_make_work(long, long);
    virtual int command_place_multi_object(long, long, long, long, int);

    unsigned char pick1(unsigned char, unsigned char, long, long,
                        RGE_Pick_Info*, RGE_Static_Object*, int);
    void fixup_pick_info(RGE_Pick_Info*);
    void reset_display_object_selection(int);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void rotate(long);
    virtual void do_right_action(int);
};
#endif

extern RGE_Base_Game* rge_base_game;
extern int allow_user_commands;
extern "C" void __cdecl color_log(unsigned char, unsigned char, int);

long RGE_Main_View::mouse_right_up_action(long param_1, long param_2,
                                          int param_3, int param_4)
{
    RGE_Static_Object** list;
    RGE_Pick_Info pick_info;
    int mode = rge_base_game->prog_mode;

    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        color_log(0x4C, 0x32, 1);

        if (this->scroll_action != 0) {
            this->end_scroll_view();
        } else {
            this->release_mouse();

            if (rge_base_game->game_mode == 0x14) {
                if (this->pick1(0x29, 2, param_1, param_2,
                                &pick_info, this->player->selected_obj,
                                1) == 0x34) {
                    pick_info.object->rotate(-1);
                }
            } else {
                if (rge_base_game->get_paused() != 0) {
                    color_log(0x4C, 0x5F, 1);
                    return 0;
                }
                if ((this->mouse_action != 1) &&
                    (this->mouse_action != 2)) {
                    color_log(0x4C, 0x5F, 1);
                    return 0;
                }

                if (rge_base_game->prog_info->interface_style == 2) {
                    if ((rge_base_game->prog_mode != 5) &&
                        (rge_base_game->prog_mode != 7)) {
                        if (rge_base_game->game_mode == 0) {
                            if (param_4 == 0) {
                                this->command_make_do(param_1, param_2, 1, -1);
                            } else if (this->player->get_selected_objects_to_command(
                                           &list, (short*)&param_4,
                                           -1, -1, -1, -1)) {
                                free(list);
                                if (allow_user_commands != 0) {
                                    if (this->pick1(0x28, 0, param_1, param_2,
                                                    &pick_info, 0, 1) == 0x33) {
                                        this->fixup_pick_info(&pick_info);
                                        this->player->command_add_waypoint(
                                            pick_info.x, pick_info.y, 1.0f);
                                        this->reset_display_object_selection(2);
                                        this->add_overlay_sprite(
                                            rge_base_game->shapes[1], 0,
                                            this->map_scr_x_offset + param_1,
                                            this->map_scr_y_offset + param_2,
                                            0, 0x0F, 0, 1, 0xFA);
                                        this->set_redraw(1);
                                    }
                                }
                            }
                        } else {
                            if (rge_base_game->game_mode == 0x15) {
                                this->set_selection_area(-1, -1, -1, -1);
                                this->set_redraw(1);
                            }
                            rge_base_game->set_game_mode(0, 0);
                        }
                    }
                } else {
                    if (rge_base_game->prog_mode != 7) {
                        if (rge_base_game->game_mode != 0) {
                            rge_base_game->set_game_mode(0, 0);
                        } else {
                            this->player->unselect_object();
                            this->set_redraw(1);
                        }
                    }
                }
            }
        }

        color_log(0x4C, 0x5F, 1);
        return 1;
    } else {
        return 0;
    }
}
