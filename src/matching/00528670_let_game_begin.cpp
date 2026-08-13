// VA: 00528670 TRIBE_Game::let_game_begin (1779 bytes)
// PDB source: tribegam.cpp:4208-4359
//
// Baseline reconstruction: natural game-start logging, typed game/world/music
// ownership, and the final input/chat transition from the original call flow.
//
// Attempt log:
// - Baseline matched size, frame, saved registers, call count, and CFG.
// - Added the complete get_string virtual overload surface. This improved the
//   map-string dispatch and exact block coverage.
// - Corrected TMusic_System fields: music_type is +0x104 and track_count is
//   +0x248. This fixed the music field accesses.
// - Pointer, array-address, and declaration-order probes were codegen
//   duplicates. The remaining drift starts at difficulty-string scheduling.
// - A const MapType return from the same-TU/PDB ABI donor was also a codegen
//   duplicate; restored the natural int helper surface.
// - Ghidra's original-source block shows diff_str initialized to "Unknown"
//   before the difficulty get_string call; testing that missing natural copy.
// - The original mouse gate checks prog_active between mouse_pointer and the
//   window handle; restored that binary-proven condition.
// - Using RGE_Game_World::curr_player at +0x7C and the two binary-proven
//   guards produced an exact 1779-byte match after four new probes.

#include <stdio.h>
#include <string.h>

extern "C" void __cdecl run_log(char* text, int level);
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* window);

class TMusic_System {
public:
    char path[260];
    unsigned char music_type; // +0x104
    char gap_105[3];
    char gap_108[0x140];
    int track_count; // +0x248

    int play_tracks(int track, int track_count, int loop, int unknown1,
                    int unknown2);
    int stop_track();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

class TChat {
public:
    void ClearChat();
    void setInChatGroup(int player, int enabled);
};

class TMousePointer {
public:
    void center();
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[0x3E];
    short curr_player; // +0x7C
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* window, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int update);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int string_id, long param, char* buffer,
                             int size);
    virtual char* get_string(long string_id, char* buffer, int size);
    virtual char* get_string(long string_id);

    char gap_04[0x0C];
    void* prog_window; // +0x10
    char gap_14[0x04];
    int prog_active; // +0x18
    char gap_1C[0x14];
    int random_game; // +0x30
    int random_map; // +0x34
    char gap_38[0x10];
    void* draw_system; // +0x48
    char gap_4C[0x18];
    TMusic_System* music_system; // +0x64
    char gap_68[0x158];
    TMousePointer* mouse_pointer; // +0x1C0
    char gap_1C4[0x230];
    RGE_Game_World* world; // +0x3F4
    char gap_3F8[0x604];
    int auto_paused; // +0x9FC
    char gap_A00[0x24];

    int difficulty();
    int fullVisibility();
    int singlePlayerGame();
    void reset_timings();
    void set_paused(int paused, int update);
    void enable_input();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x1F8];
    int started_menu_music; // +0xC1C

    int mapType();
    int mapSize();
    int victoryType();
    int victoryAmount();
    unsigned char deathMatch();
    int resourceLevel();
    int startingAge();
    int fullTechTree();
    int playerColor(int player);
    int playerTeam(int player);
    int civilization(int player);

    void let_game_begin();
};

extern TPanelSystem panel_system;
extern TChat* chat;

void TRIBE_Game::let_game_begin()
{
    int i;
    char int_str[10];
    char map_type_str[20];
    char map_size_str[20];
    char age_str[256];
    char res_str[256];
    char vic_str[256];
    char str[1024];
    char diff_str[256];

    panel_system.setCurrentPanel("Game Screen", 0);
    panel_system.destroyPanel("Status Screen");
    panel_system.destroyPanel("Multiplayer");
    run_log("game started", 1);

    switch (this->mapType()) {
    case 0:
        this->get_string(0x296A, map_type_str, 0x14);
        break;
    case 1:
        this->get_string(0x296B, map_type_str, 0x14);
        break;
    case 2:
        this->get_string(0x296C, map_type_str, 0x14);
        break;
    case 3:
        this->get_string(0x296D, map_type_str, 0x14);
        break;
    case 4:
        this->get_string(0x296E, map_type_str, 0x14);
        break;
    case 5:
        this->get_string(0x296F, map_type_str, 0x14);
        break;
    case 6:
        this->get_string(0x2970, map_type_str, 0x14);
        break;
    default:
        this->get_string(0x2804, map_type_str, 0x14);
        break;
    }

    switch (this->mapSize()) {
    case 0:
        this->get_string(0x2973, map_size_str, 0x14);
        break;
    case 1:
        this->get_string(0x2974, map_size_str, 0x14);
        break;
    case 2:
        this->get_string(0x2975, map_size_str, 0x14);
        break;
    case 3:
        this->get_string(0x2976, map_size_str, 0x14);
        break;
    case 4:
        this->get_string(0x2977, map_size_str, 0x14);
        break;
    case 5:
        this->get_string(0x2978, map_size_str, 0x14);
        break;
    default:
        this->get_string(0x2804, map_size_str, 0x14);
        break;
    }

    sprintf(str, "    randomgame=%d, randommap=%d, mapsize=%s, maptype=%s",
            this->random_game, this->random_map, map_size_str, map_type_str);
    run_log(str, 0);

    switch (this->victoryType()) {
    case 0:
        strcpy(vic_str, "Default");
        break;
    case 7:
        sprintf(vic_str, "Time(%d)", this->victoryAmount());
        break;
    case 8:
        sprintf(vic_str, "Score(%d)", this->victoryAmount());
        break;
    case 9:
        strcpy(vic_str, "Standard");
        break;
    default:
        strcpy(vic_str, "Unknown");
        break;
    }

    if (this->deathMatch() != 0) {
        strcpy(res_str, "DeathMatch");
    } else {
        switch (this->resourceLevel()) {
        case 0:
            strcpy(res_str, "Default");
            break;
        case 1:
            strcpy(res_str, "Low");
            break;
        case 2:
            strcpy(res_str, "Medium");
            break;
        case 3:
            strcpy(res_str, "High");
            break;
        default:
            strcpy(res_str, "Unknown");
            break;
        }
    }

    switch (this->startingAge()) {
    case 0:
        strcpy(age_str, "Default");
        break;
    case 2:
        strcpy(age_str, "Stone");
        break;
    case 3:
        strcpy(age_str, "Tool");
        break;
    case 4:
        strcpy(age_str, "Bronze");
        break;
    case 5:
        strcpy(age_str, "Iron");
        break;
    default:
        strcpy(age_str, "Unknown");
        break;
    }

    strcpy(diff_str, "Unknown");
    this->get_string(0x2BD0 + this->difficulty(), &diff_str[0], 0x100);
    sprintf(str, "    resources=%s, age=%s, victory=%s, difficulty=%s",
            res_str, age_str, vic_str, diff_str);
    run_log(str, 0);

    sprintf(str, "    fulltech=%d, revealmap=%d", this->fullTechTree(),
            this->fullVisibility());
    run_log(str, 0);

    sprintf(str, "    numplayers=%d", this->world->player_num - 1);
    strcat(str, " players=");
    for (i = 1; i < this->world->player_num; ++i) {
        sprintf(int_str, "%d", this->playerColor(i - 1));
        strcat(str, int_str);
    }

    strcat(str, " teams=");
    for (i = 1; i < this->world->player_num; ++i) {
        sprintf(int_str, "%d", this->playerTeam(i - 1) - 1);
        strcat(str, int_str);
    }

    strcat(str, " civs=");
    for (i = 1; i < this->world->player_num; ++i) {
        sprintf(int_str, "%d ", this->civilization(i - 1));
        strcat(str, int_str);
    }
    run_log(str, 0);

    TMusic_System* music = this->music_system;
    if (music != 0) {
        if (music->music_type == 1) {
            music->play_tracks(5, 0x0E, 1, 0, 0);
        } else if (music->music_type == 2) {
            music->play_tracks(1, music->track_count, 1, 0, 0);
        } else if (music->music_type == 3) {
            music->stop_track();
        }
        this->started_menu_music = 0;
    }

    this->reset_timings();
    this->set_prog_mode(4);
    if (this->singlePlayerGame() == 1) {
        this->set_paused(0, 0);
    }
    this->auto_paused = 0;
    chat->ClearChat();
    chat->setInChatGroup(this->world->curr_player, 1);
    if (this->mouse_pointer != 0 && this->prog_active != 0) {
        if (IsIconic(this->prog_window) == 0) {
            this->mouse_pointer->center();
        }
    }
    this->enable_input();
}
