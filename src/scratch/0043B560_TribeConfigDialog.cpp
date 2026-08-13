// VA: 0043B560 TribeConfigDialog::TribeConfigDialog
// PDB: dlg_conf.cpp:84-321
//
// Baseline reconstruction: the dialog owns the contiguous panel fields after
// the real TPanel -> TEasy_Panel -> TDialogPanel hierarchy.  The constructor
// relies on the compiler's derived-vftable and /GX lowering; it does not write
// a vptr or dispatch through a hand-padded table.
//
// Attempt log:
// - baseline: natural inherited dialog surface, explicit panel-pointer
//   initialization in declaration order, and the period panel construction
//   sequence from dlg_conf.cpp.decomp.  Frame 0x0C, 20/22 text call sites.
// - layout: ten-entry tab-list local reproduced the 0x2C original frame.
// - control-flow: separate mouse/rollover branch call sites restored 65/65
//   ordered calls and exact rebuilt size after the first structural pass.
// - layout: memset-style zeroing of each owned pointer array reproduced the
//   working-pointer/zero-register initialization block (shape 92%+).
// - behavior: title uses font/style argument 1, not the ordinary 0x0A font.
// - control-flow: speed and size label loops retain switch-shaped dispatch;
//   the bounded speed switch variant without a default was diagnostic only.
// - control-flow: reordered the speed-label switch cases to 0, 1, 2 with a
//   shared default; this matched the first sub/dec dispatch hunk and improved
//   the positional diff to 2115, but changed a later call boundary.
// - control-flow: tested an ordered if/else reconstruction from the first
//   hunk; VC5 emitted test/jne instead of the original sub/dec chain. Restored
//   the natural switch reconstruction because the binary supports its shape.
// - abi: set_radio_info takes a TPanel* group; the game pointer is the proven
//   absolute 0x62C574 global.  Named music/sound locals preserve loaded
//   subsystem pointers across their null tests.
// - final control-flow probe: display-width radio selection uses switch.
//   Current validated reconstruction remains nonexact: frame 0x2C, size
//   2861/2880, calls 65/65, shape 93.18%, first mismatch in speed-label
//   switch scheduling; no opaque codegen-only scaffolding retained.

#include <string.h>

class TDrawSystem;
class TDrawArea;
class TPanel;
class TTextPanel;
class TButtonPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class TScreenPanel;
class TMusic_System;
class TSound_Driver;
class RGE_Prog_Info;
class RGE_Game_World;

class TDrawArea {
public:
    TDrawSystem* draw_system;
};

class TPanel {
public:
    virtual ~TPanel();

    char gap_04[0x1C];
    TDrawArea* render_area;                 // +0x20
    char gap_24[0xD0];                      // TPanel size = 0xF4

    TDrawArea* renderArea();
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, int count);
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();

    char gap_F4[0x384];                     // TEasy_Panel size = 0x478

    long get_popup_info_id();
    char* get_popup_info_file();
    int create_text(TPanel* parent, TTextPanel** out, int string_id,
                    long x, long y, long width, long height, long font,
                    int center_h, int center_v, int word_wrap);
    int create_radio_button(TPanel* parent, TButtonPanel** out,
                            long x, long y, long width, long height,
                            long sound, long param8);
    int create_vert_slider(TPanel* parent, TVerticalSliderPanel** out,
                           long x, long y, long width, long height,
                           long param8, long param9, long param10);
    int create_button(TPanel* parent, TButtonPanel** out, int string_id,
                      long x, long y, long width, long height, long font,
                      long param9, long param10, long param11);
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();

    char gap_478[0x18];                     // TDialogPanel size = 0x490

    TDialogPanel(char* name);
    int setup(TDrawArea* draw_area, TPanel* parent, long width, long height,
              char* info_file, long info_id, int modal);
};

class TTextPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x204];
    int hotkey;                             // +0x298
    int hotkey_shift;                       // +0x29C

    void set_radio_info(TPanel* group, int count);
    void set_disabled(int disabled);
    void set_radio_button();
};

class TScrollBarPanel : public TPanel {
public:
    void set_tab_pos(int position);
};

class TVerticalSliderPanel : public TScrollBarPanel {
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TDrawSystem {
public:
    char gap_00[0x2C];
    long width;                             // +0x2C

    int IsModeAvail(long width, long height, int bpp);
};

class RGE_Prog_Info {
public:
    char gap_00[0x8C8];
    long mouse_scroll_interval;             // +0x8C8
    char gap_8CC[0x10];
    short interface_style;                  // +0x8DC
};

class RGE_Game_World {
public:
    char gap_00[0x18];
    float game_speed;                       // +0x18
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[0x08];
    RGE_Prog_Info* prog_info;               // +0x0C
    char gap_10[0x50];
    TSound_Driver* sound_system;            // +0x60
    TMusic_System* music_system;            // +0x64
    char gap_68[0x148];
    int prog_mode;                          // +0x1B0
    char gap_1B4[0x240];
    RGE_Game_World* world;                  // +0x3F4
    char gap_3F8[0x610];
    int rollover;                           // +0xA08

    int multiplayerGame();
    unsigned char mpPathFinding();
    unsigned char pathFinding();
};

class TMusic_System {
public:
    char gap_00[0x254];
    long volume;                            // +0x254
};

class TSound_Driver {
public:
    long get_volume();
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)
extern float DAT_0056f740;
extern float DAT_0056f744;
extern float DAT_0056f748;

class TribeConfigDialog : public TDialogPanel {
public:
    enum Mode {
        InGame = 0
    };

    Mode modeValue;                         // +0x490
    TTextPanel* title;                      // +0x494
    TTextPanel* speedTitle[4];              // +0x498
    TButtonPanel* speedButton[3];           // +0x4A8
    TTextPanel* musicTitle[3];              // +0x4B4
    TVerticalSliderPanel* musicSlider;      // +0x4C0
    TTextPanel* soundTitle[3];              // +0x4C4
    TVerticalSliderPanel* soundSlider;      // +0x4D0
    TTextPanel* scrollSpeedTitle[3];        // +0x4D4
    TVerticalSliderPanel* scrollSpeedSlider;// +0x4E0
    TTextPanel* sizeTitle[4];               // +0x4E4
    TButtonPanel* sizeButton[3];            // +0x4F4
    TTextPanel* mouseTitle[3];              // +0x500
    TButtonPanel* mouseButton[2];           // +0x50C
    TTextPanel* rolloverTitle[3];           // +0x514
    TButtonPanel* rolloverButton[2];        // +0x520
    TTextPanel* pathFindingTitle[4];        // +0x528
    TButtonPanel* pathFindingButton[3];     // +0x538
    TButtonPanel* okButton;                 // +0x544
    TButtonPanel* cancelButton;             // +0x548
    long musicVolume;                       // +0x54C
    long soundVolume;                       // +0x550
    float gameSpeed;                        // +0x554
    long scrollSpeed;                       // +0x558
    long newMusicVolume;                    // +0x55C
    long newSoundVolume;                    // +0x560

    virtual ~TribeConfigDialog();
    TribeConfigDialog(Mode mode, TScreenPanel* parent);
};

TribeConfigDialog::TribeConfigDialog(Mode mode, TScreenPanel* parent)
    : TDialogPanel("Config Dialog"), modeValue(mode)
{
    TPanel* tab_list[10];
    int i;
    int string_id;
    int y;
    unsigned char path_finding;

    this->title = 0;
    memset(this->speedTitle, 0, sizeof(this->speedTitle));
    memset(this->speedButton, 0, sizeof(this->speedButton));
    memset(this->musicTitle, 0, sizeof(this->musicTitle));
    this->musicSlider = 0;
    memset(this->soundTitle, 0, sizeof(this->soundTitle));
    this->soundSlider = 0;
    memset(this->scrollSpeedTitle, 0, sizeof(this->scrollSpeedTitle));
    this->scrollSpeedSlider = 0;
    memset(this->sizeTitle, 0, sizeof(this->sizeTitle));
    memset(this->sizeButton, 0, sizeof(this->sizeButton));
    memset(this->mouseTitle, 0, sizeof(this->mouseTitle));
    memset(this->mouseButton, 0, sizeof(this->mouseButton));
    memset(this->rolloverTitle, 0, sizeof(this->rolloverTitle));
    memset(this->rolloverButton, 0, sizeof(this->rolloverButton));
    memset(this->pathFindingTitle, 0, sizeof(this->pathFindingTitle));
    memset(this->pathFindingButton, 0, sizeof(this->pathFindingButton));
    this->okButton = 0;
    this->cancelButton = 0;

    if (!this->setup(parent->renderArea(), parent, 600, 390,
                     parent->get_popup_info_file(),
                     parent->get_popup_info_id(), 1))
        return;

    if (!this->create_text(this, &this->title, 0x24D7, 0x67, 0x0A,
                           0x18B, 0x1E, 1, 1, 1, 0))
        return;
    if (!this->create_text(this, &this->speedTitle[0], 0x24DF, 0x14,
                           0x32, 0x6E, 0x1E, 0x0B, 0, 1, 0))
        return;

    for (i = 0; i < 3; ++i) {
        switch (i) {
        case 0:
            string_id = 0x24D8;
            break;
        case 1:
            string_id = 0x24D9;
            break;
        case 2:
            string_id = 0x24DA;
            break;
        default:
            string_id = 0x24D8;
            break;
        }
        y = i * 0x23 + 0x55;
        if (!this->create_text(this, &this->speedTitle[i + 1], string_id,
                               0x37, y, 0x6E, 0x1E, 0x0B, 0, 1, 0))
            return;
        if (!this->create_radio_button(this, &this->speedButton[i],
                                       0x14, y, 0x1E, 0x1E, 0, 0))
            return;
    }

    for (i = 0; i < 3; ++i)
        this->speedButton[i]->set_radio_info((TPanel*)this->speedButton, 3);

    if (rge_base_game->prog_mode == 5) {
        for (i = 0; i < 3; ++i)
            this->speedButton[i]->set_disabled(1);
    }

    float speed = rge_base_game->world->game_speed;
    this->gameSpeed = speed;
    if (speed == DAT_0056f740) {
        this->speedButton[2]->set_radio_button();
    } else if (speed == DAT_0056f744) {
        this->speedButton[1]->set_radio_button();
    } else if (speed == DAT_0056f748) {
        this->speedButton[0]->set_radio_button();
    }

    if (!this->create_text(this, this->musicTitle, 0x24DB, 0xA5, 0x2D,
                           0x6E, 0x28, 0x0B, 0, 1, 1))
        return;
    if (!this->create_text(this, &this->musicTitle[1], 0x24DC, 0xBE,
                           0x55, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_text(this, &this->musicTitle[2], 0x24DD, 0xBE,
                           0xA5, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_vert_slider(this, &this->musicSlider, 100, 10,
                                  0x14, 0xAA, 0x55, 0x14, 100))
        return;

    TMusic_System* music_system = rge_base_game->music_system;
    if (music_system == 0)
        this->musicVolume = 99;
    else
        this->musicVolume = music_system->volume / -100;
    this->musicSlider->set_tab_pos(this->musicVolume);
    this->newMusicVolume = this->musicVolume;

    if (!this->create_text(this, this->soundTitle, 0x24DE, 0x131, 0x2D,
                           0x6E, 0x28, 0x0B, 0, 1, 1))
        return;
    if (!this->create_text(this, &this->soundTitle[1], 0x24DC, 0x14A,
                           0x55, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_text(this, &this->soundTitle[2], 0x24DD, 0x14A,
                           0xA5, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_vert_slider(this, &this->soundSlider, 100, 10,
                                  0x14, 0x136, 0x55, 0x14, 100))
        return;

    TSound_Driver* sound_system = rge_base_game->sound_system;
    if (sound_system == 0)
        this->soundVolume = 99;
    else
        this->soundVolume = sound_system->get_volume() / -100;
    this->soundSlider->set_tab_pos(this->soundVolume);
    this->newSoundVolume = this->soundVolume;

    if (!this->create_text(this, this->scrollSpeedTitle, 0x24F0, 0x1BD,
                           0x2D, 0x6E, 0x28, 0x0B, 0, 1, 1))
        return;
    if (!this->create_text(this, &this->scrollSpeedTitle[1], 0x24F1,
                           0x1D6, 0x55, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_text(this, &this->scrollSpeedTitle[2], 0x24F2,
                           0x1D6, 0xA5, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_vert_slider(this, &this->scrollSpeedSlider, 100, 10,
                                  0x14, 0x1C2, 0x55, 0x14, 100))
        return;

    this->scrollSpeed = rge_base_game->prog_info->mouse_scroll_interval;
    this->scrollSpeedSlider->set_tab_pos(this->scrollSpeed - 10);

    if (!this->create_text(this, this->sizeTitle, 0x24E0, 0x14, 0xBE,
                           200, 0x1E, 0x0B, 0, 1, 0))
        return;
    for (i = 0; i < 3; ++i) {
        switch (i) {
        case 1:
            string_id = 0x24E8;
            break;
        case 2:
            string_id = 0x24E9;
            break;
        default:
            string_id = 0x24E7;
            break;
        }
        y = i * 0x23 + 0xE1;
        if (!this->create_text(this, &this->sizeTitle[i + 1], string_id,
                               0x37, y, 100, 0x1E, 0x0B, 0, 1, 0))
            return;
        if (!this->create_radio_button(this, &this->sizeButton[i],
                                       0x14, y, 0x1E, 0x1E, 0, 0))
            return;
    }
    for (i = 0; i < 3; ++i)
        this->sizeButton[i]->set_radio_info((TPanel*)this->sizeButton, 3);

    int screen_width = this->render_area->draw_system->width;
    switch (screen_width) {
    case 0x280:
        this->sizeButton[0]->set_radio_button();
        break;
    case 0x320:
        this->sizeButton[1]->set_radio_button();
        break;
    case 0x400:
        this->sizeButton[2]->set_radio_button();
        break;
    }

    if (!this->render_area->draw_system->IsModeAvail(0x280, 0, 8))
        this->sizeButton[0]->set_disabled(1);
    if (!this->render_area->draw_system->IsModeAvail(0x320, 0, 8))
        this->sizeButton[1]->set_disabled(1);
    if (!this->render_area->draw_system->IsModeAvail(0x400, 0, 8))
        this->sizeButton[2]->set_disabled(1);

    if (!this->create_text(this, this->mouseTitle, 0x24EA, 0xAA, 0xBE,
                           0xD2, 0x1E, 0x0B, 0, 1, 0))
        return;
    for (i = 0; i < 2; ++i) {
        if (i == 0) {
            y = 0xE1;
            if (!this->create_text(this, &this->mouseTitle[i + 1],
                                   0x24EB, 0xCD, y, 0x78, 0x1E,
                                   0x0B, 0, 1, 0))
                return;
        } else {
            y = i * 0x23 + 0xE1;
            if (!this->create_text(this, &this->mouseTitle[i + 1],
                                   0x24EC, 0xCD, y, 0x78, 0x1E,
                                   0x0B, 0, 1, 0))
                return;
        }
        if (!this->create_radio_button(this, &this->mouseButton[i],
                                       0xAA, y, 0x1E, 0x1E, 0, 0))
            return;
    }
    for (i = 0; i < 2; ++i)
        this->mouseButton[i]->set_radio_info((TPanel*)this->mouseButton, 2);
    if (rge_base_game->prog_info->interface_style == 2)
        this->mouseButton[0]->set_radio_button();
    else
        this->mouseButton[1]->set_radio_button();

    if (!this->create_text(this, this->rolloverTitle, 0x24ED, 0x14A,
                           0xBE, 0xD2, 0x1E, 0x0B, 0, 1, 0))
        return;
    for (i = 0; i < 2; ++i) {
        if (i == 0) {
            y = 0xE1;
            if (!this->create_text(this, &this->rolloverTitle[i + 1],
                                   0x24EE, 0x16D, y, 0x78, 0x1E,
                                   0x0B, 0, 1, 0))
                return;
        } else {
            y = i * 0x23 + 0xE1;
            if (!this->create_text(this, &this->rolloverTitle[i + 1],
                                   0x24EF, 0x16D, y, 0x78, 0x1E,
                                   0x0B, 0, 1, 0))
                return;
        }
        if (!this->create_radio_button(this, &this->rolloverButton[i],
                                       0x14A, y, 0x1E, 0x1E, 0, 0))
            return;
    }
    for (i = 0; i < 2; ++i)
        this->rolloverButton[i]->set_radio_info((TPanel*)this->rolloverButton, 2);
    if (rge_base_game->rollover == 0)
        this->rolloverButton[1]->set_radio_button();
    else
        this->rolloverButton[0]->set_radio_button();

    if (!this->create_text(this, this->pathFindingTitle, 0x260D, 0x1CC,
                           0xBE, 0xD2, 0x1E, 0x0B, 0, 1, 0))
        return;
    y = 0xE1;
    for (i = 0; i < 3; ++i) {
        if (!this->create_text(this, &this->pathFindingTitle[i],
                               i + 0x260E, 0x1EF, y, 0x78, 0x1E,
                               0x0B, 0, 1, 0))
            return;
        if (!this->create_radio_button(this, &this->pathFindingButton[i],
                                       0x1CC, y, 0x1E, 0x1E, 0, 0))
            return;
        if (rge_base_game->multiplayerGame())
            this->pathFindingButton[i]->set_disabled(1);
        y += 0x23;
    }
    for (i = 0; i < 3; ++i)
        this->pathFindingButton[i]->set_radio_info((TPanel*)this->pathFindingButton, 3);

    if (rge_base_game->multiplayerGame())
        path_finding = rge_base_game->mpPathFinding();
    else
        path_finding = rge_base_game->pathFinding();
    if (path_finding < 3)
        this->pathFindingButton[path_finding]->set_radio_button();

    if (!this->create_button(this, &this->okButton, 0xFA1, 0, 0x78,
                             0x159, 0xAA, 0x1E, 0, 0, 0))
        return;
    if (!this->create_button(this, &this->cancelButton, 0xFA2, 0,
                             0x136, 0x159, 0xAA, 0x1E, 0, 0, 0))
        return;

    this->cancelButton->hotkey = 0x1B;
    this->cancelButton->hotkey_shift = 0;
    this->set_curr_child(this->okButton);
    tab_list[0] = this->okButton;
    tab_list[1] = this->cancelButton;
    this->set_tab_order(tab_list, 2);
}
