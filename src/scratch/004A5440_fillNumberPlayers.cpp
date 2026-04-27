// 004A5440 fillNumberPlayers
// 121 bytes, __thiscall, TribeMPSetupScreen method
// probe 1: loop filling dropdown panel with player counts

#include <stdio.h>

class TDropDownPanel {
public:
    void empty_list();
    void append_line(const char* text, int data);
    int get_line(int index);
    void set_line(int data);
};

class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;
int RGE_Base_Game_numberPlayers(RGE_Base_Game* game);

class TribeMPSetupScreen {
public:
    TDropDownPanel* numberPlayersDrop;
    int scenarioPlayerCount;

    void fillNumberPlayers();
};

void TribeMPSetupScreen::fillNumberPlayers() {
    numberPlayersDrop->empty_list();
    int i = 2;
    if (1 < scenarioPlayerCount) {
        char str[16];
        do {
            sprintf(str + 4, "%d", i);
            numberPlayersDrop->append_line(str + 4, i);
            i++;
        } while (i <= scenarioPlayerCount);
    }
    int num = RGE_Base_Game_numberPlayers(rge_base_game);
    int line = numberPlayersDrop->get_line(num);
    numberPlayersDrop->set_line(line);
}
