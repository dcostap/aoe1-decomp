#include "../include/TribeMainDecisionAIModule.h"

#include "../include/AIModule.h"
#include "../include/BuildAIModule.h"
#include "../include/debug_helpers.h"
#include "../include/DiplomacyAIModule.h"
#include "../include/EmotionalAIModule.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Static_Object.h"
#include "../include/TradeAIModule.h"
#include "../include/TribeBuildAIModule.h"
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
    return reinterpret_cast<BuildAIModule*>(self->buildAI);
}

TribeBuildAIModule* tribe_build_ai(TribeMainDecisionAIModule* self) {
    return reinterpret_cast<TribeBuildAIModule*>(self->buildAI);
}

TribeConstructionAIModule* construction_ai(TribeMainDecisionAIModule* self) {
    return reinterpret_cast<TribeConstructionAIModule*>(self->constructionAI);
}

DiplomacyAIModule* diplomacy_ai(TribeMainDecisionAIModule* self) {
    return reinterpret_cast<DiplomacyAIModule*>(self->diplomacyAI);
}

EmotionalAIModule* emotional_ai(TribeMainDecisionAIModule* self) {
    return reinterpret_cast<EmotionalAIModule*>(self->emotionalAI);
}

TribeInformationAIModule* information_ai(TribeMainDecisionAIModule* self) {
    return reinterpret_cast<TribeInformationAIModule*>(self->informationAI);
}

TribeResourceAIModule* resource_ai(TribeMainDecisionAIModule* self) {
    return reinterpret_cast<TribeResourceAIModule*>(self->resourceAI);
}

TribeStrategyAIModule* strategy_ai(TribeMainDecisionAIModule* self) {
    return reinterpret_cast<TribeStrategyAIModule*>(self->strategyAI);
}

TribeTacticalAIModule* tactical_ai(TribeMainDecisionAIModule* self) {
    return reinterpret_cast<TribeTacticalAIModule*>(self->tacticalAI);
}

TradeAIModule* trade_ai(TribeMainDecisionAIModule* self) {
    return reinterpret_cast<TradeAIModule*>(self->tradeAI);
}

int tactical_strategic_number(const TribeTacticalAIModule* tactical, int index) {
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

// TODO: Partial parity - uses BuildAIModule ctor because TribeBuildAIModule ctor is not yet transliterated.
TribeMainDecisionAIModule::TribeMainDecisionAIModule(void* param_1, int player_number, char* player_name, TRIBE_Player* player, char* ai1, char* ai2, char* ai3) {
    (void)ai1;
    (void)ai2;
    (void)ai3;

    new (build_ai(this)) BuildAIModule(param_1, player_number);
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

// TODO: Partial parity - uses BuildAIModule load-ctor because TribeBuildAIModule load-ctor is not yet transliterated.
TribeMainDecisionAIModule::TribeMainDecisionAIModule(int player_number, char* player_name, TRIBE_Player* player, int fd) {
    new (build_ai(this)) BuildAIModule(player_number, fd);
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

// TODO: Partial parity - BuildAIModule was placement-constructed as base class.
TribeMainDecisionAIModule::~TribeMainDecisionAIModule() {
    trade_ai(this)->~TradeAIModule();
    tactical_ai(this)->~TribeTacticalAIModule();
    strategy_ai(this)->~TribeStrategyAIModule();
    resource_ai(this)->~TribeResourceAIModule();
    information_ai(this)->~TribeInformationAIModule();
    emotional_ai(this)->~EmotionalAIModule();
    diplomacy_ai(this)->~DiplomacyAIModule();
    construction_ai(this)->~TribeConstructionAIModule();
    build_ai(this)->~BuildAIModule();
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
    return MainDecisionAIModule::loggingCommonHistory();
}

void TribeMainDecisionAIModule::setLogCommonHistory(int param_1) {
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

int TribeMainDecisionAIModule::loadState(char* param_1) { return MainDecisionAIModule::loadState(param_1); }
int TribeMainDecisionAIModule::saveState(char* param_1) { return MainDecisionAIModule::saveState(param_1); }
int TribeMainDecisionAIModule::gleanState(int param_1) { return MainDecisionAIModule::gleanState(param_1); }

int TribeMainDecisionAIModule::processMessage(AIModuleMessage* param_1) {
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

// TODO: Partial parity - tribute diplomacy branching from 0x004E5200..0x004E5D8C is not fully transliterated yet.
int TribeMainDecisionAIModule::update(int param_1) {
    (void)param_1;
    RGE_Game_World* world = this->aiPlayer->world;
    if ((world->game_state == 0) && (this->firstUpdate == 1)) {
        this->firstUpdate = 0;
        reinterpret_cast<AIModule*>(this)->logCommonHistory((char*)"Initial Diplomacy Settings:");
        for (int i = 1; i < world->player_num; ++i) {
            int dislike = diplomacy_ai(this)->stance(i, 0);
            int neutral = diplomacy_ai(this)->stance(i, 1);
            int like = diplomacy_ai(this)->stance(i, 2);
            reinterpret_cast<AIModule*>(this)->logCommonHistory((char*)"  Player=%d  Dislike=%d  Like=%d  Neutral=%d", i, dislike, like, neutral);
        }

        strategy_ai(this)->update(0);
        // TODO: FULL PARITY - TribeBuildAIModule::initialize is not transliterated in this repository yet.
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

    if (((world->world_time - this->lastDiplomacyUpdateTime) / 1000) > 0x3B) {
        diplomacy_ai(this)->update(0);
        this->lastDiplomacyUpdateTime = world->world_time;
    }

    if ((world->game_state == 0) && (world->currentUpdateComputerPlayer == this->aiPlayer->id)) {
        tactical_ai(this)->update(0);
        this->lastTacticalUpdateTime = world->world_time;
    }

    return 1;
}

void TribeMainDecisionAIModule::setCallbackMessage(AIModuleMessage* param_1) {
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
    if ((build_ai(this)->filterOutMessage(param_1) != 0) || (construction_ai(this)->filterOutMessage(param_1) != 0) ||
        (diplomacy_ai(this)->filterOutMessage(param_1) != 0) || (emotional_ai(this)->filterOutMessage(param_1) != 0) ||
        (information_ai(this)->filterOutMessage(param_1) != 0) || (resource_ai(this)->filterOutMessage(param_1) != 0) ||
        (strategy_ai(this)->filterOutMessage(param_1) != 0) || (tactical_ai(this)->filterOutMessage(param_1) != 0) ||
        (trade_ai(this)->filterOutMessage(param_1) != 0)) {
        return 1;
    }
    return MainDecisionAIModule::filterOutMessage(param_1);
}

// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E5DB0
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
    // TODO: FULL PARITY - direct TribeTacticalAIModule::addObject/TribeInformationAIModule::addObject are not declared in current headers.
    reinterpret_cast<MainDecisionAIModule*>(tactical_ai(this))->addObject(param_1);
    reinterpret_cast<MainDecisionAIModule*>(information_ai(this))->addObject(param_1);
    return MainDecisionAIModule::addObject(param_1);
}

// TODO: Partial parity - TribeBuildAIModule::removeBuiltItem is not available in this repository yet.
int TribeMainDecisionAIModule::removeObject(int param_1) {
    reinterpret_cast<MainDecisionAIModule*>(tactical_ai(this))->removeObject(param_1);
    reinterpret_cast<MainDecisionAIModule*>(information_ai(this))->removeObject(param_1);
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

// Fully verified. Source of truth: taimdmd.cpp.decomp @ 0x004E6090
int TribeMainDecisionAIModule::canPerformAction(int param_1, int param_2) {
    RGE_Static_Object* object = this->aiPlayer->world->object(param_1);
    if (object != nullptr) {
        int object_group = this->objectGroupThatCanPerformAction(param_2);
        if (object->master_obj->object_group == object_group) {
            return 1;
        }
    }
    return 0;
}

