// VA: 00515E00 TRIBE_Player::intelligentBuildListAndRulesSelection
// First-pass source from packet/decompiler, with binary-observed local layout notes.
// Attempt log:
// - 2026-05-30: built a full behavioral skeleton through the random personality/rule setup tail.
//   check_function compiles and keeps the same 6631-byte length, but remains a broad mismatch
//   (5628/6631 positional bytes; first drift is register allocation/prologue: rebuilt keeps
//   `this` in EBX and zero in EBP vs original EBP/ESI). Fixed the reduction loop to the
//   binary-observed 7 fixed passes; current mismatch is 5616/6631 positional bytes.
//   Needs source-shape/register-pressure work.
// - 2026-08-13: baseline check retained the named TRIBE_Player civ_id/playerAI ownership,
//   125-entry weight array, and tplayer.cpp source family (7560 strict-diff bytes, 8320 body).
// - 2026-08-13: typed the same-TU AI-module layout and changed history logging to the
//   AIModule member surface. The source is more canonical, but codegen moved farther
//   (7657 strict-diff bytes, 8336 body); no shared files changed.
// - 2026-08-13: restored the common final difficulty rule call and retained the original
//   no-call path for difficulty values outside 0..3. The emitted call-count gap remains.
// - 2026-08-13: diagnostic raw tplayer pointer/module declarations improved the strict
//   diff to 7560 and size to 8320, but kept the same missing setRule call and broad CFG
//   drift. A player alias emitted identical code. Both were rolled back to this typed
//   source because the raw form did not prove canonical ownership or exact behavior.
// Notes:
// - The packet's decompiler folds the saved game difficulty into buildLists[0]; the
//   real stack has `gameDifficulty` at +0x14 and `buildLists[125]` at +0x18.
//   BL(n) below maps decompiler buildLists[n] references to the real zero-based
//   build-list weight array by subtracting one.
// - Uses fixed-address globals/strings for the known tplayer.cpp counters and log text.

#include <string.h>

typedef unsigned char uchar;

#define rge_base_game (*(RGE_Base_Game_00515E00**)0x0062C574)
#define computerPlayerSetup (*(int*)0x00886C18)
#define DAT_00886c1c (*(int*)0x00886C1C)
#define DAT_00886c20 (*(int*)0x00886C20)
#define DAT_00886c24 (*(int*)0x00886C24)
#define DAT_00886c28 (*(int*)0x00886C28)
#define DAT_00886c2c (*(int*)0x00886C2C)
#define DAT_00886c30 (*(int*)0x00886C30)
#define DAT_00886c34 (*(int*)0x00886C34)
#define DAT_00886c38 (*(int*)0x00886C38)
#define DAT_00886c3c (*(int*)0x00886C3C)
#define DAT_00886c40 (*(int*)0x00886C40)
#define DAT_00886c44 (*(int*)0x00886C44)
#define DAT_00886c48 (*(int*)0x00886C48)
#define allowAIToCheat (*(int*)0x0057F9F0)

#define S_TPLAYER_CPP ((char*)0x0058AC44)
#define S_RANDOM_GAME_SPECIALIZED ((char*)0x0058AF78)
#define S_SETTING_AI_PERSONALITY ((char*)0x0058B130)
#define S_SELECTED_BEST_BUILD_LIST ((char*)0x0058B148)
#define S_I_AM_THE_CIV ((char*)0x0058B16C)

extern int __cdecl debug_rand(char* file, int line);

class RGE_Base_Game_00515E00 {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void get_string(int id, char* dst, int len);
    int difficulty();
    uchar deathMatch();
};

class AIModule_00515E00 {
public:
    virtual ~AIModule_00515E00();
    char gap_04[0xEC];
    void logCommonHistory(char* fmt, ...);
};

class TribeInformationAIModule_00515E00 {
public:
    virtual ~TribeInformationAIModule_00515E00();
    char gap_04[0x1008C];
    void loadUnitHistory();
    void unitsThatAreMostBuilt(int* difficultyLevel, int* mostBuiltUnit);
};

class TribeBuildAIModule_00515E00 {
public:
    virtual ~TribeBuildAIModule_00515E00();
    char gap_04[0x5BC];
};

class TribeConstructionAIModule_00515E00 {
public:
    virtual ~TribeConstructionAIModule_00515E00();
    char gap_04[0x314];
};

class DiplomacyAIModule_00515E00 {
public:
    virtual ~DiplomacyAIModule_00515E00();
    char gap_04[0x14C];
};

class EmotionalAIModule_00515E00 {
public:
    virtual ~EmotionalAIModule_00515E00();
    char gap_04[0x1BC];
};

class TribeResourceAIModule_00515E00 {
public:
    virtual ~TribeResourceAIModule_00515E00();
    char gap_04[0xF4];
};

class TribeStrategyAIModule_00515E00 {
public:
    virtual ~TribeStrategyAIModule_00515E00();
    char gap_04[0x5F4];
    int rule(int id);
    void setRule(int id, int value);
};

class TribeMainDecisionAIModule_00515E00 : public AIModule_00515E00 {
public:
    char gap_base[0x14];
    TribeBuildAIModule_00515E00 buildAI;
    TribeConstructionAIModule_00515E00 constructionAI;
    DiplomacyAIModule_00515E00 diplomacyAI;
    EmotionalAIModule_00515E00 emotionalAI;
    TribeInformationAIModule_00515E00 informationAI;
    TribeResourceAIModule_00515E00 resourceAI;
    TribeStrategyAIModule_00515E00 strategyAI;
};

class RGE_Player_00515E00 {
public:
    virtual ~RGE_Player_00515E00();
    char gap_04[0x101];
    uchar civ_id; // +0x105
    char gap_106[0x11A];
};

class TRIBE_Player : public RGE_Player_00515E00 {
public:
    char gap_220[0x18];
    TribeMainDecisionAIModule_00515E00* playerAI; // +0x238

    void setupEgyptian(int* weights, int mapType, int victoryType, int mapSize);
    void setupGreek(int* weights, int mapType, int victoryType, int mapSize);
    void setupBabylonian(int* weights, int mapType, int victoryType, int mapSize);
    void setupAssyrian(int* weights, int mapType, int victoryType, int mapSize);
    void setupMinoan(int* weights, int mapType, int victoryType, int mapSize);
    void setupHittite(int* weights, int mapType, int victoryType, int mapSize);
    void setupPhoenician(int* weights, int mapType, int victoryType, int mapSize);
    void setupSumerian(int* weights, int mapType, int victoryType, int mapSize);
    void setupPersian(int* weights, int mapType, int victoryType, int mapSize);
    void setupShang(int* weights, int mapType, int victoryType, int mapSize);
    void setupYamato(int* weights, int mapType, int victoryType, int mapSize);
    void setupChoson(int* weights, int mapType, int victoryType, int mapSize);
    void setupRoman(int* weights, int mapType, int victoryType, int mapSize);
    void setupCarthaginian(int* weights, int mapType, int victoryType, int mapSize);
    void setupPalmyran(int* weights, int mapType, int victoryType, int mapSize);
    void setupMacedonian(int* weights, int mapType, int victoryType, int mapSize);

    void intelligentBuildListAndRulesSelection(char* buildListName, char* ruleSetName,
                                               int mapType, int victoryType, int mapSize);
};

#define SET_RULE(rule_id, value) this->playerAI->strategyAI.setRule((rule_id), (value))
#define GET_RULE(rule_id) this->playerAI->strategyAI.rule((rule_id))
#define BL(n) buildLists[(n) - 1]
#define DIV3_POS(x) do { if ((x) > 0) { (x) = (x) / 3; } } while (0)
#define SIGN_MASK_MOD(v, mask) ((((((v) ^ ((v) >> 31)) - ((v) >> 31)) & (mask)) ^ ((v) >> 31)) - ((v) >> 31))

void TRIBE_Player::intelligentBuildListAndRulesSelection(char* buildListName, char* ruleSetName,
                                                         int mapType, int victoryType, int mapSize)
{
    int difficultyLevel;
    int gameDifficulty;
    int buildLists[125];
    int mostBuiltUnit1;
    char tempString[256];

    if (this->playerAI == 0) {
        return;
    }

    gameDifficulty = rge_base_game->difficulty();
    memset(buildLists, 0, sizeof(buildLists));

    switch (this->civ_id) {
    case 1:  this->setupEgyptian(buildLists, mapType, victoryType, mapSize); break;
    case 2:  this->setupGreek(buildLists, mapType, victoryType, mapSize); break;
    case 3:  this->setupBabylonian(buildLists, mapType, victoryType, mapSize); break;
    case 4:  this->setupAssyrian(buildLists, mapType, victoryType, mapSize); break;
    case 5:  this->setupMinoan(buildLists, mapType, victoryType, mapSize); break;
    case 6:  this->setupHittite(buildLists, mapType, victoryType, mapSize); break;
    case 7:  this->setupPhoenician(buildLists, mapType, victoryType, mapSize); break;
    case 8:  this->setupSumerian(buildLists, mapType, victoryType, mapSize); break;
    case 9:  this->setupPersian(buildLists, mapType, victoryType, mapSize); break;
    case 10: this->setupShang(buildLists, mapType, victoryType, mapSize); break;
    case 11: this->setupYamato(buildLists, mapType, victoryType, mapSize); break;
    case 12: this->setupChoson(buildLists, mapType, victoryType, mapSize); break;
    case 13: this->setupRoman(buildLists, mapType, victoryType, mapSize); break;
    case 14: this->setupCarthaginian(buildLists, mapType, victoryType, mapSize); break;
    case 15: this->setupPalmyran(buildLists, mapType, victoryType, mapSize); break;
    case 16: this->setupMacedonian(buildLists, mapType, victoryType, mapSize); break;
    }

    if (rge_base_game->deathMatch() == 0) {
        int civ = this->civ_id - 1;
        if (civ == 3 || civ == 0 || civ == 1 || civ == 4 || civ == 8 ||
            civ == 6 || civ == 7 || civ == 10) {
            if (mapType == 0) {
                if (DAT_00886c44 < 1) {
                    BL(0x0E) = 0;
                    BL(0x0F) = 0;
                } else if (DAT_00886c48 == 0) {
                    BL(0x0E) += 300;
                    BL(0x0F) += 300;
                } else {
                    BL(0x0E) += 100;
                    BL(0x0F) += 100;
                }
            }
            if (mapType == 1) {
                if (DAT_00886c44 < 1) {
                    BL(0x0E) = 0;
                    BL(0x0F) = 0;
                } else if (DAT_00886c48 == 0) {
                    BL(0x0E) += 250;
                    BL(0x0F) += 250;
                } else {
                    BL(0x0E) += 75;
                    BL(0x0F) += 75;
                }
            }
            if (mapType == 2 || mapType == 6 || mapType == 8) {
                if (DAT_00886c44 < 1) {
                    BL(0x0E) = 0;
                    BL(0x0F) = 0;
                } else if (DAT_00886c48 == 0) {
                    BL(0x0E) += 200;
                    BL(0x0F) += 200;
                } else {
                    BL(0x0E) += 50;
                    BL(0x0F) += 50;
                }
            }
        }
    }

    SET_RULE(0xC9, 1);

    if (rge_base_game->deathMatch() == 0) {
        difficultyLevel = -1;
        mostBuiltUnit1 = -1;
        this->playerAI->informationAI.loadUnitHistory();
        this->playerAI->informationAI.unitsThatAreMostBuilt(&difficultyLevel, &mostBuiltUnit1);
        switch (difficultyLevel) {
        case 0:
            BL(7) += 25;
            BL(8) += 25;
            break;
        case 1:
            BL(7) += 30;
            BL(8) += 30;
            break;
        case 2:
            BL(0x13) += 20;
            BL(0x12) += 20;
            BL(4) += 40;
            BL(5) += 40;
            break;
        case 3:
            BL(1) += 40;
            BL(0x12) -= 60;
            BL(0x13) -= 60;
            BL(2) += 20;
            BL(0x14) += 20;
            BL(0x15) += 20;
            break;
        case 4:
            BL(7) += 15;
            BL(8) += 15;
            BL(0x15) += 20;
            BL(0x14) += 20;
            break;
        case 5:
            BL(7) += 15;
            BL(8) += 15;
            BL(1) += 10;
            BL(2) += 10;
            break;
        case 6:
            BL(7) += 15;
            BL(8) += 15;
            break;
        case 7:
        case 10:
            BL(0x15) -= 60;
            BL(0x14) -= 60;
            break;
        case 8:
            BL(0x14) += 40;
            BL(0x15) += 40;
            if (DAT_00886c44 > 0) {
                BL(0x0E) += 50;
                BL(0x0F) += 50;
            }
            break;
        case 9:
            BL(0x15) += 100;
            BL(0x14) += 100;
            break;
        }
    }

    difficultyLevel = 0;
    do {
        switch (difficultyLevel) {
        case 0:
            DIV3_POS(BL(0x14));
            DIV3_POS(BL(0x15));
            DIV3_POS(BL(0x16));
            break;
        case 1:
            DIV3_POS(BL(7));
            DIV3_POS(BL(8));
            DIV3_POS(BL(9));
            DIV3_POS(BL(0x3C));
            DIV3_POS(BL(0x3B));
            DIV3_POS(BL(0x37));
            DIV3_POS(BL(0x38));
            DIV3_POS(BL(0x69));
            break;
        case 2:
            DIV3_POS(BL(0x11));
            DIV3_POS(BL(0x32));
            DIV3_POS(BL(0x6D));
            break;
        case 3:
            DIV3_POS(BL(0x2F));
            DIV3_POS(BL(0x36));
            DIV3_POS(BL(0x12));
            DIV3_POS(BL(0x13));
            DIV3_POS(BL(100));
            DIV3_POS(BL(0x67));
            DIV3_POS(BL(0x6E));
            DIV3_POS(BL(0x13));
            break;
        case 4:
            DIV3_POS(BL(4));
            DIV3_POS(BL(5));
            DIV3_POS(BL(6));
            DIV3_POS(BL(10));
            DIV3_POS(BL(0x0D));
            DIV3_POS(BL(0x66));
            DIV3_POS(BL(0x62));
            DIV3_POS(BL(0x63));
            DIV3_POS(BL(0x5F));
            DIV3_POS(BL(0x60));
            DIV3_POS(BL(0x61));
            DIV3_POS(BL(0x46));
            DIV3_POS(BL(0x47));
            DIV3_POS(BL(0x48));
            DIV3_POS(BL(0x6B));
            DIV3_POS(BL(0x6C));
            DIV3_POS(BL(0x51));
            DIV3_POS(BL(0x52));
            DIV3_POS(BL(0x53));
            DIV3_POS(BL(0x54));
            DIV3_POS(BL(0x72));
            DIV3_POS(BL(0x73));
            DIV3_POS(BL(0x75));
            break;
        case 5:
            DIV3_POS(BL(7));
            DIV3_POS(BL(8));
            DIV3_POS(BL(9));
            DIV3_POS(BL(0x3C));
            DIV3_POS(BL(0x3B));
            DIV3_POS(BL(0x33));
            DIV3_POS(BL(0x3A));
            DIV3_POS(BL(0x5E));
            DIV3_POS(BL(0x34));
            DIV3_POS(BL(0x35));
            DIV3_POS(BL(0x2E));
            DIV3_POS(BL(0x3E));
            DIV3_POS(BL(0x3F));
            DIV3_POS(BL(0x40));
            DIV3_POS(BL(0x3D));
            DIV3_POS(BL(0x41));
            DIV3_POS(BL(0x42));
            DIV3_POS(BL(0x43));
            DIV3_POS(BL(0x49));
            DIV3_POS(BL(0x4A));
            DIV3_POS(BL(0x4B));
            DIV3_POS(BL(0x4C));
            DIV3_POS(BL(0x4D));
            DIV3_POS(BL(0x4E));
            DIV3_POS(BL(0x55));
            DIV3_POS(BL(0x56));
            DIV3_POS(BL(0x57));
            DIV3_POS(BL(0x74));
            DIV3_POS(BL(0x76));
            DIV3_POS(BL(0x77));
            DIV3_POS(BL(0x78));
            DIV3_POS(BL(0x7D));
            break;
        case 6:
            DIV3_POS(BL(0x11));
            DIV3_POS(BL(0x32));
            DIV3_POS(BL(0x6D));
            DIV3_POS(BL(0x59));
            DIV3_POS(BL(0x5A));
            DIV3_POS(BL(0x5C));
            break;
        }
        ++difficultyLevel;
    } while (difficultyLevel < 7);

    int total = 0;
    for (difficultyLevel = 0; difficultyLevel < 125; ++difficultyLevel) {
        if (buildLists[difficultyLevel] < 0) {
            buildLists[difficultyLevel] = 0;
        }
        total += buildLists[difficultyLevel];
    }

    int randomValue = debug_rand(S_TPLAYER_CPP, 0xC41);
    int remainder = randomValue % total;
    int selectedBuildList = 0;
    int cumulative = 0;
    for (difficultyLevel = 0; difficultyLevel < 125; ++difficultyLevel) {
        cumulative += buildLists[difficultyLevel];
        if (cumulative > remainder) {
            selectedBuildList = difficultyLevel;
            break;
        }
    }

    rge_base_game->get_string(selectedBuildList + 0x26930, buildListName, 0x100);

    int countSelectedAsCommon = 1;
    switch (selectedBuildList) {
    case 0:
    case 1:
    case 2:
    case 0x29:
    case 0x32:
    case 0x33:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x6B:
        ++DAT_00886c2c;
        break;
    case 6:
    case 7:
    case 8:
    case 0x2B:
    case 0x36:
    case 0x37:
    case 0x3A:
    case 0x3B:
    case 0x68:
        ++DAT_00886c1c;
        break;
    case 0x0D:
    case 0x0E:
    case 0x0F:
        SET_RULE(0x3B, 4);
        SET_RULE(0x3C, 10);
        ++DAT_00886c34;
        ++DAT_00886c48;
        countSelectedAsCommon = 0;
        break;
    case 0x10:
    case 0x31:
    case 0x6C:
        ++DAT_00886c20;
        break;
    case 0x11:
    case 0x12:
    case 0x2E:
    case 0x34:
    case 0x35:
    case 99:
    case 0x66:
    case 0x6D:
        ++DAT_00886c24;
        break;
    case 0x13:
    case 0x14:
    case 0x15:
        ++computerPlayerSetup;
        break;
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
        break;
    case 0x28:
    case 0x39:
    case 0x54:
    case 0x72:
        ++DAT_00886c30;
        break;
    case 0x3C:
    case 0x3D:
    case 0x3E:
    case 0x3F:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
    case 0x53:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5A:
    case 0x5B:
    case 0x5C:
    case 0x5D:
    case 0x5E:
    case 0x5F:
    case 0x60:
    case 0x61:
    case 100:
    case 0x65:
    case 0x69:
    case 0x6A:
    case 0x6E:
    case 0x6F:
    case 0x73:
    case 0x74:
    case 0x79:
    case 0x7A:
    case 0x7B:
    case 0x7C:
        ++DAT_00886c48;
        countSelectedAsCommon = 0;
        break;
    case 0x48:
    case 0x49:
        ++DAT_00886c44;
        ++DAT_00886c2c;
        countSelectedAsCommon = 0;
        break;
    case 0x4A:
        ++DAT_00886c44;
        ++DAT_00886c28;
        countSelectedAsCommon = 0;
        break;
    default:
        ++DAT_00886c28;
        break;
    }
    if (countSelectedAsCommon != 0) {
        ++DAT_00886c44;
    }

    rge_base_game->get_string((int)this->civ_id + 0x27F6, tempString, 0x100);
    this->playerAI->logCommonHistory(S_I_AM_THE_CIV, tempString, (int)this->civ_id - 1);
    this->playerAI->logCommonHistory(S_SELECTED_BEST_BUILD_LIST, buildListName);
    strcpy(ruleSetName, S_RANDOM_GAME_SPECIALIZED);
    this->playerAI->logCommonHistory(S_SETTING_AI_PERSONALITY);

    int workingMapType = mapType;
    switch (victoryType) {
    case 0:
    case 1:
        SET_RULE(0x36, 5);
        SET_RULE(0x37, 5);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        workingMapType = GET_RULE(1);
        if (workingMapType < 1) {
            SET_RULE(0, 0x32);
            workingMapType = 0x32;
        } else {
            SET_RULE(0, 0x32);
            SET_RULE(1, 0x19);
            workingMapType = 0x19;
        }
        SET_RULE(2, workingMapType);
        if (mapType > 1) {
            SET_RULE(3, 5);
        }
        SET_RULE(0x2A, 2);
        SET_RULE(0x3D, 2);
        workingMapType = mapType;
        if (victoryType != 2) {
            SET_RULE(0x26, mapSize + 1);
            SET_RULE(0x24, 1);
            if (victoryType == 3) {
                SET_RULE(0x36, 1);
            } else {
                SET_RULE(0x36, 5);
            }
            if (victoryType == 4) {
                SET_RULE(0x37, 1);
            } else {
                SET_RULE(0x37, 5);
            }
        }
        break;
    }

    if (rge_base_game->deathMatch() == 1) {
        SET_RULE(4, 10);
    }

    int attackTime = (debug_rand(S_TPLAYER_CPP, 0xE3A) % 12 + 0x1C) * 60;
    switch (selectedBuildList) {
    case 0:
    case 3:
    case 0x0B:
    case 0x0C:
    case 0x0D:
    case 0x13:
    case 0x2F:
    case 0x30:
    case 0x33:
    case 0x37:
    case 0x39:
    case 0x48:
    case 0x4A:
    case 0x4B:
    case 0x4E:
    case 0x51:
    case 0x55:
    case 0x58:
    case 0x5A:
    case 0x5E:
    case 0x60:
    case 100:
    case 0x69:
    case 0x6E:
    case 0x73:
        ++DAT_00886c3c;
        attackTime = (debug_rand(S_TPLAYER_CPP, 0xE58) % 6 + 0x14) * 60;
        break;
    case 9:
    case 0x38:
        randomValue = debug_rand(S_TPLAYER_CPP, 0xE69);
        attackTime = (SIGN_MASK_MOD(randomValue, 1) + 5) * 60;
        ++DAT_00886c38;
        break;
    case 10:
    case 0x29:
    case 0x2B:
    case 0x2C:
    case 0x2D:
    case 0x32:
    case 0x3A:
    case 0x71:
        ++DAT_00886c38;
        randomValue = debug_rand(S_TPLAYER_CPP, 0xE64);
        attackTime = (SIGN_MASK_MOD(randomValue, 3) + 0x0B) * 60;
        break;
    default:
        ++DAT_00886c40;
        break;
    }

    int difficultyCopy = gameDifficulty;
    if (gameDifficulty == 0 && debug_rand(S_TPLAYER_CPP, 0xE73) % 3 == 0) {
        attackTime -= 300;
    }
    SET_RULE(0x68, attackTime);
    SET_RULE(0x10, 2);
    SET_RULE(0x1A, 10);
    SET_RULE(0x5D, 1);
    SET_RULE(99, 4);

    SET_RULE(0xBC, (debug_rand(S_TPLAYER_CPP, 0xE80) % 3 != 0));
    SET_RULE(0xC3, debug_rand(S_TPLAYER_CPP, 0xE86) % 0x28 + 10);
    SET_RULE(0xBD, debug_rand(S_TPLAYER_CPP, 0xE8A) % 0x46 + 0x1E);
    SET_RULE(0xC6, (debug_rand(S_TPLAYER_CPP, 0xE8E) % 5 + 5) * gameDifficulty);
    SET_RULE(0xC7, (debug_rand(S_TPLAYER_CPP, 0xE92) % 10 + 10) * gameDifficulty);
    SET_RULE(0xA1, 4);

    int adjustedMapSize = mapSize;
    if (workingMapType == 0) {
        adjustedMapSize -= 2;
    } else if (workingMapType == 1) {
        adjustedMapSize -= 1;
    }

    int nextGoal = 0;
    switch (adjustedMapSize) {
    case -2:
    case -1:
        randomValue = debug_rand(S_TPLAYER_CPP, 0xEA2);
        SET_RULE(0x49, SIGN_MASK_MOD(randomValue, 1) + 0x0E);
        randomValue = debug_rand(S_TPLAYER_CPP, 0xEA4);
        nextGoal = GET_RULE(0x49) + 1 + SIGN_MASK_MOD(randomValue, 3);
        break;
    case 0:
        randomValue = debug_rand(S_TPLAYER_CPP, 0xEA7);
        SET_RULE(0x49, SIGN_MASK_MOD(randomValue, 1) + 0x0F);
        randomValue = debug_rand(S_TPLAYER_CPP, 0xEA9);
        nextGoal = GET_RULE(0x49) + 1 + SIGN_MASK_MOD(randomValue, 3);
        break;
    case 1:
        SET_RULE(0x49, debug_rand(S_TPLAYER_CPP, 0xEAC) % 3 + 0x10);
        nextGoal = GET_RULE(0x49) + 1 + debug_rand(S_TPLAYER_CPP, 0xEAE) % 5;
        break;
    case 2:
        randomValue = debug_rand(S_TPLAYER_CPP, 0xEB1);
        SET_RULE(0x49, SIGN_MASK_MOD(randomValue, 1) + 0x11);
        nextGoal = GET_RULE(0x49) + 1 + debug_rand(S_TPLAYER_CPP, 0xEB3) % 6;
        break;
    case 3:
        randomValue = debug_rand(S_TPLAYER_CPP, 0xEB6);
        SET_RULE(0x49, SIGN_MASK_MOD(randomValue, 1) + 0x12);
        nextGoal = GET_RULE(0x49) + 1 + debug_rand(S_TPLAYER_CPP, 0xEB8) % 7;
        break;
    case 4:
        randomValue = debug_rand(S_TPLAYER_CPP, 0xEBB);
        SET_RULE(0x49, SIGN_MASK_MOD(randomValue, 3) + 0x12);
        randomValue = debug_rand(S_TPLAYER_CPP, 0xEBD);
        nextGoal = GET_RULE(0x49) + 1 + SIGN_MASK_MOD(randomValue, 7);
        break;
    default:
        randomValue = debug_rand(S_TPLAYER_CPP, 0xEC1);
        SET_RULE(0x49, SIGN_MASK_MOD(randomValue, 1) + 0x12);
        nextGoal = GET_RULE(0x49) + 1 + debug_rand(S_TPLAYER_CPP, 0xEC3) % 9;
        break;
    }
    SET_RULE(0x4A, nextGoal);
    SET_RULE(0xD0, 1);
    SET_RULE(0xD1, 1);
    SET_RULE(0xD2, 1);
    SET_RULE(0xDF, 1);

    if (workingMapType == 0) {
        SET_RULE(0xD4, 3);
        SET_RULE(0xD5, 6);
        SET_RULE(0xD6, 2);
        SET_RULE(0xE0, 6);
    } else if (workingMapType == 1) {
        SET_RULE(0xD4, 2);
        SET_RULE(0xD5, 5);
        SET_RULE(0xD6, 2);
        SET_RULE(0xE0, 4);
    } else if (workingMapType == 2 || workingMapType == 6 || workingMapType == 5 || workingMapType == 8) {
        SET_RULE(0xD4, 1);
        SET_RULE(0xD5, 4);
        SET_RULE(0xD6, 1);
        SET_RULE(0xE0, 3);
    } else if (workingMapType == 3 || workingMapType == 4 || workingMapType == 7) {
        SET_RULE(0xD4, 0);
        SET_RULE(0xD5, 0);
        SET_RULE(0xD6, 0);
        SET_RULE(0xE0, 0);
    }

    if (allowAIToCheat != 0) {
        int cheatFood = 0;
        int cheatWood = 0;
        int cheatStone = 0;
        int cheatGold = 0;
        if (difficultyCopy == 0) {
            cheatFood = 2000;
            cheatWood = 2000;
            cheatStone = 2000;
            cheatGold = 2000;
        }
        SET_RULE(0x8A, cheatFood);
        SET_RULE(0x8B, cheatWood);
        SET_RULE(0x8C, cheatStone);
        SET_RULE(0x8D, cheatGold);
        gameDifficulty = difficultyCopy;
    }

    SET_RULE(0xA8, 0);
    SET_RULE(0xA2, 0);
    if (gameDifficulty < 3) {
        SET_RULE(0xC2, 1);
        workingMapType = 2;
    } else {
        SET_RULE(0xC2, 0);
        workingMapType = 1;
    }
    SET_RULE(0x2F, workingMapType);

    int difficultyRuleValue;
    if (gameDifficulty == 0) {
        SET_RULE(0xBA, 0xB4);
        difficultyRuleValue = 200;
    } else if (gameDifficulty == 1) {
        SET_RULE(0xBA, 0xB4);
        difficultyRuleValue = 0x96;
    } else if (gameDifficulty == 2) {
        SET_RULE(0xBA, 0xB4);
        difficultyRuleValue = 100;
    } else if (gameDifficulty == 3) {
        SET_RULE(0xBA, 0xB4);
        difficultyRuleValue = 0x32;
    }
    if (gameDifficulty >= 0 && gameDifficulty <= 3) {
        SET_RULE(0xBA, difficultyRuleValue);
    }

    SET_RULE(0xB5, (debug_rand(S_TPLAYER_CPP, 0xF50) % 6 < 5));
    SET_RULE(0xB6, (debug_rand(S_TPLAYER_CPP, 0xF56) % 3 < 1));
}
