// VA: 0049F0D0 TRIBE_Screen_Main_Error ctor (335B)
// Scr_main.cpp lines 395-420
// EH-framed constructor
// FLAGS: /GX (EH)

#include <windows.h>

class TPanel {
public:
    char __gap[0x1C];
    void* render_area;
    char __gap2[0x1C];
    void* parent_panel;
    char __gap3[0x28];
    int active;
    int visible;
    char __gap4[0x14];
    void* clip_rgn;
    RECT render_rect;
    char __gap5[0x44];
    int display_changed_count;
    char __gap6[0x10];

    virtual ~TPanel();
    virtual long setup(long draw_area, const char* name, long flag, int param);
    virtual void set_rect(RECT r);
    virtual void set_rect(long l, long t, long r, long b);
    virtual void set_color(unsigned char c);
    virtual void set_active(int a);
    virtual void set_positioning(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, int p13);
};

class TEasy_Panel : public TPanel {
public:
    char __gap7[0x384];
    virtual ~TEasy_Panel();
    void set_ideal_size(long w, long h);
    int create_text(TPanel* parent, TPanel** output_panel, const char* text, int x, int y, int w, int h, int p8, int p9, int p10, int p11);
    int create_button(TPanel* parent, TPanel** output_panel, long string_id, int x, int y, int w, int h, int p8, int p9, int p10, int p11);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(const char* name);
    virtual ~TScreenPanel();
    long setup(long draw_area, const char* name, long flag, int param);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    long draw_area;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    TPanel* message;
    TPanel* cancel_button;
    TPanel* close_button;

    TRIBE_Screen_Main_Error();
    virtual ~TRIBE_Screen_Main_Error();
};

TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error() : TScreenPanel("Main Error Screen") {
    this->message = (TPanel*)0x0;
    this->cancel_button = (TPanel*)0x0;

    long setup_result = TEasy_Panel::setup((long)rge_base_game->draw_area, "scr1", 0xC383, 0);
    if (setup_result == 0) {
        return;
    }

    set_ideal_size(0x280, 0x1E0);

    create_text((TPanel*)this, &this->message, "", 0x28, 0x28, 0x230, 0x190, 4, 1, 1, 1);
    create_button((TPanel*)this, &this->cancel_button, 0xFA1, 0, 0xC8, 0x1B8, 0xF0, 0x1E, 0, 0, 0);
    create_button((TPanel*)this, &this->close_button, 0x3EA, 0, 0, 0, 0, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0);

    if (this->close_button != 0) {
        this->close_button->set_active(1);
        this->close_button->set_positioning(9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, 0, 0, 0, 0);
    }

    return;
}
