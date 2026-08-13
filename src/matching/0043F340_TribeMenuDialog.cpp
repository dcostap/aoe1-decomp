// 0043F340 TribeMenuDialog::TribeMenuDialog
// Attempt log:
// - Corrected create_button to the proven 11-argument parent/output ABI.
// - Mirrored exact dlg_menu.cpp sibling layout (TPanel RECT, TEasy size 0x490,
//   TDialog boundary, and virtual action surface).
// - Post-incrementing the output slot in each call recovered the oracle's
//   LEA-old-index/INC-before-call topology and raised shape similarity to 83.2%.
// - Indexed clear/memset/pointer-clear forms, a named zero, register hints, and
//   donor standard-header context emitted the same code; no source hack retained.
// Probes 13 and 17 found the one-state y schedule that reproduces the original
// button rows. A second state changed the allocator basin and was rolled back.
// Corrected the final hotkey target to button[bi - 1] and passed bi to tab order.
// The r2 reconstruction keeps by at the Scenario row, then copies it to by2
// and advances by2 before the later rows. This preserves button rows and emits
// the original one-byte add immediate. The exact source is now validated.

#include "..\..\include\game_globals.h"

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};
extern TPanelSystem* panel_system;

class TDrawArea;
class TButtonPanel;

class TPanel {
public:
    char _gap_04[0x1C];
    TDrawArea* render_area;
    char _gap_24[0x1C];
    void* parent_panel;
    char _gap_44[0x28];
    int active;
    int visible;
    char _gap_74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char _gap_9C[0x44];
    int display_changed_count;
    char _gap_E4[0x10];

    virtual ~TPanel();
    TDrawArea* renderArea();
    char* get_string(int id);
    virtual long action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** buttons, int count);
    void delete_panel(TPanel** panel);
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x39C];

    virtual ~TEasy_Panel();
    long get_popup_info_id();
    char* get_popup_info_file();
    int create_button(TPanel* parent, TButtonPanel** button_ptr, long lang_id,
                      long param5, long y_offset, long y_pos, long width, long height,
                      long param10, long param11, long type);
    void popupYesNoDialog(long lang_id, long title_id, long param3, long param4);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
    int setup(TDrawArea* area, TPanel* parent, long width, long height, char* str, long id, int param);
};

class TButtonPanel : public TPanel {
public:
    char _gap_F4[0x1A4];
    int hotkey;
    int hotkey_shift;
};

class TribeMenuDialog : public TDialogPanel {
public:
    TButtonPanel* button[11];

    TribeMenuDialog(TScreenPanel* parent);
    virtual ~TribeMenuDialog();
    virtual long action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
};

class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    char _gap_00[0x80];
    unsigned char game_status;
};

class RGE_Base_Game {
public:
    int multiplayerGame();
    RGE_Player* get_player();
    int singlePlayerGame();
};

TribeMenuDialog::TribeMenuDialog(TScreenPanel* parent) : TDialogPanel("Menu Dialog")
{
    int i;
    for (i = 0; i < 11; ++i)
        this->button[i] = 0;
    int bi = 0;

    int y = 300;

    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->get_player()->game_status == 0)
            y = 0x14F;
    }

    if (rge_base_game->singlePlayerGame())
        y += 0x69;

    if (!this->setup(parent->renderArea(), parent, 400, y,
                     parent->get_popup_info_file(), parent->get_popup_info_id(), 1))
        return;

    if (!this->create_button(this, &this->button[bi++], 0x2439, 0, 0x14, 0x0F, 0x168, 0x1E, 0, 0, 4))
        return;

    int by = 0x41;
    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->get_player()->game_status == 0) {
            if (!this->create_button(this, &this->button[bi++], 0x2440, 0, 0x14, by, 0x168, 0x1E, 0, 0, 0x0C))
                return;
            by = 100;
        }
    }

    if (!this->create_button(this, &this->button[bi++], 0x2437, 0, 0x14, by, 0x168, 0x1E, 0, 0, 7))
        return;
    by += 0x23;

    if (!this->create_button(this, &this->button[bi++], 0x243E, 0, 0x14, by, 0x168, 0x1E, 0, 0, 9))
        return;
    int by2 = by;
    by2 += 0x23;

    if (rge_base_game->singlePlayerGame()) {
        if (!this->create_button(this, &this->button[bi++], 0x2438, 0, 0x14, by2, 0x168, 0x1E, 0, 0, 1))
            return;
        by2 += 0x23;
        if (!this->create_button(this, &this->button[bi++], 0x243C, 0, 0x14, by2, 0x168, 0x1E, 0, 0, 3))
            return;
        by2 += 0x23;
        if (!this->create_button(this, &this->button[bi++], 0x243F, 0, 0x14, by2, 0x168, 0x1E, 0, 0, 0x0B))
            return;
        by2 += 0x23;
    }

    if (!this->create_button(this, &this->button[bi++], 0x243A, 0, 0x14, by2, 0x168, 0x1E, 0, 0, 5))
        return;
    by2 += 0x23;

    if (!this->create_button(this, &this->button[bi++], 0x23F5, 0, 0x14, by2, 0x168, 0x1E, 0, 0, 8))
        return;
    by2 += 0x23;

    if (!this->create_button(this, &this->button[bi++], 0x23F9, 0, 0x14, by2, 0x168, 0x1E, 0, 0, 10))
        return;
    by2 += 0x23;

    if (!this->create_button(this, &this->button[bi++], 0x243B, 0, 0x14, by2 + 0x0F, 0x168, 0x1E, 0, 0, 6))
        return;

    TButtonPanel* p = this->button[bi - 1];
    p->hotkey_shift = 0;
    p->hotkey = 0x1B;

    this->set_curr_child(this->button[0]);
    this->set_tab_order((TPanel**)this->button, bi);
}
