class RGE_Command_tu {
public:
    void command_make(int player, int a, int b, int c);
};

class RGE_Game_World_tu {
public:
    char gap_00[0x58];
    RGE_Command_tu* command;
};

class TRIBE_Player_tu {
public:
    void trainUnit(int a, int b, int c);
    char gap_00[0x3C];
    RGE_Game_World_tu* world;
    char gap_40[0x0A];
    short player_id;
};

void TRIBE_Player_tu::trainUnit(int a, int b, int c) {
    int pid = (int)this->player_id;
    this->world->command->command_make(pid, b, a, c);
}
