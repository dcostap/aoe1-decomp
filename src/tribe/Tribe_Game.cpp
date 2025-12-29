#include "TRIBE_Game.h"
#include <stdio.h>
#include <string.h>

// Dummy Globals for linking
HMODULE StringTableX = nullptr;
int disable_terrain_sounds = 0;
int out_of_sync = 0;
int out_of_sync2 = 0;
int player_dropped[9] = {};

// Stubs for setup dependencies
void RESFILE_build_res_file(const char* a, const char* b, const char* c) {}
void RESFILE_open_new_resource_file(const char* name, const char* type, const char* path, int flag) {}
int video_codec_available = 0;
int _ICInfo_12(int a, int b, void* c) { return 1; }
struct TCommunications_Handler { static int LaunchLobbyGame(void* ptr) { return 0; } };
struct TPanelSystem { 
    static void setCurrentPanel(void* sys, const char* name, int v) {} 
    static void destroyPanel(void* sys, const char* name) {}
    static void* panel(void* sys, const char* name) { return nullptr; }
};
TPanelSystem panel_system;

// --- TRIBE_Game Implementation ---
TRIBE_Game::TRIBE_Game(RGE_Prog_Info* info, int do_setup)
    : RGE_Base_Game(info, 0) // matches: RGE_Base_Game::RGE_Base_Game(this, info, 0)
{
    // --- TRIBE fields init (matches what you pasted) ---
    video_window = nullptr;
    cur_video = -1;
    old_video_wnd_proc = nullptr;
    video_paused = 0;
    last_video_time = 0;
    video_setup = 0;
    video_double_size = 0;
    video_changed_res = 0;
    video_hi_color = 0;
    video_save_res_wid = 0;
    video_save_res_hgt = 0;
    video_save_palette = nullptr;
    started_menu_music = 0;
    show_object_id = 0;
    game_screen = nullptr;

    handleIdleLock = nullptr;
    inHandleIdle = 0;

    testing_scenario[0] = '\0';
    startup_scenario[0] = '\0';
    startup_game[0] = '\0';
    save_game_name[0] = '\0';
    load_game_name[0] = '\0';
    timing_text2[0] = '\0';
    auto_exit_time = 0;

    // globals
    StringTableX = nullptr;
    disable_terrain_sounds = 0;
    out_of_sync = 0;
    out_of_sync2 = 0;

    MouseRightClickTable = nullptr;
    MouseRightClickTableSize = 0;
    MouseLeftClickTable = nullptr;
    MouseLeftClickTableSize = 0;

    // defaults (your enums should match these names/values eventually)
    setMapSize(Medium);
    setMapType(WaterAndLand);
    setAnimals(1);
    setPredators(1);
    setVictoryType(VictoryConquest, 1);
    setAllowTrading(1);
    setLongCombat(0);
    setRandomizePositions(0);
    setFullTechTree(0);
    setResourceLevel(DefaultResources);
    setStartingAge(DefaultAge);
    setStartingUnits(0);
    setDeathMatch('\0');
    setPopLimit('2');
    setQuickStartGame('\0');
    setRandomStartValue(-1);

    // notification arrays: both x and y set to -1 for 5 entries
    for (int i = 0; i < 5; ++i) {
        notification_loc_x[i] = -1;
        notification_loc_y[i] = -1;
    }
    current_notification_loc = -1;
    current_notification_recalled = -1;

    // player init loop (matches “param_1 pointer trick” but in clean form)
    int civ = 1;
    for (int p = 0; p < 9; ++p) {
        setCivilization(p, civ);
        civ++;
        if (civ > 0x10) civ = 1;

        setScenarioPlayer(p, p);
        setPlayerColor(p, 1);
        setComputerName(p, 0);
        player_dropped[p] = 0;
    }

    for (int i = 0; i < 9; ++i) {
        save_humanity[i] = 0;
    }

    RGE_Base_Game::setNumberPlayers(4);
    resetRandomComputerName();

    // constructor optional setup (matches decomp behavior)
    if (do_setup != 0) {
        int r = this->setup(); // in the binary: setup() returns 0 on success
        if (r == 0 && this->error_code == 0) {
            // binary does this pattern in both base and tribe ctors
            this->error_code = 1;
        }
    }
}

int TRIBE_Game::setup() {
    auto fail = [&](int code) -> int {
        this->error_code = code;
        return 0;
    };

    // If we’re already in an error state, decomp bails early.
    if (this->error_code != 0) {
        return 0;
    }

    const char* cmd = (prog_info && prog_info->cmd_line) ? prog_info->cmd_line : "";

    // --- MAKERES detection (case-insensitive) ---
    if (ContainsI(cmd, "makeres")) {
        // These match the decomp names: graphics.rm, sounds.rm, interfac.rm -> resource\
        RESFILE_build_res_file("graphics.rm", "resource\\", prog_info->resource_dir);
        RESFILE_build_res_file("sounds.rm",   "resource\\", prog_info->resource_dir);
        RESFILE_build_res_file("interfac.rm", "resource\\", prog_info->resource_dir);
    }

    // --- Open DRS from installed resource dir ---
    RESFILE_open_new_resource_file("sounds.drs",   "tribe", prog_info->resource_dir, 1);
    RESFILE_open_new_resource_file("graphics.drs", "tribe", prog_info->resource_dir, 0);
    RESFILE_open_new_resource_file("Interfac.drs", "tribe", prog_info->resource_dir, 0);

    // --- Open DRS from "data\" fallback (exactly like decomp) ---
    RESFILE_open_new_resource_file("sounds.drs",   "tribe", "data\\", 1);
    RESFILE_open_new_resource_file("graphics.drs", "tribe", "data\\", 0);
    RESFILE_open_new_resource_file("Terrain.drs",  "tribe", "data\\", 0);
    RESFILE_open_new_resource_file("Border.drs",   "tribe", "data\\", 0);
    RESFILE_open_new_resource_file("Interfac.drs", "tribe", "data\\", 0);

    // --- Base setup must succeed first ---
    if (!RGE_Base_Game::setup()) {
        return 0;
    }

    // --- Parse STRING= override for expansion language DLL ---
    // Decomp default is "languagex.dll", overridden by STRING=token.
    std::string dllName = "languagex.dll";
    {
        std::string overrideName = CmdValueToken(cmd, "STRING=");
        if (!overrideName.empty()) {
            dllName = overrideName;
        }
    }

    // --- Load StringTableX (expansion strings) ---
    if (!StringTableX) {
        StringTableX = LoadStringDll(this->work_dir, dllName.c_str());
    }
    if (!StringTableX) {
        // decomp sets a flag and returns 0; clean version sets error_code
        return fail(1);
    }

    // --- Palette patch (SetPaletteEntries at 0xF8 for 7 entries) ---
    // Exactly the values you saw. Entry [0] is unused in the decomp; it writes entries 1..7.
    PALETTEENTRY pe[8]{};
    pe[1] = { 0x17, 0x27, 0x7C, 0 };
    pe[2] = { 0x27, 0x3F, 0x90, 0 };
    pe[3] = { 0x3F, 0x5F, 0x9F, 0 };
    pe[4] = { 0x57, 0x7B, 0xB4, 0 };
    pe[5] = { 0x3F, 0x5F, 0xA0, 0 };
    pe[6] = { 0x3F, 0x3F, 0x91, 0 };
    pe[7] = { 0, 0, 0, 0 }; // not sure if used; decomp passes 7 starting at pe+1

    if (this->prog_palette) {
        SetPaletteEntries((HPALETTE)this->prog_palette, 0xF8, 7, &pe[1]);
    }

    // --- Create InputDisabledWindow (STATIC child) ---
    this->input_disabled_window = CreateWindowExA(
        0,
        "STATIC",
        "InputDisabledWindow",
        WS_CHILD | WS_VISIBLE,
        0, 0, 1, 1,
        (HWND)this->prog_window,
        nullptr,
        (HINSTANCE)this->prog_info->instance,
        nullptr
    );

    // --- Video codec availability ---
    // Decomp: _ICInfo_12('vidc','iv41', &ici.fccType)
    // Keep the constants; you can replace with ICInfo if you want.
    ICINFO ici{};
    video_codec_available = _ICInfo_12(0x63646976, 0x31347669, &ici.fccType);

    // --- LOBBY handling ---
    // check_prog_argument returns nonzero if present.
    const bool hasLobbyArg = (this->check_prog_argument("LOBBY") != 0);

    if (!hasLobbyArg) {
        // Normal startup path
        int lobby = TCommunications_Handler::LaunchLobbyGame(this->comm_handler);
        if (lobby == 1) {
            this->setMultiplayerGame(1);
            // create MP setup screen object here if you’ve implemented it
            TPanelSystem::setCurrentPanel(&panel_system, "MP Setup Screen", 0);
            TPanelSystem::destroyPanel(&panel_system, "Status Screen");
        } else {
            int ok = 1;
            if (startup_scenario[0] == '\0') {
                if (startup_game[0] == '\0') {
                    if (prog_info->skip_startup == 0) {
                        ok = start_video(this, 0, "logo1");
                    } else {
                        ok = start_menu();
                    }
                } else {
                    ok = load_game(startup_game);
                }
            } else {
                ok = start_scenario(startup_scenario);
            }

            // If startup failed: go to menu and show a popup (decomp uses TEasy_Panel::popupOKDialog)
            if (!ok) {
                if (!start_menu()) return 0;
                // popupOKDialog(0x961, ..., 0x1c2, 100) is game UI; stub it if needed
            }
        }

        // decomp calls set_interface_messages again and logs options; safe to do:
        this->set_interface_messages();
        return 1;
    }

    // LOBBY argument present: show status screen, then attempt LaunchLobbyGame with error handling.
    // You can mirror the exact panel/error screen behavior later; clean version:
    TPanelSystem::setCurrentPanel(&panel_system, "Status Screen", 0);

    int lobby = TCommunications_Handler::LaunchLobbyGame(this->comm_handler);
    if (lobby == 1) {
        this->setMultiplayerGame(1);
        TPanelSystem::setCurrentPanel(&panel_system, "MP Setup Screen", 0);
        TPanelSystem::destroyPanel(&panel_system, "Status Screen");
        this->set_interface_messages();
        return 1;
    }

    // Failure: in the real game it may close or show Main Error Screen.
    return 0;
}


// Helpers
int TRIBE_Game::start_video(void* this_ptr, int u, const char* name) { return 1; }
int TRIBE_Game::start_menu() { return 1; }
int TRIBE_Game::load_game(const char* name) { return 1; }
int TRIBE_Game::start_scenario(const char* name) { return 1; }


static char g_tmp[0x200];

static inline void ForceTerminate(char* out, int outLen) {
    if (out && outLen > 0) out[outLen - 1] = '\0';
}

char* TRIBE_Game::get_string(long id, char* out, int outLen) {
    if (!out || outLen <= 0) return out;

    int n = 0;
    if (StringTableX) {
        n = LoadStringA(StringTableX, (UINT)id, out, outLen);
    }
    if (n == 0) {
        // fallback to base language.dll
        return RGE_Base_Game::get_string(id, out, outLen);
    }

    ForceTerminate(out, outLen);
    return out;
}

// 00522930
char* TRIBE_Game::get_string2(int mode, long code, long extra, char* out, int outLen) {
    clear(out);
    if (!out || outLen <= 0) return out;

    // Helper to load an ID using the (virtual) loader.
    auto load_id = [&](long stringId) -> char* {
        // In the binary this is vtbl[+0x20](stringId, out, outLen)
        // which is exactly this->get_string(stringId, out, outLen).
        return this->get_string(stringId, out, outLen);
    };

    switch (mode) {
        case 1:
            switch (code) {
                case 100:
                case 0x65:
                case 0x66:
                    return load_id(0x961);
                case 0x67: return load_id(0x962);
                case 0x68: return load_id(0x963);
                case 0x69: return load_id(0x964);
                case 0x6A: return load_id(0x965);
                default:
                    return RGE_Base_Game::get_string2(mode, code, extra, out, outLen);
            }

        default:
            return RGE_Base_Game::get_string2(mode, code, extra, out, outLen);

        case 100:
            switch (code) {
                case 0: case 0x0F: case 0x10: case 0x11: return load_id(0x10CD);
                case 1: return load_id(0x10CE);
                case 2: return load_id(0x10CF);
                case 3: return load_id(0x10D0);
                case 9: return load_id(0x10DB);
            }
            break;

        case 0x65:
            switch (code) {
                case 1: return load_id(0x1069);
                case 2: return load_id(0x106A);
                case 3: return load_id(0x106B);
                case 4: return load_id(0x106C);
            }
            break;

        case 0x66:
            switch (code) {
                case 1: return load_id(0x1005);
                case 2: return load_id(0x1006);
                case 3: return load_id(0x1007);
                case 4: return load_id(0x1008);
                case 5: return load_id(0x1009);
                case 6: return load_id(0x100A);
                case 7: return load_id(0x100B);
                case 8: return load_id(0x100C);
                case 9: return load_id(0x100D);
                case 10: return load_id(0x100E);
                case 0x0B: return load_id(0x100F);
                case 0x0C: return load_id(0x1010);
                case 0x0D: return load_id(0x1011);
                case 0x0E: return load_id(0x1012);
                case 0x0F: return load_id(0x1013);
                case 0x10: return load_id(0x1014);
                case 0x11: return load_id(0x1015);
                case 0x12: return load_id(0x1016);
                case 0x13: return load_id(0x1017);
                case 0x14: return load_id(0x1018);
                case 0x15: return load_id(0x1019);
                case 0x16: return load_id(0x101A);
                case 0x17: return load_id(0x101B);
                case 0x19: return load_id(0x1020);
                case 0x1A: return load_id(0x1021);
                case 0x1B: return load_id(0x1022);
                case 0x1C: return load_id(0x101C);
                case 0x1D: return load_id(0x101D);
                case 0x1E: return load_id(0x101E);
                case 0x1F: return load_id(0x101F);
                case 0x20: return load_id(0x1025);
                case 0x21: return load_id(0x1026);
            }
            break;

        case 0x67:
            // This is the branch that uses 'extra' (param_3) in your decomp.
            if (code < 0x66) {
                if (code == 0x65) {
                    return load_id(0x0BBE);
                }
                if (code == 1) {
                    switch (extra) {
                        case 0: return load_id(0x0BB9);
                        case 1: return load_id(0x0BBA);
                        case 2: return load_id(0x0BBB);
                        case 3: return load_id(0x0BBC);
                        case 4: return load_id(0x0BBD);
                        case 0x20: return load_id(0x0BE6);
                    }
                }
            } else if (code < 0x3E9) {
                if (code == 1000) {
                    return load_id(0x0BC2);
                }
                switch (code) {
                    case 0x66: return load_id(0x0BBF);
                    case 0x67: return load_id(0x0BC0);
                    case 0x68: return load_id(0x0BC1);
                    case 0x69: return load_id(0x0BC3);
                    case 0x6A: return load_id(0x0BCA);
                }
            }
            break;

        case 0x68:
            switch (code) {
                case 1:  return load_id(0x10D4);
                case 2:  return load_id(0x10D1);
                case 3:  return load_id(0x10D2);
                case 4:  return load_id(0x10D3);
                case 5:  return load_id(0x10D5);
                case 6:  return load_id(0x10D6);
                case 7:  return load_id(0x10D7);
                case 8:  return load_id(0x10D8);
                case 9:  return load_id(0x10D9);
                case 10: return load_id(0x10DA);
                case 0x0B: return load_id(0x10DC);
            }
            break;

        case 0x69:
            // This matches your decomp behavior: some branches just "break"
            // then fall to the final termination+return.
            switch (code) {
                case 1:
                    load_id(0x27F7);
                    break;
                case 2:
                    load_id(0x27F8);
                    force_terminate(out, outLen);
                    return out;
                case 3:
                    load_id(0x27F9);
                    force_terminate(out, outLen);
                    return out;
                case 4:
                    load_id(0x27FA);
                    force_terminate(out, outLen);
                    return out;
                case 5:
                    load_id(0x27FB);
                    force_terminate(out, outLen);
                    return out;
                case 6:
                    load_id(0x27FC);
                    force_terminate(out, outLen);
                    return out;
                case 7:
                    load_id(0x27FD);
                    force_terminate(out, outLen);
                    return out;
                case 8:
                    load_id(0x27FE);
                    force_terminate(out, outLen);
                    return out;
                case 9:
                    load_id(0x27FF);
                    force_terminate(out, outLen);
                    return out;
                case 10:
                    load_id(0x2800);
                    force_terminate(out, outLen);
                    return out;
                case 0x0B:
                    load_id(0x2801);
                    force_terminate(out, outLen);
                    return out;
                case 0x0C:
                    load_id(0x2802);
                    force_terminate(out, outLen);
                    return out;
                case 0x0D:
                    load_id(0x2806);
                    force_terminate(out, outLen);
                    return out;
                case 0x0E:
                    load_id(0x2807);
                    force_terminate(out, outLen);
                    return out;
                case 0x0F:
                    load_id(0x2809);
                    force_terminate(out, outLen);
                    return out;
                case 0x10:
                    load_id(0x2808);
                    force_terminate(out, outLen);
                    return out;
                default:
                    load_id(0x2804);
                    force_terminate(out, outLen);
                    return out;
            }
            break;
    }

    // If we reach here, the decompiled function does:
    // out[outLen-1] = '\0'; return out;
    force_terminate(out, outLen);
    return out;
}

// --- Helper Stubs ---
void TRIBE_Game::setMapSize(MapSize val) {}
void TRIBE_Game::setMapType(MapType val) {}
void TRIBE_Game::setAnimals(int val) {}
void TRIBE_Game::setPredators(int val) {}
void TRIBE_Game::setVictoryType(VictoryType type, int val) {}
void TRIBE_Game::setAllowTrading(int val) {}
void TRIBE_Game::setLongCombat(int val) {}
void TRIBE_Game::setRandomizePositions(int val) {}
void TRIBE_Game::setFullTechTree(int val) {}
void TRIBE_Game::setResourceLevel(int val) {}
void TRIBE_Game::setStartingAge(int val) {}
void TRIBE_Game::setStartingUnits(int val) {}
void TRIBE_Game::setDeathMatch(char val) {}
void TRIBE_Game::setPopLimit(char val) {}
void TRIBE_Game::setQuickStartGame(char val) {}
void TRIBE_Game::setRandomStartValue(int val) {}
void TRIBE_Game::setCivilization(int player, int civ) {}
void TRIBE_Game::setScenarioPlayer(int player, int val) {}
void TRIBE_Game::setPlayerColor(int player, int color) {}
void TRIBE_Game::setComputerName(int player, int val) {}
void TRIBE_Game::resetRandomComputerName() {}