// 004DC490 TribeInformationAIModule::objectToAttackWithPlay
// Source: taiinfmd.cpp lines 3277-3451
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 1: clean typed reconstruction from the binary call set and the matching
//    AIPlay/AIPlayStatus ABI donors; baseline was 688 bytes before the
//    corrected integer phase-loop ownership.
// 2: separated the RGE_Game_World pointer from the integer 10x5 phase index;
//    this removed the erroneous sizeof(RGE_Game_World) loop increment and
//    reached exact frame size with all 13 direct calls aligned.
// 3: explicit top-of-loop invalid breaks improved CFG alignment but shortened
//    the body; restored after the source-shaped for/continue probe below.
// 4-9: canonical base/class layouts, local declaration order, and a target
//    register hint were codegen duplicates; no call or relocation issues.
// 10: modeled the outer play scan as a bounded for-loop with continue paths
//    and `deviationValue > 0`; this reached exact 703-byte size and the
//    oracle's JA polarity, while leaving a register/lifetime permutation.
// 11: removed a redundant positive play-count wrapper; the current direct
//    for-loop is the cleaner source reconstruction (684 bytes, exact frame,
//    exact call set), with remaining drift localized to register coloring,
//    loop-test/tail layout, and the two early shared-return paths.
// Shard B5: changing the zero-count return to null, reordering declarations,
// and using positive count/target guards were codegen duplicates.
// Shard B5: the donor-shaped positive playbook do-scan worsened CFG coverage;
// restored the direct bounded scan. The first hunk remains this/play register
// coloring plus merged early epilogues; no ABI or call-set issue was found.
// luna-4DC490-r2 probe: returning the proven null target value on the
// target-null branch was emitted identically; original EAX preservation alone
// does not prevent VC5 from merging the null exits.
// luna-4DC490-r2 probe: changing the phase-invalid flag from int to bool
// removed some stack traffic and moved 3 positional bytes closer, but worsened
// CFG shape and exact-block coverage; restored the int source reconstruction.
// luna-4DC490-r3 probes: byte-sized invalid state plus binary-supported top-entry
// stops for both nested scans recovered exact size, 45.45% block coverage, and
// diff 639; kept as the best clean reconstruction. Per-iteration play scope,
// top-level score locals, and score-term order were emitted-code duplicates.
// A named death-value temporary added 19 bytes and was rolled back. Remaining
// drift is the early shared epilogues and callee-save rotation (this/play/flag).

extern int debug_rand(char* file, int line);

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    unsigned char gap_0E[2];
    int attackAttempts;
    unsigned char kills;
    unsigned char gap_15[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

struct AIPlayGrouping {
    int id;
    unsigned char groupValue;
    unsigned char typeValue;
    unsigned char gap_06[2];
};

struct AIPlayPoint {
    int xValue;
    int yValue;
    int zValue;
};

struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class AIPlayStatus {
public:
    AIPlayGrouping groupings[50];
    int playNumberValue;
    int targetValue;
    AIPlayPoint originalPointValue;
    int originalHitPointsValue[5];
    unsigned char currentPhaseValue;
    unsigned char gap_1B9[3];
    int savedAttackerValue;
    int lastPhaseChangeTimeValue;
    unsigned char deviationValue;

    AIPlayStatus();
    void copyUnits(int* units, int& count);
};

class AIPlayPhaseCommand {
public:
    unsigned char groupValue;
    unsigned char typeValue;
    unsigned char gap_02[2];
    int value1Value;
    int value2Value;
};

class AIPlayPhase {
public:
    AIPlayPhaseCommand* command(int index);
};

class AIPlay {
public:
    unsigned char gap_00[0x43];
    unsigned char typeValue;
    unsigned char gap_44[0x0D];
    unsigned char deathPercentageValue;

    int humanPlay() const;
    AIPlayPhase* phase(int phaseNumber);
    int fillGroups(AIPlayStatus* status, int* unitIds, int unitCount,
                   class RGE_Game_World* world);
};

class AIPlayBook {
public:
    void* plays;
    int numberPlaysValue;

    AIPlay* play(int playNumber);
};

class RGE_Game_World {
public:
    unsigned char gap_00[0xA0];
    AIPlayBook* playbook;
};

class RGE_Player {
public:
    unsigned char gap_00[0x3C];
    RGE_Game_World* world;
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int number);
};

class AIModule {
public:
    virtual ~AIModule();
    unsigned char gap_04[0xEC];
};

class InformationAIModule : public AIModule {
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArray_int objects;
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    unsigned char gap_104[0x1146C - 0x104];
    TribeTacticalAIModule tacticalAI;
    unsigned char gap_11470[0x1256C - 0x11470];
    RGE_Player* aiPlayer;
};

class TribeInformationAIModule : public InformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    ManagedArray_int farmsTaskedThisUpdate;
    TribeMainDecisionAIModule* md;
    int mapXSizeValue;
    int mapYSizeValue;
    int lastUpdateRowValue;
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    ManagedArray_int importantObjects;
    ManagedArray_int importantUnits;
    ManagedArray_int importantMiscs;
    ManagedArray_int itemsToDefend;
    unsigned char pathMap[0x28];
    ManagedArray_int playerObjects;
    ManagedArray_int playerBuildings;
    unsigned char gap_1A0[0x564 - 0x1A0];
    int playHistory[16000];

    ObjectMemory* objectToAttackByGroup2(int group, int* unitIds, int count);
    int inRangeOfUnits(int group, int x, int y, int range);
    int calculatePlayVariation(int playNumber);

    ObjectMemory* objectToAttackWithPlay(
        int group, int* unitIds, int count, int* playNumber,
        int* outputUnits, int* outputCount, int* outputUnit);
};

ObjectMemory* TribeInformationAIModule::objectToAttackWithPlay(
    int group, int* unitIds, int count, int* playNumber,
    int* outputUnits, int* outputCount, int* outputUnit)
{
    int targetNumber;
    ObjectMemory* target;
    int worldNumber;
    RGE_Game_World* world;
    AIPlayBook* playbook;
    int variation;
    int randomValue;
    int strategicValue;
    int score;

    if (count == 0) {
        return (ObjectMemory*)count;
    }

    target = this->objectToAttackByGroup2(group, unitIds, count);
    if (target == 0) {
        return 0;
    }

    targetNumber = 0;
            world = this->md->player->world;
    playbook = world->playbook;
    *playNumber = -1;

    for (; targetNumber < playbook->numberPlaysValue; ++targetNumber) {
            AIPlay* play = playbook->play(targetNumber);
            if (play == 0) {
                continue;
            }
            if (play->humanPlay() == 1) {
                continue;
            }

            AIPlayStatus playStatus;
            playStatus.playNumberValue = targetNumber;
            play->fillGroups(&playStatus, unitIds, count, world);
            if (playStatus.deviationValue > 0) {
                continue;
            }

            bool invalid = false;
            worldNumber = 0;
            do {
                if (invalid != 0) {
                    break;
                }
                int phase = 0;
                do {
                    if (invalid != 0) {
                        break;
                    }
                    AIPlayPhaseCommand* command =
                        play->phase(worldNumber)->command(phase);
                    if (command->typeValue == 1) {
                        int x = (int)target->x + command->value1Value;
                        int y = (int)target->y + command->value2Value;
                        if (x < 0 || y < 0 ||
                            x >= this->mapXSizeValue ||
                            y >= this->mapYSizeValue) {
                            invalid = 1;
                        }
                        if (this->inRangeOfUnits(group, x, y, 0) == 1) {
                            invalid = 1;
                        }
                    }
                    ++phase;
                } while (phase < 5);
                ++worldNumber;
            } while (worldNumber < 10);

            if (invalid == 0) {
                variation = this->calculatePlayVariation(targetNumber);
                randomValue =
                    debug_rand((char*)0x5878dc, 0xd49) % 0x32;
                strategicValue = 0;

                switch (play->typeValue) {
                case 1:
                    strategicValue =
                        this->md->tacticalAI.strategicNumber(0xbd);
                    break;
                case 2:
                    strategicValue =
                        this->md->tacticalAI.strategicNumber(0xc6);
                    break;
                case 3:
                    strategicValue =
                        this->md->tacticalAI.strategicNumber(0xc7);
                    break;
                }

                score =
                    (100 - (int)play->deathPercentageValue + variation) * 2 +
                    strategicValue + randomValue;
                if (*playNumber == -1 || score > 0) {
                    *playNumber = targetNumber;
                    playStatus.copyUnits(outputUnits, *outputCount);
                    randomValue =
                        debug_rand((char*)0x5878dc, 0xd6a);
                    *outputUnit = outputUnits[randomValue % *outputCount];
                }
            }
    }

    if (*playNumber != -1) {
        ++this->playHistory[*playNumber];
        return target;
    }
    return 0;
}
