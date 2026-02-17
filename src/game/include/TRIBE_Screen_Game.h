#pragma once

#include "GameViewPanel.h"

class TRIBE_Screen_Game : public GameViewPanel {
public:
    TRIBE_Screen_Game();
    virtual ~TRIBE_Screen_Game();

    void handle_game_update();
    void game_mode_changed(int new_mode, int old_mode);
    void player_changed(int old_player, int new_player);
    void handle_pause();
    void handle_resume();
    void handleChatReceived(int from_player);
    void display_system_message(char* text);
    void setup_buttons();
    void reset_clocks();

private:
    static const int kScreenSize = 0x7C4;
    unsigned char shim_padding[kScreenSize - sizeof(GameViewPanel)];
};

static_assert(sizeof(GameViewPanel) <= 0x7C4, "GameViewPanel exceeds TRIBE_Screen_Game size");
static_assert(sizeof(TRIBE_Screen_Game) == 0x7C4, "Size mismatch");
