#ifndef PLAYER_GROUPED_TU
class RGE_Command {
public:
    void command_destroy_group(int player_id, int group_id);
};

class RGE_World {
public:
    char gap_00[0x58];
    RGE_Command* commands;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_World* world;
    char gap_40[0x0A];
    short id;

    unsigned char command_destroy_group(int group_id);
};
#endif

unsigned char RGE_Player::command_destroy_group(int group_id) {
    this->world->command->command_destroy_group((int)this->id, group_id);
    return 1;
}
