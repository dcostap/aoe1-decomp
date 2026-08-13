// 005462D0 RGE_Game_World::update_mutual_allies
// World.cpp
// Attempt log:
// try 1: broad reconstruction from packet: clear per-player ally bitmasks/matrices, derive mutual allies from player diplomacy bytes, dump debug tables, refresh UI panels.
// try 2: modeled initial debug log with world id and global debug sink 0x886C58.
// try 3: modeled playerCount at +0x3C and players array at +0x40, clearing +0xD0/+0xD4/+0xD8 and +0xDC..+0xFC.
// try 4: modeled 9-entry mutual matrix at +0xAC with self entries set and self bits in low/high masks.
// try 5: modeled alive-player loop from player 1, requiring both diplomacy bytes zero before setting mutual ally entry and ORing bit masks.
// try 6: modeled transitive mutual/indirect relation pass setting +0xD8 and +0xDC.. entries when i and j are connected through k.
// try 7: modeled debug dump for each player: header, bitmasks, alive/civ, and relation/mutual/indirect arrays.
// try 8: modeled final UI refresh through global view 0x62C574 virtual getA/getB and setMode(2).
// try 9: /GX probe made no code/size change; removed flag file.
// try 10: current source compiles but rebuilt .text is 896B vs original 1092B, no full diff.
// try 11: reviewed original: main missing size is exact debug-print punctuation loops and low-level pointer/offset topology (offset loops 0x88/0xAC/0xDC, comma/newline prints) plus exact nested-loop register scheduling.
// worker session: restored stdio/DVlogf and the BaseGame/Panel slots, added all
//   binary-observed comma/newline fprintf sites, and replaced folded clears with
//   the original 0xdc/0x100 cursors.  The transitive pass now preserves the
//   executable's three mutualAlly predicates and shared outer byte cursor.
// final bounded result: 1096 rebuilt vs 1092 original, frame 0xc, 17/17 calls,
//   93.23% shape, 822 positional bytes (75.0000%), 255 edit bytes.  The remaining
//   gap is broad VC5 register/block scheduling around the second diplomacy pass,
//   transitive setup, and final panel null tests; no accepted_drift proposal.
// shardA5 session: tested direct literal-one and for-loop diplomacy forms; they
//   emitted the same code.  Direct players[i] reloads improved shape but widened
//   size.  Named Player arrays and the transitive mutual-allies fields are kept.
// final bounded result: 1082 rebuilt vs 1092 original, frame 0x8, 17/17 calls,
//   88.92% shape, 832 positional bytes (76.1905%), 514 edit bytes.  The remaining
//   structural gap starts in the prologue and second diplomacy pass; no exact or
//   accepted_drift proposal.
// orch-5462D0-a: proven image-address macros fixed the singleton loads and the
//   transitive store was corrected to removeVisibleBits (+0xDC..+0xFC), not
//   mutualAlly.  This restored the 0xC frame and improved the best diff to 778.
//   Cached count, scoped loop locals, and direct array-pointer variants were
//   duplicate or worse.  Raw row-cursor source improved edit alignment but was
//   restored to named fields as a source-plausibility checkpoint.
// validated pause candidate: 1099 rebuilt vs 1092 original, frame 0xC,
//   17/17 calls, 89.54% shape, 778 positional bytes, 460 edit bytes.  The
//   remaining structural lead is direct diplomacy register/block scheduling.
// Replaced raw World.cpp debug-format addresses with named exact literals.
// This retained the typed model and improved positional drift to 768 bytes.

#include <stdio.h>

#define DVlogf (*(FILE**)0x886C58)

static const char s_update_visibilities[] =
    "updating player visibilities @ wt=%d\n";
static const char s_player[] = "player %d\n";
static const char s_masks[] =
    "  mutualExploredMask = %8.8x   mutualVisibleMask = %8.8x   "
    "nonMutualVisibleMask = %8.8x\n";
static const char s_player_flags[] =
    "  allied_LOS_Enable = %d   allied_victory = %d \n";
static const char s_diplomacy[] = "  unitDiplomacy = [";
static const char s_mutual_allies[] = "  mututalAlly = [";
static const char s_removed_visible_bits[] = "  RemoveVisibleBits = [";
static const char s_decimal[] = "%d";
static const char s_separator[] = ", ";
static const char s_list_end[] = "]\n";

class Panel {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void setMode(int);
};
class RGE_Base_Game {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual Panel* getA();
    virtual Panel* getB();
};
#define rge_base_game (*(RGE_Base_Game**)0x62C574)
struct Player {
    char gap0[0x84]; unsigned char* relations;
    int unit_diplomacy[9];    // +88..+A8
    int mutualAlly[9];        // +AC..+CC
    int mutualExploredMask;   // +D0
    int mutualVisibleMask;    // +D4
    int nonMutualVisibleMask; // +D8
    int removeVisibleBits[9]; // +DC..+FC
    int allied_LOS_Enable;    // +100
    unsigned char civ;        // +104
};
class RGE_Game_World {
public:
    void* vtbl; int world_time; char gap08[0x3c-0x08]; short player_num; Player** players;
    void update_mutual_allies();
};

void RGE_Game_World::update_mutual_allies() {
    int i,j,k;
    int one = 1;
    int pNum, index;
    fprintf(DVlogf, s_update_visibilities, world_time);
    i=0;
    if (i < player_num) do {
        this->players[i]->mutualExploredMask=0;
        this->players[i]->mutualVisibleMask=0;
        this->players[i]->nonMutualVisibleMask=0;
        for (j=0; j<9; ++j) this->players[i]->removeVisibleBits[j]=0;
        int* mutual = this->players[i]->mutualAlly;
        j=0;
        do {
            if (j==i) {
                *mutual=1;
                this->players[i]->mutualVisibleMask = 1 << i;
                this->players[i]->mutualExploredMask = 1 << (i+16);
            } else *mutual=0;
            ++j;
            ++mutual;
        } while (j < 9);
        ++i;
    } while (i < player_num);

    {
        k = player_num;
        i = one;
        if (i < k) do {
            if (players[i]->allied_LOS_Enable == one) {
                j = one;
                if (j < k) do {
                    if (j != i) {
                        if (!players[i]->relations[j] && !players[j]->relations[i]) {
                            players[i]->mutualAlly[j] = 1;
                            players[i]->mutualVisibleMask |= 1 << j;
                            players[i]->mutualExploredMask |= 1 << (j + 16);
                        }
                    }
                } while (++j < k);
            }
            k = player_num;
            ++i;
        } while (i < k);
    }

    for (i=0; i < player_num; ++i) {
        Player* p = players[i];
        for (pNum=1; pNum < player_num; ++pNum) {
            if (pNum != i && p->mutualAlly[pNum] == 0) {
                for (index=1; index < player_num; ++index) {
                    if (p->mutualAlly[index] == 0 &&
                        players[index]->mutualAlly[pNum] == 1 &&
                        players[index]->mutualAlly[i] == 1) {
                        p->nonMutualVisibleMask |= 1 << pNum;
                        p->removeVisibleBits[pNum] |= 1 << index;
                    }
                }
            }
        }
    }

    for (i=0;i<player_num;i++) {
        fprintf(DVlogf, s_player, i);
        fprintf(DVlogf, s_masks, players[i]->mutualExploredMask, players[i]->mutualVisibleMask, players[i]->nonMutualVisibleMask);
        fprintf(DVlogf, s_player_flags, players[i]->allied_LOS_Enable, players[i]->civ);
        fprintf(DVlogf, s_diplomacy);
        for (j=0;j<9;j++) {
            fprintf(DVlogf, s_decimal, players[i]->unit_diplomacy[j]);
            if (j < 8) fprintf(DVlogf, s_separator);
            else fprintf(DVlogf, s_list_end);
        }
        fprintf(DVlogf, s_mutual_allies);
        for (j=0;j<9;j++) {
            fprintf(DVlogf, s_decimal, players[i]->mutualAlly[j]);
            if (j < 8) fprintf(DVlogf, s_separator);
            else fprintf(DVlogf, s_list_end);
        }
        fprintf(DVlogf, s_removed_visible_bits);
        for (j=0;j<9;j++) {
            fprintf(DVlogf, s_decimal, players[i]->removeVisibleBits[j]);
            if (j < 8) fprintf(DVlogf, s_separator);
            else fprintf(DVlogf, s_list_end);
        }
    }
    Panel* panel = rge_base_game->getA();
    if (panel) panel->setMode(2);
    panel = rge_base_game->getB();
    if (panel) panel->setMode(2);
}
