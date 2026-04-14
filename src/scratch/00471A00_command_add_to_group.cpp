class RGE_Command_catg {
public:
    void command_add_to_group(int player, int a, int b, int c);
};

class RGE_Game_World_catg {
public:
    char gap_00[0x58];
    RGE_Command_catg* command;
};

class RGE_Player_catg {
public:
    unsigned char command_add_to_group(int a, int b, int c);
    char gap_00[0x3C];
    RGE_Game_World_catg* world;
    char gap_40[0x0A];
    short player_id;
};

unsigned char RGE_Player_catg::command_add_to_group(int a, int b, int c) {
    int pid = (int)this->player_id;
    this->world->command->command_add_to_group(pid, a, b, c);
    return 1;
}
