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

#include <stdio.h>

class RGE_Game_Info;
class RGE_Scenario_File_Info;
class RGE_Prog_Info {
public:
    char gap_00[0x410];
    void* instance;
    char gap_414[0x8C8 - 0x414];
    int scroll_speed;
    char gap_8CC[0x8DC - 0x8CC];
    short interface_style;
};
class RGE_Game_World {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08();
    virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20();
    virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38();
    virtual void vf3C(); virtual void vf40(); virtual void vf44();
    virtual void vf48(); virtual void vf4C(); virtual void vf50();
    virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68();
    virtual void vf6C(); virtual void vf70(); virtual void vf74();
    virtual void vf78(); virtual void vf7C(); virtual void vf80();
    virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90(); virtual void vf94(); virtual void vf98();
    virtual void vf9C(); virtual void vfA0(int value);
};
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
class RGE_Font {
public:
    void* handle;
    char gap_04[8];
};
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
extern "C" int (__stdcall* const DeleteObject)(void* object);

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

class RGE_Game_Info {
public:
    void save(char* filename);
    ~RGE_Game_Info();
};

class RGE_Scenario_File_Info {
public:
    ~RGE_Scenario_File_Info();
};

class TDrawSystem {
public:
    char gap_00[0x2C];
    int screen_size;
    ~TDrawSystem();
};

class TDrawArea {
public:
    ~TDrawArea();
};

class TMousePointer {
public:
    ~TMousePointer();
};

class TCommunications_Handler {
public:
    ~TCommunications_Handler();
};

class TChat {
public:
    ~TChat();
};

class TRegistry {
public:
    int RegGetInt(int use_user_key, const char* value_name);
    int RegSetInt(int use_user_key, const char* value_name, int value);
    ~TRegistry();
};

class TDebuggingLog {
public:
    ~TDebuggingLog();
};

class TShape {
public:
    ~TShape();
};

class TPanelSystem {
public:
    void destroyPanel(char* name);
    void release_palette(void* palette);
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

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
    unsigned char pad_51[3];
    int custom_mouse;
    short shape_num;
    unsigned char pad_5A[2];
    TShape** shapes;
    TSound_Driver* sound_system;
    TMusic_System* music_system;
    short sound_num;
    unsigned char pad_6A[2];
    TDigital** sounds;
    unsigned char save_music_type;
    unsigned char pad_71[3];
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
    unsigned char pad_1E2[2];
    RGE_Font* fonts;
    char work_dir[261];
    char string_dll_name[261];
    unsigned char pad_3F2[2];
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
    char timings[0x3C0];
    int do_show_timings;
    int do_show_comm;
    int do_show_ai;
    unsigned long last_view_time;
    char game_options[0xA8];
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
    unsigned char pad_A1E[2];
    TDrawArea* map_save_area;

    unsigned char pathFinding();
    unsigned char mpPathFinding();
    void stop_sound_system();
    void get_string(char* buffer, int string_id, int buffer_size);
};

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
        this->registry->RegSetInt(1, "Screen Size", this->draw_system->screen_size);
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
    this->registry->RegSetInt(1, "Scroll Speed", this->prog_info->scroll_speed);

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
        this->world->vfA0(1);
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
        for (i = 0; i < this->font_num; ++i) {
            if (this->fonts[i].handle != 0)
                DeleteObject(this->fonts[i].handle);
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
        SystemParametersInfoA(0x11, 0, 0, 2);
    if (this->low_power_enabled != 0)
        SystemParametersInfoA(0x55, 0, 0, 2);

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

    this->get_string(str, 0x3EB, 0x100);
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
