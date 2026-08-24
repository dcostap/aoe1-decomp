// 005153D0 TRIBE_Player::loadAIInformation
// Source recovery notes:
// - PDB module: tplayer.cpp, lines 2145-2302. The owner is TRIBE_Player.
// - The typed baseline had the exact frame, size, symbol, and 42 ordered calls.
// - The baseline had 808 positional byte differences.
// - The nested city-plan form restored the original block order and merged call tail.
// - The PDB-named debug globals restored the original local-store and global-store order.
// - A compact city-plan if/else produced 799 byte differences.
// - Absolute debug-global expressions produced nine byte differences.
// - A saved-global alias was incidental. The disabled local declarations were incidental.
// - Final validation: Result: MATCH, 0.0000%.

#include <string.h>
#include "../../include/tplayer_context.h"

// BINARY NOTE: Object declarations preserve the original local-store and global-store order.
#undef debug_random_on
extern int debug_random_on;
extern int global_save_debug_random_on2;

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
    global_save_debug_random_on2 = save_debug_random_on;
    debug_random_on = 0;

    if (this->playerAI) {
        switch (tribe_game->mapType()) {
        case 0: this->playerAI->logCommonHistory((char*)0x58B114); break;
        case 1: this->playerAI->logCommonHistory((char*)0x58B0F8); break;
        case 2: this->playerAI->logCommonHistory((char*)0x58B0D8); break;
        case 3: this->playerAI->logCommonHistory((char*)0x58B0BC); break;
        case 4: this->playerAI->logCommonHistory((char*)0x58B0A0); break;
        default: this->playerAI->logCommonHistory((char*)0x58B060); break;
        }
        base_game->get_string(0x2775, noneString, 0x100);
        base_game->get_string(0x277B, randomString, 0x100);

        strcpy(buildListName, (const char*)0x592A40);
        strcpy(ruleSetName, (const char*)0x592A40);

        if (aiFile) {
            if (strcmp(aiFile, randomString) == 0) {
                do {
                    this->intelligentBuildListAndRulesSelection(buildListName, ruleSetName,
                        tribe_game->mapType(), tribe_game->victoryType(), tribe_game->mapSize());
                    this->playerAI->logCommonHistory((char*)0x58B034, buildListName);
                } while (this->playerAI->buildAI.load(buildListName, this) == 0);
            } else {
                this->playerAI->logCommonHistory((char*)0x58B01C, aiFile);
                this->playerAI->buildAI.load(aiFile, this);
            }
        } else {
            do {
                this->intelligentBuildListAndRulesSelection(buildListName, ruleSetName,
                    tribe_game->mapType(), tribe_game->victoryType(), tribe_game->mapSize());
                this->playerAI->logCommonHistory((char*)0x58AFFC, buildListName);
            } while (this->playerAI->buildAI.load(buildListName, this) == 0);
        }

        // BINARY NOTE: This shape preserves two default log paths and one shared construction call.
        if (ruleFile) {
            if (strcmp(ruleFile, randomString) == 0) {
                this->playerAI->logCommonHistory((char*)0x58AFC0);
            } else {
                this->playerAI->logCommonHistory((char*)0x58AFA8, ruleFile);
                this->playerAI->constructionAI.load(ruleFile,
                    this->world->map->map_width, this->world->map->map_height, 0, 0, 0);
                goto constructionLoaded;
            }
        } else {
            this->playerAI->logCommonHistory((char*)0x58AFC0);
        }
        this->playerAI->constructionAI.load((char*)0x57F350,
            this->world->map->map_width, this->world->map->map_height, 0, 0, 0);

    constructionLoaded:

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
