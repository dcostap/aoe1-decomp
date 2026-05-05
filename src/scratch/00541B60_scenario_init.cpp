// VA: 00541B60 RGE_Game_World::scenario_init(int, RGE_Game_World*)
// PDB source: World.cpp lines 820-822 (96 bytes, 29 asm lines)
// FLAGS: /GX
//
// __thiscall: this in ecx, 2 stack params. ret 8 cleanup.
// SEH-framed, allocates RGE_Scenario (0x1990 bytes), constructs if non-null,
// stores at this->scenario (+0x5C).
//
// 86/96 edit-match bytes. Same null-path shared-epilogue issue as
// 005414A0, 00541BC0, 0052E920: original has jmp+shared tail for null path,
// VC5 generates separate epilogue per path. 15-byte edit diff.
//
// SEH handler address differs (relocation masked).
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
