#include "../include/DiplomacyAIModule.h"

#include "../include/AIModule.h"
#include "../include/MainDecisionAIModule.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Victory_Conditions.h"
#include "../include/globals.h"

#include <new>

namespace {
char kDiplomacyAIName[] = "Diplomacy AI";
}

// Offset: 0x0040BEC0
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040BEC0
DiplomacyAIModule::DiplomacyAIModule(void* param_1, int param_2) {
    new ((AIModule*)this) AIModule(kDiplomacyAIName, 0x3EB, param_2, param_1);
    this->md = nullptr;
    for (int i = 0; i < 10; ++i) {
        this->dislikeTable[i] = 0x31;
        this->likeTable[i] = 0x31;
        this->changeableTable[i] = '\x01';
    }
}

// Offset: 0x0040BF40
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040BF40
DiplomacyAIModule::DiplomacyAIModule(int param_1, int param_2) {
    new ((AIModule*)this) AIModule(kDiplomacyAIName, 0x3EB, param_1, nullptr);
    this->md = nullptr;
    for (int i = 0; i < 10; ++i) {
        rge_read(param_2, &this->dislikeTable[i], 4);
        rge_read(param_2, &this->likeTable[i], 4);
        rge_read(param_2, &this->changeableTable[i], 1);
    }
}

// Offset: 0x0040BFF0
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040BFF0
DiplomacyAIModule::~DiplomacyAIModule() {
    ((AIModule*)this)->~AIModule();
}

// TODO: Header model declares explicit overrides; forward to AIModule base behavior.
int DiplomacyAIModule::loggingHistory() {
    return ((AIModule*)this)->loggingHistory();
}

void DiplomacyAIModule::setLogHistory(int param_1) {
    ((AIModule*)this)->setLogHistory(param_1);
}

void DiplomacyAIModule::toggleLogHistory() {
    ((AIModule*)this)->toggleLogHistory();
}

void DiplomacyAIModule::setHistoryFilename(char* param_1) {
    ((AIModule*)this)->setHistoryFilename(param_1);
}

int DiplomacyAIModule::loggingCommonHistory() {
    return ((AIModule*)this)->loggingCommonHistory();
}

void DiplomacyAIModule::setLogCommonHistory(int param_1) {
    ((AIModule*)this)->setLogCommonHistory(param_1);
}

void DiplomacyAIModule::toggleLogCommonHistory() {
    ((AIModule*)this)->toggleLogCommonHistory();
}

int DiplomacyAIModule::loadState(char* param_1) {
    return ((AIModule*)this)->loadState(param_1);
}

int DiplomacyAIModule::saveState(char* param_1) {
    return ((AIModule*)this)->saveState(param_1);
}

int DiplomacyAIModule::gleanState(int param_1) {
    return ((AIModule*)this)->gleanState(param_1);
}

int DiplomacyAIModule::processMessage(AIModuleMessage* param_1) {
    return ((AIModule*)this)->processMessage(param_1);
}

void DiplomacyAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    ((AIModule*)this)->setCallbackMessage(param_1);
}

int DiplomacyAIModule::filterOutMessage(AIModuleMessage* param_1) {
    return ((AIModule*)this)->filterOutMessage(param_1);
}

// Offset: 0x0040C000
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C000
void DiplomacyAIModule::setMainDecisionAI(MainDecisionAIModule* param_1) {
    this->md = param_1;
}

// Offset: 0x0040C010
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C010
int DiplomacyAIModule::update(int param_1) {
    (void)param_1;
    int i = 1;
    RGE_Player* player = this->md->player;
    if (1 < player->world->player_num) {
        do {
            if (i != player->id) {
                if (isAlly(i) != 0 && isAlliedWithMe(i) == 0) {
                    changeStance(i, 0, 1);
                }
                if (isAlly(i) == 0 && isAlliedWithMe(i) != 0) {
                    changeStance(i, 2, 1);
                }
            }
            i = i + 1;
            player = this->md->player;
        } while (i < player->world->player_num);
    }
    return 1;
}

// Offset: 0x0040C0A0
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C0A0
int DiplomacyAIModule::save(int param_1) {
    for (int i = 0; i < 10; ++i) {
        rge_write(param_1, &this->dislikeTable[i], 4);
        rge_write(param_1, &this->likeTable[i], 4);
        rge_write(param_1, &this->changeableTable[i], 1);
    }
    return 1;
}

// Offset: 0x0040C100
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C100
int DiplomacyAIModule::stance(int param_1, int param_2) const {
    if ((0 < param_1) && (param_1 < this->md->player->world->player_num)) {
        if (param_2 == 0) {
            return this->dislikeTable[param_1];
        }
        if (param_2 == 1) {
            int dislike_delta = 0x31 - this->dislikeTable[param_1];
            if (dislike_delta < 0) {
                dislike_delta = -dislike_delta;
            }
            int like_delta = 0x31 - this->likeTable[param_1];
            if (like_delta < 0) {
                like_delta = -like_delta;
            }
            int value = (100 - dislike_delta) - like_delta;
            if (-1 < value) {
                return value;
            }
            return 0;
        }
        if (param_2 == 2) {
            return this->likeTable[param_1];
        }
    }
    return -1;
}

// Offset: 0x0040C190
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C190
void DiplomacyAIModule::changeStance(int param_1, int param_2, int param_3) {
    if ((0 < param_1) && (param_1 < this->md->player->world->player_num)) {
        if (param_2 == 0) {
            int value = this->dislikeTable[param_1] + param_3;
            this->dislikeTable[param_1] = value;
            if (this->changeableTable[param_1] == '\0') {
                if (value < 0x32) {
                    this->dislikeTable[param_1] = 0x32;
                    return;
                }
                if (100 < value) {
                    this->dislikeTable[param_1] = 100;
                }
            } else {
                if (value < 0) {
                    this->dislikeTable[param_1] = 0;
                    return;
                }
                if (100 < value) {
                    this->dislikeTable[param_1] = 100;
                    return;
                }
            }
        } else if (param_2 == 2) {
            int value = this->likeTable[param_1] + param_3;
            this->likeTable[param_1] = value;
            if (this->changeableTable[param_1] == '\0') {
                if (value < 0) {
                    this->likeTable[param_1] = 0;
                    return;
                }
                if (0x30 < value) {
                    this->likeTable[param_1] = 0x30;
                    return;
                }
            } else {
                if (value < 0) {
                    this->likeTable[param_1] = 0;
                    return;
                }
                if (100 < value) {
                    this->likeTable[param_1] = 100;
                    return;
                }
            }
        }
    }
}

// Offset: 0x0040C2B0
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C2B0
void DiplomacyAIModule::setStance(int param_1, int param_2, int param_3) {
    if ((0 < param_1) && (param_1 < this->md->player->world->player_num)) {
        if (param_2 == 0) {
            this->dislikeTable[param_1] = param_3;
            if (this->changeableTable[param_1] == '\0') {
                if (param_3 < 0x32) {
                    this->dislikeTable[param_1] = 0x32;
                    return;
                }
                if (100 < param_3) {
                    this->dislikeTable[param_1] = 100;
                }
            } else {
                if (param_3 < 0) {
                    this->dislikeTable[param_1] = 0;
                    return;
                }
                if (100 < param_3) {
                    this->dislikeTable[param_1] = 100;
                    return;
                }
            }
        } else if (param_2 == 2) {
            this->likeTable[param_1] = param_3;
            if (this->changeableTable[param_1] == '\0') {
                if (param_3 < 0) {
                    this->likeTable[param_1] = 0;
                    return;
                }
                if (0x30 < param_3) {
                    this->likeTable[param_1] = 0x30;
                    return;
                }
            } else {
                if (param_3 < 0) {
                    this->likeTable[param_1] = 0;
                    return;
                }
                if (100 < param_3) {
                    this->likeTable[param_1] = 100;
                    return;
                }
            }
        }
    }
}

// Offset: 0x0040C3B0
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C3B0
int DiplomacyAIModule::isDisliked(int param_1) const {
    if ((0 < param_1) && (param_1 < this->md->player->world->player_num) && (0x31 < this->dislikeTable[param_1])) {
        return 1;
    }
    return 0;
}

// Offset: 0x0040C3F0
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C3F0
int DiplomacyAIModule::isAmbivalent(int param_1) const {
    if (isDisliked(param_1) == 0 && isLiked(param_1) == 0) {
        return 1;
    }
    return 0;
}

// Offset: 0x0040C420
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C420
int DiplomacyAIModule::isLiked(int param_1) const {
    if ((0 < param_1) && (param_1 < this->md->player->world->player_num) && (0x31 < this->likeTable[param_1])) {
        return 1;
    }
    return 0;
}

// Offset: 0x0040C460
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C460
int DiplomacyAIModule::isChangeable(int param_1) const {
    if ((0 < param_1) && (param_1 < this->md->player->world->player_num) && (this->changeableTable[param_1] == '\x01')) {
        return 1;
    }
    return 0;
}

// Offset: 0x0040C4A0
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C4A0
void DiplomacyAIModule::setChangeable(int param_1, uchar param_2) {
    if ((0 < param_1) && (param_1 < this->md->player->world->player_num)) {
        this->changeableTable[param_1] = param_2;
    }
}

// Offset: 0x0040C4D0
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C4D0
int DiplomacyAIModule::mostHated(int param_1, int param_2, int param_3, int param_4) const {
    int highest = -1;
    int result = -1;
    int player_index = 1;
    RGE_Player* player = this->md->player;
    RGE_Game_World* world = player->world;
    if (1 < world->player_num) {
        do {
            if ((player_index != player->id) &&
                (world->players[player_index]->game_status != '\x02') &&
                ((param_1 < 1) || (param_2 != player_index) || (isAlly(player_index) == 0))) {
                long victory_points = world->players[player_index]->victory_conditions->get_victory_points();
                int value = this->dislikeTable[player_index];
                if (1 < param_4) {
                    if (param_3 == 1) {
                        value = value + (int)(victory_points / param_4);
                    } else {
                        value = value - (int)(victory_points / param_4);
                    }
                }
                if (highest < value) {
                    highest = value;
                    result = player_index;
                }
            }
            player_index = player_index + 1;
            player = this->md->player;
            world = player->world;
        } while (player_index < world->player_num);
    }
    return result;
}

// Offset: 0x0040C5B0
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C5B0
int DiplomacyAIModule::mostLiked(int param_1, int param_2) const {
    int player_index = 1;
    int highest = -1;
    int result = -1;
    RGE_Player* player = this->md->player;
    RGE_Game_World* world = player->world;
    if (1 < world->player_num) {
        do {
            if ((player_index != player->id) &&
                (world->players[player_index]->game_status != '\x02') &&
                ((param_1 < 1) || (param_2 != player_index) || (isEnemy(player_index) == 0)) &&
                (highest < this->likeTable[player_index])) {
                highest = this->likeTable[player_index];
                result = player_index;
            }
            player_index = player_index + 1;
            player = this->md->player;
            world = player->world;
        } while (player_index < world->player_num);
    }
    return result;
}

// Offset: 0x0040C660
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C660
int DiplomacyAIModule::isEnemy(int param_1) const {
    RGE_Player* player = this->md->player;
    if ((0 < param_1) && (param_1 <= player->world->player_num) && (param_1 != player->id) && (player->relations[param_1] == '\x03')) {
        return 1;
    }
    return 0;
}

// Offset: 0x0040C6A0
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C6A0
int DiplomacyAIModule::isNeutral(int param_1) const {
    RGE_Player* player = this->md->player;
    if ((0 < param_1) && (param_1 <= player->world->player_num) && (param_1 != player->id) && (player->relations[param_1] == '\x01')) {
        return 1;
    }
    return 0;
}

// Offset: 0x0040C6E0
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C6E0
int DiplomacyAIModule::isAlly(int param_1) const {
    RGE_Player* player = this->md->player;
    if (param_1 == player->id) {
        return 1;
    }
    if ((0 < param_1) && (param_1 <= player->world->player_num) && (player->relations[param_1] == '\0')) {
        return 1;
    }
    return 0;
}

// Offset: 0x0040C730
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C730
int DiplomacyAIModule::isAlliedWithMe(int param_1) const {
    if (0 < param_1) {
        RGE_Player* player = this->md->player;
        RGE_Game_World* world = player->world;
        if (param_1 < world->player_num) {
            RGE_Player* other = world->players[param_1];
            if (other != nullptr && other->isAlly((int)player->id) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

// Offset: 0x0040C780
// Fully verified. Source of truth: aidipmod.cpp.decomp @ 0x0040C780
void DiplomacyAIModule::setRelation(int param_1, int param_2) {
    RGE_Player* player = this->md->player;
    if ((0 < param_1) && (param_1 < player->world->player_num) && (this->changeableTable[param_1] != '\0')) {
        player->setDiplomaticStance(param_1, param_2);
    }
}
