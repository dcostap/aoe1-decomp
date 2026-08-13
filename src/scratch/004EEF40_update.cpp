// VA: 004EEF40 TribeTacticalAIModule::update
// PDB source: taitacmd.cpp:2070-2264
// Attempt log:
// - The prior scratch candidate used raw offset helpers and wrong diplomacy
//   member names. It was 677 bytes short and had 18/22 calls.
// - Rebuilt the source around the binary-proven TribeTacticalAIModule member
//   layout, ManagedArray records, strategic-number indices, and typed world /
//   diplomacy ownership. This is the clean typed baseline for the function.
// - The target's first pair clamp compares sn[0x10] > sn[0x1A] directly;
//   replaced the temporary-based spelling with that source-level predicate.
// - Corrected the farms-tasked record to the information-module ManagedArray
//   at +0xF0, placing numberValue at md+0xDE0.
// - Corrected enableAttack to the target's __thiscall member ABI and made the
//   tick/1000 guard unsigned, restoring the target magic-multiply sequence.
// - Validation: 1224 rebuilt bytes versus 1421, frame 0x8, all 22 calls in
//   order, and 76.64% shape. Structural CFG/size remains unresolved.
//   Stop before register or codegen tuning. Next lead is direct md ownership
//   and reload topology around the reset/attack guard block.

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

struct ManagedArrayInt {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class DiplomacyAIModule {
public:
    char bytes[0x150];

    int mostHated(int, int, int, int);
    int mostLiked(int, int);
    int isEnemy(int);
    int isChangeable(int);
    int stance(int, int);
    int isAlly(int);
    int isNeutral(int);
    void setRelation(int, int);
};

class RGE_Game_World {
public:
    char gap_00[4];
    int tick;
    char gap_08[0x34];
    short player_num;
    char gap_3E[0x0C];
    short player_id;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class InformationAIModule {
public:
    virtual ~InformationAIModule();
    char gap_04[0xEC];
};

class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArrayInt farmsTaskedThisUpdate;
    char gap_100[0x10090 - 0x100];
};

class TribeMainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    char gap_F4[0x10];
    char buildAI[0x5C0];
    char constructionAI[0x318];
    DiplomacyAIModule diplomacyAI;
    char emotionalAI[0x1C0];
    TribeInformationAIModule informationAI;
};

struct UnitData {
    int data[6];
};

class TacticalAIGroupStorage {
public:
    char bytes[0x330];
};

class TribeTacticalAIModule : public AIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArrayInt civilians;
    ManagedArrayInt civilianExplorers;
    ManagedArrayInt soldiers;
    ManagedArrayInt ungroupedSoldiers;
    ManagedArrayInt boats;
    ManagedArrayInt warBoats;
    ManagedArrayInt fishingBoats;
    ManagedArrayInt tradeBoats;
    ManagedArrayInt transportBoats;
    ManagedArrayInt artifacts;
    int sn[226];
    UnitData gatherers[50];
    int numberGatherersValue;
    int desiredNumberGatherersValue;
    TacticalAIGroupStorage groups;
    int groupIDValue;
    int numberGroupsValue;
    unsigned long lastGroupAttackTime;
    unsigned long lastGroupRebalanceTime;
    unsigned long lastAttackResponseTime;
    unsigned long lastBoatAttackResponseTime;
    unsigned long lastScalingUpdateValue;
    int numberBuildUpdatesSkipped;
    int randomizedAttackSeparationTime;
    ManagedArrayInt playersToAttack;
    ManagedArrayInt playersToDefend;
    ManagedArrayInt workingArea;
    ManagedArrayInt unitsTaskedThisUpdate;

    void enableAttack(int);
    int doSomething();
    int update(int);
};

int TribeTacticalAIModule::update(int)
{
    TribeMainDecisionAIModule* md = this->md;

    if ((unsigned int)(md->player->world->tick -
                       this->lastScalingUpdateValue) >
        (unsigned int)(this->sn[0x63] * 60000)) {
        int value = this->sn[0x1A] + this->sn[0x5E];
        this->sn[0x1A] = value;
        if (value < 0) {
            this->sn[0x1A] = 0;
        }

        value = this->sn[0x10] + this->sn[0x5D];
        this->sn[0x10] = value;
        if (value < 0) {
            this->sn[0x10] = 0;
        }

        if (this->sn[0x10] > this->sn[0x1A]) {
            this->sn[0x10] = this->sn[0x1A];
        }
        value = this->sn[0x1A];
        if (value < this->sn[0x10]) {
            this->sn[0x1A] = this->sn[0x10];
        }

        value = this->sn[0x1E] << 1;
        this->sn[0x1E] = value;
        if (value < 0) {
            this->sn[0x1E] = 0;
        }
        if (100 < this->sn[0x1E]) {
            this->sn[0x1E] = 100;
        }

        value = this->sn[0x1F] << 1;
        this->sn[0x1F] = value;
        if (value < 0) {
            this->sn[0x1F] = 0;
        }
        if (100 < this->sn[0x1F]) {
            this->sn[0x1F] = 100;
        }

        value = this->sn[0x5B] << 1;
        this->sn[0x5B] = value;
        if (value < 0) {
            this->sn[0x5B] = 0;
        }
        if (100 < this->sn[0x5B]) {
            this->sn[0x5B] = 100;
        }

        this->lastScalingUpdateValue = md->player->world->tick;
    }

    this->unitsTaskedThisUpdate.numberValue = 0;
    md->informationAI.farmsTaskedThisUpdate.numberValue = 0;

    if ((unsigned int)this->sn[0x68] <=
        (unsigned int)md->player->world->tick / 1000U) {
        this->enableAttack(2);
    }

    int mostHatedPlayer = md->diplomacyAI.mostHated(
        this->sn[0x7C], this->sn[0x80], this->sn[0xBC], this->sn[0xC3]);
    int mostLikedPlayer = md->diplomacyAI.mostLiked(
        this->sn[0x7C], this->sn[0x80]);

    this->playersToAttack.numberValue = 0;
    if (this->playersToAttack.numberValue >
        this->playersToAttack.maximumSizeValue - 1) {
        int newSize = this->playersToAttack.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            for (int i = 0; i < this->playersToAttack.maximumSizeValue &&
                         i < newSize; i++) {
                newArray[i] = this->playersToAttack.value[i];
            }
            delete[] this->playersToAttack.value;
            this->playersToAttack.value = newArray;
            this->playersToAttack.maximumSizeValue = newSize;
        }
    }
    this->playersToAttack.value[this->playersToAttack.numberValue] =
        mostHatedPlayer;
    this->playersToAttack.numberValue++;

    this->playersToDefend.numberValue = 0;
    short playerID = md->player->world->player_id;
    if (this->playersToDefend.numberValue >
        this->playersToDefend.maximumSizeValue - 1) {
        int newSize = this->playersToDefend.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            for (int i = 0; i < this->playersToDefend.maximumSizeValue &&
                         i < newSize; i++) {
                newArray[i] = this->playersToDefend.value[i];
            }
            delete[] this->playersToDefend.value;
            this->playersToDefend.value = newArray;
            this->playersToDefend.maximumSizeValue = newSize;
        }
    }
    this->playersToDefend.value[this->playersToDefend.numberValue] = playerID;
    this->playersToDefend.numberValue++;

    if (mostHatedPlayer != mostLikedPlayer) {
        int count = this->playersToDefend.numberValue;
        int i = 0;
        if (count > 0) {
            do {
                if (i >= this->playersToDefend.maximumSizeValue) {
                    break;
                }
                if (this->playersToDefend.value[i] == mostLikedPlayer) {
                    goto diplomacy;
                }
                i++;
            } while (i < count);
        }
        if (count > this->playersToDefend.maximumSizeValue - 1) {
            int newSize = count + 1;
            int* newArray = new int[newSize];
            if (newArray != 0) {
                for (i = 0; i < this->playersToDefend.maximumSizeValue &&
                            i < newSize; i++) {
                    newArray[i] = this->playersToDefend.value[i];
                }
                delete[] this->playersToDefend.value;
                this->playersToDefend.value = newArray;
                this->playersToDefend.maximumSizeValue = newSize;
            }
        }
        this->playersToDefend.value[this->playersToDefend.numberValue] =
            mostLikedPlayer;
        this->playersToDefend.numberValue++;
    }

diplomacy:
    {
        int player = 1;
        if (1 < md->player->world->player_num) {
            do {
                if (player != md->player->world->player_id) {
                    if (player == mostHatedPlayer) {
                        if (md->diplomacyAI.isEnemy(player) == 0 &&
                            md->diplomacyAI.isChangeable(player) != 0 &&
                            md->diplomacyAI.stance(player, 0) > 0x4A) {
                            md->diplomacyAI.setRelation(player, 3);
                        }
                    } else if (player == mostLikedPlayer) {
                        if (md->diplomacyAI.isAlly(player) == 0 &&
                            md->diplomacyAI.isChangeable(player) != 0 &&
                            md->diplomacyAI.stance(player, 2) > 0x4A) {
                            md->diplomacyAI.setRelation(player, 0);
                        }
                    } else {
                        int stance = md->diplomacyAI.stance(player, 2);
                        if (this->sn[0x1D] < stance &&
                            md->diplomacyAI.isChangeable(player) != 0) {
                            if (md->diplomacyAI.isAlly(player) == 0) {
                                md->diplomacyAI.setRelation(player, 0);
                            }
                        } else if (md->diplomacyAI.isNeutral(player) == 0 &&
                                   md->diplomacyAI.isChangeable(player) != 0) {
                            md->diplomacyAI.setRelation(player, 1);
                        }
                    }
                }
                md = this->md;
                player++;
            } while (player < md->player->world->player_num);
        }
    }

    this->doSomething();
    this->unitsTaskedThisUpdate.numberValue = 0;
    return 1;
}
