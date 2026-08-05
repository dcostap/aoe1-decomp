// VA 00514720 TRIBE_Player::aiStatus(int)
// tplayer.cpp:1804-1928
// Canonical ownership: TRIBE_Player.playerAI (TribeMainDecisionAIModule* @ +0x238)
// holds buildAI (+0x104), constructionAI (+0x6C4), diplomacyAI (+0x9DC),
// resourceAI (+0x10D7C), strategyAI (+0x10E74), tacticalAI (+0x1146C).
// The world/players/ConCP/CurCP chain uses RGE_Game_World.players (+0x40),
// currentUpdateComputerPlayer (+0xFC), TRIBE_World.controllingComputerPlayer
// (+0x11D), and the other player's tacticalAI last/average update-area times.
//
// Attempt log:
// - baseline: natural sprintf status-line switch; direct member access everywhere.
// - case 2 ResDiff pairs must be resourceName(neededResource(r)), resourceDifference(r)
//   (names derive from neededResource, not resourceDifference); fixed 4 call-site repls.
// - carrying tac/res/dip pointer locals made VC5 skip the per-call [esi+238h] reload;
//   direct this->playerAI->sub.module access restored the original reload pattern.
// - case 0/6: named last/avg locals force the pre-call callee-saved loads the original
//   has (otherAI in eax consumed before updateAreaName, last/avg in ebx/ebp).
// - DiplomacyAIModule must be 0x103A0 (resourceAI at +0x10D7C carries a 0x10000).
// - TRIBE_World byte field at +0x11D needs a flat overlay: VC5 inheritance would align
//   the first derived field to the base's aligned size (0x120), not 0x11D.
// - case 6 exact basin needs last/avg declared BEFORE attackEnabled so last wins the
//   sole remaining callee-saved register (ebp) and attackEnabled is homed to the stack
//   slot, matching the original push/spill schedule.

extern "C" int sprintf(char*, const char*, ...);

class RGE_Game_World;
class RGE_Player;
class TRIBE_Player;

class BuildAIModule {
public:
    virtual ~BuildAIModule();
    char gap_04[0x5B8];
    char* buildListName();
    int buildListLength();
    int numberItemsIntoBuildList();
    char* lastBuildItemRequested();
    char* nextBuildItemRequested();
    char* currentBuildItemRequested();
};

class TribeBuildAIModule : public BuildAIModule {
public:
    void* md;   // +0x5BC
};

class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    char gap_04[0x314];
    char* constructionPlanName();
};

class DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    char gap_04[0x1039C];
    int stance(int player_id, int type);
};

class TribeResourceAIModule {
public:
    char gap_00[0xF8];
    char* resourceName(int resource_type);
};

class TribeStrategyAIModule {
public:
    char gap_00[0x5F8];
    char* ruleSetName();
};

class TribeTacticalAIModule {
public:
    char gap_00[0xE18];
    int attackEnabledValue;              // +0xE18
    unsigned int updateArea;             // +0xE1C
    char gap_E20[0x1DC];
    int lastUpdateAreaTimeValue;         // +0xFFC
    int averageUpdateAreaTimeValue;      // +0x1000
    int updateAreaAverageCount;          // +0x1004
    int updateAreaAverageTotal;          // +0x1008

    char* updateAreaName();
    int strategicNumber(int index);
    int resourceDifference(int index);
    int neededResource(int index);
    int neededResourceAmount(int index);
    int numberBoats();
    int numberSoldiers();
    int numberCivilians();
    int desiredGathererCount(int index);
    int actualGathererCount(int index);
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0x104];
    TribeBuildAIModule buildAI;              // +0x104
    ConstructionAIModule constructionAI;     // +0x6C4
    DiplomacyAIModule diplomacyAI;           // +0x9DC
    TribeResourceAIModule resourceAI;        // +0x10D7C
    TribeStrategyAIModule strategyAI;        // +0x10E74
    TribeTacticalAIModule tacticalAI;        // +0x1146C
};

class RGE_Game_World {
public:
    char gap_000[0x3C];
    short player_num;                        // +0x3C
    RGE_Player** players;                    // +0x40
    char gap_044[0xB8];
    int currentUpdateComputerPlayer;         // +0xFC
    char gap_100[0x1D];
};

class TRIBE_World {
public:
    char gap_000[0x11D];
    unsigned char controllingComputerPlayer; // +0x11D (flat overlay; VC5 inheritance would align to 0x120)
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;                   // +0x3C
    char gap_40[0x1F8];
    TribeMainDecisionAIModule* playerAI;     // +0x238
    char aiStatusInformationValue[0x100];    // +0x23C
    char aiStatusInformationValue2[0x100];   // +0x33C
    char aiStatusInformationValue3[0x100];   // +0x43C
    char aiStatusInformationValue4[0x100];   // +0x53C
    char aiStatusInformationValue5[0x100];   // +0x63C
    char aiStatusInformationValue6[0x100];   // +0x73C
};

class TRIBE_Player : public RGE_Player {
public:
    char* aiStatus(int param_1);
};

char* TRIBE_Player::aiStatus(int param_1)
{
    if (this->playerAI == 0) {
        if (this->world->currentUpdateComputerPlayer != -1) {
            RGE_Player* otherPlayer = this->world->players[this->world->currentUpdateComputerPlayer];
            if (otherPlayer != 0) {
                TribeMainDecisionAIModule* ai = ((TRIBE_Player*)otherPlayer)->playerAI;
                int last = ai->tacticalAI.lastUpdateAreaTimeValue;
                int avg = ai->tacticalAI.averageUpdateAreaTimeValue;
                sprintf(this->aiStatusInformationValue,
                    "ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms=%3d, UA=%s.",
                    ((TRIBE_World*)this->world)->controllingComputerPlayer,
                    this->world->currentUpdateComputerPlayer,
                    avg,
                    last,
                    ai->tacticalAI.updateAreaName());
                return this->aiStatusInformationValue;
            }
        }
        return "Invalid currentUpdateComputerPlayer...";
    }
    if (param_1 == 1) {
        sprintf(this->aiStatusInformationValue,
            "Build List:%s, City Plan:%s, BuildAI(C=%s, N=%s, L=%s, %d/%d).",
            this->playerAI->buildAI.buildListName(),
            this->playerAI->constructionAI.constructionPlanName(),
            this->playerAI->buildAI.currentBuildItemRequested(),
            this->playerAI->buildAI.nextBuildItemRequested(),
            this->playerAI->buildAI.lastBuildItemRequested(),
            this->playerAI->buildAI.numberItemsIntoBuildList(),
            this->playerAI->buildAI.buildListLength());
        return this->aiStatusInformationValue;
    }
    if (param_1 == 2) {
        sprintf(this->aiStatusInformationValue2,
            "NeedRes: %s=%d, %s=%d, %s=%d, %s=%d, ResDiff: %s=%d, %s=%d, %s=%d, %s=%d.",
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(0)), this->playerAI->tacticalAI.neededResourceAmount(0),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(1)), this->playerAI->tacticalAI.neededResourceAmount(1),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(2)), this->playerAI->tacticalAI.neededResourceAmount(2),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(3)), this->playerAI->tacticalAI.neededResourceAmount(3),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(0)), this->playerAI->tacticalAI.resourceDifference(0),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(1)), this->playerAI->tacticalAI.resourceDifference(1),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(2)), this->playerAI->tacticalAI.resourceDifference(2),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(3)), this->playerAI->tacticalAI.resourceDifference(3));
        return this->aiStatusInformationValue2;
    }
    if (param_1 == 3) {
        sprintf(this->aiStatusInformationValue3,
            "Gat(Act/Des): %s=(%d/%d), %s=(%d/%d), %s=(%d/%d), %s=(%d/%d).  #Civs=%d, #Sol=%d, #Boats=%d.",
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(0)), this->playerAI->tacticalAI.actualGathererCount(0), this->playerAI->tacticalAI.desiredGathererCount(0),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(1)), this->playerAI->tacticalAI.actualGathererCount(1), this->playerAI->tacticalAI.desiredGathererCount(1),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(2)), this->playerAI->tacticalAI.actualGathererCount(2), this->playerAI->tacticalAI.desiredGathererCount(2),
            this->playerAI->resourceAI.resourceName(this->playerAI->tacticalAI.neededResource(3)), this->playerAI->tacticalAI.actualGathererCount(3), this->playerAI->tacticalAI.desiredGathererCount(3),
            this->playerAI->tacticalAI.numberCivilians(), this->playerAI->tacticalAI.numberSoldiers(), this->playerAI->tacticalAI.numberBoats());
        return this->aiStatusInformationValue3;
    }
    if (param_1 == 4) {
        sprintf(this->aiStatusInformationValue4,
            "Pers (Spec/BL): Food=(%d/%d), Wood=(%d/%d), Gold=(%d/%d), Stone=(%d/%d).",
            this->playerAI->tacticalAI.strategicNumber(0x75),
            this->playerAI->tacticalAI.strategicNumber(0x9C),
            this->playerAI->tacticalAI.strategicNumber(0x78),
            this->playerAI->tacticalAI.strategicNumber(0x9D),
            this->playerAI->tacticalAI.strategicNumber(0x76),
            this->playerAI->tacticalAI.strategicNumber(0x9F),
            this->playerAI->tacticalAI.strategicNumber(0x77),
            this->playerAI->tacticalAI.strategicNumber(0x9E));
        return this->aiStatusInformationValue4;
    }
    if (param_1 == 5) {
        sprintf(this->aiStatusInformationValue5,
            "Dip: P1(%d/%d/%d), P2(%d/%d/%d), P3(%d/%d/%d), P4(%d/%d/%d), P5(%d/%d/%d), P6(%d/%d/%d), P7(%d/%d/%d), P8(%d/%d/%d).",
            this->playerAI->diplomacyAI.stance(1, 0), this->playerAI->diplomacyAI.stance(1, 1), this->playerAI->diplomacyAI.stance(1, 2),
            this->playerAI->diplomacyAI.stance(2, 0), this->playerAI->diplomacyAI.stance(2, 1), this->playerAI->diplomacyAI.stance(2, 2),
            this->playerAI->diplomacyAI.stance(3, 0), this->playerAI->diplomacyAI.stance(3, 1), this->playerAI->diplomacyAI.stance(3, 2),
            this->playerAI->diplomacyAI.stance(4, 0), this->playerAI->diplomacyAI.stance(4, 1), this->playerAI->diplomacyAI.stance(4, 2),
            this->playerAI->diplomacyAI.stance(5, 0), this->playerAI->diplomacyAI.stance(5, 1), this->playerAI->diplomacyAI.stance(5, 2),
            this->playerAI->diplomacyAI.stance(6, 0), this->playerAI->diplomacyAI.stance(6, 1), this->playerAI->diplomacyAI.stance(6, 2),
            this->playerAI->diplomacyAI.stance(7, 0), this->playerAI->diplomacyAI.stance(7, 1), this->playerAI->diplomacyAI.stance(7, 2),
            this->playerAI->diplomacyAI.stance(8, 0), this->playerAI->diplomacyAI.stance(8, 1), this->playerAI->diplomacyAI.stance(8, 2));
        return this->aiStatusInformationValue5;
    }
    if (param_1 == 6) {
        // last/avg must be declared before attackEnabled so VC5 keeps `last` in ebp and
        // homes attackEnabled to the stack slot (original push/spill schedule).
        TribeMainDecisionAIModule* ai =
            ((TRIBE_Player*)this->world->players[this->world->currentUpdateComputerPlayer])->playerAI;
        int last = ai->tacticalAI.lastUpdateAreaTimeValue;
        int avg = ai->tacticalAI.averageUpdateAreaTimeValue;
        int attackEnabled = this->playerAI->tacticalAI.attackEnabledValue;
        sprintf(this->aiStatusInformationValue6,
            "Per: %s, AttEnab=%d, AttDly=%d Min, ConCP=%d, CurCP=%d, AveUAms=%3d, LastUAms=%3d, UA=%s.",
            this->playerAI->strategyAI.ruleSetName(),
            attackEnabled,
            this->playerAI->tacticalAI.strategicNumber(0x68) / 60,
            ((TRIBE_World*)this->world)->controllingComputerPlayer,
            this->world->currentUpdateComputerPlayer,
            avg,
            last,
            ai->tacticalAI.updateAreaName());
        return this->aiStatusInformationValue6;
    }
    return "Invalid status line number.";
}
