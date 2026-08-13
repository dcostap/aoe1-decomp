// 005153D0 TRIBE_Player::loadAIInformation
// Attempt log:
// try 1: direct packet/Ghidra reconstruction: 3x 256-byte name buffers, debug-rand save/restore, AI file selection/loading, personality/rules/build-list setup, diplomacy loops; compile failed on VC5 __thiscall vtable typedefs.
// try 2: changed vtable typedefs to __stdcall; default /O2 too small (.text 1424 vs 1514).
// try 3: inlined empty-string strcpy calls and added the two original resource get_string calls; default /O2 improved to .text 1472 vs 1514 but still too small.
// try 4: diagnostic impossible saveRand/save_debug_random_on == -1 log branches only to force exact-size compare; exact-size 1514/1514 but broad mismatch 83.5535% positional / 94.8481% edit, first mismatch +27 around saveRand/save_debug_random_on stack scheduling; diagnostic branches rolled back.
// try 5: /GX on diagnostic source no change; rolled back.
// try 6: /Od diagnostic exact-size but worse debug-basin mismatch 86.3276% positional / 169.5509% edit; rolled back.
// typed ABI probe: restored the canonical RGE_Player/World/Scenario offsets,
// AIModule and embedded AI-module surfaces, TRIBE_Game getters, virtual
// get_string/build-loader calls, direct strategy/emotional/information calls,
// and the enemy-before-ally diplomacy predicate order.  This recovered exact
// frame size, all 42 ordered calls, and a 1514-byte rebuilt body; the current
// structural best is 1281 strict-diff bytes with 89.56% edit/resync similarity.
// city-plan probe: duplicated the binary-backed custom/no-city construction
// argument setup in the two source arms, which restored original size and
// call-site parity; a shared-tail/goto variant was worse and was rolled back.
// remaining localized drift: VC5 stores the saved debug-random global before
// the local home (the oracle does the reverse), the map-switch branch spans
// differ, and the no-city/final learn tails have small block-layout shifts.
// left in scratch: no custom flags or compiler-steering scaffolding retained.
// shardB6 probe: typed save-local/global assignment chain left emitted order unchanged; restored clean source.
// luna probe: split save-random declarations and tested volatile/direct-global variants; VC5 kept the
// saved-global store before the local home or added reload/cleanup code, so all variants were rolled back.
// luna probe: inverted and nested the construction-rule guard, then tested an explicit custom-arm jump;
// VC5 retained the same custom-first block layout.  Natural if/else source remains authoritative.
// luna probe: the oracle scans learn_info with strlen before loadLearnInfo; replacing `*learn` with strlen
// improved strict diff 1281->1279, exact blocks 78.04%->79.53%, and resync similarity 89.56%->90.62%.

typedef unsigned char uchar;

class RGE_Player;

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
    void logCommonHistory(char* fmt, ...);
};

class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40();
    virtual int load(char*, RGE_Player*);
    char gap_04[0x5BC];
};

class TribeConstructionAIModule {
public:
    virtual ~TribeConstructionAIModule();
    virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void load(char*, int, int, int, int, int);
    char gap_04[0x314];
};

class DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    char gap_04[0x14C];
    void setStance(int, int, int);
    void setChangeable(int, uchar);
};

class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    char gap_04[0x1BC];
    void setOverallState(int);
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0x1008C];
    void loadLearnInfo(char*);
};

class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    char gap_04[0xF4];
};

class TribeStrategyAIModule {
public:
    virtual ~TribeStrategyAIModule();
    char gap_04[0x5F4];
    int loadRules(char*);
    void setDifficultyLevel(int);
};

class TribeMainDecisionAIModule : public AIModule {
public:
    char gap_base[0x14];
    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;
    DiplomacyAIModule diplomacyAI;
    EmotionalAIModule emotionalAI;
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    TribeStrategyAIModule strategyAI;

    void updateBuildAIWithObjects();
};

class RGE_Map {
public:
    void* vtable_ptr;
    void* tiles;
    int map_width;
    int map_height;
};

class RGE_Scenario {
public:
    void* vtable_ptr;
    char gap_04[0x100C];
    char* learn_info;
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2C[0x10];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0x18];
    RGE_Scenario* scenario;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C();
    virtual void get_string(int, char*, int);
    int difficulty();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int mapSize();
    int mapType();
    int victoryType();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);

    char gap_04[0x1E];
    short master_object_num;
    void* master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    RGE_Game_World* world;
    void* doppleganger_creator;
    char* name;
    uchar type;
    uchar gap_49;
    short id;
    char gap_4C[0x1D4];
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_220[0x18];
    TribeMainDecisionAIModule* playerAI;

    void intelligentBuildListAndRulesSelection(char*, char*, int, int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
};

extern "C" int __cdecl debug_rand(char*, int);
extern "C" void __cdecl debug_srand(char*, int, int);
extern "C" void* __cdecl strcpy(void*, const void*);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" unsigned int __cdecl strlen(const char*);

#define debug_random_on (*(int*)0x0062C4D4)
#define saved_debug2 (*(int*)0x0086BC94)
#define base_game (*(TRIBE_Game**)0x0062C574)

void TRIBE_Player::loadAIInformation(char* aiFile, char* ruleFile, char* personalityFile, int buildId, int unused)
{
    char noneString[256];
    char randomString[256];
    char ruleSetName[256];
    char buildListName[256];

    int saveRand;
    int save_debug_random_on;
    saveRand = debug_rand((char*)0x58AC44, 0x863);
    save_debug_random_on = debug_random_on;
    saved_debug2 = save_debug_random_on;
    debug_random_on = 0;

    if (this->playerAI) {
        switch (base_game->mapType()) {
        case 0: this->playerAI->logCommonHistory((char*)0x58B114); break;
        case 1: this->playerAI->logCommonHistory((char*)0x58B0F8); break;
        case 2: this->playerAI->logCommonHistory((char*)0x58B0D8); break;
        case 3: this->playerAI->logCommonHistory((char*)0x58B0BC); break;
        case 4: this->playerAI->logCommonHistory((char*)0x58B0A0); break;
        default: this->playerAI->logCommonHistory((char*)0x58B060); break;
        }
        base_game->get_string(0x2775, noneString, 0x100);
        base_game->get_string(0x277B, randomString, 0x100);

        strcpy(buildListName, (const void*)0x592A40);
        strcpy(ruleSetName, (const void*)0x592A40);

        if (aiFile) {
            if (strcmp(aiFile, randomString) == 0) {
                do {
                    this->intelligentBuildListAndRulesSelection(buildListName, ruleSetName,
                        base_game->mapType(), base_game->victoryType(), base_game->mapSize());
                    this->playerAI->logCommonHistory((char*)0x58B034, buildListName);
                } while (this->playerAI->buildAI.load(buildListName, this) == 0);
            } else {
                this->playerAI->logCommonHistory((char*)0x58B01C, aiFile);
                this->playerAI->buildAI.load(aiFile, this);
            }
        } else {
            do {
                this->intelligentBuildListAndRulesSelection(buildListName, ruleSetName,
                    base_game->mapType(), base_game->victoryType(), base_game->mapSize());
                this->playerAI->logCommonHistory((char*)0x58AFFC, buildListName);
            } while (this->playerAI->buildAI.load(buildListName, this) == 0);
        }

        if (ruleFile && strcmp(ruleFile, randomString) != 0) {
            this->playerAI->logCommonHistory((char*)0x58AFA8, ruleFile);
            this->playerAI->constructionAI.load(ruleFile,
                this->world->map->map_width, this->world->map->map_height, 0, 0, 0);
        } else {
            this->playerAI->logCommonHistory((char*)0x58AFC0);
            this->playerAI->constructionAI.load((char*)0x57F350,
                this->world->map->map_width, this->world->map->map_height, 0, 0, 0);
        }

        if (personalityFile && strcmp(personalityFile, randomString) != 0) {
            this->playerAI->logCommonHistory((char*)0x58AF90, personalityFile);
            this->playerAI->strategyAI.loadRules(personalityFile);
        } else if (strcmp(ruleSetName, (const char*)0x58AF78) != 0) {
            this->playerAI->logCommonHistory((char*)0x58AF4C, ruleSetName);
            this->playerAI->strategyAI.loadRules(ruleSetName);
        } else {
            this->playerAI->logCommonHistory((char*)0x58AF10);
        }

        int r = base_game->difficulty();
        this->playerAI->logCommonHistory((char*)0x58AEF0, r);
        this->playerAI->strategyAI.setDifficultyLevel(r);
        this->playerAI->updateBuildAIWithObjects();

        for (int i = 1; i < this->world->player_num; ++i) {
            if (i == this->id) {
                this->playerAI->diplomacyAI.setStance(i, 0, 0);
                this->playerAI->diplomacyAI.setStance(i, 2, 100);
            } else if (this->isEnemy(i)) {
                this->playerAI->diplomacyAI.setStance(i, 0, 0x4A);
                this->playerAI->diplomacyAI.setStance(i, 2, 0x18);
            } else if (this->isAlly(i)) {
                this->playerAI->diplomacyAI.setStance(i, 0, 0x18);
                this->playerAI->diplomacyAI.setStance(i, 2, 0x4A);
            }
        }

        for (int j = 1; j < this->world->player_num; ++j) {
            if (!this->isEnemy(j) && !this->isAlly(j))
                this->playerAI->diplomacyAI.setChangeable(j, 1);
            else
                this->playerAI->diplomacyAI.setChangeable(j, 0);
        }

        this->playerAI->emotionalAI.setOverallState(buildId);
        char* learn = this->world->scenario->learn_info;
        if (learn && strlen(learn) != 0) this->playerAI->informationAI.loadLearnInfo(learn);
    }

    debug_random_on = save_debug_random_on;
    debug_srand((char*)0x58AC44, 0x8FD, saveRand);
}
