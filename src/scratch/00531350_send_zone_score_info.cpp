// VA: 00531350 TRIBE_World::send_zone_score_info (877 B)
// PDB source: tworld.cpp lines 1641-1757
// Baseline reconstruction: build the 0x1fc-byte zone message from the world,
// player history, score summaries, game options, and communication state.
// Attempt log:
// - Replaced the packet scaffold with typed period-plausible ownership for the
//   TRIBE_Zone_Info/TRIBE_Game_Options buffers and the five score summaries.
// - Baseline had the exact 15-call multiset but a 0x274 frame and an emitted
//   sparse-switch table beyond the original boundary.  The binary's sparse
//   game-end switch is required: restoring it reaches the exact 877 B size.
// - Polymorphic/flattened world stubs were codegen-neutral.  A saved player
//   array alias and a long-lived player pointer regressed liveness; both were
//   removed.  The binary reloads this->players[player] for the later history
//   phase, so the final source follows those direct reloads.
// - Corrected history rewards to event->world_time (+8), removed an unsupported
//   history-null guard, and modeled the 1-based random-civ/WasKicked accesses
//   against the proven preceding array slots.  These preserve the 15 calls.
// - Final bounded candidate is 877 B/frame 0x270, all 15 calls aligned, and
//   76.54% instruction-shape similarity.  The first remaining source-shape
// - Main-agent audit restored the binary-proven total-score group value 0xff;
//   this is semantically distinct from the diagnostic signed -1 spelling and
//   improved the strict diff from 687 to 402 bytes (77.27% shape), while
//   exposing a remaining two-byte size/frame-home shift.
// - A function-scope typed player-info pointer was codegen-neutral.  Restored
//   its narrower loop lifetime; the first hunk remains the score-field anchor.
// - Switch dispatch for history events moves the clean candidate to 878 B and
//   79.84% shape; the sparse game-end switch then reaches 877 B and 86.75%.
//   Score-relative byte-pointer overlays changed no useful anchor and were
//   rolled back.  The remaining drift is the player-field EBP anchor.
// - Sender audit: direct indexed access to the canonical player record makes
//   VC5 anchor EBP at `score` (`lea [esp+134h]`) instead of `winner`.
//   It reduces the strict diff to 135 bytes, but moves the world-player load
//   and time initialization after the team/outcome stores.  That conflicts
//   with the original fault and store order, so the typed record-pointer
//   baseline remains authoritative.
// - A PDB-supported sparse-switch case order reduces that direct-indexed test
//   to 130 bytes.  It does not recover the sender loop and was not retained.
// - Natural pointer scope, declaration order, assignment order, guarded
//   while/for forms, and history-loop forms did not recover the exact sender.
//   The supported lifetime conclusion is that score must stay live as the
//   loop's address anchor, but the exact source ownership that also preserves
//   later sender scheduling is unresolved.
// - TU audit: canonical nested options, class-form packet records, enum field
//   types, neighboring random-civ/WasKicked ownership, header combinations,
//   inline-depth pragmas, same-TU fill_in_score ordering, and send-donor ABI
//   spellings were codegen-neutral or nonexact.  Default, /Ob1, and /Ob0
//   formed the same VC5 basin; /Oy- and /Oi- broke the frame or prologue.
//   No supported TU context recovered the score anchor, so this baseline stays
//   authoritative.  No context-only variant is retained.
// - Compiler-object audit: the original tworld.obj CodeView record identifies
//   VC5 compiler version 11.00, target Pentium, hardware FPU, and near code/data.
//   Its S_GPROC32 and executable FPO record both give Cb/procedure size 0x3fd,
//   locals 0x270, four saved-register slots, no SEH, and zero parameters.
//   The line table ends at +0x365, while the remaining object bytes are the
//   sparse-switch data.  This is a complete function/object boundary, not a
//   missing PDB range or an inline expansion.
// - CodeView locals are only `index` and `count` (both long at entry -0x270),
//   `info` (TRIBE_Zone_Info at -0x1fc), and nested
//   `TRIBE_Game::TRIBE_Game_Options` (108 bytes at -0x268).  No named block,
//   inline, or player-record temporary appears in CodeView.  This does not
//   rule out an optimized-away temporary.  The exact CodeView record forms and
//   implicit-padding layout were tested; both were byte-neutral.  The pinned
//   VC5 object remains 877 B/frame 0x270 with 15 calls and 151 bytes different.
//   The unresolved EBP score-versus-winner anchor is therefore not explained
//   by the tested ABI, type-size, or PDB-range axes.
// - Source-gate repair: packet classes, TRIBE_Game::TRIBE_Game_Options, and
//   the RGE_Game_World/TRIBE_World base boundary now follow PDB type ownership.
//   The direct call decorations require struct tags for the high-score record
//   and nested options, so those tags preserve the original U-tag ABI.
// - Source-gate repair also restores typed RGE_Player, TRIBE_Player,
//   RGE_Command, TRIBE_History_Info, TRIBE_Game, and communications fields.
//   The typed player-info cursor remains the only packet-record cursor.
//   Grouped checks 097-102 kept 877 B, frame 0x270, 15 ordered calls, and
//   151 differing bytes.  No raw cursor, direct-index packet anchor, or
//   invented aggregate is retained.

#include <string.h>

class RGE_Victory_Conditions {
public:
    long get_victory_points();
};

class RGE_Game_World;
class MouseClickInfo;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;
class RGE_Tile_List_Node;
class Visible_Resource_Manager;
class RGE_Color_Table;
class RGE_Static_Object;
class TRIBE_Player_Tech;
class TribeMainDecisionAIModule;

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node* list;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayerValue; // +0x04
    int pathingAttemptCapValue; // +0x08
    int pathingDelayCapValue; // +0x0c
    int currentUpdatePathingAttemptsValue; // +0x10
    long checksum; // +0x14
    long position_checksum; // +0x18
    long action_checksum; // +0x1c
    unsigned char checksum_created_this_update; // +0x20
    unsigned char gap_21; // +0x21
    short master_object_num; // +0x22
    RGE_Master_Static_Object** master_objects; // +0x24
    RGE_Object_List* objects; // +0x28
    RGE_Object_List* sleeping_objects; // +0x2c
    RGE_Object_List* doppleganger_objects; // +0x30
    RGE_Victory_Conditions* victory_conditions; // +0x34
    RGE_Visible_Map* visible; // +0x38
    RGE_Game_World* world; // +0x3c
    RGE_Doppleganger_Creator* doppleganger_creator; // +0x40
    char* name; // +0x44
    unsigned char type; // +0x48
    unsigned char gap_49; // +0x49
    short id; // +0x4a
    short attribute_num; // +0x4c
    unsigned char gap_4e[2]; // +0x4e
    float* attributes; // +0x50
    unsigned char culture; // +0x54
    unsigned char gap_55[3]; // +0x55
    RGE_Tile_List tile_list; // +0x58
    RGE_Tile_List diam_tile_list; // +0x6c
    unsigned char game_status; // +0x80
    unsigned char resigned; // +0x81
    unsigned char gap_82[2]; // +0x82
    unsigned char* relations; // +0x84
    int unitDiplomacy[9]; // +0x88
    int mutualAlly[9]; // +0xac
    unsigned long mutualExploredMask; // +0xd0
    unsigned long mutualVisibleMask; // +0xd4
    unsigned long nonMutualVisibleMask; // +0xd8
    unsigned long RemoveVisibleBits[9]; // +0xdc
    int allied_LOS_Enable; // +0x100
    unsigned char allied_victory; // +0x104
    unsigned char master_player_id; // +0x105
    unsigned char gap_106[2]; // +0x106
    RGE_Color_Table* color_table; // +0x108
    long tribe_effect; // +0x10c
    Visible_Resource_Manager* VR_List; // +0x110
    float view_x; // +0x114
    float view_y; // +0x118
    short map_x; // +0x11c
    short map_y; // +0x11e
    short selected_start_col; // +0x120
    short selected_start_row; // +0x122
    short selected_end_col; // +0x124
    short selected_end_row; // +0x126
    short replacement_terrain; // +0x128
    short replacement_overlay; // +0x12a
    short replacement_overlay_shape; // +0x12c
    unsigned char gap_12e[2]; // +0x12e
    RGE_Static_Object* selected_obj; // +0x130
    RGE_Static_Object* sel_list[25]; // +0x134
    unsigned long sel_object_properties; // +0x198
    short sel_count; // +0x19c
    unsigned char groups_used[127]; // +0x19e
    unsigned char gap_21d[3]; // +0x21d

    int computerPlayer();
};

class TRIBE_History_Events {
public:
    unsigned char event;
    char gap_01[3];
    long time;
    long world_time;
    TRIBE_History_Events* next;
};

class TRIBE_History_Entry {
public:
    unsigned char population;
};

class TRIBE_History_Info {
public:
    TRIBE_History_Entry* history;
    TRIBE_History_Events* events;
    long number_of_events;
    long number_of_entries;
    long max_number_of_entries;
};

class TRIBE_Player : public RGE_Player {
public:
    TRIBE_Player_Tech* tech_tree; // +0x220
    long fog_update; // +0x224
    long update_count; // +0x228
    long update_history_count; // +0x22c
    long updateCountNeedHelp; // +0x230
    float update_time; // +0x234
    TribeMainDecisionAIModule* playerAI; // +0x238
    char aiStatusInformationValue[256]; // +0x23c
    char aiStatusInformationValue2[256]; // +0x33c
    char aiStatusInformationValue3[256]; // +0x43c
    char aiStatusInformationValue4[256]; // +0x53c
    char aiStatusInformationValue5[256]; // +0x63c
    char aiStatusInformationValue6[256]; // +0x73c
    TRIBE_History_Info* history; // +0x83c
    float ruin_held_time; // +0x840
    float artifact_held_time; // +0x844
};

struct TRIBE_Zone_High_Score_Info {
    long score;
    unsigned char civ;
    char player_name[16];
    unsigned char num_allies;
    unsigned char gap_16[2];
};

class TRIBE_Zone_Player_Info {
public:
    char name[16];
    long score;
    unsigned char winner;
    unsigned char civ_played;
    unsigned char civ_random;
    unsigned char player_no;
    unsigned char team_no;
    unsigned char game_outcome;
    unsigned char gap_1A[2];
    long tool_time;
    long bronze_time;
    long iron_time;
};

class TRIBE_Zone_Map_Info {
public:
    unsigned char Map_Size;
    unsigned char Map_Type;
    short Pop_Limit;
    unsigned char Victory_Condition;
    unsigned char Start_Age;
    unsigned char Resources;
    unsigned char Full_Tech;
    unsigned char Fixed_Pos;
    unsigned char Reveal_Map;
    unsigned char Death_Match;
    unsigned char gap_0B;
};

class TRIBE_Zone_Info {
public:
    unsigned char number_of_players;
    unsigned char number_of_computer_players;
    char scenario_name[32];
    unsigned char gap_22[2];
    unsigned long game_time;
    TRIBE_Zone_High_Score_Info total_score;
    TRIBE_Zone_High_Score_Info religion_score;
    TRIBE_Zone_High_Score_Info economy_score;
    TRIBE_Zone_High_Score_Info combat_score;
    TRIBE_Zone_High_Score_Info research_score;
    TRIBE_Zone_Player_Info player_info[8];
    TRIBE_Zone_Map_Info map_info;
    unsigned char cheats_enabled;
    unsigned char game_end_condition_code;
    unsigned char gap_1EE[2];
    unsigned long database_checksum;
    unsigned long code_checksum;
    unsigned long program_version;
};

class RGE_Base_Game {
public:
    char gap_00[0xa24];
    int allowCheatCodes();
    int fullVisibility();
    int playerTeam(int player);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    enum MapSize {
        MapSize_0 = 0
    };
    enum MapType {
        MapType_0 = 0
    };
    enum VictoryType {
        VictoryType_0 = 0
    };
    enum ResourceLevel {
        ResourceLevel_0 = 0
    };
    enum Age {
        Age_0 = 0
    };

    struct TRIBE_Game_Options {
    public:
        MapSize mapSizeValue;
        MapType mapTypeValue;
        int animalsValue;
        int predatorsValue;
        VictoryType victoryTypeValue;
        int victoryAmountValue;
        unsigned char civilizationValue[9];
        unsigned char gap_21[3];
        int scenarioPlayerValue[9];
        unsigned char playerColorValue[9];
        unsigned char computerNameValue[9];
        unsigned char allowTradingValue;
        unsigned char longCombatValue;
        unsigned char randomizePositionsValue;
        unsigned char fullTechTreeValue;
        unsigned char gap_5E[2];
        ResourceLevel resourceLevelValue;
        Age startingAgeValue;
        unsigned char startingUnitsValue;
        unsigned char deathMatchValue;
        unsigned char popLimitValue;
        unsigned char gap_6B;
    };

    MouseClickInfo* MouseRightClickTable; // +0xa24
    int MouseRightClickTableSize; // +0xa28
    MouseClickInfo* MouseLeftClickTable; // +0xa2c
    int MouseLeftClickTableSize; // +0xa30
    long queue_is_waiting_on_pop_counter[9]; // +0xa34
    int random_civ[9];
    TRIBE_Game_Options tribe_game_options; // +0xa7c

    int civilization(int player);
    int playerColor(int player);
    void get_tribe_options(struct TRIBE_Game_Options* options);
};

class RGE_Scenario {
public:
    char gap_00[0x1010];
    char* Get_scenario_name();
};

class TCommunications_Handler {
public:
    char gap_00[0x1748];
    int HoldCount; // +0x1748
    int WasKicked[10];

    int SendZoneMessage(char* message, unsigned long length);
};

class RGE_Command {
public:
    void* vtable_ptr; // +0x00
    RGE_Game_World* world; // +0x04
    unsigned char* last_order; // +0x08
    long last_order_size; // +0x0c
    long last_order_time; // +0x10
    TCommunications_Handler* com_hand; // +0x14
};

class RGE_Map;
class RGE_Sound;
class RGE_Sprite;
class RGE_Master_Player;
class RGE_Effects;
class RGE_Color_Table;
class TSound_Driver;
class RGE_Static_Object;
class RGE_Player_Info;
class AIPlayBook;
class TRIBE_Tech;

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    virtual unsigned char data_load_terrain_tables(char* file);
    virtual unsigned char data_load_players(char* file);
    virtual unsigned char data_load_objects(char* file);
    virtual unsigned char data_load_sounds(char* file);
    virtual unsigned char data_load_color_tables(char* file);
    virtual unsigned char data_load_sprites(char* file);
    virtual void data_load_players_type(short player_type, short player_count,
        void* file);
    virtual void data_load_effects(char* file);
    virtual void data_load_map(char* map, char* terrain, char* zones,
        char* objects, short width, short height, short tile_size,
        RGE_Sound** sounds, char* file);
    virtual void data_load_random_map(char* map, char* terrain, char* zones,
        char* objects);
    virtual unsigned char init_player_type(int player, short type,
        unsigned char computer);
    virtual unsigned char init_player(int player);
    virtual void load_player(int player, unsigned char type, short color);
    virtual void color_table_init(int handle);
    virtual void terrain_tables_init(int handle);
    virtual void init_sounds(int handle, TSound_Driver* driver);
    virtual void init_sprites(int handle);
    virtual void map_init(int handle, TSound_Driver* driver);
    virtual void effects_init(int handle);
    virtual void master_player_init(int handle);
    virtual void command_init(int handle, TCommunications_Handler* handler);
    virtual void world_init(int handle, TSound_Driver* driver,
        TCommunications_Handler* handler);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info* player_info);
    virtual unsigned char new_random_game(RGE_Player_Info* player_info);
    virtual void save(int handle);
    virtual void scenario_make_player(short player, unsigned char type,
        unsigned char civ, unsigned char team, char* name);
    virtual void scenario_make_map(int handle);
    virtual unsigned char load_scenario(RGE_Player_Info* player_info);
    virtual unsigned char load_scenario(char* file, RGE_Player_Info* player_info);
    virtual void load_scenario1(int handle, RGE_Player_Info* player_info);
    virtual void load_scenario2(int handle, RGE_Player_Info* player_info);
    virtual void load_scenario3(int handle, RGE_Player_Info* player_info);
    virtual void load_scenario4(int handle, RGE_Player_Info* player_info);
    virtual void load_scenario5(int handle, RGE_Player_Info* player_info);
    virtual void load_scenario6(int handle, RGE_Player_Info* player_info);
    virtual void load_scenario7(int handle, RGE_Player_Info* player_info);
    virtual void load_scenario8(int handle, RGE_Player_Info* player_info);
    virtual void logStatus(void* stream, int verbose);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info* player_info);
    virtual unsigned char data_load(char* file, char* mode);
    virtual unsigned char init(char* file, TSound_Driver* driver,
        TCommunications_Handler* handler);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int handle);
    virtual unsigned char load_game(char* file);
    virtual unsigned char new_game(RGE_Player_Info* player_info, int mode);
    virtual unsigned char new_scenario(RGE_Player_Info* player_info, int mode);
    virtual unsigned char save_game(char* file);
    virtual void base_save(char* file);
    virtual void base_save(int handle);
    virtual unsigned char save_scenario(char* file);
    virtual RGE_Scenario* get_scenario_info(char* file);
    virtual void pause(unsigned char paused);
    virtual void scenario_init(RGE_Game_World* world);
    virtual void scenario_init(int handle, RGE_Game_World* world);
    virtual int addObject(RGE_Static_Object* object);
    virtual int removeObject(int object_id);

    unsigned long world_time; // +0x04
    unsigned long old_world_time; // +0x08
    unsigned long world_time_delta; // +0x0c
    float timer; // +0x10
    unsigned long old_time; // +0x14
    float game_speed; // +0x18
    unsigned char temp_pause; // +0x1c
    unsigned char game_state; // +0x1d
    unsigned char game_end_condition; // +0x1e
    unsigned char gap_1f; // +0x1f
    long sound_update_index; // +0x20
    long sprite_update_index; // +0x24
    RGE_Map* map; // +0x28
    short sound_num; // +0x2c
    unsigned char gap_2e[2]; // +0x2e
    RGE_Sound** sounds; // +0x30
    short sprite_num; // +0x34
    unsigned char gap_36[2]; // +0x36
    RGE_Sprite** sprites; // +0x38
    short player_num; // +0x3c
    unsigned char gap_3e[2]; // +0x3e
    RGE_Player** players; // +0x40
    short master_player_num; // +0x44
    unsigned char gap_46[2]; // +0x46
    RGE_Master_Player** master_players; // +0x48
    RGE_Effects* effects; // +0x4c
    short terrain_num; // +0x50
    short terrain_size; // +0x52
    float** terrains; // +0x54
    RGE_Command* commands; // +0x58
    RGE_Scenario* scenario; // +0x5c
    short color_table_num; // +0x60
    unsigned char gap_62[2]; // +0x62
    RGE_Color_Table** color_tables; // +0x64
    long next_object_id; // +0x68
    long next_reusable_object_id; // +0x6c
    long scenario_object_id; // +0x70
    unsigned char scenario_object_flag; // +0x74
    unsigned char gap_75[3]; // +0x75
    unsigned int random_seed; // +0x78
    short curr_player; // +0x7c
    unsigned char gap_7e[2]; // +0x7e
    TSound_Driver* sound_driver; // +0x80
    float world_time_delta_seconds; // +0x84
    RGE_Static_Object** objectsValue; // +0x88
    int numberObjectsValue; // +0x8c
    int maxNumberObjectsValue; // +0x90
    RGE_Static_Object** negativeObjectsValue; // +0x94
    int numberNegativeObjectsValue; // +0x98
    int maxNumberNegativeObjectsValue; // +0x9c
    AIPlayBook* playbook; // +0xa0
    long campaign; // +0xa4
    long campaign_player; // +0xa8
    long campaign_scenario; // +0xac
    int player_turn; // +0xb0
    unsigned long player_time_delta[9]; // +0xb4
    RGE_Object_List* reusable_static_objects; // +0xd8
    RGE_Object_List* reusable_animated_objects; // +0xdc
    RGE_Object_List* reusable_moving_objects; // +0xe0
    RGE_Object_List* reusable_action_objects; // +0xe4
    RGE_Object_List* reusable_combat_objects; // +0xe8
    RGE_Object_List* reusable_missile_objects; // +0xec
    RGE_Object_List* reusable_doppleganger_objects; // +0xf0
    unsigned long maximumComputerPlayerUpdateTime; // +0xf4
    unsigned long availableComputerPlayerUpdateTime; // +0xf8
    int currentUpdateComputerPlayer; // +0xfc
    int difficultyLevelValue; // +0x100
};

class TRIBE_World : public RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    TRIBE_Tech* tech; // +0x104
    int victory_type; // +0x108
    int artifact_count; // +0x10c
    int ruin_count; // +0x110
    unsigned char countdown_victory; // +0x114
    unsigned char gap_115[3]; // +0x115
    float countdown_clock; // +0x118
    unsigned char score_displayed; // +0x11c
    unsigned char controllingComputerPlayer; // +0x11d
    unsigned char gap_11e[2]; // +0x11e
    int sent_zone_score; // +0x120

    void fill_in_score(struct TRIBE_Zone_High_Score_Info& info, long group);
    void send_zone_score_info();
};

extern TRIBE_Game* rge_base_game;
extern TCommunications_Handler* comm;

void TRIBE_World::send_zone_score_info()
{
    TRIBE_Zone_Info info;
    TRIBE_Game::TRIBE_Game_Options options;
    int computer_players = 0;
    int player;

    if (this->sent_zone_score == 0) {
        this->sent_zone_score = 1;
        info.number_of_players = 0;
        computer_players = 0;
        player = 1;
        if (player < this->player_num) {
            do {
                if (this->players[player]->computerPlayer() == 0)
                    info.number_of_players++;
                else
                    computer_players++;
                player++;
            } while (player < this->player_num);
        }
        info.number_of_computer_players = (unsigned char)computer_players;

        strcpy(info.scenario_name, this->scenario->Get_scenario_name());
        info.game_time = this->world_time / 1000;

        this->fill_in_score(info.total_score, 0xFF);
        this->fill_in_score(info.religion_score, 2);
        this->fill_in_score(info.economy_score, 1);
        this->fill_in_score(info.combat_score, 0);
        this->fill_in_score(info.research_score, 3);

        player = 1;
        if (player < this->player_num) {
            TRIBE_Zone_Player_Info* player_info = info.player_info;
            do {
                strcpy(player_info->name, this->players[player]->name);
                player_info->score =
                    this->players[player]->victory_conditions->get_victory_points();
                player_info->winner = (this->players[player]->game_status == 1);
                player_info->civ_played =
                    (unsigned char)rge_base_game->civilization(player - 1);
                player_info->civ_random =
                    (unsigned char)rge_base_game->random_civ[player - 1];
                player_info->player_no =
                    (unsigned char)rge_base_game->playerColor(player - 1);
                player_info->team_no =
                    (unsigned char)rge_base_game->playerTeam(player - 1);
                player_info->game_outcome =
                    (unsigned char)comm->WasKicked[player - 1];
                player_info->tool_time = -1;
                player_info->bronze_time = -1;
                player_info->iron_time = -1;

                TRIBE_History_Events* event =
                    ((TRIBE_Player*)this->players[player])->history->events;
                while (event != 0) {
                    switch (event->event) {
                    case 0:
                        player_info->tool_time = event->world_time;
                        break;
                    case 1:
                        player_info->bronze_time = event->world_time;
                        break;
                    case 2:
                        player_info->iron_time = event->world_time;
                        break;
                    }
                    event = event->next;
                }

                player++;
                player_info++;
            } while (player < this->player_num);
        }

        info.cheats_enabled = (unsigned char)rge_base_game->allowCheatCodes();
        switch (this->game_end_condition) {
        case 0:
            info.game_end_condition_code = 0;
            break;
        case 1:
            info.game_end_condition_code = 1;
            break;
        case 2:
            info.game_end_condition_code = 6;
            break;
        case 100:
            info.game_end_condition_code = 2;
            break;
        case 101:
            info.game_end_condition_code = 3;
            break;
        case 102:
            info.game_end_condition_code = 4;
            break;
        case 103:
            info.game_end_condition_code = 5;
            break;
        case 104:
            info.game_end_condition_code = 7;
            break;
        default:
            info.game_end_condition_code = 8;
            break;
        }

        rge_base_game->get_tribe_options(&options);
        info.map_info.Map_Size = (unsigned char)options.mapSizeValue;
        info.map_info.Map_Type = (unsigned char)options.mapTypeValue;
        info.map_info.Pop_Limit = (short)options.popLimitValue;
        info.map_info.Victory_Condition = (unsigned char)options.victoryTypeValue;
        info.map_info.Start_Age = (unsigned char)options.startingAgeValue;
        info.map_info.Resources = (unsigned char)options.resourceLevelValue;
        info.map_info.Full_Tech = options.fullTechTreeValue;
        info.map_info.Fixed_Pos = options.randomizePositionsValue;
        info.map_info.Reveal_Map = (unsigned char)rge_base_game->fullVisibility();
        info.map_info.Death_Match = options.deathMatchValue;

        info.database_checksum = 0;
        info.code_checksum = 0;
        info.program_version = 0;

        this->commands->com_hand->SendZoneMessage((char*)&info, 0x1fc);
    }
}
