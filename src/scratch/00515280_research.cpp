class RGE_Command_rsr {
public:
    void command_research(int player, int a, int b, int c);
};

class RGE_Game_World_rsr {
public:
    char gap_00[0x58];
    RGE_Command_rsr* command;
};

class TRIBE_Player_rsr {
public:
    void research(int a, int b, int c);
    char gap_00[0x3C];
    RGE_Game_World_rsr* world;
    char gap_40[0x0A];
    short player_id;
};

void TRIBE_Player_rsr::research(int a, int b, int c) {
    int pid = (int)this->player_id;
    this->world->command->command_research(pid, a, b, c);
}
