#include "../include/globals.h"
#include <io.h>

RGE_Base_Game* rge_base_game = nullptr;
int do_draw_log = 0;
int safe_draw_log = 0;
char draw_log_name[260] = {0};
FILE* draw_log = nullptr;
HINSTANCE StringTable = nullptr;
TRegistry* Regs = nullptr;
HWND AppWnd = nullptr;
HINSTANCE AppInst = nullptr;
void* chat = nullptr;
void* comm = nullptr;
void* sound_driver = nullptr;
void* driveInfo = nullptr;
TMousePointer* MouseSystem = nullptr;

int do_run_log = 0;
int run_log_created = 0;
FILE* run_log_file = nullptr;
HINSTANCE StringTableX = nullptr;
int disable_terrain_sounds = 0;
int out_of_sync = 0;
int out_of_sync2 = 0;
int player_dropped[9] = {0};
TPanelSystem* panel_system = nullptr;
int debugActions = 0;
FILE* actionFile = nullptr;
int video_codec_available = 0;
int log_output = 0;

int quick_start_game_mode = 0;
int restore_mouse_after_paint = 0;
int restoration_count = 0;
unsigned char shape_file_first = 0;
unsigned char sound_file_first = 0;
int debug_timeGetTime_on = 0;
// system_ignore_size_messages defined in Drawarea.cpp
int do_restore_palette = 0;
unsigned long restore_palette_timer = 0;
void* save_active_wnd = nullptr;
int MouseCursorInChildContol = 0;
int DDSys_CanColorFill = 1;
int no_other_humans_count = 0;
int all_cp = 0;
int numberPathingIterations = 2500; // default per decomp (0x9c4)
int useComputerPlayers = 1; // default per ASM (= 1h)
int show_timing_max = 0;
float save_game_version = 0.0f;
unsigned char die_die_die = 0;

void run_log(char* param_1, int param_2) {}

void rge_read(int handle, void* buf, int size) {
    _read(handle, buf, size);
}

void rge_write(int handle, void* buf, int size) {
    _write(handle, buf, size);
}
