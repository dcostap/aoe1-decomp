// 005245D0 TRIBE_Game::load_game_data
// Source: tribegam.cpp lines 1887-1903
// public: int __thiscall TRIBE_Game::load_game_data(void)
//
// Attempt log:
// Probe 1: correct virtual method placement on both TRIBE_Game and RGE_Game_World, default flags

#include "..\..\include\game_globals.h"

// RGE_Game_World — with virtual methods at slots 40 (0xA0) and 44 (0xB0)
#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Game_World {
public:
    // 40 dummy virtual methods (slots 0-39)
    virtual void _d0() {} virtual void _d1() {} virtual void _d2() {} virtual void _d3() {}
    virtual void _d4() {} virtual void _d5() {} virtual void _d6() {} virtual void _d7() {}
    virtual void _d8() {} virtual void _d9() {} virtual void _d10() {} virtual void _d11() {}
    virtual void _d12() {} virtual void _d13() {} virtual void _d14() {} virtual void _d15() {}
    virtual void _d16() {} virtual void _d17() {} virtual void _d18() {} virtual void _d19() {}
    virtual void _d20() {} virtual void _d21() {} virtual void _d22() {} virtual void _d23() {}
    virtual void _d24() {} virtual void _d25() {} virtual void _d26() {} virtual void _d27() {}
    virtual void _d28() {} virtual void _d29() {} virtual void _d30() {} virtual void _d31() {}
    virtual void _d32() {} virtual void _d33() {} virtual void _d34() {} virtual void _d35() {}
    virtual void _d36() {} virtual void _d37() {} virtual void _d38() {} virtual void _d39() {}

    virtual void destroyGameData(int flag);    // Slot 40 (0xA0)
    // 3 more dummies (slots 41-43)
    virtual void _d41() {} virtual void _d42() {} virtual void _d43() {}
    virtual char loadGameData(char* file, void* sound, void* comm); // Slot 44 (0xB0)
};

// RGE_Prog_Info stub — game_data_file at +0x1F8
class RGE_Prog_Info {
public:
    char _gap_00[0x1F8];
    char game_data_file[261]; // +0x1F8
};

// TRIBE_Game — needs vtable slot 45 (0xB4): createGameData
class TRIBE_Game {
public:
    // 45 dummy virtual methods (slots 0-44) to push to slot 45
    virtual void _d0() {} virtual void _d1() {} virtual void _d2() {} virtual void _d3() {}
    virtual void _d4() {} virtual void _d5() {} virtual void _d6() {} virtual void _d7() {}
    virtual void _d8() {} virtual void _d9() {} virtual void _d10() {} virtual void _d11() {}
    virtual void _d12() {} virtual void _d13() {} virtual void _d14() {} virtual void _d15() {}
    virtual void _d16() {} virtual void _d17() {} virtual void _d18() {} virtual void _d19() {}
    virtual void _d20() {} virtual void _d21() {} virtual void _d22() {} virtual void _d23() {}
    virtual void _d24() {} virtual void _d25() {} virtual void _d26() {} virtual void _d27() {}
    virtual void _d28() {} virtual void _d29() {} virtual void _d30() {} virtual void _d31() {}
    virtual void _d32() {} virtual void _d33() {} virtual void _d34() {} virtual void _d35() {}
    virtual void _d36() {} virtual void _d37() {} virtual void _d38() {} virtual void _d39() {}
    virtual void _d40() {} virtual void _d41() {} virtual void _d42() {} virtual void _d43() {}
    virtual void _d44() {}

    virtual RGE_Game_World* createGameWorld(); // Slot 45 (0xB4)

    // Data fields (from RGE_Base_Game layout)
    char _gap_04[8];                 // player_game_info(4) + scenario_info(4)
    RGE_Prog_Info* prog_info;        // +0x0C
    char _gap_10[0x50];              // +0x10 to +0x60
    void* sound_system;              // +0x60
    char _gap_64[0x128];             // +0x64 to +0x18C
    void* comm_handler;              // +0x18C
    char _gap_190[0x264];            // +0x190 to +0x3F4
    RGE_Game_World* world;           // +0x3F4

    int load_game_data();
};
#endif

int TRIBE_Game::load_game_data()
{
    if (this->world == 0) {
        this->world = (TRIBE_World*)this->createGameWorld();
        if (this->world == 0)
            return 0;

        if (!this->world->loadGameData((char*)this->prog_info + 0x1F8,
                                         this->sound_system, this->comm_handler)) {
            if (this->world != 0)
                this->world->destroyGameData(1);
            this->world = 0;
            return 0;
        }
    }
    return 1;
}
