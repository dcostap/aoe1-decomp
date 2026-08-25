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
//   The typed 0x28 player record remains the only packet-record ownership
//   surface.  Grouped checks 097-102 kept the old 151-byte frontier.
// - Exact transition: direct indexing of the typed 0x28 player records selects
//   the original score-field address anchor.  A local int preserves the proven
//   dword WasKicked load and the world-base load before the team store.
// - Exact transition also follows the PDB handler order for game-end case 2
//   and the PDB map-option statement order.  These changes preserve all field
//   mappings, fault order, and the 15 direct calls.
// - Exact walkback kept the local event declaration, loop form, and int
//   temporary reductions.  It rejected the pointer record alias, numeric case
//   order, direct WasKicked byte read, and struct-order map stores.
//   The final source is 877 B, frame 0x270, and MATCH with 0.0000% difference.
// - Full-file source gate: replaced decompiler gap fields with natural VC5
//   padding, restored named PDB fields for the player, world, game, command,
//   history, scenario, victory, and communications records, and restored
//   RGE_Base_Game/TRIBE_Game and RGE_Game_World/TRIBE_World ownership.  The
//   canonical nested options and communications records retain their proven
//   sizes.  FILE, HWND, and other Windows types replace generic file/window
//   pointers.  The only remaining void* is the PDB-backed generic RGE_Command
//   virtual parameter.  Grouped source-gate checks remain exact.

#include <string.h>
#include <stdio.h>
#include <windows.h>

class RGE_Player;
class RGE_Victory_Entry;
class RGE_Victory_Point_Entry;

#ifndef TWORLD_PHASE2_CONTEXT
class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    RGE_Victory_Entry* victory_list;
    long list_num;
    RGE_Player* player;
    unsigned char victory;
    RGE_Victory_Point_Entry* victory_point_list;
    long point_list_num;
    long tot_victory_points;
    long get_victory_points();
};
#endif

class RGE_Game_World;
class RGE_Timeline;
class RGE_Command_Give_Attribute;
class TRIBE_Screen_Game;
class TCommunications_Handler;
class MouseClickInfo;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;
class RGE_Tile_List_Node;
class Visible_Resource_Manager;
class RGE_Color_Table;
class RGE_Static_Object;
class TPicture;
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

#ifndef TWORLD_PHASE2_CONTEXT
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
    short id; // +0x4a
    short attribute_num; // +0x4c
    float* attributes; // +0x50
    unsigned char culture; // +0x54
    RGE_Tile_List tile_list; // +0x58
    RGE_Tile_List diam_tile_list; // +0x6c
    unsigned char game_status; // +0x80
    unsigned char resigned; // +0x81
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
    RGE_Static_Object* selected_obj; // +0x130
    RGE_Static_Object* sel_list[25]; // +0x134
    unsigned long sel_object_properties; // +0x198
    short sel_count; // +0x19c
    unsigned char groups_used[127]; // +0x19e

    int computerPlayer();
};
#endif

class TRIBE_History_Events {
public:
    unsigned char event;
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

#ifndef TWORLD_PHASE2_CONTEXT
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
#endif

#ifndef TWORLD_PHASE2_CONTEXT
struct TRIBE_Zone_High_Score_Info {
    long score;
    unsigned char civ;
    char player_name[16];
    unsigned char num_allies;
};
#endif

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
};

class TRIBE_Zone_Info {
public:
    unsigned char number_of_players;
    unsigned char number_of_computer_players;
    char scenario_name[32];
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
    unsigned long database_checksum;
    unsigned long code_checksum;
    unsigned long program_version;
};

class RGE_Game_Info;
class RGE_Scenario_File_Info;
class RGE_Prog_Info;
class TDrawSystem;
class TDrawArea;
class TShape;
class TSound_Driver;
class TMusic_System;
class TDigital;
class TDebuggingLog;
class TRegistry;
class TMousePointer;
class RGE_Font;

class RGE_Timing_Info {
public:
    unsigned long accum_time;
    unsigned long last_time;
    unsigned long start_time;
    int include_in_total;
    int is_summary;
    unsigned long last_single_time;
    unsigned long max_time;
    unsigned long last_max_time;
};

#ifndef TWORLD_PHASE2_CONTEXT
class RGE_Base_Game {
public:
    class RGE_Game_Options {
    public:
        float versionValue;
        unsigned char scenarioGameValue;
        char scenarioNameValue[128];
        unsigned char singlePlayerGameValue;
        unsigned char multiplayerGameValue;
        unsigned char mapXSizeValue;
        unsigned char mapYSizeValue;
        unsigned char mapZSizeValue;
        unsigned char allowCheatCodesValue;
        unsigned char mpPathFindingValue;
        unsigned char cheatNotificationValue;
        unsigned char fullVisibilityValue;
        unsigned char fogOfWarValue;
        unsigned char coloredChatValue;
        unsigned char numberPlayersValue;
        unsigned char gameDeveloperModeValue;
        unsigned char playerCDAndVersionValue[9];
        unsigned char difficultyValue;
        unsigned char playerTeamValue[9];
    };

    virtual ~RGE_Base_Game();

    RGE_Game_Info* player_game_info;
    RGE_Scenario_File_Info* scenario_info;
    RGE_Prog_Info* prog_info;
    HWND prog_window;
    int prog_ready;
    int prog_active;
    HPALETTE prog_palette;
    HANDLE prog_mutex;
    long window_style;
    int random_game_seed;
    int random_map_seed;
    int save_random_game_seed;
    int save_random_map_seed;
    int screen_saver_enabled;
    int low_power_enabled;
    int error_code;
    int is_timer;
    TDrawSystem* draw_system;
    TDrawArea* draw_area;
    unsigned char outline_type;
    int custom_mouse;
    short shape_num;
    TShape** shapes;
    TSound_Driver* sound_system;
    TMusic_System* music_system;
    short sound_num;
    TDigital** sounds;
    unsigned char save_music_type;
    int save_music_track_from;
    int save_music_track_to;
    int save_music_cur_track;
    char save_music_file[260];
    int save_music_loop;
    unsigned long save_music_pos;
    TCommunications_Handler* comm_handler;
    int comm_syncstop;
    int comm_droppackets;
    int comm_syncmsg;
    int comm_stepmode;
    int comm_speed;
    TDebuggingLog* debugLog;
    int log_comm;
    TRegistry* registry;
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    int paused;
    TMousePointer* mouse_pointer;
    int erase_mouse;
    int mouse_blit_sync;
    int is_mouse_on;
    int windows_mouse;
    HCURSOR mouse_cursor;
    int input_enabled;
    HWND input_disabled_window;
    short font_num;
    RGE_Font* fonts;
    char work_dir[261];
    char string_dll_name[261];
    RGE_Game_World* world;
    int render_all;
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;
    char timing_text[256];
    unsigned long frame_count;
    unsigned long world_update_count;
    unsigned long view_update_count;
    unsigned long last_frame_count;
    unsigned long last_world_update_count;
    unsigned long last_view_update_count;
    unsigned long fps;
    unsigned long world_update_fps;
    unsigned long view_update_fps;
    RGE_Timing_Info timings[30];
    int do_show_timings;
    int do_show_comm;
    int do_show_ai;
    unsigned long last_view_time;
    RGE_Game_Options rge_game_options;
    int campaignGameValue;
    int savedGameValue;
    int quick_build;
    int save_check_for_cd;
    int playerIDValue[9];
    int display_selected_ids;
    long countdown_timer[9];
    int auto_paused;
    int save_paused;
    int non_user_pause;
    int rollover;
    float game_speed;
    int single_player_difficulty;
    unsigned char pathFindingValue;
    unsigned char resigned[9];
    TDrawArea* map_save_area;

    int allowCheatCodes();
    int fullVisibility();
    int playerTeam(int player);
};
#endif

#ifndef TWORLD_PHASE2_CONTEXT
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
        int scenarioPlayerValue[9];
        unsigned char playerColorValue[9];
        unsigned char computerNameValue[9];
        unsigned char allowTradingValue;
        unsigned char longCombatValue;
        unsigned char randomizePositionsValue;
        unsigned char fullTechTreeValue;
        ResourceLevel resourceLevelValue;
        Age startingAgeValue;
        unsigned char startingUnitsValue;
        unsigned char deathMatchValue;
        unsigned char popLimitValue;
    };

    MouseClickInfo* MouseRightClickTable; // +0xa24
    int MouseRightClickTableSize; // +0xa28
    MouseClickInfo* MouseLeftClickTable; // +0xa2c
    int MouseLeftClickTableSize; // +0xa30
    long queue_is_waiting_on_pop_counter[9]; // +0xa34
    int random_civ[9];
    TRIBE_Game_Options tribe_game_options; // +0xa7c
    char testing_scenario[260];
    HWND video_window;
    int cur_video;
    WNDPROC old_video_wnd_proc;
    int video_paused;
    unsigned long last_video_time;
    int video_setup;
    int video_double_size;
    int video_changed_res;
    int video_hi_color;
    long video_save_res_wid;
    long video_save_res_hgt;
    HPALETTE video_save_palette;
    int started_menu_music;
    int show_object_id;
    TRIBE_Screen_Game* game_screen;
    long notification_loc_x[5];
    long notification_loc_y[5];
    long current_notification_loc;
    long current_notification_recalled;
    char startup_scenario[260];
    char startup_game[260];
    unsigned long auto_exit_time;
    char save_game_name[260];
    char load_game_name[260];
    char timing_text2[256];
    int save_humanity[9];
    unsigned char quick_start_game;
    int random_start_value;
    unsigned char computerNameUsed[18][10];
    HANDLE handleIdleLock;
    int inHandleIdle;

    int civilization(int player);
    int playerColor(int player);
    void get_tribe_options(struct TRIBE_Game_Options* options);
};
#endif

class PlayerName {
public:
    char Name[256];
};

#ifndef TWORLD_PHASE2_CONTEXT
class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int object_id);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int file);

    RGE_Timeline* time_line;
    RGE_Game_World* world;
    unsigned char victory_conquest;
    PlayerName player_name[16];
    char* scenario_name;
    char* description;
    char* hints;
    char* win_message;
    char* loss_message;
    char* historicle_notes;
    char TempText1[224];
    char TempText2[224];
    char TempText3[224];
    char* BuildList[16];
    char* CityPlan[16];
    char* AiRules[16];
    unsigned char* BuildListFile[16];
    unsigned char* CityPlanFile[16];
    unsigned char* AiRulesFile[16];
    int BuildListFileSize[16];
    int CityPlanFileSize[16];
    int AiRulesFileSize[16];
    char Cine_PreGame[224];
    char Cine_Victory[224];
    char Cine_Loss[224];
    char Mission_Bmp[224];
    float Version;
    int PlayerPosture[16];
    int PlType[16];
    int PlCivilization[16];
    int PlActive[16];
    TPicture* mission_picture;

    char* Get_scenario_name();
};
#endif

class TChat;
class NAME;
class RGE_Communications_Queue;
class RGE_Lobby;
class RGE_TimeSinceLastCall;
class RGE_Communications_Speed;
class RGE_Communications_Synchronize;
class RGE_Communications_Addresses;
class RGE_Comm_Error;
class RESENDER;
class HOLDER;

typedef int COMMSTATUS;
typedef int COMMSTATES;
typedef int PLAYERHUMANITY;

class COMMPLAYEROPTIONS {
public:
    unsigned char NeedsToBeSent;
    unsigned long LastSentTime;
    COMMSTATES ProgramState;
    unsigned long CurrentTurn;
    unsigned char TurnSpeedMsec;
    unsigned long dcoID[10];
    unsigned long AcknowledgeAfterMsec;
    unsigned char CommandTurnIncrement;
    int PlayerReady[10];
    unsigned long User1[10];
    unsigned long User2[10];
    unsigned long User3[10];
    unsigned long User4[10];
    unsigned long User5[10];
    unsigned long User6[10];
    unsigned long User7[10];
    PLAYERHUMANITY Humanity[10];
    unsigned char InvalidPlayer[10];
    unsigned long Initialized;
    unsigned long RandomSeed;
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    unsigned int HostPlayerNumber;
    int GameHasStarted;
    unsigned long DataSizeToFollow;
};

#ifndef TWORLD_PHASE2_CONTEXT
class TCommunications_Handler {
public:
    int OptionsChanged;
    char* OptionsData;
    int Steps;
    unsigned long TickStart;
    unsigned long TickCount;
    unsigned long TimeSinceLastCall;
    TChat* Chat;
    int MeHost;
    int HaveHostInit;
    char InCommBuff[4001];
    char TBuff[257];
    unsigned long current_turn;
    unsigned long next_command_turn;
    unsigned int sequence;
    long WaitOnPlayer;
    unsigned long TurnSpeedMsec;
    unsigned long AcknowledgeAfterMsec;
    unsigned int Me;
    int Multiplayer;
    int OutOfSyncFlag;
    unsigned long dwStopTime;
    float lastRXDataRate;
    float lastTXDataRate;
    char MyFriendlyName[129];
    char MyFormalName[129];
    char MyGameTitle[129];
    unsigned long CurrentPlayers;
    int previous_last_world_random;
    int last_world_random;
    int StepMode;
    unsigned long turnstart;
    unsigned long lastcalltick;
    unsigned long mselapsed;
    int AvgTurnTime;
    int SkipFrames;
    int PauseChangePending;
    unsigned long CommunicationsVersionCode;
    int ShuttingDown;
    unsigned long ReturnElapsed;
    unsigned long ReturnRXPacketSize;
    unsigned long ReturnTXPacketSize;
    unsigned long RXPacketLength;
    unsigned long RXPacketLengthHigh;
    unsigned long TXPacketLength;
    unsigned long TXPacketLengthHigh;
    NAME* FriendlyName;
    NAME* FormalName;
    unsigned long LastTimeoutMessageTime;
    COMMSTATUS CommunicationsStatus;
    unsigned short MaxGamePlayers;
    _GUID ServiceGUID;
    _GUID ApplicationGUID;
    _GUID SessionGUID;
    HWND HostHWND;
    int LobbyLaunched;
    unsigned long MaxReceiveLatency;
    _GUID NullGUID;
    unsigned long ResendAcknowledgements;
    unsigned long ResentToOther;
    unsigned long DroppedPacketCount;
    unsigned long RXPackets;
    unsigned long TXPackets;
    int IAmLagging;
    unsigned long ServiceTimeout;
    unsigned long LastPlayerCommunication[10];
    unsigned long LastPlayerWarning[10];
    unsigned long LastTXPing[10];
    unsigned long PlayerStopTurn[10];
    unsigned int LastSerialRequestedTX[10];
    unsigned long LastRequestHonoredTX[10];
    unsigned int LastSerialRepliedTX[10];
    unsigned long LastRequestRepliedTX[10];
    unsigned long dwFlags;
    unsigned long dwMaxBufferSize;
    unsigned long dwMaxQueueSize;
    unsigned long dwMaxPlayers;
    unsigned long dwHundredBaud;
    unsigned long dwLatency;
    int Kicked[10];
    RGE_Communications_Queue* InQ;
    RGE_Communications_Queue* OutQ;
    RGE_Lobby* Lobby;
    RGE_TimeSinceLastCall* tslc;
    RGE_Communications_Speed* Speed;
    RGE_Communications_Synchronize* Sync;
    RGE_Communications_Addresses* Addresses;
    RGE_Comm_Error* Err;
    unsigned int GTDSerialNo;
    unsigned int HighResendStore;
    unsigned int DestMap[10];
    unsigned char RGE_Guaranteed_Delivery;
    int IntentionallyDropPackets;
    unsigned int WaitingForAck;
    RESENDER* Resend;
    HOLDER* OnHold;
    unsigned int PlayerHighSerialNumber[10];
    COMMPLAYEROPTIONS PlayerOptions;
    unsigned long LastTurnAck[10];
    unsigned int HoldCount;
    int WasKicked[10];

    int SendZoneMessage(char* message, unsigned long length);
};
#endif

class RGE_Command {
public:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* command);
    virtual ~RGE_Command();
    virtual void do_command(void* command);
    virtual void command_give_attribute(int player, int attribute,
        int amount, float value);

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

#ifndef TWORLD_PHASE2_CONTEXT
class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE* file);
    virtual unsigned char data_load_terrain_tables(char* file);
    virtual unsigned char data_load_players(char* file);
    virtual unsigned char data_load_objects(char* file);
    virtual unsigned char data_load_sounds(char* file);
    virtual unsigned char data_load_color_tables(char* file);
    virtual unsigned char data_load_sprites(char* file);
    virtual void data_load_players_type(short player_type, short player_count,
        FILE* file);
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
    virtual void logStatus(FILE* stream, int verbose);
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
    long sound_update_index; // +0x20
    long sprite_update_index; // +0x24
    RGE_Map* map; // +0x28
    short sound_num; // +0x2c
    RGE_Sound** sounds; // +0x30
    short sprite_num; // +0x34
    RGE_Sprite** sprites; // +0x38
    short player_num; // +0x3c
    RGE_Player** players; // +0x40
    short master_player_num; // +0x44
    RGE_Master_Player** master_players; // +0x48
    RGE_Effects* effects; // +0x4c
    short terrain_num; // +0x50
    short terrain_size; // +0x52
    float** terrains; // +0x54
    RGE_Command* commands; // +0x58
    RGE_Scenario* scenario; // +0x5c
    short color_table_num; // +0x60
    RGE_Color_Table** color_tables; // +0x64
    long next_object_id; // +0x68
    long next_reusable_object_id; // +0x6c
    long scenario_object_id; // +0x70
    unsigned char scenario_object_flag; // +0x74
    unsigned int random_seed; // +0x78
    short curr_player; // +0x7c
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
#endif

#ifndef TWORLD_PHASE2_CONTEXT
class TRIBE_World : public RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE* file);
    TRIBE_Tech* tech; // +0x104
    int victory_type; // +0x108
    int artifact_count; // +0x10c
    int ruin_count; // +0x110
    unsigned char countdown_victory; // +0x114
    float countdown_clock; // +0x118
    unsigned char score_displayed; // +0x11c
    unsigned char controllingComputerPlayer; // +0x11d
    int sent_zone_score; // +0x120

    void fill_in_score(struct TRIBE_Zone_High_Score_Info& info, long group);
    void send_zone_score_info();
};
#endif

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
            do {
                strcpy(info.player_info[player - 1].name,
                    this->players[player]->name);
                info.player_info[player - 1].score =
                    this->players[player]->victory_conditions->get_victory_points();
                info.player_info[player - 1].winner =
                    (this->players[player]->game_status == 1);
                info.player_info[player - 1].civ_played =
                    (unsigned char)rge_base_game->civilization(player - 1);
                info.player_info[player - 1].civ_random =
                    (unsigned char)rge_base_game->random_civ[player - 1];
                info.player_info[player - 1].player_no =
                    (unsigned char)rge_base_game->playerColor(player - 1);
                info.player_info[player - 1].team_no =
                    (unsigned char)rge_base_game->playerTeam(player - 1);
                int game_outcome = comm->WasKicked[player - 1];
                info.player_info[player - 1].game_outcome = (unsigned char)game_outcome;
                info.player_info[player - 1].tool_time = -1;
                info.player_info[player - 1].bronze_time = -1;
                info.player_info[player - 1].iron_time = -1;

                TRIBE_History_Events* event =
                    ((TRIBE_Player*)this->players[player])->history->events;
                while (event != 0) {
                    switch (event->event) {
                    case 0:
                        info.player_info[player - 1].tool_time = event->world_time;
                        break;
                    case 1:
                        info.player_info[player - 1].bronze_time = event->world_time;
                        break;
                    case 2:
                        info.player_info[player - 1].iron_time = event->world_time;
                        break;
                    }
                    event = event->next;
                }
                player++;
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
        case 2:
            info.game_end_condition_code = 6;
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
        info.map_info.Victory_Condition = (unsigned char)options.victoryTypeValue;
        info.map_info.Start_Age = (unsigned char)options.startingAgeValue;
        info.map_info.Resources = (unsigned char)options.resourceLevelValue;
        info.map_info.Full_Tech = options.fullTechTreeValue;
        info.map_info.Fixed_Pos = options.randomizePositionsValue;
        info.map_info.Reveal_Map = (unsigned char)rge_base_game->fullVisibility();
        info.map_info.Death_Match = options.deathMatchValue;
        info.map_info.Pop_Limit = (short)options.popLimitValue;

        info.database_checksum = 0;
        info.code_checksum = 0;
        info.program_version = 0;

        this->commands->com_hand->SendZoneMessage((char*)&info, 0x1fc);
    }
}
