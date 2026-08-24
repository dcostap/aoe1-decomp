// 00545CB0 RGE_Game_World::difficultyLevel()
// PDB: World.cpp lines 3541-3546; owning range 00545CB0-00545CD4.
// The next World.cpp sibling starts at 00545CE0; bytes 00545CD5-00545CDF are padding.
// BINARY NOTE: The cache is RGE_Game_World::difficultyLevelValue at +0x100.

#ifndef WORLD_TU
class RGE_Base_Game {
public:
    int difficulty(void);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Game_World {
public:
    char gap_00[0x100];
    int difficultyLevelValue;

    int difficultyLevel(void);
};
#endif

int RGE_Game_World::difficultyLevel(void) {
    if (this->difficultyLevelValue == -1) {
        this->difficultyLevelValue = rge_base_game->difficulty();
    }
    return this->difficultyLevelValue;
}
