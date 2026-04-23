// tried the natural ctor shape with direct member stores and helper calls; default flags were undersized
// tried a fuller virtual surface; that kicked the function out of the right basin, so the current lead is the simpler destructor-only /GX shape
// remaining mismatch to resolve later, if resumed, is the early ctor/vftable/store ordering around the first state writes

class RGE_Game_World;
class RGE_Scenario {
public:
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
    ScenarioOptions[0] = 0;
    ScenarioOptions[1] = 0;
    ScenarioOptions[2] = 0;
    ClearDisabledTechnologies();
}
