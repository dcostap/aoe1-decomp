// 004DA680 TribeInformationAIModule::addObjectMemory
// Attempt log:
// try 1: direct reconstruction from packet; local packed ObjectMemory and natural growth/update paths: default /O2 too small (.text 864 vs 1316).
// try 2: expanded copy loop from struct assignment to field-by-field COPY_ONE: default /O2 still too small (.text 1040 vs 1316).
// try 3: tested /GX: no effect, rolled back.
// try 4: tried index-based COPY_ONE to encourage repeated reloads: no size/codegen change.
// try 5: tested /Od only for diagnosis: exact-size comparable but broad debug-basin mismatch (93.6170% positional, first mismatch prologue), rolled back.
// left in scratch: behavior skeleton covers duplicate update, empty-slot reuse, growth/fill, history side effect, and return paths, but not accepted_drift quality. Need exact original source/layout/codegen basin for ObjectMemory copy/store (likely real struct declarations and source-level field order) before further matching.

typedef unsigned char uchar;

struct ObjectMemory {
    int id;
    short type;
    short group;
    uchar x;
    uchar y;
    uchar z;
    uchar owner;
    short hitPoints;
    char pad0e[2];
    int attackAttempts;
    uchar kills;
    char pad15[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

class RGE_Player { public: char gap[0x4a]; short id; int computerPlayer(); };
class RGE_Static_Object { public: char gap[0x0c]; RGE_Player* owner; };
class RGE_Base_Game { public: int singlePlayerGame(); };
extern RGE_Base_Game* rge_base_game;
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

class TribeTacticalAIModule { public: int strategicNumber(int n); };
struct PlayerHolder { char gap[0x3c]; void* player; };
class MainDecisionAIModule { public: char gap0[0xf0]; PlayerHolder* playerHolder; char gapf4[0x11378]; TribeTacticalAIModule tacticalAI; };

class TribeInformationAIModule {
public:
    char gap0[0x100];
    MainDecisionAIModule* md;
    char gap104[0x8];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    char gap118[0xfe4c];
    int unitHistory[256];
    int convertUnitToIntType(RGE_Static_Object* obj);
    ObjectMemory* addObjectMemory(int id, short type, short group, uchar x, uchar y, uchar z, uchar owner, short hp, int attempts, uchar kills, float dmg, float rof, float range, RGE_Static_Object* obj);
};

#define STORE(ARR, IDX) do { \
    (ARR)[(IDX)].id = id; \
    (ARR)[(IDX)].type = type; \
    (ARR)[(IDX)].group = group; \
    (ARR)[(IDX)].x = x; \
    (ARR)[(IDX)].y = y; \
    (ARR)[(IDX)].z = z; \
    (ARR)[(IDX)].owner = owner; \
    (ARR)[(IDX)].hitPoints = hp; \
    (ARR)[(IDX)].attackAttempts = attempts; \
    (ARR)[(IDX)].kills = kills; \
    (ARR)[(IDX)].damageCapability = dmg; \
    (ARR)[(IDX)].rateOfFire = rof; \
    (ARR)[(IDX)].range = range; \
} while (0)

#define COPY_ONE(DSTARR, SRCARR, IDX) do { \
    (DSTARR)[(IDX)].id = (SRCARR)[(IDX)].id; \
    (DSTARR)[(IDX)].type = (SRCARR)[(IDX)].type; \
    (DSTARR)[(IDX)].group = (SRCARR)[(IDX)].group; \
    (DSTARR)[(IDX)].x = (SRCARR)[(IDX)].x; \
    (DSTARR)[(IDX)].y = (SRCARR)[(IDX)].y; \
    (DSTARR)[(IDX)].z = (SRCARR)[(IDX)].z; \
    (DSTARR)[(IDX)].owner = (SRCARR)[(IDX)].owner; \
    (DSTARR)[(IDX)].hitPoints = (SRCARR)[(IDX)].hitPoints; \
    (DSTARR)[(IDX)].attackAttempts = (SRCARR)[(IDX)].attackAttempts; \
    (DSTARR)[(IDX)].kills = (SRCARR)[(IDX)].kills; \
    (DSTARR)[(IDX)].damageCapability = (SRCARR)[(IDX)].damageCapability; \
    (DSTARR)[(IDX)].rateOfFire = (SRCARR)[(IDX)].rateOfFire; \
    (DSTARR)[(IDX)].range = (SRCARR)[(IDX)].range; \
} while (0)

ObjectMemory* TribeInformationAIModule::addObjectMemory(int id, short type, short group, uchar x, uchar y, uchar z, uchar owner, short hp, int attempts, uchar kills, float dmg, float rof, float range, RGE_Static_Object* obj)
{
    int empty = -1;
    int i = 0;
    if (this->maxImportantObjectMemory > 0) {
        ObjectMemory* p = this->importantObjectMemory;
        do {
            if (p->id == id) {
                STORE(this->importantObjectMemory, i);
                return this->importantObjectMemory + i;
            }
            if (p->id == -1 && empty == -1) empty = i;
            ++i;
            ++p;
        } while (i < this->maxImportantObjectMemory);
    }

    if (obj) {
        MainDecisionAIModule* md = this->md;
        PlayerHolder* ph = md->playerHolder;
        unsigned int playerNum = *(unsigned char*)((char*)ph->player + 0x11d);
        if (md->tacticalAI.strategicNumber(0xc9) == 1) {
            short myNum = *(short*)((char*)md->playerHolder + 0x4a);
            if (playerNum == (unsigned short)myNum || playerNum == 0xff) {
                RGE_Player* op = obj->owner;
                if (op->id > 0 && op->computerPlayer() == 0 && rge_base_game->singlePlayerGame() == 1) {
                    int t = this->convertUnitToIntType(obj);
                    if (t != -1) ++this->unitHistory[t];
                }
            }
        }
    }

    if (empty == -1) {
        ObjectMemory* mem = (ObjectMemory*)operator new(this->maxImportantObjectMemory * 0x48);
        if (!mem) return 0;
        int oldCount = this->maxImportantObjectMemory;
        int j = 0;
        if (oldCount > 0) {
            do {
                COPY_ONE(mem, this->importantObjectMemory, j);
                ++j;
            } while (j < oldCount);
        }
        if (j < oldCount * 2) {
            do {
                mem[j].id = -1;
                mem[j].type = -1;
                mem[j].group = -1;
                mem[j].x = 0;
                mem[j].y = 0;
                mem[j].z = 0;
                mem[j].owner = 0;
                mem[j].hitPoints = 0;
                mem[j].attackAttempts = 0;
                mem[j].kills = 0;
                mem[j].damageCapability = 0.0f;
                mem[j].rateOfFire = 0.0f;
                mem[j].range = 0.0f;
                ++j;
            } while (j < oldCount * 2);
        }
        operator delete(this->importantObjectMemory);
        this->importantObjectMemory = mem;
        STORE(this->importantObjectMemory, oldCount);
        this->maxImportantObjectMemory = oldCount * 2;
        return this->importantObjectMemory + oldCount;
    }

    STORE(this->importantObjectMemory, empty);
    return this->importantObjectMemory + empty;
}
