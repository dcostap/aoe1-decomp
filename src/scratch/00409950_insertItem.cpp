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
// BLOCKER: current natural source is 566B versus 542B. Original starts push -1/handler then mov fs and uses EBX=this with a stack home. VC5 emits mov fs first and uses EBP=this. The remaining EH/return topology and register basin are broad.

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

    if (index > this->buildListLengthValue) return 0;
    pos = this->buildList.next;
    i = 0;
    while (pos != &this->buildList && i < index) {
        pos = pos->next;
        i++;
    }
    if (itemType == 6) {
        strncpy(name + 4, s_SetGatherPercentage, 0x3f);
        sx = 3.0f;
        sy = 3.0f;
    } else {
        RGE_Master_Static_Object* master = player->master_objects[objType];
        if (master != 0) {
            strncpy(name + 4, master->name, 0x3f);
            sx = master->radius_x + master->radius_x;
            sy = master->radius_y + master->radius_y;
        } else {
            strncpy(name + 4, s_AddedBuildListItem, 0x3f);
            sx = 3.0f;
            sy = 3.0f;
        }
    }
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
        item->next = pos->next;
        seq++;
        pos->next->prev = item;
        pos->next = item;
        this->buildListLengthValue++;
    }
    return 1;
}
