// 004A5610 TRIBE_Screen_Wait::TRIBE_Screen_Wait
// PDB source: scr_mps.cpp lines 2950-3225 (134 line records)
//
// Reconstruction notes:
// - Large /GX EH-framed screen constructor following the proven pattern of
//   the exact sibling ctor 004A71F0 (TribeSaveGameScreen): TScreenPanel base
//   ctor, compiler-emitted derived-vftable store, setup() guard writing +0xD8 on
//   failure, then panel creation and per-game-option text fill.
// - Text/button panels use vtable slots set_active(+0x14), set_positioning
//   (+0x18), set_text(+0xE8) through a local polymorphic TPanel view.
// - create_text/create_button/set_ideal_size/setup/get_string are direct
//   thiscall calls (relocation identity with the original targets).
// - Value strings are fetched either via get_string(id, buf, 0x100) or via
//   strcpy(buf, get_string(id)) exactly as the original alternates; formatted
//   lines land in a second buffer via sprintf and are pushed with
//   settingText[index]->set_text(...) + set_active(1).
// - mapSize/mapType/victoryType switches keep the per-case get_string+strcpy
//   so VC5 tail-merges them like the original shared strcpy blocks.
// FLAGS: /GX (original has the fs:[0] EH registration frame; all sibling
// scr_mps/scr_save screen ctors match only with /GX)

#ifndef SCR_MPS_TU_CONTEXT

#include <stdio.h>
#include <string.h>

struct tagRECT;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int active);          // +0x14
    virtual void set_positioning(int mode, int a2, int a3, int a4, int a5,
                                 int a6, int a7, int a8, int a9,
                                 int a10, int a11, int a12, int a13); // +0x18
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
};

class TTextPanel : public TPanel {
public:
    virtual void set_text_id(long);
    virtual void set_text_string(char*);
    virtual void set_text(char* text);            // +0xE8
};
class TButtonPanel : public TPanel {
public:
    virtual void set_text_id(long);
    virtual void set_text_string(char*);
    virtual void set_text(char* text);            // +0xE8
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    void* draw_area;                     // +0x4C
    int scenarioGame();                  // 004223A0
    int randomGame();                    // 004223B0
    char* scenarioName();                // 004223E0
    int multiplayerGame();               // 00422400
    int allowCheatCodes();               // 00422440
    int fullVisibility();                // 00422460
    unsigned char pathFinding();         // 00422670
    unsigned char mpPathFinding();       // 00422680
    int difficulty();                    // 00422640
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int mapSize();                       // 005291F0
    int mapType();                       // 005292A0
    int victoryType();                   // 00529300
    int victoryAmount();                 // 00529310
    int fullTechTree();                  // 00529430
    int randomizePositions();            // 00529420
    int resourceLevel();                 // 00529440
    int startingAge();                   // 00529450
    unsigned char deathMatch();          // 00529470
    unsigned char popLimit();            // 00529480
};

extern TRIBE_Game* rge_base_game;

class TEasy_Panel : public TPanel {
public:
    char gap_04[0xD4];
    int field_D8;                        // +0xD8
    char gap_DC[0x39C];                  // -> 0x478 total
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);                                    // 0047BAB0
    virtual ~TScreenPanel();                                     // triggers /GX ctor EH frame
    long setup(void* draw_area, char* info, long id, long value); // 0047BAE0
    char* get_string(int id);                                    // 00466870
    int get_string(int id, char* buf, int len);                  // 00466840
    void set_ideal_size(long x, long y);                         // 00467A50
    int create_text(TPanel* parent, TTextPanel** out, char* text,
                    long x, long y, long w, long h, long font,
                    long align, long center, long wrap);         // 00468CB0
    int create_button(TPanel* parent, TButtonPanel** out, long id,
                      long a4, long a5, long a6, long a7, long a8,
                      long a9, long a10, long a11);              // 00468490
};

class TRIBE_Screen_Wait : public TScreenPanel {
public:
    virtual ~TRIBE_Screen_Wait();
    TTextPanel* message;             // +0x478
    TButtonPanel* cancel_button;     // +0x47C
    TButtonPanel* close_button;      // +0x480
    TTextPanel* scenarioName;        // +0x484
    TTextPanel* settingText[20];     // +0x488

    TRIBE_Screen_Wait();
};

#endif

TRIBE_Screen_Wait::TRIBE_Screen_Wait() : TScreenPanel("Multiplayer Wait Screen")
{
    char str1[0x100];
    char str2[0x100];
    char str3[0x100];
    int i;

    this->message = 0;
    this->cancel_button = 0;
    this->close_button = 0;
    this->scenarioName = 0;
    for (i = 0; i < 20; i++) {
        this->settingText[i] = 0;
    }

    if (this->setup(rge_base_game->draw_area, "scr3", 0xC385, 0) == 0) {
        this->field_D8 = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1E0);

    this->create_text((TPanel*)this, &this->message, "",
                     0x14, 0x28, 0x17C, 0x190, 4, 1, 1, 1);
    if (this->create_button((TPanel*)this, &this->close_button, 0x3EA,
                            0, 0, 0, 0, 0, -1, -1, 0) == 0) {
        return;
    }
    this->close_button->set_active(1);
    this->close_button->set_positioning(9, 4, 4, 4, 4, 0x11, 0x11, 0x11,
                                        0x11, 0, 0, 0, 0);

    if (this->create_text((TPanel*)this, &this->scenarioName, "",
                          0x1A4, 0x54, 0xDC, 0x44, 0xB, 0, 0, 1) == 0) {
        return;
    }

    int y = 0x53;
    int k = 0;
    for (; y < 0x233; y += 0x18, k++) {
        if (this->create_text((TPanel*)this, &this->settingText[k], "",
                              0x1A4, y, 0xDC, 0x14, 0xB, 0, 0, 0) == 0) {
            return;
        }
    }

    for (k = 0; k < 20; k++) {
        this->settingText[k]->set_active(0);
    }

    if (rge_base_game->scenarioGame()) {
        sprintf(str2, get_string(0x25ED), rge_base_game->scenarioName());
        this->scenarioName->set_text(str2);
        i = 3;
    } else {
        if (rge_base_game->deathMatch()) {
            get_string(0x2617, str1, 0x100);
        } else {
            get_string(0x25B5, str1, 0x100);
        }
        sprintf(str2, get_string(0x25ED), str1);
        this->scenarioName->set_text(str2);
        i = 1;
    }

    if (rge_base_game->randomGame()) {
        switch (rge_base_game->mapSize()) {
        case 0: strcpy(str1, get_string(0x2973)); break;   // Tiny
        case 1: strcpy(str1, get_string(0x2974)); break;   // Small
        case 2: strcpy(str1, get_string(0x2975)); break;   // Medium
        case 3: strcpy(str1, get_string(0x2976)); break;   // Large
        case 4: strcpy(str1, get_string(0x2977)); break;   // Huge
        case 5: strcpy(str1, get_string(0x2978)); break;   // Gigantic
        }
        sprintf(str2, get_string(0x25DA), str1);           // "Map Size: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;

        switch (rge_base_game->mapType()) {
        case 0: strcpy(str1, get_string(0x296A)); break;   // All Water
        case 1: strcpy(str1, get_string(0x296B)); break;   // Mostly Water
        case 2: strcpy(str1, get_string(0x296C)); break;   // Water & Land
        case 3: strcpy(str1, get_string(0x296D)); break;   // Mostly Land
        case 4: strcpy(str1, get_string(0x296E)); break;   // All Land
        case 5: strcpy(str1, get_string(0x296F)); break;   // Continental
        case 6: strcpy(str1, get_string(0x2970)); break;   // Lake
        case 7: strcpy(str1, get_string(0x2971)); break;   // Hilly
        case 8: strcpy(str1, get_string(0x2972)); break;   // Narrows
        }
        sprintf(str2, get_string(0x25B6), str1);           // "Map Type: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;
    }
    i++;

    switch (rge_base_game->victoryType()) {
    case 1:                            // Conquest
        strcpy(str1, get_string(0x10E1));
        goto victory_plain;
    case 7:                            // Time
        strcpy(str1, get_string(0x10E9));
        goto victory_amount;
    case 8:                            // Score
        strcpy(str1, get_string(0x10EA));
    victory_amount:
        sprintf(str2, get_string(0x25BE), str1,
                rge_base_game->victoryAmount());            // "Victory: %s (%d)"
        goto victory_done;
    default:
        if (rge_base_game->randomGame()) {
            strcpy(str1, get_string(0x10EC));
        } else {
            strcpy(str1, get_string(0x10E7));
        }
        goto victory_plain;
    case 9:                            // Standard
        strcpy(str1, get_string(0x10E7));
    victory_plain:
        sprintf(str2, get_string(0x25BC), str1);            // "Victory: %s"
    victory_done:
        break;
    }
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    int age = rge_base_game->startingAge();
    if (age == 0) {
        get_string(0x10E7, str1, 0x100);                    // Default
    } else if (age == 1) {
        get_string(0x106E, str1, 0x100);                    // Nomad
    } else {
        get_string(age + 0x1067, str1, 0x100);
    }
    sprintf(str2, get_string(0x25E4), str1);                // "Age: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    int level = rge_base_game->resourceLevel();
    if (level == 0) {
        get_string(0x10E7, str1, 0x100);                    // Default
    } else {
        get_string(level + 0x25E5, str1, 0x100);
    }
    sprintf(str2, get_string(0x25E5), str1);                // "Resources: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    rge_base_game->difficulty();
    get_string(rge_base_game->difficulty() + 0x2BD0, str1, 0x100);
    get_string(0x25E0, str2, 0x100);                        // "Difficulty Level: %s"
    sprintf(str3, str2, str1);
    this->settingText[i]->set_text(str3);
    this->settingText[i]->set_active(1);
    i++;

    if (rge_base_game->randomizePositions()) {
        get_string(0xFA4, str1, 0x100);
    } else {
        get_string(0xFA3, str1, 0x100);
    }
    sprintf(str2, get_string(0x25E9), str1);                // "Fixed Positions: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (rge_base_game->fullVisibility()) {
        strcpy(str1, get_string(0xFA3));
    } else {
        strcpy(str1, get_string(0xFA4));
    }
    sprintf(str2, get_string(0x25B8), str1);                // "Reveal Map: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (rge_base_game->fullTechTree()) {
        get_string(0xFA3, str1, 0x100);
    } else {
        get_string(0xFA4, str1, 0x100);
    }
    sprintf(str2, get_string(0x25EC), str1);                // "Full Tech Tree: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->allowCheatCodes()) {
            strcpy(str1, get_string(0xFA3));
        } else {
            strcpy(str1, get_string(0xFA4));
        }
        sprintf(str2, get_string(0x25BB), str1);            // "Enable Cheating: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;
    }

    if (rge_base_game->multiplayerGame()) {
        get_string(rge_base_game->mpPathFinding() + 0x260E, str1, 0x100);
    } else {
        get_string(rge_base_game->pathFinding() + 0x260E, str1, 0x100);
    }
    sprintf(str2, get_string(0x25F1), str1);                // "Path Finding: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    sprintf(str2, get_string(0x25F0), rge_base_game->popLimit());
    this->settingText[i]->set_text(str2);                   // "Population Limit: %d"
    this->settingText[i]->set_active(1);
}
