#ifndef AOE1_PNL_EDIT_H
#define AOE1_PNL_EDIT_H

// PDB source: C:\\msdev\\work\\age1_x1\\pnl_edit.cpp.
// This header owns TEditPanel.
#include "panel.h"
#include "drawarea.h"
#include "basegame.h"

class TEditPanel : public TPanel {
public:
    enum FormatType {
        FormatText = 0, FormatNumber = 1, FormatInteger = 2,
        FormatUnsignedInt = 3, FormatFile = 4, FormatFileNoExt = 5,
        FormatPath = 6, FormatMultiLine = 7, FormatPercent = 8
    };
    TEditPanel();
    virtual ~TEditPanel();
    HWND edit_wnd;
    short fixed_len;
    unsigned char pad_FA[2];
    char* text;
    int text_len;
    int hidden;
    HBRUSH brush;
    int stock_brush;
    WNDPROC old_sub_wnd_proc;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlight_text_color1;
    unsigned long highlight_text_color2;
    unsigned long back_color;
    FormatType format;
    HGDIOBJ font;
    int multi_line;
    tagRECT draw_rect;
    unsigned int draw_format;
    int auto_sel;
    int sel_len;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char pad_15A[2];
    int bevel_size;
    unsigned long imc;
    int enable_ime;
    int turn_ime_on;
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, short,
               char*, FormatType, int);
    long sub_wnd_proc(void*, unsigned int, unsigned int, long);
    void set_text(char*);
    void update_text();
    char* get_text();
    char* get_input_buffer();
    char* currentLine();
    virtual void set_active(int);
    virtual void set_focus(int);
    int verify_char(int);
    virtual void draw();
    virtual void paint();
    int is_blank();
    char* get_trimmed_str(char*, int);
    virtual void handle_reactivate();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual void set_rect(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    void set_text_color(unsigned long, unsigned long);
    void set_highlight_text_color(unsigned long, unsigned long);
    void set_back_color(void*, unsigned long, unsigned char);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_ime_info(int, int);
};

typedef char pnl_edit_teditpanel_size_check[
    (sizeof(TEditPanel) == 0x16C) ? 1 : -1];

#endif
