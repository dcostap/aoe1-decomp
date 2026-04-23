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

int RGE_Game_World::difficultyLevel(void) {
    if (this->difficultyLevelValue == -1) {
        this->difficultyLevelValue = rge_base_game->difficulty();
    }
    return this->difficultyLevelValue;
}
