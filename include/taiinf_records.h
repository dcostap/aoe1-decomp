#ifndef AOE1_TAIINF_RECORDS_H
#define AOE1_TAIINF_RECORDS_H

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    int attackAttempts;
    unsigned char kills;
    float damageCapability;
    float rateOfFire;
    float range;
};

struct BuildingLot {
    int typeID;
    unsigned char status;
    unsigned char x;
    unsigned char y;
};

struct AttackMemory {
    int id;
    unsigned char type;
    unsigned char minX;
    unsigned char minY;
    unsigned char maxX;
    unsigned char maxY;
    unsigned char attackingOwner;
    unsigned char targetOwner;
    short kills;
    unsigned char success;
    unsigned long timeStamp;
    int play;
};

struct QuadrantLog {
    int numberExploredTiles;
    int numberAttacksOnUs;
    int numberAttacksByUs;
};

struct ResourceMemory {
    int id;
    unsigned char x;
    unsigned char y;
    unsigned char gatherAttempts;
    int gatherValue;
    unsigned char valid;
    unsigned char gone;
    unsigned char dropDistance;
    unsigned char resourceType;
    int dropsiteID;
};

typedef char taiinf_object_memory_size[
    (sizeof(ObjectMemory) == 0x24) ? 1 : -1];
typedef char taiinf_building_lot_size[
    (sizeof(BuildingLot) == 0x08) ? 1 : -1];
typedef char taiinf_attack_memory_size[
    (sizeof(AttackMemory) == 0x18) ? 1 : -1];
typedef char taiinf_quadrant_log_size[
    (sizeof(QuadrantLog) == 0x0C) ? 1 : -1];
typedef char taiinf_resource_memory_size[
    (sizeof(ResourceMemory) == 0x14) ? 1 : -1];

#endif
