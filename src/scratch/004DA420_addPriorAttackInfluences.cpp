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
// Left in scratch: behavior modeled, but register/load scheduling around attack-memory byte loads and mapBound blocks remains broad.

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

class MainDecisionAIModule {
public:
    char gap_000[0xF0];
    void* player; // +F0
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
    int offset;
    int count;

    offset = 0;
    count = 0;
    if (this->maxAttackMemories > 0) {
        do {
            AttackMemory* entry = (AttackMemory*)((char*)this->attackMemories + offset);
            if (entry->id != -1 && (int)entry->targetOwner == targetOwner) {
                MainDecisionAIModule* md = this->md;
                void* player = md->player;
                if ((unsigned short)entry->attackingOwner != *(unsigned short*)((char*)player + 0x4A)) {
                    goto next_memory;
                }
                min.x = entry->minX;
                min.y = entry->minY;
                this->mapBound(&min);

                char* base2 = (char*)this->attackMemories;
                unsigned int mx = *(unsigned char*)(base2 + offset + 0x07);
                AttackMemory* entry2 = (AttackMemory*)(base2 + offset);
                max.x = mx;
                max.y = entry2->maxY;
                this->mapBound(&max);

                for (int x = min.x; x <= max.x; ++x) {
                    for (int y = min.y; y <= max.y; ++y) {
                        aiPathSystem.setMisc(x, y, 0x4B);
                    }
                }

                min.x -= 5;
                min.y -= 5;
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
next_memory:
            ++count;
            offset += 0x18;
        } while (count < this->maxAttackMemories);
    }
}
