#pragma once
#include "../common.h"
#include "diam_map.h"
#include "dlg_abt.h"
#include "dlg_conf.h"
#include "dlg_dip.h"
#include "dlg_help.h"
#include "dlg_list.h"
#include "dlg_menu.h"
#include "Dlg_msg.h"
#include "dlg_sedm.h"
#include "dlg_smsg.h"
#include "Mouseptr.h"
#include "Panel.h"
#include "Pnl_btn.h"
#include "pnl_dlg.h"
#include "Pnl_drop.h"
#include "pnl_edit.h"
#include "Pnl_inp.h"
#include "Pnl_lst.h"
#include "Pnl_msg.h"
#include "Pnl_pic.h"
#include "Pnl_scbr.h"
#include "Pnl_scr.h"
#include "pnl_sld.h"
#include "Pnl_txt.h"
#include "rpnl_tbx.h"
#include "rpnl_tim.h"
#include "tpnl_btn.h"
#include "tpnl_inv.h"
#include "tpnl_obj.h"
#include "tpnl_pop.h"
#include "tpnl_tim.h"
#include "tpnl_tml.h"
#include "tpnl_txl.h"

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

    TEasy_Panel(char* param_1);
    virtual long setup(TDrawArea* param_1, TPanel* param_2, char* param_3, long param_4, int param_5, long param_6, long param_7, long param_8, long param_9, int param_10);
    TEasy_Panel();
    virtual void init_vars();
    virtual ~TEasy_Panel();
    virtual void prepare_for_close();
    virtual void setup_shadow_area(int param_1);
    virtual void draw_setup(int param_1);
    virtual void draw();
    virtual void draw_background(int param_1);
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual void set_info_file(char* param_1, long param_2);
    virtual void set_ideal_size(long param_1, long param_2);
    virtual int set_background(char* param_1, long param_2);
    virtual int set_background2(char* param_1, long param_2);
    virtual void set_background_colors(uchar param_1, uchar param_2);
    virtual int set_palette(char* param_1, long param_2);
    virtual int set_cursor(char* param_1, long param_2);
    virtual void set_use_bevels(int param_1);
    virtual void set_background_pos(int param_1);
    virtual void set_bevel_colors(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6);
    virtual void set_text_colors(ulong param_1, ulong param_2);
    virtual void set_focus_colors(ulong param_1, ulong param_2);
    virtual void set_state_colors(ulong param_1, ulong param_2);
    virtual void set_popup_info_file(char* param_1, long param_2);
    virtual void set_button_pics(char* param_1, long param_2);
    virtual void set_shadow_amount(long param_1);
    virtual void set_enable_ime(int param_1);
    virtual char* get_info_file();
    virtual long get_info_id();
    virtual TShape* get_background();
    virtual TShape* get_background2();
    virtual void* get_palette();
    virtual char* get_cursor();
    virtual int get_use_bevels();
    virtual int get_background_pos();
    virtual void get_bevel_colors(uchar* param_1, uchar* param_2, uchar* param_3, uchar* param_4, uchar* param_5, uchar* param_6);
    virtual void get_text_colors(ulong* param_1, ulong* param_2);
    virtual void get_focus_colors(ulong* param_1, ulong* param_2);
    virtual long get_shadow_amount();
    virtual void get_state_colors(ulong* param_1, ulong* param_2);
    virtual char* get_popup_info_file();
    virtual long get_popup_info_id();
    virtual TShape* get_button_pics();
    virtual RGE_Color_Table* get_shadow_color_table();
    virtual int get_enable_ime();
    virtual int create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11);
    virtual int create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11);
    virtual int create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8);
    virtual int create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8);
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11);
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11);
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11);
    virtual int create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10);
    virtual int create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12);
    virtual int create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9);
    virtual int create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7);
    virtual int create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8);
    virtual int create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3);
    virtual int create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9);
    virtual int create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9);
    virtual void position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5);
    virtual void set_focus(int param_1);
    virtual void popupOKDialog(long param_1, char* param_2, int param_3, int param_4);
    virtual void popupOKDialog(char* param_1, char* param_2, int param_3, int param_4);
    virtual void popupYesNoDialog(long param_1, char* param_2, int param_3, int param_4);
    virtual void popupYesNoDialog(char* param_1, char* param_2, int param_3, int param_4);
    virtual void popupYesNoCancelDialog(long param_1, char* param_2, int param_3, int param_4);
    virtual void popupYesNoCancelDialog(char* param_1, char* param_2, int param_3, int param_4);
    virtual void command_help(char* param_1, long param_2, long param_3, long param_4, long param_5);
    virtual void command_help(char* param_1, char* param_2, long param_3, long param_4, long param_5);
    virtual void setup_popup_help();
    virtual void clear_popup_help();
    virtual long command_do_popup_help(uchar param_1, long param_2, long param_3);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void set_system_colors();
};

static_assert(sizeof(TEasy_Panel) == 0x478, "TEasy_Panel Size Mismatch");
static_assert(offsetof(TEasy_Panel, saved_mouse_mode) == 0x474, "TEasy_Panel Offset Mismatch");

