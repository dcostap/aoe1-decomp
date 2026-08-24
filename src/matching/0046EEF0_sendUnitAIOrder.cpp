// tried a direct nested call through this->world->commands; VC5 inserted an ESI save and a different stack frame
// tried a local commands pointer; codegen stayed in the same wrong basin and started materializing extra float/mask setup
// remaining mismatch is prolog/argument-shuffle drift at the start of the wrapper, not the call target or parameter count
// attempt 2: no pointer locals, params 10-12 as ints (not unsigned char), param_1 duplicated
#ifndef PLAYER_GROUPED_TU
class RGE_Command {
public:
    // need correct signature based on observed push pattern
    void command_ai_order(int A, int B, int C, int D, int E, int F, int G, int H, int I, int J, int K, int L, int M);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* command;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;

    void sendUnitAIOrder(int p1, int p2, int p3, int p4, int p5, float p6, float p7, float p8, float p9, int p10, int p11, int p12);
};
#endif

void RGE_Player::sendUnitAIOrder(int p1, int p2, int p3, int p4, int p5, float p6, float p7, float p8, float p9, int p10, int p11, int p12)
{
    this->world->command->command_ai_order(p1, p1, p2, p3, p4, p5, *(int*)&p6, *(int*)&p7, *(int*)&p8, *(int*)&p9, p10, p11, p12);
}
