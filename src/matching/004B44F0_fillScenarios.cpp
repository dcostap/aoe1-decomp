// VA: 004B44F0 | TribeSelectScenarioScreen::fillScenarios()
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/scr_sels_context.h"

static const char s_fmt_range[] = "%d - %d";
static const char s_fmt_num[] = "%d";

void TribeSelectScenarioScreen::fillScenarios()
{
    RGE_Scenario_File_Info* scenario_info_file;
    char* name;
    int i;
    int len;
    char player_str[20];
    char file_name[260];
    char scenario_file[260];

    scenario_info_file = rge_base_game->scenario_info;
    scenario_info_file->reload_scenarios();
    this->scenarioList->empty_list();
    this->scenarioList->field_15c = 1;
    this->scenarioCount = 0;
    while (1) {
        name = scenario_info_file->get_scenario_name(this->scenarioCount);
        if (name == 0) break;
        len = strlen(name) - 4;
        strncpy(file_name, name, len);
        file_name[len] = 0;
        this->scenarioList->append_line(file_name, this->scenarioCount);
        this->scenarioCount++;
    }
    this->scenarioMission = (char**)calloc(this->scenarioCount, 4);
    this->scenarioFixed = (int*)calloc(this->scenarioCount, 4);
    if (this->scenarioMission == 0 || this->scenarioFixed == 0) return;
    i = 0;
    if (this->scenarioCount <= 0) return;
    do {
        long id = this->scenarioList->get_id(i);
        RGE_Scenario_Header* hdr = scenario_info_file->get_scenario_info(id);
        if (hdr != 0) {
            this->scenarioMission[i] = (char*)calloc(0x1000, 1);
            if (this->scenarioMission[i] != 0 && hdr->description != 0) {
                strcpy(this->scenarioMission[i], hdr->description);
            }
            this->scenarioFixed[i] = hdr->fixed;
            int players = hdr->num_players;
            if (players > 0) {
                if (this->scenarioFixed[i] == 0 && players >= 3) {
                    sprintf(player_str, s_fmt_range, 2, players);
                } else {
                    sprintf(player_str, s_fmt_num, players);
                }
                strcpy(scenario_file, this->scenarioList->get_text(i));
                this->scenarioList->change_line(i, scenario_file, player_str, 0);
            }
        }
        i++;
    } while (i < this->scenarioCount);
}
