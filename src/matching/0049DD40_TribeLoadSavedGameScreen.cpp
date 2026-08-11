// 0049DD40 TribeLoadSavedGameScreen::TribeLoadSavedGameScreen
// Source: scr_load.cpp lines 54-119
// Attempt log:
// - Pre-existing scratch used an /Od diagnostic scaffold and a partially typed
//   hierarchy; it was structurally unrelated to the optimized EH constructor.
// baseline: canonical TPanel/TEasy_Panel/TScreenPanel layout, typed child
//   ownership, natural strcpy/setup sequence, and the scr_load.cpp local order.
//   Original evidence proves a 0x478 base, fields at +0x478..+0x490, an EH
//   constructor (/GX), and four TPanel* tab entries with a 260-byte buffer.
// layout probe: the final set_tab_order(tabList + 1, 4) consumes list, OK,
//   delete, and cancel; modeling five contiguous local slots while removing
//   the dead fromPanel local preserved the original 0x11C frame.
// liveness probes: aliases for the OK output field alone were codegen-neutral;
//   carrying natural cancel/delete child pointers across their paired hotkey
//   stores removed two reloads and recovered the exact suffix.
// exact: 822B / 0.0000%; direct relocation identity and boundary validated.
// FLAGS: config/flags/0049DD40_TribeLoadSavedGameScreen.rsp (/GX)

#include <string.h>

class TDrawArea;
class TPanel;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect();
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);

    char gap_04[0xD4];
    int setup_error;                         // +0xD8
    char gap_DC[0x18];                       // through sizeof(TPanel)==0xF4

    void set_help_info(long help_id, long page_id);
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, short count);
};

class TTextPanel : public TPanel {
public:
    char* currentLine();
    long get_line(char* text);
};

class TListPanel : public TTextPanel {
public:
    void scroll_cur_line(unsigned char mode, short line, int update_scrollbar);
};

class TScrollBarPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];                       // through +0x298
    long hotkey;                              // +0x298
    long hotkey_shift;                        // +0x29C
    void set_disabled(int disabled);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];                       // sizeof(TEasy_Panel)==0x478

    char* get_info_file();
    long get_info_id();
    void setup_shadow_area(int force_rebuild);
    void set_ideal_size(long width, long height);
    int create_text(TPanel* parent, TTextPanel** out, long string_id,
                    long x, long y, long width, long height,
                    long p8, long p9, long p10, long p11);
    int create_list(TPanel* parent, TListPanel** out,
                    long x, long font, long width, long height, long lines);
    int create_auto_scrollbar(TScrollBarPanel** out, TTextPanel* text,
                              long width);
    int create_button(TPanel* parent, TButtonPanel** out, long string_id,
                      long p4, long x, long y, long width, long height,
                      long p9, long p10, long p11);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(TDrawArea* draw_area, char* info_file, long info_id, int param);
};

class TPanelSystem {
public:
    TEasy_Panel* currentPanel();
};

extern TPanelSystem panel_system;

class TRIBE_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;                     // +0x4C
    char* get_save_game_name();
};

extern TRIBE_Game* rge_base_game;

class TribeLoadSavedGameScreen : public TScreenPanel {
public:
    TTextPanel* screenTitle;                  // +0x478
    TTextPanel* listTitle;                    // +0x47C
    TListPanel* list;                          // +0x480
    TScrollBarPanel* scrollbar;                // +0x484
    TButtonPanel* okButton;                    // +0x488
    TButtonPanel* cancelButton;                // +0x48C
    TButtonPanel* deleteButton;                // +0x490

    virtual ~TribeLoadSavedGameScreen();
    TribeLoadSavedGameScreen();
    void fillList();
};

TribeLoadSavedGameScreen::TribeLoadSavedGameScreen()
    : TScreenPanel("Load Saved Game Screen")
{
    TPanel* tabList[5];
    char info_file[260];

    this->screenTitle = 0;
    this->listTitle = 0;
    this->list = 0;
    this->scrollbar = 0;
    this->okButton = 0;
    this->cancelButton = 0;
    this->deleteButton = 0;

    tabList[0] = panel_system.currentPanel();
    strcpy(info_file, ((TEasy_Panel*)tabList[0])->get_info_file());

    TDrawArea* draw_area = rge_base_game->draw_area;
    if (!this->setup(draw_area, info_file,
                     ((TEasy_Panel*)tabList[0])->get_info_id(), 1)) {
        this->setup_error = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (!this->create_text(this, &this->screenTitle, 0x24FF,
                           0x14, 0x0A, 0x258, 0x1E, 1, 1, 0, 0)) {
        return;
    }
    if (!this->create_text(this, &this->listTitle, 0x2502,
                           0x14, 0x2D, 0x258, 0x14, 4, 0, 0, 0)) {
        return;
    }
    if (!this->create_list(this, &this->list,
                           0x14, 0x41, 0x258, 0x160, 0x0B)) {
        return;
    }
    if (!this->create_auto_scrollbar(&this->scrollbar, this->list, 0x14)) {
        return;
    }

    this->scrollbar->set_help_info(0x7670, -1);

    TButtonPanel** okButton = &this->okButton;
    if (!this->create_button(this, okButton, 0x0FA1,
                             0, 0x1E, 0x1B8, 0xB4, 0x1E, 0, 0, 0)) {
        return;
    }
    if (!this->create_button(this, &this->deleteButton, 0x24C9,
                             0, 0xE6, 0x1B8, 0xB4, 0x1E, 0, 0, 0)) {
        return;
    }
    if (!this->create_button(this, &this->cancelButton, 0x0FA2,
                             0, 0x1AE, 0x1B8, 0xB4, 0x1E, 0, 0, 0)) {
        return;
    }

    (*okButton)->set_help_info(0x7531, -1);
    this->cancelButton->set_help_info(0x7532, -1);
    TButtonPanel* cancel = this->cancelButton;
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;
    TButtonPanel* deleteButton = this->deleteButton;
    deleteButton->hotkey_shift = 0;
    deleteButton->hotkey = 0x2E;

    this->fillList();
    if (this->list->currentLine()[0] == 0) {
        (*okButton)->set_disabled(1);
        this->deleteButton->set_disabled(1);
    }

    long line = this->list->get_line(rge_base_game->get_save_game_name());
    if (line != -1) {
        this->list->scroll_cur_line(1, (short)line, 1);
    }

    this->set_curr_child(this->list);
    tabList[1] = this->list;
    tabList[2] = this->okButton;
    tabList[3] = this->deleteButton;
    tabList[4] = this->cancelButton;
    this->set_tab_order(tabList + 1, 4);
}
