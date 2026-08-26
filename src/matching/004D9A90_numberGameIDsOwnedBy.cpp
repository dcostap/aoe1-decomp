// 004D9A90 TribeInformationAIModule::numberGameIDsOwnedBy
// PDB: taiinfmd.cpp:1641-1672, 132 bytes
// __thiscall, int, ret 8 (2 params: int param1, int param2)
// FLAGS: default
//
// Attempt log:
// probe 1: 93% â€” RGE_Game_World::object embedded
// probe 2: 61% â€” prologue/register order wrong, extra local var
// probe 3: restored the complete ObjectMemory record, typed md->aiPlayer
// ownership, and typed owner->id access. Standalone and grouped checks match.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class RGE_Game_World;
class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char gap_04[0x12568];
    RGE_Player* aiPlayer;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    void* master_obj;        // +0x8
    RGE_Player* owner;       // +0xC
};

class RGE_Game_World {
public:
    char gap_00[0x88];
    void** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    void** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

    RGE_Static_Object* object(int index);
};

class ObjectMemory {
public:
    int id;                  // +0x00
    short type;              // +0x04
    short group;             // +0x06
    unsigned char x;         // +0x08
    unsigned char y;         // +0x09
    unsigned char z;         // +0x0A
    unsigned char owner;     // +0x0B
    short hitPoints;         // +0x0C
    unsigned char pad_0E[2]; // +0x0E
    int attackAttempts;      // +0x10
    unsigned char kills;     // +0x14
    unsigned char pad_15[3]; // +0x15
    float damageCapability;  // +0x18
    float rateOfFire;        // +0x1C
    float range;             // +0x20
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    TribeMainDecisionAIModule* md; // +0x100
    char gap_104[0xC];
    int maxImportantObjectMemory;  // +0x110
    ObjectMemory* importantObjectMemory;  // +0x114

    int numberGameIDsOwnedBy(int param1, int param2);
};
#endif

#endif
int TribeInformationAIModule::numberGameIDsOwnedBy(int param1, int param2) {
    int result = 0;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            int id = this->importantObjectMemory[i].id;
            if (id != -1) {
                RGE_Game_World* world = this->md->aiPlayer->world;
                RGE_Static_Object* obj = world->object(id);
                if (obj != 0) {
                    short owner_id = obj->owner->id;
                    if (owner_id == param2 && (param1 == -1 || param1 == this->importantObjectMemory[i].owner)) {
                        result++;
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return result;
}
