// 004F5FB0 TribeTacticalAIModule::evaluateBuildListInsertions
// taitacmd.cpp:6194-6250, 327 bytes
//
// Attempt log:
// - Baseline was a raw-offset/free-helper scaffold (217 bytes) with the wrong
//   build calls and no typed checkForBuildInsertion surface.
// - Probe 1: reconstructed the named same-TU tactical/main-decision,
//   build/resource/information/player/world ownership and the natural nested
//   insertion guards. This recovered 327 bytes and all nine ordered calls but
//   initially placed the strategic-number array 0x60 bytes too high.
// - Probe 2: corrected the tactical prefix so sn[0xCD]/[0xA9]/[0xAF]/[0xB0]
//   own the proven +0x4C8/+0x438/+0x450/+0x454 fields; only the resourceAI
//   displacement remained three bytes off.
// - Probe 3: restored the full 0x10090 informationAI size, moving resourceAI
//   to +0x10D7C and producing an exact 327-byte match with default flags.
// - The two gotos retain binary-proven shared granary/queue tails; all data and
//   calls remain named typed members rather than raw-offset plumbing.

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    char gap_04[0x5BC];

    int haveBuildList();
    int insert(int type, int count, int priority);
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0x53C];
    int closestDropsiteValue[4];
    char gap_550[0x10];
    int numberFoundForestTilesValue;
    char gap_564[0x10090 - 0x564];
};

class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    char gap_04[0xF4];

    int resource(int type);
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    char gap_F4[0x10];
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    char gap_6C4[0xCEC - 0x6C4];
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    char gap_F4[0xA0];
    int sn[226];
    char gap_51C[0xF88 - 0x51C];
    int builtFirstStoragePit;
    int builtFirstGranary;

    void checkForBuildInsertion(int type, int count, int priority);
    void evaluateBuildListInsertions();
};

void TribeTacticalAIModule::evaluateBuildListInsertions()
{
    int one = 1;

    if (this->sn[0xCD] == one) {
        if (this->md->buildAI.haveBuildList() != 0 &&
            this->builtFirstStoragePit == 0 &&
            this->md->informationAI.numberFoundForestTilesValue >= this->sn[0xA9]) {
            this->md->buildAI.insert(0x67, one, 0);
            this->builtFirstStoragePit = one;
        }

        if (this->sn[0xCD] == one) {
            if (this->md->buildAI.haveBuildList() != 0 &&
                this->builtFirstGranary == 0) {
                if (this->builtFirstStoragePit != one &&
                    this->md->resourceAI.resource(one) < 250) {
                    goto check_granary;
                }

                if (this->md->informationAI.closestDropsiteValue[0] != -1) {
                    this->md->buildAI.insert(0x44, one, one);
                    this->builtFirstGranary = one;
                    goto after_granary;
                }
            }
        }
    }

check_granary:
    if (this->builtFirstGranary == one)
        this->checkForBuildInsertion(0x44, one, 0);

after_granary:
    int insertID = this->sn[0xAF];
    if (insertID != -1 &&
        this->sn[0xB0] <=
            this->md->player->world->world_time / 60000) {
        this->md->buildAI.insert(insertID, one, 0);
        this->sn[0xAF] = -1;
    }

    this->checkForBuildInsertion(0x32, one, 0);
    this->checkForBuildInsertion(0x4F, one, 0);
}
