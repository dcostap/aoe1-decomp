#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//==============================================================================
// Types & Stubs
//==============================================================================

typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned short ushort;

struct MouseClickInfo {};
struct TRIBE_Screen_Game {};

enum MapSize { Small, Medium, Large, Huge };
enum MapType { Coastal, Inland, Highland, Continental };
enum VictoryType { Standard, Conquest, TimeLimit, Score };
enum ResourceLevel { Low, Medium_Res, High };
enum Age { StoneAge, ToolAge, BronzeAge, IronAge };

//==============================================================================
// RGE_Prog_Info - Address: 004549e0 (Local Stack Variable)
//==============================================================================

#pragma pack(push, 1)
struct RGE_Prog_Info {
    /* 0x0000 */ char prog_name[101];
    /* 0x0065 */ char prog_version[21];
    /* 0x007a */ char prog_title[121];
    /* 0x00f3 */ char world_db_file[261];
    /* 0x01f8 */ char game_data_file[261];
    /* 0x02fd */ char vol_name[261];
    /* 0x0402 */ uchar _pad_402[2]; // Gap between vol_name and vol_ser_num
    /* 0x0404 */ ulong vol_ser_num;
    /* 0x0408 */ int verify_cd;
    /* 0x040c */ int max_players_per_cd;
    /* 0x0410 */ void* instance;
    /* 0x0414 */ void* prev_instance;
    /* 0x0418 */ char registry_key[256];
    /* 0x0518 */ char cmd_line[256];
    /* 0x0618 */ int show_wnd_flag;
    /* 0x061c */ char icon_name[41];
    /* 0x0645 */ char menu_name[41];
    /* 0x066e */ char pal_file[261];
    /* 0x0773 */ char cursor_file[261];
    /* 0x0878 */ int max_players;
    /* 0x087c */ int check_expiration;
    /* 0x0880 */ short expire_month;
    /* 0x0882 */ short expire_day;
    /* 0x0884 */ short expire_year;
    /* 0x0886 */ uchar _pad_886[2]; // Padding to ulong
    /* 0x0888 */ ulong update_interval;
    /* 0x088c */ int check_multi_copies;
    /* 0x0890 */ int skip_startup;
    /* 0x0894 */ int full_screen;
    /* 0x0898 */ int fixed_window_size;
    /* 0x089c */ int use_dir_draw;
    /* 0x08a0 */ int use_sys_mem;
    /* 0x08a4 */ int use_music;
    /* 0x08a8 */ int use_sound;
    /* 0x08ac */ int use_cd_audio;
    /* 0x08b0 */ int use_ima;
    /* 0x08b4 */ int use_midi;
    /* 0x08b8 */ int use_wave_music;
    /* 0x08bc */ int fast_view;
    /* 0x08c0 */ int auto_scroll;
    /* 0x08c4 */ long mouse_scroll_edge;
    /* 0x08c8 */ ulong mouse_scroll_interval;
    /* 0x08cc */ float mouse_scroll_max_dist;
    /* 0x08d0 */ ulong key_scroll_interval;
    /* 0x08d4 */ float key_scroll_max_dist;
    /* 0x08d8 */ float key_scroll_object_move;
    /* 0x08dc */ short interface_style;
    /* 0x08de */ uchar _pad_8de[2]; // Align to 0x8e0
    /* 0x08e0 */ long main_wid;
    /* 0x08e4 */ long main_hgt;
    /* 0x08e8 */ GUID game_guid;
    /* 0x08f8 */ GUID zone_guid;
    /* 0x0908 */ char data_dir[261];
    /* 0x0a0d */ char graphics_dir[261];
    /* 0x0b12 */ char save_dir[261];
    /* 0x0c17 */ char scenario_dir[261];
    /* 0x0d1c */ char campaign_dir[261];
    /* 0x0e21 */ char sounds_dir[261];
    /* 0x0f26 */ char resource_dir[261];
    /* 0x102b */ char ai_dir[261];
    /* 0x1130 */ char avi_dir[261];
};

//==============================================================================
// TRIBE_Game_Options - Address: 0x0A7C (Inside TRIBE_Game)
//==============================================================================
struct TRIBE_Game_Options {
    /* 0x00 */ MapSize mapSizeValue;
    /* 0x04 */ MapType mapTypeValue;
    /* 0x08 */ int animalsValue;
    /* 0x0c */ int predatorsValue;
    /* 0x10 */ VictoryType victoryTypeValue;
    /* 0x14 */ int victoryAmountValue;
    /* 0x18 */ uchar civilizationValue[9];
    /* 0x21 */ uchar _pad_21[3]; // Gap to 0x24
    /* 0x24 */ int scenarioPlayerValue[9];
    /* 0x48 */ uchar playerColorValue[9];
    /* 0x51 */ uchar computerNameValue[9];
    /* 0x5a */ uchar allowTradingValue;
    /* 0x5b */ uchar longCombatValue;
    /* 0x5c */ uchar randomizePositionsValue;
    /* 0x5d */ uchar fullTechTreeValue;
    /* 0x5e */ uchar _pad_5e[2]; // Gap to 0x60
    /* 0x60 */ ResourceLevel resourceLevelValue;
    /* 0x64 */ Age startingAgeValue;
    /* 0x68 */ uchar startingUnitsValue;
    /* 0x69 */ uchar deathMatchValue;
    /* 0x6a */ uchar popLimitValue;
};

//==============================================================================
// TRIBE_Game - Address: 0x0054f870 (Allocated in entry)
//==============================================================================
class TRIBE_Game {
public:
    /* 0x0000 */ uchar _pad_entry[0xa24]; // Large block of unknown/unmapped data

    /* 0x0a24 */ MouseClickInfo* MouseRightClickTable;
    /* 0x0a28 */ int MouseRightClickTableSize;
    /* 0x0a2c */ MouseClickInfo* MouseLeftClickTable;
    /* 0x0a30 */ int MouseLeftClickTableSize;
    /* 0x0a34 */ long queue_is_waiting_on_pop_counter[9];
    /* 0x0a58 */ int random_civ[9];
    /* 0x0a7c */ TRIBE_Game_Options tribe_game_options;
    /* 0x0ae8 */ char testing_scenario[260];
    /* 0x0bec */ void* video_window;
    /* 0x0bf0 */ int cur_video;
    /* 0x0bf4 */ void* old_video_wnd_proc;
    /* 0x0bf8 */ int video_paused;
    /* 0x0bfc */ ulong last_video_time;
    /* 0x0c00 */ int video_setup;
    /* 0x0c04 */ int video_double_size;
    /* 0x0c08 */ int video_changed_res;
    /* 0x0c0c */ int video_hi_color;
    /* 0x0c10 */ long video_save_res_wid;
    /* 0x0c14 */ long video_save_res_hgt;
    /* 0x0c18 */ void* video_save_palette;
    /* 0x0c1c */ int started_menu_music;
    /* 0x0c20 */ int show_object_id;
    /* 0x0c24 */ TRIBE_Screen_Game* game_screen;
    /* 0x0c28 */ long notification_loc_x[5];
    /* 0x0c3c */ long notification_loc_y[5];
    /* 0x0c50 */ long current_notification_loc;
    /* 0x0c54 */ long current_notification_recalled;
    /* 0x0c58 */ char startup_scenario[260];
    /* 0x0d5c */ char startup_game[260];
    /* 0x0e60 */ ulong auto_exit_time;
    /* 0x0e64 */ char save_game_name[260];
    /* 0x0f68 */ char load_game_name[260];
    /* 0x106c */ char timing_text2[256];
    /* 0x116c */ int save_humanity[9];
    /* 0x1190 */ uchar quick_start_game;
    /* 0x1191 */ uchar _pad_1191[3]; // Align to 0x1194
    /* 0x1194 */ int random_start_value;
    /* 0x1198 */ uchar computerNameUsed[18][10];
    /* 0x124c */ void* handleIdleLock;
    /* 0x1250 */ int inHandleIdle;

    // vtable stubs
    virtual ~TRIBE_Game() {}                                        // [0]
    virtual int get_error_code() { return 0; }                      // [1]
    virtual int stub2() { return 0; }
    virtual int stub3() { return 0; }
    virtual int stub4() { return 0; }
    virtual int stub5() { return 0; }
    virtual int run() { return 0; }                                 // [6]
    virtual int stub7() { return 0; }
    virtual void show_error(int id, char* buf, int s) {}            // [8]
    virtual int stub9() { return 0; }
    virtual void fatal_exit(int a, int b, int c, char* d, int e) {} // [10]

    // Constructor - logic from 004549e0
    TRIBE_Game(RGE_Prog_Info* info, int arg2) {
        printf("[DEBUG] TRIBE_Game Object created. Size: 0x%zx\n", sizeof(TRIBE_Game));
    }
};
#pragma pack(pop)

//==============================================================================
// GUID Global Constants (Address: 00570654)
//==============================================================================
const GUID _TRIBE_GUID = { 0x33626761, 0x8267, 0x11cf, { 0x10, 0x00, 0x00, 0xaa, 0x00, 0x38, 0xe9, 0x69 } };
const GUID _ZONE_GUID  = { 0x24e03b40, 0xc14b, 0x11cf, { 0x10, 0x00, 0x00, 0xaa, 0x00, 0x38, 0xe9, 0x69 } };

//==============================================================================
// WinMain - Address: 004549e0
//==============================================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    RGE_Prog_Info info;
    memset(&info, 0, sizeof(RGE_Prog_Info));

    // String initialization blocks (mapped from Ghidra assembly loops)
    strcpy(info.prog_name, "Axeman");
    strcpy(info.prog_version, "00.03.01.0717");
    sprintf(info.prog_title, "Age of Empires Expansion");
    
    strcpy(info.world_db_file, "tribes\\world.txt");
    strcpy(info.game_data_file, "data2\\empires.dat");
    strcpy(info.registry_key, "Software\\Microsoft\\Games\\Age of Empires\\1.00");
    strcpy(info.cmd_line, lpCmdLine);
    strcpy(info.icon_name, "AppIcon");
    strcpy(info.pal_file, "palette.pal");
    strcpy(info.cursor_file, "mcursors.rsc");
    strcpy(info.vol_name, "AOE");

    strcpy(info.data_dir, "data2");
    strcpy(info.sounds_dir, "sound");
    strcpy(info.graphics_dir, "graphics");
    strcpy(info.save_dir, "savegame");
    strcpy(info.scenario_dir, "scenario");
    strcpy(info.campaign_dir, "campaign");
    strcpy(info.resource_dir, "data2");
    strcpy(info.ai_dir, "data2");
    strcpy(info.avi_dir, "avi");

    // Value assignments from 004549e0
    info.instance = (void*)3;
    info.prev_instance = hPrevInstance;
    info.show_wnd_flag = nCmdShow;
    info.game_guid = _TRIBE_GUID;
    info.zone_guid = _ZONE_GUID;

    info.mouse_scroll_max_dist = 0.000117709f;
    info.key_scroll_max_dist = 0.000117709f;
    info.key_scroll_interval = 4;
    info.key_scroll_object_move = 4.0f;
    info.main_wid = 800;
    info.main_hgt = 600;

    // TRIBE_Game object allocation (operator_new(0x1254))
    TRIBE_Game* game = new TRIBE_Game(&info, 1);

    int error_code = 0;
    if (game) {
        int result = game->run();
        
        if (result == 0) {
            error_code = game->get_error_code();
            delete game;
        } 
        else if (result != 4) {
            char title[256], msg[256];
            game->show_error(2001, title, 256);
            game->fatal_exit(1, 0, 0, msg, 256);
            delete game;
            MessageBoxA(NULL, "Engine initialization failed.", "Critical Error", MB_ICONERROR);
        }
    }

    return error_code;
}