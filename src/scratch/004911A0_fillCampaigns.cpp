// 004911A0 TRIBE_Screen_Campaign_Selection::fillCampaigns
// PDB: scr_cams.cpp:247-278, 226 bytes
// __thiscall, void return
// FLAGS: default
//
// === Attempt log ===
// probes 1-7: all produce 224/226 byte variants.
// Best version: 226 bytes (matches size).
// First diff at offset 0x13: registers for rge_base_game load (eax vs edx).
// The register choice (eax=original vs edx=rebuilt) propagates through
// all lea/push/ecx setup instructions, affecting scheduling.
// Remaining diff: pure VC5 register allocation / instruction scheduling drift.
// Full TU context (scr_cams.cpp) might resolve.

#include <stdlib.h>

extern "C" void __cdecl free(void*);

class RGE_Game_Info {
public:
    long get_campaign_list(long** currentCampaign, long* local_4);
    void set_current_campaign(long id);
};

class RGE_Base_Game {
public:
    char _gap_00[4];
    RGE_Game_Info* player_game_info;    // +0x04
};

extern RGE_Base_Game* rge_base_game;

class TTextPanel {
public:
    char _gap_000[0x15C];
    long sort_flag;                     // +0x15C

    void empty_list();
    long append_line(char* name, long index);
    long get_line(long param_1);
    void set_line(long line_id);
    long get_line();
    long get_id();
};

class TRIBE_Screen_Campaign_Selection {
public:
    char _gap_000[0x490];
    TTextPanel* campaignList;           // +0x490

    void fillCampaigns();
};

void TRIBE_Screen_Campaign_Selection::fillCampaigns()
{
    long currentCampaign;
    long campaigns;

    this->campaignList->empty_list();

    long numCampaigns = rge_base_game->player_game_info->get_campaign_list(
        (long**)&currentCampaign, &campaigns);

    if (numCampaigns != 0) {
        this->campaignList->sort_flag = 1;

        {
            int i;
            for (i = 0; i < numCampaigns; i++) {
                this->campaignList->append_line(
                    ((char**)currentCampaign)[i], i);
            }
        }

        long line = this->campaignList->get_line(campaigns);
        this->campaignList->set_line(line);

        {
            int i;
            for (i = 0; i < numCampaigns; i++) {
                free(((char**)currentCampaign)[i]);
            }
        }
        free((void*)currentCampaign);

        long currentLine = this->campaignList->get_line();
        if (currentLine != -1) {
            long id = this->campaignList->get_id();
            rge_base_game->player_game_info->set_current_campaign(id);
        }
    }
}
