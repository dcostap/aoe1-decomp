// attempt 1: natural `return new TRIBE_World;` shape, matching the sibling 00420050 basin first
// result: default flags built a tiny 32-byte body, so this one needs the EH/new prolog basin
// attempt 2: adding a local RGE_Game_World body fixed compilation, but the body stayed too small
// attempt 3: testing the sibling-style /GX response file next; keep this note so the custom flag is explicit

#include "..\..\include\game_globals.h"
#include "..\..\include\game_types.h"

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_0[0x100];
};

class TRIBE_World : public RGE_Game_World {
public:
    void* tech; // +0x104
    int victory_type; // +0x108
    int artifact_count; // +0x10C
    int ruin_count; // +0x110
    unsigned char countdown_victory; // +0x114
    unsigned char _pad_0[0x3];
    float countdown_clock; // +0x118
    unsigned char score_displayed; // +0x11C
    unsigned char controllingComputerPlayer; // +0x11D
    unsigned char _pad_1[0x2];
    int sent_zone_score; // +0x120

    TRIBE_World();
};

class TRIBE_Game {
public:
    RGE_Game_World* create_world();
};

RGE_Game_World* TRIBE_Game::create_world() {
    return new TRIBE_World;
}
