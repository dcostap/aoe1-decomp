// 004911A0 TRIBE_Screen_Campaign_Selection::fillCampaigns
// PDB: scr_cams.cpp:247-278, 226 bytes
// __thiscall, void return
// FLAGS: default
//
// === Attempt log ===
// prior probes 1-7: 224/226-byte variants, register drift on rge_base_game load (eax vs edx).
// probe-001 baseline: canonical ownership restored (campaigns=0 init, exact PDB signatures).
//   diff 188, size +1: campaigns=0 store landed before empty_list (decl placed before call).
// probe-002 layout: moved declarations after empty_list() -> store lands in call setup; diff 183, size +1.
//   Remaining: global load into EDX (8B15+reloc) instead of EAX (A1); this-load deferred after pushes;
//   arg LEAs hoisted. One byte over target.
// probe-003 liveness: RGE_Game_Info* info = rge_base_game->player_game_info; local before the
//   get_campaign_list call (same idiom as exact donor 00490FF0_action.cpp). VC5 then loads the
//   global into EAX (A1), schedules mov ecx,[eax+4] between the two arg pushes, and reuses EAX
//   for the &campaigns LEA. Result: EXACT MATCH (0 bytes).
// Lesson: for a global->field->method(...) call, an explicit intermediate-pointer local can
//   change caller-side register allocation/scheduling; the inline chain form puts the global
//   in EDX and defers the this-load, costing 1 byte and shifting the whole function.

#include <stdlib.h>

#include "../../include/scr_cams_context.h"

void TRIBE_Screen_Campaign_Selection::fillCampaigns()
{
    this->campaignList->empty_list();

    RGE_Game_Info* info = rge_base_game->game_info;
    char** campaigns = 0;
    long current;

    long count = info->get_campaign_list(&campaigns, current);

    if (count != 0) {
        this->campaignList->sort_flag = 1;

        {
            int i;
            for (i = 0; i < count; i++) {
                this->campaignList->append_line(campaigns[i], i);
            }
        }

        this->campaignList->set_line(this->campaignList->get_line(current));

        {
            int i;
            for (i = 0; i < count; i++) {
                free(campaigns[i]);
            }
        }
        free(campaigns);

        long line = this->campaignList->get_line();
        if (line != -1) {
            RGE_Game_Info* info = rge_base_game->game_info;
            info->set_current_campaign(this->campaignList->get_id());
        }
    }
}
