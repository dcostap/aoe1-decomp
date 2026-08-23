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
// - Restored the duplicate-aware ManagedArray::add donor surface for all
//   player-list insertions. This recovered the original scan and growth CFG.
// - Removed the cached md receiver. Direct this->md reloads recover 1421-byte
//   size, 0x8 frame, 22 ordered calls, and 98.19% instruction shape.
// - Corrected player_id ownership to RGE_Player +0x4A, with world +0x3C and
//   player_num +0x3C. The source now has 969 differing bytes and 107 edit
//   bytes. Remaining drift is localized to the farms reset reload and benign
//   register/block scheduling. No exact match; leave the clean typed source.
// - Update r2 probes: player/world/tick locals, a function-wide md receiver,
//   a post-reset player receiver, timestamp temporary, unsigned tick type,
//   and an information-subobject pointer were codegen duplicates or worse.
//   A defend-array reference also worsened structure. Restored the clean
//   typed source; no evidence-backed lead remains for this claim.
// - Claim probes 1-22 tested short md/player/world/tick aliases, declaration
//   scope, references, real MainDecision and world class surfaces, virtual
//   update ownership, the canonical world_time spelling, diplomacy layout,
//   and an inline world-time accessor. Aliases and declaration surfaces were
//   duplicate codegen. A world local and a function-wide md local were worse.
// - The Ghidra listing confirms a temporary md receiver in the first timing
//   block, but the typed scoped alias is codegen-neutral under VC5. The first
//   clean mismatch remains the lastScalingUpdate register permutation at
//   +0x121, followed by the missing six-byte md reload before the farms reset.
// - The clean baseline remains 1421 bytes, 0x8 frame, 22/22 ordered calls,
//   98.19% shape, 969 positional diff bytes, and 107 edit bytes. No exact
//   source was found. Restore this baseline before pause.
// Accepted-drift review: the rebuild keeps an already-loaded md pointer for
// the farms reset; the executable reloads md. No call occurs between capture
// and use. Later, the rebuild reads md before clearing playersToDefend, while
// the executable clears first; both dereference md after the clear. No call
// crosses this scheduling change. All 22 calls and ManagedArray effects match.
// - Exact finish in the registered taitacmd.cpp context kept shared resize
//   out of line to protect 004F13F0. A local inline growth body restores the
//   target's three operator_new/operator_delete pairs without a helper call.
//   The zeroNumber calls preserve the md reread and player publication order.
// - Walkback of the local growth body restores three direct resize calls and
//   a 1266-byte drift. Fresh reduced validation matches all 1421 bytes, 22
//   ordered calls, the PDB-qualified owner, and every original basic block.

#ifndef TAITACMD_SHARED_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

void* operator new(unsigned int size);
void operator delete(void* ptr);

struct ManagedArrayInt {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    void zeroNumber() {
        numberValue = 0;
    }

    int add(int valueToAdd) {
        int i;
        int* newValue;
        int newSize;

        for (i = 0; i < numberValue; i++) {
            if (i >= maximumSizeValue) break;
            if (value[i] == valueToAdd) return 0;
        }
        if (numberValue > maximumSizeValue - 1) {
            newSize = numberValue + 1;
            newValue = (int*)operator new(newSize * sizeof(int));
            if (newValue != 0) {
                for (i = 0; i < maximumSizeValue; i++) {
                    if (i >= newSize) break;
                    newValue[i] = value[i];
                }
                operator delete(value);
                value = newValue;
                maximumSizeValue = newSize;
            }
        }
        value[numberValue] = valueToAdd;
        numberValue = numberValue + 1;
        return 1;
    }
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
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short player_id;
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
#endif

// BINARY NOTE: These three target insertions inline growth and emit direct
// operator_new/operator_delete calls. The shared add method emits resize.
static inline int addTacticalPlayer(ManagedArray<int>& array, int valueToAdd)
{
    int i;
    int* newValue;
    int newSize;

    for (i = 0; i < array.numberValue; i++) {
        if (i >= array.maximumSizeValue) break;
        if (array.value[i] == valueToAdd) return 0;
    }
    if (array.numberValue > array.maximumSizeValue - 1) {
        newSize = array.numberValue + 1;
        newValue = (int*)operator_new(newSize * sizeof(int));
        if (newValue != 0) {
            for (i = 0; i < array.maximumSizeValue; i++) {
                if (i >= newSize) break;
                newValue[i] = array.value[i];
            }
            operator_delete(array.value);
            array.value = newValue;
            array.maximumSizeValue = newSize;
        }
    }
    array.value[array.numberValue] = valueToAdd;
    array.numberValue = array.numberValue + 1;
    return 1;
}

int TribeTacticalAIModule::update(int)
{
    if ((unsigned int)(this->md->player->world->tick -
                       this->lastScalingUpdateValue) >
        (unsigned int)(this->sn[0x63] * 60000)) {
        this->sn[0x1A] += this->sn[0x5E];
        if (this->sn[0x1A] < 0) {
            this->sn[0x1A] = 0;
        }

        this->sn[0x10] += this->sn[0x5D];
        if (this->sn[0x10] < 0) {
            this->sn[0x10] = 0;
        }

        int value;
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

        this->lastScalingUpdateValue = this->md->player->world->tick;
    }

    // BINARY NOTE: This period array method preserves the md reread below.
    this->unitsTaskedThisUpdate.zeroNumber();
    this->md->informationAI.farmsTaskedThisUpdate.numberValue = 0;

    if ((unsigned int)this->md->player->world->tick / 1000U >=
        (unsigned int)this->sn[0x68]) {
        this->enableAttack(2);
    }

    int mostHatedPlayer = this->md->diplomacyAI.mostHated(
        this->sn[0x7C], this->sn[0x80], this->sn[0xBC], this->sn[0xC3]);
    int mostLikedPlayer = this->md->diplomacyAI.mostLiked(
        this->sn[0x7C], this->sn[0x80]);

    this->playersToAttack.numberValue = 0;
    addTacticalPlayer(this->playersToAttack, mostHatedPlayer);

    this->playersToDefend.zeroNumber();
    addTacticalPlayer(this->playersToDefend, this->md->player->player_id);

    if (mostHatedPlayer != mostLikedPlayer) {
        addTacticalPlayer(this->playersToDefend, mostLikedPlayer);
    }

diplomacy:
    {
        int player = 1;
        if (1 < this->md->player->world->player_num) {
            do {
                if (player != this->md->player->player_id) {
                    if (player == mostHatedPlayer) {
                        if (this->md->diplomacyAI.isEnemy(player) == 0 &&
                            this->md->diplomacyAI.isChangeable(player) != 0 &&
                            this->md->diplomacyAI.stance(player, 0) > 0x4A) {
                            this->md->diplomacyAI.setRelation(player, 3);
                        }
                    } else if (player == mostLikedPlayer) {
                        if (this->md->diplomacyAI.isAlly(player) == 0 &&
                            this->md->diplomacyAI.isChangeable(player) != 0 &&
                            this->md->diplomacyAI.stance(player, 2) > 0x4A) {
                            this->md->diplomacyAI.setRelation(player, 0);
                        }
                    } else {
                        int stance = this->md->diplomacyAI.stance(player, 2);
                        if (stance > this->sn[0x1D] &&
                            this->md->diplomacyAI.isChangeable(player) != 0) {
                            if (this->md->diplomacyAI.isAlly(player) == 0) {
                                this->md->diplomacyAI.setRelation(player, 0);
                            }
                        } else if (this->md->diplomacyAI.isNeutral(player) == 0 &&
                                   this->md->diplomacyAI.isChangeable(player) != 0) {
                            this->md->diplomacyAI.setRelation(player, 1);
                        }
                    }
                }
                player++;
            } while (player < this->md->player->world->player_num);
        }
    }

    this->doSomething();
    this->unitsTaskedThisUpdate.numberValue = 0;
    return 1;
}
