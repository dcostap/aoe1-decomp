// VA: 0052D600 mouse_left_up_action (844B)
// PDB: tvw_main.cpp, TRIBE_Main_View
//
// Initial reconstruction follows the executable's mode switch, typed pick
// info, player commands, overlay updates, and shared sound/game-mode tail.
// Attempt log:
// - Baseline matched the 0x14 frame and 844-byte boundary, but inlined the
//   paused/default forwarding block before the game-mode jump table.
// - Shared error/success labels restored all 32 ordered call targets and
//   matched the repeated invalid-action and sound/game-mode tails more closely.
// - Case-order and natural-default variants were rolled back; current source
//   keeps the readable typed reconstruction with evidence-backed tail labels.
// - Correcting mode-101/102 tail ownership alone worsened the diff to 656 bytes
//   and was rolled back.
// - Combining the line-backed mode-102-before-mode-101 order with the proven
//   tail ownership retained a 569-byte diff, improved exact-block coverage to
//   43.82%, and reduced the size gap to 40 bytes. The ordered tail gap remains.
// - A natural switch-tail fallthrough duplicated an earlier 744-byte basin and
//   dropped the packet's unload and redraw calls; it was rolled back.
// - An inline default arm kept the call multiset but moved the first switch
//   block and worsened the diff to 753 bytes; it was rolled back.
// - Inlining only mode-102's packet-backed play_sound/set_game_mode tail
//   reduced the diff to 192 bytes and restored the original 844-byte size;
//   the remaining call gap is the final mode-105 redraw past the boundary.
// - Moving the shared done label before error_a preserved the original
//   +014D/+015C tail and reduced the diff to 176 bytes; mode-105's invalid
//   guard still receives a local return block 10 bytes larger than the
//   original shared branch, so its final redraw call is truncated.
// - The exact same-TU donor's short command_make_do ABI was applied; VC5
//   emitted identical bytes. Invalid-label placement and a positive mode-105
//   guard were also duplicates and were rolled back.
// - Routing invalid_action through the shared return_one label tail-merged
//   the +015C return and recovered the final mode-105 redraw; diff fell to
//   17 bytes with all 32 calls, size, frame, and CFG exact.
// - Reversing mode-103's success guard to match its jne/jmp block reduced the
//   remaining diff to 14 bytes. The target-local declaration, short
//   pick_best_target ABI, case-104 scope removal, and positive mode-102 guard
//   emitted duplicates.
// - Paused in EXACT CODEGEN: remaining 14 bytes are localized register
//   coloring at mode-102 (+0124) and repair mode-104 (+0240/+0273); no new
//   source-backed lead remains within this claim.
// - Fresh claim probes: top-level int/long coordinate temps, register
//   parameters, positive and split guards, local declaration order, coordinate
//   casts, inherited receiver casts, shared call-result locals, repair-result
//   locals, object-id temps, and delayed receiver/game-mode aliases were either
//   codegen duplicates or moved into a worse basin. Donor-supported stdlib,
//   string, Windows, and combined header contexts were duplicates.
// - A 9-variant lab combined direct/base/narrow call spellings for mode-102 and
//   mode-104. All variants formed one 844-byte, 14-byte-diff group. The clean
//   typed source remains authoritative; no policy-valid exact lead was found.
// ACCEPTED DRIFT: The 14 bytes only recolor caller-saved registers in mode 102
// and mode 104. Each stack value reaches the same argument position, each
// indirect call uses the same vtable slot, and the selected object's same +4
// field reaches the same display argument. Calls then kill the temporary maps.
// Instruction order, memory access, predicates, writes, cleanup, and faults match.

class TShape;
class RGE_Tile;
class RGE_Static_Object;
class TRIBE_Player;
class RGE_Main_View;

struct RGE_Prog_Info {
    char gap_00[0x8DC];
    short interface_style;
};

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);

    char gap_04[0x8];
    RGE_Prog_Info* prog_info;
    char gap_10[0x4C];
    TShape** shapes;
    char gap_60[0x150];
    int prog_mode;
    int game_mode;
    int sub_game_mode;

    int get_paused();
    int play_sound(int);
};

extern RGE_Base_Game* rge_base_game;

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

    char gap_04[0xE8];
    unsigned char mouse_action;
    char gap_ED[7];

    void release_mouse();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
};

class TRIBE_Player {
public:
    unsigned char command_attack_ground(float, float);
    unsigned char command_make_unload(float, float);
    unsigned char command_make_repair(RGE_Static_Object*);
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

    void add_overlay_sprite(TShape*, int, int, int, int, int, unsigned char*,
                            int, unsigned long);
    void reset_overlay_sprites();
    void display_object_selection(int, int, int, int);

    void* cur_render_area;
    int calc_draw_count;
    void* world;
    TRIBE_Player* player;
    char gap_104[0x2C];
    int map_scr_x_offset;
    int map_scr_y_offset;
};

class RGE_Main_View : public RGE_View {
public:
    virtual int command_place_object(long, long, int);
    virtual int command_make_do(long, long, int, short);
    virtual int command_make_move(long, long);
    virtual int command_make_work(long, long);
    virtual int command_place_multi_object(long, long, long, long, int);

    unsigned char pick1(unsigned char, unsigned char, long, long,
                        RGE_Pick_Info*, RGE_Static_Object*, int);
    void fixup_pick_info(RGE_Pick_Info*);
    void reset_display_object_selection(int);
    RGE_Static_Object* pick_best_target(long, long, int*, short);

    virtual long mouse_left_up_action(long, long, int, int);
};

class TRIBE_Main_View : public RGE_Main_View {
public:
    virtual long mouse_left_up_action(long, long, int, int);
};

long TRIBE_Main_View::mouse_left_up_action(long param_1, long param_2,
                                           int param_3, int param_4) {
    int mode = rge_base_game->prog_mode;
    RGE_Pick_Info pick_info;
    RGE_Static_Object* object;

    if (mode != 4 && mode != 6 && mode != 7 && mode != 5) {
        return 0;
    }

    if (rge_base_game->get_paused() != 0)
        goto default_action;

    switch (rge_base_game->game_mode) {
    case 100:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->pick1(0x28, 0, param_1, param_2, &pick_info, 0, 1) == 0x33) {
            this->fixup_pick_info(&pick_info);
            if (this->player->command_attack_ground(pick_info.x, pick_info.y) != 0) {
                this->reset_display_object_selection(2);
                this->add_overlay_sprite(
                    rge_base_game->shapes[2], 0,
                    this->map_scr_x_offset + param_1,
                    this->map_scr_y_offset + param_2,
                    0, 0x0F, 0, 2, 0x7D);
                this->set_redraw(1);
                goto done_b;
            }
        }
        goto error_b;

    case 102:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->command_make_do(param_1, param_2, 0, 0x69) != 0)
            goto done_a;
        rge_base_game->play_sound(3);
        goto done_a;

done_a:
        rge_base_game->set_game_mode(0, 0);
return_one:
        return 1;

error_a:
        rge_base_game->play_sound(3);
        goto done_a;

default_action:
        return RGE_Main_View::mouse_left_up_action(
            param_1, param_2, param_3, param_4);

    case 101:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->command_make_do(param_1, param_2, 0, 0x68) == 0)
            goto error_b;
        goto done_b;

error_b:
        rge_base_game->play_sound(3);
done_b:
        rge_base_game->set_game_mode(0, 0);
        return 1;

    case 103:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->command_make_do(param_1, param_2, 0, 7) != 0)
            goto done_a;
        goto error_a;

    case 104:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        object = this->pick_best_target(param_1, param_2, 0, -1);
        if (object != 0 && this->player->command_make_repair(object) != 0) {
            this->display_object_selection(object->id, 0x5DC, 2, 2);
            this->reset_overlay_sprites();
            this->set_redraw(1);
            goto done_a;
        }
        goto error_a;

    case 105:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->pick1(0x28, 0, param_1, param_2, &pick_info, 0, 1) == 0x33) {
            this->fixup_pick_info(&pick_info);
            if (this->player->command_make_unload(pick_info.x, pick_info.y) != 0) {
                this->reset_display_object_selection(2);
                this->add_overlay_sprite(
                    rge_base_game->shapes[2], 0,
                    this->map_scr_x_offset + param_1,
                    this->map_scr_y_offset + param_2,
                    0, 0x0F, 0, 2, 0x7D);
                this->set_redraw(1);
                goto done_a;
            }
        }
        goto error_a;

    default:
        goto default_action;
    }

invalid_action:
    goto return_one;
}
