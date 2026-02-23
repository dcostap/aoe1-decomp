#pragma once
#include <windows.h>
#include <stdio.h>

class RGE_Base_Game;
class TRegistry;
struct TPanelSystem;
struct TMousePointer;
struct DClipInfo_List;

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
extern unsigned char sound_file_first;
extern int do_fixed_update;
extern int displayPathingFlags;
extern int debug_timeGetTime_on;
extern int system_ignore_size_messages;
extern int do_restore_palette;
extern unsigned long restore_palette_timer;
extern void* save_active_wnd;
extern int MouseCursorInChildContol;
extern int DDSys_CanColorFill;
extern int no_other_humans_count;
extern int all_cp;
extern int numberPathingIterations;
extern int useComputerPlayers;
extern int show_timing_max;
extern float save_game_version;
extern unsigned long* unified_map_offsets[256];
extern unsigned char die_die_die;
extern int allow_user_commands;
extern int world_update_counter;
extern int ENABLE_COMPRESSION;
extern int rge_write_error;
extern int Map_Update_Suppresion;
extern int debug_random_on;
extern int fog_next_shape;

// Selection/display capture globals (used by view/sprite/shape/static object draw paths).
extern int SDI_Capture_Info;
extern DClipInfo_List* SDI_List;
extern long SDI_Object_ID;
extern int SDI_Draw_Line;
extern int SDI_Draw_Level;
extern int startLoggingAI;
extern int confirmed_close;
extern FILE* commonHistoryLogFile;
extern int specificAIPlayerToLog;

void run_log(char* param_1, int param_2);
int rge_fake_open(int handle, int remaining_bytes);
int rge_open(char* path, int oflag);
int rge_open(char* path, int oflag, int pmode);
int rge_fake_close(int handle);
int rge_close(int handle);
void rge_read(int handle, void* buf, int size);
void rge_write(int handle, void* buf, int size);
long rge_stream_tell(int handle);
long rge_stream_seek(int handle, long pos);
