// VA: 0049F0D0 TRIBE_Screen_Main_Error ctor (335B)
// Scr_main.cpp lines 395-420
// EH-framed constructor
// Attempt log:
// - Rebuilt the same-TU screen surface: the base constructor and setup/
//   create_* calls use the period char*/direct-member ABI, and setup failure
//   sets the inherited +0xD8 error flag.
// - The close-button branch tests create_button's return value, as shown by
//   the original TEST EAX, rather than re-testing the output pointer.
// - The inherited field_D8 is modeled inside the F4-byte TPanel base; the
//   intervening base gap preserves the derived panel fields at +0x478.
// FLAGS: /GX (EH)

#include <windows.h>
#include "../../include/scr_main_context.h"

#if 0
class TTextPanel;
class TButtonPanel;

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
    char __gap5[0x3C];
    int setup_error;
    char __gap_DC[0x4];
    int display_changed_count;
    char __gap6[0x10];

    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect(RECT r);
    virtual void set_rect(long l, long t, long r, long b);
    virtual void set_color(unsigned char c);
    virtual void set_active(int a);
    virtual void set_positioning(int p1, int p2, int p3, int p4, int p5,
                                 int p6, int p7, int p8, int p9, int p10,
                                 int p11, int p12, int p13);
};

class TTextPanel : public TPanel {
};

class TButtonPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    char __gap7[0x384];
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(void* draw_area, char* name, long flag, long param);
    void set_ideal_size(long w, long h);
    int create_text(TPanel* parent, TTextPanel** output_panel, char* text,
                    long x, long y, long w, long h, long p8, long p9,
                    long p10, long p11);
    int create_button(TPanel* parent, TButtonPanel** output_panel,
                      long string_id, long x, long y, long w, long h,
                      long p8, long p9, long p10, long p11);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    void* draw_area;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    TTextPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;

    TRIBE_Screen_Main_Error();
    virtual ~TRIBE_Screen_Main_Error();
};
#endif

TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error()
    : TScreenPanel("Main Error Screen") {
    this->message = 0;
    this->cancel_button = 0;

    if (this->setup(rge_base_game->draw_area, "scr1", 0xC383, 0) == 0) {
        this->setup_error = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1E0);

    this->create_text((TPanel*)this, &this->message, "", 0x28, 0x28,
                      0x230, 0x190, 4, 1, 1, 1);
    this->create_button((TPanel*)this, &this->cancel_button, 0xFA1, 0,
                        0xC8, 0x1B8, 0xF0, 0x1E, 0, 0, 0);

    if (this->create_button((TPanel*)this, &this->close_button, 0x3EA, 0,
                            0, 0, 0, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0) != 0) {
        this->close_button->set_active(1);
        this->close_button->set_positioning(9, 4, 4, 4, 4, 0x11, 0x11,
                                            0x11, 0x11, 0, 0, 0, 0);
    }
}
