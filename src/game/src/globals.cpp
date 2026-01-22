#include "../include/globals.h"

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
int restore_mouse_after_paint = 1;

void run_log(char* param_1, int param_2) {}
