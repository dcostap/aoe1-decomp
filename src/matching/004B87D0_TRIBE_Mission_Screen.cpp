// TRIBE_Mission_Screen::~TRIBE_Mission_Screen
// VA: 004B87D0
//
// Attempt log:
// - baseline: natural /GX virtual destructor with the TScreenPanel hierarchy,
//   polymorphic owned panels, and direct sound cleanup; repeated global
//   expressions left an 11-byte second-load hunk.
// - liveness: cached rge_base_game inside the game_flag guard; exact match.
// - layout: changed the unused picture member from void* to its proven
//   TPicture* type; exact output was preserved.
// FLAGS: config/flags/004B87D0_TRIBE_Mission_Screen.rsp (/GX for EH frame)
//
// Canonical reconstruction: this is a /GX virtual destructor for a
// TScreenPanel-derived screen.  The owned panel pointers are polymorphic and
// are destroyed with ordinary delete; the three text buttons are an array.

#ifdef SCR_VC_CONTEXT_GROUP
#include "../../include/scr_vc_context.h"
#else
class TPanel {
public:
    virtual ~TPanel();
    char pad_TPanel[0x40];
};

class TEasy_Panel : public TPanel {
public:
    char pad_TEasy[0x434];
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
};

class TScrollBarPanel : public TPanel {
public:
    virtual ~TScrollBarPanel();
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
};

class TPicture;

class RGE_Prog_Info {
public:
    char pad_00[0x8A8];
    int use_sound;
};

class TSound_Driver {
public:
    int stop_stream();
};

class RGE_Base_Game {
public:
    char pad_00[0x0C];
    RGE_Prog_Info* prog_info;
    char pad_10[0x50];
    TSound_Driver* sound_system;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Mission_Screen : public TScreenPanel {
public:
    TTextPanel* title;                 // +0x478
    TTextPanel* list;                  // +0x47C
    TScrollBarPanel* scroll_bar;       // +0x480
    TButtonPanel* ok_button;           // +0x484
    TButtonPanel* text_buttons[3];     // +0x488
    unsigned char game_flag;           // +0x494
    char pad_495[3];
    TPicture* vc_back_bmp;             // +0x498

    virtual ~TRIBE_Mission_Screen();
};
#endif

TRIBE_Mission_Screen::~TRIBE_Mission_Screen()
{
    if (this->game_flag == 0) {
        RGE_Base_Game* game = rge_base_game;
        if (game->prog_info->use_sound != 0 && game->sound_system != 0) {
            game->sound_system->stop_stream();
        }
    }

    delete this->title;
    delete this->list;
    delete this->scroll_bar;
    delete this->ok_button;

    for (int i = 0; i < 3; i++) {
        delete this->text_buttons[i];
    }
}
