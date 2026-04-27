// tried the natural `return new RGE_Game_World;` shape first; default flags only built a 32-byte body
// /GX was required to land the EH/new helper in the exact 90-byte basin
#include "..\..\include\game_globals.h"
#include "..\..\include\game_types.h"

class RGE_Game_World {
public:
    void* vtable_ptr;
    char _pad[0x100];

    RGE_Game_World();
};

class RGE_Base_Game {
public:
    RGE_Game_World* create_world();
};

RGE_Game_World* RGE_Base_Game::create_world() {
    return new RGE_Game_World;
}
