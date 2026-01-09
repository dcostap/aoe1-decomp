#pragma once
#include "common.h"

enum ActionType : unsigned int {
    ActionItem = 0,
    ActionList = 1,
    ActionValue = 2,
};

typedef  enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    Bevel1 = 2,
    Bevel2 = 3,
    Bevel3 = 4,
};

enum DrawStyle : unsigned int {
    DrawStyleNormal = 0,
    DrawStyleLeftButton = 1,
};

enum DropdownMode : unsigned int {
    ModeNone = 0,
    ModeValue = 1,
    ModeList = 2,
};

class TDropDownButtonPanel : public TButtonPanel {
public:
    TDropDownPanel* drop_down_panel;         // 0x2B8

    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4); // vt0[29]+0x74=0x4754C0
    TDropDownButtonPanel(TDropDownPanel* param_1);
    ~TDropDownButtonPanel();
};

static_assert(sizeof(TDropDownButtonPanel) == 0x2BC, "TDropDownButtonPanel Size Mismatch");

class TDropDownPanel : public TPanel {
public:
    TTextPanel* val_panel;                   // 0xF4
    TButtonPanel* btn_panel;                 // 0xF8
    TListPanel* list_panel;                  // 0xFC
    TScrollBarPanel* scbar_panel;            // 0x100
    DropdownMode mode;                       // 0x104
    short val_num;                           // 0x108
    long val_wid;                            // 0x10C
    long val_hgt;                            // 0x110
    long btn_wid;                            // 0x114
    long btn_hgt;                            // 0x118
    long list_wid;                           // 0x11C
    long list_hgt;                           // 0x120
    long scbar_wid;                          // 0x124
    long scbar_arrow_hgt;                    // 0x128
    long scbar_tab_hgt;                      // 0x12C
    uchar list_is_above;                     // 0x130
    long font_hgt;                           // 0x134
    int outline_color;                       // 0x138
    DrawStyle draw_style;                    // 0x13C
    int draw_val_rect;                       // 0x140

    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt0[3]+0xC=0x474550
    virtual void draw();                                    // vt0[12]+0x30=0x474340
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[22]+0x58=0x474450
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[28]+0x70=0x474350
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4); // vt0[29]+0x74=0x474400
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[30]+0x78=0x474420
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x4744A0
    virtual void set_tab_order(TPanel* param_1, TPanel* param_2); // vt0[49]+0xC4=0x4751E0
    TDropDownPanel();
    ~TDropDownPanel();
    long setup(TDrawArea* param_1, TPanel* param_2, void* param_3, long param_4, long param_5, int param_6, uchar param_7, int param_8, uchar param_9, long param_10, long param_11, long param_12, long param_13, short param_14, short param_15, long param_16, long param_17, char* param_18, long param_19, long param_20, char** param_21, short param_22, long param_23, char* param_24, char* param_25, char* param_26, char* param_27, long param_28, long param_29);
    void set_val_text_color(ulong param_1, ulong param_2);
    void set_draw_style(DrawStyle param_1);
    void set_draw_val_rect(int param_1);
    void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    void set_buttons(TShape* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    void set_mode(DropdownMode param_1);
    int numberLines();
    int currentLineNumber();
    void setCurrentLineNumber(int param_1);
    void setCurrentLineId(int param_1);
    char* currentLine();
    void set_sorted(int param_1);
    int get_sorted();
    void set_line(long param_1);
    int append_line(char* param_1, long param_2);
    int append_line(long param_1, long param_2);
    int insert_line(long param_1, char* param_2, long param_3);
    int insert_line(long param_1, long param_2, long param_3);
    int delete_line(long param_1);
    long get_line();
    long get_line(long param_1);
    long get_line(char* param_1);
    char* get_text();
    char* get_text(long param_1);
    long get_id();
    long get_id(long param_1);
    void empty_list();
};

static_assert(sizeof(TDropDownPanel) == 0x144, "TDropDownPanel Size Mismatch");

