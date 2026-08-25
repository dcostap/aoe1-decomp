// 00545CB0 RGE_Game_World::difficultyLevel()
#include "../world_phase2_context.h"
// PDB: World.cpp lines 3541-3546; owning range 00545CB0-00545CD4.
// The next World.cpp sibling starts at 00545CE0; bytes 00545CD5-00545CDF are padding.
// BINARY NOTE: The cache is RGE_Game_World::difficultyLevelValue at +0x100.

int RGE_Game_World::difficultyLevel(void) {
    if (this->difficultyLevelValue == -1) {
        this->difficultyLevelValue = rge_base_game->difficulty();
    }
    return this->difficultyLevelValue;
}
