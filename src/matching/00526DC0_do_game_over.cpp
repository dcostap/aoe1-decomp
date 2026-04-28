// TRIBE_Game::do_game_over
// VA: 00526DC0
// tribegam.cpp:3191-3220
// 149 bytes

#include "../../include/game_globals.h"

class RGE_Player {
public:
    unsigned char gap_00[0x80];
    unsigned char game_status;     // +0x80
};

class TRIBE_Game {
public:
    // Flat layout; RGE_Base_Game base occupies 0x000 to 0xA23
    // Fields of interest within that range:
    //   +0x1B0: int game_type
    //   +0x3F4: void* some_video_object
    // +0xAE8: unsigned char testing_scenario (TRIBE_Game-specific)
    char gap_00[0x1B0];
    int game_type;                  // +0x1B0
    char gap_1B4[0x3F4 - 0x1B4];
    void* some_video_object;        // +0x3F4
    char gap_3F8[0xAE8 - 0x3F8];
    unsigned char testing_scenario; // +0xAE8

    void do_game_over(void);
    void disconnect_multiplayer_game(void);
    void quit_game(void);
    void turn_world_sound_off(void);
    RGE_Player* get_player(void);
    int start_video(int param_1, char* param_2);
};

void TRIBE_Game::do_game_over(void) {
    disconnect_multiplayer_game();
    
    if (this->testing_scenario != 0) {
        quit_game();
        return;
    }
    
    int mode = this->game_type;
    if (mode == 4 || mode == 6 || mode == 5 || mode == 3) {
        this->game_type = 0;
        if (this->some_video_object != 0) {
            turn_world_sound_off();
            
            RGE_Player* player = get_player();
            if (player->game_status == 1) {
                start_video(4, (char*)(*(int*)((char*)this->some_video_object + 0x5C) + 0x15E8));
                return;
            }
            start_video(4, (char*)(*(int*)((char*)this->some_video_object + 0x5C) + 0x16C8));
        }
    }
}
