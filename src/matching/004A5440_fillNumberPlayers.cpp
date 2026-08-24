// VA: 004A5440 TribeMPSetupScreen::fillNumberPlayers()
// PDB source: scr_mps.cpp lines 2892-2904
// Default flags
//
// __thiscall: this in ecx, no stack params. void return.
// Loop filling dropdown panel with player counts.

#include <stdio.h>
#include <stdlib.h>

#ifndef SCR_MPS_TU_CONTEXT

class TDropDownPanel {
public:
    void empty_list();
    int append_line(const char* text, int data);
    int get_line(int index);
    void set_line(int data);
};

class RGE_Base_Game {
public:
    int numberPlayers();
};

extern RGE_Base_Game* rge_base_game;

class TribeMPSetupScreen {
public:
    virtual ~TribeMPSetupScreen() {}
    char pad_04[0x6DC];
    TDropDownPanel* numberPlayersDrop;    // +0x6E0
    char pad_6E4[0x44];
    int scenarioPlayerCount;              // +0x728

    void fillNumberPlayers();
};

#endif

void TribeMPSetupScreen::fillNumberPlayers() {
    this->numberPlayersDrop->empty_list();

    int max_players = this->scenarioPlayerCount;
    if (max_players >= 2) {
        char str[16];
        int i = 2;
        do {
            sprintf(str, "%d", i);
            this->numberPlayersDrop->append_line(str, i);
            i++;
        } while (i <= this->scenarioPlayerCount);
    }

    int num = rge_base_game->numberPlayers();
    int line = this->numberPlayersDrop->get_line(num);
    this->numberPlayersDrop->set_line(line);
}
