#include "TRIBE_Game.h"
#include <stdio.h>
#include <string.h>

// Address: 004549e0
TRIBE_Game::TRIBE_Game(RGE_Prog_Info* info, int setup) 
    : RGE_Base_Game(info, setup) 
{
    printf("[DECOMP] TRIBE_Game constructor called at 0x004549e0\n");
    
    this->MouseRightClickTable = nullptr;
    this->MouseRightClickTableSize = 0;
    this->MouseLeftClickTable = nullptr;
    this->MouseLeftClickTableSize = 0;
    
    memset(this->queue_is_waiting_on_pop_counter, 0, sizeof(this->queue_is_waiting_on_pop_counter));
    memset(this->random_civ, 0, sizeof(this->random_civ));
    
    // tribe_game_options will be default constructed (garbage if not Init)? 
    // Structs in C++ are not auto-zeroed if valid constructor exists, but this is a POD struct likely.
    memset(&this->tribe_game_options, 0, sizeof(this->tribe_game_options));
    
    this->testing_scenario[0] = 0;
    
    this->video_window = nullptr;
    this->cur_video = 0;
    this->old_video_wnd_proc = nullptr;
    this->video_paused = 0;
    this->last_video_time = 0;
    this->video_setup = 0;
    this->video_double_size = 0;
    this->video_changed_res = 0;
    this->video_hi_color = 0;
    this->video_save_res_wid = 0;
    this->video_save_res_hgt = 0;
    this->video_save_palette = nullptr;
    
    this->started_menu_music = 0;
    this->show_object_id = 0;
    this->game_screen = nullptr;
    
    memset(this->notification_loc_x, 0, sizeof(this->notification_loc_x));
    memset(this->notification_loc_y, 0, sizeof(this->notification_loc_y));
    this->current_notification_loc = 0;
    this->current_notification_recalled = 0;
    
    this->startup_scenario[0] = 0;
    this->startup_game[0] = 0;
    this->auto_exit_time = 0;
    this->save_game_name[0] = 0;
    this->load_game_name[0] = 0;
    this->timing_text2[0] = 0;
    
    memset(this->save_humanity, 0, sizeof(this->save_humanity));
    this->quick_start_game = 0;
    this->random_start_value = 0;
    memset(this->computerNameUsed, 0, sizeof(this->computerNameUsed));
    
    this->handleIdleLock = nullptr;
    this->inHandleIdle = 0;
}

TRIBE_Game::~TRIBE_Game() {
    // Destructor implementation needed?
    // Dump says scalar deleting destructor.
    // Base class destructor is virtual.
}

int TRIBE_Game::run() {
    // Stub
    return 0;
}

void TRIBE_Game::show_error(int id, char* buf, int s) {
    // Stub
}

void TRIBE_Game::fatal_exit(int a, int b, int c, char* d, int e) {
    // Stub
}
