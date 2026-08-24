// RGE_Dialog_List::create_object_list
// VA: 0047E910
// PDB: rdlg_lst.cpp:151-207
//
// Attempt log:
// - Initial natural draft had the wrong RGE_Base_Game virtual slot, a 0x0C frame,
//   and an incorrect constant zero object id; it emitted an indexed record loop.
// - Restored the period RGE_Base_Game virtual surface (get_string at +0x1C),
//   canonical master-object/list-info fields, and the binary-proven object id
//   (short j, incremented for every master-object entry).
// - Short list index plus typed int unit cursors recovered the original 0x10
//   frame, 396-byte size, all three ordered calls, and the add-by-four master
//   object cursor shape. Separate first/second scan cursors are retained as the
//   cleanest source reconstruction; VC5 still colors the late cursor/id pair
//   opposite the executable and keeps the player/count homes swapped.
// - Tried local declaration reordering, a register cursor, induction update
//   order, and assignment-bound null-guard forms; no further emitted-code gain.
// - Final bounded result: structural parity is good (size/frame/calls exact),
//   but byte matching remains unresolved in the initial local schedule and
//   late cursor/id register/stack-home allocation. Left in scratch.
// - Fresh pass: packet, same-TU donors, ABI evidence, dossier, and focused
//   assembly donors confirm the typed player/master-object/list-info model.
// - Fresh probes tried pointer/count declaration order, direct initialization,
//   short counter reuse, shared cursor scope, and ordinary while/for scans.
//   The while form improved block coverage but worsened positional bytes.
// - Restored this clean natural candidate. Remaining lead is the original
//   VC5 local-home and late cursor/id allocation basin, not behavior or ABI.
// - Resumed after the host crash with the clean pin current and no new claim
//   probes. No evidence-backed natural source lead remains; retain this typed
//   candidate and pause rather than repeat prior codegen variants.
// - Applied the exact list ABI donor: TListDialog ends at +0x4AC and
//   list_type owns +0x4AC; emitted code stayed unchanged.
// - Removed the noncanonical RGE_Base_Game pre-vptr gap and used the binary
//   line-159 combined get_player guard; both emitted the same code.
// - An int i/j width probe moved the first bytes closer but lost the 0x10
//   frame and 37 bytes, so the short typed locals were restored.
// - Fresh claim probes split the get_player guard, varied counter/pointer
//   declaration order, removed this-qualification, and moved the cursor;
//   all returned the duplicate 358-byte basin. A guarded 9-case lab found
//   no first-block improvement. Retain this clean source and pause.
// - Replaced the second-pass object local with direct repeated master_objects
//   indexing. This recovered 143 instructions, 98.60% exact blocks, and a
//   localized 5-byte mismatch: the first-pass xor/movsx initialization order.
// - A six-case initialization lab, block-local declaration variants, and
//   register qualifiers all stayed in the same 5-byte basin. No natural exact
//   source lead remains in this pass; retain this candidate and pause.
// - Revisited the first scan with natural for/while forms, function-scope and
//   explicit local initialization, and a typed first-pass object local. The
//   structural forms worsened the loop; the remaining forms returned the same
//   5-byte basin. The ordered comma initializer was diagnostic only and was
//   discarded as compiler steering.
// - Clean direct-indexing source remains authoritative. The only mismatch is
//   the independent xor/movsx order at +0x3A; typed ownership and calls remain
//   exact. No policy-compliant natural source lead remains.
// ACCEPTED DRIFT: The five-byte span only exchanges adjacent XOR EDX,EDX and
// MOVSX ESI,BP instructions. They write separate registers. MOVSX preserves
// the flags produced by XOR, so registers and flags are equal afterward. No
// call, memory access, or branch occurs between them. All other bytes match.
// - Fresh exact-finish audit: canonical declaration-only panel surfaces from
//   setup, the protected helper owner, and the RGE_Player vptr changed no bytes.
// - Natural for-loop and update-order forms worsened size or block layout.
//   The direct do-loop remains the smallest source with exact calls and bounds.
// - Current evidence still shows one five-byte scheduling span only. No natural
//   source form tested here restores its XOR-before-MOVSX order.
// - Adding the canonical setup declarations kept the same emitted basin.

#ifndef RDLG_LST_TU_CONTEXT
#include <stdlib.h>
#include <string.h>
#include "..\..\include\game_globals.h"

class TPanel {
public:
    virtual ~TPanel();
    virtual void setup();
    virtual void set_rect_1();  virtual void set_rect_2();
    virtual void set_color();  virtual void set_active();
    virtual void set_positioning();  virtual void set_fixed_position();
    virtual void set_redraw();  virtual void set_overlapped_redraw();
    virtual void draw_setup();  virtual void draw_finish();
    virtual void draw();  virtual void draw_rect();
    virtual void draw_offset();  virtual void draw_rect2();
    virtual void draw_offset2();  virtual void paint();
    virtual void wnd_proc();  virtual void handle_idle();
    virtual void handle_size();  virtual void handle_paint();
    virtual void handle_key_down();  virtual void handle_char();
    virtual void handle_command();  virtual void handle_user_command();
    virtual void handle_timer_command();  virtual void handle_scroll();
    virtual void handle_mouse_down();  virtual void handle_mouse_move();
    virtual void handle_mouse_up();  virtual void handle_mouse_dbl_click();
    virtual void mouse_move_action();  virtual void mouse_left_down_action();
    virtual void mouse_left_hold_action();  virtual void mouse_left_move_action();
    virtual void mouse_left_up_action();  virtual void mouse_left_dbl_click_action();
    virtual void mouse_right_down_action();  virtual void mouse_right_hold_action();
    virtual void mouse_right_move_action();  virtual void mouse_right_up_action();
    virtual void mouse_right_dbl_click_action();  virtual void key_down_action();
    virtual void char_action();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void vfB8();  virtual void vfBC();  virtual void vfC0();
    virtual void vfC4();  virtual void vfC8();  virtual void vfCC();
    virtual void vfD0();  virtual void vfD4();  virtual void vfD8();
    virtual void vfDC();

    char gap_04[0xD4];
    int error_code;                 // +0x0D8
    char gap_DC[0x18];
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, void**, long, long, long, long, long, long, long, long, long);
    virtual int create_button_text(TPanel*, void**, char*, char*, long, long, long, long, long, long, long);
    virtual int create_check_box(TPanel*, void**, long, long, long, long, long, long);
    virtual int create_radio_button(TPanel*, void**, long, long, long, long, long, long);
    virtual int create_text_number(TPanel*, void**, int, long, long, long, long, long, int, int, int);
    virtual int create_text_list(TPanel*, void**, char**, long, long, long, long, long, long, int, int);
    virtual int create_text(TPanel*, void**, char*, long, long, long, long, long, int, int, int);
    virtual int create_input(TPanel*, void**, char*, short, long, long, long, long, long, long);
    virtual int create_edit(TPanel*, void**, char*, short, long, long, long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, void**, long, long, long, long, long, long, long);
    virtual int create_list(TPanel*, void**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, void**, TPanel*, long, long, long, long, long);
    virtual int create_auto_scrollbar(void**, TPanel*, long);
    virtual int create_vert_slider(TPanel*, void**, long, long, long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, void**, long, long, long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_F4[0x384];
    void* dlg_wnd;                  // +0x478
    TPanel* save_parent_child;      // +0x47C
    int text_font_id;               // +0x480
    int input_font_id;              // +0x484
    int button_font_id;             // +0x488
    int button_sound_id;             // +0x48C

    virtual int setup(TPanel*, TPanel*, long, long, unsigned char, int);
    virtual int setup(TPanel*, TPanel*, long, long, char*, long, int);
};

class TListDialog : public TDialogPanel {
public:
    void* title;                    // +0x490
    void* list;                     // +0x494
    void* scroll_bar;               // +0x498
    void* ok_btn;                   // +0x49C
    void* cancel_btn;               // +0x4A0
    short list_id;                  // +0x4A4
    char gap_4A6[0x02];
    char* list_name;                // +0x4A8

    virtual short get_list_id();
    virtual char* get_list_name();

    long setup(TPanel* param_1, char* param_2, long param_3,
               long param_4, long param_5, long param_6, long param_7,
               long param_8, long param_9, char* param_10,
               long param_11, long param_12, long param_13, long param_14,
               char** param_15, short param_16, short param_17,
               long param_18, long param_19, long param_20, long param_21,
               long param_22);
};

class TScreenPanel : public TEasy_Panel {
};

struct rdlg_list_info {
    char text[0x64];
    short id;
};

class RGE_Game_Object {
public:
    char gap_00[8];
    char* name;               // +0x08
    short icon_id;            // +0x0C
    char gap_0E[0x4E - 0x0E];
    unsigned char field_4E;   // +0x4E
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1E];
    short master_object_num;           // +0x22
    RGE_Game_Object** master_objects;  // +0x24
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int sub_mode);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int a, long b, char* c, int d);
    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

class RGE_Dialog_List : public TListDialog {
public:
    int list_type;                // +0x4AC
    short list_size;              // +0x4B0
    short list_line;              // +0x4B2
    rdlg_list_info* list_info;    // +0x4B4
    char** list_text;             // +0x4B8

    virtual int create_list();
    void sort_list();
    void calc_list_line();

protected:
    int create_object_list();

public:
    int setup(TScreenPanel* screen, char* popup_file, long popup_id,
              int list_type, char* title);
};
#endif

int RGE_Dialog_List::create_object_list()
{
    short i;
    short j;
    RGE_Player* player;
    short num_objects;

    if ((player = rge_base_game->get_player()) == 0)
        return 0;

    this->list_size = 1;
    num_objects = player->master_object_num;

    if (num_objects > 0) {
        int cnt;
        int obj_idx = 0;
        cnt = num_objects;
        do {
            if (player->master_objects[obj_idx] &&
                player->master_objects[obj_idx]->field_4E == 0)
                this->list_size++;
            obj_idx++;
            cnt--;
        } while (cnt != 0);
    }

    if (this->list_size == 0)
        return 0;

    this->list_info = (rdlg_list_info*)calloc(this->list_size, 0x66);
    if (!this->list_info)
        return 0;

    this->list_info[0].id = -1;
    strcpy(this->list_info[0].text, " <None> ");

    i = 1;
    j = 0;
    if (num_objects > 0) {
        int obj_idx = 0;
        do {
            if (player->master_objects[obj_idx] &&
                player->master_objects[obj_idx]->field_4E == 0) {
                this->list_info[i].id = j;
                if (player->master_objects[obj_idx]->icon_id > 0) {
                    rge_base_game->get_string(2, player->master_objects[obj_idx]->icon_id,
                                              (char*)&this->list_info[i], 100);
                } else {
                    strcpy(this->list_info[i].text, player->master_objects[obj_idx]->name);
                }
                i++;
            }
            j++;
            obj_idx++;
        } while (j < num_objects);
    }

    return 1;
}
