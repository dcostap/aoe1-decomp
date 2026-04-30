// VA: 0048AD60 RGE_Scenario::RGE_Scenario(RGE_Game_World*)
// Source: scenario.cpp lines 152-161
// Size: 138 bytes, __thiscall, ret 4 (1 param)
// FLAGS: /GX (EH frame for new expression)
// Status: 101 bytes match, 9 bytes diff — memset arg scheduling
//   Remaining: lea edi before mov ecx,400h (original) vs after (rebuilt)
//   VC5 scheduling artifact — cannot influence from C++

#include <string.h>

struct RGE_Game_World;

struct RGE_Timeline {
    int _gap[5]; // size 0x14
    RGE_Timeline(RGE_Game_World*);
};

struct RGE_Scenario {
public:
    RGE_Timeline* time_line;                // +0x04
    RGE_Game_World* world;                  // +0x08
    char victory_conquest;                  // +0x0C
    char player_name[0x1000];               // +0x0D
    char _gap_100D[0x198C - 0x100D];        // gap
    void* mission_picture;                  // +0x198C

    RGE_Scenario(RGE_Game_World*);
    virtual ~RGE_Scenario();
    void InitializeTextValues();
};

RGE_Scenario::RGE_Scenario(RGE_Game_World* game_world) {
    this->world = game_world;
    this->time_line = new RGE_Timeline(this->world);
    this->InitializeTextValues();
    this->mission_picture = 0;
    this->victory_conquest = 1;
    memset(this->player_name, 0, sizeof(this->player_name));
}
