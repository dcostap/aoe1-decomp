// PDB source module: C:\\msdev\\work\\age1_x1\\basegame.cpp.
//
// PDB lines 199-481.  0041BAA0 begins the reviewed setup hold.

#include <windows.h>
#include <io.h>
#include <new.h>
#include <stdio.h>
#include <string.h>

#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/rge_base_game_global.h"
#include "../include/gameinfo.h"
#include "../include/game_globals.h"
#include "../include/sceninfo.h"
#include "../include/scenario.h"
#include "../include/file_stf.h"
#include "../include/drawarea.h"
#include "../include/sounddrv.h"
#include "../include/music.h"
#include "../include/chat.h"
#include "../include/com_hand.h"
#include "../include/debuglog.h"
#include "../include/registry.h"
#include "../include/Mouseptr.h"
#include "../include/Shape.h"
#include "../include/panel.h"
#include "../include/panel_ez.h"
#include "../include/Pnl_scr.h"
#include "../include/world.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/obj_list.h"
#include "../include/sound.h"
#include "../include/rge_fio.h"

extern FILE* draw_log;
extern char draw_log_name[260];
extern int do_draw_log;
extern int safe_draw_log;
extern int g_592A58;
extern int g_62C4A0;
extern int g_62C4A8;
extern int g_62C4B0;
extern int g_62C4B8;
extern int g_62C4C0;
extern int g_62C4FC;
extern int g_5B215C;
extern int g_5B236C;

// 0041B620 write_draw_log, basegame.cpp:199-205 (44 bytes).
void __cdecl write_draw_log(char* text)
{
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fflush(draw_log);
    }
}

// 0041B650 write_draw_log2, basegame.cpp:208-215 (67 bytes).
void __cdecl write_draw_log2(char* text)
{
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fclose(draw_log);
        draw_log = fopen(draw_log_name, "a+");
    }
}

// 0041E7A0 rge_base_game_wnd_proc, basegame.cpp:230-235 (43 bytes).
unsigned long __stdcall rge_base_game_wnd_proc(
    unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    RGE_Base_Game* game = rge_base_game;
    if (game != 0)
        return (unsigned long)game->wnd_proc((void*)a, b, c, (long)d);
    return 0;
}

// 0041B6A0 RGE_Base_Game::RGE_Base_Game, basegame.cpp:247-481 (988 bytes).
RGE_Base_Game::RGE_Base_Game(RGE_Prog_Info* info, int do_setup)
    : player_game_info(0),
      random_game_seed(-1),
      random_map_seed(-1),
      save_random_game_seed(-1),
      save_random_map_seed(-1),
      quick_build(0)
{
    int i;

    do_draw_log = 0;
    safe_draw_log = 0;
    draw_log_name[0] = 0;
    draw_log = 0;

    this->setVersion(1.0f);
    this->setScenarioGame(0);
    this->setCampaignGame(0);
    this->setSavedGame(0);
    this->setSinglePlayerGame(1);
    this->setMultiplayerGame(0);
    this->setMapSize(0x60, 0x60, 8);
    this->setAllowCheatCodes(0);
    this->setCheatNotification(1);
    this->setFullVisibility(0);
    this->setFogOfWar(1);
    this->setColoredChat(1);
    this->setGameDeveloperMode(0);
    this->setDifficulty(0);

    for (i = 0; i < 9; i++) {
        this->setPlayerCDAndVersion(i, 0);
        this->setPlayerHasCD(i, 0);
        this->setPlayerVersion(i, 0);
        this->setPlayerTeam(i, 1);
    }

    this->setPathFinding(0);
    this->setMpPathFinding(0);
    this->setNumberPlayers(4);
    this->setScenarioName("");

    rge_base_game = this;
    this->prog_info = info;
    this->prog_window = 0;
    this->prog_ready = 0;
    this->prog_active = 1;
    this->prog_palette = 0;
    this->window_style = 0;
    g_62C4A0 = 0;
    this->screen_saver_enabled = 0;
    this->error_code = 0;
    this->is_timer = 0;
    this->draw_system = 0;
    this->draw_area = 0;
    this->outline_type = 2;
    this->custom_mouse = 0;
    this->shapes = 0;
    this->sound_system = 0;
    this->music_system = 0;
    this->sound_num = 0;
    this->sounds = 0;
    this->save_music_type = 0;
    this->save_music_track_from = 0;
    this->save_music_track_to = 0;
    this->save_music_cur_track = 0;
    this->save_music_file[0] = 0;
    this->save_music_loop = 0;
    this->save_music_pos = 0;
    this->comm_handler = 0;
    this->debugLog = 0;
    this->log_comm = 0;
    this->comm_syncstop = 0;
    this->comm_syncmsg = 0;
    this->comm_stepmode = 0;
    this->comm_speed = 1;
    this->comm_droppackets = 0;
    this->registry = 0;
    this->prog_mode = 0;
    this->game_mode = 0;
    this->sub_game_mode = 0;
    this->paused = 0;
    this->mouse_pointer = 0;
    this->erase_mouse = 0;
    this->mouse_blit_sync = 0;
    this->is_mouse_on = 1;
    this->windows_mouse = 1;
    this->mouse_cursor = LoadCursorA(0, IDC_ARROW);
    this->font_num = 0;
    this->fonts = 0;
    GetCurrentDirectoryA(0x105, this->work_dir);

    strcpy(this->string_dll_name, "language.dll");

    this->master_obj_id = -1;
    this->terrain_id = -1;
    this->elevation_height = -1;
    this->world = 0;
    this->render_all = 1;
    this->brush_size = 1;
    this->timing_text[0] = 0;
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;
    this->last_view_time = 0;

    for (i = 0; i < 30; i++) {
        this->timings[i].accum_time = 0;
        this->timings[i].last_time = 0;
        this->timings[i].start_time = 0;
        this->timings[i].last_single_time = 0;
        this->timings[i].max_time = 0;
        this->timings[i].last_max_time = 0;
        this->timings[i].include_in_total = 0;
        this->timings[i].is_summary = 0;
    }

    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;
    this->save_check_for_cd = 1;
    g_62C4FC = 0;
    g_592A58 = (int)this->prog_info->instance;
    g_5B236C = 0;
    g_62C4B8 = 0;
    g_62C4C0 = 0;
    g_62C4A8 = 0;
    g_62C4B0 = 0;
    g_5B215C = 0;
    this->scenario_info = 0;
    for (i = 0; i < 9; i++) {
        this->playerIDValue[i] = 0;
        this->resigned[i] = 0;
    }
    this->auto_paused = 0;
    this->rollover = 1;
    this->map_save_area = 0;
    this->game_speed = 1.0f;
    this->single_player_difficulty = 2;

    if (!this->setup_registry()) {
        this->error_code = 0x0E;
        return;
    }
    g_62C4A8 = (int)this->registry;
    if (!this->setup_debugging_log()) {
        this->error_code = 0x0F;
        return;
    }
    g_62C4FC = (int)this->debugLog;
    if (do_setup) {
        if (!this->setup()) {
            if (!this->error_code)
                this->error_code = 1;
        }
    }
    this->display_selected_ids = 0;
}

// 0041BAA0 RGE_Base_Game::setup remains an accepted-drift hold.



// PDB ownership: accepted_drift/0041BAA0_setup.cpp
// VA: 0041BAA0 RGE_Base_Game::setup (1948 B)
// PDB source: basegame.cpp:491-871
// Attempt log:
// - The packet scaffold was a free-function placeholder and missed the registry,
//   virtual-slot, Win32, and C++ new-expression surfaces.  This candidate restores
//   the period RGE_Base_Game vtable/interface, named RGE_Prog_Info ownership,
//   typed local Windows records, and the natural nested setup/error flow.
// - FLAGS: config/flags/0041BAA0_setup.rsp (/GX is evidenced by the original EH
//   registration and constructor new-expression state records).
// - Bounded scans as natural for loops reproduce the oracle's single sprintf/
//   findfirst call sites (67/67 ordered calls); the screen-size switch reproduces
//   the VC5 jump-to-handler layout.
// - A shared failure epilogue (with the memory-pressure error block immediately
//   before it) removes repeated return-value setup and is the best current source.
// - Paused after the 10-hypothesis budget: current drift is 1263 positional bytes;
//   remaining evidence points to a +4 frame/local-home mismatch and the memory
//   predicate's block shape, not an unresolved call set.
// - Directly assigning player_game_info from each new-expression removes the
//   saved pointer reload. It gives exact size and two more exact tail blocks.
//   It remains the best clean source, with 1320 strict drift bytes.
// - Recast the proven memory-pressure test as the natural if-bad/else-success
//   setup shape; the oracle places the bad-path assignment in the final tail.
// - Reordered the reused MEMORYSTATUS and DirectX locals to match the original
//   contiguous local window reported by the packet; this is a declaration-order probe.
// - Current shard probes left the natural memory nesting and local order in place:
//   both emitted the clean-source code.  Remaining structural drift is the +4
//   frame/local home and the original memory branch's far tail placement.
// - Removed the top-level game_info local and assigned player_game_info directly
//   in each new-expression arm.  This reduced the size gap to +2 bytes but left
//   the +4 frame and moved one later operator-new call target; restored clean.
// - Reversed the memory guard to the binary's positive success predicate.  This
//   improved CFG/block coverage and size (+6 bytes) but worsened positional diff;
//   restored the validated clean source.  The original low-memory jump tail is
//   evidence for a separate early-failure layout lead.
// - Reconstructed the early gates and later setup failures as one natural
//   nested success ladder.  This is supported by the decompiler nesting and
//   removes the old flat failure scaffold without changing the clean codegen.
// - Added the binary-proven destructors for the allocated records and scoped
//   their pointer and file-number owners.  VC5 emitted the same code.
// - Kept the memory-success body before the error 0x16 tail.  PDB line 629 and
//   the oracle's far branch support this source order; it improves CFG coverage
//   but leaves a six-byte size gap and the unresolved four-byte EH frame gap.
// - Reused ms.dwLength for the first GetDXVersion output and compared that
//   field.  The oracle passes the game-speed home as the first output, then
//   reads that same home.  This removes the four-byte frame gap and aligns the
//   EH record home; the remaining drift is not a frame-ownership mismatch.
// - Corrected LoadLibraryA to use this+0x2ED. The prior fixed string argument
//   caused broad register drift and did not match the executable's path owner.
// Accepted-drift review: size, frame, 67 calls, CFG counts, EH states, setup
// gates, error codes, global/member publication, constructor cleanup, logs,
// timers, and returns match. The remaining 22 bytes are +4 private stack-home
// offsets for valid DirectX, memory-status, file, path, and OFSTRUCT buffers.
// Each external call receives the same buffer content and object extent.
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern void __cdecl debug_srand(char* file, int line, unsigned int seed);
extern "C" void __cdecl GetDXVersion(unsigned long* version, unsigned long* platform);
extern float DAT_0056f014;

extern void* StringTable;
extern int debugActions;
extern FILE* actionFile;
extern int do_draw_log;
extern char draw_log_name[260];
extern FILE* draw_log;
extern int do_fps_log;
extern FILE* fps_log;
extern DriveInformation* driveInfo;
int RGE_Base_Game::setup()
{
    unsigned long DXVersion;
    MEMORYSTATUS ms;
    char filename[260];
    char s[256];
    OFSTRUCT of;
    _finddata_t file_info;
    debug_srand((char*)0x57FB08, 0x20A,
                debug_timeGetTime((char*)0x57FB08, 0x20A));

    int screen_size = this->registry->RegGetInt(1, (char*)0x57FAFC);
    switch (screen_size) {
    case 0x280:
            this->prog_info->main_wid = 0x280;
            this->prog_info->main_hgt = 0x1E0;
        break;
    case 0x320:
            this->prog_info->main_wid = 0x320;
            this->prog_info->main_hgt = 0x258;
        break;
    case 0x400:
            this->prog_info->main_wid = 0x400;
            this->prog_info->main_hgt = 0x300;
        break;
    case 0x500:
            this->prog_info->main_wid = screen_size;
            this->prog_info->main_hgt = 0x400;
        break;
    }

    int rollover = this->registry->RegGetInt(1, (char*)0x57FAEC);
    if (rollover == 2)
        this->rollover = 0;
    else
        this->rollover = 1;

    int mouse_style = this->registry->RegGetInt(1, (char*)0x57FAE0);
    if (mouse_style == 2)
        this->prog_info->interface_style = 2;
    else if (mouse_style == 1)
        this->prog_info->interface_style = 1;

    ms.dwLength = this->registry->RegGetInt(1, (char*)0x57FAD4);
    if (ms.dwLength != 0xFFFFFFFF)
        this->game_speed = (float)(int)ms.dwLength * DAT_0056f014;

    int difficulty = this->registry->RegGetInt(1, (char*)0x57FAC8);
    if (difficulty != -1)
        this->single_player_difficulty = difficulty;

    int path_finding = this->registry->RegGetInt(1, (char*)0x57FAB8);
    if (path_finding >= 1 && path_finding <= 3)
        this->setPathFinding((unsigned char)(path_finding - 1));

    int mp_path_finding = this->registry->RegGetInt(1, (char*)0x57FAA8);
    if (mp_path_finding >= 1 && mp_path_finding <= 3)
        this->setMpPathFinding((unsigned char)(mp_path_finding - 1));

    int scroll_speed = this->registry->RegGetInt(1, (char*)0x57FA98);
    if (scroll_speed != -1 && scroll_speed >= 10 && scroll_speed <= 200) {
        *(int*)((char*)this->prog_info + 0x8C8) = scroll_speed;
        *(int*)((char*)this->prog_info + 0x8D0) = scroll_speed;
    }

    if (_findfirst((char*)0x57FA8C,
                   (struct _finddata_t*)&file_info.time_create) == -1) {
        this->error_code = 0x17;
    }
    else {
        if (!this->setup_cmd_options()) {
            this->error_code = 2;
        }
        else {
            StringTable = LoadLibraryA((char*)this + 0x2ED);
            if (StringTable == 0) {
                this->error_code = 1;
            }
            else {
                GlobalMemoryStatus((LPMEMORYSTATUS)&ms.dwMemoryLoad);
                if ((ms.dwTotalPageFile >= 0x1400000 &&
                     ms.dwTotalVirtual >= 0xA00000) ||
                    (ms.dwTotalPageFile >= 0xA00000 &&
                     ms.dwTotalVirtual >= 0x1400000) ||
                    ms.dwTotalVirtual >= 0x1E00000) {
                this->set_interface_messages();

                if (debugActions == 1)
                    actionFile = fopen((char*)0x57FA78, (char*)0x57FA88);

                if (this->prog_info->check_expiration != 0 &&
                    this->check_expiration() == 0) {
                    this->error_code = 3;
                }
                else if (this->prog_info->check_multi_copies != 0 &&
                         this->check_multi_copies() == 0) {
                    this->error_code = 4;
                }
                else if (this->check_prog_argument((char*)0x57FA6C) == 0 &&
                         (GetDXVersion(&ms.dwLength, &DXVersion),
                          ms.dwLength < 0x501)) {
                    this->error_code = 0x14;
                }
                else {
                    SystemParametersInfoA(0x10, 0,
                                           &this->screen_saver_enabled, 0);
                    if (this->screen_saver_enabled != 0)
                        SystemParametersInfoA(0x11, 0, 0, 2);
                    SystemParametersInfoA(0x53, 0,
                                           &this->low_power_enabled, 0);
                    if (this->low_power_enabled != 0)
                        SystemParametersInfoA(0x55, 0, 0, 2);

                    this->save_check_for_cd = this->check_for_cd(0);
                    if (!this->setup_class())
                        this->error_code = 5;
                    else if (!this->setup_main_window())
                        this->error_code = 6;
                    else if (!this->setup_graphics_system()) {
                        if (this->error_code == 0)
                            this->error_code = 7;
                    }
                    else if (!this->setup_palette())
                        this->error_code = 0x11;
                    else if (!this->setup_shapes())
                        this->error_code = 7;
                    else if (!this->setup_map_save_area())
                        this->error_code = 7;
                    else if (!this->setup_mouse())
                        this->error_code = 8;
                    else if (!this->setup_sound_system())
                        this->error_code = 0x0A;
                    else if (!this->setup_chat())
                        this->error_code = 0x10;
                    else if (!this->setup_comm())
                        this->error_code = 9;
                    else if (!this->setup_fonts())
                        this->error_code = 0x0B;
                    else if (!this->setup_sounds())
                        this->error_code = 0x0C;
                    else {
                        driveInfo = new DriveInformation;
                        if (driveInfo != 0) {
                            if (!this->setup_blank_screen()) {
                                this->error_code = 0x0D;
                            }
                            else {
                            int file_number;
                            this->set_prog_mode(0);
                            this->setup_timings();
                            this->handle_size(this->prog_window, 0, 0, 0);
                            this->prog_ready = 1;
                            ShowWindow(this->prog_window, 5);
                            SetFocus(this->prog_window);
                            this->mouse_on();
                            this->is_timer = SetTimer(this->prog_window,
                                                      1, 0x32, 0);

                            file_number = this->registry->RegGetInt(
                                0, (char*)0x57FA58);
                            if (file_number >= 0) {
                                file_number = this->registry->RegGetInt(
                                    0, (char*)0x57FA58);
                                sprintf(filename + 4, (char*)0x57FA4C,
                                        file_number);
                                this->player_game_info =
                                    new RGE_Game_Info(filename + 4);
                            }
                            else {
                                int i;
                                for (i = 0; i < 9999; ++i) {
                                    sprintf(filename + 4, (char*)0x57FA4C, i);
                                    if (_findfirst(
                                            filename + 4,
                                            (struct _finddata_t*)&file_info.time_create) == -1) {
                                        this->registry->RegSetInt(
                                            0, (char*)0x57FA58, i);
                                        this->player_game_info =
                                            new RGE_Game_Info(filename + 4);
                                        break;
                                    }
                                }
                            }
                            sprintf(filename + 4, (char*)0x57FA3C,
                                    this->prog_info->scenario_dir);
                            this->scenario_info = new RGE_Scenario_File_Info(
                                filename + 4);

                            if (do_draw_log != 0) {
                                if (draw_log_name[0] == 0) {
                                    int i;
                                    for (i = 0; i < 1000; ++i) {
                                        sprintf(s + 4, (char*)0x57FA2C, i);
                                        if (OpenFile(s + 4,
                                                     (LPOFSTRUCT)&of.Reserved1,
                                                     0x4000) == -1) {
                                            draw_log = fopen(s + 4,
                                                             (char*)0x57FA88);
                                            strcpy(draw_log_name, s + 4);
                                            break;
                                        }
                                    }
                                }
                                else {
                                    draw_log = fopen(draw_log_name,
                                                     (char*)0x57FA88);
                                }
                            }

                            if (do_fps_log != 0) {
                                fps_log = fopen((char*)0x57FA20,
                                                (char*)0x57FA88);
                                if (fps_log == 0)
                                    do_fps_log = 0;
                            }

                                return 1;
                            }
                        }
                    }
                }
            }
            else {
                this->error_code = 0x16;
            }
        }
    }
    }
    return 0;
}


// PDB ownership: scratch/0041C270_RGE_Base_Game.cpp
// VA: 0041C270 ~RGE_Base_Game (1136 B)
// PDB source: basegame.cpp:877-1083
// Attempt log:
// - Baseline packet scaffold used free-function shims and missed the original
//   member/destructor, CRT, Win32-import, and function-pointer call surfaces.
// - Reconstructing the typed RGE_Base_Game ownership and ordinary destructor
//   sequence is the current source-first candidate; exactness remains pending.
// - Typed member calls, CRT/Win32 imports, and the two natural cleanup loops now
//   reproduce all 56 ordered call sites and the 0x110 frame.
// - The rollover conditional, mouse-style if/else, and saved scenario pointer
//   progressively aligned the early body; the final remaining hunk begins at
//   the fonts loop and leaves 413 positional bytes with exact size.
// - A manual vptr restore was rejected by source policy; the natural virtual
//   destructor surface is retained while the remaining codegen drift is paused.
// - The original clears the +0x1B0 prog-mode slot before world cleanup; the
//   generated field map does not support clearing game_mode at +0x1B4 here.
// - Direct RegGetInt testing, nested player-info cleanup ownership, and local
//   destructor pointers reproduce the original block structure through fonts.
// - RGE_Font is a 0xC record with its DeleteObject handle at offset zero; the
//   remaining drift is the imported-call cache and loop register coloring.
// - A local cached DeleteObject pointer inside the positive-count guard added
//   8 bytes to the frame and worsened the match; restored the direct call.
// - An explicit positive font-count guard is a natural binary-supported source
//   shape and reduced the localized drift from 413 to 266 bytes.
// - The Windows header/HGDIOBJ surface and a const local API pointer were
//   codegen duplicates; the local pointer was removed from the final source.
// - Managed pass 2026-08-17: twenty focused probes kept this source as the
//   clean best. A pre-guard do-while recovered the initial xor/cmp block but
//   lost the natural loop basin. Typed counter/index locals, bound polarity,
//   handle locals, continue form, import-pointer declarations, and local
//   DeleteObject aliases were unchanged, worse, or added frame bytes.
// - Original evidence still requires one cached DeleteObject IAT load in EBX,
//   test EAX, and a post-call font_num reload. The clean source emits a direct
//   IAT call and cmp EAX,EBX. No policy-compliant source cause is proven.
// - Behavior audit fixed two source defects. SystemParametersInfoA uses the
//   executable's uiParam value 1 for actions 0x11 and 0x55. get_string uses
//   the binary-proven (string_id, buffer, size) parameter order.
// BLOCKER: the executable caches the DeleteObject import target once before
// the font loop. The rebuild reads the writable import slot for each call. A
// prior external call can therefore change a later call target only in the
// rebuild. Keep the corrected natural destructor in scratch.
// - Managed pass 2026-08-22: a separate count and byte-offset do-while matched
//   the original pre-loop guard and raised exact-block coverage to 95.34%.
//   It still emitted cmp EAX,EBX and a direct IAT call, added three
//   instructions, and caused call-map drift after the loop. Local mutable,
//   register, const, and file-scope DeleteObject aliases did not change it;
//   the file-scope alias also changed the extracted owner. Restored the
//   smallest typed for-loop source as the clean reconstruction.
class RGE_Game_Info;
class RGE_Scenario_File_Info;


class TDrawSystem;
class TDrawArea;
class TShape;
class TSound_Driver;
class TMusic_System;
class TDigital;
class TCommunications_Handler;
class TDebuggingLog;
class TRegistry;
class TMousePointer;

class TChat;
class TPanelSystem;
class DriveInformation;

extern void __cdecl debug_random_write(void);
extern void __cdecl dump_vismap_log(void);
extern void __cdecl operator delete(void*);
extern "C" void __cdecl free(void*);

extern "C" __declspec(dllimport) int __stdcall SystemParametersInfoA(
    unsigned int action, unsigned int param, void* value, unsigned int flags);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* handle);
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(void* window);
extern "C" __declspec(dllimport) void* __stdcall FindWindowA(
    const char* class_name, const char* window_name);
extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* window, unsigned int message, unsigned int wparam, long lparam);
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* module);
extern int do_debug_random;
extern int wrote_debug_random_log;
extern FILE* actionFile;
extern FILE* fps_log;
extern FILE* draw_log;
extern void* StringTable;
extern DriveInformation* driveInfo;
extern TChat* chat;
class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;
extern float DAT_0056f018;












extern TPanelSystem panel_system;
RGE_Base_Game::~RGE_Base_Game()
{
    int i;
    char filename[13];
    char str[256];

    if (do_debug_random && !wrote_debug_random_log) {
        debug_random_write();
        dump_vismap_log();
    }

    if (this->draw_system != 0) {
        this->registry->RegSetInt(1, "Screen Size", this->draw_system->ScreenWidth);
    }

    this->registry->RegSetInt(1, "Rollover Text",
        2 + (this->rollover ? -1 : 0));

    if (this->prog_info->interface_style == 2)
        this->registry->RegSetInt(1, "Mouse Style", 2);
    else
        this->registry->RegSetInt(1, "Mouse Style", 1);

    this->registry->RegSetInt(1, "Game Speed",
        (int)(this->game_speed * DAT_0056f018));
    this->registry->RegSetInt(1, "Difficulty", this->single_player_difficulty);
    this->registry->RegSetInt(1, "Path Finding", this->pathFinding() + 1);
    this->registry->RegSetInt(1, "MP Path Finding", this->mpPathFinding() + 1);
    this->registry->RegSetInt(
        1, "Scroll Speed", this->prog_info->mouse_scroll_interval);

    if (actionFile != 0) {
        fclose(actionFile);
        actionFile = 0;
    }
    if (fps_log != 0) {
        fclose(fps_log);
        fps_log = 0;
    }
    if (draw_log != 0) {
        fclose(draw_log);
        draw_log = 0;
    }

    RGE_Scenario_File_Info* scenario_info = this->scenario_info;
    if (scenario_info != 0) {
        scenario_info->~RGE_Scenario_File_Info();
        operator delete(scenario_info);
        this->scenario_info = 0;
    }

    if (this->player_game_info != 0) {
        if (this->registry->RegGetInt(0, "Game File Number") >= 0) {
            int file_number = this->registry->RegGetInt(0, "Game File Number");
            sprintf(filename, "game%d.nfo", file_number);
            this->player_game_info->save(filename);
        }
        RGE_Game_Info* player_game_info = this->player_game_info;
        if (player_game_info != 0) {
            player_game_info->~RGE_Game_Info();
            operator delete(player_game_info);
        }
        this->player_game_info = 0;
    }

    this->prog_mode = 0;
    if (this->world != 0) {
        delete this->world;
        this->world = 0;
    }

    TDrawArea* map_save_area = this->map_save_area;
    if (map_save_area != 0) {
        map_save_area->~TDrawArea();
        operator delete(map_save_area);
        this->map_save_area = 0;
    }
    TMousePointer* mouse_pointer = this->mouse_pointer;
    if (mouse_pointer != 0) {
        mouse_pointer->~TMousePointer();
        operator delete(mouse_pointer);
        this->mouse_pointer = 0;
    }

    if (driveInfo != 0) {
        operator delete(driveInfo);
        driveInfo = 0;
    }

    TCommunications_Handler* comm_handler = this->comm_handler;
    if (comm_handler != 0) {
        comm_handler->~TCommunications_Handler();
        operator delete(comm_handler);
        this->comm_handler = 0;
    }
    TChat* chat_object = chat;
    if (chat_object != 0) {
        chat_object->~TChat();
        operator delete(chat_object);
        chat = 0;
    }

    if (this->fonts != 0) {
        if (this->font_num > 0) {
            for (i = 0; i < this->font_num; i++) {
                if (this->fonts[i].font)
                    DeleteObject(this->fonts[i].font);
            }
        }
        free(this->fonts);
        this->fonts = 0;
    }

    this->stop_sound_system();
    panel_system.destroyPanel("Blank Screen");

    TDrawSystem* draw_system = this->draw_system;
    if (draw_system != 0) {
        draw_system->~TDrawSystem();
        operator delete(draw_system);
        this->draw_system = 0;
        this->draw_area = 0;
    }

    if (this->screen_saver_enabled != 0)
        SystemParametersInfoA(0x11, 1, 0, 2);
    if (this->low_power_enabled != 0)
        SystemParametersInfoA(0x55, 1, 0, 2);

    if (this->prog_palette != 0) {
        panel_system.release_palette(this->prog_palette);
        this->prog_palette = 0;
    }

    TRegistry* registry = this->registry;
    if (registry != 0) {
        registry->~TRegistry();
        operator delete(registry);
        this->registry = 0;
    }

    if (this->prog_mutex != 0) {
        CloseHandle(this->prog_mutex);
        this->prog_mutex = 0;
    }

    rge_base_game = 0;

    if (this->prog_window != 0)
        DestroyWindow(this->prog_window);

    this->get_string(0x3EB, str, 0x100);
    if (str[0] != 0) {
        void* help_window = FindWindowA("MS_WINHELP", str);
        if (help_window != 0)
            SendMessageA(help_window, 0x10, 0, 0);
    }

    if (StringTable != 0 && StringTable != (void*)this->prog_info->instance) {
        FreeLibrary(StringTable);
        StringTable = 0;
    }

    TDebuggingLog* debug_log = this->debugLog;
    if (debug_log != 0) {
        debug_log->~TDebuggingLog();
        operator delete(debug_log);
        this->debugLog = 0;
    }

    if (this->shapes != 0) {
        for (i = 0; i < this->shape_num; ++i) {
            TShape* shape = this->shapes[i];
            if (shape != 0) {
                shape->~TShape();
                operator delete(shape);
            }
        }
        free(this->shapes);
    }
}


// PDB ownership: matching/0041C7D0_reset_timings.cpp
void RGE_Base_Game::reset_timings() {
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;

    for (int i = 0; i < 30; ++i) {
        this->timings[i].accum_time = 0;
        this->timings[i].last_time = 0;
        this->timings[i].start_time = 0;
        this->timings[i].last_single_time = 0;
        this->timings[i].max_time = 0;
        this->timings[i].last_max_time = 0;
    }
}


// PDB ownership: matching/0041C830_add_to_timing.cpp
// 0041C830 RGE_Base_Game::add_to_timing (60B)
// basegame.cpp


void RGE_Base_Game::add_to_timing(int index, unsigned long value) {
    timings[index].accum_time += value;
    timings[index].last_single_time = value;
    if (value > timings[index].max_time) {
        timings[index].max_time = value;
    }
}


// PDB ownership: matching/0041c870_increment_world_update_count.cpp
void RGE_Base_Game::increment_world_update_count() {
    this->world_update_count++;
}


// PDB ownership: matching/0041c880_increment_view_update_count.cpp
void RGE_Base_Game::increment_view_update_count() {
    this->view_update_count++;
}


// PDB ownership: matching/0041C890_set_last_single_time.cpp
void RGE_Base_Game::set_last_single_time(int i, unsigned long v) {
    this->timings[i].last_single_time = v;
}


// PDB ownership: matching/0041C8B0_get_last_time.cpp
unsigned long RGE_Base_Game::get_last_time(int i) {
    return this->timings[i].last_time;
}


// PDB ownership: matching/0041C8D0_get_last_single_time.cpp
unsigned long RGE_Base_Game::get_last_single_time(int i) {
    return this->timings[i].last_single_time;
}


// PDB ownership: matching/0041C8F0_get_accum_time.cpp
unsigned long RGE_Base_Game::get_accum_time(int i) {
    return *(unsigned long *)((char *)&this->timings + (i << 5));
}


// PDB ownership: matching/0041C910_get_max_time.cpp
unsigned long RGE_Base_Game::get_max_time(int i) {
    return this->timings[i].max_time;
}


// PDB ownership: matching/0041C930_get_last_max_time.cpp
unsigned long RGE_Base_Game::get_last_max_time(int i) {
    return this->timings[i].last_max_time;
}


// PDB ownership: matching/0041c950_get_last_world_update_count.cpp
unsigned long RGE_Base_Game::get_last_world_update_count() {
    return this->last_world_update_count;
}


// PDB ownership: matching/0041c960_get_last_view_update_count.cpp
unsigned long RGE_Base_Game::get_last_view_update_count() {
    return this->last_view_update_count;
}


// PDB ownership: matching/0041c970_get_world_update_count.cpp
unsigned long RGE_Base_Game::get_world_update_count() {
    return this->world_update_count;
}


// PDB ownership: matching/0041c980_get_view_update_count.cpp
unsigned long RGE_Base_Game::get_view_update_count() {
    return this->view_update_count;
}


// PDB ownership: matching/0041c990_get_error_code.cpp
int RGE_Base_Game::get_error_code() {
    return this->error_code;
}


// PDB ownership: matching/0041C9A0_get_string.cpp
static char g_string_buffer[0x200];

char* RGE_Base_Game::get_string(long id)
{
    this->get_string(id, g_string_buffer, 0x200);
    return g_string_buffer;
}


// PDB ownership: matching/0041C9C0_get_string.cpp
extern void* StringTable;

char* RGE_Base_Game::get_string(long string_id, char* buffer, int buffer_size) {
    int result = LoadStringA(StringTable, string_id, buffer, buffer_size);
    if (!result) {
        *buffer = 0;
    }
    buffer[buffer_size - 1] = 0;
    return buffer;
}


// PDB ownership: matching/0041C9F0_get_string.cpp
char* RGE_Base_Game::get_string(int p1, long p2, char* buf, int maxlen)
{
    return this->get_string2(p1, p2, 0, buf, maxlen);
}


// PDB ownership: matching/0041CA10_get_string2.cpp
// RGE_Base_Game::get_string2
// VA: 0041CA10
// PDB: basegame.cpp:1265-1325

// Attempt log:
// - Normal if/else and decrement-cascade forms preserved the call set but put
//   the nested switch inline and produced the wrong first branch topology.
// - An outer switch on param_1, with case 1 containing the param_2 switch and
//   case 2 calling vf20 directly, reproduced the original dec/je/dec/jne
//   dispatch and outlined switch bodies exactly.
// - Ordinary switch breaks (not fallback gotos) retain the exact bytes and the
//   natural common truncation tail. The long parameter spellings match the PDB
//   ABI without changing VC5 output.

char* RGE_Base_Game::get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5)
{
    *param_4 = 0;

    switch (param_1) {
    case 1:
        switch (param_2) {
        case 1: case 2: case 3: case 4: case 5: case 6:
        case 0x0E: case 0x0F:
            return this->get_string(0x7D2, param_4, param_5);
        case 7: case 8: case 0x0B: case 0x0D: case 0x11:
            return this->get_string(0x7D3, param_4, param_5);
        case 0x13:
            return this->get_string(0x7DB, param_4, param_5);
        case 9: case 0x10:
            return this->get_string(0x7D5, param_4, param_5);
        case 0x0A: case 0x0C:
            return this->get_string(0x7D4, param_4, param_5);
        case 0x12:
            return this->get_string(0x7DC, param_4, param_5);
        case 0x14:
            return this->get_string(0x7DD, param_4, param_5);
        case 0x15:
            return this->get_string(0x7DE, param_4, param_5);
        case 0x16:
            return this->get_string(0x7DF, param_4, param_5);
        case 0x17:
            return this->get_string(0x7E0, param_4, param_5);
        default:
            break;
        }
        break;
    case 2:
        return this->get_string(param_2, param_4, param_5);
    default:
        break;
    }

    param_4[param_5 - 1] = 0;
    return param_4;
}


// PDB ownership: matching/0041CB80_get_scenario_info.cpp
// VA: 0041CB80 RGE_Base_Game::get_scenario_info (275 B)
// PDB source: basegame.cpp
// Attempt log:
// baseline: packet-based reconstruction with local shim and free open_scenario wrapper;
// it preserved the frame but emitted the wrong direct call and a two-byte overrun.
// probe 2: restored the same-TU typed RGE_Game_Info member and RGE_Base_Game virtual
// slot surface used by get_scenario_header; this is the canonical source shape.
// probes 3-4: reading the final header into the filename buffer removed the four-byte
// local frame slot; an unused header_size declaration did not preserve it.
// probe 5: using the packet-declared header_size as the final read destination restored
// the 0x138 frame and left only the two filename LEA displacements.
// probes 6-7: declaration reordering was a codegen duplicate; probe 8's aggregate work
// window changed liveness and was rolled back.
// probe 9: with the separate header_size stack scalar, the natural temp_name base is
// already the binary's effective +4 address; removing the redundant source offset is exact.

extern int sprintf(char* buf, const char* fmt, ...);
extern int rge_open(char* path, int flags);
extern void rge_read_uncompressed(int fd, void* buf, int len);
extern void rge_read(int fd, void* buf, int len);
extern int rge_close(int fd);
extern void* malloc(int size);
extern "C" void free(void* p);




class RGE_Scenario;
RGE_Scenario* RGE_Base_Game::get_scenario_info(char* param1, int param2)
{
    char temp_name[300];
    int fd;
    int version;
    int obj_id;
    int header_size;
    RGE_Scenario* result;
    void* buf;

    sprintf(temp_name, "%s%s", this->prog_info->scenario_dir, param1);

    if (param2) {
        fd = this->player_game_info->open_scenario();
    } else {
        if (!param1)
            return 0;
        fd = rge_open(temp_name, 0x8000);
    }

    if (fd == -1)
        return 0;

    rge_read_uncompressed(fd, &obj_id, 4);
    rge_read_uncompressed(fd, &version, 4);

    if (version > 0) {
        buf = malloc(version);
        if (!buf) {
            rge_close(fd);
            return 0;
        }
        rge_read_uncompressed(fd, buf, version);
        free(buf);
    }

    rge_read(fd, &header_size, 4);

    result = this->new_scenario_info(fd);
    rge_close(fd);
    return result;
}


// PDB ownership: matching/0041CCA0_get_scenario_header.cpp
// VA: 0041CCA0 RGE_Base_Game::get_scenario_header (253 B)
// PDB source: basegame.cpp
// Attempt log:
// baseline: canonical scenario filename/open/read/version-gate reconstruction;
// the initial local shim still used free helper wrappers and had a 0x12C frame.
// probe 2: typed RGE_Game_Info::open_scenario and RGE_Base_Game virtual dispatch
// fixed the ordered call surface and reduced the mismatch to stack/codegen shape.
// probe 3: restored the observed vtable slot 0x38 (one additional preceding slot).
// probe 4: reading directly into version produced the correct 0x130 frame but
// shifted the filename buffer by four bytes; probe 5 declaration reordering was
// a codegen duplicate. Probe 6 reproduced the same direct-read result.
// probe 7: a typed local work window for the PDB-proven 300-byte temp_name and
// adjacent version slot, while keeping the compared scalar separate, matched.
// probe 8: using the aggregate version member emitted an extra store/reload;
// probe 9: reading into that member selected the wrong stack address. Rolled
// both back; retain the best period-plausible typed window and scalar compare.
// Main-agent audit restored the canonical base-game destructor slot; emitted
// code remains exact.

extern int sprintf(char* buf, const char* fmt, ...);
extern int rge_open(char* path, int flags);
extern void rge_read_uncompressed(int fd, void* buf, int len);
extern int rge_close(int fd);




class RGE_Scenario_Header;
struct Scenario_Header_Work {
    char temp_name[300];
    int version;
};

RGE_Scenario_Header* RGE_Base_Game::get_scenario_header(char* param1, int param2)
{
    int version;
    Scenario_Header_Work work;
    int fd;
    RGE_Scenario_Header* result;

    sprintf(work.temp_name + 4, "%s%s", this->prog_info->scenario_dir, param1);

    if (param2) {
        fd = this->player_game_info->open_scenario();
    } else {
        if (!param1)
            return 0;
        fd = rge_open(work.temp_name + 4, 0x8000);
    }

    if (fd == -1)
        return 0;

    rge_read_uncompressed(fd, work.temp_name, 4);
    version = *(int*)work.temp_name;

    result = 0;
    if (version == *(int*)"1.03" ||
        version == *(int*)"1.04" ||
        version == *(int*)"1.05" ||
        version == *(int*)"1.06" ||
        version == *(int*)"1.07" ||
        version == *(int*)"1.08" ||
        version == *(int*)"1.09" ||
        version == *(int*)"1.10" ||
        version == *(int*)"1.11")
    {
        result = this->new_scenario_header(fd);
    }

    rge_close(fd);
    return result;
}


// 0041CDA0 RGE_Base_Game::write_scenario_header, basegame.cpp:1503-1518
// (89 bytes).
void RGE_Base_Game::write_scenario_header(int file)
{
    RGE_Scenario_Header* header = new_scenario_header(world->scenario);

    if (header != 0) {
        header->save(file);
        delete header;
    } else {
        int header_size = 0;
        rge_write_uncompressed(file, &header_size, sizeof(header_size));
    }
}


// PDB ownership: matching/0041CE00_new_scenario_header.cpp
// attempt 1: natural `return new RGE_Scenario_Header(param_1);` shape
// result: default flags built a too-small body; the /GX context is justified for this new-helper family
// attempt 2: keep the type surface minimal but exact and let the EH/new prolog come from the compiler


RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(int param_1) {
    return new RGE_Scenario_Header(param_1);
}


// PDB ownership: matching/0041CE60_new_scenario_header.cpp
// first pass: natural `return new RGE_Scenario_Header(param_1);` shape against the EH/new prolog
// /GX was required to land the exact ctor-overload basin for the 0x14 allocation
class RGE_Scenario;

RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(RGE_Scenario* param_1) {
    return new RGE_Scenario_Header(param_1);
}


// PDB ownership: matching/0041CEC0_new_scenario_info.cpp
// attempt log:
// first pass: EH-framed new helper with the observed 0x1990 allocation and ctor(this->param, 0)
// second pass: give the scenario class an explicit 0x1990 surface so VC5 emits the requested allocation size
// target shape: allocate RGE_Scenario(0x1990), call ctor with (param_1, 0), return new object or 0

class RGE_Scenario;


RGE_Scenario* RGE_Base_Game::new_scenario_info(int param_1) {
    return new RGE_Scenario(param_1, 0);
}


// PDB ownership: matching/0041CF30_get_campaign_info.cpp
// VA: 0041CF30 RGE_Base_Game::get_campaign_info
// Exact under VC5 host with default /O2 /Oy flags.
// The +0x04 member is RGE_Game_Info::player_game_info. Keep the three
// direct getter calls and output stores in this order.


void RGE_Base_Game::get_campaign_info(long& campaign, long& player, long& num_campaigns) {
    int c = this->player_game_info->get_current_campaign();
    campaign = c;
    int p = this->player_game_info->get_current_player();
    player = p;
    int n = this->player_game_info->get_current_scenario();
    num_campaigns = n;
}


// PDB ownership: matching/0041CF70_set_campaign_info.cpp
unsigned char RGE_Base_Game::set_campaign_info(long campaign, long person, long scenario) {
    unsigned char ok;

    ok = this->player_game_info->set_current_campaign(campaign);
    if (ok != 0) {
        ok = this->player_game_info->set_current_person(person);
        if (ok != 0) {
            ok = this->player_game_info->set_current_scenario(scenario);
            if (ok != 0) {
                return 1;
            }
        }
    }
    return 0;
}


// PDB ownership: matching/0041CFC0_set_campaign_win.cpp
void RGE_Base_Game::set_campaign_win() {
    this->player_game_info->notify_of_scenario_complete();
}


// PDB ownership: matching/0041CFD0_run.cpp
// VA: 0041CFD0 RGE_Base_Game::run
// PDB source: basegame.cpp lines 1578-1640

#define P_GetMessageA      (*(int (__stdcall **)(void*, void*, unsigned int, unsigned int))0x88A7C0)
#define P_TranslateMessage (*(int (__stdcall **)(void*))0x88A7D0)
#define P_PeekMessageA     (*(int (__stdcall **)(void*, void*, unsigned int, unsigned int, unsigned int))0x88A7D4)
#define P_DispatchMessageA (*(int (__stdcall **)(void*))0x88A7D8)



struct MSG_PART {
    unsigned int message;
    unsigned int wParam;
    long lParam;
    unsigned long time;
    long pt_x;
    long pt_y;
    int pad_18;
};
struct tagMSG;


int RGE_Base_Game::run()
{
    MSG_PART msg;
    int (__stdcall *translate)(void*) = P_TranslateMessage;
    int (__stdcall *peek)(void*, void*, unsigned int, unsigned int, unsigned int) = P_PeekMessageA;
    int (__stdcall *dispatch)(void*) = P_DispatchMessageA;

    while (1) {
        if (this->prog_active != 0 && (this->prog_mode == 4 || this->prog_mode == 2)) {
            TCommunications_Handler* comm = this->comm_handler;
            if (comm == 0 || comm->IsPaused() == 0) {
                if (peek(&msg.message, 0, 0, 0, 1) != 0) {
                    if (msg.wParam == 0x12) {
                        return msg.lParam;
                    }
                    if (this->handle_message((tagMSG*)&msg.message) != 0) {
                        translate(&msg.message);
                        dispatch(&msg.message);
                    }
                } else {
                    this->handle_idle();
                }
                continue;
            }
        }

        if (P_GetMessageA(&msg.message, 0, 0, 0) == 0) {
            return msg.lParam;
        }
        translate(&msg.message);
        dispatch(&msg.message);
    }
}


// PDB ownership: matching/0041D0A0_setup_cmd_options.cpp
// VA: 0041D0A0 RGE_Base_Game::setup_cmd_options (5726 B)
// PDB source: basegame.cpp lines 1646-2199
//
// attempt log:
// v3: full function with all extern game function calls, trying to close the size gap
// v2: Ghidra-like iVar2 pattern â€” 5568 bytes (too small)
// v1: first-pass full body â€” 5664-5680 bytes
// missing: game func calls 0047F580, 004362B0, 00436330, 004362F0, 004227F0
// v4: fixed VC5-incompatible __thiscall extern declarations by modeling member calls.
// v5: changed local buffers to 256+256; stack frame moved from 0x208 to target family.
// v6: identified _mbsninc(ptr,1) (two-arg) vs _mbsinc(ptr); restores full-size family with 42 calls.
// v7: changed MBCS helper surface to char* and removed unsigned casts; current build is 5712 bytes, 14 short, with compiler choosing edi=this/ebp=1 and 0x204 frame instead of original ebp=this/edi=1 and 0x200 frame.
// lab 20260429_114927: mbs_surface/local_shape/null_style axes collapsed to same 5712-byte asm; unsigned casts and local order are not the current lever.
// probe: replacing literal constants with broken uninitialized one/zero accidentally forced ebp=this but introduced 0x204 frame/stale local load, so useful clue only: register pressure around constant one/zero controls this-register choice.
// lab 20260429_120746: tried matched-function lesson from 0040D3B0 (early named zero/one temps, macro-assignment variants); all 36 compiled variants collapsed to same 5712-byte edi=this/ebp=1 group.
// probe: direct strstr() conditions changed early cmp eax,ebx to original-like test eax,eax, but did not move prologue/register assignment or size.
// lab 20260429_121211: header/import and useless declaration context axes (manual vs string/stdlib, mbstring, windows; extra CRT/WinAPI/game decls; extra class members/virtuals) produced 4 asm groups, all 5712 bytes and same first mismatch sub esp 204/edi=this. windows.h context had better edit diff (~7352 vs 9223) but did not fix prologue.
// probe: broken uninitialized register one/zero forced original-like ebp=this but kept sub esp,204; a valid initialized register self+one form rechecked later still compiled to edi=this with the 0x204 frame. Useful clue only: register pressure can move this, but the valid source surface has not.
// TU probe: target-first basegame.cpp reconstruction axes (#line 1646 donor path, windows/string/stdlib context via prior representative, and a real-vptr/full virtual RGE_Base_Game surface with gap_04[8]) all stayed in the same 5712-byte sub esp,204 / edi=this basin. Full TU declarations before the body are not the missing prologue lever so far.
// paste-test 20260429: inspected current stack refs; the extra 4-byte slot is [esp+14] holding spilled this (mov [esp+14],edi; later reload after pushes), not a pcVar3/iVar2 slot near [esp+210]. Tested no broad temporaries/direct strstr/scoped parse pointer/name p/result return/result-for-ones variants; all valid variants stayed 5712 bytes with sub esp,204 and edi=this. Pointer-first while condition shrank to 5552 and still kept sub esp,204, so rolled back.
// paste-test 2: valid game=this alias variants (before buffers, after buffers, register) did not change prologue. Prefix bisection: prefixes through SPEED2/NOMUSIC keep sub esp,200; adding auto custom_mouse flips to sub esp,204, but deleting the final three tail blocks together from full restores sub esp,200/ebp=this while deleting any one tail block does not. Rewriting NOMUSIC/auto/NORMALMOUSE as direct/nested/truthy/1-left did not alter the full prologue.
// next probes: changing long-lived 1 spelling (int one assigned separately, const int, enum, expression after CharUpper, 1U/(unsigned)1/sizeof(char)/true for MBCS counts, int count declarations) and final auto assignment variants (assign full_screen/use_dir_draw/inc) all stayed in the same sub esp,204 / edi=this / hidden-home basin. The flip appears to be whole-function register-pressure threshold, not a single literal spelling.
// natural tail-shape lab: 78 variants across NOMUSIC/auto/NORMALMOUSE direct/nested/empty-else/prog-local/order-preserving combined forms all stayed sub esp,204. Reordering late blocks so the SPEED1/SPEED2 parse blocks move after NOMUSIC/auto/NORMALMOUSE flips to good sub esp,200/ebp=this but changes source/call order and text size 5728, so it is only a clue: speed parse + final tail adjacency is the pressure trigger.
// speed/tail iteration: SPEED1/SPEED2 natural parse variants (scoped p, assignment-in-if, for/while/no-brace, pointer-first condition, char temp, value temp, &tempStr) and mixes all stayed sub esp,204. Combining direct/scoped cleanup with nested tail stayed bad. Caching tail predicate values before SPEED flips ebp=this but adds stack locals/frame 204, so not usable; ternary/flag final-tail forms stayed bad.
// focused late-region classifier lab: 120 combinations over speed scope/shape (current/braces/scoped p/assign-if/for), tail scope/shape (current/braces/direct/nested/prog-local), and one/zero spelling (none/result/enum/local zero-one) produced no target-basin hits; every order-preserving variant kept frame 204, this=edi, zero=ebx, one=ebp, hidden home. See build/temp/focused_late_region_lab_summary.txt.
// progress 20260429: cast all _ismbcspace inputs to (unsigned char)*pcVar3. This matches original zero-extend loop idiom family and brings object text size to exact 5726 bytes; remaining mismatch still starts at prologue (rebuilt frame 204/edi=this/ebp=1/hidden this home vs original frame 200/ebp=this/edi=1).
// tail-order clue rechecked after unsigned _ismbcspace casts: build/temp/0041D0A0_order_tail_before_speeds.cpp moves NOMUSIC/auto/NORMALMOUSE before SPEED1/SPEED2 and gets frame 200/ebp=this/no hidden home, with exact size 5726 and first mismatch at 0x2C. It still chooses xor edi,edi and materializes one in ebx later, and it changes option parse order, so it is a pressure clue only, not a keepable fix.
// probes after the cast: scoped SPEED1/SPEED2 local p, final-tail pcVar3 reuse, and local declaration order variants all stayed in the bad frame 204/edi=this basin. Re-running tailnatural_probe after casts found no order-preserving tail-shape hit; individual tail rewrites generally became 5728 bytes and still had hidden this home.
// deeper tail probe: deleting any one of SPEED1, SPEED2, NOMUSIC, auto-custom-mouse, or NORMALMOUSE is enough to restore the original prologue, so the current full tail is just over a global pressure cliff. A non-equivalent clue variant changing auto-custom-mouse to `(use_dir_draw + full_screen) == 2` also restores frame 200/ebp=this/ebx=0/edi=1 and exact size 5726; with first five early OR checks spelled direct it matches the early test-eax family too, but the auto expression is not binary-observed tail behavior and was not kept. See build/temp/0041D0A0_autosum_direct5.cpp.
// continued auto-tail search: faithful spellings `1 ==`, reversed compare order, nested ifs, `!(x != 1)`, bitwise `&` of comparisons, and empty-else forms all stayed in the bad 204-frame basin. A semantically guarded pressure form `((use_dir_draw + full_screen) == 2 && use_dir_draw == 1 && full_screen == 1)` restores the prologue/size, but adds extra tail reads/tests and still mismatches early at 0x53 (or 0x44 with broader direct-OR rewrites), so not kept.
// more non-kept probes: auto assignment RHS variants (`= use_dir_draw`, `= full_screen`, bool/product/sum-derived) did not move prologue. Boolean-sum auto conditions like `((use_dir_draw == 1) + (full_screen == 1)) == 2` restore prologue but generate non-original tail logic. Bracing/clearing state across the SPEED2->NOMUSIC boundary had no effect. Converting all/simple groups of triple OR checks to direct `strstr(...) || ...` improves local test-eax shape but alone does not fix the prologue.
// progress 20260429: corrected the visible command-option string spelling to match the original string triplets (compact, spaced, underscored) and rewrote '=' scans with an explicit cVar1 like Ghidra/source; codegen is unchanged (still exact size 5726, first mismatch prologue sub esp 204/edi=this hidden-home). Tested strstr-as-int surface and /G5 flag as probes; both were codegen-identical, so not kept as special context.

extern "C" {
char* __cdecl strstr(const char* str, const char* substr);
char* __cdecl strncpy(char* dest, const char* src, unsigned int count);
long __cdecl atol(const char* str);
char* __cdecl _mbsstr(const char* str, const char* substr);
char* __cdecl _mbsninc(const char* str, unsigned int count);
int __cdecl _ismbcspace(unsigned int c);
char* __cdecl _mbsncat(char* dst, const char* src, unsigned int count);
}

// Game function declarations matching original asm calls
void __cdecl RESFILE_Set_Missing_Flag(int flag);

extern "C" {
TDebuggingLog* g_L;                                       // 62C4FC â€” global debugLog pointer
}

// Module globals
extern "C" {
extern int all_cp;
extern int do_run_log;
extern int do_debug_timeGetTime;
extern int do_fixed_update;
extern int debug_timeGetTime_interval;
extern long fixed_update_time;
extern int useComputerPlayers;
extern int startLoggingAI;
extern int logStatusOn;
extern int allowAIToCheat;
extern int chatCheatCodes;
extern int logUpdateChanges;
extern int useInfluencePlacement;
extern int all_grassland_on;
extern int numberPathingIterations;
extern int useNewPathing;
extern int pathingCapValue;
extern int force_cd;
extern int do_fps_log;
extern int Sys_DDLOG_Enable;
extern int Sys_DDLOG_ErrorOn;
extern int DDlogAutoFlush;
extern int debug_log_lock;
extern int do_debug_random;
extern int debugActions;
extern int resend_adj1;
extern int resend_adj2;
extern int specificAIPlayerToLog;
extern int logDebugID;
extern int speed_val1;
extern int speed_val2;
extern int do_draw_log;
extern int safe_draw_log;
extern char draw_log_name[260];
extern unsigned char shape_file_first;
extern unsigned char sound_file_first;
extern int log_output;
extern int DDSys_CanColorFill;
extern unsigned char do_color_log;
}

int RGE_Base_Game::setup_cmd_options()
{
    char cmdLine[256];
    char tempStr[256];
    char cVar1;
    char* pcVar3;

    strncpy(cmdLine, this->prog_info->cmd_line, 0xFF);
    cmdLine[0xFF] = 0;
    CharUpperA(cmdLine);

    // NOSTARTUP
    if ((strstr(cmdLine, "NOSTARTUP") != 0) || (strstr(cmdLine, "NO STARTUP") != 0) || (strstr(cmdLine, "NO_STARTUP") != 0)) {
        this->prog_info->skip_startup = 1;
    }

    // SYSTEMMEMORY
    if ((strstr(cmdLine, "SYSTEMMEMORY") != 0) || (strstr(cmdLine, "SYSTEM MEMORY") != 0) || (strstr(cmdLine, "SYSTEM_MEMORY") != 0)) {
        this->prog_info->use_sys_mem = 1;
    }

    // MIDIMUSIC
    if ((strstr(cmdLine, "MIDIMUSIC") != 0) || (strstr(cmdLine, "MIDI MUSIC") != 0) || (strstr(cmdLine, "MIDI_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 1;
        this->prog_info->use_wave_music = 0;
    }

    // MSYNC
    if (strstr(cmdLine, "MSYNC") != 0) {
        this->mouse_blit_sync = 1;
    }

    // MFILL
    DDSys_CanColorFill = (strstr(cmdLine, "MFILL") == 0);

    // NOSOUND
    if ((strstr(cmdLine, "NOSOUND") != 0) || (strstr(cmdLine, "NO SOUND") != 0) || (strstr(cmdLine, "NO_SOUND") != 0)) {
        this->prog_info->use_sound = 0;
    }

    // 640
    if (strstr(cmdLine, "640") != 0) {
        this->prog_info->main_wid = 0x280;
        this->prog_info->main_hgt = 0x1E0;
    }

    // 800
    if (strstr(cmdLine, "800") != 0) {
        this->prog_info->main_wid = 800;
        this->prog_info->main_hgt = 600;
    }

    // 1024
    if (strstr(cmdLine, "1024") != 0) {
        this->prog_info->main_wid = 0x400;
        this->prog_info->main_hgt = 0x300;
    }

    // ALLCP
    if (strstr(cmdLine, "ALLCP") != 0) {
        all_cp = 1;
        do_run_log = 1;
        this->comm_speed = 0;
        do_debug_timeGetTime = 1;
        debug_timeGetTime_interval = 10;
        do_fixed_update = 1;
        fixed_update_time = 20;
    }

    // RESEND1=value
    pcVar3 = _mbsstr(cmdLine, "RESEND1");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        resend_adj1 = atol(tempStr);
    }

    // RESEND2=value
    pcVar3 = _mbsstr(cmdLine, "RESEND2");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        resend_adj2 = atol(tempStr);
    }

    // NOMOUSE
    if ((strstr(cmdLine, "NOMOUSE") != 0) || (strstr(cmdLine, "NO_MOUSE") != 0)) {
        this->custom_mouse = 0;
    }

    // WING
    if (strstr(cmdLine, "WING") != 0) {
        this->prog_info->full_screen = 0;
        this->prog_info->use_dir_draw = 0;
    }

    // DIRECTDRAW
    if ((strstr(cmdLine, "DIRECTDRAW") != 0) || (strstr(cmdLine, "DIRECT DRAW") != 0)) {
        this->prog_info->use_dir_draw = 1;
    }

    // FULLSCREEN
    if ((strstr(cmdLine, "FULLSCREEN") != 0) || (strstr(cmdLine, "FULL SCREEN") != 0) || (strstr(cmdLine, "FULL_SCREEN") != 0)) {
        this->prog_info->full_screen = 1;
        this->prog_info->use_dir_draw = 1;
    }

    // VIDEOMEMORY
    if ((strstr(cmdLine, "VIDEOMEMORY") != 0) || (strstr(cmdLine, "VIDEO MEMORY") != 0) || (strstr(cmdLine, "VIDEO_MEMORY") != 0)) {
        this->prog_info->use_sys_mem = 0;
    }

    // STREAMMUSIC
    if ((strstr(cmdLine, "STREAMMUSIC") != 0) || (strstr(cmdLine, "STREAM MUSIC") != 0) || (strstr(cmdLine, "STREAM_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 1;
    }

    // IMAMUSIC
    if ((strstr(cmdLine, "IMAMUSIC") != 0) || (strstr(cmdLine, "IMA MUSIC") != 0) || (strstr(cmdLine, "IMA_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 1;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }

    // FASTVIEW
    if ((strstr(cmdLine, "FASTVIEW") != 0) || (strstr(cmdLine, "FAST VIEW") != 0) || (strstr(cmdLine, "FAST_VIEW") != 0)) {
        this->prog_info->fast_view = 1;
    }

    // SLOWVIEW
    if ((strstr(cmdLine, "SLOWVIEW") != 0) || (strstr(cmdLine, "SLOW VIEW") != 0) || (strstr(cmdLine, "SLOW_VIEW") != 0)) {
        this->prog_info->fast_view = 0;
    }

    // ONEBUTTON
    if ((strstr(cmdLine, "ONEBUTTON") != 0) || (strstr(cmdLine, "ONE BUTTON") != 0) || (strstr(cmdLine, "ONE_BUTTON") != 0)) {
        this->prog_info->interface_style = 1;
    }

    // TWOBUTTON
    if ((strstr(cmdLine, "TWOBUTTON") != 0) || (strstr(cmdLine, "TWO BUTTON") != 0) || (strstr(cmdLine, "TWO_BUTTON") != 0)) {
        this->prog_info->interface_style = 2;
    }

    // RUNLOG
    if (strstr(cmdLine, "RUNLOG")) {
        do_run_log = 1;
    }

    // SYNCMSG
    if (strstr(cmdLine, "SYNCMSG")) {
        this->comm_syncmsg = 1;
    }

    // DROPPACKETS
    if (strstr(cmdLine, "DROPPACKETS")) {
        this->comm_droppackets = 1;
    }

    // NOCOMMSPEED
    if (strstr(cmdLine, "NOCOMMSPEED")) {
        this->comm_speed = 0;
    }

    // SYNCSTOP
    if (strstr(cmdLine, "SYNCSTOP")) {
        this->comm_syncstop = 1;
    }

    // STEPMODE
    if (strstr(cmdLine, "STEPMODE")) {
        this->comm_stepmode = 1;
    }

    // SQUAREOUTLINE
    if ((strstr(cmdLine, "SQUAREOUTLINE") != 0) || (strstr(cmdLine, "SQUARE OUTLINE") != 0) || (strstr(cmdLine, "SQUARE_OUTLINE") != 0)) {
        this->outline_type = 0;
    }

    // CUBEOUTLINE
    if ((strstr(cmdLine, "CUBEOUTLINE") != 0) || (strstr(cmdLine, "CUBE OUTLINE") != 0) || (strstr(cmdLine, "CUBE_OUTLINE") != 0)) {
        this->outline_type = 1;
    }

    // GROUNDOUTLINE
    if ((strstr(cmdLine, "GROUNDOUTLINE") != 0) || (strstr(cmdLine, "GROUND OUTLINE") != 0) || (strstr(cmdLine, "GROUND_OUTLINE") != 0)) {
        this->outline_type = 2;
    }

    // EDGEOUTLINE
    if ((strstr(cmdLine, "EDGEOUTLINE") != 0) || (strstr(cmdLine, "EDGE OUTLINE") != 0) || (strstr(cmdLine, "EDGE_OUTLINE") != 0)) {
        this->outline_type = 3;
    }

    // CUSTOMMOUSE
    if ((strstr(cmdLine, "CUSTOMMOUSE") != 0) || (strstr(cmdLine, "CUSTOM MOUSE") != 0) || (strstr(cmdLine, "CUSTOM_MOUSE") != 0)) {
        this->custom_mouse = 1;
    }

    // NOCP
    if (strstr(cmdLine, "NOCP")) {
        useComputerPlayers = 0;
    }

    // LOGAI
    if (strstr(cmdLine, "LOGAI")) {
        startLoggingAI = 1;
    }

    // NOLOGSTATUS
    if (strstr(cmdLine, "NOLOGSTATUS")) {
        logStatusOn = 0;
    }

    // DOLOGSTATUS
    if (strstr(cmdLine, "DOLOGSTATUS")) {
        logStatusOn = 1;
    }

    // NOAICHEAT
    if (strstr(cmdLine, "NOAICHEAT")) {
        allowAIToCheat = 0;
    }

    // NOCHATCHEATCODES
    if (strstr(cmdLine, "NOCHATCHEATCODES")) {
        chatCheatCodes = 0;
    }

    // LOGUPDATECHANGES
    if (strstr(cmdLine, "LOGUPDATECHANGES")) {
        logUpdateChanges = 1;
    }

    // UIP
    if (strstr(cmdLine, "UIP")) {
        useInfluencePlacement = 1;
    }

    // ALLGRASS
    if (strstr(cmdLine, "ALLGRASS")) {
        all_grassland_on = 1;
    }

    // ALLCP
    if (strstr(cmdLine, "ALLCP")) {
        all_cp = 1;
    }

    // ALLCP1
    if (strstr(cmdLine, "ALLCP1")) {
        all_cp = 2;
    }

    // NOPATHLIMIT
    if (strstr(cmdLine, "NOPATHLIMIT")) {
        numberPathingIterations = -1;
    }

    // UNP
    if (strstr(cmdLine, "UNP")) {
        useNewPathing = -1;
    }

    // COLORLOG
    if (strstr(cmdLine, "COLORLOG")) {
        do_color_log = 1;
    }

    // LOGAI=value
    pcVar3 = _mbsstr(cmdLine, "LOGAI");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        specificAIPlayerToLog = atol(tempStr);
    }

    // LOGDEBUG=value
    pcVar3 = _mbsstr(cmdLine, "LOGDEBUG");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        logDebugID = atol(tempStr);
    }

    // NOPATHCAP
    if (strstr(cmdLine, "NOPATHCAP")) {
        pathingCapValue = -1;
    }

    // GAMECD
    if (strstr(cmdLine, "GAMECD")) {
        force_cd = 1;
    }

    // 1280
    if (strstr(cmdLine, "1280")) {
        this->prog_info->main_wid = 0x500;
        this->prog_info->main_hgt = 0x400;
    }

    // LOGFPS
    if ((strstr(cmdLine, "LOGFPS") != 0) || (strstr(cmdLine, "LOG FPS") != 0) || (strstr(cmdLine, "LOG_FPS") != 0)) {
        do_fps_log = 1;
    }

    // DDERRORLOG
    if (strstr(cmdLine, "DDERRORLOG")) {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 1;
    }

    // DDLOG
    if (strstr(cmdLine, "DDLOG")) {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 0;
    }

    // DDFLUSHLOG
    if (strstr(cmdLine, "DDFLUSHLOG")) {
        DDlogAutoFlush = 1;
    }

    // DDNOFLUSHLOG
    if (strstr(cmdLine, "DDNOFLUSHLOG")) {
        DDlogAutoFlush = 0;
    }

    // DDLOCKLOG
    if (strstr(cmdLine, "DDLOCKLOG")) {
        debug_log_lock = 1;
    }

    // LOGRANDOM
    if (strstr(cmdLine, "LOGRANDOM")) {
        do_debug_random = 1;
    }

    // FIXEDUPDATE
    if (strstr(cmdLine, "FIXEDUPDATE")) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
    }

    // LOGACTION
    if (strstr(cmdLine, "LOGACTION")) {
        debugActions = 1;
    }

    // RES_WARN
    if (strstr(cmdLine, "RES_WARN")) {
        RESFILE_Set_Missing_Flag(1);
    }

    // SCENARIOS=value
    pcVar3 = _mbsstr(cmdLine, "SCENARIOS");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        this->prog_info->scenario_dir[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(this->prog_info->scenario_dir, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        _mbsncat(this->prog_info->scenario_dir, "\\", 1);
    }

    // WORLD=value
    pcVar3 = _mbsstr(cmdLine, "WORLD");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        this->prog_info->world_db_file[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(this->prog_info->world_db_file, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
    }

    // FIXEDUPDATE=value
    pcVar3 = _mbsstr(cmdLine, "FIXEDUPDATE");
    if (pcVar3) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        fixed_update_time = atol(tempStr);
    }

    // AISPEED=value
    pcVar3 = _mbsstr(cmdLine, "AISPEED");
    if (pcVar3) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        debug_timeGetTime_interval = atol(tempStr);
    }

    // RANDOMGAME=value
    pcVar3 = _mbsstr(cmdLine, "RANDOMGAME");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        this->random_game_seed = atol(tempStr);
    }

    // RANDOMMAP=value
    pcVar3 = _mbsstr(cmdLine, "RANDOMMAP");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        this->random_map_seed = atol(tempStr);
    }

    // DRAWLOG=value
    pcVar3 = _mbsstr(cmdLine, "DRAWLOG");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        draw_log_name[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(draw_log_name, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
    }

    // DRAWLOG (boolean)
    if (strstr(cmdLine, "DRAWLOG")) {
        do_draw_log = 1;
    }

    // SAFEDRAWLOG
    if (strstr(cmdLine, "SAFEDRAWLOG")) {
        safe_draw_log = 1;
    }

    // DATA=value
    pcVar3 = _mbsstr(cmdLine, "DATA");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        this->prog_info->game_data_file[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(this->prog_info->game_data_file, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
    }

    // CDAUDIO
    if ((strstr(cmdLine, "CDAUDIO") != 0) || (strstr(cmdLine, "CD AUDIO") != 0) || (strstr(cmdLine, "CD_AUDIO") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 1;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }

    // WINDOW
    if (strstr(cmdLine, "WINDOW")) {
        this->prog_info->full_screen = 0;
    }

    // FILEFIRST
    if ((strstr(cmdLine, "FILEFIRST") != 0) || (strstr(cmdLine, "FILE FIRST") != 0) || (strstr(cmdLine, "FILE_FIRST") != 0)) {
        shape_file_first = 1;
        sound_file_first = 1;
    }

    // LOGCOMM
    if (((strstr(cmdLine, "LOGCOMM") != 0) || (strstr(cmdLine, "LOG COMM") != 0) || (strstr(cmdLine, "LOG_COMM") != 0)) &&
        (this->log_comm = 1, g_L != 0)) {
        g_L->LogFile(1);
        g_L->LogTimestamp(1);
    }

    // LOGOUTPUT
    if (((strstr(cmdLine, "LOGOUTPUT") != 0) || (strstr(cmdLine, "LOG OUTPUT") != 0) || (strstr(cmdLine, "LOG_OUTPUT") != 0)) &&
        (log_output = 1, g_L != 0)) {
        g_L->LogOutput(1);
    }

    // DEVELOPER
    if (strstr(cmdLine, "DEVELOPER")) {
        this->setGameDeveloperMode(1);
    }

    // SPEED1=value
    pcVar3 = _mbsstr(cmdLine, "SPEED1");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        speed_val1 = atol(tempStr);
    }

    // SPEED2=value
    pcVar3 = _mbsstr(cmdLine, "SPEED2");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        speed_val2 = atol(tempStr);
    }

    // NOMUSIC (conditional)
    if (this->prog_info->use_sound == 0 ||
        strstr(cmdLine, "NOMUSIC") != 0 ||
        strstr(cmdLine, "NO MUSIC") != 0 ||
        strstr(cmdLine, "NO_MUSIC") != 0) {
        this->prog_info->use_music = 0;
    }

    // Auto custom_mouse for fullscreen direct draw
    if (this->prog_info->use_dir_draw == 1 && this->prog_info->full_screen == 1) {
        this->custom_mouse = 1;
    }

    // NORMALMOUSE
    if ((strstr(cmdLine, "NORMALMOUSE") != 0) || (strstr(cmdLine, "NORMAL MOUSE") != 0) || (strstr(cmdLine, "NORMAL_MOUSE") != 0)) {
        this->custom_mouse = 0;
    }

    return 1;
}


// PDB ownership: matching/0041E700_setup_class.cpp
// VA: 0041E700 setup_class (152B)
// basegame.cpp: 2205-2236
// int __thiscall RGE_Base_Game::setup_class(void)
#define RGE_BASE_GAME_WND_PROC ((WNDPROC)0x0041E7A0)


int RGE_Base_Game::setup_class() {
    if (prog_info->prev_instance != 0) {
        return 1;
    }

    WNDCLASSA cls;
    cls.hCursor = 0;
    char c = *prog_info->menu_name;
    cls.lpszMenuName = (LPCSTR)0x00592A40;
    if (c) {
        cls.lpszMenuName = prog_info->menu_name;
    }
    cls.hIcon = LoadIconA(prog_info->instance, prog_info->icon_name);
    cls.lpszClassName = (LPCSTR)prog_info;
    cls.hbrBackground = 0;

    cls.hInstance = (HINSTANCE)prog_info->instance;
    cls.style = 0x0B;
    cls.lpfnWndProc = RGE_BASE_GAME_WND_PROC;
    cls.cbWndExtra = 0;
    cls.cbClsExtra = 0;

    return RegisterClassA(&cls) != 0;
}


// PDB ownership: matching/0041E7D0_setup_main_window.cpp
// VA: 0041E7D0 RGE_Base_Game::setup_main_window (330 B)
// PDB source: basegame.cpp:2242-2288
//
// Attempt log:
// - Replaced the packet's free-function/raw-offset scaffold with the typed
//   RGE_Prog_Info and RGE_Base_Game member surface.  The source follows the
//   natural CreateWindowExA, RECT, SetWindowPos, and panel-system flow proved
//   by the original call order.
// - The typed baseline is exact in size/frame/CFG and all 10 calls.  The only
//   drift is the SetWindowPos arithmetic schedule: VC5 loads window bottom
//   before top, while the original loads top, then bottom.  Algebraic,
//   compound, grouped, named-top, unsigned, and four-case height-lab variants
//   all duplicated the 11-byte mismatch; keep the natural expression here.
// - Main-agent audit confirmed canonical game/program/window ownership and kept
//   the direct Win32 rectangle arithmetic rather than scheduling scaffolding.
// - Follow-up top-first and inline-helper spellings, plus a gated nine-way
//   height-expression lab, all collapsed to the same 11-byte SetWindowPos drift;
//   restored the pinned natural source.
// - This pass rechecked int/long field widths, compound updates, custom RECT
//   overlays, ordinary aliases, and likely basegame.cpp header context; all
//   remained in the same 11-byte basin.
// - A narrow volatile lvalue on win_rect.bottom alone reproduces the original
//   330 bytes exactly by preserving its observed delayed stack load.  It is
//   diagnostic only: no source/donor evidence supports volatile on a local
//   Win32 RECT, so the natural typed expression remains the living source.
extern TPanelSystem panel_system;
extern HWND AppWnd;

int RGE_Base_Game::setup_main_window()
{
    int screen_width = GetSystemMetrics(0);
    int screen_height = GetSystemMetrics(1);
    RECT win_rect;
    RECT client_rect;

    if (this->prog_info->full_screen == 0 &&
        (screen_width != this->prog_info->main_wid ||
         screen_height != this->prog_info->main_hgt)) {
        this->prog_window = CreateWindowExA(
            0, this->prog_info->prog_name, this->prog_info->prog_title,
            0x02CA0000, 0, 0,
            this->prog_info->main_wid, this->prog_info->main_hgt,
            0, 0, this->prog_info->instance, 0);
    }
    else {
        this->prog_window = CreateWindowExA(
            0, this->prog_info->prog_name, this->prog_info->prog_title,
            0x82080000, 0, 0, screen_width, screen_height,
            0, 0, this->prog_info->instance, 0);
    }

    if (this->prog_window == 0)
        return 0;

    GetWindowRect(this->prog_window, &win_rect);
    GetClientRect(this->prog_window, &client_rect);

    if (client_rect.right != this->prog_info->main_wid ||
        client_rect.bottom != this->prog_info->main_hgt) {
        SetWindowPos(
            this->prog_window, 0, win_rect.left, win_rect.top,
            (win_rect.right - win_rect.left) - client_rect.right +
                this->prog_info->main_wid,
            (win_rect.bottom - win_rect.top) - client_rect.bottom +
                this->prog_info->main_hgt,
            0);
    }

    if (this->prog_info->full_screen != 0) {
        ShowWindow(this->prog_window, this->prog_info->show_wnd_flag);
        UpdateWindow(this->prog_window);
        SetFocus(this->prog_window);
    }

    AppWnd = this->prog_window;
    panel_system.DisableIME();
    return 1;
}


// PDB ownership: accepted_drift/0041E920_setup_graphics_system.cpp
// VA: 0041E920 RGE_Base_Game::setup_graphics_system (672 B)
// PDB source: basegame.cpp, lines 2294-2377
//
// Attempt log:
// baseline: packet-grounded free-function shims had the right broad behavior,
//   but no EH frame, imported Win32 calls, or typed member-call identities.
// probe 2 (behavior): restored the period typed RGE_Base_Game/RGE_Prog_Info,
//   TDrawSystem, TDrawArea, and TPanelSystem ownership, the real new-expression,
//   and the executable's fourth-mode probe bug.  The mode/fallback source stays
//   direct-member and naturally typed; exact metrics are recorded by the session.
// probe 3 (layout): int draw_type/draw_mode worsened the register basin; rolled back.
// probe 5 (control-flow): converging the 1280 rejection and Init failure through
//   one natural init_fail tail reduced the candidate from 719 to 678 bytes.
// probes 6-9 (liveness/layout/variant): split boolean increments, declaration
//   order, and operand-order variants were duplicates or farther; retained the
//   simple byte locals and combined `(condition != 0) + 1` form.
// probe 10 (variant lab): the lab's default-flag variants lacked /GX and were
//   rejected by size/frame gates; no generated variant was adopted.
// probes 11-12 (context/liveness): full base-game virtual declarations and
//   post-guard local scope were codegen duplicates.  Best current result is
//   678 bytes (+6), all 16 ordered calls aligned, with only the early boolean
//   materialization hunk unresolved (original full-register `inc` versus VC5's
//   byte `inc` plus zeroing).  Left in scratch as clean typed source.
// probe 17 (layout): changed the two byte mode locals to period-plausible
//   signed `char` declarations, matching the packet's byte stores.  VC5 emitted
//   identical code; retained the signed-byte source with the same unresolved
//   allocation hunk.
// probe 14 (control-flow): replaced the goto-based mode fallback with a natural
//   else-if chain and direct failure tail; emitted code was byte-identical, so
//   restored the clean typed source.  The first divergence remains allocation
//   setup at +006D, not a graphics call or fallback CFG issue.
// probe 19 (layout): removed the mode locals and passed direct predicates to Init;
//   lost the EH frame and fell to 650 bytes (diff 610), so restored.
// probe 21 (layout): cached raw use_dir_draw/use_sys_mem values and converted them
//   at Init; shape improved but the first hunk stayed at +006D (676 bytes, diff 536).
// probe 23 (layout): followed the decompiler's raw iVar2/iVar3/iVar5 cache through
//   Init; diff reached 513, but argument materialization moved to the call and
//   destroyed the structural block, so restored.
// probes 25/29 (liveness): int predicate temporaries produced the original full
//   register increments, but VC5 emitted dword stack stores and diff 552; explicit
//   unsigned-char casts were identical.  Raw int flag caches with byte locals were
//   a duplicate of the clean 678-byte source.  Restored clean typed source.
// follow-up lease (2026-08-17): revalidated the 678-byte typed source and tested
//   assignment-after-new (672 bytes but frame 8, diff 539), raw integer flag
//   caches (676 bytes, diff 513 but wrong allocation block), int mode locals
//   (676 bytes, diff 552), split/compound/reversed mode arithmetic, joined
//   declarations, scoped allocation pointer, explicit new parentheses, and
//   standard string/stdio headers.  The source-shape probes were duplicates or
//   worse.  A structured 48-variant mode/VC5 flag lab found no exact result;
//   /GX+/Ow reached size 672 but still diverged at +006D.  Assembly donor search
//   found no matching byte-mode arithmetic donor.  Clean typed source remains
//   the best policy-valid reconstruction; pause with the original full-register
//   inc versus VC5 byte-inc/zeroing hunk unresolved.
// Accepted-drift review: the executable applies setne to CL and DL, then
// increments the full register. Only each low byte is stored. The rebuild
// clears each register and increments the low byte, producing the same 1 or 2.
// All 16 calls, EH state, mode probes, fallbacks, stores, and returns match.
class TDrawArea;





extern TPanelSystem panel_system;

int RGE_Base_Game::setup_graphics_system()
{
    TDrawSystem* draw_system;

    if (this->prog_info->use_dir_draw != 0) {
        HDC dc = GetDC(0);
        int bits = GetDeviceCaps(dc, 0x0C);
        ReleaseDC(0, dc);
        if (bits < 8) {
            this->error_code = 0x13;
            return 0;
        }
    }

    char draw_mode;
    char draw_type;
    int use_sys_mem;

    draw_type = (this->prog_info->use_dir_draw != 0) + 1;
    draw_mode = (this->prog_info->full_screen != 0) + 1;
    use_sys_mem = this->prog_info->use_sys_mem != 0;

    draw_system = new TDrawSystem;
    this->draw_system = draw_system;
    if (draw_system == 0)
        return 0;

    draw_system->CheckAvailModes(this->prog_info->full_screen);

    if (!this->draw_system->IsModeAvail(this->prog_info->main_wid, 0, 8)) {
        if (this->prog_info->main_wid != 0x280) {
            if (this->draw_system->IsModeAvail(0x280, 0, 8)) {
                this->prog_info->main_wid = 0x280;
                this->prog_info->main_hgt = 0x1E0;
                goto init_step;
            }
        }

        if (this->prog_info->main_wid != 800) {
            if (this->draw_system->IsModeAvail(800, 0, 8)) {
                this->prog_info->main_wid = 800;
                this->prog_info->main_hgt = 600;
                goto init_step;
            }
        }

        if (this->prog_info->main_wid != 0x400) {
            if (this->draw_system->IsModeAvail(0x400, 0, 8)) {
                this->prog_info->main_wid = 0x400;
                this->prog_info->main_hgt = 0x300;
                goto init_step;
            }
        }

        if (this->prog_info->main_wid == 0x500)
            goto init_fail;

        // The original checks 1024x0x0 here before storing 1280x1024.
        if (!this->draw_system->IsModeAvail(0x400, 0, 8))
            goto init_fail;

        this->prog_info->main_wid = 0x500;
        this->prog_info->main_hgt = 0x400;
    }

init_step:
    if (this->draw_system->Init(
            this->prog_info->instance,
            this->prog_window,
            this->prog_palette,
            draw_type,
            draw_mode,
            this->prog_info->main_wid,
            this->prog_info->main_hgt,
            use_sys_mem) == 0)
        goto init_fail;

    panel_system.release_palette(this->prog_palette);
    this->prog_palette = panel_system.get_palette(
        this->prog_info->pal_file, 0xC544);

    this->draw_area = this->draw_system->DrawArea;
    this->draw_area->Clear(0, 0);
    this->draw_system->Paint(0);

    return 1;

init_fail:
    return 0;
}


// PDB ownership: matching/0041EBC0_setup_palette.cpp
// VA: 0041EBC0 RGE_Base_Game::setup_palette (41 B)
// PDB source: basegame.cpp, lines 2383-2398



extern TPanelSystem panel_system;
int RGE_Base_Game::setup_palette()
{
    void* result = panel_system.get_palette(this->prog_info->pal_file, 0xC544);
    this->prog_palette = result;
    return result != 0;
}


// PDB ownership: matching/0041EBF0_setup_mouse.cpp
// VA: 0041EBF0 RGE_Base_Game::setup_mouse (270 B) EH-framed
// PDB source: basegame.cpp lines 2404-2431
//
// Probe 1 baseline used free-function shims and included decompiler-inferred
// helper calls.  The packet proves the period setup flow is only the registry
// mode read/write, TMousePointer construction/setup, and mouse_off.
// Probe 2: replaced the shims with typed member calls and a real new-expression
// under the basegame /GX context; call set and layout then aligned.
// Probe 3: a direct-result switch preserved EAX but used the wrong branch order.
// Probe 4: a register result local plus a separate constructor-mode local
// reproduced the original branch/lifetime topology exactly.
// The result==2 arm intentionally leaves custom_type unassigned: the original
// reloads that local's incoming stack home before construction, so initializing
// it would change the observed behavior and bytes.
// Main-agent audit restored the canonical base-game destructor surface;
// emitted code remains exact.
class TDrawArea;




int RGE_Base_Game::setup_mouse()
{
    register int result;
    int custom_type;
    TMousePointer* mouse_pointer;

    result = this->registry->RegGetInt(0, "Custom Mouse");
    if (result == -1) {
        this->registry->RegSetInt(0, "Custom Mouse", 0);
        custom_type = 0;
    }
    else if (result == 1) {
        custom_type = result;
    }
    else if (result == 2) {
        this->custom_mouse = 0;
    }
    else {
        custom_type = 0;
    }

    mouse_pointer = new TMousePointer(custom_type);
    this->mouse_pointer = mouse_pointer;
    if (mouse_pointer == 0)
        return 0;

    if (mouse_pointer->setup(this->custom_mouse, this->draw_area,
                             this->prog_info->cursor_file,
                             0xC738, 10) == 0)
        return 0;

    this->mouse_off();
    return 1;
}


// PDB ownership: matching/0041ED00_setup_chat.cpp
// attempt 2: donor-style TU context for the chat constructor/new basin
// exact match landed with /GX and the donor-style TChat context; target function stays lexically first so the bytes still belong to 0041ED00
class SoundDriver;
class TDigital;


class SoundDriver;


TChat* chat;

int RGE_Base_Game::setup_chat() {
    TChat* new_chat;

    new_chat = new TChat(this->prog_window);
    chat = new_chat;
    return new_chat != 0;
}

TChat::TChat(void* host_wnd) {
    int i;

    taunt = new TTaunt(rge_base_game->sound_system);
    HostWnd = host_wnd;

    for (i = 0; i < 0x33; ++i) {
        Chat[i] = 0;
    }

    CurrentMsgNo = 0;

    for (i = 0; i <= 9; ++i) {
        setInChatGroup(i, 0);
    }
}

TChat::~TChat() {
    if (taunt != 0) {
        delete taunt;
    }
}


// PDB ownership: matching/0041ED70_setup_registry.cpp
// 0041ED70 RGE_Base_Game::setup_registry
// Source: basegame.cpp lines 2451-2459
// protected: virtual int __thiscall RGE_Base_Game::setup_registry(void)
//
// Attempt log:
// Probe 1: natural new-expression shape with /GX per-function rsp.
//   Exact match (0.0000%). /GX confirmed needed for EH prolog.
//   Neighbor setup_chat (0041ED00) also uses /GX â€” consistent with basegame.cpp cluster.
// TRegistry size 0x110 (from inventory types dump)


// RGE_Prog_Info uses registry_key at +0x418.


// RGE_Base_Game uses prog_info at +0xC and registry at +0x1AC.


int RGE_Base_Game::setup_registry()
{
    TRegistry* reg = new TRegistry(this->prog_info->registry_key);
    this->registry = reg;
    return reg != 0;
}


// PDB ownership: matching/0041EDE0_setup_debugging_log.cpp
extern int log_output;



int RGE_Base_Game::setup_debugging_log()
{
    TDebuggingLog* log = new TDebuggingLog;
    debugLog = log;
    if (log == 0)
        return 0;

    log->LogFile(log_comm);
    debugLog->LogOutput(log_output);
    debugLog->LogTimestamp(1);
    return 1;
}


// PDB ownership: matching/0041EE90_setup_comm.cpp
// VA: 0041EE90 RGE_Base_Game::setup_comm (342 B) EH-framed
// PDB source: basegame.cpp:2483-2506
//
// Attempt log:
// - Replaced the packet scaffold's free helper shims and raw member offsets
//   with the period typed new-expression, GUID value parameter, member calls,
//   and named RGE_Base_Game/RGE_Prog_Info ownership.
class TChat;





extern TChat* chat;
extern TCommunications_Handler* comm;
extern int speed_val1;
extern int speed_val2;

int RGE_Base_Game::setup_comm()
{
    TCommunications_Handler* new_comm;

    new_comm = new TCommunications_Handler(
        this->prog_window,
        (unsigned char)this->prog_info->max_players,
        chat,
        this->prog_info->game_guid);
    this->comm_handler = new_comm;

    if (new_comm == 0)
        return 0;

    new_comm->StopIfSyncFail(this->comm_syncstop);
    this->comm_handler->ShowSyncChatMsgs(this->comm_syncmsg);
    this->comm_handler->SetStepMode(this->comm_stepmode);
    this->comm_handler->SetSpeedControl(this->comm_speed);
    this->comm_handler->DropPacketsIntentionally(this->comm_droppackets);
    comm = this->comm_handler;

    if (this->world != 0)
        this->world->reset_communications(this->comm_handler);

    if (speed_val1 != 0)
        this->comm_handler->SetSpeedV1(speed_val1);
    if (speed_val2 != 0)
        this->comm_handler->SetSpeedV1(speed_val2);

    return 1;
}


// PDB ownership: matching/0041EFF0_reset_comm.cpp



extern TCommunications_Handler* comm;

int RGE_Base_Game::reset_comm() {
    TCommunications_Handler* handler = comm_handler;
    if (handler != 0) {
        handler->~TCommunications_Handler();
        operator delete(handler);
        comm_handler = 0;
        comm = 0;
    }
    return setup_comm();
}


// PDB ownership: matching/0041F030_setup_sound_system.cpp
// VA: 0041F030 RGE_Base_Game::setup_sound_system (224 B) EH-framed
// PDB source: basegame.cpp lines 2527-2552
// /GX: EH frame with new-expression state stores at [esp+18h] (0 -> -1)
//
// Canonical ownership:
//   RGE_Base_Game: prog_info +0x0C, prog_window +0x10, sound_system +0x60,
//                  registry +0x1AC; virtual setup_music_system at vtable+0x58.
//   RGE_Prog_Info: use_sound +0x8A8 (int), sounds_dir +0xE21 (char[]).
//   TSound_Driver: 0x69C bytes (operator new size); ctor(prog_window, sounds_dir),
//                  driver_active(), ~TSound_Driver(), set_volume(volume, 1).
//   TRegistry::RegGetInt(1, "Sound Volume").
//   Global sound_driver at 0x62C4B0.
//
// Attempt log:
// probe 1 (baseline): canonical classes RGE_Base_Game/TSound_Driver/TRegistry/RGE_Prog_Info,
//   new-expression + delete, sound_driver global, /GX rsp. diff=189; all 8 calls aligned
//   (100%). Remaining drift: prologue missing push ebx and every zero-compare/zero-store
//   used test/C7 instead of the original's cmp X,edi / mov [mem],edi register-zero forms.
//   Root cause: VC5 reused the volume's edi for the destroy pointer (volume declared at top
//   is const-0 until its neg, so the destroy path reuses edi; no ebx save).
// probes 2-8: long volume, delete w/o guard, member-only accesses, driver-variable reuse,
//   sound_system=(TSound_Driver*)volume, explicit dtor+operator_delete temp, combined &&
//   condition â€” all byte-identical (VC5 IR invariant to these shapes).
// probe 9 (match): move `int volume = 0;` AFTER the destroy block, right before the
//   RegGetInt/set_volume region. VC5 then keeps edi as the function-wide zero register
//   (xor hoisted to the use_sound check, exactly like the original's 2529 line record),
//   allocates ebx for the destroy pointer, and assigns the late volume to the already-zero
//   edi. Exact match (0.0000%).
// Left in matching: the late-declared volume is the binary-proven original shape.






extern TSound_Driver* sound_driver;    // 0x62C4B0


int RGE_Base_Game::setup_sound_system()
{
    if (this->prog_info->use_sound != 0) {
        TSound_Driver* driver = new TSound_Driver(this->prog_window, this->prog_info->sounds_dir);
        this->sound_system = driver;
        if (driver != 0 && driver->driver_active() == 0) {
            if (this->sound_system != 0) {
                delete this->sound_system;
            }
            this->sound_system = 0;
            return 1;
        }
        sound_driver = this->sound_system;
        int volume = 0;
        int result = this->registry->RegGetInt(1, "Sound Volume");
        if (result != -1) {
            volume = -result;
        }
        this->sound_system->set_volume(volume, 1);
    }
    this->setup_music_system();
    return 1;
}


// PDB ownership: matching/0041F110_setup_music_system.cpp
// VA: 0041F110 RGE_Base_Game::setup_music_system (442 B)
// PDB source: basegame.cpp lines 2558-2624
//
// Attempt log:
// baseline: packet scaffold had free-function shims and an extra prog_info-null
//   guard; it matched size/frame but not the member-call targets or entry CFG.
// probe 2: restored the period typed RGE_Base_Game/RGE_Prog_Info/TMusic_System/
//   TRegistry surfaces and natural new/delete/member calls; checking next.
// probes 3-5: /GX plus direct prog_info rereads restored the EH frame, all nine
//   decorated call targets, the 0x10C frame, and the threshold cmp/jg; the
//   remaining localized gap is source-local music_path scheduling.
// probes 6-8: direct-negation, unsigned-mask, and multiply spellings for the
//   wave fallback were non-exact; the multiply variant was closer but not kept.
// probes 9-18: the natural 3-or-1 ternary, explicit byte casts, plain-char
//   locals, mask arithmetic, and buffer-size/order variants did not match.
//   The explicit if/else wave fallback is the source shape that reproduces
//   the oracle's BL neg/sbb/and/inc lowering.
// bounded pause: calls, ownership, offsets, EH frame, and behavior are aligned;
//   remaining drift starts at the music_path local/address schedule.
// - Function-scope music locals, constructor-result-before-path declaration,
//   and direct assignment to the owned music_system field all duplicated the
//   218-byte drift; restored the clean branch-local typed source.
// probe 16: declaring music_path before music_type was a codegen duplicate;
//   restored the clean declaration order after the local-address probe.
// probe 18: plain char music type plus a scoped path buffer was a codegen
//   duplicate; VC5 kept the EBX fallback width and separate path slot.
// probe 19: explicit if/else wave fallback plus direct music_path use matches
//   the original byte-for-byte. The decompiler's +4 labels are stack-variable
//   naming artifacts, not source pointer bias.
class TSound_Driver;





int RGE_Base_Game::setup_music_system()
{
    if (this->prog_info->use_music != 0) {
        int volume = -5000;
        int result = this->registry->RegGetInt(1, "Music Volume");
        if (result != -1)
            volume = -result;

        if (volume <= -0x26AC) {
            this->prog_info->use_music = 0;
            TMusic_System* music = this->music_system;
            if (music != 0) {
                delete music;
                this->music_system = 0;
            }
        }
        else if (this->music_system == 0) {
            unsigned char music_type;
            char music_path[260];

            if (this->prog_info->use_cd_audio != 0)
                music_type = 1;
            else if (this->prog_info->use_midi != 0)
                music_type = 2;
            else if (this->prog_info->use_ima != 0)
                music_type = 4;
            else {
                if (this->prog_info->use_wave_music != 0)
                    music_type = 3;
                else
                    music_type = 1;
            }

            sprintf(music_path, "%s\\%s", this->work_dir,
                    this->prog_info->sounds_dir);

            TMusic_System* music_system =
                new TMusic_System(music_type, this->prog_info->instance, this->prog_window,
                                  this->sound_system, music_path);
            this->music_system = music_system;

            if (music_system != 0 && music_type == 1 &&
                this->prog_info->use_cd_audio == 0) {
                if (music_system->device_open == 0 ||
                    music_system->track_count < 2) {
                    if (music_system->set_music_type(2) == 0)
                        this->music_system->set_music_type(3);
                }
            }

            if (this->music_system != 0)
                this->music_system->set_volume(volume, 1);
        }
    }

    return 1;
}


// PDB ownership: matching/0041F2D0_setup_shapes.cpp
// VA: 0041F2D0 RGE_Base_Game::setup_shapes (289 B) EH-framed
// PDB source: basegame.cpp, lines 2630-2647
//
// Attempt log:
// - Baseline: replaced the free-function/decompiler shims with the canonical
//   RGE_Base_Game fields, a 0x20-byte TShape class, and the real
//   TShape(char*, long) new-expression ABI.  Calls aligned and the EH frame
//   appeared; the initialization loop still used a pointer induction.
// - Direct-member loop: spelling the zeroing as this->shapes[i] reproduced the
//   original per-iteration member reload and indexed store.  Exact match.
// - Main-agent audit restored setup_shapes at its donor-backed +0x98 virtual
//   slot behind the canonical base-game destructor; bytes remain exact.
// FLAGS: config/flags/0041F2D0_setup_shapes.rsp (/GX is required by the
//        binary's EH-framed constructor new-expressions).
int RGE_Base_Game::setup_shapes()
{
    TShape* shape;
    TShape** shape_array;
    int i;

    this->shape_num = 3;
    shape_array = (TShape**)calloc(3, 4);
    this->shapes = shape_array;
    if (shape_array == 0)
        return 0;

    for (i = 0; i < this->shape_num; ++i)
        this->shapes[i] = 0;

    shape = new TShape("groupnum.shp", 0xC4E3);
    this->shapes[0] = shape;

    shape = new TShape("waypoint.shp", 0xC4E4);
    this->shapes[1] = shape;

    shape = new TShape("moveto.shp", 0xC4E5);
    this->shapes[2] = shape;

    return 1;
}


// PDB ownership: matching/0041F400_setup_sounds.cpp
// VA: 0041F400 RGE_Base_Game::setup_sounds (347 B) EH-framed
// PDB source: basegame.cpp:2653-2676
//
// Attempt log:
// - Replaced the packet scaffold's free constructor/load shims with the
//   period typed TDigital new-expression, named sound array ownership, and
//   external static sound-name symbols.
extern "C" void* calloc(unsigned int num, unsigned int size);
extern char s_button1_wav[];
extern char s_button2_wav[];
extern char s_chatrcvd_wav[];

class TSound_Driver;



int RGE_Base_Game::setup_sounds()
{
    TDigital* sound;
    int i;

    this->sound_num = 3;
    this->sounds = (TDigital**)calloc(3, 4);
    if (this->sounds == 0)
        return 0;

    for (i = 0; i < this->sound_num; ++i)
        this->sounds[i] = 0;

    sound = new TDigital(this->sound_system, s_button1_wav, 0xC47C);
    this->sounds[0] = sound;

    sound = new TDigital(this->sound_system, s_button2_wav, 0xC47D);
    this->sounds[1] = sound;

    sound = new TDigital(this->sound_system, s_chatrcvd_wav, 0xC47E);
    this->sounds[2] = sound;

    i = 0;
    for (; i < this->sound_num; ++i) {
        if (this->sounds[i] != 0)
            this->sounds[i]->load(0, -1);
    }

    return 1;
}


// PDB ownership: verified_logic/0041F560_setup_fonts.cpp
// VA: 0041F560 RGE_Base_Game::setup_fonts (410 B)
// PDB source: basegame.cpp:2682-2732
//
// Attempt log:
// - Replaced the packet scaffold with the period typed RGE_Base_Game,
//   RGE_Font, TDrawArea, TEXTMETRICA, and member-call surfaces.  The loop
//   keeps the original short index and switch on tmHeight; the binary also
//   proves the API receives the address of the ascent field.
// - Corrected draw_area/font_num/fonts to the proven +0x4C/+0x1E0/+0x1E4
//   ownership; this removed the broad displacement drift.
// - A natural RGE_Font element-pointer local shortened the body but did not
//   reproduce the oracle's reused scaled offset; rolled back.
// - A named int font_index assigned from tm.tmHeight restored the oracle's
//   one-time index scaling and exact 410-byte body shape (best diff 50).
// - Restored the base-game virtual slot surface, reordered locals, added the
//   donor stdlib context, and tested an int old SelectObject handle; all were
//   codegen duplicates.  An 8-variant declaration/scope lab likewise found
//   only the same two codegen groups.
// - Left in scratch: calls/CFG and instruction count align, but VC5 keeps a
//   0x3C frame and rotates this/dc/font through ESI/EDI/EBX versus the oracle's
//   0x40 frame and EDI/EBX/ESI register coloring.
// - Direct member ownership for the calloc result, generic TEXTMETRIC/GetTextMetrics
//   spellings, and typed HDC/HFONT handles each duplicated the 50-byte drift;
//   restored the pinned named-array and explicit-A API source.
// - Main-agent stack accounting rejected a blind-review field correction. Two
//   pending SelectObject arguments shift ESP by eight bytes at the metric reads.
extern char s_basegame_setup_fonts[];




int RGE_Base_Game::setup_fonts()
{
    RGE_Font* font_array;
    void* dc;
    HGDIOBJ old_font;
    short i;
    void* font;
    int font_index;
    TEXTMETRICA tm;

    this->font_num = 12;
    font_array = (RGE_Font*)calloc(12, 12);
    this->fonts = font_array;
    if (font_array == 0)
        return 0;

    dc = this->draw_area->GetDc(s_basegame_setup_fonts);
    if (dc == 0)
        return 0;

    i = 0;
    if (this->font_num > 0) {
        do {
            tm.tmHeight = (long)i;
            switch (tm.tmHeight) {
            case 0:
                font = this->make_font(dc, 0x6E, 0);
                break;
            case 1:
                font = this->make_font(dc, 0x71, 0);
                break;
            case 4:
                font = this->make_font(dc, 0x74, 0);
                break;
            case 6:
                font = this->make_font(dc, 0x83, 0);
                break;
            case 7:
                font = this->make_font(dc, 0x77, 0);
                break;
            case 8:
                font = this->make_font(dc, 0x80, 1);
                break;
            case 9:
                font = this->make_font(dc, 0x7A, 0);
                break;
            case 10:
                font = this->make_font(dc, 0x7D, 0);
                break;
            case 11:
                font = this->make_font(dc, 0x80, 0);
                break;
            default:
                font = 0;
                break;
            }

            if (font != 0) {
                old_font = SelectObject((HDC)dc, (HGDIOBJ)font);
                GetTextMetricsA((HDC)dc,
                                (LPTEXTMETRICA)&tm.tmAscent);
                font_index = tm.tmHeight;
                this->fonts[font_index].font = font;
                this->fonts[font_index].font_wid = tm.tmMaxCharWidth;
                this->fonts[font_index].font_hgt =
                    tm.tmAscent + tm.tmAveCharWidth;
                SelectObject((HDC)dc, old_font);
            }

            i = i + 1;
        } while (i < this->font_num);
    }

    this->draw_area->ReleaseDc(s_basegame_setup_fonts);
    return 1;
}


// PDB ownership: matching/0041F730_setup_blank_screen.cpp
// VA: 0041F730 RGE_Base_Game::setup_blank_screen (196 B)
// PDB source: basegame.cpp, lines 2737-2749
// Attempt log:
// - Baseline: free-function shims compiled with the right call count but lost
//   member-call conventions, the IAT call, and the /GX new-expression frame.
// - Reconstructed the natural new TScreenPanel/member-call source with the
//   panel-system object, set_render_all member, and SendMessageA IAT surface;
//   exact match.
// - Restored the proven TPanel -> TEasy_Panel -> TScreenPanel inheritance and
//   0xF4/0x478 sizes; unchanged exact match.
// - Removed unnecessary char* casts from the old-style string arguments;
//   unchanged exact match.
class TDrawArea;
class TPanel;






extern TPanelSystem panel_system;

int RGE_Base_Game::setup_blank_screen()
{
    TScreenPanel* panel;

    panel = new TScreenPanel("Blank Screen");
    if (panel == 0)
        return 0;

    if (panel->setup(this->draw_area, 0, -1, 0) == 0)
        return 0;

    panel_system.setCurrentPanel("Blank Screen", 0);
    this->set_render_all();
    SendMessageA(this->prog_window, 0x0F, 0, 0);
    return 1;
}


// PDB ownership: matching/0041F800_setup_timings.cpp
void RGE_Base_Game::setup_timings(void) {
    int val = 1;
    this->timings[1].include_in_total = val;
    this->timings[2].include_in_total = val;
    this->timings[3].include_in_total = val;
    this->timings[10].include_in_total = val;
    this->timings[13].include_in_total = val;
    this->timings[0].is_summary = val;
    this->timings[4].is_summary = val;
}


// PDB ownership: matching/0041F830_stop_sound_system.cpp
// VA: 0041F830 RGE_Base_Game::stop_sound_system
void operator delete(void* p);
extern "C" void __cdecl free(void* block);

void RGE_Base_Game::stop_sound_system(void) {
    if (chat != 0)
        chat->StopSoundSystem();

    panel_system.stop_sound_system();

    if (this->world != 0) {
        for (int i = 0; i < this->world->sound_num; ++i)
            this->world->sounds[i]->restart_sound(0);
    }

    if (this->sounds != 0) {
        for (int i = 0; i < this->sound_num; ++i) {
            if (this->sounds[i] != 0)
                delete this->sounds[i];
        }
        free(this->sounds);
        this->sounds = 0;
    }

    this->shutdown_music_system();

    if (this->sound_system != 0) {
        this->registry->RegSetInt(1, "Sound Volume", -this->sound_system->get_volume());
        delete this->sound_system;
        this->sound_system = 0;
        sound_driver = 0;
    }
}


// PDB ownership: matching/0041F920_restart_sound_system.cpp
// VA: 0041F920 RGE_Base_Game::restart_sound_system
int RGE_Base_Game::restart_sound_system()
{
    if (this->sound_system != 0)
        goto done;

    if (this->setup_sound_system() == 0)
        return 0;
    if (this->setup_sounds() == 0)
        return 0;

    if (this->world != 0) {
        for (int i = 0; i < this->world->sound_num; ++i)
            this->world->sounds[i]->restart_sound(this->sound_system);
    }

    panel_system.restart_sound_system();

    if (chat != 0)
        chat->RestartSoundSystem(this->sound_system);

    this->restart_music_system();

done:
    return 1;
}


// PDB ownership: matching/0041F9B0_stop_music_system.cpp



void RGE_Base_Game::stop_music_system(void) {
    if (this->music_system != 0) {
        this->music_system->get_play_info(&this->save_music_type, &this->save_music_track_from, &this->save_music_track_to, &this->save_music_cur_track, this->save_music_file, &this->save_music_loop, &this->save_music_pos);
        this->music_system->stop_track();
    }
}


// PDB ownership: matching/0041F9F0_restart_music_system.cpp
// 0041F9F0 RGE_Base_Game::restart_music_system (basegame.cpp:2876-2888, 149B)
// STATUS: GIVEN_UP (2026-05-19)
// FLAGS: default
//
// Remaining mismatch: size 149 vs 144 (body bytes identical; prologue/epilogue
// structure differs: register save order, save timing, epilogue sharing).
// Boss denied accepted_drift due to size mismatch preventing byte-level review.
//
// Attempt log (2026-05-19):
// try 1-2: baseline - register saves at prologue, merged epilogues = 144B vs 149
// try 3: restructured with goto + separate return paths to force inline epilogues - still 144B
// try 4: removed ms local variable, used this->music_system directly - still 144B
// try 5: flag tries /G5, /Os, /GA - no change
// GIVEUP: VC5 internal prologue/epilogue heuristic mismatch; cannot override register save order
//   (ebx,esi,edi vs edi,esi,ebx) or save timing (prologue vs after early-null-check) from C++ source.
// Retry 2026-05-19 Boss pass: 10 source variants (self/ms locals, direct member access, shared-goto return, explicit pos/loop/to/cur locals, duplicate original tests, nested if/else, result local) all remained 144B or worse (one 128B). Flag probes /Od, /O1, /Ox, /O2 without /Oy did not help (/Od broad mismatch, /O1 110B, /Ox and /Oy- still 144B). Restored prior scratch.
// Retry 2026-05-20: 10 more variants: nested no-goto, self/ms locals, raw/direct calls, separate-goto epilogues, result local, duplicate tests, explicit pos/loop/to/cur locals, volatile music_system, single outer else, raw byte-offset members. All close variants still 144B; volatile music_system reached exact size but broad 71.8121% positional / 144.2953% edit regression; one explicit-local variant shrank to 128B. Restored 144B best.
// GIVEUP: same blocker remains. Original delays callee-save pushes until after the music_system null check and uses separate inline epilogues; VC5 C++ source keeps selecting the 144B shared-epilogue/prologue family unless volatile forces a completely wrong stack-home basin. Not accepted_drift: best is 5 bytes short and exact-size variant is broadly reordered.
// Retry 2026-05-21 Boss pass: tried explicit `self`/`ms` locals, raw byte-offset access to bias EAX=self/ECX=music_system, ms-before-self ordering, `register` self, `__stdcall` and int-return TMusic declarations, non-virtual declaration, /Ob0 and /Gz flag probes, and duplicate explicit track_from test/goto file-case shape. All close variants stayed 144B; no variant recovered original delayed `push edi; push esi; push ebx` with EAX self and ECX music_system. Restored prior 144B best; no accepted_drift proposal.
// Retry 2026-05-24 assigned pass: 15 further probes. Volatile music_system field/local and volatile-after-check variants reached exact 149B but were broad wrong stack-home/register families (best 69.7987% positional, first mismatch 0). Nested positive, separate return labels, ms local/direct-after-check stayed 144B or failed. Volatile track_from exact-size variant worsened to 91.9463%. Flag probes /Ob0 /Og /Oa /Ow /Gs /Gy on the best source all stayed 144B. Still not accepted_drift: best behavioral source is 5 bytes short; exact-size volatile families are broad byte-0 topology mismatches.
// Retry 2026-05-26 Boss pass: 10 further probes. Rechecked non-virtual explicit-vptr
// class surface, direct/no-local member access, `self` locals, no-local `save_music_track_from`
// rereads, TMusic return type `int` vs `void`, `register int from`, and combinations of
// self/from/to locals. All close variants still compile to the same 144-byte family with
// an initial `push ecx` stack home, eager EBX/ESI saves, and shared/short epilogues; none
// recover original `mov eax,ecx; mov ecx,[eax+64h]` null gate followed by delayed
// `push edi; push esi; push ebx`. No accepted_drift: best source is short/truncated, exact-size
// volatile variants from earlier are broad mismatches.
// Retry 2026-08-02 Luna-41F9F0: corrected the local music field layout and TMusic call
// prototypes from repo ground truth; no emitted-byte change.
// An inline post-null helper was a productive source-context probe: it reproduced the
// delayed callee-save prologue and exact early-null block, improving the best build to
// 144 aligned bytes / 149-byte boundary. A narrow volatile read on the first track_to
// comparison preserved the original direct `cmp [eax+78h]` and later reload, giving 138
// equal bytes, 96.61% exact-block coverage, and only three resync spans.
// The remaining structural gap is binary-proven at basegame.cpp:2882: original has the
// redundant `test edx,edx; je file; mov esi,[eax+78h]; test esi,esi; je file`, while VC5
// removes the first two instructions after every natural/direct-member spelling tried.
// Volatile-addressing the local creates a stack home and a broad 164-byte mismatch;
// duplicate predicates, nested positive flow, and repeated direct members are codegen
// duplicates. Left in scratch pending a source-context lead that preserves that block.
// Retry 2026-08-02 Luna41F9F0: the key source shape is two independent `if` statements,
// not a second range check nested inside the first `if (track_from)`. This preserves the
// original redundant `test edx,edx` and produces MATCH (149/149, 0.0000%). Removing the
// prior volatile `track_to` read leaves the exact bytes unchanged. Auditing away the
// inline helper and using a direct positive/null-guard body reintroduces eager callee-save
// pushes and a broad 143-byte mismatch, so the helper-backed source is retained as the
// smallest exact-friendly TU context. No inline asm or custom flags.



static inline int restart_music_system_body(RGE_Base_Game* self)
{
    if (self->save_music_track_from) {
        if (self->save_music_track_from == self->save_music_track_to) {
            self->music_system->play_track(self->save_music_track_from, self->save_music_loop, self->save_music_pos);
            return 1;
        }
    }

    if (self->save_music_track_from != 0 && self->save_music_track_to) {
        self->music_system->play_tracks(self->save_music_track_from, self->save_music_track_to,
            self->save_music_loop, self->save_music_cur_track, self->save_music_pos);
        return 1;
    }

    if (self->save_music_file[0]) {
        self->music_system->play_file(self->save_music_file, self->save_music_loop, self->save_music_pos);
    }

    return 1;
}

int RGE_Base_Game::restart_music_system()
{
    if (!this->music_system)
        return 1;
    return restart_music_system_body(this);
}


// PDB ownership: matching/0041FA90_shutdown_music_system.cpp
// attempt 1: compile error on manual vtable call
// attempt 2: member offsets wrong, delete adds extra code
// attempt 3: operator delete, 80 bytes
// attempt 4-5: more cast errors
// attempt 6: virtual method at 0 offset, still 80 bytes
// attempt 7: try with padding virtuals

class TRegistry;



void operator delete(void* p);


void RGE_Base_Game::shutdown_music_system() {
    if (music_system == 0) return;
    this->stop_music_system();
    registry->RegSetInt(1, "Music Volume", -music_system->volume);
    TMusic_System* p = music_system;
    if (p != 0) {
        p->~TMusic_System();
        operator delete(p);
    }
    music_system = 0;
}


// PDB ownership: matching/0041FAF0_make_font.cpp
// VA: 0041FAF0 RGE_Base_Game::make_font (203 B)
// PDB source: basegame.cpp lines 2909-2930
//
// Attempt log:
// baseline: natural locale-string lookup, atoi/style parsing, and direct same-class
// make_font overload call; local virtual surface exposes the observed vslot +0x20.

extern "C" int __cdecl atoi(const char*);
extern "C" char* __cdecl strstr(const char*, const char*);


void* RGE_Base_Game::make_font(void* param1, long id, int italic)
{
    char face_name[256];
    char point_size_str[10];
    char style[10];
    int point_size;
    int weight;

    this->get_string(id, face_name, 0x100);
    if (face_name[0] == 0)
        return 0;

    this->get_string(id + 1, point_size_str, 10);
    point_size = atoi(point_size_str);

    this->get_string(id + 2, style, 10);
    if (strstr(style, "B") != 0 || strstr(style, "b") != 0)
        weight = 700;
    else
        weight = 400;

    return this->make_font(param1, face_name, point_size, weight, italic);
}


// PDB ownership: matching/0041FBC0_make_font.cpp
// VA: 0041FBC0 RGE_Base_Game::make_font (207 B)
// PDB source: basegame.cpp, lines 2936-2964
// Attempt log:
// baseline: natural LOGFONTA construction from the target assembly: language charset
// parsing, zeroed LOGFONT, MulDiv height, strikeout/quality fields, and strcpy face name.
// probe 2: added the explicit binary-observed zero/weight/byte field stores; this
// restored the original 207-byte frame/body shape under the default flags.
// probe 3: ordered weight and charset with the declared LOGFONTA fields; exact
// match, including the delayed parameter loads and inline strcpy schedule.
extern "C" int __cdecl atoi(const char*);
extern "C" __declspec(dllimport) int __stdcall MulDiv(int, int, int);



void* RGE_Base_Game::make_font(void* dc, char* name, int size, int weight, int strikeout)
{
    char str[256];
    LOGFONTA logfont;
    char charset;

    this->get_string(0x65, str, 0x100);
    charset = (char)atoi(str);
    memset(&logfont, 0, sizeof(logfont));
    logfont.lfHeight = -MulDiv(size, 0x60, 0x48);
    logfont.lfWidth = 0;
    logfont.lfEscapement = 0;
    logfont.lfOrientation = 0;
    logfont.lfWeight = weight;
    logfont.lfItalic = 0;
    logfont.lfUnderline = 0;
    logfont.lfStrikeOut = (char)strikeout;
    logfont.lfCharSet = charset;
    logfont.lfOutPrecision = 0;
    logfont.lfClipPrecision = 0;
    logfont.lfQuality = 2;
    logfont.lfPitchAndFamily = 2;
    strcpy(logfont.lfFaceName, name);
    return CreateFontIndirectA(&logfont);
}


// PDB ownership: matching/0041FC90_check_for_cd.cpp
// VA: 0041FC90 RGE_Base_Game::check_for_cd (331 B)
// PDB source: basegame.cpp:2977-3028
//
// Attempt log:
// - Replaced the free-function/raw-offset scaffold with the typed
//   RGE_Prog_Info, RGE_Base_Game, TCommunications_Handler, and TRegistry
//   member surfaces.  The source mirrors the original positive-player-count
//   loop and CD-path validation flow.
// - Main-agent audit confirmed canonical member/API ownership and natural CD
//   validation flow; exact bytes were revalidated after promotion.
extern int force_cd;
extern "C" int __cdecl stricmp(const char* left, const char* right);





int RGE_Base_Game::check_for_cd(int value)
{
    char vol_name[256];
    char file_sys_name[256];
    unsigned long vol_ser_num;
    unsigned long max_comp_len;
    unsigned long file_sys_flags;

    if (this->prog_info->verify_cd == 0)
        return 1;

    if (value > 0) {
        int cd_count = 0;
        int i = 0;
        do {
            if (this->comm_handler->GetPlayerHumanity(i + 1) == 2 &&
                this->playerHasCD(i) != 0) {
                ++cd_count;
            }
            ++i;
        } while (i < 9);

        return value <= this->prog_info->max_players_per_cd * cd_count;
    }

    if (force_cd != 0)
        return 1;

    char* path = this->registry->RegGetAscii(0, "CDPath");
    if (path == 0)
        return 0;

    if (GetDriveTypeA(path) != 5)
        return 0;

    if (GetVolumeInformationA(path, vol_name, 256, &vol_ser_num,
                               &max_comp_len, &file_sys_flags,
                               file_sys_name, 256) == 0)
        return 0;

    return stricmp(vol_name, this->prog_info->vol_name) == 0;
}


// PDB ownership: matching/0041FDE0_check_expiration.cpp
// attempt 1: zeroed tm-like local, build the expiration date, then compare current time against it
// exact match landed once the tm-like layout started at tm_min and memset zeroed the 9-dword local block before the date fields were filled

struct tm_like {
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    int tm_gmtoff;
};



extern "C" void* memset(void* dst, int value, unsigned int size);
extern "C" long mktime(tm_like* tm);
extern "C" long time(long* cur_date);

int RGE_Base_Game::check_expiration() {
    tm_like kill_def;
    long cur_date;
    long expiration;

    memset(&kill_def, 0, sizeof(kill_def));
    kill_def.tm_year = (int)this->prog_info->expire_year - 1;
    kill_def.tm_mon = (int)this->prog_info->expire_month;
    kill_def.tm_wday = (int)this->prog_info->expire_day;

    expiration = mktime(&kill_def);
    time(&cur_date);
    return cur_date <= expiration;
}


// PDB ownership: matching/0041FE50_check_multi_copies.cpp
// VA: 0041FE50 RGE_Base_Game::check_multi_copies (208 B)
// PDB source: basegame.cpp lines 3057-3095
// Baseline was a decompiler-shaped free-function lift with direct Win32 calls.
// The original uses the RGE_Prog_Info name/title fields, imported Win32 APIs,
// and the real check_prog_argument member.
// try 1: restore the period-plausible class/SDK surface and direct member fields;
//         expected to recover the 14 IAT calls and the +0xC/+0x20 layout.
// try 2: imported Win32/member reconstruction reached the correct calls and
//         fields but merged the failed-mutex cleanup with the lobby path.
// try 3: express ERROR_ALREADY_EXISTS as the positive guarded body; this keeps
//         the late failure release block and produces an exact 208-byte match.

extern "C" __declspec(dllimport) void* __stdcall FindWindowA(
    const char* class_name, const char* window_name);

#define s_LOBBY ((char*)0x58025C)



int RGE_Base_Game::check_multi_copies()
{
    this->prog_mutex = CreateMutexA(0, 1, this->prog_info->prog_name);
    if (GetLastError() == 0xB7) {
        void* window = FindWindowA(this->prog_info->prog_name,
                                   this->prog_info->prog_title);
        if (window != 0) {
            if (this->check_prog_argument(s_LOBBY) != 0) {
                SendMessageA(window, 0x10, 0, 0);
                if (this->prog_mutex != 0)
                    ReleaseMutex(this->prog_mutex);
                return 1;
            }
            if (IsIconic(window) != 0)
                ShowWindow(window, 1);
            SetForegroundWindow(window);
            BringWindowToTop(GetLastActivePopup(window));
        }

        if (this->prog_mutex != 0) {
            ReleaseMutex(this->prog_mutex);
            CloseHandle(this->prog_mutex);
            this->prog_mutex = 0;
        }
        return 0;
    }

    if (this->prog_mutex != 0)
        ReleaseMutex(this->prog_mutex);
    return 1;
}


// PDB ownership: matching/0041FF20_check_paint.cpp
// VA: 0041FF20 RGE_Base_Game::check_paint (221 B)
// PDB source: basegame.cpp lines 3101-3149
//
// Attempt log:
// - Baseline reconstruction: real RGE_Base_Game/TDrawSystem member surface,
//   dllimport Win32 IAT calls, RECT local, switch dispatch on CheckSurfaces().

int RGE_Base_Game::check_paint()
{
    tagRECT update_rect;
    unsigned char surface_status;

    if (this->prog_ready == 0) {
        this->clear_window();
        ValidateRect(this->prog_window, 0);
        return 0;
    }

    if (IsIconic(this->prog_window) != 0) {
        ValidateRect(this->prog_window, 0);
        return 0;
    }

    if (this->prog_active == 0) {
        if (GetUpdateRect(this->prog_window, &update_rect, 0) != 0) {
            this->draw_system->Paint(&update_rect);
        }
        ValidateRect(this->prog_window, 0);
        return 0;
    }

    surface_status = this->draw_system->CheckSurfaces();
    switch (surface_status) {
    case 1:
        return 0;
    case 2:
        this->draw_system->ClearRestored();
        this->set_render_all();
        break;
    case 3:
        ValidateRect(this->prog_window, 0);
        DestroyWindow(this->prog_window);
        return 0;
    default:
        break;
    }
    return 1;
}


// PDB ownership: matching/00420000_clear_window.cpp


void RGE_Base_Game::clear_window() {
    RECT rect;
    void* dc;
    void* brush;

    if (this->prog_window != 0) {
        dc = GetDC(this->prog_window);
        GetClientRect(this->prog_window, &rect);
        brush = GetStockObject(4);
        FillRect(dc, &rect, brush);
        ReleaseDC(this->prog_window, dc);
    }
}


// PDB ownership: matching/00420050_create_world.cpp
// tried the natural `return new RGE_Game_World;` shape first; default flags only built a 32-byte body
// /GX was required to land the EH/new helper in the exact 90-byte basin
RGE_Game_World* RGE_Base_Game::create_world() {
    return new RGE_Game_World;
}


// PDB ownership: matching/004200B0_close.cpp
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);


void RGE_Base_Game::close()
{
    PostMessageA(this->prog_window, 0x10, 0, 0);
}


// PDB ownership: matching/004200D0_create_dialog.cpp



int RGE_Base_Game::create_dialog(TPanel** out, TPanel* panel) {
    *out = 0;
    if (panel == 0) {
        return 0;
    }
    if (panel->error_code != 0) {
        delete panel;
        return 0;
    }
    *out = panel;
    return 1;
}


// PDB ownership: matching/00420110_delete_dialog.cpp



void RGE_Base_Game::delete_dialog(TPanel** p)
{
    if (*p) {
        delete *p;
        *p = 0;
    }
}


// PDB ownership: matching/00420130_set_game_mode.cpp


void RGE_Base_Game::set_game_mode(int a, int b) {
    this->game_mode = a;
    this->sub_game_mode = b;
}


// PDB ownership: matching/00420150_set_player.cpp
// VA: 00420150 virtual RGE_Base_Game::set_player
// Exact under VC5 host with default /O2 /Oy flags.
// world is at +0x3F4; its player_num, curr_player, and map fields are
// at +0x3C, +0x7C, and +0x28. Keep the null and signed bound guards.




void RGE_Base_Game::set_player(short player_id) {
    RGE_Game_World* w = this->world;
    if (w == 0) return;
    if (player_id >= w->player_num) return;
    w->curr_player = player_id;
    this->world->map->clear_map_view_info();
}


// PDB ownership: matching/00420180_get_paused.cpp
// BINARY NOTE: the shipped compare uses prog_mode at +0x1B0.
// BINARY NOTE: the shipped tail targets TCommunications_Handler::IsPaused.
struct CommsHandler {
    int IsPaused();
};


int RGE_Base_Game::get_paused()
{
    if (this->prog_mode == 7)
        return 0;
    return this->comm_handler->IsPaused();
}


// PDB ownership: matching/004201A0_get_font.cpp


RGE_Font* RGE_Base_Game::get_font(int index)
{
    if (!this->fonts)
        return 0;
    return this->fonts + index;
}


// PDB ownership: matching/004201C0_get_shape.cpp
TShape* RGE_Base_Game::get_shape(int i) {
    if (!this->shapes) return 0;
    return this->shapes[i];
}


// PDB ownership: matching/004201E0_get_sound.cpp
TDigital* RGE_Base_Game::get_sound(int i) {
    if (!this->sounds) return 0;
    return this->sounds[i];
}


// PDB ownership: matching/00420200_request_pause.cpp
// VA: 00420200 RGE_Base_Game::request_pause
// Exact under VC5 host with default /O2 /Oy flags.
// Call TogglePauseGame through comm_handler at +0x18C, then set world
// temp_pause at +0x3F4/+0x1C. Keep the call before the null-guarded store.




void RGE_Base_Game::request_pause()
{
    this->comm_handler->TogglePauseGame();
    if (this->world)
        this->world->temp_pause = 1;
}


// PDB ownership: matching/00420220_set_paused.cpp


void RGE_Base_Game::set_paused(int paused, int non_user_pause) {
    this->save_paused = this->get_paused();
    if (paused != this->save_paused) {
        if (paused != 0) {
            this->non_user_pause = non_user_pause;
        } else {
            this->non_user_pause = 0;
        }
        this->request_pause();
    }
}


// PDB ownership: matching/00420270_get_mouse_info.cpp



void RGE_Base_Game::get_mouse_info(unsigned int flags, long lparam, tagPOINT& point, int& lbtn, int& rbtn, int& mbtn, int& wheel) {
    int x = lparam & 0xFFFF;
    int y = (unsigned long)lparam >> 0x10;
    point.x = x;
    point.y = y;
    if (60000 < x) {
        point.x = x - 0x10000;
    }
    if (60000 < y) {
        point.y = y - 0x10000;
    }
    lbtn = flags & 1;
    rbtn = flags & 2;
    mbtn = flags & 8;
    wheel = flags & 4;
}


// PDB ownership: matching/004202E0_get_mouse_pos.cpp
void RGE_Base_Game::get_mouse_pos(tagPOINT& pt) {
    GetCursorPos(&pt);
    if (this->prog_info->full_screen == 0) {
        ScreenToClient(this->prog_window, &pt);
        if (pt.x > 60000) {
            pt.x += -0x10000;
        }
        if (pt.y > 60000) {
            pt.y += -0x10000;
        }
    }
}


// PDB ownership: scratch/00420330_get_player.cpp
RGE_Player* RGE_Base_Game::get_player(void) {
    RGE_Game_World* w = this->world;
    if (!w) return 0;
    if (!w->player_num) return 0;
    if (w->curr_player >= w->player_num) return 0;
    return w->players[(int)(short)w->curr_player];
}


// PDB ownership: matching/00420360_draw_window.cpp
extern void (__stdcall *g_draw_window_fn)(int hwnd);


void RGE_Base_Game::draw_window() {
    g_draw_window_fn((int)this->prog_window);
}


// PDB ownership: matching/00420370_mouse_on.cpp


extern "C" __declspec(dllimport) void* __stdcall SetCursor(void*);


void RGE_Base_Game::mouse_on() {
    if (this->is_mouse_on == 0) {
        if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
            this->mouse_pointer->on();
            this->is_mouse_on = 1;
            return;
        }
        SetCursor(this->mouse_cursor);
        SetClassLongA(this->prog_window, -12, (long)this->mouse_cursor);
        this->is_mouse_on = 1;
    }
}


// PDB ownership: matching/004203E0_mouse_off.cpp
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hcur);



void RGE_Base_Game::mouse_off() {
    if (is_mouse_on) {
        if (custom_mouse && !windows_mouse) {
            mouse_pointer->off();
            is_mouse_on = 0;
            return;
        }
        SetCursor(0);
        SetClassLongA(prog_window, -12, 0);
        is_mouse_on = 0;
    }
}


// PDB ownership: matching/00420440_set_windows_mouse.cpp
// VA: 00420440 RGE_Base_Game::set_windows_mouse
// PDB source: basegame.cpp
// Attempt log:
// v0: natural decompiler-shaped source using sibling mouse_on/off declarations.

extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hcur);



void RGE_Base_Game::set_windows_mouse(int value) {
    if (this->custom_mouse != 0) {
        this->windows_mouse = value;
    } else {
        this->windows_mouse = 1;
    }

    if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
        SetCursor(0);
        SetClassLongA(this->prog_window, -12, 0);
        if (this->is_mouse_on != 0) {
            this->mouse_pointer->on();
            return;
        }
        this->mouse_pointer->off();
        return;
    }

    this->mouse_pointer->off();
    if (this->is_mouse_on != 0) {
        SetCursor(this->mouse_cursor);
        SetClassLongA(this->prog_window, -12, (long)this->mouse_cursor);
    } else {
        SetCursor(0);
        SetClassLongA(this->prog_window, -12, 0);
    }
}


// PDB ownership: matching/00420500_set_mouse_cursor.cpp
// RGE_Base_Game::set_mouse_cursor at 00420500 (basegame.cpp lines 3448-3457)
// Inventory: 00420500_set_mouse_cursor
// Status: first pass â€” building to compare

// Forward declarations for class types used in layout (only sizes matter)
class RGE_Game_Info;
class RGE_Scenario_File_Info;
class RGE_Prog_Info;



// Global last_mouse_cursor (declared in some compilation unit)
extern "C" void* last_mouse_cursor;

// Windows API functions (via USER32.DLL imported IAT)
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hCursor);

void RGE_Base_Game::set_mouse_cursor(void* new_cursor) {
    this->mouse_cursor = new_cursor;

    if (new_cursor != 0) {
        last_mouse_cursor = new_cursor;
    }

    if (this->is_mouse_on == 0) {
        return;
    }

    if (this->custom_mouse != 0) {
        if (this->windows_mouse == 0) {
            return;
        }
    }

    SetCursor(this->mouse_cursor);
    SetClassLongA(this->prog_window, 0xFFFFFFF4, (unsigned long)this->mouse_cursor);
}


// PDB ownership: matching/00420560_set_mouse_facet.cpp
void RGE_Base_Game::set_mouse_facet(long param)
{
    this->mouse_pointer->set_facet(param);
}


// PDB ownership: matching/00420580_enum_wnd_proc.cpp

int __stdcall enum_wnd_proc(void* param_1, long param_2) {
    char buffer[256];
    GetWindowTextA(param_1, buffer, 255);
    return 1;
}


// PDB ownership: matching/004205B0_enum_child_proc.cpp

int __stdcall enum_child_proc(void* param_1, long param_2) {
    char buffer[256];
    GetWindowTextA(param_1, buffer, 255);
    return 1;
}


// PDB ownership: matching/004205E0_enum_thread_proc.cpp

int __stdcall enum_thread_proc(void* param_1, long param_2) {
    char buffer[256];
    GetWindowTextA(param_1, buffer, 255);
    return 1;
}


// PDB ownership: matching/00420610_close_thread_windows.cpp

extern void* AppWnd;

int __stdcall close_thread_windows(void* wnd, long unused) {
    if (wnd != AppWnd) {
        if (GetParent(wnd) != AppWnd) {
            SendMessageA(wnd, 0x10, 0, 0);
        }
    }
    return 1;
}


// PDB ownership: matching/00420650_close_child_windows.cpp
// 00420650 close_child_windows
//
// Attempt log:
// - Prior scratch hand-spelled an inline strcmp-like loop. Behavior was correct, but VC5 chose a different
//   register/loop family without EBX and with broad scheduling drift.
// - SpruceGlow MATCH: declare/use plain CRT `strcmp(str, s_Locate_Session) != 0`. Under the pinned VC5 /O2 flags,
//   this inlines to the original hand-unrolled strcmp loop using EDI hwnd, ESI literal pointer, EAX buffer pointer,
//   and EBX scratch.
// Result: MATCH locally with `python tools/check_function.py --va 00420650`.

extern "C" int __cdecl strcmp(const char* a, const char* b);

extern char s_Locate_Session[];

int __stdcall close_child_windows(void* hwnd, long param)
{
    char str[256];

    str[0] = 0;
    GetWindowTextA(hwnd, str, 0xff);

    if (strcmp(str, s_Locate_Session) != 0) {
        SendMessageA(hwnd, 0x10, 0, 0);
    }

    return 1;
}


// PDB ownership: scratch/004206D0_wnd_proc.cpp
// VA: 004206D0 RGE_Base_Game::wnd_proc (2181 B)
// PDB source: basegame.cpp:3513-3975
// Attempt log:
// - Rebuilt the message dispatcher from the executable's ordered calls and
//   switch cases.  The prior file was only a behavior sketch with omitted
//   handlers and wrapper calls.
// - Added the period Win32 imports, named base-game fields, panel virtual
//   surface, sound/music forwarding, and all observed message handlers.
// - Corrected the WM_CLOSE fallthrough and shared the 0x10/0x30F and
//   0x3B9/0x500 handler tails.  The child-cursor state is at 0062C4C4.
// - Raw return blocks at 00420D04, 00420E5E, and 00420E74 reload the wparam
//   home at [esp+24].  Ordinary handled tails return wparam; only WM_USER
//   0x400 returns the panel result after restoring debug_timeGetTime_on.
// - An explicit mouse_down pair in the destroy, exit-menu, and music paths was
//   rolled back after VC5 proved it away or merged it without adding calls.
// - Inlining the panel-result tails for exit-menu and music-done raised the
//   call surface from 74 to 78 calls and the shape score to 89.33 percent.
// - A WM_SIZE tail returning wparam kept a separate 4C/24 log pair: 80/80
//   calls and +1 byte versus 80/80 and -9 bytes with panel_result.  Keep this
//   binary-supported return-home lead while the shared-tail return remains.
// - Replacing all handled-tail predicates with mouse_down matched the later
//   [esp+10] loads but collapsed four log calls.  Restored the 80-call source.
// - Kept the WM_SIZE handled tail on mouse_down: it recovers the binary's
//   [esp+10] load and one exact block without changing the 80-call surface.
// - Corrected WM_ACTIVATE to use wparam's high word.  Named int word values
//   recover the binary's shared extraction and reduce the diff to 1118 bytes;
//   the remaining cost is a 17-byte size increase and tail placement drift.
// - Inlined the thread-id comparison and reversed its operands to match the
//   original call-result homes and cmp operand order.
// - Made the definition the __stdcall RGE_Base_Game member.  This restores the
//   original decorated owner symbol and the stack-passed member ABI.
// - Binary evidence at 00420D04 loads the mouse-down home before the handled
//   log pair.  The early handled tail now uses that predicate; changing the
//   other joined tails merges distinct shipped blocks and loses call order.
// - Tested the exact-donor panel_system macro and the period Windows SDK
//   surface.  They restore the absolute panel receiver, but do not remove the
//   remaining tail-placement drift.
// - Probes 1-25 tested owner ABI, return-tail predicates, stack aliases,
//   global forms, SDK context, boolean width, and switch source order.
// - Direct external declarations for the fixed storage slots recover the
//   original absolute load/store form without pointer aliases.  The remaining
//   drift is the compiler's shared WM_SIZE logging tail and shifted blocks.
// - Behavior review corrected message 0x400's first color-log argument,
//   restored WM_COMMAND's unconditional DefWindowProcA path, and made the
//   music-done exit log depend only on mouse_down before returning wparam.
// - The corrected ordinary tails improve the current check to 1,609 bytes,
//   94.88 percent shape, and 78/80 ordered calls.  VC5 still merges the
//   WM_SIZE two-log block into the music block.  Raw code proves a separate
//   block at 00420859; source-order and lifetime probes did not split it.
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

extern void color_log(unsigned char a, unsigned char b, int c);

// BINARY NOTE: these external objects occupy the fixed storage slots observed
// in the executable.  Direct objects preserve the original absolute accesses.
extern int system_ignore_size_messages_storage;
extern int MouseCursorInChildContol_storage;
extern int mouse_cursor_in_child_control_storage;
extern void* save_active_wnd_storage;
extern int do_restore_palette_storage;
extern unsigned long restore_palette_timer_storage;
extern int restore_mouse_after_paint_storage;
extern int debug_timeGetTime_on_storage;





class TPanel;

// BINARY NOTE: panel_system is the fixed object at 0062E870.
long __stdcall RGE_Base_Game::wnd_proc(void* hwnd, unsigned int msg,
                                       unsigned int wparam, long lparam)
{
    RGE_Base_Game* self = this;
    color_log(0x24, 0x24, 3);
    int mouse_down = 0;
    if (msg >= 0x201 && msg <= 0x206) {
        mouse_down = 1;
        color_log(0x4C, 0x4C, 4);
    }

    if (self->sound_system != 0) {
        self->sound_system->handle_messages(hwnd, msg, wparam, lparam);
    }

    color_log(0x24, 0x16, 3);
    if (self->music_system != 0) {
        self->music_system->handle_messages(hwnd, msg, wparam, lparam);
    }

    color_log(0x24, 0x4C, 3);

    long panel_result = 0;
    TPanel* panel = panel_system.currentPanel();
    if (panel != 0) {
        color_log(0x24, 0x32, 3);
        panel = panel_system.currentPanel();
        panel_result = panel->wnd_proc(hwnd, msg, wparam, lparam);
        if (panel_result != 0 && msg != 0x200 && msg != 0x113)
            goto panel_return_after_exit_menu;
    }

    color_log(0x24, 0x45, 3);

    switch (msg) {
    case 2:
        color_log(0x32, 0xBA, 3);
        if (self->handle_destroy(hwnd, 2, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_alt;

    case 5:
        {
        if (system_ignore_size_messages_storage != 0)
            goto default_window_proc;
        color_log(0x32, 0xBA, 3);
        int size_handled = self->handle_size(hwnd, 5, wparam, lparam);
        if (size_handled != 0)
            goto default_window_proc;
        if (mouse_down == 0)
            goto wparam_return;
        color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return (long)wparam;
        }

    case 6:
        if (self->prog_ready != 0) {
            int active_state = wparam & 0xFFFF;
            int minimized = wparam >> 16;
            if (active_state == 0) {
                if (GetWindowThreadProcessId((void*)lparam, 0) ==
                    GetWindowThreadProcessId(self->prog_window, 0))
                    save_active_wnd_storage = (void*)lparam;
            }
            if (hwnd == self->prog_window && active_state != 0 &&
                minimized != 0 && save_active_wnd_storage != 0) {
                save_active_wnd_storage = 0;
            }
        }
        goto default_window_proc;

    case 0x0F:
        color_log(0x32, 0x45, 3);
        if (self->handle_paint(hwnd, 0x0F, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x1C:
        if (self->prog_ready != 0) {
            if (wparam == 1) {
                if (MouseCursorInChildContol_storage != 0) {
                    SetCursor(0);
                    SetClassLongA(self->prog_window, -12, 0);
                    if (self->prog_mode != 1)
                        self->restart_sound_system();
                    MouseCursorInChildContol_storage = 0;
                    if (self->draw_system != 0) {
                        self->draw_system->CheckSurfaces();
                        self->draw_system->ClearRestored();
                        self->set_render_all();
                    }
                    if (self->prog_mode != 1) {
                        if (self->draw_system != 0) {
                            self->draw_system->ClearPrimarySurface();
                            self->draw_system->ModifyPalette(
                                0, 0x100, self->draw_system->palette);
                        }
                        self->set_render_all();
                        InvalidateRect(self->prog_window, 0, 1);
                        do_restore_palette_storage = 10;
                        restore_palette_timer_storage = debug_timeGetTime(
                            (char*)0x57FB08, 0xE9B);
                        restore_mouse_after_paint_storage = 1;
                    }
                }
            } else if (MouseCursorInChildContol_storage == 0) {
                SetClassLongA(self->prog_window, -12, 0);
                if (self->prog_mode != 1)
                    self->stop_sound_system();
                MouseCursorInChildContol_storage = 1;
                if (self->prog_mode != 1 && self->mouse_pointer != 0)
                    self->mouse_pointer->Shutdown_Mouse();
            }
        }
        color_log(0x32, 0x54, 3);
        if (self->handle_activate(hwnd, 0x1C, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x104:
        color_log(0x24, 0xBA, 3);
        {
            int handled = self->handle_key_down(hwnd, 0x104, wparam, lparam);
            if (handled != 0)
                goto default_window_proc;
        }
        goto panel_return;

    case 0x100:
        color_log(0x24, 0xBA, 3);
        {
            int handled = self->handle_key_down(hwnd, 0x100, wparam, lparam);
            if (handled != 0)
                goto default_window_proc;
        }
        goto panel_return;

    case 0x105:
        if (wparam == 0x12 && panel_system.currentPanel() != 0) {
            panel = panel_system.currentPanel();
            panel->handle_reactivate();
        }
        goto default_window_proc;

    case 0x111:
        color_log(0x32, 0x16, 3);
        if (self->handle_command(hwnd, 0x111, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_after_exit_menu;

    case 0x112:
        if (wparam == 0xF100 && self->prog_info->skip_startup != 0 &&
            IsIconic(self->prog_window) == 0)
            return 0;
        goto default_window_proc;

    case 0x113:
        if (self->handle_idle() != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x116:
        color_log(0x32, 0xBA, 3);
        if (self->handle_init_menu(hwnd, 0x116, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x200:
        color_log(0x24, 0x54, 3);
        if (self->handle_mouse_move(hwnd, 0x200, wparam, lparam) != 0) {
            if (mouse_cursor_in_child_control_storage != 0) {
                if (self->windows_mouse == 0) {
                    SetCursor(0);
                    SetClassLongA(self->prog_window, -12, 0);
                    self->mouse_on();
                    mouse_cursor_in_child_control_storage = 0;
                } else {
                    SetCursor(self->mouse_cursor);
                    mouse_cursor_in_child_control_storage = 0;
                }
            }
            goto default_window_proc;
        }
        goto panel_return;

    case 0x212:
        color_log(0x32, 0xBA, 3);
        if (self->handle_exit_menu(hwnd, 0x212, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_after_exit_menu;

panel_return_after_exit_menu:
        if (mouse_down != 0)
            color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return (long)wparam;

    case 0x218:
        if (wparam == 0)
            return 0x424D5144;
        goto default_window_proc;

    case 0x10:
        goto close_message;

    case 0x30F:
        color_log(0x32, 0xBA, 3);
        if (self->handle_query_new_palette(hwnd, 0x30F, wparam, lparam) != 0)
            goto close_message;
        goto panel_return_alt;

    case 0x311:
        color_log(0x32, 0xBA, 3);
        if (self->handle_palette_changed(hwnd, 0x311, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_alt;

    case 0x3B9:
        goto music_done_message;

    case 0x400:
        color_log(0x32, 0x24, 3);
        {
            int old_time = debug_timeGetTime_on_storage;
            debug_timeGetTime_on_storage = 0;
            if (self->handle_user_command(hwnd, 0x400, wparam, lparam) == 0) {
                if (mouse_down != 0)
                    color_log(0x4C, 0x5F, 4);
                color_log(0x24, 0x5F, 3);
                debug_timeGetTime_on_storage = old_time;
                return (long)panel_result;
            }
            debug_timeGetTime_on_storage = old_time;
        }
        goto default_window_proc;

    case 0x500:
        goto music_done_message;

close_message:
    color_log(0x32, 0xBA, 3);
    if (self->handle_close(hwnd, msg, wparam, lparam) != 0)
        goto default_window_proc;
    if (panel_result != 0) {
        color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return (long)panel_result;
    }
    goto panel_return_alt;

music_done_message:
    {
    color_log(0x32, 0x4C, 3);
    int music_handled = self->handle_music_done(hwnd, msg, wparam, lparam);
    if (music_handled != 0)
        goto default_window_proc;
    if (mouse_down != 0)
        color_log(0x4C, 0x5F, 4);
    color_log(0x24, 0x5F, 3);
    return (long)wparam;
    }

    default:
        goto default_window_proc;
    }

 wparam_return:
    color_log(0x24, 0x5F, 3);
    return (long)wparam;

panel_return:
    if (mouse_down == 0)
        goto panel_return_alt;
    color_log(0x4C, 0x5F, 4);
    color_log(0x24, 0x5F, 3);
    return (long)wparam;

panel_return_alt:
    if (mouse_down != 0)
        color_log(0x4C, 0x5F, 4);
    color_log(0x24, 0x5F, 3);
    return (long)wparam;

default_window_proc:
    {
        color_log(0x24, 0x54, 3);
        long result = DefWindowProcA(hwnd, msg, wparam, lparam);
        if (mouse_down != 0)
            color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return result;
    }

}


// PDB ownership: matching/00420F60_handle_idle.cpp
// VA: 00420F60 RGE_Base_Game::handle_idle (431 B)
// PDB source: basegame.cpp
// Attempt log:
// - Baseline used a packet-grounded free-function/raw-offset scaffold; it had
//   the correct broad behavior but emitted wrapper call identities and a raw
//   vtable call, leaving a 463-byte / 21-call mismatch.
// - Probe 2: restored the period typed member surfaces for RGE_Base_Game,
//   TDrawSystem, TSound_Driver, TPanelSystem, TPanel, and communications. The
//   field ownership remains named; the original panel palette member and
//   virtual show_comm/show_ai calls are used instead of raw vtable plumbing.

extern void color_log(unsigned char a, unsigned char b, int c);
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern int do_restore_palette;
extern int restore_palette_timer;




class TPanel;
class TDrawArea;
typedef int PositionMode;
typedef int RedrawMode;



extern TPanelSystem panel_system;



int RGE_Base_Game::handle_idle()
{
    if (!this->prog_ready || !this->prog_window)
        return 0;

    color_log(0x16, 0x16, 2);

    if (do_restore_palette && this->prog_active) {
        int delay = 0xFA;
        if (do_restore_palette > 5)
            delay = 0x1F4;

        unsigned long t = debug_timeGetTime((char*)0x57FB08, 0xF9A);
        if ((t - restore_palette_timer) >= (unsigned long)delay) {
            if (this->draw_system) {
                this->draw_system->ModifyPalette(0, 0x100,
                    this->draw_system->palette);
            }
            do_restore_palette--;
            restore_palette_timer = debug_timeGetTime((char*)0x57FB08,
                                                       0xFA4);
        }
    }

    color_log(0x32, 0x32, 5);

    if (this->sound_system) {
        color_log(0x16, 0xBA, 2);
        this->sound_system->handle_messages(this->prog_window, 0x113, 0, 0);
    }

    TPanel* panel = panel_system.currentPanel();
    if (panel != 0) {
        color_log(0x16, 0x45, 2);
        panel = panel_system.currentPanel();
        panel->handle_idle();
    }

    if (this->comm_handler) {
        if (this->multiplayerGame()) {
            color_log(0x45, 0x45, 1);
            this->comm_handler->ReceiveGameMessages();
            color_log(0x45, 0x5F, 1);
        }
    }

    if (this->do_show_comm) {
        color_log(0x16, 0x32, 2);
        this->show_comm();
    }

    if (this->do_show_ai) {
        color_log(0x16, 0x24, 2);
        this->show_ai();
    }

    color_log(0x32, 0x5F, 5);
    color_log(0x16, 0x5F, 2);

    return 1;
}


// PDB ownership: matching/00421110_handle_mouse_move.cpp
// RGE_Base_Game::handle_mouse_move
// VA: 00421110
// basegame.cpp






int RGE_Base_Game::handle_mouse_move(void* p1, unsigned int p2, unsigned int p3, long p4)
{
    struct Frame {
        int ctrl_key;
        int right_btn;
        int left_btn;
        tagPOINT point;
        int shift_key;
    } f;
    if (this->prog_ready == 0) {
        return 1;
    }

    if (this->custom_mouse != 0 && this->windows_mouse == 0) {
        if (this->mouse_pointer->in_game_mode()) {
            this->mouse_pointer->Poll();
        } else {
            this->mouse_pointer->draw(0);
        }
    }

    this->get_mouse_info(p3, p4, &f.point.y, &f.point.x, &f.left_btn, &f.right_btn, &f.ctrl_key);
    this->action_mouse_move(
        f.point.y, f.shift_key, f.point.x, f.left_btn, f.right_btn, f.ctrl_key);
    this->handle_idle();
    return 1;
}


// PDB ownership: matching/004211D0_handle_key_down.cpp
// VA: 004211D0 RGE_Base_Game::handle_key_down (268 B)
// PDB source: basegame.cpp
// Attempt log:
// - Baseline used a free-function shim and local globals; it had the wrong
//   __thiscall prologue and helper/call surfaces (90.7143% positional diff).
// - Reconstructed the period RGE_Base_Game member layout, imported GetKeyState
//   pointer, TDrawArea::take_snapshot(char*, int&), and action_key_down slot.
// - A local GetKeyState pointer alias after the readiness guard reproduces the
//   original one-time IAT load into ESI and three calls through that pointer.
// - Main-agent audit restored the canonical base-game destructor slot while
//   preserving the proven +0xC4/+0x100 virtual positions; output remains exact.

extern int snapshot_number;

extern unsigned int DAT_005b2164;
extern unsigned int DAT_005b2368;
extern unsigned int DAT_005b2370;
extern unsigned int DAT_0062c4b4;
extern unsigned int DAT_0062c4bc;







int RGE_Base_Game::handle_key_down(void* param_1, unsigned int param_2,
                                   unsigned int param_3, long param_4)
{
    if (this->prog_ready == 0) {
        return 1;
    }

    short (__stdcall *get_key_state)(int) = GetKeyState;

    DAT_005b2368 = param_3;
    DAT_005b2370 = param_4 & 0xFFFF;
    DAT_0062c4bc = (get_key_state(0x11) < 0);
    DAT_0062c4b4 = (get_key_state(0x12) < 0);
    DAT_005b2164 = (get_key_state(0x10) < 0);

    if (param_1 == this->prog_window && param_2 == 0x104 &&
        (DAT_005b2368 == 0x12 || DAT_005b2368 == 0x20 ||
         DAT_005b2368 == 0x79) &&
        this->prog_info->full_screen != 0 &&
        IsIconic(this->prog_window) == 0) {
        return 0;
    }

    if (DAT_0062c4bc != 0 && DAT_005b2368 == 0x7B) {
        this->draw_system->DrawArea->take_snapshot(
            ".\\AoE%04d.bmp", snapshot_number);
        return 0;
    }

    return this->action_key_down(DAT_005b2368, DAT_005b2370,
                                 DAT_0062c4bc, DAT_0062c4b4,
                                 DAT_005b2164) != 0;
}


// PDB ownership: matching/004212E0_handle_user_command.cpp
// VA: 004212E0 RGE_Base_Game::handle_user_command
// PDB source: basegame.cpp

extern int out_of_sync;




int RGE_Base_Game::handle_user_command(void* param_1, unsigned int param_2, unsigned int command, long param)
{
    if (this->comm_handler->MultiplayerGameStart() != 0 && out_of_sync == 0) {
        if (command == 0x17B3) {
            this->world->players[this->playerID(param)]->command_resign((int)param, 1);
        } else if (command == 0x17B4) {
            this->world->players[this->playerID(param)]->command_resign((int)param, 0);
        }
    }

    switch (command) {
    case 0x17A2:
        if (this->world != 0) {
            this->world->pause((unsigned char)1);
        }
        break;
    case 0x17A3:
        if (this->world != 0) {
            this->world->pause((unsigned char)0);
        }
        break;
    }

    return this->action_user_command(command, param) != 0;
}


// PDB ownership: matching/004213A0_handle_command.cpp


int RGE_Base_Game::handle_command(void* a, unsigned int b, unsigned int c, long d)
{
    return this->action_command((unsigned long)c, (unsigned long)d) != 0;
}


// PDB ownership: matching/004213C0_handle_music_done.cpp


int RGE_Base_Game::handle_music_done(void* p0, unsigned int p1,
                                     unsigned int p2, long p3) {
    return this->action_music_done() != 0;
}


// PDB ownership: matching/004213E0_handle_paint.cpp
// VA: 004213E0 RGE_Base_Game::handle_paint (1096 B)
// PDB source: basegame.cpp:4319-4531
// Attempt log:
// - Replaced the packet's raw-offset/free-function scaffold with the period
//   typed RGE_Base_Game, TDrawSystem, TPanel, TMousePointer, and COM surfaces.
//   Kept the original timing/panel/mouse control-flow shape and corrected the
//   final InvalidateRect receiver to the incoming window parameter.
// - The animation deadline is updated in place before the do-loop; this is the
//   natural source form that preserves the oracle's result/deadline registers.
// - The panel test is a direct positive currentPanel() predicate, and the
//   proven panel_system global is kept at 0062E870.
// - The late timing expression keeps the panel delta on the left of the
//   inline 115B elapsed subtraction; this preserves the original x86 order.



typedef int PositionMode;
typedef int RedrawMode;

struct tagRECT;
class TDrawArea;
class TShape;

extern void color_log(unsigned char a, unsigned char b, int c);
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* cursor);










extern RGE_Base_Game* rge_base_game;
extern int restore_mouse_after_paint;
int RGE_Base_Game::handle_paint(void* param_1, unsigned int param_2,
                                unsigned int param_3, long param_4)
{
    unsigned long time_a;
    unsigned long time_b;
    unsigned long time_c;
    int result;

    color_log(0x32, 0x32, 4);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x10EA);
    result = this->check_paint();
    time_b = debug_timeGetTime((char*)0x57FB08, 0x10EE);
    this->add_to_timing(5, time_b - time_a);

    if (result == 0) {
        color_log(0x32, 0x5F, 4);
        return 0;
    }

    if (((this->prog_mode == 4 || this->prog_mode == 6 ||
          this->prog_mode == 7) &&
         this->draw_system->DrawType != 1 && this->custom_mouse != 0) &&
        this->mouse_blit_sync != 0) {
        IDirectDrawSurface* surface = this->draw_system->PrimarySurface;
        result = surface->GetBltStatus(1);
        time_a = debug_timeGetTime((char*)0x57FB08, 0x10FC);
        time_a += 100;

        do {
            if (result != (int)0x8876021C)
                goto paint_done;

            surface = this->draw_system->PrimarySurface;
            result = surface->GetBltStatus(1);
            time_b = debug_timeGetTime((char*)0x57FB08, 0x1100);
        } while (time_b <= time_a);

        this->mouse_blit_sync = 0;
    }

paint_done:
    color_log(0x32, 0xBA, 4);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x110C);
    TSound_Driver* sound = rge_base_game->sound_system;
    if (sound != 0) {
        sound->play_list();
        sound->reset_play_list();
    }

    time_b = debug_timeGetTime((char*)0x57FB08, 0x1115);
    this->add_to_timing(10, time_b - time_a);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x111C);
    if (this->erase_mouse != 0) {
        color_log(0x32, 0x4C, 4);
        if (this->render_all == 0 && this->custom_mouse != 0)
            this->mouse_pointer->erase();
        this->erase_mouse = 0;
    }

    time_c = debug_timeGetTime((char*)0x57FB08, 0x1127) - time_a;
    time_a = debug_timeGetTime((char*)0x57FB08, 0x112A);
    color_log(0x32, 0x16, 4);

    TPanel* panel;
    if (panel_system.currentPanel() != 0) {
        color_log(0x16, 0x16, 1);
        if (this->render_all != 0) {
            panel = panel_system.currentPanel();
            panel->set_redraw(TPanel::RedrawImmediate);
        }
        panel = panel_system.currentPanel();
        panel->handle_paint();
        color_log(0x16, 0x5F, 1);
    } else {
        this->clear_window();
    }

    color_log(0x32, 0x24, 4);
    if (DAT_0062c57c != 0) {
        DAT_0062c57c = 0;
        if ((this->prog_mode == 4 || this->prog_mode == 5) &&
            this->do_show_timings != 0)
            this->show_timings();
    }

    time_b = debug_timeGetTime((char*)0x57FB08, 0x1147);
    this->add_to_timing(2, time_b - time_a);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x114B);
    color_log(0x32, 0x54, 4);
    if (this->custom_mouse != 0 && this->windows_mouse == 0) {
        this->mouse_pointer->draw(1);
        this->erase_mouse = 1;
    }

    time_c += debug_timeGetTime((char*)0x57FB08, 0x115B) - time_a;
    this->add_to_timing(8, time_c);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x1160);
    color_log(0x32, 0x45, 4);
    this->draw_system->Paint(0);
    ValidateRect(this->prog_window, 0);
    ValidateRect(this->prog_window, 0);
    this->render_all = 0;

    time_b = debug_timeGetTime((char*)0x57FB08, 0x1176);
    this->add_to_timing(3, time_b - time_a);

    color_log(0x32, 0x5F, 4);
    ++this->frame_count;

    time_a = debug_timeGetTime((char*)0x57FB08, 0x1182);
    if (time_a - DAT_0062c578 >= 1000) {
        this->calc_timings();
        DAT_0062c578 = time_a;
        DAT_0062c57c = 1;
    }

    if (restore_mouse_after_paint != 0) {
        if (this->mouse_pointer != 0) {
            this->mouse_pointer->Restore_Mouse(this->draw_area);
            if (this->is_mouse_on != 0) {
                if (this->custom_mouse == 0 || this->windows_mouse != 0) {
                    SetCursor(this->mouse_cursor);
                    SetClassLongA(this->prog_window, -12,
                                  (long)this->mouse_cursor);
                } else {
                    this->mouse_pointer->on();
                    this->mouse_pointer->draw(1);
                }
            }
            InvalidateRect(param_1, 0, 0);
        }
        restore_mouse_after_paint = 0;
    }

    return 1;
}


// PDB ownership: matching/00421830_handle_activate.cpp
// VA: 00421830 RGE_Base_Game::handle_activate (215 B)
// PDB source: basegame.cpp lines 4537-4598
// Attempt log:
// baseline reconstruction: named RGE_Base_Game fields, natural active/inactive
// branches, typed direct helpers, and virtual dispatch surfaces from the packet.
// The complete panel and base-game call surface produced the exact match.





extern TPanelSystem panel_system;


int RGE_Base_Game::handle_activate(void* param_1, unsigned int param_2,
                                   unsigned int param_3, long param_4)
{
    if (param_3 != 0) {
        this->prog_active = 1;
    } else {
        this->prog_active = 0;
    }

    if (this->prog_active != 0) {
        if ((this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 7) &&
            this->auto_paused == 1) {
            this->auto_paused = 0;
            this->set_paused(0, 0);
        }

        TPanel* panel = panel_system.currentPanel();
        if (panel != 0) {
            panel = panel_system.currentPanel();
            panel->handle_reactivate();
        }
        this->action_activate();
    } else {
        if (this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 7) {
            if (this->singlePlayerGame() == 1 && this->get_paused() == 0) {
                this->auto_paused = 1;
                this->set_paused(1, 0);
            }
        }
        this->action_deactivate();
    }

    return 1;
}


// PDB ownership: matching/00421910_handle_init_menu.cpp


int RGE_Base_Game::handle_init_menu(void* p0, unsigned int p1,
                                    unsigned int p2, long p3) {
    return this->action_init_menu() != 0;
}


// PDB ownership: matching/00421930_handle_exit_menu.cpp


int RGE_Base_Game::handle_exit_menu(void* p0, unsigned int p1,
                                    unsigned int p2, long p3) {
    return this->action_exit_menu() != 0;
}


// PDB ownership: matching/00421950_handle_size.cpp
// VA: 00421950 RGE_Base_Game::handle_size(void*, unsigned int, unsigned int, long)
// PDB source: basegame.cpp lines 4626-4649 (151 B, 52 asm)
// Attempt log:





extern TPanelSystem panel_system;


int RGE_Base_Game::handle_size(void* p1, unsigned int p2, unsigned int p3, long p4)
{
    if (p3 == 1) return 1;

    if (this->draw_system != 0) {
        this->draw_system->HandleSize(p1, p2, p3, p4);

        if (this->draw_system != 0 && this->draw_system->ScreenWidth != 0) {
            this->prog_info->main_wid = this->draw_system->ScreenWidth;
            this->prog_info->main_hgt = this->draw_system->ScreenHeight;
        }

        TPanel* panel = panel_system.currentPanel();
        if (panel != 0) {
            panel = panel_system.currentPanel();
            panel->handle_size(this->prog_info->main_wid, this->prog_info->main_hgt);
        }
    }

    this->action_size();
    return 1;
}


// PDB ownership: matching/004219F0_handle_palette_changed.cpp
// VA: 004219F0 RGE_Base_Game::handle_palette_changed
// basegame.cpp lines 4655-4678
//
// Attempt log:
// - Initial stub was empty.
// - Natural member-call/control-flow shape nearly matched, but the fallback virtual call initially used the wrong
//   vtable slot and returned the virtual result, shortening the final epilogue.
// - SpruceGlow MATCH: expose the fallback virtual at vtable offset 0xEC (59 dummy slots before it) and call it for
//   side effect only, then return 1. Keep the slightly unsafe source order `DrawType || ScreenMode || ds == 0` to
//   preserve the original null test after the byte checks.
// Result: MATCH locally with `python tools/check_function.py --va 004219F0`.



int RGE_Base_Game::handle_palette_changed(void* p1, unsigned int p2, unsigned int p3, long p4) {
    if (this->draw_system != 0) {
        this->draw_system->HandlePaletteChanged(p1, p2, p3, p4);
    }

    if ((void*)p3 != p1) {
        TDrawSystem* ds = this->draw_system;
        if (ds->DrawType == 1 || ds->ScreenMode == 1 || ds == 0) {
            this->handle_query_new_palette(p1, p2, p3, p4);
        }
        else if (this->prog_mode != 1) {
            ds->ModifyPalette(0, 0x100, ds->palette);
            return 1;
        }
    }

    return 1;
}


// PDB ownership: matching/00421A80_handle_query_new_palette.cpp
// VA: 00421A80 RGE_Base_Game::handle_query_new_palette (234 B)
// PDB source: basegame.cpp lines 4683-4726
//
// Attempt log:
// - Baseline rewrite (this session): corrected both TDrawSystem::HandleQueryNewPalette
//   calls to pass (hwnd, msg, wparam, lparam) through unchanged (the old scratch passed
//   (long)hwnd as the last arg, a Ghidra stack-mis-analysis). Rebuilt the palette path
//   from the binary: double currentPanel call (first result only null-tested), double
//   get_palette call (second inline in SelectPalette), prog_palette default load sunk
//   into the else arm, SelectPalette spelled in both arms to preserve the split push 0
//   and shared push-palette/push-dc/call tail, RealizePalette result saved across
//   ReleaseDC, final draw_system guard with reload, return 1.
// - Fixed RGE_Base_Game layout: gap_00[0x1C] (no-vptr class) so prog_palette lands at +0x1C
//   and draw_system at +0x48; first HandleQueryNewPalette call site reloads this->draw_system
//   (ds local dies after the guard) to reproduce the post-InvalidateRect reload.
// - MATCH: dropped the pal local entirely; tested panel->get_palette() twice (second call
//   inline in SelectPalette args) and used direct this->prog_palette access in the else
//   branch. VC5 then sinks the prog_palette load into the else arm and tail-merges the
//   shared SelectPalette push-palette/push-dc/call with the split push 0 in each arm.
// Result: MATCH locally with `python tools/check_function.py --va 00421A80`.





extern TPanelSystem panel_system;


int RGE_Base_Game::handle_query_new_palette(void* hwnd, unsigned int msg, unsigned int wparam, long lparam)
{
    TDrawSystem* ds = this->draw_system;
    if (ds != 0 && ds->DrawType != 1 && ds->ScreenMode != 1) {
        InvalidateRect(hwnd, 0, 0);
        return this->draw_system->HandleQueryNewPalette(hwnd, msg, wparam, lparam);
    }

    void* dc = GetDC(hwnd);
    if (panel_system.currentPanel() != 0) {
        TEasy_Panel* panel = static_cast<TEasy_Panel*>(panel_system.currentPanel());
        if (panel->get_palette() != 0)
            SelectPalette(dc, panel->get_palette(), 0);
    } else {
        if (this->prog_palette != 0)
            SelectPalette(dc, this->prog_palette, 0);
    }
    int result = RealizePalette(dc);
    ReleaseDC(hwnd, dc);
    if (result != 0)
        InvalidateRect(hwnd, 0, 0);
    if (this->draw_system != 0)
        return this->draw_system->HandleQueryNewPalette(hwnd, msg, wparam, lparam);
    return 1;
}


// PDB ownership: matching/00421B70_handle_close.cpp




int RGE_Base_Game::handle_close(void* param_1, unsigned int param_2, unsigned int param_3, long param_4) {
    if (this->action_close() == 0) {
        return 0;
    }
    if (this->draw_area != 0 && this->draw_system != 0) {
        this->draw_area->Clear(0, 0);
        this->draw_system->Paint(0);
    }
    return 1;
}


// PDB ownership: matching/00421BB0_handle_destroy.cpp
extern "C" __declspec(dllimport) int __stdcall KillTimer(void* hWnd, unsigned int idEvent);
extern "C" __declspec(dllimport) void __stdcall PostQuitMessage(int nExitCode);


int RGE_Base_Game::handle_destroy(void* param1, unsigned int param2, unsigned int param3, long param4) {
    this->prog_ready = 0;
    if (this->is_timer != 0) {
        KillTimer(this->prog_window, 1);
    }
    this->prog_window = 0;
    PostQuitMessage(0);
    return 1;
}


// PDB ownership: accepted_drift/00421BF0_calc_timings.cpp
// VA: 00421BF0 RGE_Base_Game::calc_timings (934 B)
// PDB source: basegame.cpp:4767-4914
// Attempt log:
// - Baseline used a packet-grounded raw-offset scaffold.  It omitted the real
//   profiler fprintf/fflush path and duplicated two time probes, producing a
//   476-byte structural mismatch.
// - Probe 2: restored the period typed timing/world/player surfaces, the three
//   single debug_timeGetTime calls, the virtual calc_timing_text call, and the
//   binary-observed giant conditional fprintf argument list.  The source keeps
//   timing ownership named while preserving the original zero-count behavior.
// - Probe 4: explicit pre-loop and post-load player-pointer increments recovered
//   the original add/dec/load scan topology and reduced the positional drift to
//   the timer-update block plus relocations.
// - Probe 7: donor-era stdlib/string/windows header context preserved the late
//   profiler argument and cleanup blocks; the remaining drift is localized to
//   VC5 scheduling around the first timer reset call.
// - Variant lab (probe 8): six plausible timer-field statement orders produced
//   no exact group.  The natural last/last-max/zero/zero/start order is retained.
// - Probes 9-10: restoring the known 0xA24 object size and testing the int
//   debug-time return ABI did not improve emitted bytes.  Final best source is
//   the typed reconstruction; exact gap is the timer block's first branch.
// - Probe 12: a natural per-iteration reference alias for the timing record
//   produced identical code; the typed pointer form remains the clean source.
// - Probe 13: snapshot max_time after storing last_time to follow the
//   original load/store order; emitted code was unchanged, so it was rolled back.
// - Current pass: the clean typed source keeps exact size (934), frame (0x18),
//   saved registers, CFG counts, and all six ordered calls.  Its only behavior
//   gap is the first timing-record block: the original pushes 0x12B5 before
//   the last/max stores and delays stack cleanup until after the include test.
// - Current pass: raw int-pointer access, signed timing fields, declaration
//   order, loop spelling, address aliases, filename forms, targeted volatile
//   fields, and local optimizer pragmas did not improve the 44-byte gap.
// - Current pass: a four-way timer statement-order lab kept size, frame, and
//   calls but produced no exact group.  A 512-variant ambient declaration lab
//   also produced no exact group; its best context was still nonexact.
// - Behavior audit: the original only accumulates include_in_total for
//   non-summary records, and emits view_update_fps before world_update_fps.
//   Restoring both facts reduced the clean mismatch from 44 to 30 bytes in
//   four spans; the remaining gap is the first timer block's instruction order.
// - Object/ABI audit: the original PDB names this method as protected
//   (?calc_timings@RGE_Base_Game@@MAEXXZ) and names debug_timeGetTime with C++
//   linkage (?debug_timeGetTime@@YAKPADH@Z).  The local declarations now emit
//   those exact COFF symbols; these ABI changes were byte-neutral.
// - Object audit: the original basegame module records VC5 11.00, Pentium,
//   hardware floating point, near code/data, a 0x3A6 function range, and no
//   inline-line records.  The /Z7 VC5 probe emits the same function range and
//   compile record.  No object evidence supports omitted locals or a stale
//   PDB boundary.
// - PDB type audit: canonical RGE_Object_List is 12 bytes with one virtual
//   load slot and list at +4.  A local canonical test worsened the body to
//   46 bytes by reversing two late logger loads, so the narrow +8 field view
//   remains.  This target proves only number_of_objects at +8.
// - Current pass: a natural indexed timing scan with a per-iteration indexed
//   member access reproduces the timer block and reduces the gap from 30 to 6.
// - Current pass: incrementing the player-list pointer before decrementing its
//   remaining count reproduces the observed setup order and reduces the gap to
//   2 bytes.  The remaining two bytes are the quotient sum load order.
// - Specialist audit: PDB line 4900 and the Ghidra stack locals support the
//   seven quotient results as outgoing homes.  Reverse-order named quotient
//   locals, a named denominator, and a sequential sum all emit the same
//   2-byte mismatch.  A guarded named sum changes the CFG and is rejected.
// - Specialist audit: the original hunk loads timing[10] at +0x221 and
//   timing[12] at +0x227.  Natural direct and reversed `+` expressions both
//   load timing[12] first under this VC5 context.  The exact calc_timing_text
//   donor confirms that the surrounding use changes this commutative schedule.
// - Specialist follow-up: natural unsigned `a - (0 - b)` preserved the same
//   two-byte hunk, while the donor-supported timings union worsened two late
//   logger displacements.  Both probes were restored.
// - Context gate: the direct BaseGame source stops at 0041B6A0. 00421BF0 is
//   not registered. No config edit was used.
// - PDB inventory orders owners from 0041ED00 through 00421FA0. 0041E7A0
//   remains an independently checked prefix anchor. The grouped later checks
//   preserve size, frame, six calls, publication, rollover, and fault order.
//   They retain the two quotient-load bytes. The context does not resolve it.
// - Fresh grouped checks: 0041E7A0 and 00421FA0 both report MATCH with their
//   PDB-qualified owners; 00421BF0 still reports MISMATCH at two bytes.  The
//   later owner segment is an evidence boundary test, not an exact claim.
// BLOCKER: Owners after 0041EBF0 use incompatible local RGE_Base_Game
//   declarations. Including them all would require unsupported ABI substitution
//   or broad source edits. Keep the registered prefix and config unchanged until
//   a canonical shared basegame declaration is proved.
// ACCEPTED DRIFT: The only two differing bytes swap the source displacements
//   of two adjacent MOV instructions. The original loads timings[10] into EAX
//   and timings[12] into EDX. The rebuild reverses those two loads. Both loads
//   precede the same unsigned ADD. EDX is then cleared before DIV. No call,
//   write, branch, or observable operation occurs between the loads and ADD.
//   Thus, the sum, divisor, quotient, calls, writes, predicates, and faults are
//   equal for the valid nonvolatile RGE_Base_Game object required by the ABI.
// BINARY NOTE: The executable reloads include_in_total after the first timer
//   probe and performs the 8-byte cleanup after that reload.
// LIKELY INTENT: The timer record is a typed 0x20-byte array.  The remaining
//   difference is compiler scheduling or original translation-unit context.
unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern int do_fps_log;
extern FILE* fps_log;
extern unsigned long start_mem_total;
extern unsigned long start_mem_high;
extern unsigned long cur_mem_total;
extern unsigned long cur_mem_high;


class RGE_Player;





void RGE_Base_Game::calc_timings()
{
    unsigned long total_time = 0;
    for (int i = 0; i < 30; ++i) {
        if (this->timings[i].is_summary == 0) {
            this->timings[i].last_time = this->timings[i].accum_time;
            this->timings[i].last_max_time = this->timings[i].max_time;
            this->timings[i].accum_time = 0;
            this->timings[i].max_time = 0;
            this->timings[i].start_time = debug_timeGetTime(
                (char*)0x57FB08, 0x12B5);

            if (this->timings[i].include_in_total != 0)
                total_time += this->timings[i].last_time;
        }
    }

    if (this->timings[0].start_time > 0) {
        this->timings[0].last_time = debug_timeGetTime(
            (char*)0x57FB08, 0x12BE) - this->timings[0].start_time;
    } else {
        this->timings[0].last_time = total_time;
    }

    this->timings[0].start_time = debug_timeGetTime(
        (char*)0x57FB08, 0x12C1);

    if (this->timings[0].last_time > total_time)
        this->timings[4].last_time =
            this->timings[0].last_time - total_time;
    else
        this->timings[4].last_time = 0;

    if (this->timings[2].last_time >
        this->timings[6].last_time + this->timings[7].last_time)
        this->timings[9].last_time =
            this->timings[2].last_time - this->timings[6].last_time -
            this->timings[7].last_time;
    else
        this->timings[9].last_time = 0;

    unsigned long total = this->timings[0].last_time;
    if (total == 0 || this->frame_count == 0 ||
        total / this->frame_count == 0) {
        this->fps = 1000;
    } else {
        this->fps = 1000 / (total / this->frame_count);
    }

    if (total == 0 || this->view_update_count == 0 ||
        total / this->view_update_count == 0) {
        this->view_update_fps = 0;
    } else {
        this->view_update_fps =
            1000 / (total / this->view_update_count);
    }

    if (total == 0 || this->world_update_count == 0 ||
        total / this->world_update_count == 0) {
        this->world_update_fps = 0;
    } else {
        this->world_update_fps =
            1000 / (total / this->world_update_count);
    }

    this->calc_timing_text();

    if (do_fps_log != 0 && this->prog_mode == 4) {
        int object_count = 0;
        int sleeping_object_count = 0;
        int player_count = this->world->player_num;

        if (player_count > 1) {
            RGE_Player** players = this->world->players;
            ++players;
            --player_count;
            do {
                RGE_Player* player = *players;
                ++players;
                object_count += player->objects->number_of_objects;
                sleeping_object_count +=
                    player->sleeping_objects->number_of_objects;
                --player_count;
            } while (player_count != 0);
        }

        fprintf(
            fps_log,
            (const char*)0x580284,
            this->world->world_time,
            start_mem_total,
            start_mem_high,
            cur_mem_total,
            cur_mem_high,
            (*this->world->players)->objects->number_of_objects,
            (*this->world->players)->sleeping_objects->number_of_objects,
            object_count,
            sleeping_object_count,
            this->world_update_count,
            this->view_update_count,
            this->world_update_fps,
            this->view_update_fps,
            this->world_update_count == 0
                ? 0 : this->timings[6].last_time / this->world_update_count,
            this->timings[6].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[7].last_time / this->world_update_count,
            this->timings[7].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[3].last_time / this->world_update_count,
            this->timings[3].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[1].last_time / this->world_update_count,
            this->timings[1].last_max_time,
            this->world_update_count == 0
                ? 0 : (this->timings[10].last_time +
                       this->timings[12].last_time) /
                      this->world_update_count,
            this->timings[10].last_max_time +
                this->timings[12].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[13].last_time / this->world_update_count,
            this->timings[13].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[4].last_time / this->world_update_count,
            this->timings[4].last_max_time,
            0,
            -1,
            -1);
        fflush(fps_log);
    }

    this->last_frame_count = this->frame_count;
    this->last_world_update_count = this->world_update_count;
    this->last_view_update_count = this->view_update_count;
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
}


// PDB ownership: matching/00421FA0_calc_timing_text.cpp
extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);

void RGE_Base_Game::calc_timing_text()
{
    unsigned long divisor = this->frame_count;
    if (divisor == 0)
        divisor = 1;

    sprintf(this->timing_text,
        "fps=%lu, rend=%lu, view=%lu, map=%lu, scr=%lu, draw=%lu, prog=%lu, ui=%lu, sfx=%lu, misc=%lu",
        this->fps,
        this->world_update_count / divisor,
        this->view_update_count / divisor,
        this->timings[0].last_time / divisor,
        this->timings[0].accum_time / divisor,
        this->timings[0].start_time / divisor,
        this->timings[1].last_time / divisor,
        this->timings[1].accum_time / divisor,
        this->timings[1].start_time / divisor,
        this->timings[0].last_single_time / divisor);
}


// PDB ownership: matching/00422030_show_timings.cpp
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void* hWnd, const char* lpString);

void RGE_Base_Game::show_timings()
{
    SetWindowTextA(this->prog_window, this->timing_text);
}


// PDB ownership: matching/00422050_show_comm.cpp
extern "C" int sprintf(char*, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void*, const char*);

void RGE_Base_Game::show_comm(void) {
    char str[256];
    sprintf(str, "%s", this->comm_handler->GetCommInfo(1));
    SetWindowTextA(this->prog_window, str);
}


// PDB ownership: matching/00422090_show_ai.cpp
extern "C" int sprintf(char*, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void*, const char*);

void RGE_Base_Game::show_ai(void) {
    char str[256];
    sprintf(str, "No AI Information for Player #%d.",
            (int)this->world->curr_player);
    SetWindowTextA(this->prog_window, str);
}


// PDB ownership: matching/004220D0_send_game_options.cpp
void RGE_Base_Game::send_game_options()
{
    if (this->comm_handler)
        this->comm_handler->SetMyGameOptions((char*)&this->rge_game_options, 0xA8);
}


// PDB ownership: matching/004220F0_receive_game_options.cpp
void RGE_Base_Game::receive_game_options(void)
{
    if (this->comm_handler != 0) {
        unsigned long size = 0;
        void* options = this->comm_handler->GetMyGameOptions(&size);
        if (options != 0 && size == 0xA8)
            this->set_game_options((RGE_Game_Options*)options);
    }
}


// PDB ownership: matching/00422130_set_game_options.cpp
// VA: 00422130 RGE_Base_Game::set_game_options (297 B)
// PDB source: basegame.cpp
// Packet-grounded: write all game options from RGE_Game_Options struct
// Attempt log:
// - Replaced the initial cdecl self shims with the canonical member-setter
//   ABI and nested RGE_Game_Options layout; size/calls/CFG became exact.
// - Reversed subscripts, pointer-add/raw-byte offset forms, nested-type and
//   destructor context, loop declaration/register variants, and a focused
//   variant lab all emitted the same 2-byte SIB drift: rebuilt [edi+esi+92/9C]
//   versus original [esi+edi+92/9C].
// - Left the natural typed reconstruction in scratch; only the address-term
//   encoding remains unresolved.
// - Rechecked the ground-truth three-byte tail pad against the paired getter;
//   it is a codegen duplicate, so the natural nested record remains canonical.
// - Main-agent audit retained the shared named option record and ordinary
//   indexed loop; no address-expression steering survives.
// - New worker probes: do/while lowering, integer-address-sum spelling,
//   signed-byte fields with explicit casts, an inline array wrapper, and an
//   index-first pointer-cast address all remained the same 2-byte SIB group.
//   Array references added a 21-byte frame/CFG drift; a non-inlined helper
//   added two calls; both were restored. The vc5-small flag family (12
//   variants, including /GX, /Ow, /Oi, /Og, /Ot, /Ob0 combinations) also
//   collapsed to one 2-byte group. The residual is therefore a backend
//   address-term encoding basin, not a supported ownership/type lead.
// - Restoring the period <string.h> include used by the exact paired getter
//   donor changed only the two loop SIB bytes and reached an exact match.
void RGE_Base_Game::set_game_options(RGE_Game_Options* opt)
{
    int i;

    this->setVersion(opt->versionValue);
    this->setScenarioGame(opt->scenarioGameValue);
    this->setScenarioName(opt->scenarioNameValue);
    this->setSinglePlayerGame(opt->singlePlayerGameValue);
    this->setMultiplayerGame(opt->multiplayerGameValue);
    this->setMapSize(opt->mapXSizeValue, opt->mapYSizeValue,
                     opt->mapZSizeValue);
    this->setAllowCheatCodes(opt->allowCheatCodesValue);
    this->setCheatNotification(opt->cheatNotificationValue);
    this->setFullVisibility(opt->fullVisibilityValue);
    this->setFogOfWar(opt->fogOfWarValue);
    this->setColoredChat(opt->coloredChatValue);
    this->setNumberPlayers(opt->numberPlayersValue);
    this->setGameDeveloperMode(opt->gameDeveloperModeValue);
    this->setDifficulty(opt->difficultyValue);
    this->setMpPathFinding(opt->mpPathFindingValue);

    for (i = 0; i < 9; i++) {
        this->setPlayerCDAndVersion(i, opt->playerCDAndVersionValue[i]);
        this->setPlayerTeam(i, opt->playerTeamValue[i]);
    }
}


// PDB ownership: matching/00422260_get_game_options.cpp
// VA: 00422260 RGE_Base_Game::get_game_options (296 B)
// PDB source: basegame.cpp:5032-5059
//
// Attempt log:
// - The prior packet scaffold used free helper shims, raw option offsets, and a
//   hand-written name loop; it did not model the nested option record or the
//   original member-call ABI.
// - Baseline reconstruction: use the PDB-sized nested RGE_Game_Options record,
//   typed RGE_Base_Game member calls, natural field assignments, strcpy for the
//   scenario name, and one indexed player loop. The source order follows the
//   original basegame.cpp line bands, including mpPathFinding after difficulty.
// - Reversed subscripts, pointer-add/raw-byte offset forms, index-first address
//   arithmetic, per-array pointer locals, do/while and register-index variants
//   did not change the two-byte SIB drift; a six-case focused lab likewise put
//   all variants in the same codegen group.
// - Best clean result: exact size/frame/CFG and all 19 ordered calls, with only
//   the two loop stores encoded as [ebp+esi+92/9C] instead of the original
//   [esi+ebp+92/9C]. The paired set_game_options reconstruction reports the same
//   compiler SIB artifact, so retain the named-field source rather than raw
//   address or volatile steering.
// - Rechecked the ground-truth three-byte tail pad and struct spelling against
//   the paired setter surface; both were codegen duplicates, leaving the SIB
//   operand order as the only blocker.
// - Restoring the period <string.h> context instead of a hand-declared strcpy
//   surface flips both loop-store SIB encodings and reaches an exact match;
//   the typed option record and ordinary indexed loop remain unchanged.
// - Main-agent audit retained the shared named option record used by the paired
//   setter; no address-expression steering survives.
void RGE_Base_Game::get_game_options(RGE_Game_Options* options)
{
    options->versionValue = this->version();
    options->scenarioGameValue = (unsigned char)this->scenarioGame();
    strcpy(options->scenarioNameValue, this->scenarioName());

    options->singlePlayerGameValue = (unsigned char)this->singlePlayerGame();
    options->multiplayerGameValue = (unsigned char)this->multiplayerGame();
    options->mapXSizeValue = (unsigned char)this->mapXSize();
    options->mapYSizeValue = (unsigned char)this->mapYSize();
    options->mapZSizeValue = (unsigned char)this->mapZSize();
    options->allowCheatCodesValue = (unsigned char)this->allowCheatCodes();
    options->cheatNotificationValue = (unsigned char)this->cheatNotification();
    options->fullVisibilityValue = (unsigned char)this->fullVisibility();
    options->fogOfWarValue = (unsigned char)this->fogOfWar();
    options->coloredChatValue = (unsigned char)this->coloredChat();
    options->numberPlayersValue = (unsigned char)this->numberPlayers();
    options->gameDeveloperModeValue = (unsigned char)this->gameDeveloperMode();
    options->difficultyValue = (unsigned char)this->difficulty();
    options->mpPathFindingValue = this->mpPathFinding();

    for (int i = 0; i < 9; i++) {
        options->playerCDAndVersionValue[i] = this->playerCDAndVersion(i);
        options->playerTeamValue[i] = (unsigned char)this->playerTeam(i);
    }
}


// PDB ownership: matching/00422390_version.cpp


float RGE_Base_Game::version() const {
    return this->rge_game_options.versionValue;
}


// PDB ownership: matching/004223a0_scenarioGame.cpp
int RGE_Base_Game::scenarioGame() const {
    return this->rge_game_options.scenarioGameValue;
}


// PDB ownership: matching/004223b0_randomGame.cpp


int RGE_Base_Game::randomGame() const {
    return !this->rge_game_options.scenarioGameValue;
}


// PDB ownership: matching/004223c0_campaignGame.cpp


int RGE_Base_Game::campaignGame() const {
    return this->campaignGameValue;
}


// PDB ownership: matching/004223d0_savedGame.cpp


int RGE_Base_Game::savedGame() const {
    return this->savedGameValue;
}


// PDB ownership: matching/004223e0_scenarioName.cpp


char* RGE_Base_Game::scenarioName() {
    return this->rge_game_options.scenarioNameValue;
}


// PDB ownership: matching/004223f0_singlePlayerGame.cpp
int RGE_Base_Game::singlePlayerGame() const {
    return this->rge_game_options.singlePlayerGameValue;
}


// PDB ownership: matching/00422400_multiplayerGame.cpp
int RGE_Base_Game::multiplayerGame() const {
    return this->rge_game_options.multiplayerGameValue;
}


// PDB ownership: matching/00422410_mapXSize.cpp


int RGE_Base_Game::mapXSize() const {
    return this->rge_game_options.mapXSizeValue;
}


// PDB ownership: matching/00422420_mapYSize.cpp


int RGE_Base_Game::mapYSize() const {
    return this->rge_game_options.mapYSizeValue;
}


// PDB ownership: matching/00422430_mapZSize.cpp


int RGE_Base_Game::mapZSize() const {
    return this->rge_game_options.mapZSizeValue;
}


// PDB ownership: matching/00422440_allowCheatCodes.cpp


int RGE_Base_Game::allowCheatCodes() const {
    return this->rge_game_options.allowCheatCodesValue;
}


// PDB ownership: matching/00422450_cheatNotification.cpp


int RGE_Base_Game::cheatNotification() const {
    return this->rge_game_options.cheatNotificationValue;
}


// PDB ownership: matching/00422460_fullVisibility.cpp


int RGE_Base_Game::fullVisibility() const {
    return this->rge_game_options.fullVisibilityValue;
}


// PDB ownership: matching/00422470_fogOfWar.cpp


int RGE_Base_Game::fogOfWar() const {
    return this->rge_game_options.fogOfWarValue;
}


// PDB ownership: matching/00422480_coloredChat.cpp


int RGE_Base_Game::coloredChat() const {
    return this->rge_game_options.coloredChatValue;
}


// PDB ownership: matching/00422490_gameDeveloperMode.cpp


int RGE_Base_Game::gameDeveloperMode() const {
    return this->rge_game_options.gameDeveloperModeValue;
}


// PDB ownership: matching/004224A0_playerHasCD.cpp
int RGE_Base_Game::playerHasCD(int i) {
    return this->rge_game_options.playerCDAndVersionValue[i] & 1;
}


// PDB ownership: matching/004224C0_playerVersion.cpp
unsigned char RGE_Base_Game::playerVersion(int i) {
    return this->rge_game_options.playerCDAndVersionValue[i] >> 1;
}


// PDB ownership: matching/004224E0_playerVersionString.cpp
// VA: 004224E0 RGE_Base_Game::playerVersionString (231 B)
// PDB source: basegame.cpp
// PDB line span: 5200-5230


char* RGE_Base_Game::playerVersionString(int param)
{
    unsigned char v = playerVersion(param);

    switch (v) {
        case 0:   return "";
        case 1:   return "1.0";
        case 2:   return "1.0a";
        case 3:   return "1.0b";
        case 4:   return "1.0c";
        case 5:   return "1.0d";
        case 6:   return "1.0e";
        case 7:   return "1.1";
        case 8:   return "1.1a";
        case 9:   return "1.1b";
        case 10:  return "1.1c";
        case 11:  return "1.2";
        case 12:  return "1.2a";
        case 13:  return "1.2b";
        case 14:  return "1.2c";
        case 15:  return "1.3";
        case 16:  return "1.3a";
        case 17:  return "1.3b";
        case 18:  return "1.3c";
        case 19:  return "1.4";
        case 20:  return "1.4a";
        case 21:  return "1.4b";
        case 22:  return "1.4c";
        default:  return "1.X";
    }
}


// PDB ownership: matching/00422630_playerCDAndVersion.cpp


unsigned char RGE_Base_Game::playerCDAndVersion(int idx) {
    return this->rge_game_options.playerCDAndVersionValue[idx];
}


// PDB ownership: matching/00422640_difficulty.cpp
int RGE_Base_Game::difficulty() {
    return this->rge_game_options.difficultyValue;
}


// PDB ownership: matching/00422650_numberPlayers.cpp
int RGE_Base_Game::numberPlayers() const {
    return this->rge_game_options.numberPlayersValue;
}


// PDB ownership: matching/00422660_playerTeam.cpp
int RGE_Base_Game::playerTeam(int player) {
    RGE_Game_Options* options = (RGE_Game_Options*)&this->rge_game_options;
    return options->playerTeamValue[player];
}


// PDB ownership: matching/00422670_pathFinding.cpp


unsigned char RGE_Base_Game::pathFinding() {
    return this->pathFindingValue;
}


// PDB ownership: matching/00422680_mpPathFinding.cpp


unsigned char RGE_Base_Game::mpPathFinding() {
    return this->rge_game_options.mpPathFindingValue;
}


// PDB ownership: matching/00422690_gameSummary.cpp
static char game_summary_buf;


char* RGE_Base_Game::gameSummary() {
    game_summary_buf = 0;
    return &game_summary_buf;
}


// PDB ownership: matching/004226A0_find_campaigns.cpp
struct Inner_004226A0 {
    void find_campaigns();
};


void RGE_Base_Game::find_campaigns() {
    this->player_game_info->find_campaigns();
}


// PDB ownership: matching/004226b0_setScenarioGame.cpp


void RGE_Base_Game::setScenarioGame(int v) {
    this->rge_game_options.scenarioGameValue = v;
}


// PDB ownership: matching/004226c0_setVersion.cpp


void RGE_Base_Game::setVersion(float v) {
    this->rge_game_options.versionValue = v;
}


// PDB ownership: matching/004226D0_setScenarioName.cpp
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

void RGE_Base_Game::setScenarioName(char* name) {
    strncpy(this->rge_game_options.scenarioNameValue, name, 0x80);
    *((unsigned char*)this + 0x97C) = 0;
}


// PDB ownership: matching/00422700_setCampaignGame.cpp


void RGE_Base_Game::setCampaignGame(int v) {
    this->campaignGameValue = v;
}


// PDB ownership: matching/00422710_setSavedGame.cpp


void RGE_Base_Game::setSavedGame(int v) {
    this->savedGameValue = v;
}


// PDB ownership: matching/00422720_setSinglePlayerGame.cpp
void RGE_Base_Game::setSinglePlayerGame(int v)
{
    this->rge_game_options.singlePlayerGameValue = (unsigned char)v;
    this->rge_game_options.multiplayerGameValue = (unsigned char)(v == 0);
}


// PDB ownership: matching/00422740_setMultiplayerGame.cpp
void RGE_Base_Game::setMultiplayerGame(int v)
{
    this->rge_game_options.multiplayerGameValue = (unsigned char)v;
    this->rge_game_options.singlePlayerGameValue = (unsigned char)(v == 0);
}


// PDB ownership: matching/00422760_setMapSize.cpp


void RGE_Base_Game::setMapSize(int a, int b, int c) {
    this->rge_game_options.mapXSizeValue = a;
    this->rge_game_options.mapYSizeValue = b;
    this->rge_game_options.mapZSizeValue = c;
}


// PDB ownership: matching/00422790_setAllowCheatCodes.cpp


void RGE_Base_Game::setAllowCheatCodes(int v) {
    this->rge_game_options.allowCheatCodesValue = v;
}


// PDB ownership: matching/004227a0_setCheatNotification.cpp


void RGE_Base_Game::setCheatNotification(int v) {
    this->rge_game_options.cheatNotificationValue = v;
}


// PDB ownership: matching/004227b0_setFullVisibility.cpp


void RGE_Base_Game::setFullVisibility(int v) {
    this->rge_game_options.fullVisibilityValue = v;
}


// PDB ownership: matching/004227c0_setFogOfWar.cpp


void RGE_Base_Game::setFogOfWar(int v) {
    this->rge_game_options.fogOfWarValue = v;
}


// PDB ownership: matching/004227d0_setColoredChat.cpp


void RGE_Base_Game::setColoredChat(int v) {
    this->rge_game_options.coloredChatValue = v;
}


// PDB ownership: matching/004227e0_setNumberPlayers.cpp


void RGE_Base_Game::setNumberPlayers(int v) {
    this->rge_game_options.numberPlayersValue = v;
}


// PDB ownership: matching/004227f0_setGameDeveloperMode.cpp


void RGE_Base_Game::setGameDeveloperMode(int v) {
    this->rge_game_options.gameDeveloperModeValue = v;
}


// PDB ownership: matching/00422800_setPlayerHasCD.cpp
void RGE_Base_Game::setPlayerHasCD(int player, int hasCD) {
    unsigned char val = this->rge_game_options.playerCDAndVersionValue[player];
    val = (val & 0xFE) | hasCD;
    this->rge_game_options.playerCDAndVersionValue[player] = val;
}


// PDB ownership: matching/00422820_setPlayerVersion.cpp
void RGE_Base_Game::setPlayerVersion(int player, unsigned char version) {
    unsigned char v = version << 1;
    unsigned char old = this->rge_game_options.playerCDAndVersionValue[player];
    v = v | (old & 1);
    this->rge_game_options.playerCDAndVersionValue[player] = v;
}


// PDB ownership: matching/00422850_setPlayerCDAndVersion.cpp
void RGE_Base_Game::setPlayerCDAndVersion(int i, unsigned char v) {
    this->rge_game_options.playerCDAndVersionValue[i] = v;
}


// PDB ownership: matching/00422870_setDifficulty.cpp


void RGE_Base_Game::setDifficulty(int v) {
    this->rge_game_options.difficultyValue = v;
}


// PDB ownership: matching/00422880_setPlayerTeam.cpp
void RGE_Base_Game::setPlayerTeam(int i, int v) {
    RGE_Game_Options* options = (RGE_Game_Options*)&this->rge_game_options;
    options->playerTeamValue[i] = v;
}


// PDB ownership: matching/004228a0_setPathFinding.cpp


void RGE_Base_Game::setPathFinding(unsigned char v) {
    this->pathFindingValue = v;
}


// PDB ownership: matching/004228b0_setMpPathFinding.cpp


void RGE_Base_Game::setMpPathFinding(unsigned char v) {
    this->rge_game_options.mpPathFindingValue = v;
}


// PDB ownership: matching/004228C0_set_map_visible.cpp
void RGE_Base_Game::set_map_visible(unsigned char param)
{
    if (this->world)
        this->world->set_map_visible((unsigned char)param);
}


// PDB ownership: matching/004228E0_set_map_fog.cpp
void RGE_Base_Game::set_map_fog(unsigned char param)
{
    if (this->world)
        this->world->set_map_fog((unsigned char)param);
}


// PDB ownership: matching/00422900_turn_world_sound_off.cpp
void RGE_Base_Game::turn_world_sound_off() {
    this->world->turn_sound_off();
}


// PDB ownership: matching/00422910_campaign_open_scenario.cpp
int RGE_Base_Game::campaign_open_scenario() {
    return this->player_game_info->open_scenario();
}


// PDB ownership: matching/00422920_GetChecksum.cpp




long RGE_Base_Game::GetChecksum(long param_1) {
    RGE_Game_World* world = this->world;
    if (world != 0) {
        if (param_1 < 0) {
            return world->players[world->curr_player]->get_checksum();
        }
        if (param_1 < world->player_num) {
            return world->players[param_1]->get_checksum();
        }
    }
    return 0;
}


// PDB ownership: matching/00422960_GetWorldChecksums.cpp




struct GetWorldChecksums_Locals {
    long c1;
    long c2;
    long c3;
    RGE_Base_Game* self;
};

unsigned char RGE_Base_Game::GetWorldChecksums(long& checksum1, long& checksum2, long& checksum3)
{
    GetWorldChecksums_Locals locals;
    int i;
    RGE_Game_World* w;

    i = 0;
    locals.self = this;
    locals.c1 = 0;
    checksum1 = 0;
    checksum2 = 0;
    checksum3 = 0;
    w = world;
    locals.c2 = 0;
    locals.c3 = 0;
    if (w != 0) {
        if (w->player_num > 0) {
            do {
                w->players[i]->get_checksums(locals.c1, locals.c2, locals.c3);
                checksum1 += locals.c1;
                checksum2 += locals.c2;
                checksum3 += locals.c3;
                ++i;
                w = locals.self->world;
            } while (i < w->player_num);
        }
        return 1;
    }
    return 0;
}


// PDB ownership: matching/00422A10_GetWorldChecksum.cpp
// VA: 00422A10 GetWorldChecksum (64B)
// basegame.cpp - RGE_Base_Game member function




long RGE_Base_Game::GetWorldChecksum(void) {
    long sum;
    RGE_Game_World* world;

    sum = 0;
    world = this->world;
    if (world != 0) {
        int i = 0;
        if (world->player_num > 0) {
            do {
                sum += world->players[i]->get_checksum();
                world = this->world;
                i++;
            } while (i < world->player_num);
        }
        return sum;
    }
    return 0;
}


// PDB ownership: matching/00422A50_disable_input.cpp
extern TPanelSystem panel_system;


void RGE_Base_Game::disable_input() {
    if (this->is_mouse_on != 0) {
        void* cursor = LoadCursorA(0, (const char*)0x7F02);
        set_mouse_cursor(cursor);
    }
    panel_system.DisableInput();
    this->input_enabled = 0;
    if (this->input_disabled_window != 0) {
        if (GetCapture()) {
            ReleaseCapture();
        }
        SetCapture(this->input_disabled_window);
    }
}


// PDB ownership: matching/00422AB0_enable_input.cpp
// VA: 00422AB0 RGE_Base_Game::enable_input
// basegame.cpp lines 5645-5658
// MATCHED: mirror the nearby disable_input surface exactly.
// The working details were: extern "C" dllimport USER32 declarations, full mouse-related field layout through +0x1DC,
// and a named local for the LoadCursorA result before set_mouse_cursor.

extern TPanelSystem panel_system;


void RGE_Base_Game::enable_input() {
    if (this->input_disabled_window != 0) {
        if (GetCapture()) {
            ReleaseCapture();
        }
    }
    panel_system.EnableInput();
    this->input_enabled = 1;
    if (this->is_mouse_on != 0) {
        void* cursor = LoadCursorA(0, (const char*)0x7F00);
        set_mouse_cursor(cursor);
    }
}


// PDB ownership: matching/00422B10_set_screen_size.cpp
// VA: 00422B10 RGE_Base_Game::set_screen_size (430 B)
// PDB source: basegame.cpp lines 5664-5735
//
// Attempt log:
// - The packet scaffold used free-function shims, null guards, and the wrong
//   direct-call/import surfaces.  Replaced it with the period typed member and
//   Win32 API forms; the binary proves the draw-area, draw-system, window, and
//   mouse-pointer offsets used below.
// - Corrected the fallback guard and client-size correction from the packet
//   decompiler's window-size expression to the executable's client RECT logic.
// - Hand-declared Win32 imports left a four-byte late register/arithmetic drift;
//   the donor-era <windows.h> surface restores the VC5 optimizer basin exactly.
// - Added the high-confidence polymorphic RGE_Base_Game prefix and canonical
//   TDrawArea widths; both preserve the exact output and the proven offsets.
extern int restore_mouse_after_paint;


void RGE_Base_Game::set_screen_size(long width, long height)
{
    RECT win_rect;
    RECT client_rect;

    if (this->draw_area->Width != width || this->draw_area->Height != height) {
        if (this->draw_system->DrawType == 2 &&
            this->draw_system->ScreenMode == 2) {
            SetCursor(0);
            SetClassLongA(this->prog_window, -12, 0);
            this->mouse_pointer->Shutdown_Mouse();
            this->draw_system->SetDisplaySize(width, height, 8);
            this->draw_system->CheckSurfaces();
            this->draw_system->ClearRestored();
            this->set_render_all();
            restore_mouse_after_paint = 1;
            return;
        }

        int display_width = 0;
        int display_height = 0;
        void* dc = CreateICA("DISPLAY", 0, 0, 0);
        if (dc != 0) {
            display_width = GetDeviceCaps(dc, 8);
            display_height = GetDeviceCaps(dc, 10);
            DeleteDC(dc);
        }

        if (width <= display_width && height <= display_height) {
            if (display_width == width && display_height == height) {
                this->window_style = 0x92080000;
                SetWindowLongA(this->prog_window, -16, 0x92080000);
                SetWindowLongA(this->prog_window, -20, this->window_style);
            } else {
                this->window_style = 0x12CA0000;
                SetWindowLongA(this->prog_window, -20, 0x12CA0000);
                SetWindowLongA(this->prog_window, -16, this->window_style);
            }

            SetWindowPos(this->prog_window, 0, 0, 0, width, height, 0);
            GetWindowRect(this->prog_window, &win_rect);
            GetClientRect(this->prog_window, &client_rect);

            if (client_rect.right != width || client_rect.bottom != height) {
                SetWindowPos(this->prog_window, 0,
                    win_rect.left, win_rect.top,
                    width + win_rect.right - win_rect.left - client_rect.right,
                    height + win_rect.bottom - win_rect.top - client_rect.bottom,
                    0);
            }
        }
    }
}


// PDB ownership: matching/00422CC0_check_prog_argument.cpp
// VA: 00422CC0 check_prog_argument (87B)
// Fixed buffer layout: 256 bytes, use buffer[4] form

extern "C" __declspec(dllimport) char* __stdcall CharUpperA(char* lpString);
extern "C" char* __cdecl strstr(const char* str, const char* substr);
extern "C" char* __cdecl strncpy(char* dest, const char* src, unsigned int count);



unsigned char RGE_Base_Game::check_prog_argument(char* param_1) {
    char buffer[256];

    strncpy(buffer, this->prog_info->cmd_line, 0xFF);
    buffer[0xFF] = 0;
    CharUpperA(buffer);
    if (strstr(buffer, param_1) != 0) {
        return 1;
    }
    return 0;
}


// PDB ownership: scratch/00422D20_get_scenario_checksum.cpp
long RGE_Base_Game::get_scenario_checksum(char* scenario_name) {
    RGE_Scenario_Header* hdr = this->get_scenario_header(scenario_name, 0);
    if (!hdr) return 0;
    unsigned long checksum = hdr->checksum;
    delete hdr;
    return checksum;
}


// PDB ownership: matching/00422D60_check_scenario_checksum.cpp


unsigned char RGE_Base_Game::check_scenario_checksum(char* filename, long expected) {
    long cs = this->get_scenario_checksum(filename);
    if (cs != 0 && cs == expected) return 1;
    return 0;
}


// PDB ownership: matching/00422d80_dump_memory_usage.cpp


void RGE_Base_Game::dump_memory_usage(char*) {
}


// PDB ownership: matching/00422d90_playerID.cpp


int RGE_Base_Game::playerID(int idx) {
    return this->playerIDValue[idx];
}


// PDB ownership: matching/00422DA0_setPlayerID.cpp
void RGE_Base_Game::setPlayerID(int i, int v) {
    this->playerIDValue[i] = v;
}


// PDB ownership: matching/00422DC0_reset_countdown_timer.cpp
void RGE_Base_Game::reset_countdown_timer(long i) {
    this->countdown_timer[i] = -1;
}


// PDB ownership: matching/00422DE0_set_countdown_timer.cpp
void RGE_Base_Game::set_countdown_timer(long index, long value) {
    long current = this->countdown_timer[index];
    if (current > value || current < 0) {
        this->countdown_timer[index] = value;
    }
}


// PDB ownership: matching/00422E10_get_countdown_timer.cpp


void RGE_Base_Game::get_countdown_timer(long index, long& output)
{
    output = this->countdown_timer[index];
}


// PDB ownership: matching/00422e30_play_video.cpp


int RGE_Base_Game::play_video(char*) {
    return 0;
}


// PDB ownership: matching/00422e40_close_video.cpp
// close_video (00422E40) - RGE_Base_Game::close_video
// Empty member function - just ret


void RGE_Base_Game::close_video(void)
{
}


// PDB ownership: matching/00422e50_handle_video_notify.cpp
// handle_video_notify (00422E50) - RGE_Base_Game::handle_video_notify
// Empty member function - just ret


void RGE_Base_Game::handle_video_notify(void)
{
}


// PDB ownership: matching/00422E60_play_sound.cpp



int RGE_Base_Game::play_sound(int param_1)
{
    if (this->sounds == 0)
        return 0;

    if (this->sounds[param_1] == 0)
        return 0;

    if (this->sounds[param_1]->is_playing() != 0)
        return 1;

    return this->sounds[param_1]->play();
}


// PDB ownership: matching/00422eb0_get_game_speed.cpp


float RGE_Base_Game::get_game_speed() {
    return this->game_speed;
}


// PDB ownership: matching/00422ec0_set_game_speed.cpp


void RGE_Base_Game::set_game_speed(float v) {
    this->game_speed = v;
}


// PDB ownership: matching/00422ed0_get_single_player_difficulty.cpp


int RGE_Base_Game::get_single_player_difficulty() {
    return this->single_player_difficulty;
}


// PDB ownership: matching/00422ee0_set_single_player_difficulty.cpp


void RGE_Base_Game::set_single_player_difficulty(int v) {
    this->single_player_difficulty = v;
}


// PDB ownership: matching/00422EF0_setup_map_save_area.cpp
// VA: 00422EF0 RGE_Base_Game::setup_map_save_area (214 B)
// PDB source: basegame.cpp, lines 6128-6139
// Attempt log:
// - Replaced the prior free-function/shim lift with the natural TDrawArea
//   new-expression, member calls, and ordinary typed delete cleanup. The
//   binary-proven 0x100 size includes TDrawArea's vptr. Exact match.
class TDrawSystem;



int RGE_Base_Game::setup_map_save_area()
{
    TDrawArea* area = new TDrawArea("Diamond Map Save Area", 0);
    this->map_save_area = area;

    if (area == 0) {
        return 0;
    }

    if (area->Init(this->draw_system, 0x118, 0x8C, 0, 0) == 0) {
        TDrawArea* to_delete = this->map_save_area;
        if (to_delete != 0) {
            delete to_delete;
        }
        this->map_save_area = 0;
        return 0;
    }

    return 1;
}


// PDB ownership: matching/00422FD0_reload_scenarios_info.cpp
void RGE_Base_Game::reload_scenarios_info() {
    this->scenario_info->reload_scenarios();
}


// PDB ownership: matching/00422fe0_set_interface_messages.cpp
// set_interface_messages (00422FE0) - RGE_Base_Game::set_interface_messages
// Empty member function - just ret


void RGE_Base_Game::set_interface_messages(void)
{
}


// PDB ownership: scratch/00422FF0_set_render_all.cpp
struct GlobalRenderObj {
    void invalidate_all();
};

extern GlobalRenderObj g_render_obj;


void RGE_Base_Game::set_render_all()
{
    this->render_all = 1;
    g_render_obj.invalidate_all();
}


// PDB ownership: matching/00423010_debug_random_reset.cpp
extern char debug_random_log[0x19][0x64];
extern int debug_random_index;

void __cdecl debug_random_reset() {
    char (*entry)[0x64];

    entry = debug_random_log;
    do {
        (*entry)[0] = 0;
        entry = entry + 1;
    } while ((int)entry < (int)&debug_random_log[0x19]);
    debug_random_index = -1;
}


// PDB ownership: matching/00423030_debug_random_write.cpp
// first pass: open the debug random log, walk the fixed 0x64 stride block, then mark the write complete
// the only real shape here is the file-open guard plus the pointer/index loop and final flag store
extern int debug_random_index;
extern int wrote_debug_random_log;

void debug_random_write(void) {
    FILE* file;
    int index;
    long ptr;
    const char* marker;

    file = fopen("c:\\aoerand.txt", "w");
    if (file == 0) {
        return;
    }

    index = 0;
    ptr = 0x5B2378;
    while (ptr < 0x62C498) {
        if (index == debug_random_index) {
            marker = ">";
        }
        else {
            marker = " ";
        }
        fprintf(file, "%s%d - %s\n", marker, index, (char*)ptr);
        ptr += 0x64;
        index++;
    }

    fclose(file);
    wrote_debug_random_log = 1;
}


// PDB ownership: matching/004230A0_debug_rand.cpp
// VA: 004230A0
// PDB source: basegame.cpp
// debug_rand (__cdecl)
extern int do_debug_random;
extern int debug_random_on;
extern int debug_random_index;
extern char debug_random_log[25][100];

int __cdecl debug_rand(char* param_1, int param_2)
{
    int rv = rand();
    if (do_debug_random && debug_random_on) {
        char temp_name[9];
        param_1 += 10;
        char* dst = temp_name;
        char* end = param_1 + 8;
        char c = *param_1;
        while (c != '.' && param_1 < end) {
            *dst = c;
            c = param_1[1];
            ++dst;
            ++param_1;
        }
        int idx = debug_random_index;
        *dst = 0;
        if (idx < 4999)
            ++idx;
        else
            idx = 0;
        debug_random_index = idx;
        sprintf(&debug_random_log[0][0] + idx * 100, (char*)0x580478,
                rge_base_game->world->world_time, temp_name, param_2, rv);
    }
    return rv;
}


// PDB ownership: matching/00423140_debug_srand.cpp
// 00423140 debug_srand
// basegame.cpp:6231-6257, 158 bytes
// Retry 2026-05-19 Boss pass:
// - Implemented from packet/Ghidra. 10 variants tried: nested vs && debug gates, several filename-copy loops (do/while, while, goto, for bounded), idx*100 address spelling, seed local, record-array surface, and goto done.
// - Best variant is bounded for-loop copy: exact size 158, MISMATCH 34.8101% positional / 34.1772% edit, first mismatch 27.
// - Original shares the same hand-shaped copy/index/sprintf family as debug_rand; rebuilt still uses different loop topology/registers and sprintf argument scheduling. No accepted_drift: broad control-flow/register/scheduling differences, not localized.
// Retry 2026-05-20: MATCH. Mutating param_1 in place (`param_1 += 10`) plus `char buf[9]` with `d = buf` recovered the exact copy-loop and stack LEA. Removing the game/world local and using the direct nested expression inside sprintf preserved right-to-left vararg scheduling (push seed/line before loading rge_base_game) and matched exactly.
extern int do_debug_random;
extern int debug_random_on;
extern int debug_random_index;
extern char debug_random_log[25][100];



void __cdecl debug_srand(char* param_1, int param_2, unsigned int param_3)
{
    if (do_debug_random && debug_random_on) {
        char buf[9]; param_1 += 10; char* d = buf; char* end = param_1 + 8; char c = *param_1;
        while (c != '.' && param_1 < end) { *d = c; c = param_1[1]; d++; param_1++; }
        *d = 0;
        int idx = debug_random_index;
        if (idx < 4999) idx++; else idx = 0;
        debug_random_index = idx;
        sprintf(&debug_random_log[0][0] + idx * 100, "t%d,%s,l%d,s%u", rge_base_game->world->world_time, buf, param_2, param_3);
    }
    srand(param_3);
}


// PDB ownership: matching/004231E0_debug_timeGetTime.cpp
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);

extern int do_debug_timeGetTime;
extern int debug_timeGetTime_on;
extern int debug_timeGetTime_cnt;
extern int debug_timeGetTime_interval;
extern int debug_timeGetTime_time;

unsigned long __cdecl debug_timeGetTime(char* param_1, int param_2) {
    if (do_debug_timeGetTime != 0 && debug_timeGetTime_on != 0) {
        debug_timeGetTime_cnt = debug_timeGetTime_cnt + 1;
        if (debug_timeGetTime_cnt == debug_timeGetTime_interval) {
            debug_timeGetTime_cnt = 0;
            debug_timeGetTime_time = debug_timeGetTime_time + 1;
        }
        return debug_timeGetTime_time;
    }
    return timeGetTime();
}
