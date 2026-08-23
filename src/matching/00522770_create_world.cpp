// attempt 1: natural `return new TRIBE_World;` shape, matching the sibling 00420050 basin first
// result: default flags built a tiny 32-byte body, so this one needs the EH/new prolog basin
// attempt 2: adding a local RGE_Game_World body fixed compilation, but the body stayed too small
// attempt 3: testing the sibling-style /GX response file next; keep this note so the custom flag is explicit

#include "..\..\include\game_globals.h"
#include "..\..\include\game_types.h"
#include "../../include/tribegam_context.h"

#if 0
class TRIBE_Game {
public:
    RGE_Game_World* create_world();
};
#endif

RGE_Game_World* TRIBE_Game::create_world() {
    return new TRIBE_World;
}
