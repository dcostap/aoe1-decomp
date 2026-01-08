#pragma once
#include "../common.h"

enum Action : unsigned int {
    ActionSelect = 1,
};

enum Alignment : unsigned int {
    AlignCenter = 0,
    AlignLeft = 1,
    AlignRight = 2,
    AlignTop = 3,
    AlignBottom = 4,
    AlignHorizontalScroll = 5,
    AlignWordwrap = 6,
};

enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    BevelIn1 = 2,
    BevelIn2 = 3,
    BevelIn3 = 4,
    BevelOut1 = 5,
    BevelOut2 = 6,
    BevelOut3 = 7,
};

enum CharType : unsigned int {
    SingleByteChar = 0,
    SingleByteKanaChar = 1,
    DoubleByteChar = 2,
};

enum ScrollAction : unsigned int {
    ScrollCount = 0,
    ScrollLine = 1,
    ScrollDown = 2,
    ScrollUp = 3,
    ScrollNext = 4,
    ScrollPrior = 5,
    ScrollHome = 6,
    ScrollEnd = 7,
};

enum Style : unsigned int {
    NormalStyle = 0,
    BeveledStyle = 1,
    ChiseledStyle = 2,
};

// ----------------------------------------------------------------
// TextNode
// Size: 0x10
struct TextNode {
    char * text; // 0x0
    char * text2; // 0x4
    long id; // 0x8
    TextNode * next_node; // 0xC
};

class TTextPanel : public TPanel       {
public:
    char _pad_0x4[0xF0];
    TextNode* list;                          // 0xF4
    short num_lines;                         // 0xF8
    short draw_lines;                        // 0xFA
    short top_line;                          // 0xFC
    short bot_line;                          // 0xFE
    short cur_line;                          // 0x100
    short cur_col;                           // 0x102
    void* font;                              // 0x104
    long font_wid;                           // 0x108
    long font_hgt;                           // 0x10C
    Alignment vert_align;                    // 0x110
    Alignment horz_align;                    // 0x114
    int word_wrap;                           // 0x118
    Style text_style;                        // 0x11C
    ulong text_color1;                       // 0x120
    ulong text_color2;                       // 0x124
    ulong highlightTextColor1;               // 0x128
    ulong highlightTextColor2;               // 0x12C
    TScrollBarPanel* scbar_panel;            // 0x130
    int auto_scbar;                          // 0x134
    short fixed_len;                         // 0x138
    long text_wid;                           // 0x13C
    long text_hgt;                           // 0x140
    TShape* back_pic;                        // 0x144
    short back_pic_wid;                      // 0x148
    short back_pic_hgt;                      // 0x14A
    int fill_back;                           // 0x14C
    uchar back_color;                        // 0x150
    int outline;                             // 0x154
    uchar outline_color;                     // 0x158
    int sorted;                              // 0x15C
    long second_column_pos;                  // 0x160
    long full_width;                         // 0x164
    long scbar_width;                        // 0x168
    int scbar_active;                        // 0x16C
    int bevel_type;                          // 0x170
    uchar bevel_color1;                      // 0x174
    uchar bevel_color2;                      // 0x175
    uchar bevel_color3;                      // 0x176
    uchar bevel_color4;                      // 0x177
    uchar bevel_color5;                      // 0x178
    uchar bevel_color6;                      // 0x179
    void* clip_rgn2;                         // 0x17C
    int border_size;                         // 0x180
    int spacer_size;                         // 0x184

    TTextPanel();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TTextPanel() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 03] Offset 0x0C (Override)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // Ghidra: set_rect

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 05] Offset 0x14 (Override)
    virtual void set_active(int param_1); // Ghidra: set_active

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 12] Offset 0x30 (Override)
    virtual void draw(); // Ghidra: draw

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 33] Offset 0x84 (Override)
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // Ghidra: mouse_left_down_action

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 43] Offset 0xAC (Override)
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // Ghidra: key_down_action

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 45] Offset 0xB4 (Override)
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // Ghidra: action

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 56] Offset 0xE0 (Override)
    virtual void set_text(char** param_1, short param_2); // Ghidra: set_text

    // [Slot 57] Offset 0xE4 (Override)
    virtual void set_text(long param_1); // Ghidra: set_text

    // [Slot 58] Offset 0xE8 (Override)
    virtual void set_text(char* param_1); // Ghidra: set_text

    // [Slot 59] Offset 0xEC (Override)
    virtual void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7); // Ghidra: set_bevel_info

    // --- Non-Virtual Members ---
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, long param_8, long param_9, char* param_10, int param_11, uchar param_12, int param_13, uchar param_14, short param_15, char* param_16);
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, long param_8, long param_9, char* param_10, int param_11, uchar param_12, int param_13, uchar param_14, short param_15, long param_16);
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, long param_8, long param_9, char* param_10, int param_11, uchar param_12, int param_13, uchar param_14, short param_15, char** param_16, short param_17);
    void set_scrollbar(TScrollBarPanel* param_1, int param_2);
    CharType char_type(uchar* param_1);
    int word_wrap_append(char* param_1);
    void set_font(void* param_1, long param_2, long param_3);
    void set_alignment(Alignment param_1, Alignment param_2);
    void set_word_wrap(int param_1);
    void set_style(Style param_1);
    void set_text_color(ulong param_1, ulong param_2);
    void set_highlight_text_color(ulong param_1, ulong param_2);
    void set_fill_back(int param_1, uchar param_2);
    void set_back_pic(char* param_1);
    void set_outline(int param_1, uchar param_2);
    void set_spacer_size(int param_1);
    void calc_draw_info(int param_1);
    void scroll(uchar param_1, short param_2, int param_3);
    void draw_background();
    void draw_border();
    void draw_line(void* param_1, short param_2, short param_3, ulong param_4, ulong param_5);
    void calc_line_pos(void* param_1, short param_2, short param_3, tagRECT* param_4, long* param_5);
    int numberLines();
    int numberDrawLines();
    int currentLineNumber();
    void setCurrentLineNumber(int param_1);
    char* currentLine();
    void set_line(long param_1);
    void set_line_by_id(long param_1);
    int append_line(char* param_1, long param_2);
    int append_line(char* param_1, char* param_2, long param_3);
    int append_line(long param_1, long param_2);
    int append_line(long param_1, long param_2, long param_3);
    int insert_line(long param_1, char* param_2, long param_3);
    int insert_line(long param_1, char* param_2, char* param_3, long param_4);
    int insert_line(long param_1, long param_2, long param_3);
    int insert_line(long param_1, long param_2, long param_3, long param_4);
    int change_line(long param_1, char* param_2, char* param_3, long param_4);
    int change_line(long param_1, long param_2, long param_3, long param_4);
    int delete_line(long param_1);
    long get_line();
    long get_line(long param_1);
    long get_line(char* param_1);
    char* get_text();
    char* get_text(long param_1);
    char* get_text2();
    char* get_text2(long param_1);
    long get_id();
    long get_id(long param_1);
    void empty_list();
    void free_text();
    void set_second_column_pos(long param_1);
    int get_text_rect(tagRECT* param_1);
};

static_assert(sizeof(TTextPanel) == 0x188, "TTextPanel Size Mismatch");
static_assert(offsetof(TTextPanel, spacer_size) == 0x184, "TTextPanel Offset Mismatch");

