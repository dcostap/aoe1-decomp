// 0052A430 TRIBE_Game::shutdown_video_system (tribegam.cpp:5575-5605)
// Attempt 3: declare virtual methods at correct vtable slots

__declspec(dllimport) int __stdcall InvalidateRect_tribe(void* hWnd, void* lpRect, int bErase);
__declspec(dllimport) void* __stdcall LoadCursorA(void* hInstance, int lpCursorName);

extern "C" int restore_mouse_after_paint;  // 62C55Ch

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Scenario;
class RGE_Scenario_Header;
class TPanel;
struct TDrawSystem {
    void SetDisplaySize(long wid, long hgt, int bits);
    void ClearPrimarySurface();
    void SetPalette(void* palette);
    unsigned char CheckSurfaces();
    void ClearRestored();
};

class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
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
    virtual int restart_sound_system();

    // Data members
    char gap_04[0x0C];          // +0x04 to +0x0F
    void* prog_window;          // +0x10
    char gap_14[0x34];          // +0x14 to +0x47
    TDrawSystem* draw_system;   // +0x48
    char gap_4C[0xBB4];         // +0x4C to +0xBFF
    int video_setup;             // +0xC00
    int video_double_size;       // +0xC04
    int video_changed_res;       // +0xC08
    int video_hi_color;          // +0xC0C
    long video_save_res_wid;     // +0xC10
    long video_save_res_hgt;     // +0xC14
    void* video_save_palette;    // +0xC18

    // Non-virtual helper methods (inherited from RGE_Base_Game)
    int check_paint();
    void set_render_all();
    void set_mouse_cursor(void* cursor);
    void mouse_on();

    void shutdown_video_system();
};
#endif

void TRIBE_Game::shutdown_video_system()
{
    if (video_setup == 0) return;

    if (video_changed_res) {
        draw_system->SetDisplaySize(video_save_res_wid, video_save_res_hgt, 8);
        draw_system->ClearPrimarySurface();
        draw_system->SetPalette(video_save_palette);
        video_changed_res = 0;
        draw_system->CheckSurfaces();
        draw_system->ClearRestored();
        check_paint();
        restore_mouse_after_paint = 1;
    }

    draw_system->ClearPrimarySurface();
    draw_system->SetPalette(video_save_palette);
    set_render_all();

    InvalidateRect_tribe(this->prog_window, 0, 1);

    set_prog_mode(2);
    restart_sound_system();

    void* cursor = LoadCursorA(0, 0x7F00);
    set_mouse_cursor(cursor);
    mouse_on();

    video_setup = 0;
}
