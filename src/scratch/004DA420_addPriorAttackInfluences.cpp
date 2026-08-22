// VA: 004DA420 TribeInformationAIModule::addPriorAttackInfluences
// Source: taiinfmd.cpp lines 1973-2005
// Attempt log:
// 1: natural attack memory scan with local XYPoint min/max and setMisc loops: frame too small because loop count was aliased with max.x.
// 2: use separate count local plus byte-offset local to match original five stack slots.
// 3: remove persistent AttackMemory* local; original uses EAX then reloads base after mapBound rather than carrying entry in ESI.
// 4: split md/player owner test; no register-order improvement.
// 5: swapped min/max assignment order; worsened local store order, rolled back.
// 6: tried base2/entry2/max temp to force indexed max reload; still wrong order/length.
// 7: /O1 too small; removed custom flag.
// 8: a volatile player read reached exact output, but this was rejected during
//    promotion audit as unsupported compiler steering; the ordinary typed read is
//    retained for further source recovery.
// 9: a localized variant lab also found an exact packed-record access basin, but
//    its raw offset plumbing is not retained as canonical source.
// Left in scratch despite a former exact diagnostic: recover a natural typed source
// that preserves the observed load order without artificial volatility or offsets.
// Fresh bounded pass: corrected virtual RGE_Player layout, reference and direct
// md->player forms, signed owner/id types, TribeMainDecision ownership, typed max
// access, a combined eligibility condition, and comparison order. These produced
// the same 281-byte basin or worsened it; the clean typed source is restored.
// Retry orch-4DA420-b: direct md/player chains, a player reference, explicit md
// liveness, negated equality, and reversed comparison all duplicated the 281-byte
// basin or worsened it to 282 bytes. A volatile player pointer restored 381 exact
// bytes, but this is compiler steering, so the ordinary typed pointer is retained.
// A donor-era <stdlib.h> context changed the basin to 384 bytes and was removed.
// Natural-source cleanup: direct typed attackMemories[count] accesses, combined
// eligibility, and ordinary nested influence loops reproduce the 281-byte basin.
// This removes the rejected byte-offset cursor and packed-record access forms.
// Revisit sa-e82554ff-r1: the natural y,x point spelling with pointer mapBound,
// complete AttackMemory fields, the reviewed polymorphic base, complete player
// fields, unsigned owner ABI, short player id, typed reference aliases, and
// declaration-order changes all reproduced the same 281-byte mismatch. The
// pinned typed source is restored. The remaining first hunk reverses the
// md/player and attackingOwner load order; the next hunk uses a different
// record-address lowering. No policy-valid exact source was found.
// Revisit sa-3d0c436c-r1: y,x point spelling, XYPoint declaration swaps,
// reversed player-id comparison, moving AttackMemory pointers, typed 0x18
// byte offsets, and field-pointer max reads all reproduced the 281-byte
// basin or made the frame and CFG worse. The clean typed source is restored.

struct XYPoint {
    int x;
    int y;
};

struct AttackMemory {
    int id;                    // +00
    unsigned char type;        // +04
    unsigned char minX;        // +05
    unsigned char minY;        // +06
    unsigned char maxX;        // +07
    unsigned char maxY;        // +08
    unsigned char attackingOwner; // +09
    unsigned char targetOwner;    // +0A
    char gap_0B[0x18 - 0x0B];
};

class PathingSystem {
public:
    void setMisc(int row, int column, unsigned char value);
};

extern PathingSystem aiPathSystem;

class RGE_Player {
public:
    char gap_00[0x4A];
    unsigned short id;
};

class MainDecisionAIModule {
public:
    char gap_000[0xF0];
    RGE_Player* player; // +F0
};

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    MainDecisionAIModule* md; // +100
    int mapXSizeValue;        // +104
    int mapYSizeValue;        // +108
    char gap_10C[0x1FC - 0x10C];
    int maxAttackMemories;    // +1FC
    AttackMemory* attackMemories; // +200

    int mapBound(XYPoint* pt);
    void addPriorAttackInfluences(int targetOwner, int unused);
};

void TribeInformationAIModule::addPriorAttackInfluences(int targetOwner, int unused)
{
    XYPoint max;
    XYPoint min;
    int count;

    count = 0;
    if (this->maxAttackMemories > 0) {
        do {
            if (this->attackMemories[count].id != -1 &&
                (int)this->attackMemories[count].targetOwner == targetOwner &&
                (unsigned short)this->attackMemories[count].attackingOwner ==
                    this->md->player->id) {
                min.x = this->attackMemories[count].minX;
                min.y = this->attackMemories[count].minY;
                this->mapBound(&min);

                max.x = this->attackMemories[count].maxX;
                max.y = this->attackMemories[count].maxY;
                this->mapBound(&max);

                for (int x = min.x; x <= max.x; ++x) {
                    for (int y = min.y; y <= max.y; ++y) {
                        aiPathSystem.setMisc(x, y, 0x4B);
                    }
                }

                min.x = min.x - 5;
                min.y = min.y - 5;
                this->mapBound(&min);
                max.x += 5;
                max.y += 5;
                this->mapBound(&max);

                for (int x2 = min.x; x2 <= max.x; ++x2) {
                    for (int y2 = min.y; y2 <= max.y; ++y2) {
                        aiPathSystem.setMisc(x2, y2, 0x0F);
                    }
                }
            }
            ++count;
        } while (count < this->maxAttackMemories);
    }
}
