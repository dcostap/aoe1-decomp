// 0043F340 TribeMenuDialog::TribeMenuDialog
// Probe 1: 76% diff — EH prolog OK, class offsets wrong (button at 42Ch vs 490h)
// Probe 2: fix TPanel gaps, add missing fields -> button at 490h
// Probe 3-4: raw address macro, zero constant -> same 74%
// Remaining ~74%: register allocation. Original uses ebx for zero constant
// (xor ebx,ebx; then push ebx for zero params). Rebuilt uses ebx for
// button array base (lea ebx,[esi+490h]), zeros as immediates.
// This register role swap cascades through all param pushes.
// Deep VC5 register alloc heuristic. Left in scratch.

#include "..\..\include\game_globals.h"

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};
extern TPanelSystem* panel_system;

class TDrawArea;

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
    char _gap_8C[0x54];
    int display_changed_count;
    char _gap_E4[0x10];

    virtual ~TPanel();
    TDrawArea* renderArea();
    char* get_string(int id);
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** buttons, int count);
    void delete_panel(TPanel** panel);
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x384];

    virtual ~TEasy_Panel();
    long get_popup_info_id();
    char* get_popup_info_file();
    int create_button(TPanel* parent, TPanel* panel, void* button_ptr, int lang_id,
                      int param5, int y_offset, int y_pos, int width, int height,
                      int param10, int param11, int type);
    void popupYesNoDialog(long lang_id, long title_id, long param3, long param4);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TDialogPanel : public TEasy_Panel {
public:
    char _gap_478[0x18];

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
    int action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
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
    for (i = 0; i < 11; i++)
        this->button[i] = 0;

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

    int bi = 0;
    if (!this->create_button(this, this, &this->button[bi], 0x2439, 0, 0x14, 0x0F, 0x168, 0x1E, 0, 0, 4))
        return;
    bi++;

    int by = 0x41;
    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->get_player()->game_status == 0) {
            if (!this->create_button(this, this, &this->button[bi], 0x2440, 0, 0x14, by, 0x168, 0x1E, 0, 0, 0x0C))
                return;
            bi++;
            by = 100;
        }
    }

    if (!this->create_button(this, this, &this->button[bi], 0x2437, 0, 0x14, by, 0x168, 0x1E, 0, 0, 7))
        return;
    bi++;
    by += 0x23;

    if (!this->create_button(this, this, &this->button[bi], 0x243E, 0, 0x14, by, 0x168, 0x1E, 0, 0, 9))
        return;
    bi++;
    by += 0x23;
    int by2 = by;

    if (rge_base_game->singlePlayerGame()) {
        if (!this->create_button(this, this, &this->button[bi], 0x2438, 0, 0x14, by2, 0x168, 0x1E, 0, 0, 1))
            return;
        bi++;
        if (!this->create_button(this, this, &this->button[bi], 0x243C, 0, 0x14, by + 0x69, 0x168, 0x1E, 0, 0, 3))
            return;
        bi++;
        if (!this->create_button(this, this, &this->button[bi], 0x243F, 0, 0x14, by + 0x8C, 0x168, 0x1E, 0, 0, 0x0B))
            return;
        bi++;
        by2 = by + 0xAF;
    }

    if (!this->create_button(this, this, &this->button[bi], 0x243A, 0, 0x14, by2, 0x168, 0x1E, 0, 0, 5))
        return;
    bi++;
    by2 += 0x23;

    if (!this->create_button(this, this, &this->button[bi], 0x23F5, 0, 0x14, by2, 0x168, 0x1E, 0, 0, 8))
        return;
    bi++;
    by2 += 0x23;

    if (!this->create_button(this, this, &this->button[bi], 0x23F9, 0, 0x14, by2, 0x168, 0x1E, 0, 0, 10))
        return;
    bi++;
    by2 += 0x23;

    if (!this->create_button(this, this, &this->button[bi], 0x243B, 0, 0x14, by2 + 0x0F, 0x168, 0x1E, 0, 0, 6))
        return;

    TButtonPanel* p = this->button[bi];
    p->hotkey_shift = 0;
    p->hotkey = 0x1B;

    this->set_curr_child(this->button[0]);
    this->set_tab_order((TPanel**)this->button, bi + 1);
}
