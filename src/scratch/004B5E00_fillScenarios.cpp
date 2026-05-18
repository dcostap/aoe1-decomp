// VA: 004B5E00 TribeGameSettingsScreen::fillScenarios
// Attempt log:
// try 1: natural reconstruction from packet; models scenario reload, first pass count,
// allocations, second pass detail strings/fixed players, and standard/random scenario lines. Compiled too small (784B vs original 864B).
// try 2: temporary extra special-line calls reached byte compare but proved broad mismatch (74.8843% positional / 81.8287% edit); removed those behavior-wrong padding calls.
// Current blockers: exact TListPanel/TTextPanel method surfaces, base-game scenario-info type, first-pass strcmp/source order, second-pass get_line_text/get_scenario_info calls, fixed-player formatting branch, and special random/default scenario insertion tails. No inline asm used; not accepted_drift quality.
// GIVEUP: natural source remains a broad model/size mismatch, left for donor-source reconstruction.

extern "C" char* strncpy(char* dst, const char* src, unsigned int n);
extern "C" int strcmp(const char*, const char*);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* calloc(unsigned int n, unsigned int sz);

class RGE_Scenario_File_Entry { public: char gap00[0x10]; char* title; int fixed_players; int player_count; };
class RGE_Scenario_File_Info {
public:
    void reload_scenarios();
    char* get_scenario_name(int idx);
    RGE_Scenario_File_Entry* get_scenario_info(char* name);
};
class RGE_Base_Game {
public:
    int multiplayerGame();
    int scenarioGame();
    char* scenarioName();
    int isTrial();
    RGE_Scenario_File_Info* scenario_info;
};
class TTextPanel {
public:
    char gap00[0x15c];
    int field_15c;
    void empty_list();
    void add_line(char* text, int id);
    char* get_line_text(int line);
    int get_id(int line);
    void add_text_line(char* a, char* b, char* c, int d);
};
class TribeGameSettingsScreen {
public:
    char gap000[0x4F0];
    TTextPanel* scenarioList;       // +4f0
    char gap4f4[4];
    int scenarioCount;              // +4f8
    char** scenarioMission;         // +4fc
    int* scenarioFixed;             // +500
    char gap504[0x54];
    int scenario_line_offset;       // +558

    void* stringFromID(int id, char* table, int param);
    void fillScenarios();
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

void TribeGameSettingsScreen::fillScenarios()
{
    char file_name[260];
    char scenario_file[260];
    char player_str[20];
    int i;

    this->scenarioList->empty_list();
    this->scenario_line_offset = 0;

    if (rge_base_game->multiplayerGame() || rge_base_game->scenarioGame()) {
        RGE_Scenario_File_Info* info = rge_base_game->scenario_info;
        info->reload_scenarios();
        this->scenarioList->field_15c = 1;
        this->scenarioCount = 0;
        i = 0;
        for (;;) {
            char* name = info->get_scenario_name(i);
            if (name == 0) break;
            int len = 0;
            while (name[len] != 0) ++len;
            len -= 4;
            strncpy(file_name, name, len);
            file_name[len] = 0;
            if (rge_base_game->multiplayerGame() || strcmp(file_name, rge_base_game->scenarioName()) == 0) {
                this->scenarioList->add_line(file_name, i);
                ++this->scenarioCount;
            }
            ++i;
        }
        this->scenarioMission = (char**)calloc(this->scenarioCount, 4);
        this->scenarioFixed = (int*)calloc(this->scenarioCount, 4);
        if (this->scenarioMission == 0 || this->scenarioFixed == 0) goto finish_scenarios;

        i = 0;
        if (this->scenarioCount > 0) {
            do {
                char* list_text = this->scenarioList->get_line_text(i);
                RGE_Scenario_File_Entry* entry = info->get_scenario_info(list_text);
                if (entry != 0) {
                    this->scenarioMission[i] = (char*)calloc(1, 0x1000);
                    if (this->scenarioMission[i] != 0 && entry->title != 0) {
                        char* dst = this->scenarioMission[i];
                        char* src = entry->title;
                        while ((*dst++ = *src++) != 0) {}
                    }
                    this->scenarioFixed[i] = entry->fixed_players;
                    int players = entry->player_count;
                    if (players > 0) {
                        if (this->scenarioFixed[i] == 0 && players >= 3) {
                            sprintf(player_str, "%d - %d", 2, players);
                        } else {
                            sprintf(player_str, "%d", players);
                        }
                        char* text = this->scenarioList->get_line_text(i);
                        this->scenarioList->add_text_line(text, scenario_file, player_str, 0);
                    }
                }
                ++i;
            } while (i < this->scenarioCount);
        }
    }

finish_scenarios:
    this->scenarioList->field_15c = 0;

    if (rge_base_game->multiplayerGame() || (rge_base_game->scenarioGame() && !rge_base_game->isTrial())) {
        char* s = (char*)this->stringFromID(0x25B5, (char*)0x586DE0, -2);
        this->scenarioList->add_line(s, 0);
        --this->scenario_line_offset;
    }
    if (rge_base_game->multiplayerGame() || (rge_base_game->scenarioGame() && rge_base_game->isTrial())) {
        char* s2 = (char*)this->stringFromID(0x2617, (char*)0x586DE0, -1);
        this->scenarioList->add_line(s2, 1);
        --this->scenario_line_offset;
    }
}
