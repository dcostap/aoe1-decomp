class RGE_Command_cta {
public:
    void command_trade_attribute(int a, int player, int b);
};

class RGE_Game_World_cta {
public:
    char gap_00[0x58];
    RGE_Command_cta* command;
};

class TRIBE_Player_cta {
public:
    unsigned char command_trade_attribute(int a, int b);
    char gap_00[0x3C];
    RGE_Game_World_cta* world;
    char gap_40[0x0A];
    short player_id;
};

unsigned char TRIBE_Player_cta::command_trade_attribute(int a, int b) {
    int pid = (int)this->player_id;
    this->world->command->command_trade_attribute(a, pid, b);
    return 1;
}
