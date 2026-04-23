// tried direct indexing first; mismatch stayed in loop codegen around player-array access
// tried a local players pointer next; mismatch moved to the loop entry / saved-register shape
// leaving in scratch because the remaining gap is codegen-shape drift, not call-set or behavior
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

long TRIBE_World::get_achievement(unsigned char achievement_id, char** buffers) {
    short player = 1;
    TRIBE_Player** players = this->players;

    if (this->player_num > 1) {
        do {
            if (players[player] != 0) {
                players[player]->get_achievement(achievement_id, buffers[player]);
            }
            player++;
        } while (player < this->player_num);
    }

    return this->player_num;
}
