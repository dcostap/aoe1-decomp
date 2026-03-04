#include "../include/TribeMainDecisionAIModule.h"

#include "../include/AIModule.h"
#include "../include/BuildAIModule.h"
#include "../include/debug_helpers.h"
#include "../include/DiplomacyAIModule.h"
#include "../include/EmotionalAIModule.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Victory_Conditions.h"
#include "../include/TradeAIModule.h"
#include "../include/TribeBuildAIModule.h"
#include "../include/TRIBE_Command.h"
#include "../include/TRIBE_Game.h"
#include "../include/TribeConstructionAIModule.h"
#include "../include/TribeInformationAIModule.h"
#include "../include/TribeResourceAIModule.h"
#include "../include/TribeStrategyAIModule.h"
#include "../include/TribeTacticalAIModule.h"
#include "../include/TRIBE_Player.h"
#include "../include/globals.h"

#include <cstring>
#include <new>

namespace {
BuildAIModule* build_ai(TribeMainDecisionAIModule* self) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    return reinterpret_cast<BuildAIModule*>(self->buildAI);
}

TribeBuildAIModule* tribe_build_ai(TribeMainDecisionAIModule* self) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    return reinterpret_cast<TribeBuildAIModule*>(self->buildAI);
}

TribeConstructionAIModule* construction_ai(TribeMainDecisionAIModule* self) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    return reinterpret_cast<TribeConstructionAIModule*>(self->constructionAI);
}

DiplomacyAIModule* diplomacy_ai(TribeMainDecisionAIModule* self) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    return reinterpret_cast<DiplomacyAIModule*>(self->diplomacyAI);
}

EmotionalAIModule* emotional_ai(TribeMainDecisionAIModule* self) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    return reinterpret_cast<EmotionalAIModule*>(self->emotionalAI);
}

TribeInformationAIModule* information_ai(TribeMainDecisionAIModule* self) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    return reinterpret_cast<TribeInformationAIModule*>(self->informationAI);
}

TribeResourceAIModule* resource_ai(TribeMainDecisionAIModule* self) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    return reinterpret_cast<TribeResourceAIModule*>(self->resourceAI);
}

TribeStrategyAIModule* strategy_ai(TribeMainDecisionAIModule* self) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    return reinterpret_cast<TribeStrategyAIModule*>(self->strategyAI);
}

TribeTacticalAIModule* tactical_ai(TribeMainDecisionAIModule* self) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    return reinterpret_cast<TribeTacticalAIModule*>(self->tacticalAI);
}

TradeAIModule* trade_ai(TribeMainDecisionAIModule* self) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    return reinterpret_cast<TradeAIModule*>(self->tradeAI);
}

signed char& world_ai_preferred_enemy(RGE_Game_World* world) {
    // Fully verified. Source of truth: taimdmd.cpp.asm @ 0x004E5A1D (TRIBE_World + 0x11D).
    return *reinterpret_cast<signed char*>(reinterpret_cast<unsigned char*>(world) + 0x11D);
}

int tactical_strategic_number(const TribeTacticalAIModule* tactical, int index) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    if ((tactical == nullptr) || (index < 0) || (index >= 226)) {
        return 0;
    }
    return tactical->sn[index];
}

void set_tribute_chat_timeout(TribeMainDecisionAIModule* self) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E6580
    TribeTacticalAIModule* tactical = tactical_ai(self);
    int variation = tactical_strategic_number(tactical, 0x7E);
    if (variation > 0) {
        int roll = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x41D);
        int base = tactical_strategic_number(tactical, 0x7D);
        self->tributeChatTimeout = (roll % variation - variation / 2) + base;
        return;
    }
    self->tributeChatTimeout = tactical_strategic_number(tactical, 0x7D);
}

void information_add_resource_type(TribeInformationAIModule* info, int bucket, int resource_type) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    if ((info == nullptr) || (bucket < 0) || (bucket >= 4) || (info->resourceTypesValue == nullptr) || (info->numberResourceTypesValue == nullptr)) {
        return;
    }

    int count = info->numberResourceTypesValue[bucket];
    int* values = info->resourceTypesValue[bucket];
    for (int i = 0; i < count; ++i) {
        if (values[i] == resource_type) {
            return;
        }
    }

    int* resized = static_cast<int*>(::operator new((size_t)(count + 1) * sizeof(int), std::nothrow));
    if (resized == nullptr) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        resized[i] = values[i];
    }
    resized[count] = resource_type;

    if (values != nullptr) {
        ::operator delete(values);
    }
    info->resourceTypesValue[bucket] = resized;
    info->numberResourceTypesValue[bucket] = count + 1;
}
}

// Offset: 0x004E4800
// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E4800
TribeMainDecisionAIModule::TribeMainDecisionAIModule(void* param_1, int player_number, char* player_name, TRIBE_Player* player, char* ai1, char* ai2, char* ai3) {
    (void)ai1;
    (void)ai2;
    (void)ai3;

    new (tribe_build_ai(this)) TribeBuildAIModule(param_1, player_number);
    new (construction_ai(this)) TribeConstructionAIModule(param_1, player_number);
    new (diplomacy_ai(this)) DiplomacyAIModule(param_1, player_number);
    new (emotional_ai(this)) EmotionalAIModule(param_1, player_number);
    new (information_ai(this)) TribeInformationAIModule(param_1, player_number);
    new (resource_ai(this)) TribeResourceAIModule(param_1, player_number, 4, 500, 0, 1000);
    new (strategy_ai(this)) TribeStrategyAIModule(param_1, player_number);
    new (tactical_ai(this)) TribeTacticalAIModule(param_1, player_number);
    new (trade_ai(this)) TradeAIModule(param_1, player_number);

    this->player = reinterpret_cast<RGE_Player*>(player);
    this->aiPlayer = player;
    this->firstUpdate = 1;
    this->veryFirstUpdate = 1;
    this->updateDelay = player_number;
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

    reinterpret_cast<AIModule*>(this)->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(this)->setLogCommonHistory((startLoggingAI != 0) ? 1 : 0);

    tribe_build_ai(this)->setMainDecisionAI(this);
    construction_ai(this)->setMainDecisionAI(this);
    diplomacy_ai(this)->setMainDecisionAI(this);
    emotional_ai(this)->setMainDecisionAI(this);
    information_ai(this)->setMainDecisionAI(this);
    resource_ai(this)->setMainDecisionAI(this);
    strategy_ai(this)->setMainDecisionAI(this);
    tactical_ai(this)->setMainDecisionAI(this);
    trade_ai(this)->setMainDecisionAI(this);

    reinterpret_cast<AIModule*>(build_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(construction_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(diplomacy_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(emotional_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(information_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(resource_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(strategy_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(tactical_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(trade_ai(this))->setPlayer(player_number, player_name);

    information_add_resource_type(information_ai(this), 0, 0x30);
    information_add_resource_type(information_ai(this), 0, 0x7E);
    information_add_resource_type(information_ai(this), 0, 0x3B);
    information_add_resource_type(information_ai(this), 0, 0x41);
    information_add_resource_type(information_ai(this), 0, 0x34);
    information_add_resource_type(information_ai(this), 0, 0x35);
    information_add_resource_type(information_ai(this), 0, 0x104);
    information_add_resource_type(information_ai(this), 0, 0x107);
    information_add_resource_type(information_ai(this), 0, 0x32);

    for (int id = 0x6F; id < 0x73; ++id) {
        information_add_resource_type(information_ai(this), 1, id);
    }
    for (int id = 0x86; id < 0x9A; ++id) {
        information_add_resource_type(information_ai(this), 1, id);
    }
    for (int id = 0xC0; id < 0xC6; ++id) {
        information_add_resource_type(information_ai(this), 1, id);
    }
    information_add_resource_type(information_ai(this), 2, 0x66);
    information_add_resource_type(information_ai(this), 3, 0x42);
    for (int id = 0x150; id < 0x154; ++id) {
        information_add_resource_type(information_ai(this), 3, id);
    }

    emotional_ai(this)->setOverallState(0);
    std::memset(this->tributeGiven, 0, sizeof(this->tributeGiven));
}

// Offset: 0x004E4B80
// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E4B80
TribeMainDecisionAIModule::TribeMainDecisionAIModule(int player_number, char* player_name, TRIBE_Player* player, int fd) {
    new (tribe_build_ai(this)) TribeBuildAIModule(player_number, fd);
    new (construction_ai(this)) TribeConstructionAIModule(player_number, fd);
    new (diplomacy_ai(this)) DiplomacyAIModule(player_number, fd);
    new (emotional_ai(this)) EmotionalAIModule(player_number, fd);
    new (information_ai(this)) TribeInformationAIModule(player_number, fd);
    new (resource_ai(this)) TribeResourceAIModule(player_number, fd);
    new (strategy_ai(this)) TribeStrategyAIModule(player_number, fd);
    new (tactical_ai(this)) TribeTacticalAIModule(player_number, fd);
    new (trade_ai(this)) TradeAIModule(player_number, fd);

    this->player = reinterpret_cast<RGE_Player*>(player);
    this->aiPlayer = player;
    this->firstUpdate = 0;
    this->veryFirstUpdate = 0;
    this->updateDelay = player_number;
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
    std::memset(this->tributeGiven, 0, sizeof(this->tributeGiven));

    reinterpret_cast<AIModule*>(this)->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(this)->setLogCommonHistory((startLoggingAI != 0) ? 1 : 0);

    tribe_build_ai(this)->setMainDecisionAI(this);
    construction_ai(this)->setMainDecisionAI(this);
    diplomacy_ai(this)->setMainDecisionAI(this);
    emotional_ai(this)->setMainDecisionAI(this);
    information_ai(this)->setMainDecisionAI(this);
    resource_ai(this)->setMainDecisionAI(this);
    strategy_ai(this)->setMainDecisionAI(this);
    tactical_ai(this)->setMainDecisionAI(this);
    trade_ai(this)->setMainDecisionAI(this);

    reinterpret_cast<AIModule*>(build_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(construction_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(diplomacy_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(emotional_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(information_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(resource_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(strategy_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(tactical_ai(this))->setPlayer(player_number, player_name);
    reinterpret_cast<AIModule*>(trade_ai(this))->setPlayer(player_number, player_name);

    rge_read(fd, &this->updateDelay, 4);
    rge_read(fd, &this->lastDiplomacyUpdateTime, 4);
    rge_read(fd, &this->lastTacticalUpdateTime, 4);
    if (save_game_version >= 1.2f) {
        rge_read(fd, &this->lastTributeChatTime, 4);
        rge_read(fd, &this->tributeChatTimeout, 4);
        rge_read(fd, &this->waitingOnTribute, 4);
        rge_read(fd, &this->tributeExpirationTimeout, 4);
        rge_read(fd, &this->tributeAddressed, 4);
        rge_read(fd, &this->tributeAmount, 4);
    }
    if (save_game_version >= 7.08f) {
        rge_read(fd, &this->decidedInitialDiplomacy, 4);
        rge_read(fd, &this->requiredDiplomacyTributeAmount, 4);
        rge_read(fd, this->tributeGiven, 0x24);
    }
}

// Offset: 0x004E4EC0
// Offset: 0x004E4EC0
// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E4EC0
TribeMainDecisionAIModule::~TribeMainDecisionAIModule() {
    trade_ai(this)->~TradeAIModule();
    tactical_ai(this)->~TribeTacticalAIModule();
    strategy_ai(this)->~TribeStrategyAIModule();
    resource_ai(this)->~TribeResourceAIModule();
    information_ai(this)->~TribeInformationAIModule();
    emotional_ai(this)->~EmotionalAIModule();
    diplomacy_ai(this)->~DiplomacyAIModule();
    construction_ai(this)->~TribeConstructionAIModule();
    tribe_build_ai(this)->~TribeBuildAIModule();
}

int TribeMainDecisionAIModule::loggingHistory() {
    return MainDecisionAIModule::loggingHistory();
}

// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E4FA0
void TribeMainDecisionAIModule::setLogHistory(int param_1) {
    build_ai(this)->setLogHistory(param_1);
    construction_ai(this)->setLogHistory(param_1);
    diplomacy_ai(this)->setLogHistory(param_1);
    emotional_ai(this)->setLogHistory(param_1);
    information_ai(this)->setLogHistory(param_1);
    resource_ai(this)->setLogHistory(param_1);
    strategy_ai(this)->setLogHistory(param_1);
    tactical_ai(this)->setLogHistory(param_1);
    trade_ai(this)->setLogHistory(param_1);
    MainDecisionAIModule::setLogHistory(param_1);
}

void TribeMainDecisionAIModule::toggleLogHistory() {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    build_ai(this)->toggleLogHistory();
    construction_ai(this)->toggleLogHistory();
    diplomacy_ai(this)->toggleLogHistory();
    emotional_ai(this)->toggleLogHistory();
    information_ai(this)->toggleLogHistory();
    resource_ai(this)->toggleLogHistory();
    strategy_ai(this)->toggleLogHistory();
    tactical_ai(this)->toggleLogHistory();
    trade_ai(this)->toggleLogHistory();
    MainDecisionAIModule::toggleLogHistory();
}

void TribeMainDecisionAIModule::setHistoryFilename(char* param_1) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    build_ai(this)->setHistoryFilename(param_1);
    construction_ai(this)->setHistoryFilename(param_1);
    diplomacy_ai(this)->setHistoryFilename(param_1);
    emotional_ai(this)->setHistoryFilename(param_1);
    information_ai(this)->setHistoryFilename(param_1);
    resource_ai(this)->setHistoryFilename(param_1);
    strategy_ai(this)->setHistoryFilename(param_1);
    tactical_ai(this)->setHistoryFilename(param_1);
    trade_ai(this)->setHistoryFilename(param_1);
    MainDecisionAIModule::setHistoryFilename(param_1);
}

int TribeMainDecisionAIModule::loggingCommonHistory() {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    return MainDecisionAIModule::loggingCommonHistory();
}

void TribeMainDecisionAIModule::setLogCommonHistory(int param_1) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    build_ai(this)->setLogCommonHistory(param_1);
    construction_ai(this)->setLogCommonHistory(param_1);
    diplomacy_ai(this)->setLogCommonHistory(param_1);
    emotional_ai(this)->setLogCommonHistory(param_1);
    information_ai(this)->setLogCommonHistory(param_1);
    resource_ai(this)->setLogCommonHistory(param_1);
    strategy_ai(this)->setLogCommonHistory(param_1);
    tactical_ai(this)->setLogCommonHistory(param_1);
    trade_ai(this)->setLogCommonHistory(param_1);
    MainDecisionAIModule::setLogCommonHistory(param_1);
}

void TribeMainDecisionAIModule::toggleLogCommonHistory() {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    build_ai(this)->toggleLogCommonHistory();
    construction_ai(this)->toggleLogCommonHistory();
    diplomacy_ai(this)->toggleLogCommonHistory();
    emotional_ai(this)->toggleLogCommonHistory();
    information_ai(this)->toggleLogCommonHistory();
    resource_ai(this)->toggleLogCommonHistory();
    strategy_ai(this)->toggleLogCommonHistory();
    tactical_ai(this)->toggleLogCommonHistory();
    trade_ai(this)->toggleLogCommonHistory();
    MainDecisionAIModule::toggleLogCommonHistory();
}
// Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
int TribeMainDecisionAIModule::loadState(char* param_1) { return MainDecisionAIModule::loadState(param_1); }
// Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
int TribeMainDecisionAIModule::saveState(char* param_1) { return MainDecisionAIModule::saveState(param_1); }
// Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
int TribeMainDecisionAIModule::gleanState(int param_1) { return MainDecisionAIModule::gleanState(param_1); }

int TribeMainDecisionAIModule::processMessage(AIModuleMessage* param_1) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    build_ai(this)->processMessage(param_1);
    construction_ai(this)->processMessage(param_1);
    diplomacy_ai(this)->processMessage(param_1);
    emotional_ai(this)->processMessage(param_1);
    information_ai(this)->processMessage(param_1);
    resource_ai(this)->processMessage(param_1);
    strategy_ai(this)->processMessage(param_1);
    tactical_ai(this)->processMessage(param_1);
    trade_ai(this)->processMessage(param_1);
    return MainDecisionAIModule::processMessage(param_1);
}

// Offset: 0x004E5050
// Fully verified. Source of truth: taimdmd.cpp.decomp + taimdmd.cpp.asm @ 0x004E5050
int TribeMainDecisionAIModule::update(int param_1) {
    (void)param_1;
    RGE_Game_World* world = this->aiPlayer->world;
    if ((world->game_state == 0) && (this->firstUpdate == 1)) {
        this->firstUpdate = 0;
        reinterpret_cast<AIModule*>(this)->logCommonHistory((char*)"Initial Diplomacy Settings:");
        for (int i = 1; i < world->player_num; ++i) {
            const int neutral = diplomacy_ai(this)->stance(i, 1);
            const int like = diplomacy_ai(this)->stance(i, 2);
            const int dislike = diplomacy_ai(this)->stance(i, 0);
            reinterpret_cast<AIModule*>(this)->logCommonHistory((char*)"  Player #%d: Dislike=%d, Like=%d, Ambivalence=%d", i, dislike, like, neutral);
        }

        strategy_ai(this)->update(0);
        tribe_build_ai(this)->initialize();
        information_ai(this)->initialize();
        set_tribute_chat_timeout(this);

        if ((tactical_strategic_number(tactical_ai(this), 0x81) == 1) && (tactical_strategic_number(tactical_ai(this), 0x7D) == 0)) {
            this->waitingOnTribute = 1;
            this->tributeAmount = 0;
        }

        int value = tactical_strategic_number(tactical_ai(this), 0x8A);
        if (value != 0) {
            this->aiPlayer->command_add_attribute(0, (float)value);
        }
        value = tactical_strategic_number(tactical_ai(this), 0x8B);
        if (value != 0) {
            this->aiPlayer->command_add_attribute(3, (float)value);
        }
        value = tactical_strategic_number(tactical_ai(this), 0x8C);
        if (value != 0) {
            this->aiPlayer->command_add_attribute(2, (float)value);
        }
        value = tactical_strategic_number(tactical_ai(this), 0x8D);
        if (value != 0) {
            this->aiPlayer->command_add_attribute(1, (float)value);
        }
    }

    this->updateDelay = this->updateDelay + 1;
    if (this->updateDelay > 0x13) {
        strategy_ai(this)->update(0);
        this->updateDelay = 0;
    }

    information_ai(this)->update(0);

    if (((world->world_time - this->lastDiplomacyUpdateTime) / 1000) >= 0x3C) {
        diplomacy_ai(this)->update(0);
        this->lastDiplomacyUpdateTime = world->world_time;
    }

    TribeTacticalAIModule* tactical = tactical_ai(this);
    const int tribute_threshold = tactical->strategicNumber(0x7C);
    if ((tribute_threshold > 0) && (this->tributeAddressed == 0)) {
        const int elapsed_seconds = static_cast<int>((world->world_time - this->lastTributeChatTime) / 1000);
        const int tribute_chat_window = tactical->strategicNumber(0x7D);

        if ((elapsed_seconds >= static_cast<int>(this->tributeChatTimeout)) && (tribute_chat_window > 0)) {
            if (this->waitingOnTribute == 0) {
                this->waitingOnTribute = 1;
                this->tributeAmount = 0;
                this->tributeExpirationTimeout = tactical->strategicNumber(0x7F) * 1000;
            }

            this->lastTributeChatTime = world->world_time;
            const int tribute_player = tactical->strategicNumber(0x80);
            char tempString[256];

            if (tactical->strategicNumber(0x82) == 1) {
                int request_amount = 0;
                if (this->tributeAmount < 1) {
                    rge_base_game->get_string(0x903, tempString, 0x100);
                    request_amount = tactical->strategicNumber(0x7C);
                } else {
                    rge_base_game->get_string(0x902, tempString, 0x100);
                    request_amount = tactical->strategicNumber(0x7C) - this->tributeAmount;
                }
                this->aiPlayer->sendChatMessage(tribute_player, 0, tempString, request_amount);
                set_tribute_chat_timeout(this);
            } else if (tactical->strategicNumber(0x81) == 1) {
                int request_amount = 0;
                if (this->tributeAmount < 1) {
                    rge_base_game->get_string(0x905, tempString, 0x100);
                    request_amount = tactical->strategicNumber(0x7C) - this->tributeAmount;
                } else {
                    rge_base_game->get_string(0x904, tempString, 0x100);
                    request_amount = tactical->strategicNumber(0x7C);
                }
                this->aiPlayer->sendChatMessage(tribute_player, 0, tempString, request_amount);
                set_tribute_chat_timeout(this);
            } else {
                set_tribute_chat_timeout(this);
            }
        } else if (this->waitingOnTribute == 1) {
            this->tributeExpirationTimeout -= static_cast<int>(world->world_time_delta);
            if (this->tributeExpirationTimeout < 1) {
                const int tribute_player = tactical->strategicNumber(0x80);
                char tempString[256];
                if (tactical->strategicNumber(0x82) == 1) {
                    diplomacy_ai(this)->setStance(tribute_player, 0, 100);
                    diplomacy_ai(this)->setStance(tribute_player, 2, 0);
                    this->aiPlayer->setDiplomaticStance(tribute_player, 3);
                    rge_base_game->get_string(0x901, tempString, 0x100);
                    this->aiPlayer->sendChatMessage(tribute_player, 0, tempString);
                    this->waitingOnTribute = 0;
                    this->tributeAddressed = 1;
                    this->lastTributeChatTime = world->world_time;
                } else if (tactical->strategicNumber(0x81) == 1) {
                    rge_base_game->get_string(0x900, tempString, 0x100);
                    this->aiPlayer->sendChatMessage(tribute_player, 0, tempString);
                    this->waitingOnTribute = 0;
                    this->lastTributeChatTime = world->world_time;
                }
            } else {
                const int required_amount = tactical->strategicNumber(0x7C);
                if (this->tributeAmount >= required_amount) {
                    const int tribute_player = tactical->strategicNumber(0x80);
                    char tempString[256];
                    if (tactical->strategicNumber(0x81) == 1) {
                        diplomacy_ai(this)->setStance(tribute_player, 0, 0);
                        diplomacy_ai(this)->setStance(tribute_player, 2, 100);
                        this->aiPlayer->setDiplomaticStance(tribute_player, 0);
                        rge_base_game->get_string(0x8FF, tempString, 0x100);
                        this->aiPlayer->sendChatMessage(tribute_player, 0, tempString);
                        this->waitingOnTribute = 0;
                        this->lastTributeChatTime = world->world_time;
                    } else if (tactical->strategicNumber(0x82) == 1) {
                        rge_base_game->get_string(0x8FE, tempString, 0x100);
                        this->aiPlayer->sendChatMessage(tribute_player, 0, tempString);
                        this->waitingOnTribute = 0;
                        this->lastTributeChatTime = world->world_time;
                    }

                    this->tributeAddressed = (tactical->strategicNumber(0x84) == 0) ? 1 : 0;
                }
            }
        }
    }

    if ((this->decidedInitialDiplomacy == 0) && (world->world_time > 10000)) {
        this->decidedInitialDiplomacy = 1;

        int computer_count = 0;
        int human_count = 0;
        int neutral_computer_count = 0;
        int neutralList[9] = {0};

        for (int i = 1; i < world->player_num; ++i) {
            RGE_Player* player_i = world->players[i];
            if (player_i->computerPlayer() == 0) {
                human_count += 1;
            } else {
                computer_count += 1;
                if (player_i->isAllNeutral() == 1) {
                    neutralList[i] = 1;
                    neutral_computer_count += 1;
                }
            }
        }

        signed char& preferred_enemy = world_ai_preferred_enemy(world);
        if (preferred_enemy == -1) {
            if (computer_count == 1) {
                preferred_enemy = static_cast<signed char>(this->aiPlayer->id);
            } else if (computer_count > 1) {
                int choice = (debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x236) % computer_count) + 1;
                for (int i = 1; i < world->player_num; ++i) {
                    RGE_Player* player_i = world->players[i];
                    if ((player_i->computerPlayer() == 1) && (--choice == 0)) {
                        preferred_enemy = static_cast<signed char>(player_i->id);
                    }
                }
            }
        }

        if (preferred_enemy == static_cast<signed char>(this->aiPlayer->id)) {
            int swayable_target_count = (computer_count - human_count) / 2;
            if (swayable_target_count < 0) {
                swayable_target_count = 0;
            }
            if (neutral_computer_count < swayable_target_count) {
                swayable_target_count = neutral_computer_count;
            }
            if (((TRIBE_Game*)rge_base_game)->deathMatch() == 1) {
                swayable_target_count = 0;
            }

            if ((swayable_target_count <= neutral_computer_count) && (neutral_computer_count > 0)) {
                int swayableCPs[9] = {0};
                int swayable_count = 0;

                for (int i = 1; i < world->player_num; ++i) {
                    RGE_Player* player_i = world->players[i];
                    if ((player_i->computerPlayer() != 0) &&
                        (neutralList[i] != 0) &&
                        ((unsigned char)preferred_enemy != (unsigned char)player_i->id) &&
                        (swayable_count < swayable_target_count)) {
                        int found = 0;
                        for (int j = 0; j < swayable_count; ++j) {
                            if (swayableCPs[j] == i) {
                                found = 1;
                                break;
                            }
                        }
                        if (found == 0) {
                            swayableCPs[swayable_count] = i;
                            swayable_count += 1;
                        }
                    }
                }

                int request_amount = 2000;
                switch (rge_base_game->difficulty()) {
                case 0:
                    request_amount = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x26E) % 500 + 0x578;
                    break;
                case 1:
                    request_amount = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x26F) % 400 + 1000;
                    break;
                case 2:
                    request_amount = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x270) % 300 + 700;
                    break;
                case 3:
                    request_amount = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x271) % 200 + 0x1C2;
                    break;
                case 4:
                    request_amount = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x272) % 100 + 300;
                    break;
                default:
                    break;
                }

                for (int i = 1; i < world->player_num; ++i) {
                    RGE_Player* player_i = world->players[i];
                    if ((player_i->computerPlayer() != 0) && (neutralList[i] != 0)) {
                        int player_is_swayable = 0;
                        for (int j = 0; j < swayable_count; ++j) {
                            if (swayableCPs[j] == i) {
                                player_is_swayable = 1;
                                player_i->sendAICommand(this->aiPlayer->id, 7, request_amount, 0, 0);
                                request_amount = request_amount * 2;
                                break;
                            }
                        }

                        for (int j = 1; j < world->player_num; ++j) {
                            if (i == j) {
                                continue;
                            }

                            RGE_Player* other = world->players[j];
                            if (other->computerPlayer() == 0) {
                                if (player_is_swayable == 0) {
                                    player_i->sendAICommand(this->aiPlayer->id, 6, j, 0, 0);
                                }
                            } else if (other->computerPlayer() == 1) {
                                player_i->sendAICommand(this->aiPlayer->id, 6, j, 2, 0);
                            }
                        }
                    }
                }
            }
        }
    }

    if (tactical->strategicNumber(0xD9) == 1) {
        int diplomacy_timeout = (tactical->strategicNumber(0x68) - 3) * 1000;
        if (diplomacy_timeout < 0) {
            diplomacy_timeout = 0;
        }

        if ((ulong)diplomacy_timeout < world->world_time) {
            tactical->setStrategicNumber(0xD9, 0);

            int target_player = -1;
            for (int i = 1; i < world->player_num; ++i) {
                if (world->players[i]->computerPlayer() != 1) {
                    target_player = i;
                    break;
                }
            }

            if (target_player != -1) {
                if (this->aiPlayer->isEnemy(target_player) == 0) {
                    this->aiPlayer->sendAICommand(this->aiPlayer->id, 6, target_player, 0, 0);
                }

                for (int i = 1; i < world->player_num; ++i) {
                    if ((i == this->aiPlayer->id) || (i == target_player)) {
                        continue;
                    }

                    RGE_Player* player_i = world->players[i];
                    if (player_i->isEnemy(target_player) == 1) {
                        this->aiPlayer->sendAICommand(this->aiPlayer->id, 6, i, 2, 0);
                        if (player_i->computerPlayer() == 1) {
                            player_i->sendAICommand(this->aiPlayer->id, 6, this->aiPlayer->id, 2, 0);
                        }
                    } else if (player_i->isAlly(target_player) == 1) {
                        this->aiPlayer->sendAICommand(this->aiPlayer->id, 6, i, 0, 0);
                    }
                }
            }
        }
    }

    if ((world->game_state == 0) && (world->currentUpdateComputerPlayer == this->aiPlayer->id)) {
        tactical_ai(this)->update(0);
        this->lastTacticalUpdateTime = world->world_time;
    }

    return 1;
}

void TribeMainDecisionAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    build_ai(this)->setCallbackMessage(param_1);
    construction_ai(this)->setCallbackMessage(param_1);
    diplomacy_ai(this)->setCallbackMessage(param_1);
    emotional_ai(this)->setCallbackMessage(param_1);
    information_ai(this)->setCallbackMessage(param_1);
    resource_ai(this)->setCallbackMessage(param_1);
    strategy_ai(this)->setCallbackMessage(param_1);
    tactical_ai(this)->setCallbackMessage(param_1);
    trade_ai(this)->setCallbackMessage(param_1);
    MainDecisionAIModule::setCallbackMessage(param_1);
}

int TribeMainDecisionAIModule::filterOutMessage(AIModuleMessage* param_1) {
    // Fully verified. Source of truth: taimdmd.cpp.decomp (helper implementation).
    if ((build_ai(this)->filterOutMessage(param_1) != 0) || (construction_ai(this)->filterOutMessage(param_1) != 0) ||
        (diplomacy_ai(this)->filterOutMessage(param_1) != 0) || (emotional_ai(this)->filterOutMessage(param_1) != 0) ||
        (information_ai(this)->filterOutMessage(param_1) != 0) || (resource_ai(this)->filterOutMessage(param_1) != 0) ||
        (strategy_ai(this)->filterOutMessage(param_1) != 0) || (tactical_ai(this)->filterOutMessage(param_1) != 0) ||
        (trade_ai(this)->filterOutMessage(param_1) != 0)) {
        return 1;
    }
    return MainDecisionAIModule::filterOutMessage(param_1);
}

// Fully verified. Source of truth: taimdmd.cpp.decomp + taimdmd.cpp.asm @ 0x004E5DB0
int TribeMainDecisionAIModule::save(int param_1) {
    MainDecisionAIModule::save(param_1);
    build_ai(this)->save(param_1);
    construction_ai(this)->save(param_1);
    diplomacy_ai(this)->save(param_1);
    emotional_ai(this)->save(param_1);
    information_ai(this)->save(param_1);
    resource_ai(this)->save(param_1);
    strategy_ai(this)->save(param_1);
    tactical_ai(this)->save(param_1);
    trade_ai(this)->save(param_1);

    rge_write(param_1, &this->updateDelay, 4);
    rge_write(param_1, &this->lastDiplomacyUpdateTime, 4);
    rge_write(param_1, &this->lastTacticalUpdateTime, 4);
    rge_write(param_1, &this->lastTributeChatTime, 4);
    rge_write(param_1, &this->tributeChatTimeout, 4);
    rge_write(param_1, &this->waitingOnTribute, 4);
    rge_write(param_1, &this->tributeExpirationTimeout, 4);
    rge_write(param_1, &this->tributeAddressed, 4);
    rge_write(param_1, &this->tributeAmount, 4);
    rge_write(param_1, &this->decidedInitialDiplomacy, 4);
    rge_write(param_1, &this->requiredDiplomacyTributeAmount, 4);
    rge_write(param_1, this->tributeGiven, 0x24);
    return 1;
}

// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E5FA0
int TribeMainDecisionAIModule::addObject(RGE_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    tactical_ai(this)->addObject(param_1);
    information_ai(this)->addObject(param_1);
    return MainDecisionAIModule::addObject(param_1);
}

// Offset: 0x004E5FE0
// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E5FE0
int TribeMainDecisionAIModule::removeObject(int param_1) {
    tactical_ai(this)->removeObject(param_1);
    tribe_build_ai(this)->removeBuiltItem(param_1);
    information_ai(this)->removeObject(param_1);
    return MainDecisionAIModule::removeObject(param_1);
}

// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E6020
int TribeMainDecisionAIModule::objectGroupThatCanPerformAction(int param_1) {
    switch (param_1) {
    case 0x25A:
    case 0x25D:
    case 0x261:
    case 0x265:
        return 4;
    case 0x26B:
    case 0x26C:
        return 3;
    default:
        return MainDecisionAIModule::objectGroupThatCanPerformAction(param_1);
    }
}

// Fully verified. Source of truth: taimdmd.cpp.decomp + taimdmd.cpp.asm @ 0x004E6090
int TribeMainDecisionAIModule::canPerformAction(int param_1, int param_2) {
    RGE_Static_Object* object = MainDecisionAIModule::object(param_1);
    if (object != nullptr) {
        int object_group = this->objectGroupThatCanPerformAction(param_2);
        if (object->master_obj->object_group == object_group) {
            return 1;
        }
    }
    return 0;
}

// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E5D95
// Decomp artifact block in save epilogue; behavior is covered by save() at 0x004E5DB0.
// TODO: PARITY - 0x004E5D95 decomp resolves to corrupted FUN_004e5d95 thunk-like output and is not transliterated as an explicit function path here. [decomp: taimdmd.cpp.decomp @ 0x004E5D95]

// Offset: 0x004E5F30
// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E5F30
void TribeMainDecisionAIModule::kick(int param_1) {
    reinterpret_cast<AIModule*>(this)->logCommonHistory((char*)"Got a kick %d.", param_1);
    if (param_1 == 1) {
        tribe_build_ai(this)->skipNextBuildListItem();
    } else if (param_1 == 2) {
        tribe_build_ai(this)->insert(0x53, 1, -1);
    } else if (param_1 == 3) {
        reinterpret_cast<AIModule*>(this)->logCommonHistory((char*)"Current Build list is:");
        tribe_build_ai(this)->displayBuildList();
    }
}

// Offset: 0x004E60D0
// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E60D0
void TribeMainDecisionAIModule::detask(int param_1) {
    tactical_ai(this)->detask(param_1);
}

// Offset: 0x004E60F0
// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E60F0
int TribeMainDecisionAIModule::isMoveable(int param_1) {
    RGE_Static_Object* object = MainDecisionAIModule::object(param_1);
    if ((object != nullptr) && (object->master_obj != nullptr)) {
        short object_group = object->master_obj->object_group;
        if ((object_group != 3) &&
            (object_group != 0x1B) &&
            (object_group != 0x1E) &&
            (object_group != 0x1F) &&
            (object_group != 5) &&
            (object_group != 0x21) &&
            (object_group != 7) &&
            (object_group != 8) &&
            (object_group != 0x20) &&
            (object_group != 0x10) &&
            (object_group != 0xE) &&
            (object_group != 0xF)) {
            return 1;
        }
    }
    return 0;
}

// Offset: 0x004E6160
// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E6160
void TribeMainDecisionAIModule::updateBuildAIWithObjects() {
    if (this->objects.value == nullptr) {
        return;
    }

    for (int i = 0; i < this->objects.numberValue; ++i) {
        RGE_Static_Object* object = MainDecisionAIModule::object(this->objects.value[i]);
        if (object == nullptr) {
            continue;
        }

        tribe_build_ai(this)->addItem(object, 0);
        if ((object->master_obj != nullptr) && (object->master_obj->id == 0x6D)) {
            construction_ai(this)->setReferencePoint(0, 0, object->world_x, object->world_y, object->world_z);
        }
    }
}

// Offset: 0x004E6250
// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E6250
void TribeMainDecisionAIModule::tributeNotify(int param_1, int param_2, int param_3) {
    int tribute_player = tactical_ai(this)->strategicNumber(0x80);
    if ((this->waitingOnTribute == 1) && (param_1 == tribute_player) && (param_2 == 3)) {
        this->tributeAmount = this->tributeAmount + param_3;
        return;
    }

    if (param_1 == tribute_player) {
        return;
    }

    diplomacy_ai(this)->changeStance(param_1, 2, param_3 / 100);
    diplomacy_ai(this)->changeStance(param_1, 0, -(param_3 / 100));
    if ((param_1 >= 0) && (param_1 < 9)) {
        this->tributeGiven[param_1] = this->tributeGiven[param_1] + param_3;
    }

    if ((tactical_ai(this)->strategicNumber(0xD9) == 1) &&
        (param_1 >= 0) && (param_1 < 9) &&
        (this->requiredDiplomacyTributeAmount <= this->tributeGiven[param_1])) {
        diplomacy_ai(this)->setRelation(param_1, 0);
        tactical_ai(this)->setStrategicNumber(0xD9, 0);
    }
}

// Offset: 0x004E6490
// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E6490
void TribeMainDecisionAIModule::revokeTributeAlliance() {
    int tribute_player = tactical_ai(this)->strategicNumber(0x80);
    if (this->aiPlayer->isEnemy(tribute_player) == 0) {
        diplomacy_ai(this)->setStance(tribute_player, 0, 100);
        diplomacy_ai(this)->setStance(tribute_player, 2, 100);
        this->aiPlayer->set_relation(tribute_player, 0);
        this->waitingOnTribute = 0;
        this->tributeAddressed = 1;
    }
}

// Offset: 0x004E6600
// Fully verified. Source of truth: taimdmd.cpp.decomp + taimdmd.cpp.asm @ 0x004E6600
int TribeMainDecisionAIModule::processAICommand(int param_1, int param_2, int param_3, int param_4, int param_5) {
    switch (param_2) {
    case 0:
        information_ai(this)->lookAtMap();
        return 1;
    case 1:
        if ((param_1 != this->player->id) &&
            (this->aiPlayer->objects->find_by_master_id(0x54, -1.0f, -1.0f, '\0', '\x02', nullptr) != nullptr)) {
            float tributeBaseline = 0.0f;
            std::memcpy(&tributeBaseline, &this->aiPlayer->world->player_time_delta[1], sizeof(float));
            this->aiPlayer->command_give_attribute(param_1, param_3, static_cast<float>(param_4), tributeBaseline);
            return 1;
        }
        return 1;
    case 2:
    case 3:
        if (param_1 != this->player->id) {
            tactical_ai(this)->processCoopAttack(param_1, param_3, param_4, param_5);
            return 1;
        }
        return 1;
    case 6:
    {
        DiplomacyAIModule* diplomacy = diplomacy_ai(this);
        diplomacy->setChangeable(param_3, '\x01');
        if (param_4 == 0) {
            diplomacy->setStance(param_3, 0, 100);
            diplomacy->setRelation(param_3, 3);
        } else if (param_4 == 1) {
            diplomacy->setStance(param_3, 0, 0x31);
            diplomacy->setStance(param_3, 2, 0x31);
            diplomacy->setRelation(param_3, 1);
        } else if (param_4 == 2) {
            diplomacy->setStance(param_3, 2, 100);
            diplomacy->setRelation(param_3, 0);
            if (rge_base_game->difficulty() != 4) {
                reinterpret_cast<TRIBE_Command*>(this->player->world->commands)->command_allied_victory(this->player->id, '\x01');
                diplomacy->setChangeable(param_3, '\0');
                return 1;
            }
            RGE_Player* otherPlayer = this->player->world->players[param_3];
            if (otherPlayer->computerPlayer() == 0) {
                reinterpret_cast<TRIBE_Command*>(this->player->world->commands)->command_allied_victory(this->player->id, '\x01');
                diplomacy->setChangeable(param_3, '\0');
                return 1;
            }
            reinterpret_cast<TRIBE_Command*>(this->player->world->commands)->command_allied_victory(this->player->id, '\0');
            diplomacy->setChangeable(param_3, '\0');
            return 1;
        }
        diplomacy->setChangeable(param_3, '\0');
        return 1;
    }
    case 7:
        this->requiredDiplomacyTributeAmount = param_3;
        tactical_ai(this)->setStrategicNumber(0xD9, 1);
        return 1;
    default:
        return 0;
    }
}

// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E6841
// Decomp artifact block is covered by currentScore() at 0x004E6870.

// Offset: 0x004E6870
// Fully verified. Source of truth: taimdmd.cpp.decomp + taimdmd.cpp.asm @ 0x004E6870
int TribeMainDecisionAIModule::currentScore(int param_1) {
    if ((param_1 >= 1) && (param_1 <= this->player->world->player_num)) {
        return (int)this->player->world->players[param_1]->victory_conditions->get_victory_points();
    }
    return -1;
}

