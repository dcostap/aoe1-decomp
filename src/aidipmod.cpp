#include "../include/aiconmod.h"

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
};

class RGE_Victory_Conditions {
public:
    int get_victory_points();
};

class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;          // +0xF0
    int dislikeTable[10];              // +0xF4
    int likeTable[10];                 // +0x11C
    unsigned char changeableTable[10]; // +0x144

    virtual ~DiplomacyAIModule();
    virtual int save(int file);
    virtual int update(int value);

    DiplomacyAIModule(void* param, int value);
    DiplomacyAIModule(int value, int file);
    void setMainDecisionAI(MainDecisionAIModule* value);
    int stance(int player_id, int type) const;
    void changeStance(int player, int type, int value);
    void setStance(int player, int type, int value);
    int isDisliked(int player) const;
    int isAmbivalent(int player) const;
    int isLiked(int player) const;
    int isChangeable(int player) const;
    void setChangeable(int index, unsigned char value);
    int mostHated(int param1, int param2, int param3, int param4) const;
    int mostLiked(int param1, int param2) const;
    int isEnemy(int player) const;
    int isNeutral(int player) const;
    int isAlly(int player) const;
    int isAlliedWithMe(int player) const;
    void setRelation(int player_id, int stance);
};

DiplomacyAIModule::DiplomacyAIModule(void* param, int value)
    : AIModule("Diplomacy AI", 0x3EB, value, param)
{
    this->md = 0;
    for (int i = 0; i <= 9; i++) {
        this->dislikeTable[i] = 49;
        this->likeTable[i] = 49;
        this->changeableTable[i] = 1;
    }
}

extern int __cdecl rge_read(int handle, void* buf, int size);

DiplomacyAIModule::DiplomacyAIModule(int value, int file)
    : AIModule("Diplomacy AI", 0x3EB, value, 0), md(0)
{
    unsigned char* cp = this->changeableTable;
    int* lp = this->likeTable;
    int count = 10;
    do {
        rge_read(file, lp - 10, 4);
        rge_read(file, lp, 4);
        rge_read(file, cp, 1);
        lp++;
        cp++;
        count--;
    } while (count != 0);
}

DiplomacyAIModule::~DiplomacyAIModule()
{
}

void DiplomacyAIModule::setMainDecisionAI(MainDecisionAIModule* value)
{
    this->md = value;
}

int DiplomacyAIModule::update(int)
{
    int i = 1;
    char* player = *(char**)((char*)this->md + 0xF0);
    char* world = *(char**)(player + 0x3C);
    if (*(short*)(world + 0x3C) > i) {
        do {
            if (i != *(short*)(player + 0x4A)) {
                if (isAlly(i)) {
                    if (!isAlliedWithMe(i))
                        changeStance(i, 0, 1);
                }
                if (!isAlly(i)) {
                    if (isAlliedWithMe(i))
                        changeStance(i, 2, 1);
                }
            }
            player = *(char**)((char*)this->md + 0xF0);
            ++i;
            world = *(char**)(player + 0x3C);
        } while (i < *(short*)(world + 0x3C));
    }
    return 1;
}

extern "C" int __cdecl rge_write(int handle, void* buffer, int count);

int DiplomacyAIModule::save(int param_1) {
    unsigned char* changeableTable = this->changeableTable;
    int* likeTable = this->likeTable;
    int count = 10;

    do {
        rge_write(param_1, likeTable - 10, 4);
        rge_write(param_1, likeTable, 4);
        rge_write(param_1, changeableTable, 1);
        ++likeTable;
        ++changeableTable;
    } while (--count != 0);

    return 1;
}

int DiplomacyAIModule::stance(int player_id, int type) const
{
    // BINARY NOTE: this access form preserves the original VC5 register basin.
    if ((0 < player_id) && (player_id < *(short*)(*(char**)(*(char**)((char*)this->md + 0xF0) + 0x3C) + 0x3C))) {
        switch (type) {
        case 0:
            return this->dislikeTable[player_id];
        case 1: {
            int dislike_diff = 0x31 - this->dislikeTable[player_id];
            if (dislike_diff < 0) dislike_diff = -dislike_diff;
            int like_diff = 0x31 - this->likeTable[player_id];
            if (like_diff < 0) like_diff = -like_diff;
            int result = 100 - dislike_diff - like_diff;
            if (result < 0) result = 0;
            return result;
        }
        case 2:
            return this->likeTable[player_id];
        }
    }
    return -1;
}

void DiplomacyAIModule::changeStance(int player, int type, int value)
{
    if (player > 0 && player < this->md->player->world->player_num) {
        switch (type) {
        case 0:
            this->dislikeTable[player] += value;
            if (this->changeableTable[player] != 0) {
                if (this->dislikeTable[player] < 0) {
                    this->dislikeTable[player] = 0;
                    return;
                }
                if (this->dislikeTable[player] > 100) {
                    this->dislikeTable[player] = 100;
                    return;
                }
            } else {
                if (this->dislikeTable[player] < 50) {
                    this->dislikeTable[player] = 50;
                    return;
                }
                if (this->dislikeTable[player] > 100) {
                    this->dislikeTable[player] = 100;
                }
            }
            break;

        case 2:
            this->likeTable[player] += value;
            if (this->changeableTable[player] != 0) {
                if (this->likeTable[player] < 0) {
                    this->likeTable[player] = 0;
                    return;
                }
                if (this->likeTable[player] > 100) {
                    this->likeTable[player] = 100;
                    return;
                }
            } else {
                if (this->likeTable[player] < 0) {
                    this->likeTable[player] = 0;
                    return;
                }
                if (this->likeTable[player] > 48) {
                    this->likeTable[player] = 48;
                    return;
                }
            }
            break;
        }
    }
}

void DiplomacyAIModule::setStance(int player, int type, int value)
{
    if (player > 0 && player < this->md->player->world->player_num) {
        switch (type) {
        case 0:
            this->dislikeTable[player] = value;
            if (this->changeableTable[player] != 0) {
                if (value < 0) {
                    this->dislikeTable[player] = 0;
                    return;
                }
                if (value > 100) {
                    this->dislikeTable[player] = 100;
                    return;
                }
            } else {
                if (value < 50) {
                    this->dislikeTable[player] = 50;
                    return;
                }
                if (value > 100) {
                    this->dislikeTable[player] = 100;
                }
            }
            break;

        case 2:
            this->likeTable[player] = value;
            if (this->changeableTable[player] != 0) {
                if (value < 0) {
                    this->likeTable[player] = 0;
                    return;
                }
                if (value > 100) {
                    this->likeTable[player] = 100;
                    return;
                }
            } else {
                if (value < 0) {
                    this->likeTable[player] = 0;
                    return;
                }
                if (value > 48) {
                    this->likeTable[player] = 48;
                    return;
                }
            }
            break;
        }
    }
}

int DiplomacyAIModule::isDisliked(int player) const {
    if (((player > 0) && (player < this->md->player->world->player_num)) && (this->dislikeTable[player] > 0x31)) {
        return 1;
    }
    return 0;
}

int DiplomacyAIModule::isAmbivalent(int player) const {
    if (this->isDisliked(player) == 0) {
        if (this->isLiked(player) == 0) {
            return 1;
        }
    }
    return 0;
}

int DiplomacyAIModule::isLiked(int player) const {
    if (((player > 0) && (player < this->md->player->world->player_num)) && (this->likeTable[player] > 0x31)) {
        return 1;
    }
    return 0;
}

int DiplomacyAIModule::isChangeable(int player) const {
    if (((player > 0) && (player < this->md->player->world->player_num)) && (this->changeableTable[player] == 1)) {
        return 1;
    }
    return 0;
}

void DiplomacyAIModule::setChangeable(int index, unsigned char value) {
    if (index > 0 && index < this->md->player->world->player_num) {
        this->changeableTable[index] = value;
    }
}

int DiplomacyAIModule::mostHated(int param1, int param2, int param3, int param4) const
{
    int result = -1;
    int highest = -1;
    for (int i = 1; i < this->md->player->world->player_num; ++i) {
        if (i != this->md->player->id
            && this->md->player->world->players[i]->game_status != 2
            && (param1 <= 0 || param2 != i || !isAlly(i))) {
            int vp = this->md->player->world->players[i]->victory_conditions->get_victory_points();
            int value = this->dislikeTable[i];
            if (param4 > 1) {
                if (param3 == 1) {
                    value += vp / param4;
                } else {
                    value -= vp / param4;
                }
            }
            if (value > highest) {
                result = i;
                highest = value;
            }
        }
    }
    return result;
}

int DiplomacyAIModule::mostLiked(int param1, int param2) const
{
    int result;
    int delta;
    int i;
    int highest;
    int* like;
    int player;
    int world;
    int obj;
    int base;

    i = 1;
    highest = -1;
    result = -1;
    player = *(int*)(*(int*)((char*)this + 0xF0) + 0xF0);
    world = *(int*)(player + 0x3C);
    if (i < *(short*)(world + 0x3C)) {
        delta = 0xFFFFFEE4 - (int)this;
        like = (int*)((char*)this + 0x120);
        do {
            if (i != *(short*)(player + 0x4A)) {
                base = delta + *(int*)(world + 0x40);
                obj = *(int*)((int)like + base);
                if (*(unsigned char*)(obj + 0x80) != 2) {
                    if (param1 <= 0 || param2 != i || isEnemy(i) == 0) {
                        if (*like > highest) {
                            result = i;
                            highest = *like;
                        }
                    }
                }
            }
            world = *(int*)((char*)this + 0xF0);
            ++i;
            ++like;
            player = *(int*)(world + 0xF0);
            world = *(int*)(player + 0x3C);
        } while (i < *(short*)(world + 0x3C));
    }
    return result;
}

int DiplomacyAIModule::isEnemy(int player) const {
    if (player > 0) {
        RGE_Player* pRVar1 = this->md->player;
        if (player <= pRVar1->world->player_num) {
            if (player != pRVar1->id) {
                if (pRVar1->relations[player] == 3) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int DiplomacyAIModule::isNeutral(int player) const {
    RGE_Player* pVar1;

    if (((0 < player) && (pVar1 = this->md->player, player <= pVar1->world->player_num)) &&
        (player != pVar1->id) && (pVar1->relations[player] == 1)) {
        return 1;
    }
    return 0;
}

int DiplomacyAIModule::isAlly(int param_1) const {
    if (param_1 == this->md->player->id) {
        return 1;
    }

    if (param_1 > 0 && param_1 <= this->md->player->world->player_num
        && this->md->player->relations[param_1] == 0) {
        return 1;
    }

    return 0;
}

int DiplomacyAIModule::isAlliedWithMe(int player_num) const
{
    if (0 < player_num) {
        RGE_Player* me = this->md->player;
        RGE_Game_World* world = me->world;
        if (player_num < world->player_num) {
            RGE_Player* other = world->players[player_num];
            if (other != 0) {
                if (other->isAlly((int)me->id) != 0)
                    return 1;
            }
        }
    }

    return 0;
}

void DiplomacyAIModule::setRelation(int player_id, int stance) {
    if (player_id > 0) {
        if (player_id < this->md->player->world->player_num) {
            if (this->changeableTable[player_id] != 0) {
                this->md->player->setDiplomaticStance(player_id, stance);
            }
        }
    }
}
