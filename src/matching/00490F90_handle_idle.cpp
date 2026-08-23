// attempt 1: direct decompiler-shaped if chain, member-call base idle
// result: first mismatch was the class layout; campaignList landed 4 bytes late
// next try: keep the same block shape, but trim the local stub padding to account for the vptr

#include "../../include/scr_cams_context.h"

long TRIBE_Screen_Campaign_Selection::handle_idle() {
    if (this->campaignsLoaded == 0) {
        this->fillCampaigns();
        this->fillScenarios();
        this->set_curr_child(this->campaignList);
        this->campaignsLoaded = 1;
    }

    if (this->campaignsLoaded != 0) {
        if (rge_base_game->input_enabled == 0) {
            rge_base_game->enable_input();
        }
    }

    return TPanel::handle_idle();
}
