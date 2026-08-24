// VA: 004A54C0 TribeMPSetupScreen::fillPlayerColors
// PDB donor: scr_mps.cpp:2910-2943
//
// Baseline reconstruction: the screen owns eight color-button panels.  Each
// panel receives the currently eligible scenario players, with the fixed
// player-color palette selected by the inner index.
// Main-agent audit restored canonical scenario/game/screen destructor surfaces;
// emitted code remains exact.

#include <stdio.h>

#ifndef SCR_MPS_TU_CONTEXT

class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    int Get_player_Active(int index);
    int Get_player_Type(int index);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    int scenarioGame();
    int singlePlayerGame();
};

extern RGE_Base_Game* rge_base_game;

class TButtonPanel {
public:
    void set_text(short state, char* text);
    void set_id(short state, long id, long id2);
    void set_text_color(int state, unsigned long color1, unsigned long color2);
    void set_state_info(short state_count);
};

class TribeMPSetupScreen {
public:
    virtual ~TribeMPSetupScreen();

    char gap_04[0x56C];
    TButtonPanel* playerColor[8]; // +0x570
    char gap_590[0x848 - 0x590];
    RGE_Scenario* scenarioInfo;   // +0x848

    void fillPlayerColors();
};

#endif

void TribeMPSetupScreen::fillPlayerColors() {
    TButtonPanel** buttons = this->playerColor;
    int remaining = 8;
    char str[16];

    do {
        int player = 0;
        int state = 0;

        do {
            if (rge_base_game->scenarioGame() == 0 ||
                this->scenarioInfo == 0 ||
                (this->scenarioInfo->Get_player_Active(player) != 0 &&
                 (rge_base_game->singlePlayerGame() == 0 ||
                  this->scenarioInfo->Get_player_Type(player) == 1))) {
                sprintf(str, "%d", player + 1);
                buttons[0]->set_text((short)state, str);
                buttons[0]->set_id((short)state, player + 1, 0);

                switch (player) {
                case 0:
                    buttons[0]->set_text_color(state, 0xFF0000, 0);
                    break;
                case 1:
                    buttons[0]->set_text_color(state, 0x0000FF, 0);
                    break;
                case 2:
                    buttons[0]->set_text_color(state, 0x00FFFF, 0);
                    break;
                case 3:
                    buttons[0]->set_text_color(state, 0x284673, 0);
                    break;
                case 4:
                    buttons[0]->set_text_color(state, 0x0764F0, 0);
                    break;
                case 5:
                    buttons[0]->set_text_color(state, 0x00FF00, 0);
                    break;
                case 6:
                    buttons[0]->set_text_color(state, 0xB4B4B4, 0);
                    break;
                case 7:
                    buttons[0]->set_text_color(state, 0x93BF2B, 0);
                    break;
                }
                state++;
            }
            player++;
        } while (player < 8);

        buttons[0]->set_state_info((short)state);
        buttons++;
    } while (--remaining != 0);
}
