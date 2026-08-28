// PDB source module: C:\\msdev\\work\\age1_x1\\taimdmd.cpp.
// Definitions follow the original PDB source order.

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
extern int rgeLog;
extern float g_time;
extern float g_cut1;
extern float g_cut2;

// PDB lines 89-151; VA 004E4800.
// BINARY NOTE: The shipped constructor stores the derived vptr at +0x155,
// after field initialization. VC5 emits that store at +0xF7 here.
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
      tradeAI(p1, p2)
{
    this->firstUpdate = 1;
    this->veryFirstUpdate = 1;
    this->aiPlayer = (TRIBE_Player*)player;
    this->updateDelay = p2;
    this->lastDiplomacyUpdateTime = 0;
    this->lastTacticalUpdateTime = 0;
    this->lastTributeChatTime = 0;
    this->tributeChatTimeout = 0;
    this->waitingOnTribute = 0;
    this->tributeExpirationTimeout = 0;
    this->tributeAddressed = 0;
    this->tributeAmount = 0;
    this->decidedInitialDiplomacy = 0;
    this->requiredDiplomacyTributeAmount = 0;
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

// PDB lines 175-231; VA 004E4B80.
// BINARY NOTE: The shipped load constructor stores its derived vptr at +0x114,
// after field initialization. VC5 emits that store at +0xEA here.
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
      tradeAI(p1, file)
{
    this->firstUpdate = 0;
    this->veryFirstUpdate = 0;
    this->updateDelay = p1;
    this->lastDiplomacyUpdateTime = 0;
    this->lastTacticalUpdateTime = 0;
    this->decidedInitialDiplomacy = 0;
    this->requiredDiplomacyTributeAmount = 0;
    this->aiPlayer = p3;
    this->setPlayer(p1, p2);
    if (rgeLog != 0) {
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

    if (g_time >= g_cut1) {
        rge_read(file, &this->lastTributeChatTime, 4);
        rge_read(file, &this->tributeChatTimeout, 4);
        rge_read(file, &this->waitingOnTribute, 4);
        rge_read(file, &this->tributeExpirationTimeout, 4);
        rge_read(file, &this->tributeAddressed, 4);
        rge_read(file, &this->tributeAmount, 4);
    }
    if (g_time >= g_cut2) {
        rge_read(file, &this->decidedInitialDiplomacy, 4);
        rge_read(file, &this->requiredDiplomacyTributeAmount, 4);
        rge_read(file, this->tributeGiven, 0x24);
    } else {
        memset(this->tributeGiven, 0, 0x24);
    }
}

// PDB lines 236-237; VA 004E4EC0.
// The natural virtual destructor matched in the standalone context.
TribeMainDecisionAIModule::~TribeMainDecisionAIModule()
{
}

// PDB lines 242-253; VA 004E4FA0.
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

// PDB lines 258-784; VA 004E5050.
// BINARY NOTE: The clean source retains the natural local model. The shipped
// attribute result uses [esp+1Ch], while this source emits [esp+10h].
// BINARY NOTE: The first swayable scan jumps to the shared increment tail.
int TribeMainDecisionAIModule::update(int param_1)
{
    int newEnemy;
    TRIBE_World* world;
    int numberNeutralCPs;
    int numberHumanPlayers;
    int neutralList[9];
    char tempString[256];

    if (this->player->world->game_state == 0 && this->firstUpdate == 1) {
        this->firstUpdate = 0;
        this->logCommonHistory("Initial Diplomacy Settings:");

        int playerIndex = 1;
        if (this->player->world->player_num > playerIndex) {
            DiplomacyAIModule* diplomacy = &this->diplomacyAI;
            do {
                this->logCommonHistory(
                    "  Player #%d: Dislike=%d, Like=%d, Ambivalence=%d.",
                    playerIndex,
                    diplomacy->stance(playerIndex, 0),
                    diplomacy->stance(playerIndex, 2),
                    diplomacy->stance(playerIndex, 1));
                playerIndex++;
            } while (playerIndex < this->player->world->player_num);
        }
        ((StrategyAIModule*)&this->strategyAI)->update(0);
        this->buildAI.initialize();
        this->informationAI.initialize();
        this->setTributeChat();

        TribeTacticalAIModule* tactical = &this->tacticalAI;
        if (tactical->strategicNumber(0x81) == 1 &&
            tactical->strategicNumber(0x7D) == 0) {
            this->waitingOnTribute = 1;
            this->tributeAmount = 0;
        }

        {
            int amount = tactical->strategicNumber(0x8A);
            if (amount != 0) {
                this->player->command_add_attribute(0, (float)amount);
            }
        }
        {
            int amount = tactical->strategicNumber(0x8B);
            if (amount != 0) {
                this->player->command_add_attribute(3, (float)amount);
            }
        }
        {
            int amount = tactical->strategicNumber(0x8C);
            if (amount != 0) {
                this->player->command_add_attribute(2, (float)amount);
            }
        }
        {
            int amount = tactical->strategicNumber(0x8D);
            if (amount != 0) {
                this->player->command_add_attribute(1, (float)amount);
            }
        }
    }

    this->updateDelay++;
    if (this->updateDelay >= 0x14) {
        ((StrategyAIModule*)&this->strategyAI)->update(0);
        this->updateDelay = 0;
    }
    this->informationAI.update(0);

    if ((this->player->world->world_time - this->lastDiplomacyUpdateTime) /
            1000 < 60) {
        // No diplomacy refresh is due yet.
    } else {
        this->diplomacyAI.update(0);
        this->lastDiplomacyUpdateTime = this->player->world->world_time;
    }

    TribeTacticalAIModule* tactical = &this->tacticalAI;
    unsigned long tributeLastTime = this->lastTributeChatTime;
    unsigned long tributeElapsed =
        (this->player->world->world_time - tributeLastTime) / 1000;
    int tributeSetting = tactical->strategicNumber(0x7C);
    if (tributeSetting > 0 && this->tributeAddressed == 0) {
        if (tributeElapsed < this->tributeChatTimeout ||
            tactical->strategicNumber(0x7D) <= 0) {
            if (this->waitingOnTribute == 1) {
                this->tributeExpirationTimeout -=
                    this->player->world->world_time_delta;
                if (this->tributeExpirationTimeout <= 0) {
                    if (tactical->strategicNumber(0x82) == 1) {
                        int stanceValue = tactical->strategicNumber(0x80);
                        this->diplomacyAI.setStance(stanceValue, 0, 100);
                        stanceValue = tactical->strategicNumber(0x80);
                        this->diplomacyAI.setStance(stanceValue, 2, 0);
                        this->player->setDiplomaticStance(
                            tactical->strategicNumber(0x80), 3);
                        rge_base_game->get_string(
                            (long)0x901, tempString, 0x100);
                        this->player->sendChatMessage(
                            tactical->strategicNumber(0x80), 0, tempString);
                        this->waitingOnTribute = 0;
                        this->tributeAddressed = 1;
                        this->lastTributeChatTime =
                            this->player->world->world_time;
                    } else if (tactical->strategicNumber(0x81) == 1) {
                        rge_base_game->get_string(
                            (long)0x900, tempString, 0x100);
                        goto tribute_response_send;
                    }
                } else {
                    if (this->tributeAmount >=
                        tactical->strategicNumber(0x7C)) {
                        if (tactical->strategicNumber(0x81) == 1) {
                            int stanceValue = tactical->strategicNumber(0x80);
                            this->diplomacyAI.setStance(stanceValue, 0, 0);
                            stanceValue = tactical->strategicNumber(0x80);
                            this->diplomacyAI.setStance(stanceValue, 2, 100);
                            this->player->setDiplomaticStance(
                                tactical->strategicNumber(0x80), 0);
                            rge_base_game->get_string(
                                (long)0x8FF, tempString, 0x100);
                            goto tribute_response_send;
                        } else if (tactical->strategicNumber(0x82) == 1) {
                            rge_base_game->get_string(
                                (long)0x8FE, tempString, 0x100);
                            this->player->sendChatMessage(
                                tactical->strategicNumber(0x80), 0, tempString);
                            this->waitingOnTribute = 0;
                            this->lastTributeChatTime =
                                this->player->world->world_time;
                            goto tribute_response_addressed;
                        }
                    }
                }
                goto tribute_response_done;

tribute_response_send:
                this->player->sendChatMessage(
                    tactical->strategicNumber(0x80), 0, tempString);
                this->waitingOnTribute = 0;
                this->lastTributeChatTime = this->player->world->world_time;

tribute_response_addressed:
                this->tributeAddressed =
                    tactical->strategicNumber(0x84) == 0;

tribute_response_done:
                ;
            }
        } else {
            if (this->waitingOnTribute == 0) {
                this->waitingOnTribute = 1;
                this->tributeAmount = 0;
                this->tributeExpirationTimeout =
                    tactical->strategicNumber(0x7F) * 1000;
            }
            this->lastTributeChatTime = this->player->world->world_time;
            int tribute = 0;
            if (tactical->strategicNumber(0x82) == 1) {
                if (this->tributeAmount > 0) {
                    rge_base_game->get_string(
                        (long)0x902, tempString, 0x100);
                    tribute = tactical->strategicNumber(0x7C) -
                              this->tributeAmount;
                    goto tribute_chat_send_one;
                } else {
                    rge_base_game->get_string(
                        (long)0x903, tempString, 0x100);
                    tribute = tactical->strategicNumber(0x7C);
                    goto tribute_chat_send_two;
                }
            } else {
                if (tactical->strategicNumber(0x81) != 1) {
                    goto tribute_chat_done;
                }
                if (this->tributeAmount > 0) {
                    rge_base_game->get_string(
                        (long)0x904, tempString, 0x100);
                    tribute = tactical->strategicNumber(0x7C);
                    goto tribute_chat_send_one;
                } else {
                    rge_base_game->get_string(
                        (long)0x905, tempString, 0x100);
                    tribute = tactical->strategicNumber(0x7C) -
                              this->tributeAmount;
                    goto tribute_chat_send_two;
                }
            }

tribute_chat_send_one:
            this->player->sendChatMessage(
                tactical->strategicNumber(0x80), 0, tempString, tribute);
            this->setTributeChat();
            goto tribute_chat_done;

tribute_chat_send_two:
            this->player->sendChatMessage(
                tactical->strategicNumber(0x80), 0, tempString, tribute);
            this->setTributeChat();

tribute_chat_done:
            ;
        }
    }

    if (this->decidedInitialDiplomacy == 0 &&
        this->player->world->world_time > 10000) {
        this->decidedInitialDiplomacy = 1;
        world = (TRIBE_World*)this->player->world;
        newEnemy = 0;
        numberNeutralCPs = 0;
        numberHumanPlayers = 0;

        int playerIndex = 1;
        if (playerIndex < world->player_num) {
            do {
                RGE_Player* player = world->players[playerIndex];
                if (player->computerPlayer() == 0) {
                    numberHumanPlayers++;
                } else {
                    newEnemy++;
                    if (player->isAllNeutral() == 1) {
                        neutralList[playerIndex] = 1;
                        numberNeutralCPs++;
                    } else {
                        neutralList[playerIndex] = 0;
                    }
                }
                playerIndex++;
            } while (playerIndex < world->player_num);
        }

        if (world->controllingComputerPlayer == 0xFF) {
            if (newEnemy == 1) {
                world->controllingComputerPlayer = (uchar)this->player->id;
            } else {
                int selected =
                    debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp",
                               0x236) % newEnemy + 1;
                int playerIndex = 1;
                if (playerIndex < world->player_num) do {
                    RGE_Player* player = world->players[playerIndex];
                    if (player->computerPlayer() == 1) {
                        selected--;
                        if (selected == 0) {
                            world->controllingComputerPlayer =
                                (uchar)player->id;
                        }
                    }
                    playerIndex++;
                } while (playerIndex < world->player_num);
            }
        }

        if (world->controllingComputerPlayer == (uchar)this->player->id) {
            newEnemy = (newEnemy - numberHumanPlayers) / 2;
            if (newEnemy < 0) {
                newEnemy = 0;
            }
            if (numberNeutralCPs < newEnemy) {
                newEnemy = numberNeutralCPs;
            }
            if (((TRIBE_Game*)rge_base_game)->deathMatch() == 1) {
                newEnemy = 0;
            }

            if (newEnemy <= numberNeutralCPs && numberNeutralCPs > 0) {
                ManagedArray<int> swayableCPs;
                numberNeutralCPs = 1;
                while (numberNeutralCPs < world->player_num) {
                    RGE_Player* player = world->players[numberNeutralCPs];
                    if (player->computerPlayer() != 0 &&
                        neutralList[numberNeutralCPs] != 0) {
                        for (int i = 0; i < swayableCPs.numberValue; i++) {
                            if (swayableCPs.maximumSizeValue <= i) {
                                break;
                            }
                            if (swayableCPs.value[i] == numberNeutralCPs) {
                                goto swayable_next_player;
                            }
                        }
                        if (swayableCPs.numberValue < newEnemy) {
                            swayableCPs[swayableCPs.numberValue] =
                                numberNeutralCPs;
                            swayableCPs.numberValue++;
                        }
                    }

swayable_next_player:
                    numberNeutralCPs++;
                }

                newEnemy = 2000;
                switch (rge_base_game->difficulty()) {
                case 0:
                    newEnemy =
                        debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp",
                                   0x26E) % 500 + 0x578;
                    break;
                case 1:
                    newEnemy =
                        debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp",
                                   0x26F) % 400 + 1000;
                    break;
                case 2:
                    newEnemy =
                        debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp",
                                   0x270) % 300 + 700;
                    break;
                case 3:
                    newEnemy =
                        debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp",
                                   0x271) % 200 + 0x1C2;
                    break;
                case 4:
                    newEnemy =
                        debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp",
                                   0x272) % 100 + 300;
                    break;
                }

                numberNeutralCPs = 1;
                while (numberNeutralCPs < world->player_num) {
                    RGE_Player* player = world->players[numberNeutralCPs];
                    if (player->computerPlayer() != 0 &&
                        neutralList[numberNeutralCPs] != 0) {
                        int found = 0;
                        for (int i = 0; i < swayableCPs.numberValue; i++) {
                            if (swayableCPs.maximumSizeValue <= i) {
                                break;
                            }
                            if (swayableCPs.value[i] == numberNeutralCPs) {
                                found = 1;
                                break;
                            }
                        }
                        if (found) {
                            player->sendAICommand(
                                (int)this->player->id, 7, newEnemy, 0, 0);
                            newEnemy = newEnemy + newEnemy;
                        }

                        for (int otherIndex = 1;
                             otherIndex < world->player_num; otherIndex++) {
                            if (numberNeutralCPs != otherIndex) {
                                RGE_Player* other =
                                    world->players[otherIndex];
                                if (other->computerPlayer() == 0) {
                                    int otherFound = 0;
                                    for (int i = 0;
                                         i < swayableCPs.numberValue; i++) {
                                        if (swayableCPs.maximumSizeValue <= i) {
                                            break;
                                        }
                                        if (swayableCPs.value[i] ==
                                            numberNeutralCPs) {
                                            otherFound = 1;
                                            break;
                                        }
                                    }
                                    if (otherFound) {
                                        if (other->computerPlayer() == 1) {
                                            player->sendAICommand(
                                                (int)this->player->id, 6,
                                                otherIndex, 2, 0);
                                        }
                                    } else {
                                        player->sendAICommand(
                                            (int)this->player->id, 6,
                                            otherIndex, 0, 0);
                                    }
                                } else {
                                    player->sendAICommand(
                                        (int)this->player->id, 6,
                                        otherIndex, 2, 0);
                                }
                            }
                        }
                    }
                    numberNeutralCPs++;
                }
            }
        }
    }

    if (tactical->strategicNumber(0xD9) == 1) {
        unsigned int timeout = (unsigned int)(
            (tactical->strategicNumber(0x68) - 3) * 1000);
        if ((int)timeout < 0) {
            timeout = 0;
        }
        if (timeout < this->player->world->world_time) {
            tactical->setStrategicNumber(0xD9, 0);
            int newPlayer = -1;
            for (int playerIndex = 1;
                 playerIndex < this->player->world->player_num;
                 playerIndex++) {
                if (this->player->world->players[playerIndex]->computerPlayer() !=
                    1) {
                    newPlayer = playerIndex;
                    break;
                }
            }
            if (newPlayer != -1) {
                if (this->player->isEnemy(newPlayer) == 0) {
                    this->player->sendAICommand(
                        (int)this->player->id, 6, newPlayer, 0, 0);
                }
                for (int playerIndex = 1;
                     playerIndex < this->player->world->player_num;
                     playerIndex++) {
                    if (playerIndex != this->player->id &&
                        playerIndex != newPlayer) {
                        RGE_Player* player =
                            this->player->world->players[playerIndex];
                        if (player->isEnemy(newPlayer) == 1) {
                            this->player->sendAICommand(
                                (int)this->player->id, 6, playerIndex, 2, 0);
                            if (player->computerPlayer() == 1) {
                                player->sendAICommand(
                                    (int)this->player->id, 6,
                                    (int)this->player->id, 2, 0);
                            }
                        } else if (player->isAlly(newPlayer) == 1) {
                            this->player->sendAICommand(
                                (int)this->player->id, 6, playerIndex, 0, 0);
                        }
                    }
                }
            }
        }
    }

    if (this->player->world->game_state == 0 &&
        this->player->world->currentUpdateComputerPlayer == this->player->id) {
        this->tacticalAI.update(0);
        this->lastTacticalUpdateTime = this->player->world->world_time;
    }

    return 1;
}

// PDB lines 789-816; VA 004E5DB0.
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

// PDB lines 821-832; VA 004E5F30.
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

// PDB lines 837-846; VA 004E5FA0.
int TribeMainDecisionAIModule::addObject(RGE_Static_Object* object)
{
    if (object == 0) {
        return 0;
    }
    tacticalAI.addObject(object);
    informationAI.addObject(object);
    return MainDecisionAIModule::addObject(object);
}

// PDB lines 851-859; VA 004E5FE0.
int TribeMainDecisionAIModule::removeObject(int object_id)
{
    this->tacticalAI.removeObject(object_id);
    this->buildAI.removeBuiltItem(object_id);
    this->informationAI.removeObject(object_id);
    return MainDecisionAIModule::removeObject(object_id);
}

// PDB lines 864-880; VA 004E6020.
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

// PDB lines 885-891; VA 004E6090.
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

// PDB lines 896-899; VA 004E60D0.
void TribeMainDecisionAIModule::detask(int param)
{
    this->tacticalAI.detask(param);
}

// PDB lines 904-924; VA 004E60F0.
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

// PDB lines 929-943; VA 004E6160.
// BINARY NOTE: The source keeps the natural bounded ManagedArray copy loop.
void TribeMainDecisionAIModule::updateBuildAIWithObjects()
{
    int* newList;
    int j;
    RGE_Static_Object* object;
    int i;

    i = 0;
    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int limit = i + 1;
                newList = new int[limit];
                if (newList != 0) {
                    j = 0;
                    if (this->objects.maximumSizeValue > 0) {
                        while (j < this->objects.maximumSizeValue && j < limit) {
                            newList[j] = this->objects.value[j];
                            ++j;
                        }
                    }
                    delete[] this->objects.value;
                    this->objects.value = newList;
                    this->objects.maximumSizeValue = limit;
                }
            }

            object = this->object(this->objects.value[i]);
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

            ++i;
        } while (i < this->objects.numberValue);
    }
}

// PDB lines 949-1015; VA 004E6250.
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

// PDB lines 1020-1043; VA 004E6490.
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

// PDB lines 1048-1059; VA 004E6580.
// BINARY NOTE: Naming the random result before the arithmetic preserves the
// standalone MATCH in the reduced function context.
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

// PDB lines 1065-1170; VA 004E6600.
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

// PDB lines 1175-1181; VA 004E6870.
int TribeMainDecisionAIModule::currentScore(int index)
{
    if (index >= 1 && index <= this->player->world->player_num)
        return this->player->world->players[index]
            ->victory_conditions->get_victory_points();
    return -1;
}
