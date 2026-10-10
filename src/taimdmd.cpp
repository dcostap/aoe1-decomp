
#include "../include/taimdmd.h"
#include "../include/game_globals.h"
#include "../include/m_s_obj.h"
#include "../include/map.h"
#include "../include/obj_list.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/rge_fio.h"
#include "../include/stat_obj.h"
#include "../include/tcommand.h"
#include "../include/tribegam.h"
#include "../include/tplayer.h"
#include "../include/tworld.h"
#include "../include/victory.h"
#include "../include/world.h"
#include "../include/resource_ids.h"
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

extern int startLoggingAI;

TribeMainDecisionAIModule::TribeMainDecisionAIModule(
    void* pW, int playerID, char* playerName, TRIBE_Player* aiP, char* buildListName, char* cityPlanName,
    char* ruleSetName
) :
    MainDecisionAIModule(pW, playerID, aiP), buildAI(pW, playerID), constructionAI(pW, playerID),
    diplomacyAI(pW, playerID), emotionalAI(pW, playerID), informationAI(pW, playerID),
    resourceAI(pW, playerID, 4, 500, 0, 1000), strategyAI(pW, playerID), tacticalAI(pW, playerID),
    tradeAI(pW, playerID), aiPlayer((TRIBE_Player*) aiP), firstUpdate(1), veryFirstUpdate(1), updateDelay(playerID),
    lastDiplomacyUpdateTime(0), lastTacticalUpdateTime(0), lastTributeChatTime(0), tributeChatTimeout(0),
    waitingOnTribute(0), tributeExpirationTimeout(0), tributeAddressed(0), tributeAmount(0), decidedInitialDiplomacy(0),
    requiredDiplomacyTributeAmount(0) {
    this->setPlayer(playerID, playerName);
    if (startLoggingAI != 0) {
        this->setLogCommonHistory(1);
    } else {
        this->setLogCommonHistory(0);
    }

    this->buildAI.setMainDecisionAI(this);
    this->constructionAI.setMainDecisionAI(this);
    this->diplomacyAI.setMainDecisionAI(this);
    this->emotionalAI.setMainDecisionAI(this);
    this->informationAI.setMainDecisionAI(this);
    this->resourceAI.setMainDecisionAI(this);
    this->strategyAI.setMainDecisionAI(this);
    this->tacticalAI.setMainDecisionAI(this);
    this->tradeAI.setMainDecisionAI(this);

    this->buildAI.setPlayer(playerID, playerName);
    this->constructionAI.setPlayer(playerID, playerName);
    this->diplomacyAI.setPlayer(playerID, playerName);
    this->emotionalAI.setPlayer(playerID, playerName);
    this->informationAI.setPlayer(playerID, playerName);
    this->resourceAI.setPlayer(playerID, playerName);
    this->strategyAI.setPlayer(playerID, playerName);
    this->tacticalAI.setPlayer(playerID, playerName);
    this->tradeAI.setPlayer(playerID, playerName);

    this->informationAI.addResourceType(0, 0x30);
    this->informationAI.addResourceType(0, 0x7e);
    this->informationAI.addResourceType(0, 0x3b);
    this->informationAI.addResourceType(0, 0x41);
    this->informationAI.addResourceType(0, 0x34);
    this->informationAI.addResourceType(0, 0x35);
    this->informationAI.addResourceType(0, 0x104);
    this->informationAI.addResourceType(0, 0x107);
    this->informationAI.addResourceType(0, 0x32);
    int i;
    for (i = 0x6f; i <= 0x72; i++)
        this->informationAI.addResourceType(1, i);
    for (i = 0x86; i <= 0x99; i++)
        this->informationAI.addResourceType(1, i);
    for (i = 0xc0; i <= 0xc5; i++)
        this->informationAI.addResourceType(1, i);
    this->informationAI.addResourceType(2, 0x66);
    this->informationAI.addResourceType(3, 0x42);
    for (i = 0x150; i <= 0x153; i++)
        this->informationAI.addResourceType(3, i);

    this->emotionalAI.setOverallState(0);
    memset(this->tributeGiven, 0, 36);
}

TribeMainDecisionAIModule::TribeMainDecisionAIModule(int playerID, char* playerName, TRIBE_Player* aiP, int infile) :
    MainDecisionAIModule(playerID, aiP, infile), buildAI(playerID, infile), constructionAI(playerID, infile),
    diplomacyAI(playerID, infile), emotionalAI(playerID, infile), informationAI(playerID, infile),
    resourceAI(playerID, infile), strategyAI(playerID, infile), tacticalAI(playerID, infile), tradeAI(playerID, infile),
    //! @bug Load forces these flags to 0 ("init done"), but save() never stores them.
    //! A save before the first AI update therefore skips the one-time init after load.
    //! No dynamic build items, no learn-file path, and no AI start-resource bonus then.
    firstUpdate(0), veryFirstUpdate(0), updateDelay(playerID), lastDiplomacyUpdateTime(0), lastTacticalUpdateTime(0),
    decidedInitialDiplomacy(0), requiredDiplomacyTributeAmount(0) {
    this->aiPlayer = aiP;
    this->setPlayer(playerID, playerName);
    if (startLoggingAI != 0) {
        this->setLogCommonHistory(1);
    } else {
        this->setLogCommonHistory(0);
    }

    this->buildAI.setMainDecisionAI(this);
    this->constructionAI.setMainDecisionAI(this);
    this->diplomacyAI.setMainDecisionAI(this);
    this->emotionalAI.setMainDecisionAI(this);
    this->informationAI.setMainDecisionAI(this);
    this->resourceAI.setMainDecisionAI(this);
    this->strategyAI.setMainDecisionAI(this);
    this->tacticalAI.setMainDecisionAI(this);
    this->tradeAI.setMainDecisionAI(this);

    this->buildAI.setPlayer(playerID, playerName);
    this->constructionAI.setPlayer(playerID, playerName);
    this->diplomacyAI.setPlayer(playerID, playerName);
    this->emotionalAI.setPlayer(playerID, playerName);
    this->informationAI.setPlayer(playerID, playerName);
    this->resourceAI.setPlayer(playerID, playerName);
    this->strategyAI.setPlayer(playerID, playerName);
    this->tacticalAI.setPlayer(playerID, playerName);
    this->tradeAI.setPlayer(playerID, playerName);

    rge_read(infile, &this->updateDelay, 4);
    rge_read(infile, &this->lastDiplomacyUpdateTime, 4);
    rge_read(infile, &this->lastTacticalUpdateTime, 4);

    if (save_game_version >= g_main_decision_save_version_1_2) {
        rge_read(infile, &this->lastTributeChatTime, 4);
        rge_read(infile, &this->tributeChatTimeout, 4);
        rge_read(infile, &this->waitingOnTribute, 4);
        rge_read(infile, &this->tributeExpirationTimeout, 4);
        rge_read(infile, &this->tributeAddressed, 4);
        rge_read(infile, &this->tributeAmount, 4);
    }
    if (save_game_version >= g_main_decision_save_version_7_08) {
        rge_read(infile, &this->decidedInitialDiplomacy, 4);
        rge_read(infile, &this->requiredDiplomacyTributeAmount, 4);
        rge_read(infile, this->tributeGiven, 36);
    } else {
        memset(this->tributeGiven, 0, 36);
    }
}

TribeMainDecisionAIModule::~TribeMainDecisionAIModule() {
}

void TribeMainDecisionAIModule::setLogHistory(int v) {
    buildAI.setLogHistory(v);
    constructionAI.setLogHistory(v);
    diplomacyAI.setLogHistory(v);
    emotionalAI.setLogHistory(v);
    informationAI.setLogHistory(v);
    resourceAI.setLogHistory(v);
    strategyAI.setLogHistory(v);
    tacticalAI.setLogHistory(v);
    tradeAI.setLogHistory(v);
    MainDecisionAIModule::setLogHistory(v);
}

int TribeMainDecisionAIModule::update(int timeLimit) {
    TribeTacticalAIModule* tactical = &this->tacticalAI;
    char tempString[256];

    if (this->player->world->game_state == 0 && this->firstUpdate == 1) {
        this->firstUpdate = 0;
        this->logCommonHistory("Initial Diplomacy Settings:");
        for (int i = 1; i < this->player->world->player_num; i++) {
            this->logCommonHistory(
                "  Player #%d: Dislike=%d, Like=%d, Ambivalence=%d.", i, this->diplomacyAI.stance(i, 0),
                this->diplomacyAI.stance(i, 2), this->diplomacyAI.stance(i, 1)
            );
        }

        this->strategyAI.update(0);
        this->buildAI.initialize();
        this->informationAI.initialize();
        this->setTributeChat();

        if (tactical->strategicNumber(SNTributeSuccessOutcome) == 1
            && tactical->strategicNumber(SNTributeChatFrequency) == 0) {
            this->waitingOnTribute = 1;
            this->tributeAmount = 0;
        }

        int value = tactical->strategicNumber(0x8A);
        if (value != 0)
            this->player->command_add_attribute(0, (float) value);
        value = tactical->strategicNumber(0x8B);
        if (value != 0)
            this->player->command_add_attribute(3, (float) value);
        value = tactical->strategicNumber(0x8C);
        if (value != 0)
            this->player->command_add_attribute(2, (float) value);
        value = tactical->strategicNumber(0x8D);
        if (value != 0)
            this->player->command_add_attribute(1, (float) value);
    }

    this->updateDelay++;
    if (this->updateDelay >= 20) {
        this->strategyAI.update(0);
        this->updateDelay = 0;
    }
    this->informationAI.update(0);

    if ((this->player->world->world_time - this->lastDiplomacyUpdateTime) / 1000 >= 60) {
        this->diplomacyAI.update(0);
        this->lastDiplomacyUpdateTime = this->player->world->world_time;
    }

    unsigned long tribute_elapsed = (this->player->world->world_time - this->lastTributeChatTime) / 1000;
    if (tactical->strategicNumber(SNTributeAmount) > 0 && this->tributeAddressed == 0) {
        if (tribute_elapsed >= (unsigned long) this->tributeChatTimeout
            && tactical->strategicNumber(SNTributeChatFrequency) > 0) {
            if (this->waitingOnTribute == 0) {
                this->waitingOnTribute = 1;
                int expiration_timeout = tactical->strategicNumber(SNTributeTimeout);
                this->tributeAmount = 0;
                this->tributeExpirationTimeout = expiration_timeout * 1000;
            }

            this->lastTributeChatTime = this->player->world->world_time;
            if (tactical->strategicNumber(SNTributeFailureOutcome) == 1) {
                if (this->tributeAmount > 0) {
                    rge_base_game->get_string(STRING_ID_AI_TRIBUTE_MORE_GOLD, tempString, 256);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(SNTributePlayer), 0, tempString,
                        tactical->strategicNumber(SNTributeAmount) - this->tributeAmount
                    );
                } else {
                    rge_base_game->get_string(STRING_ID_AI_TRIBUTE_GOLD, tempString, 256);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(SNTributePlayer), 0, tempString,
                        tactical->strategicNumber(SNTributeAmount)
                    );
                }
            } else if (tactical->strategicNumber(SNTributeSuccessOutcome) == 1) {
                if (this->tributeAmount > 0) {
                    rge_base_game->get_string(STRING_ID_AI_TRIBUTE_ALLIANCE_GOLD, tempString, 256);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(SNTributePlayer), 0, tempString,
                        tactical->strategicNumber(SNTributeAmount)
                    );
                } else {
                    rge_base_game->get_string(STRING_ID_AI_TRIBUTE_ALLIANCE_MORE_GOLD, tempString, 256);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(SNTributePlayer), 0, tempString,
                        tactical->strategicNumber(SNTributeAmount) - this->tributeAmount
                    );
                }
            }
            this->setTributeChat();
        } else if (this->waitingOnTribute == 1) {
            this->tributeExpirationTimeout -= this->player->world->world_time_delta;
            if (this->tributeExpirationTimeout <= 0) {
                if (tactical->strategicNumber(SNTributeFailureOutcome) == 1) {
                    this->diplomacyAI.setStance(tactical->strategicNumber(SNTributePlayer), 0, 100);
                    this->diplomacyAI.setStance(tactical->strategicNumber(SNTributePlayer), 2, 0);
                    this->aiPlayer->setDiplomaticStance(tactical->strategicNumber(SNTributePlayer), 3);
                    rge_base_game->get_string(STRING_ID_AI_TRIBUTE_THREAT, tempString, 256);
                    this->player->sendChatMessage(tactical->strategicNumber(SNTributePlayer), 0, tempString);
                    this->waitingOnTribute = 0;
                    this->tributeAddressed = 1;
                    this->lastTributeChatTime = this->player->world->world_time;
                } else if (tactical->strategicNumber(SNTributeSuccessOutcome) == 1) {
                    rge_base_game->get_string(STRING_ID_AI_TRIBUTE_ALLIANCE_MISSED, tempString, 256);
                    this->player->sendChatMessage(tactical->strategicNumber(SNTributePlayer), 0, tempString);
                    this->waitingOnTribute = 0;
                    this->lastTributeChatTime = this->player->world->world_time;
                    this->tributeAddressed = tactical->strategicNumber(SNTributePersistence) == 0;
                }
            } else if (this->tributeAmount >= tactical->strategicNumber(SNTributeAmount)) {
                if (tactical->strategicNumber(SNTributeSuccessOutcome) == 1) {
                    this->diplomacyAI.setStance(tactical->strategicNumber(SNTributePlayer), 0, 0);
                    this->diplomacyAI.setStance(tactical->strategicNumber(SNTributePlayer), 2, 100);
                    this->aiPlayer->setDiplomaticStance(tactical->strategicNumber(SNTributePlayer), 0);
                    rge_base_game->get_string(STRING_ID_AI_TRIBUTE_ALLIANCE, tempString, 256);
                    this->player->sendChatMessage(tactical->strategicNumber(SNTributePlayer), 0, tempString);
                    this->waitingOnTribute = 0;
                    this->lastTributeChatTime = this->player->world->world_time;
                    this->tributeAddressed = tactical->strategicNumber(SNTributePersistence) == 0;
                } else if (tactical->strategicNumber(SNTributeFailureOutcome) == 1) {
                    rge_base_game->get_string(STRING_ID_AI_TRIBUTE_ACCEPTED, tempString, 256);
                    this->player->sendChatMessage(tactical->strategicNumber(SNTributePlayer), 0, tempString);
                    this->waitingOnTribute = 0;
                    this->lastTributeChatTime = this->player->world->world_time;
                    this->tributeAddressed = tactical->strategicNumber(SNTributePersistence) == 0;
                }
            }
        }
    }

    //! With no teams set, world.cpp new_game makes every computer player all-neutral.
    //! At 10 seconds this block turns that state into one alliance against every human.
    //! Each neutral computer allies with all computers and declares each human enemy.
    if (this->decidedInitialDiplomacy == 0 && this->player->world->world_time > 10000) {
        this->decidedInitialDiplomacy = 1;
        TRIBE_World* world = static_cast<TRIBE_World*>(this->player->world);
        int numberComputerPlayers = 0;
        int numberHumanPlayers = 0;
        int numberNeutralCPs = 0;
        int neutralList[9];

        for (int i = 1; i < world->player_num; i++) {
            RGE_Player* other = world->players[i];
            if (other->computerPlayer() == 0) {
                numberHumanPlayers++;
            } else {
                numberComputerPlayers++;
                if (other->isAllNeutral() == 1) {
                    neutralList[i] = 1;
                    numberNeutralCPs++;
                } else {
                    neutralList[i] = 0;
                }
            }
        }

        if (world->controllingComputerPlayer == (unsigned char) -1) {
            if (numberComputerPlayers == 1) {
                world->controllingComputerPlayer = (unsigned char) this->player->id;
            } else {
                int selection = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 566) % numberComputerPlayers + 1;
                for (int i = 1; i < world->player_num; i++) {
                    RGE_Player* other = world->players[i];
                    if (other->computerPlayer() == 1) {
                        selection--;
                        if (selection == 0)
                            world->controllingComputerPlayer = (unsigned char) other->id;
                    }
                }
            }
        }

        if (world->controllingComputerPlayer == (unsigned char) this->player->id) {
            int numberSwayable = (numberComputerPlayers - numberHumanPlayers) / 2;
            if (numberSwayable < 0)
                numberSwayable = 0;
            if (numberSwayable > numberNeutralCPs)
                numberSwayable = numberNeutralCPs;
            if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1)
                numberSwayable = 0;

            if (numberSwayable <= numberNeutralCPs && numberNeutralCPs > 0) {
                ManagedArray<int> swayableCPs;
                for (int i = 1; i < world->player_num; i++) {
                    RGE_Player* other = world->players[i];
                    if (other->computerPlayer() != 0 && neutralList[i] != 0
                        && (unsigned short) world->controllingComputerPlayer != (unsigned short) other->id
                        && swayableCPs.number() < numberSwayable) {
                        swayableCPs.add(i);
                    }
                }

                int resAmount = 2000;
                switch (rge_base_game->difficulty()) {
                    case RGE_DIFFICULTY_HARDEST:
                        resAmount = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 622) % 500 + 1400;
                        break;
                    case RGE_DIFFICULTY_HARD:
                        resAmount = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 623) % 400 + 1000;
                        break;
                    case RGE_DIFFICULTY_MODERATE:
                        resAmount = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 624) % 300 + 700;
                        break;
                    case RGE_DIFFICULTY_EASY:
                        resAmount = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 625) % 200 + 450;
                        break;
                    case RGE_DIFFICULTY_EASIEST:
                        resAmount = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 626) % 100 + 300;
                        break;
                }

                for (int neutralPlayer = 1; neutralPlayer < world->player_num; neutralPlayer++) {
                    RGE_Player* other = world->players[neutralPlayer];
                    if (other->computerPlayer() == 0 || neutralList[neutralPlayer] == 0)
                        continue;

                    if (swayableCPs.contains(neutralPlayer)) {
                        other->sendAICommand(this->player->id, 7, resAmount, 0, 0);
                        resAmount *= 2;
                    }

                    for (int j = 1; j < world->player_num; j++) {
                        if (j == neutralPlayer)
                            continue;
                        RGE_Player* target = world->players[j];
                        if (target->computerPlayer() == 0 && !swayableCPs.contains(neutralPlayer)) {
                            other->sendAICommand(this->player->id, 6, j, 0, 0);
                        } else if (target->computerPlayer() == 1) {
                            other->sendAICommand(this->player->id, 6, j, 2, 0);
                        }
                    }
                }
            }
        }
    }

    if (tactical->strategicNumber(0xD9) == 1) {
        int diplomacy_start_time = (tactical->strategicNumber(SNInitialAttackDelay) - 3) * 1000;
        if (diplomacy_start_time < 0)
            diplomacy_start_time = 0;
        if (this->player->world->world_time > (unsigned long) diplomacy_start_time) {
            tactical->setStrategicNumber(0xD9, 0);
            int newEnemy = -1;
            for (int i = 1; i < this->player->world->player_num; i++) {
                if (this->player->world->players[i]->computerPlayer() != 1) {
                    newEnemy = i;
                    break;
                }
            }

            if (newEnemy != -1) {
                if (this->player->isEnemy(newEnemy) == 0) {
                    this->player->sendAICommand(this->player->id, 6, newEnemy, 0, 0);
                }
                for (int i = 1; i < this->player->world->player_num; i++) {
                    if (i == this->player->id || i == newEnemy)
                        continue;
                    RGE_Player* other = this->player->world->players[i];
                    if (other->isEnemy(newEnemy) == 1) {
                        this->player->sendAICommand(this->player->id, 6, i, 2, 0);
                        if (other->computerPlayer() == 1) {
                            other->sendAICommand(this->player->id, 6, this->player->id, 2, 0);
                        }
                    } else if (other->isAlly(newEnemy) == 1) {
                        this->player->sendAICommand(this->player->id, 6, i, 0, 0);
                    }
                }
            }
        }
    }

    if (this->player->world->game_state == 0 && this->player->world->currentUpdateComputerPlayer == this->player->id) {
        this->tacticalAI.update(0);
        this->lastTacticalUpdateTime = this->player->world->world_time;
    }
    return 1;
}

int TribeMainDecisionAIModule::save(int outfile) {
    MainDecisionAIModule::save(outfile);

    this->buildAI.save(outfile);
    this->constructionAI.save(outfile);
    this->diplomacyAI.save(outfile);
    this->emotionalAI.save(outfile);
    this->informationAI.save(outfile);
    this->resourceAI.save(outfile);
    this->strategyAI.save(outfile);
    this->tacticalAI.save(outfile);
    this->tradeAI.save(outfile);

    rge_write(outfile, &this->updateDelay, 4);
    rge_write(outfile, &this->lastDiplomacyUpdateTime, 4);
    rge_write(outfile, &this->lastTacticalUpdateTime, 4);
    rge_write(outfile, &this->lastTributeChatTime, 4);
    rge_write(outfile, &this->tributeChatTimeout, 4);
    rge_write(outfile, &this->waitingOnTribute, 4);
    rge_write(outfile, &this->tributeExpirationTimeout, 4);
    rge_write(outfile, &this->tributeAddressed, 4);
    rge_write(outfile, &this->tributeAmount, 4);
    rge_write(outfile, &this->decidedInitialDiplomacy, 4);
    rge_write(outfile, &this->requiredDiplomacyTributeAmount, 4);
    rge_write(outfile, this->tributeGiven, 36);

    return 1;
}

void TribeMainDecisionAIModule::kick(int m) {
    this->logCommonHistory("Got a kick=%d.", m);
    if (m == 1) {
        this->buildAI.skipNextBuildListItem();
    }
    if (m == 2) {
        this->buildAI.insert(MASTER_OBJECT_MAN, 1, -1);
    }
    if (m == 3) {
        this->logCommonHistory("Current Build list is:");
        this->buildAI.displayBuildList();
    }
}

int TribeMainDecisionAIModule::addObject(RGE_Static_Object* bo) {
    if (bo == 0) {
        return 0;
    }
    tacticalAI.addObject(bo);
    informationAI.addObject(bo);
    return MainDecisionAIModule::addObject(bo);
}

int TribeMainDecisionAIModule::removeObject(int id) {
    this->tacticalAI.removeObject(id);
    this->buildAI.removeBuiltItem(id);
    this->informationAI.removeObject(id);
    return MainDecisionAIModule::removeObject(id);
}

int TribeMainDecisionAIModule::objectGroupThatCanPerformAction(int a) {
    switch (a) {
        case UNIT_AI_ACTION_BUILD:
        case UNIT_AI_ACTION_EXPLORE:
        case UNIT_AI_ACTION_GATHER:
        case UNIT_AI_ACTION_HUNT:
            return OBJECT_GROUP_CIVILIAN;
        case UNIT_AI_ACTION_TRAIN:
        case UNIT_AI_ACTION_RESEARCH:
            return OBJECT_GROUP_BUILDING;
        default:
            return MainDecisionAIModule::objectGroupThatCanPerformAction(a);
    }
}

int TribeMainDecisionAIModule::canPerformAction(int id, int a) {
    RGE_Static_Object* object = this->object(id);
    if (object != 0) {
        if (object->master_obj->object_group == this->objectGroupThatCanPerformAction(a)) {
            return 1;
        }
    }
    return 0;
}

void TribeMainDecisionAIModule::detask(int uID) {
    this->tacticalAI.detask(uID);
}

int TribeMainDecisionAIModule::isMoveable(int o) {
    RGE_Static_Object* obj = this->object(o);
    if (obj == 0)
        return 0;

    short group = obj->master_obj->object_group;
    if (group == OBJECT_GROUP_BUILDING || group == OBJECT_GROUP_WALL || group == 0x1E || group == 0x1F || group == 5
        || group == 0x21 || group == 7 || group == OBJECT_GROUP_STONE_SOURCE || group == OBJECT_GROUP_GOLD_SOURCE
        || group == 0x10 || group == 0x0E || group == OBJECT_GROUP_TREE)
        return 0;

    return 1;
}

void TribeMainDecisionAIModule::updateBuildAIWithObjects() {
    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object = this->object(this->objects[i]);
        if (object != 0) {
            this->buildAI.addItem(object, 0);
            if (object->master_obj->id == MASTER_OBJECT_TOWN_CENTER1) {
                this->constructionAI.setReferencePoint(
                    this->player->world->map->map_width, this->player->world->map->map_height, object->world_x,
                    object->world_y, object->world_z
                );
            }
        }
    }
}

void TribeMainDecisionAIModule::tributeNotify(int playerID, int resourceID, int amount) {
    char tempString[256];

    if (this->waitingOnTribute == 1 && playerID == this->tacticalAI.strategicNumber(SNTributePlayer)
        && resourceID == RGE_RESOURCE_GOLD) {
        this->tributeAmount += amount;
        return;
    }

    TribeTacticalAIModule* tactical = &this->tacticalAI;
    if (playerID != tactical->strategicNumber(SNTributePlayer)) {
        int tribute = amount / 100;
        this->diplomacyAI.changeStance(playerID, 2, tribute);
        this->diplomacyAI.changeStance(playerID, 0, -tribute);
        this->tributeGiven[playerID] += amount;

        if (this->player->isNeutral(playerID) == 1 && tactical->strategicNumber(0xD9) == 1
            && this->tributeGiven[playerID] >= this->requiredDiplomacyTributeAmount) {
            this->player->sendAICommand(this->player->id, 6, playerID, 2, 0);
            rge_base_game->get_string(STRING_ID_AI_TRIBUTE_ALLIANCE_ACCEPTED, tempString, 256);
            this->player->sendChatMessage(playerID, 0, tempString);

            RGE_Player* newAlly = this->player->world->players[playerID];
            for (int i = 1; i < this->player->world->player_num; ++i) {
                if (i != this->player->id && i != playerID) {
                    if (newAlly->isAlly(i) == 1) {
                        this->player->sendAICommand(this->player->id, 6, i, 2, 0);
                    } else if (newAlly->isEnemy(i) == 1) {
                        this->player->sendAICommand(this->player->id, 6, i, 0, 0);
                    }
                }
            }

            tactical->setStrategicNumber(0xD9, 0);
        } else if (this->player->isEnemy(playerID) == 1) {
            rge_base_game->get_string(STRING_ID_AI_TRIBUTE_REJECTED, tempString, 256);
            this->player->sendChatMessage(playerID, 0, tempString);
        }
    }
}

void TribeMainDecisionAIModule::revokeTributeAlliance() {
    char tempString[256];
    TribeTacticalAIModule* tactical = &this->tacticalAI;

    if (this->player->isEnemy(tactical->strategicNumber(SNTributePlayer)) == 0) {
        this->diplomacyAI.setStance(tactical->strategicNumber(SNTributePlayer), 0, 0);
        this->diplomacyAI.setStance(tactical->strategicNumber(SNTributePlayer), 2, 100);
        this->aiPlayer->setDiplomaticStance(tactical->strategicNumber(SNTributePlayer), 3);
        rge_base_game->get_string(STRING_ID_AI_TRIBUTE_REFUSED, tempString, 256);
        this->player->sendChatMessage(tactical->strategicNumber(SNTributePlayer), 0, tempString);
        this->waitingOnTribute = 0;
        this->tributeAddressed = 1;
    }
}

void TribeMainDecisionAIModule::setTributeChat() {
    TribeTacticalAIModule* tactical = &this->tacticalAI;
    if (tactical->strategicNumber(SNTributeChatRandomness) > 0) {
        int random_value = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 1053);
        this->tributeChatTimeout = random_value % tactical->strategicNumber(SNTributeChatRandomness)
                                   - tactical->strategicNumber(SNTributeChatRandomness) / 2
                                   + tactical->strategicNumber(SNTributeChatFrequency);
    } else {
        this->tributeChatTimeout = tactical->strategicNumber(SNTributeChatFrequency);
    }
}

int TribeMainDecisionAIModule::processAICommand(int caller, int mType, int p1, int p2, int p3) {
    switch (mType) {
        case 0:
            this->informationAI.lookAtMap();
            return 1;

        case 1:
            if (caller != this->player->id
                && this->aiPlayer->objects->find_by_master_id(0x54, -1.0f, -1.0f, 0, RGE_OBJECT_STATE_ACTIVE, 0) != 0) {
                float current = this->aiPlayer->attributes[0x2E];
                this->aiPlayer->command_give_attribute(caller, p1, (float) p2, current);
                return 1;
            }
            break;

        case 2:
        case 3:
            if (caller != this->player->id) {
                this->tacticalAI.processCoopAttack(caller, p1, p2, p3);
                return 1;
            }
            break;

        case 7:
            this->requiredDiplomacyTributeAmount = p1;
            this->tacticalAI.setStrategicNumber(0xD9, 1);
            return 1;

        case 6: {
            this->diplomacyAI.setChangeable(p1, 1);
            switch (p2) {
                case 0:
                    this->diplomacyAI.setStance(p1, 0, 100);
                    this->diplomacyAI.setRelation(p1, 3);
                    break;

                case 1:
                    this->diplomacyAI.setStance(p1, 0, 0x31);
                    this->diplomacyAI.setStance(p1, 2, 0x31);
                    this->diplomacyAI.setRelation(p1, 1);
                    break;

                case 2:
                    this->diplomacyAI.setStance(p1, 2, 100);
                    this->diplomacyAI.setRelation(p1, 0);
                    if (rge_base_game->difficulty() == RGE_DIFFICULTY_EASIEST) {
                        if (this->player->world->players[p1]->computerPlayer() == 0) {
                            static_cast<TRIBE_Command*>(this->player->world->commands)
                                ->command_allied_victory(this->player->id, 1);
                            this->diplomacyAI.setChangeable(p1, 0);
                            return 1;
                        } else {
                            static_cast<TRIBE_Command*>(this->player->world->commands)
                                ->command_allied_victory(this->player->id, 0);
                            this->diplomacyAI.setChangeable(p1, 0);
                            return 1;
                        }
                    } else {
                        static_cast<TRIBE_Command*>(this->player->world->commands)
                            ->command_allied_victory(this->player->id, 1);
                        this->diplomacyAI.setChangeable(p1, 0);
                        return 1;
                    }

                default:
                    break;
            }
            this->diplomacyAI.setChangeable(p1, 0);
            break;
        }

        default:
            return 0;
    }

    return 1;
}

int TribeMainDecisionAIModule::currentScore(int playerID) {
    if (playerID >= 1 && playerID <= this->player->world->player_num)
        return this->player->world->players[playerID]->victory_conditions->get_victory_points();
    return -1;
}
