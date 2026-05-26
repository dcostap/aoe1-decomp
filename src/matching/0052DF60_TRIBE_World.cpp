// VA: 0052DF60 TRIBE_World ctor
// tworld.cpp

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Game_World();
};

class AIPlayBook {
public:
    int loadPlays(char* filename);
};

class TribeAIPlayBook : public AIPlayBook {
public:
    char gap[0x50];
    TribeAIPlayBook();
};

char data_aoe_ply[] = "data\\aoe.ply";

class __declspec(novtable) TRIBE_World : public RGE_Game_World {
public:
    char gap_004[0x9C];
    AIPlayBook* playBook;
    char gap_0A4[0x60];
    int tech;
    int victory_type;
    int artifact_count;
    int ruin_count;
    char countdown_victory;
    char gap_115[3];
    int countdown_clock;
    char score_displayed;
    char controllingComputerPlayer;
    char gap_11E[2];
    int sent_zone_score;

    virtual ~TRIBE_World();
    TRIBE_World();
};

TRIBE_World::TRIBE_World() {
    controllingComputerPlayer = -1;
    *(int*)this = 0x577458;
    tech = 0;
    victory_type = 0;
    artifact_count = 0;
    ruin_count = 0;
    sent_zone_score = 0;
    countdown_victory = 0;
    countdown_clock = 0;
    score_displayed = 0;

    TribeAIPlayBook* pb = new TribeAIPlayBook;
    playBook = pb;
    if (pb) {
        pb->loadPlays(data_aoe_ply);
    }
}
