class RGE_Command_cr {
public:
    void command_resign(int player, int a, int b);
};

class RGE_Game_World_cr {
public:
    char gap_00[0x58];
    RGE_Command_cr* command;
};

class RGE_Player_cr {
public:
    unsigned char command_resign(int a, int b);
    char gap_00[0x3C];
    RGE_Game_World_cr* world;
    char gap_40[0x0A];
    short player_id;
    char gap_4C[0x34];
    unsigned char game_over;
};

unsigned char RGE_Player_cr::command_resign(int a, int b) {
    if (this->game_over) return 0;
    int pid = (int)this->player_id;
    this->world->command->command_resign(pid, a, b);
    return 1;
}
