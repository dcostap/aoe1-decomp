
#include "../include/taimdmd.h"
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
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

extern int startLoggingAI;
extern float g_time;
extern float DAT_00575618;
extern float DAT_0057561c;

TribeMainDecisionAIModule::TribeMainDecisionAIModule(
    void* p1, int p2, char* p3, TRIBE_Player* player, char* p5, char* p6,
    char* p7)
    : MainDecisionAIModule(p1, p2, player),
      buildAI(p1, p2),
      constructionAI(p1, p2),
      diplomacyAI(p1, p2),
      emotionalAI(p1, p2),
      informationAI(p1, p2),
      resourceAI(p1, p2, 4, 500, 0, 1000),
      strategyAI(p1, p2),
      tacticalAI(p1, p2),
      tradeAI(p1, p2),
      aiPlayer((TRIBE_Player*)player),
      firstUpdate(1),
      veryFirstUpdate(1),
      updateDelay(p2),
      lastDiplomacyUpdateTime(0),
      lastTacticalUpdateTime(0),
      lastTributeChatTime(0),
      tributeChatTimeout(0),
      waitingOnTribute(0),
      tributeExpirationTimeout(0),
      tributeAddressed(0),
      tributeAmount(0),
      decidedInitialDiplomacy(0),
      requiredDiplomacyTributeAmount(0)
{
    this->setPlayer(p2, p3);
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

    this->buildAI.setPlayer(p2, p3);
    this->constructionAI.setPlayer(p2, p3);
    this->diplomacyAI.setPlayer(p2, p3);
    this->emotionalAI.setPlayer(p2, p3);
    this->informationAI.setPlayer(p2, p3);
    this->resourceAI.setPlayer(p2, p3);
    this->strategyAI.setPlayer(p2, p3);
    this->tacticalAI.setPlayer(p2, p3);
    this->tradeAI.setPlayer(p2, p3);

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
    for (i = 0x6f; i <= 0x72; i++) this->informationAI.addResourceType(1, i);
    for (i = 0x86; i <= 0x99; i++) this->informationAI.addResourceType(1, i);
    for (i = 0xc0; i <= 0xc5; i++) this->informationAI.addResourceType(1, i);
    this->informationAI.addResourceType(2, 0x66);
    this->informationAI.addResourceType(3, 0x42);
    for (i = 0x150; i <= 0x153; i++) this->informationAI.addResourceType(3, i);

    this->emotionalAI.setOverallState(0);
    memset(this->tributeGiven, 0, 36);
}

TribeMainDecisionAIModule::TribeMainDecisionAIModule(
    int p1, char* p2, TRIBE_Player* p3, int file)
    : MainDecisionAIModule(p1, p3, file),
      buildAI(p1, file),
      constructionAI(p1, file),
      diplomacyAI(p1, file),
      emotionalAI(p1, file),
      informationAI(p1, file),
      resourceAI(p1, file),
      strategyAI(p1, file),
      tacticalAI(p1, file),
      tradeAI(p1, file),
      firstUpdate(0),
      veryFirstUpdate(0),
      updateDelay(p1),
      lastDiplomacyUpdateTime(0),
      lastTacticalUpdateTime(0),
      decidedInitialDiplomacy(0),
      requiredDiplomacyTributeAmount(0)
{
    this->aiPlayer = p3;
    this->setPlayer(p1, p2);
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

    this->buildAI.setPlayer(p1, p2);
    this->constructionAI.setPlayer(p1, p2);
    this->diplomacyAI.setPlayer(p1, p2);
    this->emotionalAI.setPlayer(p1, p2);
    this->informationAI.setPlayer(p1, p2);
    this->resourceAI.setPlayer(p1, p2);
    this->strategyAI.setPlayer(p1, p2);
    this->tacticalAI.setPlayer(p1, p2);
    this->tradeAI.setPlayer(p1, p2);

    rge_read(file, &this->updateDelay, 4);
    rge_read(file, &this->lastDiplomacyUpdateTime, 4);
    rge_read(file, &this->lastTacticalUpdateTime, 4);

    if (g_time >= DAT_00575618) {
        rge_read(file, &this->lastTributeChatTime, 4);
        rge_read(file, &this->tributeChatTimeout, 4);
        rge_read(file, &this->waitingOnTribute, 4);
        rge_read(file, &this->tributeExpirationTimeout, 4);
        rge_read(file, &this->tributeAddressed, 4);
        rge_read(file, &this->tributeAmount, 4);
    }
    if (g_time >= DAT_0057561c) {
        rge_read(file, &this->decidedInitialDiplomacy, 4);
        rge_read(file, &this->requiredDiplomacyTributeAmount, 4);
        rge_read(file, this->tributeGiven, 0x24);
    } else {
        memset(this->tributeGiven, 0, 0x24);
    }
}

TribeMainDecisionAIModule::~TribeMainDecisionAIModule()
{
}

void TribeMainDecisionAIModule::setLogHistory(int value)
{
    buildAI.setLogHistory(value);
    constructionAI.setLogHistory(value);
    diplomacyAI.setLogHistory(value);
    emotionalAI.setLogHistory(value);
    informationAI.setLogHistory(value);
    resourceAI.setLogHistory(value);
    strategyAI.setLogHistory(value);
    tacticalAI.setLogHistory(value);
    tradeAI.setLogHistory(value);
    MainDecisionAIModule::setLogHistory(value);
}

int TribeMainDecisionAIModule::update(int)
{
    TribeTacticalAIModule* tactical = &this->tacticalAI;
    char tempString[256];

    if (this->player->world->game_state == 0 && this->firstUpdate == 1) {
        this->firstUpdate = 0;
        this->logCommonHistory("Initial Diplomacy Settings:");
        for (int i = 1; i < this->player->world->player_num; i++) {
            this->logCommonHistory(
                "  Player #%d: Dislike=%d, Like=%d, Ambivalence=%d.",
                i,
                this->diplomacyAI.stance(i, 0),
                this->diplomacyAI.stance(i, 2),
                this->diplomacyAI.stance(i, 1));
        }

        this->strategyAI.update(0);
        this->buildAI.initialize();
        this->informationAI.initialize();
        this->setTributeChat();

        if (tactical->strategicNumber(0x81) == 1 &&
            tactical->strategicNumber(0x7D) == 0) {
            this->waitingOnTribute = 1;
            this->tributeAmount = 0;
        }

        int value = tactical->strategicNumber(0x8A);
        if (value != 0)
            this->player->command_add_attribute(0, (float)value);
        value = tactical->strategicNumber(0x8B);
        if (value != 0)
            this->player->command_add_attribute(3, (float)value);
        value = tactical->strategicNumber(0x8C);
        if (value != 0)
            this->player->command_add_attribute(2, (float)value);
        value = tactical->strategicNumber(0x8D);
        if (value != 0)
            this->player->command_add_attribute(1, (float)value);
    }

    this->updateDelay++;
    if (this->updateDelay >= 20) {
        this->strategyAI.update(0);
        this->updateDelay = 0;
    }
    this->informationAI.update(0);

    if ((this->player->world->world_time -
         this->lastDiplomacyUpdateTime) / 1000 >= 60) {
        this->diplomacyAI.update(0);
        this->lastDiplomacyUpdateTime = this->player->world->world_time;
    }

    unsigned long tributeElapsed =
        (this->player->world->world_time - this->lastTributeChatTime) / 1000;
    if (tactical->strategicNumber(0x7C) > 0 &&
        this->tributeAddressed == 0) {
        if (tributeElapsed >= (unsigned long)this->tributeChatTimeout &&
            tactical->strategicNumber(0x7D) > 0) {
            if (this->waitingOnTribute == 0) {
                this->waitingOnTribute = 1;
                int expirationTimeout = tactical->strategicNumber(0x7F);
                this->tributeAmount = 0;
                this->tributeExpirationTimeout = expirationTimeout * 1000;
            }

            this->lastTributeChatTime = this->player->world->world_time;
            if (tactical->strategicNumber(0x82) == 1) {
                if (this->tributeAmount > 0) {
                    rge_base_game->get_string(0x902, tempString, 0x100);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(0x80), 0, tempString,
                        tactical->strategicNumber(0x7C) - this->tributeAmount);
                } else {
                    rge_base_game->get_string(0x903, tempString, 0x100);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(0x80), 0, tempString,
                        tactical->strategicNumber(0x7C));
                }
            } else if (tactical->strategicNumber(0x81) == 1) {
                if (this->tributeAmount > 0) {
                    rge_base_game->get_string(0x904, tempString, 0x100);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(0x80), 0, tempString,
                        tactical->strategicNumber(0x7C));
                } else {
                    rge_base_game->get_string(0x905, tempString, 0x100);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(0x80), 0, tempString,
                        tactical->strategicNumber(0x7C) - this->tributeAmount);
                }
            }
            this->setTributeChat();
        } else if (this->waitingOnTribute == 1) {
            this->tributeExpirationTimeout -=
                this->player->world->world_time_delta;
            if (this->tributeExpirationTimeout <= 0) {
                if (tactical->strategicNumber(0x82) == 1) {
                    this->diplomacyAI.setStance(
                        tactical->strategicNumber(0x80), 0, 100);
                    this->diplomacyAI.setStance(
                        tactical->strategicNumber(0x80), 2, 0);
                    this->aiPlayer->setDiplomaticStance(
                        tactical->strategicNumber(0x80), 3);
                    rge_base_game->get_string(0x901, tempString, 0x100);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(0x80), 0, tempString);
                    this->waitingOnTribute = 0;
                    this->tributeAddressed = 1;
                    this->lastTributeChatTime =
                        this->player->world->world_time;
                } else if (tactical->strategicNumber(0x81) == 1) {
                    rge_base_game->get_string(0x900, tempString, 0x100);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(0x80), 0, tempString);
                    this->waitingOnTribute = 0;
                    this->lastTributeChatTime =
                        this->player->world->world_time;
                    this->tributeAddressed =
                        tactical->strategicNumber(0x84) == 0;
                }
            } else if (this->tributeAmount >=
                       tactical->strategicNumber(0x7C)) {
                if (tactical->strategicNumber(0x81) == 1) {
                    this->diplomacyAI.setStance(
                        tactical->strategicNumber(0x80), 0, 0);
                    this->diplomacyAI.setStance(
                        tactical->strategicNumber(0x80), 2, 100);
                    this->aiPlayer->setDiplomaticStance(
                        tactical->strategicNumber(0x80), 0);
                    rge_base_game->get_string(0x8FF, tempString, 0x100);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(0x80), 0, tempString);
                    this->waitingOnTribute = 0;
                    this->lastTributeChatTime =
                        this->player->world->world_time;
                    this->tributeAddressed =
                        tactical->strategicNumber(0x84) == 0;
                } else if (tactical->strategicNumber(0x82) == 1) {
                    rge_base_game->get_string(0x8FE, tempString, 0x100);
                    this->player->sendChatMessage(
                        tactical->strategicNumber(0x80), 0, tempString);
                    this->waitingOnTribute = 0;
                    this->lastTributeChatTime =
                        this->player->world->world_time;
                    this->tributeAddressed =
                        tactical->strategicNumber(0x84) == 0;
                }
            }
        }
    }

    if (this->decidedInitialDiplomacy == 0 &&
        this->player->world->world_time > 10000) {
        this->decidedInitialDiplomacy = 1;
        TRIBE_World* world =
            static_cast<TRIBE_World*>(this->player->world);
        int computerPlayers = 0;
        int humanPlayers = 0;
        int neutralComputerPlayers = 0;
        int neutralList[9];

        for (int i = 1; i < world->player_num; i++) {
            RGE_Player* other = world->players[i];
            if (other->computerPlayer() == 0) {
                humanPlayers++;
            } else {
                computerPlayers++;
                if (other->isAllNeutral() == 1) {
                    neutralList[i] = 1;
                    neutralComputerPlayers++;
                } else {
                    neutralList[i] = 0;
                }
            }
        }

        if (world->controllingComputerPlayer == (unsigned char)-1) {
            if (computerPlayers == 1) {
                world->controllingComputerPlayer = (unsigned char)this->player->id;
            } else {
                int selection =
                    debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x236) %
                        computerPlayers +
                    1;
                for (int i = 1; i < world->player_num; i++) {
                    RGE_Player* other = world->players[i];
                    if (other->computerPlayer() == 1) {
                        selection--;
                        if (selection == 0)
                            world->controllingComputerPlayer =
                                (unsigned char)other->id;
                    }
                }
            }
        }

        if (world->controllingComputerPlayer ==
            (unsigned char)this->player->id) {
            int numberToSway = (computerPlayers - humanPlayers) / 2;
            if (numberToSway < 0)
                numberToSway = 0;
            if (numberToSway > neutralComputerPlayers)
                numberToSway = neutralComputerPlayers;
            if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1)
                numberToSway = 0;

            if (numberToSway <= neutralComputerPlayers &&
                neutralComputerPlayers > 0) {
                ManagedArray<int> swayableCPs;
                for (int i = 1; i < world->player_num; i++) {
                    RGE_Player* other = world->players[i];
                    if (other->computerPlayer() != 0 && neutralList[i] != 0 &&
                        (unsigned short)world->controllingComputerPlayer !=
                            (unsigned short)other->id &&
                        swayableCPs.number() < numberToSway) {
                        swayableCPs.add(i);
                    }
                }

                int tribute = 2000;
                switch (rge_base_game->difficulty()) {
                case 0:
                    tribute =
                        debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x26E) %
                            500 +
                        1400;
                    break;
                case 1:
                    tribute =
                        debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x26F) %
                            400 +
                        1000;
                    break;
                case 2:
                    tribute =
                        debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x270) %
                            300 +
                        700;
                    break;
                case 3:
                    tribute =
                        debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x271) %
                            200 +
                        450;
                    break;
                case 4:
                    tribute =
                        debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x272) %
                            100 +
                        300;
                    break;
                }

                for (int neutralPlayer = 1;
                     neutralPlayer < world->player_num;
                     neutralPlayer++) {
                    RGE_Player* other = world->players[neutralPlayer];
                    if (other->computerPlayer() == 0 ||
                        neutralList[neutralPlayer] == 0)
                        continue;

                    if (swayableCPs.contains(neutralPlayer)) {
                        other->sendAICommand(
                            this->player->id, 7, tribute, 0, 0);
                        tribute *= 2;
                    }

                    for (int j = 1; j < world->player_num; j++) {
                        if (j == neutralPlayer)
                            continue;
                        RGE_Player* target = world->players[j];
                        if (target->computerPlayer() == 0 &&
                            !swayableCPs.contains(neutralPlayer)) {
                            other->sendAICommand(
                                this->player->id, 6, j, 0, 0);
                        } else if (target->computerPlayer() == 1) {
                            other->sendAICommand(
                                this->player->id, 6, j, 2, 0);
                        }
                    }
                }
            }
        }
    }

    if (tactical->strategicNumber(0xD9) == 1) {
        int diplomacyStartTime =
            (tactical->strategicNumber(0x68) - 3) * 1000;
        if (diplomacyStartTime < 0)
            diplomacyStartTime = 0;
        if (this->player->world->world_time >
            (unsigned long)diplomacyStartTime) {
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
                    this->player->sendAICommand(
                        this->player->id, 6, newEnemy, 0, 0);
                }
                for (int relationPlayer = 1;
                     relationPlayer < this->player->world->player_num;
                     relationPlayer++) {
                    if (relationPlayer == this->player->id ||
                        relationPlayer == newEnemy)
                        continue;
                    RGE_Player* other =
                        this->player->world->players[relationPlayer];
                    if (other->isEnemy(newEnemy) == 1) {
                        this->player->sendAICommand(
                            this->player->id, 6, relationPlayer, 2, 0);
                        if (other->computerPlayer() == 1) {
                            other->sendAICommand(
                                this->player->id, 6, this->player->id, 2, 0);
                        }
                    } else if (other->isAlly(newEnemy) == 1) {
                        this->player->sendAICommand(
                            this->player->id, 6, relationPlayer, 0, 0);
                    }
                }
            }
        }
    }

    if (this->player->world->game_state == 0 &&
        this->player->world->currentUpdateComputerPlayer ==
            this->player->id) {
        this->tacticalAI.update(0);
        this->lastTacticalUpdateTime = this->player->world->world_time;
    }
    return 1;
}

int TribeMainDecisionAIModule::save(int file)
{
    MainDecisionAIModule::save(file);

    this->buildAI.save(file);
    this->constructionAI.save(file);
    this->diplomacyAI.save(file);
    this->emotionalAI.save(file);
    this->informationAI.save(file);
    this->resourceAI.save(file);
    this->strategyAI.save(file);
    this->tacticalAI.save(file);
    this->tradeAI.save(file);

    rge_write(file, &this->updateDelay, 4);
    rge_write(file, &this->lastDiplomacyUpdateTime, 4);
    rge_write(file, &this->lastTacticalUpdateTime, 4);
    rge_write(file, &this->lastTributeChatTime, 4);
    rge_write(file, &this->tributeChatTimeout, 4);
    rge_write(file, &this->waitingOnTribute, 4);
    rge_write(file, &this->tributeExpirationTimeout, 4);
    rge_write(file, &this->tributeAddressed, 4);
    rge_write(file, &this->tributeAmount, 4);
    rge_write(file, &this->decidedInitialDiplomacy, 4);
    rge_write(file, &this->requiredDiplomacyTributeAmount, 4);
    rge_write(file, this->tributeGiven, 0x24);

    return 1;
}

void TribeMainDecisionAIModule::kick(int param_1)
{
    this->logCommonHistory("Got a kick=%d.", param_1);
    if (param_1 == 1) {
        this->buildAI.skipNextBuildListItem();
    }
    if (param_1 == 2) {
        this->buildAI.insert(0x53, 1, -1);
    }
    if (param_1 == 3) {
        this->logCommonHistory("Current Build list is:");
        this->buildAI.displayBuildList();
    }
}

int TribeMainDecisionAIModule::addObject(RGE_Static_Object* object)
{
    if (object == 0) {
        return 0;
    }
    tacticalAI.addObject(object);
    informationAI.addObject(object);
    return MainDecisionAIModule::addObject(object);
}

int TribeMainDecisionAIModule::removeObject(int object_id)
{
    this->tacticalAI.removeObject(object_id);
    this->buildAI.removeBuiltItem(object_id);
    this->informationAI.removeObject(object_id);
    return MainDecisionAIModule::removeObject(object_id);
}

int TribeMainDecisionAIModule::objectGroupThatCanPerformAction(int action)
{
    switch (action) {
    case 0x25a:
    case 0x25d:
    case 0x261:
    case 0x265:
        return 4;
    case 0x26b:
    case 0x26c:
        return 3;
    default:
        return MainDecisionAIModule::objectGroupThatCanPerformAction(action);
    }
}

int TribeMainDecisionAIModule::canPerformAction(int param_1, int param_2)
{
    RGE_Static_Object* object = this->object(param_1);
    if (object != 0) {
        if (object->master_obj->object_group ==
            this->objectGroupThatCanPerformAction(param_2)) {
            return 1;
        }
    }
    return 0;
}

void TribeMainDecisionAIModule::detask(int param)
{
    this->tacticalAI.detask(param);
}

int TribeMainDecisionAIModule::isMoveable(int id)
{
    RGE_Static_Object* obj = this->object(id);
    if (obj == 0)
        return 0;

    short group = obj->master_obj->object_group;
    if (group == 3 || group == 0x1B || group == 0x1E || group == 0x1F ||
        group == 5 || group == 0x21 || group == 7 || group == 8 ||
        group == 0x20 || group == 0x10 || group == 0x0E || group == 0x0F)
        return 0;

    return 1;
}

void TribeMainDecisionAIModule::updateBuildAIWithObjects()
{
    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object = this->object(this->objects[i]);
        if (object != 0) {
            this->buildAI.addItem(object, 0);
            if (object->master_obj->id == 0x6d) {
                this->constructionAI.setReferencePoint(
                    this->player->world->map->map_width,
                    this->player->world->map->map_height,
                    object->world_x,
                    object->world_y,
                    object->world_z);
            }
        }
    }
}

void TribeMainDecisionAIModule::tributeNotify(int player, int notification,
                                               int amount)
{
    char tempString[256];

    if (this->waitingOnTribute == 1 &&
        player == this->tacticalAI.strategicNumber(0x80) &&
        notification == 3) {
        this->tributeAmount += amount;
        return;
    }

    TribeTacticalAIModule* tactical = &this->tacticalAI;
    if (player != tactical->strategicNumber(0x80)) {
        int tribute = amount / 100;
        this->diplomacyAI.changeStance(player, 2, tribute);
        this->diplomacyAI.changeStance(player, 0, -tribute);
        this->tributeGiven[player] += amount;

        if (this->player->isNeutral(player) == 1 &&
            tactical->strategicNumber(0xD9) == 1 &&
            this->tributeGiven[player] >=
                this->requiredDiplomacyTributeAmount) {
            this->player->sendAICommand(this->player->id, 6, player, 2, 0);
            rge_base_game->get_string(0x907, tempString, 0x100);
            this->player->sendChatMessage(player, 0, tempString);

            RGE_Player* newAlly = this->player->world->players[player];
            for (int i = 1; i < this->player->world->player_num; ++i) {
                if (i != this->player->id && i != player) {
                    if (newAlly->isAlly(i) == 1) {
                        this->player->sendAICommand(
                            this->player->id, 6, i, 2, 0);
                    }
                    else if (newAlly->isEnemy(i) == 1) {
                        this->player->sendAICommand(
                            this->player->id, 6, i, 0, 0);
                    }
                }
            }

            tactical->setStrategicNumber(0xD9, 0);
        }
        else if (this->player->isEnemy(player) == 1) {
            rge_base_game->get_string(0x906, tempString, 0x100);
            this->player->sendChatMessage(player, 0, tempString);
        }
    }
}

void TribeMainDecisionAIModule::revokeTributeAlliance()
{
    char tempString[256];
    TribeTacticalAIModule* tactical = &this->tacticalAI;

    if (this->player->isEnemy(tactical->strategicNumber(0x80)) == 0) {
        this->diplomacyAI.setStance(
            tactical->strategicNumber(0x80), 0, 0);
        this->diplomacyAI.setStance(
            tactical->strategicNumber(0x80), 2, 100);
        this->aiPlayer->setDiplomaticStance(
            tactical->strategicNumber(0x80), 3);
        rge_base_game->get_string(0x8FD, tempString, 0x100);
        this->player->sendChatMessage(
            tactical->strategicNumber(0x80), 0, tempString);
        this->waitingOnTribute = 0;
        this->tributeAddressed = 1;
    }
}

// Naming the random result before the arithmetic preserves the
void TribeMainDecisionAIModule::setTributeChat()
{
    TribeTacticalAIModule* tactical = &this->tacticalAI;
    if (tactical->strategicNumber(0x7E) > 0) {
        int randomValue =
            debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x41D);
        this->tributeChatTimeout =
            randomValue % tactical->strategicNumber(0x7E) -
            tactical->strategicNumber(0x7E) / 2 +
            tactical->strategicNumber(0x7D);
    } else {
        this->tributeChatTimeout = tactical->strategicNumber(0x7D);
    }
}

int TribeMainDecisionAIModule::processAICommand(int player, int command,
                                                int value, int amount,
                                                int extra)
{
    switch (command) {
    case 0:
        this->informationAI.lookAtMap();
        return 1;

    case 1:
        if (player != this->player->id &&
            this->aiPlayer->objects->find_by_master_id(
                0x54, -1.0f, -1.0f, 0, 2, 0) != 0) {
            float current = this->aiPlayer->attributes[0x2E];
            this->aiPlayer->command_give_attribute(
                player, value, (float)amount,
                current);
            return 1;
        }
        break;

    case 2:
    case 3:
        if (player != this->player->id) {
            this->tacticalAI.processCoopAttack(player, value, amount, extra);
            return 1;
        }
        break;

    case 7:
        this->requiredDiplomacyTributeAmount = value;
        this->tacticalAI.setStrategicNumber(0xD9, 1);
        return 1;

    case 6: {
        this->diplomacyAI.setChangeable(value, 1);
        switch (amount) {
        case 0:
            this->diplomacyAI.setStance(value, 0, 100);
            this->diplomacyAI.setRelation(value, 3);
            break;

        case 1:
            this->diplomacyAI.setStance(value, 0, 0x31);
            this->diplomacyAI.setStance(value, 2, 0x31);
            this->diplomacyAI.setRelation(value, 1);
            break;

        case 2:
            this->diplomacyAI.setStance(value, 2, 100);
            this->diplomacyAI.setRelation(value, 0);
            if (rge_base_game->difficulty() == 4) {
                if (this->player->world->players[value]->computerPlayer() == 0) {
                    static_cast<TRIBE_Command*>(this->player->world->commands)
                        ->command_allied_victory(
                        this->player->id, 1);
                    this->diplomacyAI.setChangeable(value, 0);
                    return 1;
                } else {
                    static_cast<TRIBE_Command*>(this->player->world->commands)
                        ->command_allied_victory(
                        this->player->id, 0);
                    this->diplomacyAI.setChangeable(value, 0);
                    return 1;
                }
            } else {
                static_cast<TRIBE_Command*>(this->player->world->commands)
                    ->command_allied_victory(
                    this->player->id, 1);
                this->diplomacyAI.setChangeable(value, 0);
                return 1;
            }

        default:
            break;
        }
        this->diplomacyAI.setChangeable(value, 0);
        break;
    }

    default:
        return 0;
    }

    return 1;
}

int TribeMainDecisionAIModule::currentScore(int index)
{
    if (index >= 1 && index <= this->player->world->player_num)
        return this->player->world->players[index]
            ->victory_conditions->get_victory_points();
    return -1;
}
