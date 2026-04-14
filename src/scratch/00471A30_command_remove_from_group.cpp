class RGE_Command_crfg {
public:
    void command_remove_from_group(int player, int a, int b);
};

class RGE_Game_World_crfg {
public:
    char gap_00[0x58];
    RGE_Command_crfg* command;
};

class RGE_Player_crfg {
public:
    unsigned char command_remove_from_group(int a, int b);
    char gap_00[0x3C];
    RGE_Game_World_crfg* world;
    char gap_40[0x0A];
    short player_id;
};

unsigned char RGE_Player_crfg::command_remove_from_group(int a, int b) {
    int pid = (int)this->player_id;
    this->world->command->command_remove_from_group(pid, a, b);
    return 1;
}
