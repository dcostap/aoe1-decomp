#pragma once
#include "common.h"

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

class TTextPanel : public TPanel {
public:
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

    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt0[3]+0xC=0x47C3B0
    virtual void set_active(int param_1);                   // vt0[5]+0x14=0x47CE20
    virtual void draw();                                    // vt0[12]+0x30=0x47D2C0
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[33]+0x84=0x47DC10
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[43]+0xAC=0x47D120
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x47D200
    virtual void set_text(char** param_1, short param_2);   // vt0[56]+0xE0=0x47CAB0
    virtual void set_text(long param_1);                    // vt0[57]+0xE4=0x47CA70
    virtual void set_text(char* param_1);                   // vt0[58]+0xE8=0x47C560
    virtual void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7); // vt0[59]+0xEC=0x47CD40
    TTextPanel();
    ~TTextPanel();
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
    char* get_text();
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
    void free_text();
    void empty_list();
    void free_text();
    void set_second_column_pos(long param_1);
    int get_text_rect(tagRECT* param_1);
};

static_assert(sizeof(TTextPanel) == 0x188, "TTextPanel Size Mismatch");

