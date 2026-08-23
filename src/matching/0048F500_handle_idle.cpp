#include "../../include/scr_ach_context.h"

long TribeAchievementsScreen::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}
