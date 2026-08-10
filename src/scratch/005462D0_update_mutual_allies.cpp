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

#include <stdio.h>

extern FILE* DVlogf;

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
extern RGE_Base_Game* rge_base_game;
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
    fprintf(DVlogf,(const char*)0x58EF08,world_time);
    i=0;
    if (i < player_num) do {
        this->players[i]->mutualExploredMask=0;
        this->players[i]->mutualVisibleMask=0;
        this->players[i]->nonMutualVisibleMask=0;
        int offset=0xdc;
        do {
            offset += 4;
            *(int*)((char*)this->players[i]+offset-4)=0;
        } while (offset < 0x100);
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
        int one=1;
        i=one;
        if (one < player_num) do {
            Player* p=players[i];
            if (p->allied_LOS_Enable==one) {
                j=one;
                if (one < player_num) do {
                    if (j != i) {
                        if (!p->relations[j] && !players[j]->relations[i]) {
                            p->mutualAlly[j]=one;
                            p->mutualVisibleMask |= one << j;
                            p->mutualExploredMask |= one << (j+16);
                        }
                    }
                } while (++j < player_num);
            }
            ++i;
        } while (i < player_num);
    }

    i=0;
    int player_offset=0;
    if (i < player_num) do {
        j=1;
        if (1 < player_num) {
            int ally_offset=0xe0;
            do {
                if (j != i &&
                    *(int*)((char*)*(Player**)((char*)this->players+player_offset)+ally_offset-0x30) == 0) {
                    k=1;
                    if (k < player_num) do {
                        if (*(int*)((char*)*(Player**)((char*)this->players+player_offset)+0xac+k*4) == 0 &&
                            *(int*)((char*)players[k]+ally_offset-0x30) == 1 &&
                            *(int*)((char*)players[k]->mutualAlly+player_offset) == 1) {
                            *(int*)((char*)*(Player**)((char*)this->players+player_offset)+0xd8) |= 1 << j;
                            *(int*)((char*)*(Player**)((char*)this->players+player_offset)+ally_offset) |= 1 << k;
                        }
                        ++k;
                    } while (k < player_num);
                }
                ++j;
                ally_offset += 4;
            } while (j < player_num);
        }
        ++i;
        player_offset += 4;
    } while (i < player_num);

    for (i=0;i<player_num;i++) {
        fprintf(DVlogf,(const char*)0x58EEFC,i);
        fprintf(DVlogf,(const char*)0x58EEA0,players[i]->mutualExploredMask,players[i]->mutualVisibleMask,players[i]->nonMutualVisibleMask);
        fprintf(DVlogf,(const char*)0x58EE6C,players[i]->allied_LOS_Enable,players[i]->civ);
        fprintf(DVlogf,(const char*)0x58EE58);
        for (j=0x88;j<0xac;j+=4) {
            fprintf(DVlogf,(const char*)0x584610,*(int*)((char*)players[i]+j));
            if (j < 0xa8) fprintf(DVlogf,(const char*)0x584ee4);
            else fprintf(DVlogf,(const char*)0x58ee54);
        }
        fprintf(DVlogf,(const char*)0x58EE40);
        for (j=0xac;j<0xd0;j+=4) {
            fprintf(DVlogf,(const char*)0x584610,*(int*)((char*)players[i]+j));
            if (j < 0xcc) fprintf(DVlogf,(const char*)0x584ee4);
            else fprintf(DVlogf,(const char*)0x58ee54);
        }
        fprintf(DVlogf,(const char*)0x58EE28);
        for (j=0xdc;j<0x100;j+=4) {
            fprintf(DVlogf,(const char*)0x58EE20,*(int*)((char*)players[i]+j));
            if (j < 0xfc) fprintf(DVlogf,(const char*)0x584ee4);
            else fprintf(DVlogf,(const char*)0x58ee54);
        }
    }
    Panel* panel = rge_base_game->getA();
    if (panel) panel->setMode(2);
    panel = rge_base_game->getB();
    if (panel) panel->setMode(2);
}
