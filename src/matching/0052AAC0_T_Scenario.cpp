// MATCHED 2026-05-19. FLAGS: /nologo /c /O2 /GX
// Key fixes: make the base class visibly polymorphic (`virtual ~RGE_Scenario`) so VC5 emits the
// original constructor EH/unwind frame and base-at-zero call shape. Use a small `for (int i=0; i<3; i++)`
// to clear ScenarioOptions; direct repeated stores made VC5 keep ECX as `this`, while the loop source
// collapses to the original `xor ecx,ecx` plus three ECX-based stores before reloading ECX for the final call.

class RGE_Game_World;
class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    RGE_Scenario(RGE_Game_World*);
};

class T_Scenario : public RGE_Scenario {
public:
    virtual ~T_Scenario();

    void InitializePlayerValues();
    void InitializeVictoryValues();
    void InitializeFriendlinessValues();
    void ClearDisabledTechnologies();

    char gap_0004[0x4BE4];
    int victory_all_flag;
    int is_multi_player_flag;
    int which_player;
    char gap_4BF4[0x50F4 - 0x4BF4];
    int ScenarioOptions[3];
    char gap_5100[0x5140 - 0x5100];
    int mp_victory_type;
    int victory_score;
    int victory_time;

    T_Scenario(RGE_Game_World* world);
};

T_Scenario::T_Scenario(RGE_Game_World* world)
    : RGE_Scenario(world) {
    InitializePlayerValues();
    InitializeVictoryValues();
    InitializeFriendlinessValues();
    mp_victory_type = 0;
    victory_score = 900;
    victory_time = 9000;
    victory_all_flag = 0;
    which_player = 0;
    for (int i = 0; i < 3; i++) {
        ScenarioOptions[i] = 0;
    }
    ClearDisabledTechnologies();
}
