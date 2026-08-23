// quick-win attempt log:
// target is 00490E30 TRIBE_Screen_Campaign_Selection::init_vars from scr_cams.cpp
// first pass uses direct member-zeroing plus the two global base-game calls; if codegen drifts,
// probe call order and whether the global load wants to stay duplicated like the oracle.

#include "../../include/scr_cams_context.h"

void TRIBE_Screen_Campaign_Selection::init_vars() {
    title = 0;
    campaignTitle = 0;
    campaignList = 0;
    campaignScrollbar = 0;
    scenarioTitle = 0;
    scenarioList = 0;
    scenarioScrollbar = 0;
    difficultyTitle = 0;
    difficultyDrop = 0;
    okButton = 0;
    cancelButton = 0;
    close_button = 0;
    campaignsLoaded = 0;

    int difficulty = rge_base_game->get_single_player_difficulty();
    rge_base_game->setDifficulty(difficulty);
}
