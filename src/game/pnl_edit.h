#pragma once
#include "../common.h"

typedef enum ActionType : unsigned int {
    ActionEnter = 0,
    ActionEscape = 1,
    ActionTab = 2,
};

typedef enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    BevelIn1 = 2,
    BevelIn2 = 3,
    BevelIn3 = 4,
    BevelOut1 = 5,
    BevelOut2 = 6,
    BevelOut3 = 7,
};

typedef enum FormatType : unsigned int {
    FormatText = 0,
    FormatNumber = 1,
    FormatInteger = 2,
    FormatUnsignedInt = 3,
    FormatFile = 4,
    FormatFileNoExt = 5,
    FormatPath = 6,
    FormatMultiLine = 7,
    FormatPercent = 8,
};

class TEditPanel : public TPanel {
public:
    void* edit_wnd;                          // 0xF4
    short fixed_len;                         // 0xF8
    char* text;                              // 0xFC
    int text_len;                            // 0x100
    int hidden;                              // 0x104
    void* brush;                             // 0x108
    int stock_brush;                         // 0x10C
    void* old_sub_wnd_proc;                  // 0x110
    ulong text_color1;                       // 0x114
    ulong text_color2;                       // 0x118
    ulong highlight_text_color1;             // 0x11C
    ulong highlight_text_color2;             // 0x120
    ulong back_color;                        // 0x124
    FormatType format;                       // 0x128
    void* font;                              // 0x12C
    int multi_line;                          // 0x130
    tagRECT draw_rect;                       // 0x134
    uint draw_format;                        // 0x144
    int auto_sel;                            // 0x148
    int sel_len;                             // 0x14C
    int bevel_type;                          // 0x150
    uchar bevel_color1;                      // 0x154
    uchar bevel_color2;                      // 0x155
    uchar bevel_color3;                      // 0x156
    uchar bevel_color4;                      // 0x157
    uchar bevel_color5;                      // 0x158
    uchar bevel_color6;                      // 0x159
    int bevel_size;                          // 0x15C
    ulong imc;                               // 0x160
    int enable_ime;                          // 0x164
    int turn_ime_on;                         // 0x168

    TEditPanel();
    virtual ~TEditPanel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, short param_8, char* param_9, FormatType param_10, int param_11);
    virtual void set_text(char* param_1);
    virtual void update_text();
    virtual char* get_text();
    virtual char* get_input_buffer();
    virtual char* currentLine();
    virtual void set_active(int param_1);
    virtual void set_focus(int param_1);
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void set_redraw(RedrawMode param_1);
    virtual void set_text_color(ulong param_1, ulong param_2);
    virtual void set_highlight_text_color(ulong param_1, ulong param_2);
    virtual void set_back_color(void* param_1, ulong param_2, uchar param_3);
    virtual void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    virtual void set_ime_info(int param_1, int param_2);
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    virtual long sub_wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    virtual int verify_char(int param_1);
    virtual void draw();
    virtual void paint();
    virtual int is_blank();
    virtual char* get_trimmed_str(char* param_1, int param_2);
    virtual void handle_reactivate();
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
};

static_assert(sizeof(TEditPanel) == 0x16C, "TEditPanel Size Mismatch");
static_assert(offsetof(TEditPanel, turn_ime_on) == 0x168, "TEditPanel Offset Mismatch");

