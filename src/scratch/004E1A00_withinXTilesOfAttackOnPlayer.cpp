// 004E1A00 TribeInformationAIModule::withinXTilesOfAttackOnPlayer
// Source: taiinfmd.cpp lines 6682-6716, size 233 bytes

class RGE_Static_Object {
public:
    virtual void dummy();
    char pad_04[0x34];
    float world_x;              // +0x38
    float world_y;              // +0x3C
};

struct AttackMemory {
    long id;
    unsigned char minX;          // +0x05
    unsigned char minY;          // +0x06
    unsigned char maxX;          // +0x07
    unsigned char maxY;          // +0x08
    unsigned char attackingOwner; // +0x09
    unsigned char targetOwner;    // +0x0A
};

class TribeInformationAIModule {
public:
    virtual void dummy();
    char pad_04[0x1F8];
    long maxAttackMemories;      // +0x1FC
    AttackMemory* attackMemories; // +0x200

    int withinXTilesOfAttackOnPlayer(RGE_Static_Object* target, int tiles, int playerId);
};

int TribeInformationAIModule::withinXTilesOfAttackOnPlayer(
    RGE_Static_Object* target, int tiles, int playerId)
{
    long tilesSq = tiles * tiles;
    long tx = (long)target->world_x;
    long ty = (long)target->world_y;

    if (maxAttackMemories <= 0)
        return 0;

    for (long i = 0; i < maxAttackMemories; i++) {
        AttackMemory* am = &attackMemories[i];
        if (am->id == -1 || !am->attackingOwner || (long)am->targetOwner != playerId)
            continue;

        long dy = (long)am->minY - ty;
        long dx = (long)am->minX - tx;
        if (dy * dy + dx * dx <= tilesSq) return 1;

        dy = (long)am->maxY - ty;
        if (dy * dy + dx * dx <= tilesSq) return 1;

        dx = (long)am->maxX - tx;
        if (dy * dy + dx * dx <= tilesSq) return 1;

        dy = (long)am->minY - ty;
        if (dy * dy + dx * dx <= tilesSq) return 1;
    }

    return 0;
}
