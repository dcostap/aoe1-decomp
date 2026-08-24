#include "../../include/scr_sing_context.h"

long TribeSPMenuScreen::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}
