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
    virtual void set_text(char*);
    virtual long handle_idle();
    virtual void draw();

    TScrollTextPanel(TPanel*, TDrawArea*, long, long, long, long, int,
                     void*, long, long, char*);
    void draw_scrolled_line(void*, short, short, unsigned long,
                            unsigned long);
};

typedef char scr_cred_scroll_text_panel_size_check[
    (sizeof(TScrollTextPanel) == 0x198) ? 1 : -1];

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
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_idle();
    virtual void draw();
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void close_screen();
};

typedef char scr_cred_screen_size_check[
    (sizeof(TRIBE_Credits_Screen) == 0x8B8) ? 1 : -1];

#endif
