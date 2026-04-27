// scenarioGame (004223A0, 9 bytes, basegame.cpp)
// tried: simple getter returning rge_game_options.scenarioGameValue
#include "game_globals.h"
#include "game_types.h"

// --- local stubs ---
// RGE_Game_Options nested struct (partial, from PDB)
struct RGE_Game_Options {
    float versionValue;                // +0x0
    unsigned char scenarioGameValue;   // +0x4
    // ... rest omitted, total size 0xA8
    unsigned char _pad[0xA4];
};

class RGE_Base_Game {
public:
    void* vtable;                     // +0x0
    unsigned char _pad[0x8F8];        // +0x4 .. +0x8F7
    RGE_Game_Options rge_game_options; // +0x8F8
    // ... rest omitted
};

int RGE_Base_Game::scenarioGame() {
    return rge_game_options.scenarioGameValue;
}
