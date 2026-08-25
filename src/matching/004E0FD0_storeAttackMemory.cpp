// VA: 004E0FD0 TribeInformationAIModule::storeAttackMemory
// Source: taiinfmd.cpp lines 6370-6418
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 1: first typed - 320 bytes
// 2: for loop + volatile - 352 bytes
// 3: while loop + direct field access - 416 bytes
// 4: volatile timeOffset + push ecx - 416 bytes
// 5: moved bestIdx init after quadrant - 416 bytes
// 6: explicit int locals for params, match exact computation
// 7: signed `/ 2` quadrant divisions and typed QuadrantLog/RGE_Player ownership
//    improved structural parity to 441 bytes / 250 positional diff.
// 8: do/while scan, result-index split, scoped cursor declarations, and a
//    timestamp pointer were tested; the single-index raw scan remains closer.
// 9: the ordinary timestamp-pointer variant was rejected (429 bytes / 408 diff)
//    and restored; remaining drift is scan rotation/liveness plus mapY register
//    coloring (EBP versus original EBX).
// 10: testing one natural counted loop with one index and a first-body sentinel
//     check; typed memory fields and the existing store tail remain unchanged.
// 11: removed the redundant positive-count wrapper so the counted loop owns the
//     single max-memory test; this keeps the natural one-index scan shape.
// 12: the counted loop without the wrapper matches all 441 bytes under default
//     flags; the scan and store tail remain typed and free of cursor scaffolding.
// Main audit: the original reads both narrow coordinate parameter homes as
// dwords before masking them to bytes. Keep that binary-observed access width;
// ordinary unsigned conversions reverse the two loads and differ by two bytes.

#include <stdlib.h>

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct AttackMemory {
    int id;                     // +0x00
    unsigned char type;         // +0x04
    unsigned char minX;         // +0x05
    unsigned char minY;         // +0x06
    unsigned char maxX;         // +0x07
    unsigned char maxY;         // +0x08
    unsigned char attackingOwner; // +0x09
    unsigned char targetOwner;    // +0x0A
    unsigned char pad_0B;         // +0x0B
    short kills;                // +0x0C
    unsigned char success;      // +0x0E
    unsigned char pad_0F;       // +0x0F
    unsigned int timeStamp;     // +0x10
    int play;                   // +0x14
};

#endif
class RGE_Player {
public:
    char gap_00[0x4A];
    unsigned short id;
};

class MainAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;         // +0xF0
};

struct QuadrantLog {
    int numberExploredTiles;
    int numberAttacksOnUs;
    int numberAttacksByUs;
};

class InformationAIModule {
public:
    virtual ~InformationAIModule();
    char gap_04[0xEC];
};

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule : public InformationAIModule {
public:
    char gap_F0[0x100 - 0xF0];
    MainAIModule* md;           // +0x100
    int mapXSizeValue;          // +0x104
    int mapYSizeValue;          // +0x108
    char gap_10C[0x1FC - 0x10C];
    int maxAttackMemories;      // +0x1FC
    AttackMemory* attackMemories; // +0x200
    char gap_204[0x408 - 0x204];
    QuadrantLog quadrantLog[4][4]; // +0x408

    int storeAttackMemory(
        unsigned char param_1,
        unsigned char param_2,
        unsigned char param_3,
        unsigned char param_4,
        unsigned char param_5,
        unsigned char param_6,
        unsigned char param_7,
        short param_8,
        unsigned char param_9,
        unsigned int param_10,
        int param_11);
};
#endif

#endif
int TribeInformationAIModule::storeAttackMemory(
    unsigned char param_1,
    unsigned char param_2,
    unsigned char param_3,
    unsigned char param_4,
    unsigned char param_5,
    unsigned char param_6,
    unsigned char param_7,
    short param_8,
    unsigned char param_9,
    unsigned int param_10,
    int param_11)
{
    int bestIdx;
    int count;

    if (this->mapXSizeValue > 0 && this->mapYSizeValue > 0) {
        int nMaxX = *(int*)&param_4;
        int nMinX = *(int*)&param_2;
        nMaxX &= 0xFF;
        nMinX &= 0xFF;
        int sum = nMaxX + nMinX;
        int product = sum * 4;
        int cx = product / this->mapXSizeValue;
        product = product / this->mapYSizeValue;
        cx /= 2;
        product /= 2;
        if (cx > 4) cx = 3;
        if (product > 4) product = 3;

        unsigned short playerID = this->md->player->id;
        if (param_7 == playerID) {
            this->quadrantLog[cx][product].numberAttacksOnUs += 1;
        } else if (param_6 == playerID) {
            this->quadrantLog[cx][product].numberAttacksByUs += 1;
        }
    }

    bestIdx = -1;
    count = 0;

    for (count = 0; count < this->maxAttackMemories; ++count) {
        if (this->attackMemories[count].id == -1) {
            bestIdx = count;
            break;
        }

        if (bestIdx == -1 ||
            this->attackMemories[bestIdx].timeStamp <
                this->attackMemories[count].timeStamp) {
            bestIdx = count;
        }
    }

    if (bestIdx != -1) {
        this->attackMemories[bestIdx].id = count;
        this->attackMemories[bestIdx].type = param_1;
        this->attackMemories[bestIdx].minX = param_2;
        this->attackMemories[bestIdx].minY = param_3;
        this->attackMemories[bestIdx].maxX = param_4;
        this->attackMemories[bestIdx].maxY = param_5;
        this->attackMemories[bestIdx].attackingOwner = param_6;
        this->attackMemories[bestIdx].targetOwner = param_7;
        this->attackMemories[bestIdx].kills = param_8;
        this->attackMemories[bestIdx].success = param_9;
        this->attackMemories[bestIdx].timeStamp = param_10;
        this->attackMemories[bestIdx].play = param_11;
    }

    return bestIdx;
}
