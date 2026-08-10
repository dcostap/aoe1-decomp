// VA: 004E1260 TribeInformationAIModule::loadLearnInfo
// PDB: taiinfmd.cpp:6451-6549
//
// Attempt log:
// initial reconstruction from packet/decompiler: filename build, rge_read temp stack blocks, natural add/grow int-array helpers.
// try 1: static add_unique helper compiled too small (.text 880 vs 1212), because helper not inlined/parent inlining missing.
// try 2: macro-expanded add_unique to inline the three grow/list blocks; compiles to full size but broad mismatch.
// try 3: fixed storeAttackMemory visible arity to 11 explicit params (matching wrapper in 004E0F90); still broad drift.
// try 4: switched temp from struct ObjectMemory24 to raw char[0x24] and named filename/civ locals to test stack/local scheduling; edit diff improved 71% -> 55.6%, frame still wrong.
// try 5: tested /GX flag; no change (original has no EH frame); removed flag.
// try 6: restored the period ObjectMemory/ManagedArray source surface, parameter-home loop counters, canonical resource arrays, and exact serialized field widths.
// try 7: corrected the addObjectMemory ABI to the packet's four-byte/byte/short/float parameter widths.
// try 8: swapped local_4 ahead of ObjectMemory temp to test the original four-byte stack-window placement.
// try 9: reordered the count/temp locals to the PDB/decompiler declaration order and named the reused local_2c explicitly.
// try 10: used the binary-proven absolute rge_base_game address without changing the canonical source surface.
// left in scratch: validate the canonical source before any codegen-only tuning.
// Main-agent audit: added donor-backed virtual destructors for the proven
// Base_Game and Player polymorphic boundaries without changing emitted bytes;
// the remaining uninitialized local warning reflects an unresolved serialized
// argument/stack-slot reconstruction, not a promoted exact candidate.

#include <stdio.h>

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl rge_open(char*, int);
extern "C" void __cdecl rge_read(int, void*, int);
extern "C" int __cdecl rge_close(int);

void* operator new(unsigned int size);
void operator delete(void* ptr);

class RGE_Game_Info {
public:
    char* get_current_player_name();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    RGE_Game_Info* info;
};

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x46];
    short id;
};

class MainDecision {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    unsigned char _pad_0[2];
    int attackAttempts;
    unsigned char kills;
    unsigned char _pad_1[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

struct ResourceMemory {
    int id;
    unsigned char x;
    unsigned char y;
    unsigned char gatherAttempts;
    unsigned char _pad_0;
    int gatherValue;
    unsigned char valid;
    unsigned char gone;
    unsigned char dropDistance;
    unsigned char resourceType;
    int dropsiteID;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int add(T valueToAdd) {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == valueToAdd)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int newSize = this->numberValue + 1;
            T* newValue = (T*)operator new(newSize * sizeof(T));
            if (newValue != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= newSize)
                        break;
                    newValue[j] = this->value[j];
                }
                operator delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }

        this->value[this->numberValue] = valueToAdd;
        this->numberValue = this->numberValue + 1;
        return 1;
    }
};

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    MainDecision* md; // +0x100
    int mapXSizeValue; // +0x104
    int mapYSizeValue; // +0x108
    int lastUpdateRowValue; // +0x10C
    int maxImportantObjectMemory; // +0x110
    ObjectMemory* importantObjectMemory; // +0x114
    ManagedArray<int> importantObjects; // +0x118
    ManagedArray<int> importantUnits; // +0x128
    ManagedArray<int> importantMiscs; // +0x138
    ManagedArray<int> itemsToDefend; // +0x148
    char gap_158[0xB0];
    char learnFileName[0x100]; // +0x208
    char gap_308[0x1C8];
    ResourceMemory* resources[4]; // +0x4D0
    int numberResources[4]; // +0x4E0
    int maxResources[4]; // +0x4F0

    int storeAttackMemory(
        unsigned char, unsigned char, unsigned char, unsigned char,
        unsigned char, unsigned char, unsigned char, short,
        unsigned char, unsigned long, int);
    ObjectMemory* addObjectMemory(
        int, short, short, unsigned char, unsigned char, unsigned char,
        unsigned char, short, int, unsigned char, float, float, float, void*);

    void loadLearnInfo(char* suffix);
};

void TribeInformationAIModule::loadLearnInfo(char* suffix)
{
    int numMemoriesToLoad;
    int numToLoad;
    int tempInt;
    int local_2c;
    ObjectMemory temp;
    float local_4;
    char* learnFileName = this->learnFileName;
    int civ = (int)this->md->player->id;

    if (suffix == 0) {
        sprintf(learnFileName, (char*)0x5879A4, civ);
    } else {
        char* playerName = rge_base_game->info->get_current_player_name();
        sprintf(learnFileName, (char*)0x587994, suffix, playerName, civ);
    }

    int file = rge_open(learnFileName, 0x8000);
    if (file != -1) {
        rge_read(file, &this->mapXSizeValue, 4);
        rge_read(file, &this->mapYSizeValue, 4);
        rge_read(file, &numToLoad, 4);

        int i = 0;
        if (numToLoad > 0) {
            do {
                rge_read(file, &temp.type, 0x18);
                this->storeAttackMemory(
                    temp.x,
                    temp.y,
                    temp.z,
                    temp.owner,
                    *((unsigned char*)&temp.hitPoints),
                    *((unsigned char*)&temp.hitPoints + 1),
                    temp.kills,
                    *(short*)&temp.attackAttempts,
                    *((unsigned char*)&temp.attackAttempts + 2),
                    *(unsigned long*)&temp.range,
                    *(int*)&temp.damageCapability);
                i++;
            } while (i < numToLoad);
        }

        rge_read(file, &numToLoad, 4);
        suffix = 0;
        if (numToLoad > 0) {
            do {
                rge_read(file, &temp.type, 0x24);
                this->addObjectMemory(
                    temp.id,
                    *(short*)&temp.x,
                    *(short*)&temp.z,
                    *((unsigned char*)&temp.hitPoints),
                    *((unsigned char*)&temp.hitPoints + 1),
                    temp.kills,
                    *((unsigned char*)&temp.kills + 1),
                    *(short*)&temp.attackAttempts,
                    *(int*)&temp.range,
                    *((unsigned char*)&temp.damageCapability),
                    temp.rateOfFire,
                    temp.range,
                    local_4,
                    0);
                this->importantUnits.add(temp.id);
                suffix = suffix + 1;
            } while ((int)suffix < numToLoad);
        }

        int* maxResources = this->maxResources;
        int resourceCount = 4;
        do {
            rge_read(file, maxResources, 4);
            rge_read(file, maxResources - 4, 4);
            ResourceMemory* resourceMemory =
                (ResourceMemory*)operator new((*maxResources) * sizeof(ResourceMemory));
            *(ResourceMemory**)(maxResources - 8) = resourceMemory;
            rge_read(file, resourceMemory, (*maxResources) * sizeof(ResourceMemory));
            maxResources++;
            resourceCount--;
        } while (resourceCount != 0);

        rge_read(file, &tempInt, 4);
        suffix = 0;
        if (tempInt > 0) {
            do {
                rge_read(file, &local_2c, 4);
                this->importantMiscs.add(local_2c);
                suffix = suffix + 1;
            } while ((int)suffix < tempInt);
        }

        rge_read(file, &tempInt, 4);
        suffix = 0;
        if (tempInt > 0) {
            do {
                rge_read(file, &local_2c, 4);
                this->itemsToDefend.add(local_2c);
                suffix = suffix + 1;
            } while ((int)suffix < tempInt);
        }

        rge_close(file);
    }
}
