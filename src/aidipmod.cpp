#include "../include/aidipmod.h"

#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/victory.h"
#include "../include/world.h"

DiplomacyAIModule::DiplomacyAIModule(void* pW, int playerID)
    : AIModule("Diplomacy AI", 0x3EB, playerID, pW) {
    this->md = 0;
    for (int i = 0; i <= 9; i++) {
        this->dislikeTable[i] = 49;
        this->likeTable[i] = 49;
        this->changeableTable[i] = 1;
    }
}

DiplomacyAIModule::DiplomacyAIModule(int playerID, int infile)
    : AIModule("Diplomacy AI", 0x3EB, playerID, 0), md(0) {
    unsigned char* changeable_table = this->changeableTable;
    int* like_table = this->likeTable;
    int count = 10;
    do {
        rge_read(infile, like_table - 10, 4);
        rge_read(infile, like_table, 4);
        rge_read(infile, changeable_table, 1);
        like_table++;
        changeable_table++;
        count--;
    } while (count != 0);
}

DiplomacyAIModule::~DiplomacyAIModule() {
}

void DiplomacyAIModule::setMainDecisionAI(MainDecisionAIModule* m) {
    this->md = m;
}

int DiplomacyAIModule::update(int timeLimit) {
    int player_index = 1;
    RGE_Player* player = this->md->player;
    RGE_Game_World* world = player->world;
    if (world->player_num > player_index) {
        do {
            if (player_index != player->id) {
                if (isAlly(player_index)) {
                    if (!isAlliedWithMe(player_index))
                        changeStance(player_index, 0, 1);
                }
                if (!isAlly(player_index)) {
                    if (isAlliedWithMe(player_index))
                        changeStance(player_index, 2, 1);
                }
            }
            player = this->md->player;
            ++player_index;
            world = player->world;
        } while (player_index < world->player_num);
    }
    return 1;
}

int DiplomacyAIModule::save(int outfile) {
    unsigned char* changeable_table = this->changeableTable;
    int* like_table = this->likeTable;
    int count = 10;

    do {
        rge_write(outfile, like_table - 10, 4);
        rge_write(outfile, like_table, 4);
        rge_write(outfile, changeable_table, 1);
        ++like_table;
        ++changeable_table;
    } while (--count != 0);

    return 1;
}

int DiplomacyAIModule::stance(int playerID, int likeType) const {
    if (playerID > 0 && playerID < this->md->player->world->player_num) {
        switch (likeType) {
        case 0:
            return this->dislikeTable[playerID];
        case 1: {
            int dislike_diff = 0x31 - this->dislikeTable[playerID];
            if (dislike_diff < 0) dislike_diff = -dislike_diff;
            int like_diff = 0x31 - this->likeTable[playerID];
            if (like_diff < 0) like_diff = -like_diff;
            int result = 100 - dislike_diff - like_diff;
            if (result < 0) result = 0;
            return result;
        }
        case 2:
            return this->likeTable[playerID];
        }
    }
    return -1;
}

void DiplomacyAIModule::changeStance(int playerID, int likeType, int delta) {
    if (playerID > 0 && playerID < this->md->player->world->player_num) {
        switch (likeType) {
        case 0:
            this->dislikeTable[playerID] += delta;
            if (this->changeableTable[playerID] != 0) {
                if (this->dislikeTable[playerID] < 0) {
                    this->dislikeTable[playerID] = 0;
                    return;
                }
                if (this->dislikeTable[playerID] > 100) {
                    this->dislikeTable[playerID] = 100;
                    return;
                }
            } else {
                if (this->dislikeTable[playerID] < 50) {
                    this->dislikeTable[playerID] = 50;
                    return;
                }
                if (this->dislikeTable[playerID] > 100) {
                    this->dislikeTable[playerID] = 100;
                }
            }
            break;

        case 2:
            this->likeTable[playerID] += delta;
            if (this->changeableTable[playerID] != 0) {
                if (this->likeTable[playerID] < 0) {
                    this->likeTable[playerID] = 0;
                    return;
                }
                if (this->likeTable[playerID] > 100) {
                    this->likeTable[playerID] = 100;
                    return;
                }
            } else {
                if (this->likeTable[playerID] < 0) {
                    this->likeTable[playerID] = 0;
                    return;
                }
                if (this->likeTable[playerID] > 48) {
                    this->likeTable[playerID] = 48;
                    return;
                }
            }
            break;
        }
    }
}

void DiplomacyAIModule::setStance(int playerID, int likeType, int value) {
    if (playerID > 0 && playerID < this->md->player->world->player_num) {
        switch (likeType) {
        case 0:
            this->dislikeTable[playerID] = value;
            if (this->changeableTable[playerID] != 0) {
                if (value < 0) {
                    this->dislikeTable[playerID] = 0;
                    return;
                }
                if (value > 100) {
                    this->dislikeTable[playerID] = 100;
                    return;
                }
            } else {
                if (value < 50) {
                    this->dislikeTable[playerID] = 50;
                    return;
                }
                if (value > 100) {
                    this->dislikeTable[playerID] = 100;
                }
            }
            break;

        case 2:
            this->likeTable[playerID] = value;
            if (this->changeableTable[playerID] != 0) {
                if (value < 0) {
                    this->likeTable[playerID] = 0;
                    return;
                }
                if (value > 100) {
                    this->likeTable[playerID] = 100;
                    return;
                }
            } else {
                if (value < 0) {
                    this->likeTable[playerID] = 0;
                    return;
                }
                if (value > 48) {
                    this->likeTable[playerID] = 48;
                    return;
                }
            }
            break;
        }
    }
}

int DiplomacyAIModule::isDisliked(int playerID) const {
    if (((playerID > 0) && (playerID < this->md->player->world->player_num)) && (this->dislikeTable[playerID] > 0x31)) {
        return 1;
    }
    return 0;
}

int DiplomacyAIModule::isAmbivalent(int playerID) const {
    if (this->isDisliked(playerID) == 0) {
        if (this->isLiked(playerID) == 0) {
            return 1;
        }
    }
    return 0;
}

int DiplomacyAIModule::isLiked(int playerID) const {
    if (((playerID > 0) && (playerID < this->md->player->world->player_num)) && (this->likeTable[playerID] > 0x31)) {
        return 1;
    }
    return 0;
}

int DiplomacyAIModule::isChangeable(int playerID) const {
    if (((playerID > 0) && (playerID < this->md->player->world->player_num)) && (this->changeableTable[playerID] == 1)) {
        return 1;
    }
    return 0;
}

void DiplomacyAIModule::setChangeable(int playerID, unsigned char v) {
    if (playerID > 0 && playerID < this->md->player->world->player_num) {
        this->changeableTable[playerID] = v;
    }
}

int DiplomacyAIModule::mostHated(int tributeOn, int tributePlayer, int attackWinningPlayer, int attackWinningPlayerFactor) const {
    int highest = -1;
    int highestValue = -1;
    for (int player_index = 1; player_index < this->md->player->world->player_num; ++player_index) {
        //! @bug This scan does not reject allied players, so an ally can become the attack target.
        //! The engine refuses attacks on allies, so the AI then stays inactive with idle military.
        if (player_index != this->md->player->id && this->md->player->world->players[player_index]->game_status != 2
            && (tributeOn <= 0 || tributePlayer != player_index || !isAlly(player_index))) {
            int victory_points = this->md->player->world->players[player_index]->victory_conditions->get_victory_points();
            int stance_value = this->dislikeTable[player_index];
            //! @bug This gate has no check for attackWinningPlayer == 0.
            //! Value 0 means "ignore score", but the else branch subtracts the victory points.
            //! So a zero SNAttackWinningPlayer lowers hate for the high-score players instead.
//! The score term is also score / factor; the formula needs score * 100 / factor.
            if (attackWinningPlayerFactor > 1) {
                if (attackWinningPlayer == 1) {
                    stance_value += victory_points / attackWinningPlayerFactor;
                } else {
                    stance_value -= victory_points / attackWinningPlayerFactor;
                }
            }
            if (stance_value > highestValue) {
                highest = player_index;
                highestValue = stance_value;
            }
        }
    }
    return highest;
}

int DiplomacyAIModule::mostLiked(int tributeOn, int tributePlayer) const {
    int result = -1;
    int highest = -1;
    int player_index = 1;
    RGE_Player* player = this->md->player;
    RGE_Game_World* world = player->world;

    if (player_index < world->player_num) {
        do {
            if (player_index != player->id) {
                if (world->players[player_index]->game_status != 2) {
                    if (tributeOn <= 0 || tributePlayer != player_index || isEnemy(player_index) == 0) {
                        if (this->likeTable[player_index] > highest) {
                            result = player_index;
                            highest = this->likeTable[player_index];
                        }
                    }
                }
            }
            player = this->md->player;
            ++player_index;
            world = player->world;
        } while (player_index < world->player_num);
    }
    return result;
}

int DiplomacyAIModule::isEnemy(int playerID) const {
    if (playerID > 0) {
        RGE_Player* player = this->md->player;
        if (playerID <= player->world->player_num) {
            if (playerID != player->id) {
                if (player->relations[playerID] == 3) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int DiplomacyAIModule::isNeutral(int playerID) const {
    RGE_Player* player;

    if (((0 < playerID) && (player = this->md->player, playerID <= player->world->player_num)) &&
        (playerID != player->id) && (player->relations[playerID] == 1)) {
        return 1;
    }
    return 0;
}

int DiplomacyAIModule::isAlly(int playerID) const {
    if (playerID == this->md->player->id) {
        return 1;
    }

    if (playerID > 0 && playerID <= this->md->player->world->player_num && this->md->player->relations[playerID] == 0) {
        return 1;
    }

    return 0;
}

int DiplomacyAIModule::isAlliedWithMe(int playerID) const {
    if (0 < playerID) {
        RGE_Player* me = this->md->player;
        RGE_Game_World* world = me->world;
        if (playerID < world->player_num) {
            RGE_Player* other = world->players[playerID];
            if (other != 0) {
                if (other->isAlly((int)me->id) != 0)
                    return 1;
            }
        }
    }

    return 0;
}

void DiplomacyAIModule::setRelation(int playerID, int newRelation) {
    if (playerID > 0) {
        if (playerID < this->md->player->world->player_num) {
            if (this->changeableTable[playerID] != 0) {
                this->md->player->setDiplomaticStance(playerID, newRelation);
            }
        }
    }
}
