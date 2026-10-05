#ifndef AOE1_SCR_CRED_H
#define AOE1_SCR_CRED_H

// This header owns only the classes defined by this module.
#include "Pnl_scr.h"
#include "pnl_lst.h"

class TRIBE_Screen_Main_Menu;

class TScrollTextPanel : public TTextPanel {
  public:
    int scroll;
    unsigned long last_time;
    int speed;
    int done;

    virtual ~TScrollTextPanel();
    virtual void set_text(char* text_in);
    virtual long handle_idle();
    virtual void draw();

    TScrollTextPanel(
        TPanel* parent_in, TDrawArea* render_area_in, long x, long y, long wid, long hgt, int speed_in, void* font_in,
        long font_wid_in, long font_hgt_in, char* text_in
    );
    void draw_scrolled_line(void* dc, short draw_row, short text_line, unsigned long color1, unsigned long color2);
};

typedef char scr_cred_scroll_text_panel_size_check[(sizeof(TScrollTextPanel) == 0x198) ? 1 : -1];

class TRIBE_Credits_Screen : public TScreenPanel {
  public:
    TScrollTextPanel* text_panel;
    int text_set;
    int picture_set;
    unsigned long last_picture_time;
    unsigned long last_pause_time;
    int mode;
    tagPALETTEENTRY color_table[256];
    tagPALETTEENTRY color;
    TShape* back_pics[7];
    int first_draw;
    int text_done;

    TRIBE_Credits_Screen();
    virtual ~TRIBE_Credits_Screen();
    virtual long handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key);
    virtual long handle_idle();
    virtual void draw();
    virtual long key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key);
    virtual long action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2);
    void close_screen();
};

typedef char scr_cred_screen_size_check[(sizeof(TRIBE_Credits_Screen) == 0x8B8) ? 1 : -1];

#endif
