#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_World {
public:
    long get_achievement(unsigned char param_1, char** param_2);
};

class TRIBE_Game {
public:
    char gap_0[0x3F4];
    TRIBE_World* world;

    long get_achievement_info(unsigned char param_1, char** param_2);
};
#endif

long TRIBE_Game::get_achievement_info(unsigned char param_1, char** param_2) {
    if (!this->world)
        return 0;
    return this->world->get_achievement(param_1, param_2);
}
