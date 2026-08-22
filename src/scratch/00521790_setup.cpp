// VA: 00521790 TRIBE_Game::setup (2061 B)
// PDB source: tribegam.cpp
// EH-framed (FS:[0] prolog). TRIBE_Game::setup - main game setup/init.
//
// Attempt log (owner dsb1-00521790):
//   baseline: first canonical reconstruction from packet/Ghidra decomp + asm.
//     Result MISMATCH frame 0xB20/0x90C code 1858/2061, edit-diff 64%.
//     Early makeres/RESFILE/cmd-line/palette blocks already structurally aligned.
//   probe layout: fixed class layout so field_40 reads +0x40 (was +0x20), comm
//     at +0x18C, lobby_hwnd +0x1DC, startup_scenario +0xC58/game +0xD5C; moved
//     vslot80 to vtable index 80 (offset 0x140) via VPAD64+8+4+2+1 (was landing
//     at +0xC4). cmd_line used as base for CharUpperA/_mbsstr (not +4).
//     Frame dropped 0xB20->0x720 (too small), code 1953/2061, call-gap 0.
//   probe layout2: version logging reuses cmd_line+0xF4/+0xFC and str[0x400]
//     like the original (program=/data=/options= into cmd_line/str buffers).
//     Done-block call sequence now matches (8-arg sprintf, FileTimeToSystemTime
//     SYSTEMTIME masking, run_log/FindClose). 55/70 calls aligned, gap 0.
//   Remaining gap: rebuilt frame 0x720 vs original 0x90C (VC5 packs tighter;
//     original reserves ~0x1EC more local area), code -108 bytes (register/
//     branch-width drift), positional diff dominated by frame-offset shift.
//   Next lead: force the 0x90C local layout by matching original decl order
//     (ici, str[1024], cmd_line, file_data, new_string_dll_name[100],
//     pal_entries, file_time SYSTEMTIME always-live) and reordering the
//     version-logging st/sprintf blocks; then re-tune the tail. Structural
//     shape is sound; exactness needs local-layout replication.
//
// Current worker (sa-c26d31f1-r1-00521790):
//   ABI/layout baseline: corrected ICINFO to the SDK 0x238-byte object,
//     WIN32_FIND_DATAA to 0x140 bytes, screen allocation sizes/field_D8
//     offsets, and direct prog_info ownership. Frame became exact 0x90C.
//   behavior probe: recovered the binary-supported command-line overlap
//     (copy/uppercase/search at cmd_line+4, terminator at str[3]) and the
//     shared str+4 reporting buffer for program/data/options records.
//   layout/control-flow probes: declaration and label-order variants were
//     codegen duplicates; the source retains the readable binary-supported
//     lobby/normal CFG with a shared logging tail and MP setup tail.
//   SYSTEMTIME probe: a single natural memset per FileTime block preserves
//     the observed full zero initialization better than aggregate init.
//   import-context probe: explicit const stdcall KERNEL32 thunk declarations
//     recover the repeated indirect import surface and reduce strict drift;
//     remaining mismatch is broad CFG/import/register scheduling, not an ABI
//     or object-size guess. Budget exhausted; leave in scratch.
//
// Worker sa-dcf94338-r1 (2026-08-06):
//   decl-order: PDB line 510/511 proves _mbsstr BEFORE the languagex.dll
//     copy; declaring new_string_dll_name AFTER the call recovers the
//     original deferred `add esp,8` and the edx-saved mbsstr result
//     (size -34->-29, shape 63.0->66.8, edit-diff 131.7%->35.6%).
//   behavior: both version sprintf blocks pass st.wMonth TWICE and use
//     time=%d:%d:%d (3 components); binary shows push eax;push eax for the
//     date group. Rebuilt arg-push pattern now matches the original.
//   layout negative evidence: the ORIGINAL emits lobby-path -> main-error ->
//     done -> epilogue -> close -> normal_start (done right after the lobby
//     main-error tail, epilogue near the end, ret0 last). Rebuilt emits
//     lobby -> main-error -> close -> normal_start -> mp_setup -> checks ->
//     done with ret0+epilogue early. Tried brace/if-else/else-goto/goto
//     (`if (LOBBY==0) goto normal_start` inverts to ns-inline/lobby-cold),
//     mp_setup-inside-if-body, function-level cmd, else-close, thunk-pointer
//     forms, volatile guard, guard local, and label-order moves: ALL are
//     codegen-identical except the goto form (wrong order). The done-block
//     placement is a front-end block-creation-order behavior: the original
//     created the done block at the first `goto done` (lobby main-error arm,
//     line 577) BEFORE close/normal_start; my PDB-faithful source creates it
//     at the label (front-end does not relocate forward goto targets here).
//   Remaining gap: -47 bytes / 88.9% positional, dominated by done-block
//     placement (+0x271 block delta) and its knock-on register allocation
//     (rebuilt keeps a function-wide ebx=0 zero register and ebp=-1; the
//     original uses ebp=1 and lobby-local edi=-1, with the FindFirstFileA/
//     FindClose/FileTimeToSystemTime thunk caching in ebx/ebp of the done
//     block). All 15 call-site gaps are the done block shifted by the
//     layout. Frame exact 0x90C, saved regs exact, calls 55/70 aligned.
//   Next lead: reproduce the front-end's goto-site block creation for the
//     done label (only the original source text can trigger it), or find
//     the TU-context difference (real TRIBE_Game vtable at slot 0x60 vs the
//     local VPAD view) that changes the block list.
//
// Worker sa-c21c4e7d-r1 (2026-08-06 canonical retry):
//   restored the clean checkpoint and replaced the VPAD/manual-vtable view
//     with the generated high-confidence RGE_Base_Game -> TRIBE_Game virtual
//     sequence and named generated field layouts.  No VPAD macros or manual
//     slot placeholders remain in this source.
//   context: real dllimport declarations for FindFirstFileA,
//     FileTimeToSystemTime, and FindClose cache the latter thunk in the
//     original-looking EBP surface; this moved the clean-source result
//     1833 -> 1830 bytes and recovered exact import-side blocks.
//   control-flow: label/goto placement and declaration-order variants were
//     duplicates.  A nested scenario/game/start-menu tree matching the
//     executable's decision structure moved the result to 1635 bytes,
//     74.51% shape, 56/70 ordered calls, and code size 2005/2061; restoring
//     typed HANDLE and separate launch-result locals preserved that output.
//   final state: canonical typed source remains in scratch; frame is exact
//     0x90C, but structural/call ordering and the prologue zero-register
//     choice still prevent exact promotion.  Next lead is the original TU's
//     front-end block formation / remaining import-register scheduling, not
//     another VPAD or raw-offset experiment.

// Worker shardC5-521790 (2026-08-13):
//   control-flow: changed the three natural integer-result zero tests to
//     truthiness because the original repeats test eax,eax at startup exits.
//     VC5 emitted an exact codegen duplicate (diff 1635, 80% ordered calls).
//     Restored the canonical explicit comparisons; no first-hunk movement.
//
// Worker sa-b781fbc9 (2026-08-17):
//   Ran 20 new evidence-led probes.  The clean source stayed at 1635 strict
//   differing bytes, 74.51% shape, 56/70 ordered calls, and a 0x90C frame.
//   Declaration scope, guard polarity, split allocation checks, lobby and MP
//   block forms, CRT linkage, header context, local types, and one unused
//   external declaration did not improve the clean result.  Some branch forms
//   reduced size or improved shape while worsening call order; they were
//   restored.  No exact result.  Next lead remains VC5 front-end block
//   formation for the lobby done/close/normal-start order and zero-register
//   allocation, not another local type or raw-offset change.

// Worker sa-340126dc-r1 (2026-08-22):
//   Read the full source, lessons, dossier, original assembly, and prior
//   history.  The clean source remains 1635 differing bytes, 74.51% shape,
//   56/70 ordered calls, and a 0x90C frame.
//   Tested an entry error local, positive and explicit-else entry guards,
//   function-scope SYSTEMTIME, split screen guards, field-value locals, a
//   lobby switch, natural command truth tests, and Ghidra-shaped inline
//   normal/lobby CFG variants.  The clean source was restored after each.
//   The entry-local, SYSTEMTIME, explicit-else, and truth-test forms were
//   codegen duplicates.  Split guards, field locals, switch, and inline CFG
//   forms were worse or changed call order.  No exact result or accepted drift
//   residue was proved.  The first structural mismatch remains the VC5
//   zero-register entry compare; the main gap remains done/close/normal-start
//   block formation and ordered call placement.

#include <string.h>

typedef void* HWND;
typedef void* HANDLE;

struct PALETTEENTRY { unsigned char peRed, peGreen, peBlue, peFlags; };
// Video-for-Windows ICINFO is the full 0x238-byte structure.  The setup
// routine passes its address to ICInfo and the original stack frame reserves
// the complete SDK object, not a short opaque placeholder.
struct ICINFO {
    unsigned long dwSize;
    unsigned long fccType;
    unsigned long fccHandler;
    unsigned long dwFlags;
    unsigned long dwVersion;
    unsigned long dwVersionICM;
    unsigned short szName[16];
    unsigned short szDescription[128];
    unsigned short szDriver[128];
};
struct FILETIME { unsigned long dwLowDateTime, dwHighDateTime; };
struct SYSTEMTIME {
    unsigned short wYear, wMonth, wDayOfWeek, wDay, wHour, wMinute, wSecond, wMilliseconds;
};
struct WIN32_FIND_DATAA {
    unsigned long dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    unsigned long nFileSizeHigh, nFileSizeLow;
    unsigned long dwReserved0, dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
    unsigned char pad_end[2];
};

extern "C" __declspec(dllimport) int __stdcall SetPaletteEntries(HWND, unsigned, unsigned, PALETTEENTRY*);
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char*);
extern "C" __declspec(dllimport) char* __stdcall CharUpperA(char*);
extern "C" __declspec(dllimport) HWND __stdcall CreateWindowExA(unsigned, const char*, const char*, unsigned, int, int, int, int, HWND, void*, void*, void*);
extern "C" __declspec(dllimport) HANDLE __stdcall FindFirstFileA(const char*, WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall FileTimeToSystemTime(const FILETIME*, SYSTEMTIME*);
extern "C" __declspec(dllimport) int __stdcall FindClose(HANDLE);

extern "C" char* __cdecl strstr(const char* str, const char* substr);
extern "C" char* __cdecl strncpy(char* dest, const char* src, unsigned int count);
extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);
extern "C" char* __cdecl _mbsstr(const char* str, const char* substr);
extern "C" char* __cdecl _mbsninc(const char* str, unsigned int count);
extern "C" int __cdecl _ismbcspace(unsigned int c);
extern "C" char* __cdecl _mbsncat(char* dst, const char* src, unsigned int count);
void* operator new(unsigned int size);

extern "C" void __cdecl RESFILE_build_res_file(const char* name, const char* dir, char* out);
extern "C" void __cdecl RESFILE_open_new_resource_file(const char* name, const char* tribe, char* out, int flag);
extern "C" void __cdecl run_log(const char* s, int flag);
extern "C" int __stdcall ICInfo(unsigned int fccType, unsigned int dwHandler, ICINFO* pICI);

extern char* __pgmptr;

// RGE_Prog_Info exact period layout (generated type dump)
class RGE_Prog_Info {
public:
    char prog_name[101];
    char prog_version[21];
    char prog_title[121];
    char world_db_file[261];
    char game_data_file[261];
    char vol_name[261];
    unsigned char _pad_0[2];
    unsigned long vol_ser_num;
    int verify_cd;
    int max_players_per_cd;
    void* instance;
    void* prev_instance;
    char registry_key[256];
    char cmd_line[256];
    int show_wnd_flag;
    char icon_name[41];
    char menu_name[41];
    char pal_file[261];
    char cursor_file[261];
    int max_players;
    int check_expiration;
    short expire_month;
    short expire_day;
    short expire_year;
    unsigned char _pad_1[2];
    unsigned long update_interval;
    int check_multi_copies;
    int skip_startup;
    int full_screen;
    int fixed_window_size;
    int use_dir_draw;
    int use_sys_mem;
    int use_music;
    int use_sound;
    int use_cd_audio;
    int use_ima;
    int use_midi;
    int use_wave_music;
    int fast_view;
    int auto_scroll;
    long mouse_scroll_edge;
    unsigned long mouse_scroll_interval;
    float mouse_scroll_max_dist;
    unsigned long key_scroll_interval;
    float key_scroll_max_dist;
    float key_scroll_object_move;
    short interface_style;
    unsigned char _pad_2[2];
    long main_wid;
    long main_hgt;
    unsigned char game_guid[0x10];
    unsigned char zone_guid[0x10];
    char data_dir[261];
    char graphics_dir[261];
    char save_dir[261];
    char scenario_dir[261];
    char campaign_dir[261];
    char sounds_dir[261];
    char resource_dir[261];
    char ai_dir[261];
    char avi_dir[261];
    unsigned char _pad_end[3];
};

class RGE_Game_Info;
class RGE_Scenario_File_Info;
class RGE_Game_World;
class RGE_Scenario;
class RGE_Scenario_Header;
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
class TPanel;
struct tagMSG;
class TCommunications_Handler;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario*);
    virtual RGE_Scenario_Header* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int, char*);
    virtual int setup_music_system();
    virtual void shutdown_music_system();
    virtual int setup();
    virtual int setup_cmd_options();
    virtual int setup_class();
    virtual int setup_main_window();
    virtual int setup_graphics_system();
    virtual int setup_palette();
    virtual int setup_mouse();
    virtual int setup_registry();
    virtual int setup_debugging_log();
    virtual int setup_chat();
    virtual int setup_comm();
    virtual int setup_sound_system();
    virtual int setup_fonts();
    virtual int setup_sounds();
    virtual int setup_shapes();
    virtual int setup_blank_screen();
    virtual void setup_timings();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void stop_music_system();
    virtual int restart_music_system();
    virtual RGE_Game_World* create_world();
    virtual int handle_message(tagMSG*);
    virtual int handle_idle();
    virtual int handle_mouse_move(void*, unsigned int, unsigned int, long);
    virtual int handle_key_down(void*, unsigned int, unsigned int, long);
    virtual int handle_user_command(void*, unsigned int, unsigned int, long);
    virtual int handle_command(void*, unsigned int, unsigned int, long);
    virtual int handle_music_done(void*, unsigned int, unsigned int, long);
    virtual int handle_paint(void*, unsigned int, unsigned int, long);
    virtual int handle_activate(void*, unsigned int, unsigned int, long);
    virtual int handle_init_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_exit_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_size(void*, unsigned int, unsigned int, long);
    virtual int handle_palette_changed(void*, unsigned int, unsigned int, long);
    virtual int handle_query_new_palette(void*, unsigned int, unsigned int, long);
    virtual int handle_close(void*, unsigned int, unsigned int, long);
    virtual int handle_destroy(void*, unsigned int, unsigned int, long);
    virtual int action_update();
    virtual int action_mouse_move(long, long, int, int, int, int);
    virtual int action_key_down(unsigned long, int, int, int, int);
    virtual int action_user_command(unsigned long, unsigned long);
    virtual int action_command(unsigned long, unsigned long);
    virtual int action_music_done();
    virtual int action_activate();
    virtual int action_deactivate();
    virtual int action_init_menu();
    virtual int action_exit_menu();
    virtual int action_size();
    virtual int action_close();
    virtual void calc_timings();
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    virtual int setup_map_save_area();
    virtual void set_interface_messages();

    RGE_Game_Info* player_game_info;
    RGE_Scenario_File_Info* scenario_info;
    RGE_Prog_Info* prog_info;
    void* prog_window;
    int prog_ready;
    int prog_active;
    void* prog_palette;
    void* prog_mutex;
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
    unsigned char _pad_3[3];
    int custom_mouse;
    short shape_num;
    unsigned char _pad_4[2];
    TShape** shapes;
    TSound_Driver* sound_system;
    TMusic_System* music_system;
    short sound_num;
    unsigned char _pad_5[2];
    TDigital** sounds;
    unsigned char save_music_type;
    unsigned char _pad_6[3];
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
    void* mouse_cursor;
    int input_enabled;
    void* input_disabled_window;
    short font_num;
    unsigned char _pad_7[2];
    RGE_Font* fonts;
    char work_dir[261];
    char string_dll_name[261];
    unsigned char _pad_8[2];
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
    unsigned char timings[0x3C0];
    int do_show_timings;
    int do_show_comm;
    int do_show_ai;
    unsigned long last_view_time;
    unsigned char rge_game_options[0xA8];
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
    unsigned char _pad_9[2];
    TDrawArea* map_save_area;

    unsigned char check_prog_argument(const char*);
    void setMultiplayerGame(int);
    void close();
};

class MouseClickInfo;

class TRIBE_Game : public RGE_Base_Game {
public:
    virtual ~TRIBE_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario*);
    virtual RGE_Scenario_Header* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int, char*);
    virtual int setup_music_system();
    virtual void shutdown_music_system();
    virtual int setup();
    virtual int setup_cmd_options();
    virtual int setup_class();
    virtual int setup_main_window();
    virtual int setup_graphics_system();
    virtual int setup_palette();
    virtual int setup_mouse();
    virtual int setup_registry();
    virtual int setup_debugging_log();
    virtual int setup_chat();
    virtual int setup_comm();
    virtual int setup_sound_system();
    virtual int setup_fonts();
    virtual int setup_sounds();
    virtual int setup_shapes();
    virtual int setup_blank_screen();
    virtual void setup_timings();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void stop_music_system();
    virtual int restart_music_system();
    virtual RGE_Game_World* create_world();
    virtual int handle_message(tagMSG*);
    virtual int handle_idle();
    virtual int handle_mouse_move(void*, unsigned int, unsigned int, long);
    virtual int handle_key_down(void*, unsigned int, unsigned int, long);
    virtual int handle_user_command(void*, unsigned int, unsigned int, long);
    virtual int handle_command(void*, unsigned int, unsigned int, long);
    virtual int handle_music_done(void*, unsigned int, unsigned int, long);
    virtual int handle_paint(void*, unsigned int, unsigned int, long);
    virtual int handle_activate(void*, unsigned int, unsigned int, long);
    virtual int handle_init_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_exit_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_size(void*, unsigned int, unsigned int, long);
    virtual int handle_palette_changed(void*, unsigned int, unsigned int, long);
    virtual int handle_query_new_palette(void*, unsigned int, unsigned int, long);
    virtual int handle_close(void*, unsigned int, unsigned int, long);
    virtual int handle_destroy(void*, unsigned int, unsigned int, long);
    virtual int action_update();
    virtual int action_mouse_move(long, long, int, int, int, int);
    virtual int action_key_down(unsigned long, int, int, int, int);
    virtual int action_user_command(unsigned long, unsigned long);
    virtual int action_command(unsigned long, unsigned long);
    virtual int action_music_done();
    virtual int action_activate();
    virtual int action_deactivate();
    virtual int action_init_menu();
    virtual int action_exit_menu();
    virtual int action_size();
    virtual int action_close();
    virtual void calc_timings();
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    virtual int setup_map_save_area();
    virtual void set_interface_messages();

    MouseClickInfo* MouseRightClickTable;
    int MouseRightClickTableSize;
    MouseClickInfo* MouseLeftClickTable;
    int MouseLeftClickTableSize;
    long queue_is_waiting_on_pop_counter[9];
    int random_civ[9];
    unsigned char tribe_game_options[0x6C];
    char testing_scenario[260];
    void* video_window;
    int cur_video;
    int (__stdcall *old_video_wnd_proc)();
    int video_paused;
    unsigned long last_video_time;
    int video_setup;
    int video_double_size;
    int video_changed_res;
    int video_hi_color;
    long video_save_res_wid;
    long video_save_res_hgt;
    void* video_save_palette;
    int started_menu_music;
    int show_object_id;
    void* game_screen;
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
    unsigned char _pad_A[3];
    int random_start_value;
    unsigned char computerNameUsed[18][10];
    void* handleIdleLock;
    int inHandleIdle;

    int start_scenario(char*);
    int load_game(char*);
    int start_menu();
    int start_video(int, char*);
};

class TPanelSystem {
public:
    void* panel(const char* name);                     // 00463D50
    int setCurrentPanel(const char* name, int idx);    // 00463E60
    int destroyPanel(const char* name);                // 00464060
};
extern TPanelSystem panel_system;   // 0x62E870

class TCommunications_Handler {
public:
    int LaunchLobbyGame();          // 0042D180
};

class TRIBE_Screen_Status_Message {
public:
    virtual ~TRIBE_Screen_Status_Message();
    char gap_04[0x478];
    TRIBE_Screen_Status_Message(const char* a, int b, const char* c, int d); // 004B7330
};
class TribeMPSetupScreen {
public:
    virtual ~TribeMPSetupScreen();
    TribeMPSetupScreen();           // 004A00B0
    char gap_04[0xD8 - 4];
    int field_D8;                   // +0xD8
    char gap_DC[0x890 - 0xDC];
};
class TRIBE_Screen_Main_Error {
public:
    virtual ~TRIBE_Screen_Main_Error();
    TRIBE_Screen_Main_Error();      // 0049F0D0
    void set_text(int);             // 0049F2D0
    char gap_04[0xD8 - 4];
    int field_D8;                   // +0xD8
    char gap_DC[0x484 - 0xDC];
};
class TEasy_Panel {
public:
    void popupOKDialog(int a, const char* b, int c, int d); // 00469EE0
};

extern void* StringTableX;           // 0x86BDE0
extern int video_codec_available;    // 0x86BDF0

int TRIBE_Game::setup()
{
    HANDLE h;
    int cmd;

    if (this->error_code)
        return 0;

    if (strstr(this->prog_info->cmd_line, "makeres") != 0 ||
        strstr(this->prog_info->cmd_line, "Makeres") != 0 ||
        strstr(this->prog_info->cmd_line, "MAKERES") != 0) {
        RESFILE_build_res_file("graphics.rm", "resource\\", this->prog_info->resource_dir);
        RESFILE_build_res_file("sounds.rm", "resource\\", this->prog_info->resource_dir);
        RESFILE_build_res_file("interfac.rm", "resource\\", this->prog_info->resource_dir);
    }
    RESFILE_open_new_resource_file("sounds.drs", "tribe", this->prog_info->resource_dir, 1);
    RESFILE_open_new_resource_file("graphics.drs", "tribe", this->prog_info->resource_dir, 0);
    RESFILE_open_new_resource_file("Interfac.drs", "tribe", this->prog_info->resource_dir, 0);
    RESFILE_open_new_resource_file("sounds.drs", "tribe", (char*)"data\\", 1);
    RESFILE_open_new_resource_file("graphics.drs", "tribe", (char*)"data\\", 0);
    RESFILE_open_new_resource_file("Terrain.drs", "tribe", (char*)"data\\", 0);
    RESFILE_open_new_resource_file("Border.drs", "tribe", (char*)"data\\", 0);
    RESFILE_open_new_resource_file("Interfac.drs", "tribe", (char*)"data\\", 0);

    if (this->RGE_Base_Game::setup() == 0)
        return 0;

    // command line parsing for STRING= language dll override
    WIN32_FIND_DATAA file_data;
    char cmd_line[256];
    char str[0x400];
    ICINFO ici;
    strncpy(&cmd_line[4], this->prog_info->cmd_line, 0xFF);
    str[3] = 0;
    CharUpperA(&cmd_line[4]);

    char* p = _mbsstr(&cmd_line[4], "STRING=");
    char new_string_dll_name[100] = "languagex.dll";
    if (p != 0) {
        while (*p != '=') {
            p = _mbsninc(p, 1);
        }
        p = _mbsninc(p, 1);
        while (!_ismbcspace((unsigned char)*p) && *p) {
            _mbsncat(new_string_dll_name, p, 1);
            p = _mbsninc(p, 1);
        }
    }
    StringTableX = LoadLibraryA(new_string_dll_name);
    if (!StringTableX) {
        this->error_code = 1;
        return 0;
    }

    PALETTEENTRY pal_entries[7] = {
        {0x17, 0x27, 0x7C, 0x00},
        {0x27, 0x3F, 0x90, 0x00},
        {0x3F, 0x5F, 0x9F, 0x00},
        {0x57, 0x7B, 0xB4, 0x00},
        {0x3F, 0x5F, 0xA0, 0x00},
        {0x27, 0x3F, 0x91, 0x00},
        {0x17, 0x27, 0x7B, 0x00}
    };
    SetPaletteEntries(this->prog_palette, 0xF8, 7, pal_entries);

    this->input_disabled_window = CreateWindowExA(0, "STATIC", "InputDisabledWindow", 0x40000000,
                                       0, 0, 1, 1, this->prog_window, 0,
                                       this->prog_info->instance, 0);

    video_codec_available = ICInfo(0x63646976, 0x31347669, &ici);

    if (this->check_prog_argument("LOBBY") != 0) {
        // lobby path inline
        new TRIBE_Screen_Status_Message("Status Screen", 0x4BF, "scr1", 0xC383);
        panel_system.setCurrentPanel("Status Screen", 0);
        cmd = this->comm_handler->LaunchLobbyGame();
        if (cmd == 1) {
            this->setMultiplayerGame(1);
            TribeMPSetupScreen* mp = new TribeMPSetupScreen;
            if (!mp || mp->field_D8)
                return 0;
            goto mp_setup;
        }
        if (cmd == -1) {
            TRIBE_Screen_Main_Error* err = new TRIBE_Screen_Main_Error;
            if (!err || err->field_D8)
                return 0;
            err->set_text(0x96A);
            panel_system.setCurrentPanel("Main Error Screen", 0);
            panel_system.destroyPanel("Status Screen");
            goto done;
        }
        this->close();
        return 1;
    }
    goto normal_start;

done:
    this->set_interface_messages();

    run_log("------------------------------", 0);
    run_log("", 1);

    // program version logging
    h = FindFirstFileA(__pgmptr, &file_data);
    if (h != (HANDLE)-1) {
        SYSTEMTIME st;
        memset(&st, 0, sizeof(st));
        FileTimeToSystemTime(&file_data.ftLastWriteTime, &st);
        sprintf(&str[4], "program=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d",
                __pgmptr, file_data.nFileSizeLow,
                st.wMonth, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
        run_log(&str[4], 0);
        FindClose(h);
    }

    // data version logging
    h = FindFirstFileA(this->prog_info->game_data_file, &file_data);
    if (h != (HANDLE)-1) {
        SYSTEMTIME st;
        memset(&st, 0, sizeof(st));
        FileTimeToSystemTime(&file_data.ftLastWriteTime, &st);
        sprintf(&str[4], "data=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d",
                this->prog_info->game_data_file, file_data.nFileSizeLow,
                st.wMonth, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
        run_log(&str[4], 0);
        FindClose(h);
    }

    sprintf(&str[4], "options=%s", this->prog_info->cmd_line);
    run_log(&str[4], 0);

    return 1;

normal_start:
    // ---- non-lobby / normal startup flow ----
    cmd = this->comm_handler->LaunchLobbyGame();
    if (cmd == 1) {
        this->setMultiplayerGame(1);
        new TribeMPSetupScreen;
        goto mp_setup;
    }
    if (!this->startup_scenario[0]) {
        if (!this->startup_game[0]) {
            if (!this->prog_info->skip_startup) {
                this->start_video(0, "logo1");
            } else {
                cmd = this->start_menu();
                if (cmd == 0)
                    goto ret_zero;
            }
            goto done;
        }
        cmd = this->load_game(this->startup_game);
    } else {
        cmd = this->start_scenario(this->startup_scenario);
    }
    if (cmd == 0) {
        cmd = this->start_menu();
        if (cmd == 0)
            goto ret_zero;
        TEasy_Panel* q = (TEasy_Panel*)panel_system.panel("Main Menu");
        if (q)
            q->popupOKDialog(0x961, 0, 0x1C2, 0x64);
    }
    goto done;

mp_setup:
        panel_system.setCurrentPanel("MP Setup Screen", 0);
        panel_system.destroyPanel("Status Screen");
        goto done;

ret_zero:
    return 0;
}
