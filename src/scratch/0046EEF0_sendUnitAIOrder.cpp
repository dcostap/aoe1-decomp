// tried a direct nested call through this->world->commands; VC5 inserted an ESI save and a different stack frame
// tried a local commands pointer; codegen stayed in the same wrong basin and started materializing extra float/mask setup
// remaining mismatch is prolog/argument-shuffle drift at the start of the wrapper, not the call target or parameter count
class RGE_Command {
public:
    void command_ai_order(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, unsigned char param_10, unsigned char param_11, unsigned char param_12, unsigned char param_13);
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

    void sendUnitAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12);
};

void RGE_Player::sendUnitAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12)
{
    RGE_Command* commands;

    commands = this->world->commands;
    commands->command_ai_order(param_1, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, (unsigned char)param_10, (unsigned char)param_11, (unsigned char)param_12);
}
