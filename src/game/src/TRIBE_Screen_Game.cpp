#include "../include/TRIBE_Screen_Game.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/custom_debug.h"
#include "../include/globals.h"

#include <string.h>

TRIBE_Screen_Game::TRIBE_Screen_Game()
    : GameViewPanel((rge_base_game != nullptr && rge_base_game->world != nullptr) ? rge_base_game->world->map : nullptr) {
    // TODO: STUB: this is a temporary wrapper over GameViewPanel until scr_game.cpp parity is restored.
    memset(this->shim_padding, 0, sizeof(this->shim_padding));
}

TRIBE_Screen_Game::~TRIBE_Screen_Game() {}

void TRIBE_Screen_Game::handle_game_update() {
    // TODO: STUB: restore real scr_game.cpp @ 0x00496800 update behavior.
    if (rge_base_game != nullptr && rge_base_game->world != nullptr) {
        this->world_map = rge_base_game->world->map;
    }

    this->set_redraw(TPanel::Redraw);
}

void TRIBE_Screen_Game::game_mode_changed(int new_mode, int old_mode) {
    // TODO: STUB: restore real scr_game.cpp @ 0x00498A10 game-mode transition behavior.
    (void)new_mode;
    (void)old_mode;
}

void TRIBE_Screen_Game::player_changed(int old_player, int new_player) {
    // TODO: STUB: restore real scr_game.cpp @ 0x00498A50 player-changed behavior.
    (void)old_player;
    (void)new_player;
}

void TRIBE_Screen_Game::handle_pause() {
    // TODO: STUB: restore real scr_game.cpp @ 0x004972A0 pause behavior.
}

void TRIBE_Screen_Game::handle_resume() {
    // TODO: STUB: restore real scr_game.cpp @ 0x004972F0 resume behavior.
}

void TRIBE_Screen_Game::handleChatReceived(int from_player) {
    // TODO: STUB: restore real scr_game.cpp @ 0x00497330 chat receive behavior.
    (void)from_player;
}

void TRIBE_Screen_Game::display_system_message(char* text) {
    // TODO: STUB: restore real scr_game.cpp @ 0x004973F0 message panel behavior.
    if (text != nullptr && text[0] != '\0') {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("TRIBE_Screen_Game message: %s", text);
CUSTOM_DEBUG_END
    }
}

void TRIBE_Screen_Game::setup_buttons() {
    // TODO: STUB: restore real scr_game.cpp @ 0x004996C0 button setup behavior.
}

void TRIBE_Screen_Game::reset_clocks() {
    // TODO: STUB: restore real scr_game.cpp @ 0x0049ADA0 clock-reset behavior.
}
