// 004DA680 TribeInformationAIModule::addObjectMemory
// Attempt log:
// try 1: direct reconstruction from packet; local packed ObjectMemory and natural growth/update paths: default /O2 too small (.text 864 vs 1316).
// try 2: expanded copy loop from struct assignment to field-by-field COPY_ONE: default /O2 still too small (.text 1040 vs 1316).
// try 3: tested /GX: no effect, rolled back.
// try 4: tried index-based COPY_ONE to encourage repeated reloads: no size/codegen change.
// try 5: tested /Od only for diagnosis: exact-size comparable but broad debug-basin mismatch (93.6170% positional, first mismatch prologue), rolled back.
// left in scratch: behavior skeleton covers duplicate update, empty-slot reuse, growth/fill, history side effect, and return paths, but not accepted_drift quality. Need exact original source/layout/codegen basin for ObjectMemory copy/store (likely real struct declarations and source-level field order) before further matching.
// try 6: replaced the decompiler pointer-holder surface with typed player/world ownership and restored the proven map-field layout; direct member access is the bounded structural probe. Rebuilt size rose to 1221, shape rose to 65.66%, and the positional diff improved by 6 bytes; structural drift remains.
// try 7: moved duplicate update to a tail label; VC5 kept the same block order and codegen.
// try 8: reused the empty-count and scan-index locals through growth; copy/fill islands aligned and the candidate reached 1339 bytes with 75.95% shape.
// try 9: used signed int player-id comparison and an explicit bounded while scan; the candidate reached exact size, 98.20% shape, and 431-byte positional drift.
// try 10: restored the outer guard and bottom-tested scan; this regressed to 1337 bytes, so the best while-scan source is retained.
// left in scratch: all six calls and 19 conditional edges align. Remaining drift starts in prologue EBP/EDI coloring and one duplicate-store block placement; target has no stack frame.
// focused probe: local declaration/initialization order variants and a declaration-order lab kept the same 431-byte drift.
// focused probe: outer-guard, delayed-pointer, indexed-entry, and explicit early-exit scans broke size/CFG parity; rolled back.
// focused probe: register hints, unsigned-short player number, and direct duplicate return did not improve positional output; rolled back.
// left in scratch: exact-size typed while-scan remains the clean source; unresolved drift is limited to register coloring and duplicate-block placement.
// luna-4DA680-r1: guarded cursor scope and direct indexed scan were behavior-backed but broke size/CFG parity; restored.
// luna-4DA680-r1: for-loop spelling, local declaration/lifetime changes, signed player-number, full same-TU type fields, and pointer/old-count reuse all emitted the same 431-byte drift.
// luna-4DA680-r1: 15-probe pass exhausted; clean typed while-scan remains authoritative.
// luna-4DA680-r2: Ghidra's iVar1 reuse for convertUnitToIntType, direct owner access, and one-line initialization matching PDB line 2047 all emitted the same 431-byte drift.
// luna-4DA680-r2: the exact objectMemory donor's direct-member outer do scan, with and without inline duplicate return, rebuilt 1337 bytes and broke CFG; restored.
// luna-4DA680-r3: baseline confirmed the canonical typed while-scan at 431 bytes; declaration-order and split-initializer variants emitted the same bytes.
// luna-4DA680-r3: using the first-empty register as the duplicate store index moved the diff to 286 bytes but broke broad block shape; binary duplicate path uses scan index, restored.
// luna-4DA680-r3: exact objectMemory donor declaration order and pointer-first declarations did not move the prologue coloring; clean source remains authoritative.
// luna-4DA680-r4: localized four-axis scan declaration lab kept size/frame/call gates and grouped all variants at the same 431-byte diff.
// luna-4DA680-r4: reusing the scan pointer for allocation was byte-identical; delaying the base load with outer guard or early goto broke size and CFG.
// luna-4DA680-r5: inspected the original duplicate block; EAX carries scan index i, while EDI is only the first-empty index for normal insertion. The 286-byte STORE(empty) diagnostic was not an original duplicate write and remains discarded.
// sa-53b45eb0 pass: baseline and final validation remain 1316 bytes, six calls,
// no frame, 19 conditional edges, and 431 positional bytes different.
// sa-53b45eb0 pass: tested 20 distinct source hypotheses. Outer positive guards,
// goto and do/while scans, direct owner bounds, declaration and initialization
// order, pointer and count reuse, player-number widths, register hints, const,
// nested predicates, and direct field stores did not improve the clean source.
// sa-53b45eb0 pass: original setup loads maxImportantObjectMemory into EBP,
// sentinel into EDI, and the memory cursor after the count test. Clean source
// loads max into EDI, sentinel into EBP, and hoists the cursor load. This is the
// remaining codegen lead; no supported source axis found the original basin.
// sa-53b45eb0 pass: restored and pinned the clean typed while-scan. Next lead is
// original source scope or translation-unit context, not metric-only steering.
// luna-4DA680-r5: the remaining source-backed discrepancy is saved-register coloring at the scan prologue; no fresh natural axis remains after the eligible declaration lab.
// BLOCKER: The rebuild hoists importantObjectMemory before the maximum-count
// test. The executable reads that member only when the scan can run. For a
// zero or negative count, the rebuild performs an extra pointer read. Fault
// order and concurrent-mutation behavior therefore differ.

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

struct RGE_Game_World { public: char gap[0x11d]; uchar playerNumber; };
class RGE_Player {
public:
    char gap00[0x3c];
    RGE_Game_World* world;
    char gap40[0x0a];
    short id;
    char gap4c[0xd1];
    uchar playerNumber;
    int computerPlayer();
};
class RGE_Static_Object { public: char gap[0x0c]; RGE_Player* owner; };
class RGE_Base_Game { public: int singlePlayerGame(); };
extern RGE_Base_Game* rge_base_game;
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

class TribeTacticalAIModule { public: int strategicNumber(int n); };
class MainDecisionAIModule { public: char gap0[0xf0]; RGE_Player* player; char gapf4[0x11378]; TribeTacticalAIModule tacticalAI; };

class TribeInformationAIModule {
public:
    char gap0[0x100];
    MainDecisionAIModule* md;
    int mapXSize;
    int mapYSize;
    int lastUpdateRow;
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    char gap118[0xfe4c];
    int unitHistory[11];
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
    int maxMemory = this->maxImportantObjectMemory;
    int empty = -1;
    int i = 0;
    ObjectMemory* p = this->importantObjectMemory;
    while (i < maxMemory) {
        if (p->id == id) {
            goto duplicate;
        }
        if (p->id == -1 && empty == -1) empty = i;
        ++i;
        ++p;
    }

    if (obj) {
        unsigned int playerNum = this->md->player->world->playerNumber;
        if (this->md->tacticalAI.strategicNumber(0xc9) == 1) {
            int myNum = this->md->player->id;
            if (playerNum == (unsigned int)myNum || playerNum == 0xff) {
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
        empty = 0;
        if (this->maxImportantObjectMemory > 0) {
            i = 0;
            do {
                COPY_ONE(mem, this->importantObjectMemory, i);
                ++empty;
                ++i;
            } while (empty < this->maxImportantObjectMemory);
        }
        if (empty < this->maxImportantObjectMemory * 2) {
            do {
                mem[empty].id = -1;
                mem[empty].type = -1;
                mem[empty].group = -1;
                mem[empty].x = 0;
                mem[empty].y = 0;
                mem[empty].z = 0;
                mem[empty].owner = 0;
                mem[empty].hitPoints = 0;
                mem[empty].attackAttempts = 0;
                mem[empty].kills = 0;
                mem[empty].damageCapability = 0.0f;
                mem[empty].rateOfFire = 0.0f;
                mem[empty].range = 0.0f;
                ++empty;
            } while (empty < this->maxImportantObjectMemory * 2);
        }
        operator delete(this->importantObjectMemory);
        this->importantObjectMemory = mem;
        STORE(this->importantObjectMemory, this->maxImportantObjectMemory);
        int oldCount = this->maxImportantObjectMemory;
        this->maxImportantObjectMemory = oldCount * 2;
        return this->importantObjectMemory + oldCount;
    }

    STORE(this->importantObjectMemory, empty);
    return this->importantObjectMemory + empty;

duplicate:
    STORE(this->importantObjectMemory, i);
    return this->importantObjectMemory + i;
}
