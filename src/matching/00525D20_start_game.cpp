// VA: 00525D20 TRIBE_Game::start_game (299 B)
// PDB source: tribegam.cpp, lines 2586-2638
// Attempt log:
// baseline: natural start-game flow with period string-copy, status-message,
// world/scenario, and member-call surfaces reconstructed from the packet and
// same-TU donors; size/frame/call set matched, with only three LEA bytes off.
// declaration-order and register/local-result probes were codegen duplicates.
// 260-byte and 252-byte buffers changed the frame (104h/0fch); union overlay
// changed the copy topology; all were rolled back.
// exact: using the named 256-byte info_file directly (rather than the inferred
// decompiler +4 prefix) reproduces the original stack address and all 299 bytes.
// Main-agent audit restored the donor-backed scenario/world/base-game virtual
// slot declarations; the natural start-game source remains exact.

#include <string.h>
#include <stdio.h>

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Static_Object;

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~RGE_Scenario();
    char gap_04[0x1504];
    char Cine_PreGame[0xE0]; // +0x1508
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE* file);
    char gap_04[0x58];
    RGE_Scenario* scenario; // +0x5C
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    int singlePlayerGame();
    void disable_input();
    void enable_input();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_04[0x3F0];
    RGE_Game_World* world; // +0x3F4

    void show_status_message(int string_id, char* param_2, long param_3);
    int load_game_data();
    int create_game(int param_1);
    void close_status_message();
    void set_save_game_name(char* param_1);
    void set_load_game_name(char* param_1);
    int create_game_screen();
    int start_video(int param_1, char* param_2);

    int start_game(int param_1);
};
#endif

int TRIBE_Game::start_game(int param_1)
{
    long info_id;
    char info_file[256];

    if (this->singlePlayerGame()) {
        strcpy(info_file, "scr2");
        info_id = 0xC384;
    } else {
        strcpy(info_file, "scr3");
        info_id = 0xC385;
    }

    this->disable_input();

    if (this->world == 0) {
        this->show_status_message(0x44D, info_file, info_id);
        if (this->load_game_data() == 0)
            goto start_game_failed;
    }

    this->show_status_message(0x451, info_file, info_id);
    if (this->create_game(0) == 0)
        goto start_game_failed;

    this->set_save_game_name(0);
    this->set_load_game_name(0);

    if (param_1 != 0)
        return this->create_game_screen();

    this->start_video(3, (char*)this->world->scenario + 0x1508);
    return 1;

start_game_failed:
    this->close_status_message();
    this->enable_input();
    return 0;
}
