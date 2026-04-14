class RGE_Command_sgo {
public:
    void sendCommand(int cmd_type, int* params, int a, int b, int c);
};

class RGE_Game_World_sgo {
public:
    char gap_00[0x58];
    RGE_Command_sgo* command;
};

class RGE_Player_sgo {
public:
    void sendGameOrder(int a, int b, int c, int d);
    char gap_00[0x3C];
    RGE_Game_World_sgo* world;
};

void RGE_Player_sgo::sendGameOrder(int a, int b, int c, int d) {
    // original: stores a into [esp+4] then loads from stack
    // The original rearranges params and calls via world->command
    this->world->command->sendCommand(1, &a, b, c, d);
}
