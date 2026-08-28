#ifndef AOE1_PNL_DROP_H
#define AOE1_PNL_DROP_H

// PDB source: C:\\msdev\\work\\age1_x1\\Pnl_drop.cpp.
// This header owns TDropDownPanel and TDropDownButtonPanel.
#include "panel.h"
#include "drawarea.h"
#include "Shape.h"
#include "pnl_btn.h"
#include "pnl_lst.h"

class TScrollBarPanel;

class TDropDownPanel : public TPanel {
public:
    enum DrawStyle { DrawStyleDefault = 0, DrawStyleLeftButton = 1 };
    enum DropdownMode { ModeNone = 0, ModeValue = 1, ModeList = 2 };

    TTextPanel* val_panel;
    TButtonPanel* btn_panel;
    TListPanel* list_panel;
    TScrollBarPanel* scbar_panel;
    int mode;
    short val_num;
    unsigned char val_num_padding[2];
    long val_wid;
    long val_hgt;
    long btn_wid;
    long btn_hgt;
    long list_wid;
    long list_hgt;
    long scbar_wid;
    long scbar_arrow_hgt;
    long scbar_tab_hgt;
    unsigned char list_is_above;
    unsigned char list_is_above_padding[3];
    long font_hgt;
    int outline_color;
    int draw_style;
    int draw_val_rect;

    TDropDownPanel();
    virtual ~TDropDownPanel();
    virtual void draw();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_key_down(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_rect(long, long, long, long);
    virtual long handle_mouse_move(long, long, int, int);
    long setup(TDrawArea*, TPanel*, void*, long, long, int, unsigned char, int,
               unsigned char, long, long, long, long, short, short, long, long,
               char*, long, long, char**, short, long, char*, char*, char*,
               char*, long, long);
    void set_val_text_color(unsigned long, unsigned long);
    void set_draw_style(DrawStyle);
    void set_draw_val_rect(int);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_buttons(TShape*, int, int, int, int, int);
    void set_mode(DropdownMode);
    int numberLines();
    int currentLineNumber();
    void setCurrentLineNumber(int);
    void setCurrentLineId(int);
    char* currentLine();
    void set_tab_order(TPanel*, TPanel*);
    void set_sorted(int);
    int get_sorted();
    void set_line(long);
    int append_line(char*, long);
    int append_line(long, long);
    int insert_line(long, char*, long);
    int insert_line(long, long, long);
    int delete_line(long);
    long get_line();
    long get_line(long);
    long get_line(char*);
    char* get_text();
    char* get_text(long);
    long get_id();
    long get_id(long);
    void empty_list();
};

typedef char pnl_drop_tdropdownpanel_size_check[
    (sizeof(TDropDownPanel) == 0x144) ? 1 : -1];

class TDropDownButtonPanel : public TButtonPanel {
public:
    TDropDownPanel* drop_down_panel;
    TDropDownButtonPanel(TDropDownPanel*);
    virtual long handle_mouse_move(long, long, int, int);
};

typedef char pnl_drop_tdropdownbuttonpanel_size_check[
    (sizeof(TDropDownButtonPanel) == 0x2BC) ? 1 : -1];

#endif
