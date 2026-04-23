class RGE_Player {
public:
    char gap_00[0x20];
    unsigned char checksum_created_this_update;
    char gap_21[0x13];
    long checksum;
    long position_checksum;
    long action_checksum;

    long get_checksum(void);
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[0x02];
    RGE_Player** players;
    short master_player_num;
    char gap_46[0x36];
    short curr_player;
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;

    long GetChecksum(long param_1);
};

long RGE_Base_Game::GetChecksum(long param_1) {
    RGE_Game_World* world = this->world;
    if (world != 0) {
        if (param_1 < 0) {
            return world->players[world->curr_player]->get_checksum();
        }
        if (param_1 < world->player_num) {
            return world->players[param_1]->get_checksum();
        }
    }
    return 0;
}
