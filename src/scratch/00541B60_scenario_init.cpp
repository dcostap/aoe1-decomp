// World.cpp:820-822, 96 bytes
// attempt 1: 64 bytes, class size 0x1990 too compact
// attempt 2: 48 bytes, small class too compact
// attempt 3: 48 bytes, extern ctor too compact
// attempt 4: 59.4%, new RGE_Scenario, class size 4
// attempt 5: 21.9%, class size 0x1990, fail path order diff
// attempt 6: 21.9%, source shape change no help
// attempt 7: 48 bytes, manual operator new too small
// BEST: 21.9% (attempts 5,6). BLOCKER: original fail path has
//   jmp/xor eax/mov [esi+5ch],eax before EH teardown; rebuilt skips this.
// FLAGS: /GX
class RGE_Game_World;

class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_04[0x1990 - 0x04];
    RGE_Scenario(int, RGE_Game_World*);
};

class RGE_Game_World {
public:
    char gap_00[0x5C];
    RGE_Scenario* scenario;  // +0x5C

    void scenario_init(int param1, RGE_Game_World* param2);
};

void RGE_Game_World::scenario_init(int param1, RGE_Game_World* param2) {
    RGE_Scenario* p = new RGE_Scenario(param1, param2);
    scenario = p;
}
