// Attempt log for 00409950 BuildAIModule::insertItem
// try 1: natural reconstruction from packet/decompiler with /GX; exact size but EH prologue order/register basin differs (compiler emits mov fs before push -1).
// try 2: default flags without /GX too small (496B), so /GX is required.
// try 3: split new expression into operator new + explicit ctor call; too small 512B, rolled back.
// try 4: use nested positive if for index guard to avoid early EH cleanup return; still EH prologue mismatch.
// try 5: add <string.h> include for real strncpy declaration/context; no change.
// try 6: rollback nested guard to direct early return; edit diff better but EH prologue still differs.
// try 7: introduce self local and use it for member accesses to probe EBX=this; no change.
// try 8: /GX+/O1 flag probe; too small 474B, rolled back.
// try 9: /GX+/Oy- flag probe; too small 528B, rolled back.
// try 10: reviewed include/context and constructor surface; old source had a stale exact-size note.
// try 11: restored the donor-proven BuildItem vptr/0xB0 layout and 64-byte name buffer; baseline was 567B.
// try 12: routed both failure paths through one result/exit; VC5 retained duplicate cleanup returns.
// try 13: restored direct natural returns and member access after the shared-exit experiment.
// try 14: used a natural for-loop; bottom jl shape improved and size fell to 566B.
// try 15: modeled BaseItem inheritance so inherited setters use the original BaseItem symbols; bytes stayed unchanged.
// try 16: normal-object branch first increased size to 571B; shape improved but positional diff worsened, so restored the clean candidate.
// try 17: removed the explicit derived destructor declaration; the same-TU constructor donor omits it, so this tests the narrow destructor-type surface without changing layout.
// try 18: kept the typed successor across the insertion stores to model one list-link lifetime and avoid rereading pos->next.
// try 19: moved the successor declaration after item->prev so the source follows the original link-store order.
// result: typed successor reduced code size from 566B to 563B and positional diff from 509B to 502B; source order improved shape, but EH/return CFG remains broad drift.
// retry 2026-08-17:
// try 20: removed the successor local; direct pos->next links worsened the clean baseline, so restored the typed successor.
// try 21: replaced the named master with repeated typed player->master_objects[objType] expressions. This recovered EBX=this, the original member reloads, and 56.29% exact-block coverage; size rose to 572B but positional diff improved to 487B.
// try 22: shared the natural strncpy statement for itemType 6 and the null-master fallback, with a proven jump after the master arm. Positional diff improved to 471B and call order stayed exact; four checker direct-target warnings are offset alignment diagnostics, not new calls.
// try 23: changed the string declarations to the period mutable-char form; VC5 output was unchanged.
// try 24: routed failures through a typed result and common finish label; VC5 output was unchanged. Removed this metric-only scaffolding.
// try 25: final simplified shared-name/direct-master source is 573B versus 542B, 471 positional diff bytes, 16/16 calls aligned, and 56.29% exact-block coverage.
// BLOCKER: exactness remains unresolved. The original starts push -1/handler then mov fs, stores EBX=this, and has one late cleanup epilogue. VC5 emits the EH registration in another order, retains three returns, and places the name buffer four bytes higher. Do not use compiler steering to force these differences.

#include <string.h>
typedef unsigned int uint;
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
void* operator new(uint size);

class RGE_Master_Static_Object { public: char gap_00[8]; char* name; char gap_0c[0x24]; float radius_x; float radius_y; };
class RGE_Player { public: char gap_00[0x24]; RGE_Master_Static_Object** master_objects; };

class AIModule {
public:
    virtual ~AIModule();
    char gap_00[0xec];
};

class BaseItem {
public:
    char gap_00[0x68];
    virtual ~BaseItem();
    void setSkip(int); void setGameID(int); void setX(float); void setY(float); void setZ(float);
};

class BuildItem : public BaseItem {
public:
    BuildItem* next;
    BuildItem* prev;
    char gap_74[0x3c];
    virtual ~BuildItem();
    BuildItem(int type,int obj,int seq,int a,int b,int p5,char* name,float sx,float sy,float f,int x,int y,int z,int w);
    void setBuilt(int); void setInProgress(int); void setBuildAttempts(int);
    void setNumberBuilds(int); void setBuildCap(int); void setSkipCycles(int); void setPermanentSkip(unsigned char);
};

class BuildAIModule : public AIModule {
public:
    BuildItem buildList;
    int buildListLengthValue;
    int insertItem(RGE_Player* player, int objType, int count, int itemType, int p5, int buildCap, int index);
};

static const char s_SetGatherPercentage[] = "SetGatherPercentage";
static const char s_AddedBuildListItem[] = "AddedBuildListItem";

int BuildAIModule::insertItem(RGE_Player* player, int objType, int count, int itemType, int p5, int buildCap, int index)
{
    BuildItem* pos;
    int i;
    int j;
    char name[64];
    float sx;
    float sy;
    const char* text;

    if (index > this->buildListLengthValue) return 0;
    pos = this->buildList.next;
    i = 0;
    while (pos != &this->buildList && i < index) {
        pos = pos->next;
        i++;
    }
    if (itemType == 6) {
        text = s_SetGatherPercentage;
    } else {
        if (player->master_objects[objType] != 0) {
            strncpy(name + 4, player->master_objects[objType]->name, 0x3f);
            sx = player->master_objects[objType]->radius_x +
                 player->master_objects[objType]->radius_x;
            sy = player->master_objects[objType]->radius_y +
                 player->master_objects[objType]->radius_y;
            goto name_done;
        } else {
            text = s_AddedBuildListItem;
        }
    }
    strncpy(name + 4, text, 0x3f);
    sx = 3.0f;
    sy = 3.0f;

name_done:
    int seq = this->buildListLengthValue;
    for (j = 0; j < count; ++j) {
        BuildItem* item = new BuildItem(itemType, objType, seq, 1, 0, p5, name + 4, sx, sy, 1.0f, -1, -1, -1, 0);
        if (item == 0) return 0;
        item->setBuilt(0);
        item->setInProgress(0);
        item->setBuildAttempts(0);
        item->setSkip(0);
        item->setGameID(-1);
        item->setX(-1.0f);
        item->setY(-1.0f);
        item->setZ(-1.0f);
        item->setNumberBuilds(0);
        item->setBuildCap(buildCap);
        item->setSkipCycles(0);
        item->setPermanentSkip(0);
        item->prev = pos;
        BuildItem* next = pos->next;
        item->next = next;
        seq++;
        next->prev = item;
        pos->next = item;
        this->buildListLengthValue++;
    }
    return 1;
}
