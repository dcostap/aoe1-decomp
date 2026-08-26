// VA: 00515E00 TRIBE_Player::intelligentBuildListAndRulesSelection
// First-pass source from packet/decompiler, with binary-observed local layout notes.
// Attempt log:
// - 2026-05-30: built a full behavioral skeleton through the random personality/rule setup tail.
//   check_function compiles and keeps the same 6631-byte length, but remains a broad mismatch
//   (5628/6631 positional bytes; first drift is register allocation/prologue: rebuilt keeps
//   `this` in EBX and zero in EBP vs original EBP/ESI). Fixed the reduction loop to the
//   binary-observed 7 fixed passes; current mismatch is 5616/6631 positional bytes.
//   Needs source-shape/register-pressure work.
// - 2026-08-13: baseline check retained the named TRIBE_Player civ_id/playerAI ownership,
//   125-entry weight array, and tplayer.cpp source family (7560 strict-diff bytes, 8320 body).
// - 2026-08-13: typed the same-TU AI-module layout and changed history logging to the
//   AIModule member surface. The source is more canonical, but codegen moved farther
//   (7657 strict-diff bytes, 8336 body); no shared files changed.
// - 2026-08-13: restored the common final difficulty rule call and retained the original
//   no-call path for difficulty values outside 0..3. The emitted call-count gap remains.
// - 2026-08-13: diagnostic raw tplayer pointer/module declarations improved the strict
//   diff to 7560 and size to 8320, but kept the same missing setRule call and broad CFG
//   drift. A player alias emitted identical code. Both were rolled back to this typed
//   source because the raw form did not prove canonical ownership or exact behavior.
// - 2026-08-14: modeled the binary local packet as 125 weights followed by the
//   adjacent most-built output slot. This restores the observed +0x18/+0x20c layout
//   and raises shape similarity to 55.0%; the remaining register allocation is broad.
// - 2026-08-14: evaluated each goal rule before its random adjustment. Ordered calls
//   now match all 131 original calls; this is retained as natural source order.
// - 2026-08-14: changed the three count gates from `< 1` to `<= 0`, matching the
//   original zero compare and improving the early CFG. Current best remains nonexact.
// - 2026-08-17: completed 20 distinct probes. The original reduction pass sets
//   are now restored from the local Ghidra listing. This cuts the rebuild to the
//   original 6631-byte boundary and raises shape similarity to 89.36%.
//   Separate pointer loops reproduce the original sanitize and total passes.
//   Extern counter globals and reviewed rge_base_game ownership improve the
//   codegen basin.
// - 2026-08-19: completed another 20 distinct probes. Natural power-of-two
//   remainder expressions, branch-specific merged calls, the original selected-
//   counter tails, and explicit final Boolean branches raise shape similarity
//   from 89.36% to 96.60% and exact-block coverage from 59.66% to 80.30%.
//   Ordered call parity rises from 127/131 to 130/131. The remaining missing
//   site is the final victory-branch setRule(0x37), whose cold block starts past
//   the 6631-byte boundary. The retained source has the exact frame, size,
//   prologue, instruction count within two, and all 27 debug_rand call sites.
// - 2026-08-19: a third 20-probe pass restored PDB-ordered selected-switch
//   handlers, positive-first early map branches, and a distinct selection index.
//   Strict positional difference falls from 5714 to 3074 bytes. Shape rises to
//   98.13% and exact-block coverage rises to 83.81%. The instruction count is
//   one above the original. The final cold-tail setRule remains outside the
//   boundary because the selected switch uses an 8-byte-larger compressed
//   dispatch and map adjustment adds another 7 bytes. A direct index-only scan
//   proves all 131 calls can fit, but it loses the binary-observed zero fallback
//   and changes broad register allocation, so it is not retained.
// - 2026-08-19: a fourth 20-probe pass expanded each selected-build-list case
//   body, as supported by the original 425-line switch span. This restores the
//   direct jump table. Reusing randomValue for adjusted map size restores the
//   original common load and in-place adjustment. An explicit rule 0xBC branch
//   restores the missing CFG blocks. The result has exact size, frame, saved
//   registers, instruction count, all 131 calls, 124 conditionals, and 71 jumps.
//   Shape is 98.68%, exact-block coverage is 88.04%, and strict difference is
//   1518 bytes. Remaining differences are mainly register and shared-tail maps.
// - 2026-08-22: restored canonical period class names and the TRIBE_Game
//   deathMatch surface. This changes no emitted bytes, but it restores the
//   proven direct-call symbol identities.
// - 2026-08-22: cached the early DAT_00886c48 and DAT_00886c44 values in that
//   declaration order. This recovers the original +0x1D9 load order and lowers
//   strict difference from 1518 to 1508 bytes without changing the frame.
// - 2026-08-22: reversed the independent case-2 and case-3 updates where the
//   original loads the lower build-list slots first. The current result is 1481
//   strict-difference bytes, 98.96% shape, and 88.80% exact-block coverage.
// - 2026-08-22: tested the natural int buildLists[126] owner and a common
//   post-switch setRule(0x4A) tail. Both moved the function farther and were
//   restored. Keep the packet layout and branch-local call form.
// - 2026-08-23: restored one natural setRule expression in each random-goal
//   arm. This preserves every rule reread and debug_rand call. VC5 then emits
//   the original shared argument and call tail, reducing the strict difference
//   from 1481 bytes to 55 bytes.
// - 2026-08-23: a complete permutation check of the six case-3 updates found
//   one source order that emits the original complete block. The retained
//   BL1, BL2, BL0x14, BL0x15, BL0x12, BL0x13 order reduces the difference to
//   10 bytes without changing any call, predicate, frame, or boundary.
// - 2026-08-23: the final 10 bytes are the two paired case-7/10 and case-9
//   load/store register maps. Reversing either pair restores its local fault
//   order, but changes tail ownership, removes one late setRule call, and moves
//   thousands of later bytes. Named values, expanded assignments, a shared
//   source label, register qualification, and the current tplayer.cpp wrapper
//   did not recover both the local order and the exact later basin.
// - 2026-08-24: focused natural-form labs tested direct, expanded, comma,
//   pointer, reference, and asymmetric cached-low pair updates. Every low-first
//   form changed the early failure branch or the later basin. The direct
//   high-first form remains the smallest clean source with exact size, frame,
//   boundary, owner, and all 131 ordered calls. The ten raw spans are seven
//   unmasked paired-map bytes and three late register-color bytes.
// - 2026-08-24: reordered the cheat locals to food, gold, wood, and stone.
//   This restores the three shipped zero-register bytes.
// - 2026-08-24: reordered cases 4, 7/10, and 9 as one low-first group.
//   This restores seven bytes and keeps the shared suffix and all 131 calls.
//   Reverting any group member breaks exact tail ownership. Reverting the
//   cheat declaration order leaves only its three register bytes different.
//   The reduced natural source now matches all 6631 bytes at the PDB boundary.
// Notes:
// - The packet's decompiler folds the saved game difficulty into buildLists[0]; the
//   real stack has `gameDifficulty` at +0x14 and `buildLists[125]` at +0x18.
//   BL(n) below maps decompiler buildLists[n] references to the real zero-based
//   build-list weight array by subtracting one.
// - Uses fixed-address globals/strings for the known tplayer.cpp counters and log text.

#include "../../include/tplayer_context.h"

#if 0

typedef unsigned char uchar;

extern int computerPlayerSetup;
extern int DAT_00886c1c;
extern int DAT_00886c20;
extern int DAT_00886c24;
extern int DAT_00886c28;
extern int DAT_00886c2c;
extern int DAT_00886c30;
extern int DAT_00886c34;
extern int DAT_00886c38;
extern int DAT_00886c3c;
extern int DAT_00886c40;
extern int DAT_00886c44;
extern int DAT_00886c48;
extern int allowAIToCheat;

struct BuildListPacket_00515E00 {
    int weights[125];
    int mostBuiltUnit;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual void get_string(int id, char* dst, int len);
    int difficulty();
    uchar deathMatch();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    uchar deathMatch();
};

extern TRIBE_Game* rge_base_game;

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
    void logCommonHistory(char* fmt, ...);
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0x1008C];
    void loadUnitHistory();
    void unitsThatAreMostBuilt(int* difficultyLevel, int* mostBuiltUnit);
};

class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    char gap_04[0x5BC];
};

class TribeConstructionAIModule {
public:
    virtual ~TribeConstructionAIModule();
    char gap_04[0x314];
};

class DiplomacyAIModule {
public:
    virtual ~DiplomacyAIModule();
    char gap_04[0x14C];
};

class EmotionalAIModule {
public:
    virtual ~EmotionalAIModule();
    char gap_04[0x1BC];
};

class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    char gap_04[0xF4];
};

class TribeStrategyAIModule {
public:
    virtual ~TribeStrategyAIModule();
    char gap_04[0x5F4];
    int rule(int id);
    void setRule(int id, int value);
};

class TribeMainDecisionAIModule : public AIModule {
public:
    char gap_base[0x14];
    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;
    DiplomacyAIModule diplomacyAI;
    EmotionalAIModule emotionalAI;
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    TribeStrategyAIModule strategyAI;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x101];
    uchar civ_id; // +0x105
    char gap_106[0x11A];
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_220[0x18];
    TribeMainDecisionAIModule* playerAI; // +0x238

    void setupEgyptian(int* weights, int mapType, int victoryType, int mapSize);
    void setupGreek(int* weights, int mapType, int victoryType, int mapSize);
    void setupBabylonian(int* weights, int mapType, int victoryType, int mapSize);
    void setupAssyrian(int* weights, int mapType, int victoryType, int mapSize);
    void setupMinoan(int* weights, int mapType, int victoryType, int mapSize);
    void setupHittite(int* weights, int mapType, int victoryType, int mapSize);
    void setupPhoenician(int* weights, int mapType, int victoryType, int mapSize);
    void setupSumerian(int* weights, int mapType, int victoryType, int mapSize);
    void setupPersian(int* weights, int mapType, int victoryType, int mapSize);
    void setupShang(int* weights, int mapType, int victoryType, int mapSize);
    void setupYamato(int* weights, int mapType, int victoryType, int mapSize);
    void setupChoson(int* weights, int mapType, int victoryType, int mapSize);
    void setupRoman(int* weights, int mapType, int victoryType, int mapSize);
    void setupCarthaginian(int* weights, int mapType, int victoryType, int mapSize);
    void setupPalmyran(int* weights, int mapType, int victoryType, int mapSize);
    void setupMacedonian(int* weights, int mapType, int victoryType, int mapSize);

    void intelligentBuildListAndRulesSelection(char* buildListName, char* ruleSetName,
                                               int mapType, int victoryType, int mapSize);
};

#endif

#define SET_RULE(rule_id, value) this->playerAI->strategyAI.setRule((rule_id), (value))
#define GET_RULE(rule_id) this->playerAI->strategyAI.rule((rule_id))
#define BL(n) buildLists[(n) - 1]
#define buildLists packet.weights
#define DIV3_POS(x) do { if (0 < (x)) { (x) = (x) / 3; } } while (0)
#define SELECT_SPECIAL(v) case v: SET_RULE(0x3B, 4); SET_RULE(0x3C, 10); ++DAT_00886c34; ++DAT_00886c48; goto selectedCountersDone
#define SELECT_COMPUTER(v) case v: ++computerPlayerSetup; break
#define SELECT_NONE(v) case v: break
#define SELECT_C48(v) case v: ++DAT_00886c48; goto selectedCountersDone
#define SELECT_C44_C2C(v) case v: ++DAT_00886c44; ++DAT_00886c2c; goto selectedCountersDone
#define SELECT_C44_C28(v) case v: ++DAT_00886c44; ++DAT_00886c28; goto selectedCountersDone
#define SELECT_C1C(v) case v: ++DAT_00886c1c; break
#define SELECT_C2C(v) case v: ++DAT_00886c2c; break
#define SELECT_C20(v) case v: ++DAT_00886c20; break
#define SELECT_C24(v) case v: ++DAT_00886c24; break
#define SELECT_C30(v) case v: ++DAT_00886c30; break
#define SELECT_C28(v) case v: ++DAT_00886c28; break

void TRIBE_Player::intelligentBuildListAndRulesSelection(char* buildListName, char* ruleSetName,
                                                         int mapType, int victoryType, int mapSize)
{
    int difficultyLevel;
    int gameDifficulty;
    BuildListPacket_00515E00 packet;
    char tempString[256];

    if (this->playerAI == 0) {
        return;
    }

    gameDifficulty = rge_base_game->difficulty();
    memset(packet.weights, 0, sizeof(packet.weights));

    switch (this->civ_id) {
    case 1:  this->setupEgyptian(buildLists, mapType, victoryType, mapSize); break;
    case 2:  this->setupGreek(buildLists, mapType, victoryType, mapSize); break;
    case 3:  this->setupBabylonian(buildLists, mapType, victoryType, mapSize); break;
    case 4:  this->setupAssyrian(buildLists, mapType, victoryType, mapSize); break;
    case 5:  this->setupMinoan(buildLists, mapType, victoryType, mapSize); break;
    case 6:  this->setupHittite(buildLists, mapType, victoryType, mapSize); break;
    case 7:  this->setupPhoenician(buildLists, mapType, victoryType, mapSize); break;
    case 8:  this->setupSumerian(buildLists, mapType, victoryType, mapSize); break;
    case 9:  this->setupPersian(buildLists, mapType, victoryType, mapSize); break;
    case 10: this->setupShang(buildLists, mapType, victoryType, mapSize); break;
    case 11: this->setupYamato(buildLists, mapType, victoryType, mapSize); break;
    case 12: this->setupChoson(buildLists, mapType, victoryType, mapSize); break;
    case 13: this->setupRoman(buildLists, mapType, victoryType, mapSize); break;
    case 14: this->setupCarthaginian(buildLists, mapType, victoryType, mapSize); break;
    case 15: this->setupPalmyran(buildLists, mapType, victoryType, mapSize); break;
    case 16: this->setupMacedonian(buildLists, mapType, victoryType, mapSize); break;
    }

    if (rge_base_game->deathMatch() == 0) {
        int civ = this->civ_id - 1;
        if (civ == 3 || civ == 0 || civ == 1 || civ == 4 || civ == 8 ||
            civ == 6 || civ == 7 || civ == 10) {
            int c48 = DAT_00886c48;
            int c44 = DAT_00886c44;
            if (mapType == 0) {
                if (c44 > 0) {
                    if (c48 == 0) {
                        BL(0x0E) += 300;
                        BL(0x0F) += 300;
                    } else {
                        BL(0x0E) += 100;
                        BL(0x0F) += 100;
                    }
                } else {
                    BL(0x0E) = 0;
                    BL(0x0F) = 0;
                }
            }
            if (mapType == 1) {
                if (c44 > 0) {
                    if (c48 == 0) {
                        BL(0x0E) += 250;
                        BL(0x0F) += 250;
                    } else {
                        BL(0x0E) += 75;
                        BL(0x0F) += 75;
                    }
                } else {
                    BL(0x0E) = 0;
                    BL(0x0F) = 0;
                }
            }
            if (mapType == 2 || mapType == 6 || mapType == 8) {
                if (c44 > 0) {
                    if (c48 == 0) {
                        BL(0x0E) += 200;
                        BL(0x0F) += 200;
                    } else {
                        BL(0x0E) += 50;
                        BL(0x0F) += 50;
                    }
                } else {
                    BL(0x0E) = 0;
                    BL(0x0F) = 0;
                }
            }
        }
    }

    SET_RULE(0xC9, 1);

    if (rge_base_game->deathMatch() == 0) {
        difficultyLevel = -1;
        packet.mostBuiltUnit = -1;
        this->playerAI->informationAI.loadUnitHistory();
        this->playerAI->informationAI.unitsThatAreMostBuilt(&difficultyLevel, &packet.mostBuiltUnit);
        switch (difficultyLevel) {
        case 0:
            BL(7) += 25;
            BL(8) += 25;
            break;
        case 1:
            BL(7) += 30;
            BL(8) += 30;
            break;
        case 2:
            BL(0x12) += 20;
            BL(0x13) += 20;
            BL(4) += 40;
            BL(5) += 40;
            break;
        case 3:
            // BINARY NOTE: this independent update order fixes VC5's complete block schedule.
            BL(1) += 40;
            BL(2) += 20;
            BL(0x14) += 20;
            BL(0x15) += 20;
            BL(0x12) -= 60;
            BL(0x13) -= 60;
            break;
        case 4:
            BL(7) += 15;
            BL(8) += 15;
            // BINARY NOTE: related pair cases need this low-first order for the shipped shared tail.
            BL(0x14) += 20;
            BL(0x15) += 20;
            break;
        case 5:
            BL(7) += 15;
            BL(8) += 15;
            BL(1) += 10;
            BL(2) += 10;
            break;
        case 6:
            BL(7) += 15;
            BL(8) += 15;
            break;
        case 7:
        case 10:
            BL(0x14) -= 60;
            BL(0x15) -= 60;
            break;
        case 8:
            BL(0x14) += 40;
            BL(0x15) += 40;
            if (DAT_00886c44 > 0) {
                BL(0x0E) += 50;
                BL(0x0F) += 50;
            }
            break;
        case 9:
            BL(0x14) += 100;
            BL(0x15) += 100;
            break;
        }
    }

    difficultyLevel = 0;
    do {
        switch (difficultyLevel) {
        case 0:
            DIV3_POS(BL(0x14));
            DIV3_POS(BL(0x15));
            DIV3_POS(BL(0x16));
            break;
        case 1:
            DIV3_POS(BL(7));
            DIV3_POS(BL(8));
            DIV3_POS(BL(9));
            DIV3_POS(BL(0x3C));
            DIV3_POS(BL(0x3B));
            DIV3_POS(BL(0x37));
            DIV3_POS(BL(0x38));
            DIV3_POS(BL(0x69));
            break;
        case 2:
            DIV3_POS(BL(0x11));
            DIV3_POS(BL(0x32));
            DIV3_POS(BL(0x6D));
            break;
        case 3:
            DIV3_POS(BL(0x2F));
            DIV3_POS(BL(0x36));
            DIV3_POS(BL(0x12));
            DIV3_POS(BL(0x13));
            DIV3_POS(BL(100));
            DIV3_POS(BL(0x67));
            DIV3_POS(BL(0x6E));
            DIV3_POS(BL(0x13));
            break;
        case 4:
            DIV3_POS(BL(4));
            DIV3_POS(BL(5));
            DIV3_POS(BL(6));
            DIV3_POS(BL(10));
            DIV3_POS(BL(0x0B));
            DIV3_POS(BL(0x0C));
            DIV3_POS(BL(0x0D));
            DIV3_POS(BL(0x2B));
            DIV3_POS(BL(0x2D));
            DIV3_POS(BL(0x2E));
            DIV3_POS(BL(0x30));
            DIV3_POS(BL(0x31));
            DIV3_POS(BL(0x39));
            DIV3_POS(BL(0x4B));
            DIV3_POS(BL(99));
            DIV3_POS(BL(0x68));
            DIV3_POS(BL(0x71));
            DIV3_POS(BL(0x72));
            break;
        case 5:
            DIV3_POS(BL(0x2A));
            DIV3_POS(BL(1));
            DIV3_POS(BL(2));
            DIV3_POS(BL(3));
            DIV3_POS(BL(0x2A));
            DIV3_POS(BL(0x33));
            DIV3_POS(BL(0x34));
            DIV3_POS(BL(0x49));
            DIV3_POS(BL(0x4A));
            DIV3_POS(BL(0x33));
            DIV3_POS(BL(0x34));
            DIV3_POS(BL(0x51));
            DIV3_POS(BL(0x52));
            DIV3_POS(BL(0x53));
            DIV3_POS(BL(0x6C));
            break;
        case 6:
            DIV3_POS(BL(0x29));
            DIV3_POS(BL(0x3A));
            DIV3_POS(BL(0x73));
            DIV3_POS(BL(0x55));
            break;
        }
        ++difficultyLevel;
    } while (difficultyLevel < 7);

    int total = 0;
    int* cursor = buildLists;
    int count = 125;
    do {
        if (*cursor < 0) {
            *cursor = 0;
        }
        ++cursor;
        --count;
    } while (count != 0);
    total = 0;
    cursor = buildLists;
    count = 125;
    do {
        total += *cursor;
        ++cursor;
        --count;
    } while (count != 0);

    int randomValue = debug_rand(S_TPLAYER_CPP, 0xC41);
    int remainder = randomValue % total;
    int selectedBuildList = 0;
    int cumulative = 0;
    int selectionIndex = 0;
    for (; selectionIndex < 125; ++selectionIndex) {
        cumulative += buildLists[selectionIndex];
        if (cumulative > remainder) {
            selectedBuildList = selectionIndex;
            break;
        }
    }

    rge_base_game->get_string(selectedBuildList + 0x26930, buildListName, 0x100);

    switch (selectedBuildList) {
    SELECT_SPECIAL(0x0D);
    SELECT_SPECIAL(0x0E);
    SELECT_SPECIAL(0x0F);
    SELECT_COMPUTER(0x13);
    SELECT_COMPUTER(0x14);
    SELECT_COMPUTER(0x15);
    SELECT_NONE(0x16);
    SELECT_NONE(0x17);
    SELECT_NONE(0x18);
    SELECT_NONE(0x19);
    SELECT_NONE(0x1A);
    SELECT_NONE(0x1B);
    SELECT_NONE(0x1C);
    SELECT_NONE(0x1D);
    SELECT_NONE(0x1E);
    SELECT_NONE(0x1F);
    SELECT_NONE(0x20);
    SELECT_NONE(0x21);
    SELECT_NONE(0x22);
    SELECT_NONE(0x23);
    SELECT_NONE(0x24);
    SELECT_NONE(0x25);
    SELECT_NONE(0x26);
    SELECT_NONE(0x27);
    SELECT_NONE(0x75);
    SELECT_NONE(0x76);
    SELECT_NONE(0x77);
    SELECT_NONE(0x78);
    SELECT_C48(0x3C);
    SELECT_C48(0x3D);
    SELECT_C48(0x3E);
    SELECT_C48(0x3F);
    SELECT_C48(0x40);
    SELECT_C48(0x41);
    SELECT_C48(0x42);
    SELECT_C48(0x43);
    SELECT_C48(0x44);
    SELECT_C48(0x45);
    SELECT_C48(0x46);
    SELECT_C48(0x47);
    SELECT_C48(0x4B);
    SELECT_C48(0x4C);
    SELECT_C48(0x4D);
    SELECT_C48(0x4E);
    SELECT_C48(0x4F);
    SELECT_C48(0x53);
    SELECT_C48(0x55);
    SELECT_C48(0x56);
    SELECT_C48(0x57);
    SELECT_C48(0x58);
    SELECT_C48(0x59);
    SELECT_C48(0x5A);
    SELECT_C48(0x5B);
    SELECT_C48(0x5C);
    SELECT_C48(0x5D);
    SELECT_C48(0x5E);
    SELECT_C48(0x5F);
    SELECT_C48(0x60);
    SELECT_C48(0x61);
    SELECT_C48(100);
    SELECT_C48(0x65);
    SELECT_C48(0x69);
    SELECT_C48(0x6A);
    SELECT_C48(0x6E);
    SELECT_C48(0x6F);
    SELECT_C48(0x73);
    SELECT_C48(0x74);
    SELECT_C48(0x79);
    SELECT_C48(0x7A);
    SELECT_C48(0x7B);
    SELECT_C48(0x7C);
    SELECT_C44_C2C(0x48);
    SELECT_C44_C2C(0x49);
    SELECT_C44_C28(0x4A);
    SELECT_C1C(6);
    SELECT_C1C(7);
    SELECT_C1C(8);
    SELECT_C1C(0x2B);
    SELECT_C1C(0x36);
    SELECT_C1C(0x37);
    SELECT_C1C(0x3A);
    SELECT_C1C(0x3B);
    SELECT_C1C(0x68);
    SELECT_C2C(0);
    SELECT_C2C(1);
    SELECT_C2C(2);
    SELECT_C2C(0x29);
    SELECT_C2C(0x32);
    SELECT_C2C(0x33);
    SELECT_C2C(0x50);
    SELECT_C2C(0x51);
    SELECT_C2C(0x52);
    SELECT_C2C(0x6B);
    SELECT_C20(0x10);
    SELECT_C20(0x31);
    SELECT_C20(0x6C);
    SELECT_C24(0x11);
    SELECT_C24(0x12);
    SELECT_C24(0x2E);
    SELECT_C24(0x34);
    SELECT_C24(0x35);
    SELECT_C24(99);
    SELECT_C24(0x66);
    SELECT_C24(0x6D);
    SELECT_C30(0x28);
    SELECT_C30(0x39);
    SELECT_C30(0x54);
    SELECT_C30(0x72);
    SELECT_C28(3);
    SELECT_C28(4);
    SELECT_C28(5);
    SELECT_C28(9);
    SELECT_C28(10);
    SELECT_C28(0x0B);
    SELECT_C28(0x0C);
    SELECT_C28(0x2A);
    SELECT_C28(0x2C);
    SELECT_C28(0x2D);
    SELECT_C28(0x2F);
    SELECT_C28(0x30);
    SELECT_C28(0x38);
    SELECT_C28(0x62);
    SELECT_C28(0x67);
    SELECT_C28(0x70);
    SELECT_C28(0x71);
    default:
        ++DAT_00886c28;
        break;
    }
    ++DAT_00886c44;

selectedCountersDone:
    rge_base_game->get_string((int)this->civ_id + 0x27F6, tempString, 0x100);
    this->playerAI->logCommonHistory(S_I_AM_THE_CIV, tempString, (int)this->civ_id - 1);
    this->playerAI->logCommonHistory(S_SELECTED_BEST_BUILD_LIST, buildListName);
    strcpy(ruleSetName, S_RANDOM_GAME_SPECIALIZED);
    this->playerAI->logCommonHistory(S_SETTING_AI_PERSONALITY);

    int workingMapType = mapType;
    switch (victoryType) {
    case 0:
    case 1:
        SET_RULE(0x36, 5);
        SET_RULE(0x37, 5);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        workingMapType = GET_RULE(1);
        if (workingMapType > 0) {
            SET_RULE(0, 0x32);
            SET_RULE(1, 0x19);
            SET_RULE(2, 0x19);
        } else {
            SET_RULE(0, 0x32);
            SET_RULE(2, 0x32);
        }
        if (mapType > 1) {
            SET_RULE(3, 5);
        }
        SET_RULE(0x2A, 2);
        SET_RULE(0x3D, 2);
        workingMapType = mapType;
        if (victoryType != 2) {
            SET_RULE(0x26, mapSize + 1);
            SET_RULE(0x24, 1);
            if (victoryType == 3) {
                SET_RULE(0x36, 1);
            } else {
                SET_RULE(0x36, 5);
            }
            if (victoryType == 4) {
                SET_RULE(0x37, 1);
            } else {
                SET_RULE(0x37, 5);
            }
        }
        break;
    }

    if (rge_base_game->deathMatch() == 1) {
        SET_RULE(4, 10);
    }

    int attackTime = (debug_rand(S_TPLAYER_CPP, 0xE3A) % 12 + 0x1C) * 60;
    switch (selectedBuildList) {
    case 0:
    case 3:
    case 0x0B:
    case 0x0C:
    case 0x0D:
    case 0x13:
    case 0x2F:
    case 0x30:
    case 0x33:
    case 0x37:
    case 0x39:
    case 0x48:
    case 0x4A:
    case 0x4B:
    case 0x4E:
    case 0x51:
    case 0x55:
    case 0x58:
    case 0x5A:
    case 0x5E:
    case 0x60:
    case 100:
    case 0x69:
    case 0x6E:
    case 0x73:
        ++DAT_00886c3c;
        attackTime = (debug_rand(S_TPLAYER_CPP, 0xE58) % 6 + 0x14) * 60;
        break;
    case 10:
    case 0x29:
    case 0x2B:
    case 0x2C:
    case 0x2D:
    case 0x32:
    case 0x3A:
    case 0x71:
        ++DAT_00886c38;
        attackTime = (debug_rand(S_TPLAYER_CPP, 0xE64) % 4 + 0x0B) * 60;
        break;
    case 9:
    case 0x38:
        attackTime = (debug_rand(S_TPLAYER_CPP, 0xE69) % 2 + 5) * 60;
        ++DAT_00886c38;
        break;
    default:
        ++DAT_00886c40;
        break;
    }

    int difficultyCopy = gameDifficulty;
    if (gameDifficulty == 0 && debug_rand(S_TPLAYER_CPP, 0xE73) % 3 == 0) {
        attackTime -= 300;
    }
    SET_RULE(0x68, attackTime);
    SET_RULE(0x10, 2);
    SET_RULE(0x1A, 10);
    SET_RULE(0x5D, 1);
    SET_RULE(99, 4);

    if (debug_rand(S_TPLAYER_CPP, 0xE80) % 3 == 0) {
        SET_RULE(0xBC, 0);
    } else {
        SET_RULE(0xBC, 1);
    }
    SET_RULE(0xC3, debug_rand(S_TPLAYER_CPP, 0xE86) % 0x28 + 10);
    SET_RULE(0xBD, debug_rand(S_TPLAYER_CPP, 0xE8A) % 0x46 + 0x1E);
    SET_RULE(0xC6, (debug_rand(S_TPLAYER_CPP, 0xE8E) % 5 + 5) * gameDifficulty);
    SET_RULE(0xC7, (debug_rand(S_TPLAYER_CPP, 0xE92) % 10 + 10) * gameDifficulty);
    SET_RULE(0xA1, 4);

    randomValue = mapSize;
    if (workingMapType == 0) {
        randomValue -= 2;
    } else if (workingMapType == 1) {
        randomValue -= 1;
    }

    switch (randomValue) {
    case -2:
    case -1:
        SET_RULE(0x49, debug_rand(S_TPLAYER_CPP, 0xEA2) % 2 + 0x0E);
        SET_RULE(0x4A, GET_RULE(0x49) + debug_rand(S_TPLAYER_CPP, 0xEA4) % 4 + 1);
        break;
    case 0:
        SET_RULE(0x49, debug_rand(S_TPLAYER_CPP, 0xEA7) % 2 + 0x0F);
        SET_RULE(0x4A, GET_RULE(0x49) + debug_rand(S_TPLAYER_CPP, 0xEA9) % 4 + 1);
        break;
    case 1:
        SET_RULE(0x49, debug_rand(S_TPLAYER_CPP, 0xEAC) % 3 + 0x10);
        SET_RULE(0x4A, GET_RULE(0x49) + debug_rand(S_TPLAYER_CPP, 0xEAE) % 5 + 1);
        break;
    case 2:
        SET_RULE(0x49, debug_rand(S_TPLAYER_CPP, 0xEB1) % 2 + 0x11);
        SET_RULE(0x4A, GET_RULE(0x49) + debug_rand(S_TPLAYER_CPP, 0xEB3) % 6 + 1);
        break;
    case 3:
        SET_RULE(0x49, debug_rand(S_TPLAYER_CPP, 0xEB6) % 2 + 0x12);
        SET_RULE(0x4A, GET_RULE(0x49) + debug_rand(S_TPLAYER_CPP, 0xEB8) % 7 + 1);
        break;
    case 4:
        SET_RULE(0x49, debug_rand(S_TPLAYER_CPP, 0xEBB) % 4 + 0x12);
        SET_RULE(0x4A, GET_RULE(0x49) + debug_rand(S_TPLAYER_CPP, 0xEBD) % 8 + 1);
        break;
    default:
        SET_RULE(0x49, debug_rand(S_TPLAYER_CPP, 0xEC1) % 2 + 0x12);
        SET_RULE(0x4A, GET_RULE(0x49) + debug_rand(S_TPLAYER_CPP, 0xEC3) % 9 + 1);
        break;
    }
    SET_RULE(0xD0, 1);
    SET_RULE(0xD1, 1);
    SET_RULE(0xD2, 1);
    SET_RULE(0xDF, 1);

    if (workingMapType == 0) {
        SET_RULE(0xD4, 3);
        SET_RULE(0xD5, 6);
        SET_RULE(0xD6, 2);
        SET_RULE(0xE0, 6);
    } else if (workingMapType == 1) {
        SET_RULE(0xD4, 2);
        SET_RULE(0xD5, 5);
        SET_RULE(0xD6, 2);
        SET_RULE(0xE0, 4);
    } else if (workingMapType == 2 || workingMapType == 6 || workingMapType == 5 || workingMapType == 8) {
        SET_RULE(0xD4, 1);
        SET_RULE(0xD5, 4);
        SET_RULE(0xD6, 1);
        SET_RULE(0xE0, 3);
    } else if (workingMapType == 3 || workingMapType == 4 || workingMapType == 7) {
        SET_RULE(0xD4, 0);
        SET_RULE(0xD5, 0);
        SET_RULE(0xD6, 0);
        SET_RULE(0xE0, 0);
    }

    if (allowAIToCheat != 0) {
        int cheatFood = 0;
        int cheatGold = 0;
        int cheatWood = 0;
        int cheatStone = 0;
        if (difficultyCopy == 0) {
            cheatFood = 2000;
            cheatWood = 2000;
            cheatStone = 2000;
            cheatGold = 2000;
        }
        SET_RULE(0x8A, cheatFood);
        SET_RULE(0x8B, cheatWood);
        SET_RULE(0x8C, cheatStone);
        SET_RULE(0x8D, cheatGold);
        gameDifficulty = difficultyCopy;
    }

    SET_RULE(0xA8, 0);
    SET_RULE(0xA2, 0);
    if (gameDifficulty < 3) {
        SET_RULE(0xC2, 1);
        SET_RULE(0x2F, 2);
    } else {
        SET_RULE(0xC2, 0);
        SET_RULE(0x2F, 1);
    }

    if (gameDifficulty == 0) {
        SET_RULE(0xBA, 0xB4);
        SET_RULE(0xBA, 200);
    } else if (gameDifficulty == 1) {
        SET_RULE(0xBA, 0xB4);
        SET_RULE(0xBA, 0x96);
    } else if (gameDifficulty == 2) {
        SET_RULE(0xBA, 0xB4);
        SET_RULE(0xBA, 100);
    } else if (gameDifficulty == 3) {
        SET_RULE(0xBA, 0xB4);
        SET_RULE(0xBA, 0x32);
    }

    if (debug_rand(S_TPLAYER_CPP, 0xF50) % 6 < 5) {
        SET_RULE(0xB5, 1);
    } else {
        SET_RULE(0xB5, 0);
    }
    if (debug_rand(S_TPLAYER_CPP, 0xF56) % 3 < 1) {
        SET_RULE(0xB6, 1);
    } else {
        SET_RULE(0xB6, 0);
    }
}
