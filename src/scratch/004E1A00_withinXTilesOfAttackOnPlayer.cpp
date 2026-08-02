// 004E1A00 TribeInformationAIModule::withinXTilesOfAttackOnPlayer
// Source: taiinfmd.cpp lines 6682-6716, size 233 bytes
//
// Attempt log:
// - Initial state: struct missing `type` at +0x04 (minX at +4 instead of +5,
//   stride 0x0C instead of 0x18) and an explicit `if (max <= 0) return 0;`
//   guard before the for loop -> rebuilt 219 bytes, redundant double guard
//   (test edi,edi; jle twice) and wrong field offsets.
// - Probe 1 (baseline): canonical AttackMemory layout from exact donor
//   004E1190 (type at +0x04, minX..targetOwner at +5..+0A, stride 0x18),
//   dropped explicit guard (VC5 for-loop guard covers it), natural dy/dx
//   reassignment checks. Now: rebuilt 211B vs 233B; struct offsets, stride,
//   call set, and 4-check register-reuse pattern (dy1=edi reused by check4)
//   all correct. Remaining drift is register allocation only: original spills
//   the loop counter to the param_1 slot ([esp+18h]) with am=edx (this stays
//   esi), tilesSq=ebp/tx=ebx, push ecx local; rebuilt keeps counter in eax,
//   am=esi (clobbers this), tilesSq=ebx/tx=ebp, no local. Matched sibling
//   004E1AF0 has the identical push-ecx/tilesSq=ebp prologue basin.
//   Next leads (untried): pointer-walk `AttackMemory* am = attackMemories`
//   declared before the loop; one-line `long dy=..., dx=...` declaration
//   (PDB line map attributes both statements to line 6694); indexed
//   `attackMemories[i]` access without the am local; hoisting this-based
//   reloads to keep `this` live in the loop body.

class RGE_Static_Object {
public:
    virtual void v00();
    int id;                              // +0x04
    char gap_08[0x38 - 0x08];
    float world_x;                       // +0x38
    float world_y;                       // +0x3C
};

struct AttackMemory {
    int id;                 // +0x00
    char type;              // +0x04
    char minX;              // +0x05
    char minY;              // +0x06
    char maxX;              // +0x07
    char maxY;              // +0x08
    char attackingOwner;    // +0x09
    char targetOwner;       // +0x0A
    short kills;            // +0x0C
    char success;           // +0x0E
    char gap_0F[5];
    int play;               // +0x14
};

class TribeInformationAIModule {
public:
    char gap_00[0x1FC];
    int maxAttackMemories;               // +0x1FC
    AttackMemory* attackMemories;        // +0x200

    int withinXTilesOfAttackOnPlayer(RGE_Static_Object* target, int tiles, int playerId);
};

int TribeInformationAIModule::withinXTilesOfAttackOnPlayer(
    RGE_Static_Object* target, int tiles, int playerId)
{
    int tilesSq = tiles * tiles;
    int tx = (int)target->world_x;
    int ty = (int)target->world_y;

    for (int i = 0; i < maxAttackMemories; i++) {
        AttackMemory* am = &attackMemories[i];
        if (am->id == -1 || !am->attackingOwner || (unsigned char)am->targetOwner != playerId)
            continue;

        int dy = (unsigned char)am->minY - ty;
        int dx = (unsigned char)am->minX - tx;
        if (dy * dy + dx * dx <= tilesSq) return 1;

        dy = (unsigned char)am->maxY - ty;
        if (dy * dy + dx * dx <= tilesSq) return 1;

        dx = (unsigned char)am->maxX - tx;
        if (dy * dy + dx * dx <= tilesSq) return 1;

        dy = (unsigned char)am->minY - ty;
        if (dy * dy + dx * dx <= tilesSq) return 1;
    }

    return 0;
}
