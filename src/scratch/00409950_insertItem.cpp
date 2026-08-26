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
// retry 2026-08-22:
// try 26: established canonical ownership from exact BuildItem/BuildAIModule donors: RGE_Player and master fields, BaseItem scalar fields, and BuildItem link/scalar fields. The real hidden-vptr class surface emitted the same 573B, 471-diff result.
// try 27: explicit-vtable and nonvirtual fallback variants either shifted BuildItem/list offsets or widened the frame; restored the real polymorphic BaseItem/BuildItem ownership.
// try 28: positive outer guards with a natural result local produced one return but added a 4-byte frame and reduced structural coverage; restored direct failure returns.
// try 29: local declaration order, mutable-period string types, period stdlib allocation declarations, and the string-header declaration all emitted duplicate 573B code.
// CURRENT EVIDENCE: canonical item/list ownership is stable. The remaining blocker is source CFG/EH topology: original has one late cleanup epilogue, while natural VC5 source keeps three returns and the name buffer four bytes higher.
// retry 2026-08-23:
// try 30: direct literal strncpy statements removed the local text pointer, but VC5 emitted 572B and 487 differing bytes; the immediate-push order still differed.
// try 31: one explicit failure label reduced the output to 554B and 468 differing bytes, but VC5 emitted a near jg to the finish instead of the original short jle plus zero/jmp tail. Restored.
// try 32: an uninitialized result local optimized back to the 573B clean output. A success-default result added a 4-byte frame and 495 differing bytes. Restored.
// try 33: placing a valid-body label before the failure assignment reproduced the 554B/468-byte basin, not the original branch layout. Restored.
// try 34: reusing index, sequence, and result values, reusing the index parameter, and lifting item/next locals produced duplicate 572B or 573B code. Restored.
// CURRENT BLOCKER: fresh checks still show 573B versus 542B, 471 differing bytes, 16/16 ordered calls, and 56.29% exact-block coverage. The original has one shared late cleanup tail; these natural CFG variants do not recover it. Do not retain compiler-steering or opaque context forms.
// Context gate: PDB module aibldmod.cpp lines 513-592 owns this
// BuildAIModule::insertItem body at 00409950-00409B6D. Exact anchors are the
// two strncpy calls, operator new 0054B6F0, BuildItem ctor 00408220, and the
// setter sequence 004085C0..004086A0. Field anchors are +0x15C, +0xF0, and
// +0x1A0. These facts are proved; source order remains a hypothesis.
// try 35: direct string-copy statements selected a 572-byte branch basin in
// standalone code, but worsened positional drift to 487 bytes. Restored.
// try 36: inverted the itemType guard to match the original je polarity and
// source arm order. Test branch layout without changing the text-pointer ABI.
// try 37: moved the non-special strncpy after master selection so its count
// push can hoist before the null test, while keeping two call sites.
// try 37 result: standalone size 580 and diff 532; restored the prior source.
// try 38: combine the inverted guard with direct literal strncpy calls. Test
// whether both target polarity and literal push order can survive together.
// try 39: naming the object type did not change grouped emission; restored
// the clean parameter expression.
// try 40: assigning a typed object index did not alter grouped bytes; the
// alias was removed for the natural parameter expression.
// try 41: spell the typed array access as pointer addition to test VC5's
// operand scheduling while preserving the same indexed ownership.
// try 41 result: grouped output stayed at 8 differing bytes; restored array
// subscript syntax as the natural ownership form.
// try 42: reorder declarations so the address-taken name buffer precedes list
// locals. Test whether VC5 schedules the objType load before player.
// try 42 result: grouped output stayed at 8 differing bytes; restored order.
// try 43: express the special case as an explicit forward label while keeping
// source semantics in Ghidra's itemType==6 order. Test target branch polarity.
// try 43 result: grouped output returned to 428 differing bytes; restored the
// inverted guard, which remains the best natural grouped basin.
// try 44: bind the player's master-object table before indexing it. Test a
// canonical member alias as an alternate load schedule for the final 8 bytes.
// try 44 result: grouped diff rose to 425; restored direct member ownership.
// try 45: use a two-arm switch to test a compiler-natural dispatch that may
// retain the target je special-case polarity and parameter load order.
// try 45 result: grouped output stayed at 8 differing bytes; restored the
// equivalent inverted if form supported by the same emitted CFG.
// try 46: reverse the typed pointer-plus-index operands to test whether VC5
// follows source operand order for the two swapped parameter loads.
// try 46 result: grouped output stayed at 8 differing bytes; restored the
// canonical subscript spelling.
// try 47: mark the read-only object type as a register parameter to test the
// known VC5 register-color axis without changing ABI or field ownership.
// try 47 result: grouped output stayed at 8 differing bytes; removed the
// unsupported register qualifier.
// GROUPED FRONTIER: inverted guard plus direct literal strncpy calls produce
// 542-byte output with 8 differing bytes, 16/16 calls, zero relocation target
// mismatches, and zero boundary escapes. The only mismatch is the order of
// the objType and player parameter loads at the master-object arm.
// The natural text-pointer source produced grouped diff 380. Do not restore it.

#include <string.h>
#include <stdlib.h>

// The module wrapper supplies the canonical class surface.
#ifndef AIBLDMOD_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[4];
    char* name;                         // +0x08
    char gap_0c[0x24];
    float radius_x;                     // +0x30
    float radius_y;                     // +0x34
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1e];
    short master_object_num;            // +0x22
    RGE_Master_Static_Object** master_objects; // +0x24
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_00[0xec];
};

class BaseItem {
public:
    int typeIDValue;
    int gameIDValue;
    int uniqueIDValue;
    char nameValue[64];
    float xValue;
    float yValue;
    float zValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int skipValue;
    virtual ~BaseItem();
    void setSkip(int); void setGameID(int); void setX(float); void setY(float); void setZ(float);
};

class BuildItem : public BaseItem {
public:
    BuildItem* next;
    BuildItem* prev;
    int buildCategoryValue;
    int numberValue;
    int priorityValue;
    int progressValue;
    int builtValue;
    int buildAttemptsValue;
    int buildFromValue;
    int terrainSetValue;
    int terrainAdjacencyValue[2];
    int placeOnElevationValue;
    int numberBuildsValue;
    int buildCapValue;
    int skipCyclesValue;
    unsigned char permanentSkipValue;
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
#endif

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
    // BINARY NOTE: This guard and the direct calls preserve the original
    // special-arm branch and shared strncpy tail in the canonical TU.
    if (itemType != 6) {
        if (player->master_objects[objType] != 0) {
            strncpy(name + 4, player->master_objects[objType]->name, 0x3f);
            sx = player->master_objects[objType]->radius_x +
                 player->master_objects[objType]->radius_x;
            sy = player->master_objects[objType]->radius_y +
                 player->master_objects[objType]->radius_y;
            goto name_done;
        } else {
            strncpy(name + 4, s_AddedBuildListItem, 0x3f);
            sx = 3.0f;
            sy = 3.0f;
        }
    } else {
        strncpy(name + 4, s_SetGatherPercentage, 0x3f);
        sx = 3.0f;
        sy = 3.0f;
    }

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
