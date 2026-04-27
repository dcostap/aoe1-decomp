// World.cpp:852-854, 89 bytes
// attempt 1: 23.6%, same null-store basin as 00541B60
// BEST: 23.6%. BLOCKER: identical to 00541B60 - original fail path has
//   jmp/xor eax/mov [esi+58h],eax before EH teardown; rebuilt new expression
//   skips this store. All other bytes match.
// FLAGS: /GX
class RGE_Game_World;

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[0x18 - 0x04];
    RGE_Command(RGE_Game_World*, void*);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* command;  // +0x58

    void command_init(int param1, void* param2);
};

void RGE_Game_World::command_init(int param1, void* param2) {
    RGE_Command* p = new RGE_Command(this, param2);
    command = p;
}
