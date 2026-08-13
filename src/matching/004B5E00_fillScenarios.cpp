// VA: 004B5E00 TribeGameSettingsScreen::fillScenarios
// Attempt log:
// - Prior scratch candidate used guessed add_line/get_line_text/add_text_line and
//   fake stringFromID surfaces; it was 83 bytes too small with broad call drift.
// - Binary evidence establishes TTextPanel::append_line(char*,long),
//   get_id(long), get_text(long), change_line(long,char*,char*,long), and the
//   four-argument insert_line used by the two special rows.
// - Binary evidence also establishes RGE_Scenario_File_Info::get_scenario_info
//   takes the list id, and the special rows use TPanel::get_string(int) plus
//   the natural "2 - 8" label.  This pass restores those canonical surfaces.
// - SA60574_fill: the typed pass reached the correct 0x224 frame and 28/29
//   call topology; remaining drift is the first scan's VC5 loop rotation,
//   stack-buffer +4 placement, and broad late block spans. Alternate while,
//   for, do/while, explicit-label, initialization-order, and local-order
//   forms were codegen duplicates. Kept the ordinary while source below.
// - shardC5-4B5E00: tested a natural for-header guard/increment to remove the
//   rebuilt extra get_scenario_name site; VC5 emitted the same 29-call code,
//   so restored the ordinary while reconstruction.
// - orch-4B5E00-a: used the same-TU donor's explicit body call and break; this
//   restored the original single get_scenario_name site and exact CFG/size.
// - orch-4B5E00-a: removed decompiler-only +4 biases from all three buffers;
//   the natural buffer bases produce an exact 864-byte match.

extern "C" char* strncpy(char* dst, const char* src, unsigned int count);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" unsigned int strlen(const char* src);
extern "C" int strcmp(const char* left, const char* right);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" void* calloc(unsigned int count, unsigned int size);

class RGE_Scenario_Header {
public:
    char gap_00[0x10];
    char* description;       // +0x10
    int fixed_players;       // +0x14
    int player_count;        // +0x18
};

class RGE_Scenario_File_Info {
public:
    void reload_scenarios();
    char* get_scenario_name(int index);
    RGE_Scenario_Header* get_scenario_info(int index);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[4];
    RGE_Scenario_File_Info* scenario_info; // +0x08

    int multiplayerGame();
    int scenarioGame();
    int randomGame();
    char* scenarioName();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    unsigned char deathMatch();
};

extern TRIBE_Game* rge_base_game;

class TextNode {
public:
    char gap_00[8];
    long id;
    TextNode* next;
};

class TTextPanel {
public:
    char gap_00[0xF4];
    TextNode* list;           // +0xF4
    short num_lines;          // +0xF8
    char gap_FA[0x62];
    int sorted;               // +0x15C

    void empty_list();
    int append_line(char* text, long value);
    long get_id(long index);
    char* get_text(long index);
    int insert_line(long line, char* text1, char* text2, long value);
    int change_line(long line, char* text1, char* text2, long value);
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
    char* get_string(int id);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
};

class TribeGameSettingsScreen : public TEasy_Panel {
public:
    char gap_478[0x78];
    TTextPanel* scenarioList;       // +0x4F0
    char gap_4F4[4];
    int scenarioCount;              // +0x4F8
    char** scenarioMission;         // +0x4FC
    int* scenarioFixed;             // +0x500
    char gap_504[0x54];
    int scenario_line_offset;       // +0x558

    void fillScenarios();
};

void TribeGameSettingsScreen::fillScenarios()
{
    RGE_Scenario_File_Info* info;
    char* name;
    int i;
    int len;
    char player_str[20];
    char file_name[260];
    char scenario_file[260];

    this->scenarioList->empty_list();
    this->scenario_line_offset = 0;

    if (rge_base_game->multiplayerGame() || rge_base_game->scenarioGame()) {
        info = rge_base_game->scenario_info;
        info->reload_scenarios();
        i = 0;
        this->scenarioList->sorted = 1;
        this->scenarioCount = 0;
        while (1) {
            name = info->get_scenario_name(i);
            if (name == 0) {
                break;
            }
            len = (int)strlen(name) - 4;
            strncpy(file_name, name, len);
            file_name[len] = 0;

            if (rge_base_game->multiplayerGame() ||
                strcmp(file_name, rge_base_game->scenarioName()) == 0) {
                this->scenarioList->append_line(file_name, i);
                this->scenarioCount++;
            }
            i++;
        }

        this->scenarioMission = (char**)calloc(this->scenarioCount, 4);
        this->scenarioFixed = (int*)calloc(this->scenarioCount, 4);

        if (this->scenarioMission != 0 && this->scenarioFixed != 0) {
            i = 0;
            if (this->scenarioCount > 0) {
                do {
                    RGE_Scenario_Header* entry =
                        info->get_scenario_info(this->scenarioList->get_id(i));
                    if (entry != 0) {
                        this->scenarioMission[i] = (char*)calloc(0x1000, 1);
                        if (this->scenarioMission[i] != 0 &&
                            entry->description != 0) {
                            strcpy(this->scenarioMission[i], entry->description);
                        }

                        this->scenarioFixed[i] = entry->fixed_players;
                        int players = entry->player_count;
                        if (players > 0) {
                            if (this->scenarioFixed[i] == 0 && players >= 3) {
                                sprintf(player_str, "%d - %d", 2, players);
                            } else {
                                sprintf(player_str, "%d", players);
                            }
                            strcpy(scenario_file,
                                   this->scenarioList->get_text(i));
                            this->scenarioList->change_line(
                                i, scenario_file, player_str, 0);
                        }
                    }
                    i++;
                } while (i < this->scenarioCount);
            }
        }
    }

    this->scenarioList->sorted = 0;

    if (rge_base_game->multiplayerGame() ||
        (rge_base_game->randomGame() &&
         ((TRIBE_Game*)rge_base_game)->deathMatch() == 0)) {
        this->scenarioList->insert_line(
            0, this->get_string(0x25B5), "2 - 8", -2);
        this->scenario_line_offset--;
    }

    if (rge_base_game->multiplayerGame() ||
        (rge_base_game->randomGame() &&
         ((TRIBE_Game*)rge_base_game)->deathMatch() != 0)) {
        this->scenarioList->insert_line(
            1, this->get_string(0x2617), "2 - 8", -1);
        this->scenario_line_offset--;
    }
}
