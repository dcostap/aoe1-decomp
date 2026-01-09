#pragma once
#include "common.h"

class TEasy_Panel : public TPanel {
public:
    long ideal_width;                        // 0xF4
    long ideal_height;                       // 0xF8
    char info_file_name[260];                // 0xFC
    long info_id;                            // 0x200
    TShape* background_pic;                  // 0x204
    TShape* background_pic2;                 // 0x208
    void* palette;                           // 0x20C
    char cursor_file[260];                   // 0x210
    long cursor_id;                          // 0x314
    int background_pos;                      // 0x318
    int use_bevels;                          // 0x31C
    uchar bevel_color1;                      // 0x320
    uchar bevel_color2;                      // 0x321
    uchar bevel_color3;                      // 0x322
    uchar bevel_color4;                      // 0x323
    uchar bevel_color5;                      // 0x324
    uchar bevel_color6;                      // 0x325
    ulong text_color1;                       // 0x328
    ulong text_color2;                       // 0x32C
    ulong focus_color1;                      // 0x330
    ulong focus_color2;                      // 0x334
    ulong state_color1;                      // 0x338
    ulong state_color2;                      // 0x33C
    char popup_info_file_name[260];          // 0x340
    long popup_info_id;                      // 0x444
    TShape* button_pics;                     // 0x448
    RGE_Color_Table* shadow_color_table;     // 0x44C
    long shadow_amount;                      // 0x450
    uchar background_color1;                 // 0x454
    uchar background_color2;                 // 0x455
    int enable_ime;                          // 0x458
    uchar help_mode;                         // 0x45C
    int stock_brush;                         // 0x460
    void* brush;                             // 0x464
    ulong brush_color;                       // 0x468
    TDrawArea* shadow_area;                  // 0x46C
    int allow_shadow_area;                   // 0x470
    int saved_mouse_mode;                    // 0x474

    virtual void draw_setup(int param_1);                   // vt0[10]+0x28=0x467560
    virtual void draw();                                    // vt0[12]+0x30=0x467570
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[28]+0x70=0x4679A0
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x46A4E0
    virtual void set_focus(int param_1);                    // vt0[48]+0xC0=0x469E10
    virtual void draw_background(int param_1);              // vt0[56]+0xE0=0x4675C0
    virtual void set_ideal_size(long param_1, long param_2); // vt0[57]+0xE4=0x467A50
    virtual int create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11); // vt0[58]+0xE8=0x468490
    virtual int create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11); // vt0[59]+0xEC=0x468530
    virtual int create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8); // vt0[60]+0xF0=0x468760
    virtual int create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8); // vt0[61]+0xF4=0x4689C0
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11); // vt0[62]+0xF8=0x468C20
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11); // vt0[63]+0xFC=0x468E50
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11); // vt0[64]+0x100=0x468CB0
    virtual int create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10); // vt0[65]+0x104=0x469000
    virtual int create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12); // vt0[66]+0x108=0x4691C0
    virtual int create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9); // vt0[67]+0x10C=0x469380
    virtual int create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7); // vt0[68]+0x110=0x4696B0
    virtual int create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8); // vt0[69]+0x114=0x469910
    virtual int create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3); // vt0[70]+0x118=0x469A80
    virtual int create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9); // vt0[71]+0x11C=0x469AD0
    virtual int create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9); // vt0[72]+0x120=0x469C40
    virtual void position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5); // vt0[73]+0x124=0x469DB0
    TEasy_Panel(char* param_1);
    long setup(TDrawArea* param_1, TPanel* param_2, char* param_3, long param_4, int param_5, long param_6, long param_7, long param_8, long param_9, int param_10);
    TEasy_Panel();
    void init_vars();
    ~TEasy_Panel();
    void prepare_for_close();
    void setup_shadow_area(int param_1);
    void set_info_file(char* param_1, long param_2);
    int set_background(char* param_1, long param_2);
    int set_background2(char* param_1, long param_2);
    void set_background_colors(uchar param_1, uchar param_2);
    int set_palette(char* param_1, long param_2);
    int set_cursor(char* param_1, long param_2);
    void set_use_bevels(int param_1);
    void set_background_pos(int param_1);
    void set_bevel_colors(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6);
    void set_text_colors(ulong param_1, ulong param_2);
    void set_focus_colors(ulong param_1, ulong param_2);
    void set_state_colors(ulong param_1, ulong param_2);
    void set_popup_info_file(char* param_1, long param_2);
    void set_button_pics(char* param_1, long param_2);
    void set_shadow_amount(long param_1);
    void set_enable_ime(int param_1);
    char* get_info_file();
    long get_info_id();
    TShape* get_background();
    TShape* get_background2();
    void* get_palette();
    char* get_cursor();
    int get_use_bevels();
    int get_background_pos();
    void get_bevel_colors(uchar* param_1, uchar* param_2, uchar* param_3, uchar* param_4, uchar* param_5, uchar* param_6);
    void get_text_colors(ulong* param_1, ulong* param_2);
    void get_focus_colors(ulong* param_1, ulong* param_2);
    long get_shadow_amount();
    void get_state_colors(ulong* param_1, ulong* param_2);
    char* get_popup_info_file();
    long get_popup_info_id();
    TShape* get_button_pics();
    RGE_Color_Table* get_shadow_color_table();
    int get_enable_ime();
    void popupOKDialog(long param_1, char* param_2, int param_3, int param_4);
    void popupOKDialog(char* param_1, char* param_2, int param_3, int param_4);
    void popupYesNoDialog(long param_1, char* param_2, int param_3, int param_4);
    void popupYesNoDialog(char* param_1, char* param_2, int param_3, int param_4);
    void popupYesNoCancelDialog(long param_1, char* param_2, int param_3, int param_4);
    void popupYesNoCancelDialog(char* param_1, char* param_2, int param_3, int param_4);
    void command_help(char* param_1, long param_2, long param_3, long param_4, long param_5);
    void command_help(char* param_1, char* param_2, long param_3, long param_4, long param_5);
    void setup_popup_help();
    void clear_popup_help();
    long command_do_popup_help(uchar param_1, long param_2, long param_3);
    void set_system_colors();
};

static_assert(sizeof(TEasy_Panel) == 0x478, "TEasy_Panel Size Mismatch");

