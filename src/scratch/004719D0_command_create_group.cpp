class RGE_Command_ccg {
public:
    void command_create_group(int player, int a, int b, int c, int d);
};

class RGE_Game_World_ccg {
public:
    char gap_00[0x58];
    RGE_Command_ccg* command;
};

class RGE_Player_ccg {
public:
    unsigned char command_create_group(int a, int b, int c, int d);
    char gap_00[0x3C];
    RGE_Game_World_ccg* world;
    char gap_40[0x0A];
    short player_id;
};

unsigned char RGE_Player_ccg::command_create_group(int a, int b, int c, int d) {
    int pid = (int)this->player_id;
    this->world->command->command_create_group(pid, a, b, c, d);
    return 1;
}
