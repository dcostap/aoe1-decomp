#ifndef PLAYER_GROUPED_TU
class RGE_Command {
public:
    void command_add_attribute(int param_1, int param_2, float param_3);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* commands;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;

    unsigned char command_add_attribute(int param_1, float param_2);
};
#endif

unsigned char RGE_Player::command_add_attribute(int param_1, float param_2) {
    if ((param_1 != -1) && (param_2 != 0.0f)) {
        this->world->command->command_add_attribute((int)this->id, param_1, param_2);
        return 1;
    }
    return 0;
}
