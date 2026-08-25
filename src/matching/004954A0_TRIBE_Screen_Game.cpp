// 004954A0 ~TRIBE_Screen_Game - destructor reconstruction attempt
// FLAGS: config/flags/004954A0_TRIBE_Screen_Game.rsp (/GX for original EH destructor frame)
// Attempts:
// - Existing raw ownership stubs matched the broad cleanup order but used the
//   wrong helper names and call targets.
// - Recovered scr_game.cpp field names and period C++ ownership forms:
//   panel_system.destroyPanel, typed TDigital/TShape deletes, free, and
//   virtual panel deletes. Exact match with /GX.
// - The simple TScreenPanel size stub preserves the proven +0x478 derived
//   layout and emits the expected base cleanup and destructor call.

#include "../../include/scr_game_context.h"

#if 0

class TShape {
public:
    ~TShape();
};

class TDigital {
public:
    int is_playing();
    void stop();
    ~TDigital();
};

class RGE_Sound {
public:
    void stop();
};

class TPanel {
public:
    virtual ~TPanel();
};

class TPanelSystem {
public:
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;
extern "C" void __cdecl free(void* block);
void __cdecl operator delete(void* block);

class TScreenPanel {
public:
    virtual ~TScreenPanel();
    char gap_04[0x474];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    TShape* game_screen_pic;             // +0x478
    TShape* button_border1_pic;          // +0x47C
    TShape* button_other_pic;            // +0x480
    TShape* button_border2_pic;           // +0x484
    TShape* button_border3_pic;           // +0x488
    TShape* button_cmd_pic;              // +0x48C
    TShape* button_tech_pic;             // +0x490
    TShape* button_unit_pic;             // +0x494
    TShape* button_bldg_pics[5];         // +0x498
    void* more_cancel_pic;               // +0x4AC
    short more_frame;                    // +0x4B0
    short cancel_frame;                  // +0x4B2
    short unselect_frame;                // +0x4B4
    unsigned char gap_4B6[2];
    TPanel* main_view;                   // +0x4B8
    TPanel* map_view;                    // +0x4BC
    TPanel* inven_panel;                 // +0x4C0
    TPanel* object_panel;                // +0x4C4
    TPanel* button_panel[17];            // +0x4C8
    TPanel* text_line_panel;             // +0x50C
    TPanel* quit_message_panel;          // +0x510
    TPanel* time_panel;                  // +0x514
    TPanel* countdown_clock[10];         // +0x518
    TPanel* pop_panel;                   // +0x540
    TPanel* message_panel;               // +0x544
    TPanel* message_panel2;              // +0x548
    TPanel* message_panel3;              // +0x54C
    TPanel* message_panel4;              // +0x550
    TPanel* message_panel5;              // +0x554
    TPanel* message_panel6;              // +0x558
    TPanel* chat_panel[8];               // +0x55C
    TPanel* tool_box;                    // +0x57C
    TPanel* age_panel;                   // +0x580
    TPanel* pause_text;                  // +0x584
    TPanel* fps_panel;                   // +0x588
    TPanel* score_panel[8];              // +0x58C
    TPanel* log_text;                    // +0x5AC
    TPanel* log_scrollbar;               // +0x5B0
    char gap_5B4[0x1C];
    void* tech_list;                     // +0x5D0
    void* make_list;                     // +0x5D4
    void* bldg_list;                     // +0x5D8
    void* trade_list;                    // +0x5DC
    char gap_5E0[0xA0];
    RGE_Sound* terrain_sound;            // +0x680
    int terrain_playing;                 // +0x684
    char gap_688[0x130];
    TDigital* sound_system;              // +0x7B8

    virtual ~TRIBE_Screen_Game();
};

#endif

TRIBE_Screen_Game::~TRIBE_Screen_Game() {
    panel_system.destroyPanel((char*)0x5842D8);

    if (this->sound_system != 0) {
        if (this->sound_system->is_playing() != 0) {
            this->sound_system->stop();
        }
        TDigital* sound = this->sound_system;
        if (sound != 0) {
            delete sound;
        }
        this->sound_system = 0;
    }

    if (this->terrain_sound != 0) {
        if (this->terrain_playing != 0) {
            this->terrain_playing = 0;
            this->terrain_sound->stop();
        }
        this->terrain_sound = 0;
    }

    if (this->game_screen_pic != 0) {
        delete this->game_screen_pic;
        this->game_screen_pic = 0;
    }
    if (this->button_border1_pic != 0) {
        delete this->button_border1_pic;
        this->button_border1_pic = 0;
    }
    if (this->button_other_pic != 0) {
        delete this->button_other_pic;
        this->button_other_pic = 0;
    }
    if (this->button_border2_pic != 0) {
        delete this->button_border2_pic;
        this->button_border2_pic = 0;
    }
    if (this->button_border3_pic != 0) {
        delete this->button_border3_pic;
        this->button_border3_pic = 0;
    }
    if (this->button_cmd_pic != 0) {
        delete this->button_cmd_pic;
        this->button_cmd_pic = 0;
    }
    if (this->button_tech_pic != 0) {
        delete this->button_tech_pic;
        this->button_tech_pic = 0;
    }
    if (this->button_unit_pic != 0) {
        delete this->button_unit_pic;
        this->button_unit_pic = 0;
    }

    int i;
    for (i = 0; i < 5; i++) {
        if (this->button_bldg_pics[i] != 0) {
            delete this->button_bldg_pics[i];
            this->button_bldg_pics[i] = 0;
        }
    }

    if (this->tech_list != 0) {
        free(this->tech_list);
        this->tech_list = 0;
    }
    if (this->make_list != 0) {
        free(this->make_list);
        this->make_list = 0;
    }
    if (this->bldg_list != 0) {
        free(this->bldg_list);
        this->bldg_list = 0;
    }
    if (this->trade_list != 0) {
        free(this->trade_list);
        this->trade_list = 0;
    }

    for (i = 0; i < 8; i++) {
        if (this->chat_panel[i] != 0) {
            delete this->chat_panel[i];
            this->chat_panel[i] = 0;
        }
    }
    for (i = 0; i < 17; i++) {
        if (this->button_panel[i] != 0) {
            delete this->button_panel[i];
            this->button_panel[i] = 0;
        }
    }

    if (this->age_panel != 0) {
        delete this->age_panel;
        this->age_panel = 0;
    }
    if (this->fps_panel != 0) {
        delete this->fps_panel;
        this->fps_panel = 0;
    }
    for (i = 0; i < 8; i++) {
        if (this->score_panel[i] != 0) {
            delete this->score_panel[i];
            this->score_panel[i] = 0;
        }
    }

    if (this->log_text != 0) {
        delete this->log_text;
        this->log_text = 0;
    }
    if (this->log_scrollbar != 0) {
        delete this->log_scrollbar;
        this->log_scrollbar = 0;
    }
    if (this->inven_panel != 0) {
        delete this->inven_panel;
        this->inven_panel = 0;
    }
    if (this->object_panel != 0) {
        delete this->object_panel;
        this->object_panel = 0;
    }
    if (this->quit_message_panel != 0) {
        delete this->quit_message_panel;
        this->quit_message_panel = 0;
    }
    if (this->text_line_panel != 0) {
        delete this->text_line_panel;
        this->text_line_panel = 0;
    }
    if (this->time_panel != 0) {
        delete this->time_panel;
        this->time_panel = 0;
    }
    if (this->pop_panel != 0) {
        delete this->pop_panel;
        this->pop_panel = 0;
    }
    for (i = 0; i < 10; i++) {
        if (this->countdown_clock[i] != 0) {
            delete this->countdown_clock[i];
            this->countdown_clock[i] = 0;
        }
    }
    if (this->message_panel6 != 0) {
        delete this->message_panel6;
        this->message_panel6 = 0;
    }
    if (this->message_panel5 != 0) {
        delete this->message_panel5;
        this->message_panel5 = 0;
    }
    if (this->message_panel4 != 0) {
        delete this->message_panel4;
        this->message_panel4 = 0;
    }
    if (this->message_panel3 != 0) {
        delete this->message_panel3;
        this->message_panel3 = 0;
    }
    if (this->message_panel2 != 0) {
        delete this->message_panel2;
        this->message_panel2 = 0;
    }
    if (this->message_panel != 0) {
        delete this->message_panel;
        this->message_panel = 0;
    }
    if (this->tool_box != 0) {
        delete this->tool_box;
        this->tool_box = 0;
    }
    if (this->pause_text != 0) {
        delete this->pause_text;
        this->pause_text = 0;
    }
    if (this->main_view != 0) {
        delete this->main_view;
        this->main_view = 0;
    }
    if (this->map_view != 0) {
        delete this->map_view;
        this->map_view = 0;
    }
}
