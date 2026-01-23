#pragma once
#include <windows.h>
#include <stdio.h>

class RGE_Base_Game;
class TRegistry;
struct TPanelSystem;
struct TMousePointer;

extern RGE_Base_Game* rge_base_game;
extern int do_draw_log;
extern int safe_draw_log;
extern char draw_log_name[260];
extern FILE* draw_log;
extern HINSTANCE StringTable;
extern TRegistry* Regs;
extern HWND AppWnd;
extern HINSTANCE AppInst;
extern void* chat;
extern void* comm;
extern void* sound_driver;
extern void* driveInfo;
extern TMousePointer* MouseSystem;

extern int do_run_log;
extern int run_log_created;
extern FILE* run_log_file;
extern HINSTANCE StringTableX;
extern int disable_terrain_sounds;
extern int out_of_sync;
extern int out_of_sync2;
extern int player_dropped[9];
extern TPanelSystem* panel_system;
extern int debugActions;
extern FILE* actionFile;
extern int video_codec_available;
extern int log_output;

extern int quick_start_game_mode;
extern int restore_mouse_after_paint;
extern unsigned char shape_file_first;

void run_log(char* param_1, int param_2);
