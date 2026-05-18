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
// left in scratch: broad behavior is represented, but debug dump formatting loops, bitmask offset topology, and transitive-alliance loop shape are incomplete/collapsed; rebuilt is size-short. No accepted_drift: no localized diff.

extern "C" void __cdecl debug_printf(void*, const char*, ...);
extern void* debug_out;
extern void* gMainView;

class Panel { public: virtual void* vf0(); virtual void* vf1(); virtual void* getA(); virtual void* getB(); virtual void setMode(int); };
struct Player {
    char gap0[0x84]; unsigned char* diplomacy;
    int rel0[9];              // +88..+A8-ish
    int mutual[9];            // +AC..+CC
    int allyBitsHi;           // +D0
    int allyBitsLo;           // +D4
    int mutualBits;           // +D8
    int rel2[9];              // +DC..+FC
    int alive;                // +100
    unsigned char civ;        // +104
};
class RGE_Game_World {
public:
    void* vtbl; int id; char gap08[0x3c-0x08]; short playerCount; Player** players;
    void update_mutual_allies();
};

void RGE_Game_World::update_mutual_allies() {
    int i,j,k;
    debug_printf(debug_out,(const char*)0x58EF08,id);
    for (i=0;i<playerCount;i++) {
        Player* p=players[i];
        p->allyBitsHi=0; p->allyBitsLo=0; p->mutualBits=0;
        for (j=0;j<9;j++) p->rel2[j]=0;
        for (j=0;j<9;j++) {
            if (j==i) {
                p->mutual[j]=1;
                p->allyBitsLo = 1 << i;
                p->allyBitsHi = 1 << (i+16);
            } else p->mutual[j]=0;
        }
    }

    for (i=1;i<playerCount;i++) {
        Player* p=players[i];
        if (p->alive==1) {
            for (j=1;j<playerCount;j++) {
                if (j==i) continue;
                if (!p->diplomacy[j] && !players[j]->diplomacy[i]) {
                    p->mutual[j]=1;
                    p->allyBitsLo |= 1 << j;
                    p->allyBitsHi |= 1 << (j+16);
                }
            }
        }
    }

    for (i=0;i<playerCount;i++) {
        for (j=1;j<playerCount;j++) {
            if (j==i) continue;
            Player* p=players[i];
            if (p->mutual[j]==0) {
                for (k=1;k<playerCount;k++) {
                    if (p->mutual[k] && players[k]->mutual[j]) {
                        p->mutualBits |= 1 << j;
                        p->rel2[j] |= 1 << k;
                    }
                }
            }
        }
    }

    for (i=0;i<playerCount;i++) {
        Player* p=players[i];
        debug_printf(debug_out,(const char*)0x58EEFC,i);
        debug_printf(debug_out,(const char*)0x58EEA0,p->allyBitsHi,p->allyBitsLo,p->mutualBits);
        debug_printf(debug_out,(const char*)0x58EE6C,p->alive,p->civ);
        debug_printf(debug_out,(const char*)0x58EE58);
        for (j=0;j<9;j++) debug_printf(debug_out,(const char*)0x584610,p->rel0[j]);
        debug_printf(debug_out,(const char*)0x58EE40);
        for (j=0;j<9;j++) debug_printf(debug_out,(const char*)0x584610,p->mutual[j]);
        debug_printf(debug_out,(const char*)0x58EE28);
        for (j=0;j<9;j++) debug_printf(debug_out,(const char*)0x58EE20,p->rel2[j]);
    }
    Panel* a = (Panel*)((Panel*)gMainView)->getA();
    if (a) a->setMode(2);
    Panel* b = (Panel*)((Panel*)gMainView)->getB();
    if (b) b->setMode(2);
}
