#include "RGE_Base_Game.h"
#include "RGE_Game_World.h"
#include "RGE_Map.h"
#include "RGE_Prog_Info.h"
#include <stdio.h>

RGE_Base_Game* rge_base_game = nullptr;

RGE_Base_Game::RGE_Base_Game(RGE_Prog_Info *info, int setup_flag) {
    this->prog_info = info;
    this->world = nullptr;
    this->prog_ready = 0;
    this->prog_active = 0;
    this->windows_mouse = 0;
    this->error_code = 0;
    this->save_music_file[0] = 0;
}

RGE_Base_Game::~RGE_Base_Game() {
    if (this->world) delete this->world;
}

int RGE_Base_Game::setup() { return 1; }
int RGE_Base_Game::run() {
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}
int RGE_Base_Game::handle_idle() { return 1; }
int RGE_Base_Game::handle_message(tagMSG *msg) { return 0; }
long RGE_Base_Game::wnd_proc(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam) { return 0; }
void RGE_Base_Game::set_game_mode(int mode, int sub_mode) { this->prog_mode = mode; }
void RGE_Base_Game::set_player(short player_id) {}
char *RGE_Base_Game::get_string(long a, char *b, int c) { return nullptr; }
char *RGE_Base_Game::get_string2(int a, long b, long c, char *d, int e) { return nullptr; }
void *RGE_Base_Game::get_view_panel() { return nullptr; }
void *RGE_Base_Game::get_map_panel() { return nullptr; }
void *RGE_Base_Game::new_scenario_header(void *scenario) { return nullptr; }
void *RGE_Base_Game::new_scenario_header(int a) { return nullptr; }
void *RGE_Base_Game::new_scenario_info(int a) { return nullptr; }
void RGE_Base_Game::notification(int a, long b, long c, long d, long e) {}
void RGE_Base_Game::send_game_options() {}
void RGE_Base_Game::receive_game_options() {}
char *RGE_Base_Game::gameSummary() { return nullptr; }
int RGE_Base_Game::processCheatCode(int a, char *b) { return 0; }
void RGE_Base_Game::setNumberPlayers(int n) { this->rge_game_options.numberPlayersValue = (uchar)n; }
int RGE_Base_Game::setup_palette() { return 1; }
int RGE_Base_Game::setup_sounds() { return 1; }
RGE_Game_World* RGE_Base_Game::create_world() { return new RGE_Game_World(); }
int RGE_Base_Game::handle_activate(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_query_new_palette(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::action_key_down(ulong key, int a, int b, int c, int d) { return 0; }
int RGE_Base_Game::action_user_command(ulong a, ulong b) { return 0; }
int RGE_Base_Game::action_close() { return 0; }
void RGE_Base_Game::calc_timing_text() {}
void RGE_Base_Game::show_timings() {}
void RGE_Base_Game::show_comm() {}
void RGE_Base_Game::show_ai() {}
void RGE_Base_Game::set_interface_messages() {}
void RGE_Base_Game::set_prog_mode(int mode) { this->prog_mode = mode; }
char* RGE_Base_Game::get_string(int a, long b, char* c, int d) { return nullptr; }
char* RGE_Base_Game::get_string(long a) { return nullptr; }
int RGE_Base_Game::reset_comm() { return 1; }
int RGE_Base_Game::setup_music_system() { return 1; }
void RGE_Base_Game::shutdown_music_system() {}
int RGE_Base_Game::setup_cmd_options() { return 1; }
int RGE_Base_Game::setup_class() { return 1; }
int RGE_Base_Game::setup_main_window() { return 1; }
int RGE_Base_Game::setup_graphics_system() { return 1; }
int RGE_Base_Game::setup_mouse() { return 1; }
int RGE_Base_Game::setup_registry() { return 1; }
int RGE_Base_Game::setup_debugging_log() { return 1; }
int RGE_Base_Game::setup_chat() { return 1; }
int RGE_Base_Game::setup_comm() { return 1; }
int RGE_Base_Game::setup_sound_system() { return 1; }
int RGE_Base_Game::setup_fonts() { return 1; }
int RGE_Base_Game::setup_shapes() { return 1; }
int RGE_Base_Game::setup_blank_screen() { return 1; }
void RGE_Base_Game::setup_timings() {}
void RGE_Base_Game::stop_sound_system() {}
int RGE_Base_Game::restart_sound_system() { return 1; }
void RGE_Base_Game::stop_music_system() {}
int RGE_Base_Game::restart_music_system() { return 1; }
int RGE_Base_Game::handle_mouse_move(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_key_down(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_user_command(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_command(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_music_done(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_paint(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_init_menu(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_exit_menu(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_size(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_palette_changed(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_close(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::handle_destroy(void* hwnd, uint msg, uint wparam, long lparam) { return 0; }
int RGE_Base_Game::action_update() { return 1; }
int RGE_Base_Game::action_mouse_move(long x, long y, int a, int b, int c, int d) { return 0; }
int RGE_Base_Game::action_command(ulong a, ulong b) { return 0; }
int RGE_Base_Game::action_music_done() { return 0; }
int RGE_Base_Game::action_activate() { return 0; }
int RGE_Base_Game::action_deactivate() { return 0; }
int RGE_Base_Game::action_init_menu() { return 0; }
int RGE_Base_Game::action_exit_menu() { return 0; }
int RGE_Base_Game::action_size() { return 0; }
void RGE_Base_Game::calc_timings() {}
int RGE_Base_Game::setup_map_save_area() { return 1; }
int RGE_Base_Game::get_error_code() { return this->error_code; }
