// Attempt log for 004B44F0 TribeSelectScenarioScreen::fillScenarios
// try 1: natural reconstruction from packet/decompiler with minimal local class surfaces; close (56.5% positional/32.9% edit), but frame 0x220 vs original 0x224 and member offsets 4 low.
// try 2: add missing field before scenarioCount so offsets become 494/49C/4A0/4A4; edit diff improved to 15.16%, frame still 0x220.
// try 3: make pad_local volatile and assign it to force 0x224 frame; worsened due extra store, rolled back.
// try 4: remove forced volatile store, keep dead pad local (compiler ignores).
// try 5: reorder len copy statements to match original lea eax before mov esi/sub esi; edit diff improved to 8.84%, first loop exact except frame size.
// try 6: add address-taken dummy local; worsened due emitted check, rolled back.
// try 7: /Od flag probe; much worse from offset 0, rolled back.
// try 8: /Oy- flag probe; worse from offset 0, rolled back.
// try 9: reviewed calloc/strcpy include context; default /O2 remains best.
// try 10: reviewed loop topology; first name-enumeration loop now instruction-identical after frame-size displacement except call relocs.
// BLOCKER: best default source is very close by edit diff (8.84%) and exact size, but frame allocation remains 0x220 vs original 0x224 causing broad positional shift; later second loop has localized scheduling/block drift. Not accepted_drift-safe yet.
// session baseline: retained the named scenario-info, list, and buffer ownership as the clean reconstruction.
// session probe: binding rge_base_game to its proven absolute storage fixed the global relocation without changing structure.
// session probe: same-TU local declaration/lifetime shape (scenario_info_file, name, i, len, then buffers) restored the 0x224 frame and EBX scenario-info reload.
// session probe: a local union for the pointer/string overlap was not plausible/codegen-equivalent and was rolled back.
// session result: with the separate pointer local occupying the preceding stack slot, ordinary buffers use their base (not decompiler-only +4 biases); this yields an exact 554-byte match under default /O2 /Oy.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

class RGE_Scenario_Header { public: char gap_00[0x10]; char* description; int fixed; int num_players; };
class RGE_Scenario_File_Info { public: void reload_scenarios(); char* get_scenario_name(int); RGE_Scenario_Header* get_scenario_info(long); };
class RGE_Base_Game { public: char gap_00[8]; RGE_Scenario_File_Info* scenario_info; };
class TTextPanel { public: void empty_list(); long get_id(long); char* get_text(long); int append_line(char*, long); int change_line(long,char*,char*,int); char gap[0x15c]; int field_15c; };
class TribeSelectScenarioScreen { public: char gap_000[0x494]; TTextPanel* scenarioList; int gap_498; int scenarioCount; char** scenarioMission; int* scenarioFixed; void fillScenarios(); };

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
