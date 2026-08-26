// VA: 0052A260 TRIBE_Game::setup_video_system (450 B)
// PDB source: tribegam.cpp:5501-5569
//
// Attempt log:
// - Replaced the allocation-only scaffold with the natural period video setup
//   flow: blank panel, mouse shutdown, draw-system mode selection, debugging
//   logs, and the base-game virtual mode/sound calls.
// - Exact baseline: the donor-backed +0x48 draw system, +0x1c0 mouse pointer,
//   +0xc00 video fields, and virtual stop_sound_system slot reproduce all
//   450 bytes with the default flags.

extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hcur);
extern "C" __declspec(dllimport) long __stdcall SetClassLongA_tribe(
    void* hwnd, long index, long value);

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Game_World;
class RGE_Scenario;
class RGE_Scenario_Header;
class TPanel;
class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
};

extern TPanelSystem panel_system;

class TMousePointer {
public:
    int Shutdown_Mouse();
};

class TDrawSystem {
public:
    void* instance; // +0x00
    void* window; // +0x04
    void* palette; // +0x08
    char gap_0C[0x20];
    long ScreenWidth; // +0x2C
    long ScreenHeight; // +0x30
    char gap_34[0x444];
    unsigned char DrawType; // +0x478
    unsigned char ScreenMode; // +0x479

    int IsModeAvail(long width, long height, int bits);
    int SetDisplaySize(long width, long height, int bits);
};

class TDebuggingLog;
extern TDebuggingLog* L;
extern void __cdecl Log(TDebuggingLog* log, char* format, ...);

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* window, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int sub_mode);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int id, long param, char* buffer, int length);
    virtual char* get_string(long id, char* buffer, int length);
    virtual char* get_string(long id);
    virtual char* get_string2(int id, long p2, long p3, char* buffer,
                              int length);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* scenario);
    virtual RGE_Scenario_Header* new_scenario_header(int scenario);
    virtual RGE_Scenario* new_scenario_info(int scenario);
    virtual void notification(int id, long p2, long p3, long p4, long p5);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int id, char* code);
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

    char gap_04[0x0C];
    void* prog_window; // +0x10
    char gap_14[0x34];
    TDrawSystem* draw_system; // +0x48
    char gap_4C[0x174];
    TMousePointer* mouse_pointer; // +0x1C0
    char gap_1C4[0x860];

    void mouse_off();
    unsigned char check_prog_argument(char* value);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x1DC];
    int video_setup; // +0xC00
    int video_double_size; // +0xC04
    int video_changed_res; // +0xC08
    int video_hi_color; // +0xC0C
    long video_save_res_wid; // +0xC10
    long video_save_res_hgt; // +0xC14
    void* video_save_palette; // +0xC18

    int setup_video_system();
};
#endif

int TRIBE_Game::setup_video_system()
{
    if (this->video_setup != 0) {
        return 1;
    }

    panel_system.setCurrentPanel("Blank Screen", 0);
    this->mouse_off();

    this->video_double_size = 1;
    this->video_changed_res = 0;
    this->video_hi_color = 0;
    this->video_save_palette = this->draw_system->palette;

    if (this->draw_system->ScreenMode == 2) {
        SetCursor(0);
        SetClassLongA_tribe(this->prog_window, -12, 0);
        this->mouse_pointer->Shutdown_Mouse();

        this->video_save_res_wid = this->draw_system->ScreenWidth;
        this->video_save_res_hgt = this->draw_system->ScreenHeight;
        if (this->check_prog_argument("8BITVIDEO") == 0) {
            if (this->draw_system->IsModeAvail(0x280, 0x1E0, 0x10) != 0) {
                Log(L, "640x480 16bit");
                this->video_changed_res =
                    this->draw_system->SetDisplaySize(0x280, 0x1E0, 0x10);
                if (this->video_changed_res != 0) {
                    this->video_double_size = 1;
                    this->video_hi_color = 1;
                    Log(L, "640x480 16bit success");
                }
            }

            if (this->video_changed_res == 0 &&
                this->draw_system->ScreenWidth != 0x280) {
                if (this->draw_system->IsModeAvail(0x280, 0x1E0, 8) != 0) {
                    Log(L, "640x480 8bit");
                    this->video_changed_res =
                        this->draw_system->SetDisplaySize(0x280, 0x1E0, 8);
                    if (this->video_changed_res != 0) {
                        this->video_double_size = 1;
                        Log(L, "640x480 8bit success");
                    }
                }
            }
        }
    }

    Log(L, "video_changed_res=%d, double_size=%d",
        this->video_changed_res, this->video_double_size);
    this->set_prog_mode(1);
    this->stop_sound_system();
    this->video_setup = 1;
    return 1;
}
