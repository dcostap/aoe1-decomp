// Attempt log for 004A63D0 TRIBE_Screen_Name::TRIBE_Screen_Name
// Prior scaffold attempts (preserved): natural constructor was 640B/737B;
// /GX and /Oy- did not recover the missing base/type/call surface.  The
// current reconstruction restores the period TPanel -> TEasy_Panel ->
// TScreenPanel ownership, the direct TEasy_Panel setup overload, the exact
// typed child-panel fields, and the binary-proven close-button virtual call.
//
// baseline: canonical screen-panel hierarchy and scr_name.cpp constructor
// call order; /GX is required by the original fs:[0] EH registration.
// probe 2: carried cancel_button in a natural local across its two hotkey
// stores; this preserved the oracle's one load, contiguous stores, and exact
// close-button setup schedule.  Result: 737B exact match.
// FLAGS: config/flags/004A63D0_TRIBE_Screen_Name.rsp (/GX)

#include <windows.h>

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect(RECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);

    char gap_04[0xD4];
    int setup_error;                         // +0xD8
    char gap_DC[0x18];

    void set_help_info(long help_id, long page_id);
};

class TTextPanel : public TPanel {
};

class TListPanel : public TTextPanel {
};

class TScrollBarPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;                             // +0x298
    long hotkey_shift;                       // +0x29C
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];                      // sizeof(TEasy_Panel) == 0x478

    long setup(TDrawArea* draw_area, TPanel* parent, char* info_file,
               long info_id, int p5, long p6, long p7, long p8,
               long p9, int p10);
    void setup_shadow_area(int force_rebuild);
    void set_ideal_size(long width, long height);
    int create_text(TPanel* parent, TTextPanel** output, int string_id,
                    long x, long y, long width, long height,
                    long p8, int p9, int p10, int p11);
    int create_list(TPanel* parent, TListPanel** output,
                    long x, long y, long width, long height, long lines);
    int create_auto_scrollbar(TScrollBarPanel** output,
                              TTextPanel* text, long width);
    int create_button(TPanel* parent, TButtonPanel** output, long string_id,
                      long p4, long x, long y, long width, long height,
                      long p9, long p10, long p11);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
};

extern RGE_Base_Game* rge_base_game;

static char name_selection_screen[] = "Name Selection Screen";
static char setup_info_file[] = "scr2";

class TRIBE_Screen_Name : public TScreenPanel {
public:
    TTextPanel* title;                       // +0x478
    TTextPanel* name_text;                   // +0x47C
    TListPanel* name_list;                   // +0x480
    TScrollBarPanel* name_scrollbar;         // +0x484
    TButtonPanel* new_button;                // +0x488
    TButtonPanel* remove_button;             // +0x48C
    TButtonPanel* ok_button;                 // +0x490
    TButtonPanel* cancel_button;             // +0x494
    TButtonPanel* close_button;              // +0x498
    int started_input;                       // +0x49C

    virtual ~TRIBE_Screen_Name();
    TRIBE_Screen_Name();
    void init_vars();
    void setup_tab_order();
    void get_player_names();
};

TRIBE_Screen_Name::TRIBE_Screen_Name()
    : TScreenPanel(name_selection_screen)
{
    this->init_vars();

    if (!this->TEasy_Panel::setup(rge_base_game->draw_area, 0, setup_info_file,
                                  0xC384, 1, 0, 0, 0, 0, 1)) {
        this->setup_error = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (!this->create_text(this, &this->title, 0x29FE,
                           0x14, 0x14, 0x258, 0x1E, 1, 1, 0, 0)) {
        return;
    }
    if (!this->create_text(this, &this->name_text, 0x29FF,
                           0x3C, 0x50, 0x8C, 0x14, 4, 0, 0, 0)) {
        return;
    }
    if (!this->create_list(this, &this->name_list,
                           0x3C, 0x64, 0x14A, 0x12C, 0x0B)) {
        return;
    }
    if (!this->create_auto_scrollbar(&this->name_scrollbar,
                                     this->name_list, 0x14)) {
        return;
    }

    this->name_scrollbar->set_help_info(0x765C, -1);

    if (!this->create_button(this, &this->new_button, 0x2A00,
                             0, 0x190, 0x64, 0xB4, 0x1E, 0, 0, 0)) {
        return;
    }
    this->new_button->set_help_info(0x765D, -1);

    if (!this->create_button(this, &this->remove_button, 0x2A01,
                             0, 0x190, 0x8C, 0xB4, 0x1E, 0, 0, 0)) {
        return;
    }
    this->remove_button->set_help_info(0x765E, -1);

    if (!this->create_button(this, &this->ok_button, 0x0FA1,
                             0, 0x46, 0x1B8, 0xF0, 0x1E, 0, 0, 0)) {
        return;
    }
    this->ok_button->set_help_info(0x7531, -1);

    if (!this->create_button(this, &this->cancel_button, 0x0FA2,
                             0, 0x14A, 0x1B8, 0xF0, 0x1E, 0, 0, 0)) {
        return;
    }
    this->cancel_button->set_help_info(0x7532, -1);
    TButtonPanel* cancel = this->cancel_button;
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;

    if (!this->create_button(this, &this->close_button, 0x03EA,
                             0, 0, 0, 0, 0, -1, -1, 0)) {
        return;
    }
    this->close_button->set_positioning(9, 4, 4, 4, 4, 0x11, 0x11,
                                        0x11, 0x11, 0, 0, 0, 0);
    this->setup_tab_order();
    this->get_player_names();
    this->started_input = 0;
}
