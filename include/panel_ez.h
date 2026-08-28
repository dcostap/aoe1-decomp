#ifndef AOE1_PANEL_EZ_H
#define AOE1_PANEL_EZ_H

// PDB source: C:\\msdev\\work\\age1_x1\\Panel_ez.cpp.
// This header owns TEasy_Panel. Foreign types stay in their own headers.
#include "panel.h"

typedef unsigned char uchar;

class TDrawArea;
class RGE_Color_Table;
class TShape;
class TButtonPanel;
class TTextPanel;
class TInputPanel;
class TEditPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class THelpDialog;
class TMessageDialog;

class TEasy_Panel : public TPanel {
public:
    TEasy_Panel(char* name);
    TEasy_Panel();
    virtual ~TEasy_Panel();

    long ideal_width;
    long ideal_height;
    char info_file_name[260];
    long info_id;
    TShape* background_pic;
    TShape* background_pic2;
    void* palette;
    char cursor_file[260];
    long cursor_id;
    int background_pos;
    int use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char pad_326[2];
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    unsigned long state_color1;
    unsigned long state_color2;
    char popup_info_file_name[260];
    long popup_info_id;
    TShape* button_pics;
    RGE_Color_Table* shadow_color_table;
    long shadow_amount;
    unsigned char background_color1;
    unsigned char background_color2;
    unsigned char pad_456[2];
    int enable_ime;
    unsigned char help_mode;
    unsigned char pad_45D[3];
    int stock_brush;
    void* brush;
    unsigned long brush_color;
    TDrawArea* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;

    virtual void draw_setup(int);
    virtual void draw();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_focus(int);
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);

    long setup(TDrawArea*, TPanel*, char*, long, int, long, long, long, long,
               int);

protected:
    // PDB virtual order: long button, character button, integer text,
    // text array, then character text.
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long,
                              long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long,
                              long, long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long,
                                 long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long,
                                    long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long,
                            long, long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long,
                            long, long, long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long,
                            long, long, int, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, int, long,
                             long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, int, long,
                            long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long,
                                 long, long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long,
                            long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long,
                                 long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long,
                                   long, long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);

    void init_vars();
    void command_help(char*, long, long, long, long);
    void command_help(char*, char*, long, long, long);

public:
    void prepare_for_close();
    void setup_shadow_area(int);
    void set_info_file(char*, long);
    int set_background(char*, long);
    int set_background2(char*, long);
    void set_background_colors(unsigned char, unsigned char);
    int set_palette(char*, long);
    int set_cursor(char*, long);
    void set_use_bevels(int);
    void set_background_pos(int);
    void set_bevel_colors(unsigned char, unsigned char, unsigned char,
                          unsigned char, unsigned char, unsigned char);
    void set_text_colors(unsigned long, unsigned long);
    void set_focus_colors(unsigned long, unsigned long);
    void set_state_colors(unsigned long, unsigned long);
    void set_popup_info_file(char*, long);
    void set_button_pics(char*, long);
    void set_shadow_amount(long);
    void set_enable_ime(int);
    char* get_info_file();
    long get_info_id();
    TShape* get_background();
    TShape* get_background2();
    void* get_palette();
    char* get_cursor();
    int get_use_bevels();
    int get_background_pos();
    void get_bevel_colors(unsigned char&, unsigned char&, unsigned char&,
                          unsigned char&, unsigned char&, unsigned char&);
    void get_text_colors(unsigned long&, unsigned long&);
    void get_focus_colors(unsigned long&, unsigned long&);
    long get_shadow_amount();
    void get_state_colors(unsigned long&, unsigned long&);
    char* get_popup_info_file();
    long get_popup_info_id();
    TShape* get_button_pics();
    RGE_Color_Table* get_shadow_color_table();
    int get_enable_ime();
    void popupOKDialog(long, char*, int, int);
    void popupOKDialog(char*, char*, int, int);
    void popupYesNoDialog(long, char*, int, int);
    void popupYesNoDialog(char*, char*, int, int);
    void popupYesNoCancelDialog(long, char*, int, int);
    void popupYesNoCancelDialog(char*, char*, int, int);
    void setup_popup_help();
    void clear_popup_help();
    long command_do_popup_help(unsigned char, long, long);
    void set_system_colors();
};

typedef char panel_ez_teasy_size_check[
    (sizeof(TEasy_Panel) == 0x478) ? 1 : -1];

#endif
