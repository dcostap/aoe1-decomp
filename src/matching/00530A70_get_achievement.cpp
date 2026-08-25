#ifndef TWORLD_PHASE2_CONTEXT
class TRIBE_Player {
public:
    void get_achievement(unsigned char achievement_id, char* buffer);
};

class TRIBE_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[0x2];
    TRIBE_Player** players;

    long get_achievement(unsigned char achievement_id, char** buffers);
};
#endif

long TRIBE_World::get_achievement(unsigned char achievement_id, char** buffers) {
    int player = 1;

    if (this->player_num > 1) {
        do {
#ifdef TWORLD_PHASE2_CONTEXT
            TRIBE_Player* p = (TRIBE_Player*)this->players[player];
#else
            TRIBE_Player* p = this->players[player];
#endif
            if (p != 0) {
                p->get_achievement(achievement_id, buffers[player]);
            }
            player++;
        } while (player < this->player_num);
    }

    return this->player_num;
}
