#pragma once
#include "../common.h"
#include "Drawarea.h"

// ----------------------------------------------------------------
// PanelNode
// Size: 0xC
struct PanelNode {
    TPanel * panel; // 0x0
    PanelNode * prev_node; // 0x4
    PanelNode * next_node; // 0x8
};

class TPanel {
public:
    TPanel* previousPanelValue;              // 0x4
    TPanel* previousModalPanelValue;         // 0x8
    long pnl_x;                              // 0xC
    long pnl_y;                              // 0x10
    long pnl_wid;                            // 0x14
    long pnl_hgt;                            // 0x18
    char* panelNameValue;                    // 0x1C
    TDrawArea* render_area;                  // 0x20
    tagRECT clip_rect;                       // 0x24
    PositionMode position_mode;              // 0x34
    RedrawMode need_redraw;                  // 0x38
    TPanel* curr_child;                      // 0x3C
    TPanel* parent_panel;                    // 0x40
    TPanel* left_panel;                      // 0x44
    TPanel* top_panel;                       // 0x48
    TPanel* right_panel;                     // 0x4C
    TPanel* bottom_panel;                    // 0x50
    PanelNode* node;                         // 0x54
    PanelNode* first_child_node;             // 0x58
    PanelNode* last_child_node;              // 0x5C
    TPanel* tab_prev_panel;                  // 0x60
    TPanel* tab_next_panel;                  // 0x64
    int mouse_captured;                      // 0x68
    int active;                              // 0x6C
    int visible;                             // 0x70
    int tab_stop;                            // 0x74
    int have_focus;                          // 0x78
    int overlapping_children;                // 0x7C
    int handle_mouse_input;                  // 0x80
    int just_drawn;                          // 0x84
    void* clip_rgn;                          // 0x88
    tagRECT render_rect;                     // 0x8C
    long left_border;                        // 0x9C
    long top_border;                         // 0xA0
    long right_border;                       // 0xA4
    long bottom_border;                      // 0xA8
    long min_wid;                            // 0xAC
    long max_wid;                            // 0xB0
    long min_hgt;                            // 0xB4
    long max_hgt;                            // 0xB8
    long mouse_hold_interval;                // 0xBC
    long mouse_move_tolerance;               // 0xC0
    long mouse_down_x;                       // 0xC4
    long mouse_down_y;                       // 0xC8
    int mouse_down_ctrl;                     // 0xCC
    int mouse_down_shift;                    // 0xD0
    ulong mouse_down_time;                   // 0xD4
    int error_code;                          // 0xD8
    int z_order;                             // 0xDC
    int display_changed_count;               // 0xE0
    long help_string_id;                     // 0xE4
    long help_page_id;                       // 0xE8
    uchar mouse_action;                      // 0xEC
    uchar mouse_down_button;                 // 0xED
    uchar panel_type;                        // 0xEE
    uchar color;                             // 0xEF
    uchar fill_in_background;                // 0xF0
    uchar clip_to_parent;                    // 0xF1
    uchar draw_rect2_flag;                   // 0xF2
    uchar need_restore;                      // 0xF3

    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long char_action(long param_1, short param_2);
    virtual void take_snapshot();
    TPanel(char* param_1);
    TPanel();
    virtual ~TPanel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7);
    virtual void add_panel_node(PanelNode* param_1, PanelNode* param_2, int param_3);
    virtual void remove_panel_node(PanelNode* param_1);
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void set_rect(tagRECT param_1);
    virtual void set_color(uchar param_1);
    virtual void set_active(int param_1);
    virtual void set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13);
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4);
    virtual void set_redraw(RedrawMode param_1);
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3);
    virtual void set_any_overlapping_redraw(TPanel* param_1, RedrawMode param_2);
    virtual void draw();
    virtual void draw_rect(tagRECT* param_1);
    virtual void draw_offset(long param_1, long param_2, tagRECT* param_3);
    virtual void draw_rect2(tagRECT* param_1);
    virtual void draw_offset2(long param_1, long param_2, tagRECT* param_3);
    virtual void draw_setup(int param_1);
    virtual void draw_finish();
    virtual void paint();
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    virtual long handle_idle();
    virtual long handle_size(long param_1, long param_2);
    virtual long handle_paint();
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long handle_char(long param_1, short param_2);
    virtual long handle_command(uint param_1, long param_2);
    virtual long handle_user_command(uint param_1, long param_2);
    virtual long handle_timer_command(uint param_1, long param_2);
    virtual long handle_scroll(long param_1, long param_2);
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4);
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void get_mouse_info(uint param_1, long param_2, tagPOINT* param_3, int* param_4, int* param_5);
    virtual void get_mouse_pos(tagPOINT* param_1);
    virtual int capture_mouse();
    virtual void release_mouse();
    virtual uchar is_redraw_needed();
    virtual int is_inside(long param_1, long param_2);
    virtual int is_inside_rect(long param_1, long param_2, tagRECT* param_3);
    virtual int bound_point(long* param_1, long* param_2);
    virtual void set_curr_child(TPanel* param_1);
    virtual void set_focus(int param_1);
    virtual int get_focus();
    virtual void set_z_order(uchar param_1, short param_2);
    virtual void set_child_z_order(TPanel* param_1, uchar param_2, short param_3);
    virtual void set_tab_order(TPanel** param_1, short param_2);
    virtual void set_tab_order(TPanel* param_1, TPanel* param_2);
    virtual TPanel* previousPanel();
    virtual void setPreviousPanel(TPanel* param_1);
    virtual TPanel* previousModalPanel();
    virtual void setPreviousModalPanel(TPanel* param_1);
    virtual char* panelName();
    virtual void setPanelName(char* param_1);
    virtual long xPosition();
    virtual long yPosition();
    virtual long width();
    virtual long height();
    virtual TDrawArea* renderArea();
    virtual tagRECT* clipRectangle(tagRECT* __return_storage_ptr__);
    virtual void setClipRectangle(tagRECT param_1);
    virtual void delete_panel(TPanel** param_1);
    virtual int get_string(int param_1, char* param_2, int param_3);
    virtual char* get_string(int param_1);
    virtual long get_help_message();
    virtual long get_help_page();
    virtual void set_help_info(long param_1, long param_2);
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void handle_reactivate();
    virtual void get_true_render_rect(tagRECT* param_1);
};

static_assert(sizeof(TPanel) == 0xF4, "TPanel Size Mismatch");
static_assert(offsetof(TPanel, need_restore) == 0xF3, "TPanel Offset Mismatch");

class TPanelSystem {
public:
    TPanel* keyboardOwnerValue;              // 0x4
    TPanel* modalPanelValue;                 // 0x8
    TPanel* currentPanelValue;               // 0xC
    PanelNode* panelListValue;               // 0x10
    int numberActivePanelsValue;             // 0x14
    TPanel* prevCurrentChildValue;           // 0x18
    void* palette[10];                       // 0x1C
    char palette_file[10][260];                  // 0x44
    int palette_use_count[10];               // 0xA6C
    long palette_id[10];                     // 0xA94
    ulong Imc;                               // 0xABC
    int ImeEnabled;                          // 0xAC0
    int ImeOn;                               // 0xAC4
    int InputEnabled;                        // 0xAC8
    int saved_colors;                        // 0xACC
    ulong save_back_color;                   // 0xAD0
    ulong save_text_color;                   // 0xAD4

    TPanelSystem();
    virtual ~TPanelSystem();
    virtual TPanel* currentPanel();
    virtual TPanel* previousPanel();
    virtual TPanel* mouseOwner();
    virtual TPanel* keyboardOwner();
    virtual TPanel* modalPanel();
    virtual TPanel* panel(char* param_1);
    virtual int numberActivePanels();
    virtual int addPanel(TPanel* param_1, int param_2, int param_3);
    virtual int removePanel(char* param_1);
    virtual int setCurrentPanel(char* param_1, int param_2);
    virtual int restorePreviousPanel(int param_1);
    virtual void setMouseOwner(TPanel* param_1);
    virtual void setKeyboardOwner(TPanel* param_1);
    virtual void setModalPanel(TPanel* param_1);
    virtual void setCurrentPanelModal();
    virtual int restorePreviousModalPanel();
    virtual int destroyPanel(char* param_1);
    virtual int inSystem(char* param_1);
    virtual int inSystem(TPanel* param_1);
    virtual int setup();
    virtual PanelNode* findPanelNode(char* param_1);
    virtual void setCurrentPanel(TPanel* param_1, int param_2);
    virtual void* get_palette(char* param_1, long param_2);
    virtual void release_palette(void* param_1);
    virtual void DisableIME();
    virtual void EnableIME();
    virtual int IsIMEEnabled();
    virtual void TurnIMEOn();
    virtual void TurnIMEOff();
    virtual int IsIMEOn();
    virtual int GetInputEnabled();
    virtual void EnableInput();
    virtual void DisableInput();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void restore_system_colors();
    virtual void set_restore();
};

static_assert(sizeof(TPanelSystem) == 0xAD8, "TPanelSystem Size Mismatch");
static_assert(offsetof(TPanelSystem, save_text_color) == 0xAD4, "TPanelSystem Offset Mismatch");

long TPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_move_action(TPanel * this, long param_1, long
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_move_action@TPanel@@UAEJJJHH@Z                        XREF[70]:    0056f588(*), 0056f690(*),
//                               TPanel::mouse_move_action                                                 0056f7d0(*), 0056f918(*),
//                                                                                                         0056fa48(*), 0056fb78(*),
//                                                                                                         0056fcb0(*), 0056fde0(*),
//                                                                                                         0056ff10(*), 00570040(*),
//                                                                                                         00570170(*), 00570cb8(*),
//                                                                                                         00570d98(*), 00571048(*),
//                                                                                                         00571130(*), 00571260(*),
//                                                                                                         00571340(*), 00571428(*),
//                                                                                                         00571508(*), 005716e8(*), [more]
//                              panel.h:230 (5)
//         00437110     XOR        EAX,EAX
//         00437112     RET        0x10
//         00437115     ??         90h
//         00437116     NOP
//         00437117     NOP
//         00437118     NOP
//         00437119     NOP
//         0043711a     NOP
//         0043711b     NOP
//         0043711c     NOP
//         0043711d     NOP
//         0043711e     NOP
//         0043711f     NOP
    return 0;
}

long TPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_down_action(TPanel * this, long param_1,
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_left_down_action@TPanel@@UAEJJJHH@Z                   XREF[56]:    0056f58c(*), 0056f694(*),
//                               TPanel::mouse_left_down_action                                            0056f7d4(*), 0056f91c(*),
//                                                                                                         0056fa4c(*), 0056fb7c(*),
//                                                                                                         0056fcb4(*), 0056fde4(*),
//                                                                                                         0056ff14(*), 00570044(*),
//                                                                                                         00570174(*), 00570cbc(*),
//                                                                                                         00570d9c(*), 00571134(*),
//                                                                                                         00571264(*), 0057142c(*),
//                                                                                                         005716ec(*), 005717d4(*),
//                                                                                                         00571994(*), 00571d74(*), [more]
//                              panel.h:232 (5)
//         00437230     XOR        EAX,EAX
//         00437232     RET        0x10
//         00437235     ??         90h
//         00437236     NOP
//         00437237     NOP
//         00437238     NOP
//         00437239     NOP
//         0043723a     NOP
//         0043723b     NOP
//         0043723c     NOP
//         0043723d     NOP
//         0043723e     NOP
//         0043723f     NOP
    return 0;
}

long TPanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_hold_action(TPanel * this, long param_1,
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_left_hold_action@TPanel@@UAEJJJHH@Z                   XREF[73]:    0056f590(*), 0056f698(*),
//                               TPanel::mouse_left_hold_action                                            0056f7d8(*), 0056f920(*),
//                                                                                                         0056fa50(*), 0056fb80(*),
//                                                                                                         0056fcb8(*), 0056fde8(*),
//                                                                                                         0056ff18(*), 00570048(*),
//                                                                                                         00570178(*), 00570cc0(*),
//                                                                                                         00570da0(*), 00571050(*),
//                                                                                                         00571138(*), 00571268(*),
//                                                                                                         00571348(*), 00571430(*),
//                                                                                                         00571510(*), 00571600(*), [more]
//                              panel.h:234 (5)
//         00437240     XOR        EAX,EAX
//         00437242     RET        0x10
//         00437245     ??         90h
//         00437246     NOP
//         00437247     NOP
//         00437248     NOP
//         00437249     NOP
//         0043724a     NOP
//         0043724b     NOP
//         0043724c     NOP
//         0043724d     NOP
//         0043724e     NOP
//         0043724f     NOP
    return 0;
}

long TPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_move_action(TPanel * this, long param_1,
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_left_move_action@TPanel@@UAEJJJHH@Z                   XREF[62]:    0056f594(*), 0056f69c(*),
//                               TPanel::mouse_left_move_action                                            0056f7dc(*), 0056f924(*),
//                                                                                                         0056fa54(*), 0056fb84(*),
//                                                                                                         0056fcbc(*), 0056fdec(*),
//                                                                                                         0056ff1c(*), 0057004c(*),
//                                                                                                         0057017c(*), 00570cc4(*),
//                                                                                                         00570da4(*), 0057113c(*),
//                                                                                                         0057126c(*), 00571434(*),
//                                                                                                         00571514(*), 005716f4(*),
//                                                                                                         005717dc(*), 0057199c(*), [more]
//                              panel.h:236 (5)
//         00437250     XOR        EAX,EAX
//         00437252     RET        0x10
//         00437255     ??         90h
//         00437256     NOP
//         00437257     NOP
//         00437258     NOP
//         00437259     NOP
//         0043725a     NOP
//         0043725b     NOP
//         0043725c     NOP
//         0043725d     NOP
//         0043725e     NOP
//         0043725f     NOP
    return 0;
}

long TPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_up_action(TPanel * this, long param_1, lo
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_left_up_action@TPanel@@UAEJJJHH@Z                     XREF[60]:    0056f598(*), 0056f6a0(*),
//                               TPanel::mouse_left_up_action                                              0056f7e0(*), 0056f928(*),
//                                                                                                         0056fa58(*), 0056fb88(*),
//                                                                                                         0056fcc0(*), 0056fdf0(*),
//                                                                                                         0056ff20(*), 00570050(*),
//                                                                                                         00570180(*), 00570cc8(*),
//                                                                                                         00570da8(*), 00571140(*),
//                                                                                                         00571270(*), 00571438(*),
//                                                                                                         00571518(*), 005716f8(*),
//                                                                                                         005717e0(*), 005719a0(*), [more]
//                              panel.h:238 (5)
//         00437260     XOR        EAX,EAX
//         00437262     RET        0x10
//         00437265     ??         90h
//         00437266     NOP
//         00437267     NOP
//         00437268     NOP
//         00437269     NOP
//         0043726a     NOP
//         0043726b     NOP
//         0043726c     NOP
//         0043726d     NOP
//         0043726e     NOP
//         0043726f     NOP
    return 0;
}

long TPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_dbl_click_action(TPanel * this, long para
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_left_dbl_click_action@TPanel@@UAEJJJHH@Z              XREF[68]:    0056f59c(*), 0056f6a4(*),
//                               TPanel::mouse_left_dbl_click_action                                       0056f7e4(*), 0056f92c(*),
//                                                                                                         0056fa5c(*), 0056fb8c(*),
//                                                                                                         0056fcc4(*), 0056fdf4(*),
//                                                                                                         0056ff24(*), 00570054(*),
//                                                                                                         00570184(*), 00570ccc(*),
//                                                                                                         00570dac(*), 00571144(*),
//                                                                                                         00571274(*), 0057143c(*),
//                                                                                                         0057151c(*), 005716fc(*),
//                                                                                                         005717e4(*), 005718c4(*), [more]
//                              panel.h:240 (5)
//         00437270     XOR        EAX,EAX
//         00437272     RET        0x10
//         00437275     ??         90h
//         00437276     NOP
//         00437277     NOP
//         00437278     NOP
//         00437279     NOP
//         0043727a     NOP
//         0043727b     NOP
//         0043727c     NOP
//         0043727d     NOP
//         0043727e     NOP
//         0043727f     NOP
    return 0;
}

long TPanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_right_down_action(TPanel * this, long param_1,
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_right_down_action@TPanel@@UAEJJJHH@Z                  XREF[66]:    0056f5a0(*), 0056f6a8(*),
//                               TPanel::mouse_right_down_action                                           0056f7e8(*), 0056f930(*),
//                                                                                                         0056fa60(*), 0056fb90(*),
//                                                                                                         0056fcc8(*), 0056fdf8(*),
//                                                                                                         0056ff28(*), 00570058(*),
//                                                                                                         00570188(*), 00570cd0(*),
//                                                                                                         00570db0(*), 00571148(*),
//                                                                                                         00571278(*), 00571440(*),
//                                                                                                         00571520(*), 00571610(*),
//                                                                                                         00571700(*), 005717e8(*), [more]
//                              panel.h:242 (5)
//         00437280     XOR        EAX,EAX
//         00437282     RET        0x10
//         00437285     ??         90h
//         00437286     NOP
//         00437287     NOP
//         00437288     NOP
//         00437289     NOP
//         0043728a     NOP
//         0043728b     NOP
//         0043728c     NOP
//         0043728d     NOP
//         0043728e     NOP
//         0043728f     NOP
    return 0;
}

long TPanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_right_hold_action(TPanel * this, long param_1,
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_right_hold_action@TPanel@@UAEJJJHH@Z                  XREF[73]:    0056f5a4(*), 0056f6ac(*),
//                               TPanel::mouse_right_hold_action                                           0056f7ec(*), 0056f934(*),
//                                                                                                         0056fa64(*), 0056fb94(*),
//                                                                                                         0056fccc(*), 0056fdfc(*),
//                                                                                                         0056ff2c(*), 0057005c(*),
//                                                                                                         0057018c(*), 00570cd4(*),
//                                                                                                         00570db4(*), 00571064(*),
//                                                                                                         0057114c(*), 0057127c(*),
//                                                                                                         0057135c(*), 00571444(*),
//                                                                                                         00571524(*), 00571614(*), [more]
//                              panel.h:244 (5)
//         00437290     XOR        EAX,EAX
//         00437292     RET        0x10
//         00437295     ??         90h
//         00437296     NOP
//         00437297     NOP
//         00437298     NOP
//         00437299     NOP
//         0043729a     NOP
//         0043729b     NOP
//         0043729c     NOP
//         0043729d     NOP
//         0043729e     NOP
//         0043729f     NOP
    return 0;
}

long TPanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_right_move_action(TPanel * this, long param_1,
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_right_move_action@TPanel@@UAEJJJHH@Z                  XREF[66]:    0056f5a8(*), 0056f6b0(*),
//                               TPanel::mouse_right_move_action                                           0056f7f0(*), 0056f938(*),
//                                                                                                         0056fa68(*), 0056fb98(*),
//                                                                                                         0056fcd0(*), 0056fe00(*),
//                                                                                                         0056ff30(*), 00570060(*),
//                                                                                                         00570190(*), 00570cd8(*),
//                                                                                                         00570db8(*), 00571150(*),
//                                                                                                         00571280(*), 00571448(*),
//                                                                                                         00571528(*), 00571618(*),
//                                                                                                         00571708(*), 005717f0(*), [more]
//                              panel.h:246 (5)
//         004372a0     XOR        EAX,EAX
//         004372a2     RET        0x10
//         004372a5     ??         90h
//         004372a6     NOP
//         004372a7     NOP
//         004372a8     NOP
//         004372a9     NOP
//         004372aa     NOP
//         004372ab     NOP
//         004372ac     NOP
//         004372ad     NOP
//         004372ae     NOP
//         004372af     NOP
    return 0;
}

long TPanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_right_up_action(TPanel * this, long param_1, l
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_right_up_action@TPanel@@UAEJJJHH@Z                    XREF[66]:    0056f5ac(*), 0056f6b4(*),
//                               TPanel::mouse_right_up_action                                             0056f7f4(*), 0056f93c(*),
//                                                                                                         0056fa6c(*), 0056fb9c(*),
//                                                                                                         0056fcd4(*), 0056fe04(*),
//                                                                                                         0056ff34(*), 00570064(*),
//                                                                                                         00570194(*), 00570cdc(*),
//                                                                                                         00570dbc(*), 00571154(*),
//                                                                                                         00571284(*), 0057144c(*),
//                                                                                                         0057152c(*), 0057161c(*),
//                                                                                                         0057170c(*), 005717f4(*), [more]
//                              panel.h:248 (5)
//         004372b0     XOR        EAX,EAX
//         004372b2     RET        0x10
//         004372b5     ??         90h
//         004372b6     NOP
//         004372b7     NOP
//         004372b8     NOP
//         004372b9     NOP
//         004372ba     NOP
//         004372bb     NOP
//         004372bc     NOP
//         004372bd     NOP
//         004372be     NOP
//         004372bf     NOP
    return 0;
}

long TPanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_right_dbl_click_action(TPanel * this, long par
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_right_dbl_click_action@TPanel@@UAEJJJHH@Z             XREF[70]:    0056f5b0(*), 0056f6b8(*),
//                               TPanel::mouse_right_dbl_click_action                                      0056f7f8(*), 0056f940(*),
//                                                                                                         0056fa70(*), 0056fba0(*),
//                                                                                                         0056fcd8(*), 0056fe08(*),
//                                                                                                         0056ff38(*), 00570068(*),
//                                                                                                         00570198(*), 00570ce0(*),
//                                                                                                         00570dc0(*), 00571158(*),
//                                                                                                         00571288(*), 00571450(*),
//                                                                                                         00571530(*), 00571620(*),
//                                                                                                         00571710(*), 005717f8(*), [more]
//                              panel.h:250 (5)
//         00437490     XOR        EAX,EAX
//         00437492     RET        0x10
//         00437495     ??         90h
//         00437496     NOP
//         00437497     NOP
//         00437498     NOP
//         00437499     NOP
//         0043749a     NOP
//         0043749b     NOP
//         0043749c     NOP
//         0043749d     NOP
//         0043749e     NOP
//         0043749f     NOP
    return 0;
}

long TPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall key_down_action(TPanel * this, long param_1, short p
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              short             Stack[0x8]:2   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?key_down_action@TPanel@@UAEJJFHHH@Z                         XREF[54]:    0056f5b4(*), 0056f6bc(*),
//                               TPanel::key_down_action                                                   0056f7fc(*), 0056f944(*),
//                                                                                                         0056fa74(*), 0056fcdc(*),
//                                                                                                         0056ff3c(*), 0057006c(*),
//                                                                                                         0057019c(*), 00570ce4(*),
//                                                                                                         00570dc4(*), 0057115c(*),
//                                                                                                         0057128c(*), 00571454(*),
//                                                                                                         00571714(*), 005717fc(*),
//                                                                                                         005718dc(*), 005719bc(*),
//                                                                                                         00571ae4(*), 00571bc4(*), [more]
//                              panel.h:253 (5)
//         004374a0     XOR        EAX,EAX
//         004374a2     RET        0x14
//         004374a5     ??         90h
//         004374a6     NOP
//         004374a7     NOP
//         004374a8     NOP
//         004374a9     NOP
//         004374aa     NOP
//         004374ab     NOP
//         004374ac     NOP
//         004374ad     NOP
//         004374ae     NOP
//         004374af     NOP
    return 0;
}

long TPanel::char_action(long param_1, short param_2) {
    /* TODO: Stub */
//                              long __thiscall char_action(TPanel * this, long param_1, short param
//              long              EAX:4          <RETURN>
//              TPanel *          ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              short             Stack[0x8]:2   param_2
//                               ?char_action@TPanel@@UAEJJF@Z                                XREF[67]:    0056f5b8(*), 0056f6c0(*),
//                               TPanel::char_action                                                       0056f800(*), 0056f948(*),
//                                                                                                         0056fa78(*), 0056fba8(*),
//                                                                                                         0056fce0(*), 0056fe10(*),
//                                                                                                         0056ff40(*), 00570070(*),
//                                                                                                         005701a0(*), 00570ce8(*),
//                                                                                                         00570dc8(*), 00571160(*),
//                                                                                                         00571290(*), 00571458(*),
//                                                                                                         00571718(*), 00571800(*),
//                                                                                                         005718e0(*), 005719c0(*), [more]
//                              panel.h:254 (5)
//         004374b0     XOR        EAX,EAX
//         004374b2     RET        0x8
//         004374b5     ??         90h
//         004374b6     NOP
//         004374b7     NOP
//         004374b8     NOP
//         004374b9     NOP
//         004374ba     NOP
//         004374bb     NOP
//         004374bc     NOP
//         004374bd     NOP
//         004374be     NOP
//         004374bf     NOP
    return 0;
}

void TPanel::take_snapshot() {
    /* TODO: Stub */
//                              void __thiscall take_snapshot(TPanel * this)
//              void              <VOID>         <RETURN>
//              TPanel *          ECX:4 (auto)   this
//                               ?take_snapshot@TPanel@@UAEXXZ                                XREF[73]:    0056f5e0(*), 0056f6e8(*),
//                               TPanel::take_snapshot                                                     0056f828(*), 0056f970(*),
//                                                                                                         0056faa0(*), 0056fbd0(*),
//                                                                                                         0056fd08(*), 0056fe38(*),
//                                                                                                         0056ff68(*), 00570098(*),
//                                                                                                         005701c8(*), 00570d10(*),
//                                                                                                         00570df0(*), 005710a0(*),
//                                                                                                         00571188(*), 005712b8(*),
//                                                                                                         00571398(*), 00571480(*),
//                                                                                                         00571560(*), 00571650(*), [more]
//                              panel.h:338 (1)
//         00437610     RET
//         00437611     ??         90h
//         00437612     NOP
//         00437613     NOP
//         00437614     NOP
//         00437615     NOP
//         00437616     NOP
//         00437617     NOP
//         00437618     NOP
//         00437619     NOP
//         0043761a     NOP
//         0043761b     NOP
//         0043761c     NOP
//         0043761d     NOP
//         0043761e     NOP
//         0043761f     NOP
    return;
}

