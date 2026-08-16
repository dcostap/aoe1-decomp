#pragma once

class RGE_Base_Game;

// The executable stores the process-wide base-game pointer at 0062C574.
// Use this extern symbol in compiler-facing source. An absolute-dereference
// macro can change VC5 relocations, scheduling, and register coloring.
extern RGE_Base_Game* rge_base_game;

static __inline RGE_Base_Game* rge_base_game_at_storage()
{
    return *(RGE_Base_Game**)0x0062C574;
}
