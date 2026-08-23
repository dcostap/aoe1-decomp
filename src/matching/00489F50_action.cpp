// VA: 00489F50 action (973B)
// PDB source: rpnl_tbx.cpp:180-306
// FLAGS: /GX is required by the binary-observed new-expression EH frame.
// Recovery log:
// - The first typed baseline was 971 bytes. It had all 25 ordered calls.
// - The baseline used one common code-two close block. VC5 compared the stack home directly.
// - PDB records place this method between exact same-module constructor and destructor anchors.
// - PDB records also place key_down_action, game_mode_changed, and draw after this method.
// - PDB types prove the TPanel, TEasy_Panel, and TScreenPanel inheritance used here.
// - PDB types prove a 0x478 TScreenPanel and a 0x4BC RGE_Dialog_List.
// - PDB types place TListDialog::get_list_id at virtual slot 0x130.
// - The constructor proves TButtonPanel ownership for the seven button fields.
// - Exact source duplicates code-two close handling in both recognized-name arms.
// - The object arm returns one. The terrain arm falls to the common return.
// - VC5 merges these two source tails into one physical close block.
// - This merge keeps action_in in EAX for both code-one tests and the code-two test.
// - Removing the object return produced a 983-byte function with one extra compare block.
// - Adding a terrain return produced a 1002-byte function with one extra EH epilogue.
// - Removing the terrain goto and label kept the exact result. The final source has no label.
// - String externs, flat button types, the old command tree, and a dialog alias stayed exact.
// - Minimal declarations also stayed exact. These changes were not required for code generation.
// - The final source keeps the PDB-backed types and the simpler direct dialog ownership.
// - Final validation: 973 bytes, 294 instructions, 25 ordered calls, and 0.0000% difference.

#include <string.h>

class TPanel {
public:
    virtual ~TPanel();
    virtual void setup();
    virtual void set_rect_1();
    virtual void set_rect_2();
    virtual void set_color();
    virtual void set_active();
    virtual void set_positioning();
    virtual void set_fixed_position();
    virtual void set_redraw();
    virtual void set_overlapped_redraw();
    virtual void draw_setup();
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect();
    virtual void draw_offset();
    virtual void draw_rect2();
    virtual void draw_offset2();
    virtual void paint();
    virtual void wnd_proc();
    virtual void handle_idle();
    virtual void handle_size();
    virtual void handle_paint();
    virtual void handle_key_down();
    virtual void handle_char();
    virtual void handle_command();
    virtual void handle_user_command();
    virtual void handle_timer_command();
    virtual void handle_scroll();
    virtual void handle_mouse_down();
    virtual void handle_mouse_move();
    virtual void handle_mouse_up();
    virtual void handle_mouse_dbl_click();
    virtual void mouse_move_action();
    virtual void mouse_left_down_action();
    virtual void mouse_left_hold_action();
    virtual void mouse_left_move_action();
    virtual void mouse_left_up_action();
    virtual void mouse_left_dbl_click_action();
    virtual void mouse_right_down_action();
    virtual void mouse_right_hold_action();
    virtual void mouse_right_move_action();
    virtual void mouse_right_up_action();
    virtual void mouse_right_dbl_click_action();
    virtual void key_down_action();
    virtual void char_action();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();

    char gap_04[0xF0];

    char* panelName();
    char* get_string(int id);
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual void draw_background();
    virtual void set_ideal_size();
    virtual void create_button_number();
    virtual void create_button_text();
    virtual void create_check_box();
    virtual void create_radio_button();
    virtual void create_text_number();
    virtual void create_text_list();
    virtual void create_text();
    virtual void create_input();
    virtual void create_edit();
    virtual void create_drop_down();
    virtual int create_list(TPanel*, void**, long, long, long, long, long);
    virtual void create_scrollbar();
    virtual void create_auto_scrollbar();
    virtual void create_vert_slider();
    virtual void create_horz_slider();
    virtual void position_panel();

    char gap_F4[0x384];

    long get_popup_info_id();
    char* get_popup_info_file();
};

class TScreenPanel : public TEasy_Panel {
};

class TButtonPanel : public TPanel {
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0x18];
    unsigned char temp_pause;
};

class RGE_Player {
public:
    void unselect_object();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void vf04();
    virtual void vf08();
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int sub_mode);

    char gap_14[0x1AC];
    int prog_mode;                         // +0x1B0
    int game_mode;                         // +0x1B4
    char gap_1B8[0x23C];
    RGE_Game_World* world;                 // +0x3F4
    int render_all;                        // +0x3F8
    short master_obj_id;                   // +0x3FC
    short terrain_id;                      // +0x3FE

    void delete_dialog(TPanel** dialog);
    RGE_Player* get_player();
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
    virtual int setup(TPanel*, TPanel*, long, long, unsigned char, int);
    virtual int setup(TPanel*, TPanel*, long, long, char*, long, int);

    void* dlg_wnd;
    TPanel* save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;
};

class TListDialog : public TDialogPanel {
public:
    virtual ~TListDialog();
    virtual short get_list_id();           // vtable +0x130
    virtual char* get_list_name();         // vtable +0x134

    void* title;
    void* list;
    void* scroll_bar;
    void* ok_btn;
    void* cancel_btn;
    short list_id;
    char gap_4A6[2];
    char* list_name;
};

struct rdlg_list_info {
    char text[100];
    short id;
};

class RGE_Dialog_List : public TListDialog {
public:
    virtual ~RGE_Dialog_List();
    virtual short get_list_id();
    virtual int create_list();              // vtable +0x138
    virtual short get_cur_id();             // vtable +0x13C

    int list_type;
    short list_size;
    short list_line;
    rdlg_list_info* list_info;
    char** list_text;

    RGE_Dialog_List(char* name);
    int setup(TScreenPanel* screen, char* popup_file, long popup_id,
              int list_type, char* title);
};

class RGE_Panel_Tool_Box : public TPanel {
public:
    virtual ~RGE_Panel_Tool_Box();
    TScreenPanel* screen_panel;             // +0xF4
    void* view;                             // +0xF8
    void* map;                              // +0xFC
    TButtonPanel* game_mode_button;         // +0x100
    TButtonPanel* object_mode_button;       // +0x104
    TButtonPanel* delete_mode_button;       // +0x108
    TButtonPanel* move_mode_button;         // +0x10C
    TButtonPanel* terrain_mode_button;      // +0x110
    TButtonPanel* elevation_mode_button;    // +0x114
    TButtonPanel* command_button;           // +0x118
    TPanel* dialog;                         // +0x11C

    void game_mode_changed(int mode, int new_mode);
    virtual long action(TPanel* panel, long code,
                        unsigned long param_3, unsigned long param_4);
};

extern RGE_Base_Game* rge_base_game;

long RGE_Panel_Tool_Box::action(TPanel* panel, long code,
                                unsigned long param_3, unsigned long param_4)
{
    if (panel != 0) {
        if ((panel == this->game_mode_button) && (code == 1)) {
            rge_base_game->set_game_mode(0, 0);
            return 1;
        }

        if ((panel == this->object_mode_button) && (code == 1)) {
            this->dialog = new RGE_Dialog_List("Object List Dialog");
            if (this->dialog != 0) {
                if (((RGE_Dialog_List*)this->dialog)->setup(
                        this->screen_panel,
                        this->screen_panel->get_popup_info_file(),
                        this->screen_panel->get_popup_info_id(),
                        1,
                        this->get_string(0x232A)) == 0) {
                    delete this->dialog;
                    this->dialog = 0;
                }
            }
            return 1;
        }
        else {
            if ((panel == this->move_mode_button) && (code == 1)) {
                rge_base_game->set_game_mode(0x12, 0);
                return 1;
            }
            if ((panel == this->delete_mode_button) && (code == 1)) {
                rge_base_game->set_game_mode(0x0E, 0);
                return 1;
            }
            if ((panel == this->elevation_mode_button) && (code == 1)) {
                rge_base_game->set_game_mode(3, 0);
                return 1;
            }
            if ((panel == this->command_button) && (code == 1)) {
                if (rge_base_game->prog_mode == 4) {
                    rge_base_game->set_prog_mode(6);
                    rge_base_game->world->temp_pause = 1;
                }
                else {
                    rge_base_game->set_prog_mode(4);
                    return 1;
                }
            }
            else {
                if (panel != this->dialog) {
                    return 0;
                }

                // BINARY NOTE: Unknown dialog names skip both close arms.
                if (strcmp(this->dialog->panelName(), "Object List Dialog") == 0) {
                    if (code == 1) {
                        rge_base_game->master_obj_id =
                            ((RGE_Dialog_List*)this->dialog)->get_list_id();
                        rge_base_game->delete_dialog(&this->dialog);
                        rge_base_game->set_game_mode(1, 0);
                        rge_base_game->get_player()->unselect_object();
                        return 1;
                    }
                    if (code == 2) {
                        rge_base_game->delete_dialog(&this->dialog);
                        this->game_mode_changed(rge_base_game->game_mode,
                                                rge_base_game->game_mode);
                        // BINARY NOTE: This return lets VC5 merge both close tails.
                        return 1;
                    }
                }
                else if (strcmp(this->dialog->panelName(), "Terrain List Dialog") == 0) {
                    if (code == 1) {
                        rge_base_game->terrain_id =
                            ((RGE_Dialog_List*)this->dialog)->get_list_id();
                        rge_base_game->delete_dialog(&this->dialog);
                        rge_base_game->set_game_mode(2, 0);
                        return 1;
                    }
                    if (code == 2) {
                        rge_base_game->delete_dialog(&this->dialog);
                        this->game_mode_changed(rge_base_game->game_mode,
                                                rge_base_game->game_mode);
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}
