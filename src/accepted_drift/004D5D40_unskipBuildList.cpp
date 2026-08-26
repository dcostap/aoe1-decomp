// 004D5D40 TribeBuildAIModule::unskipBuildList (155B)
// taibldmd.cpp:1721-1753
// STATUS: PAUSED — proposed accepted_drift
// Remaining drift: 15 bytes positional / 6 edit bytes (9.4%)
// Root cause: VC5 generates separated sentinel+null checks at bottom-of-loop
// instead of combined `jne to_null_check` that jumps back to the null check
// at the loop body entry.
// Context gate: PROVED PDB module taibldmd.cpp, lines 1721-1753, with this
// owner between allBuilt at 004D5C20 and buildItem at 004D5DE0. Exact anchors
// are the vslot+0x48 calls at 004D5D4A, first-list read at 004D5D5B, and the
// built/inProgress/typeID/setter calls from 004D5D73 through 004D5DC8.
// PROVED owner: TribeBuildAIModule::unskipBuildList(int, int). LIKELY context
// is the real taibldmd.cpp class surface. UNKNOWN: natural VC5 source that
// recovers the original bottom-loop branch without a forbidden wrapper.
// Attempts: 12+ across all loop forms (for, do-while, while, for(;;), goto-based)
// All register allocation and instruction sequences match except bottom-of-loop structure.
// Default flags
// BINARY NOTE: the PDB and decorated owner symbol are unskipBuildList.  The
// old readyToTrain spelling was a source-owner error and is not retained.

#ifndef TAIBLDMD_SHARED_CONTEXT
class BuildItem {
public:
    char gap_00[0x6C];
    BuildItem* next;    // +0x6C

    int built();
    int inProgress();
    void setBuildAttempts(int);
    void setSkipCycles(int);
    void setPermanentSkip(unsigned char);
    int typeID();
    void setSkip(int);
};

class TribeBuildAIModule {
public:
    // vtable slots 0 through 17 (0x48/4 = 18th function)
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual void d6() {}
    virtual void d7() {}
    virtual void d8() {}
    virtual void d9() {}
    virtual void d10() {}
    virtual void d11() {}
    virtual void d12() {}
    virtual void d13() {}
    virtual void d14() {}
    virtual void d15() {}
    virtual void d16() {}
    virtual void d17() {}
    // vtable[0x48] = 18th function (index 18 * 4 = 0x48)
    virtual int getUnitLimit(int, int);
    char gap_04[0x0EC];
    BuildItem buildList;                // +0xF0; next is at +0x15C

    void unskipBuildList(int limit67, int limit44);
};
#endif

void TribeBuildAIModule::unskipBuildList(int limit67, int limit44)
{
#ifdef TAIBLDMD_SHARED_CONTEXT
    int lim67 = this->numberBuiltOrInProgressItemsOfType(0x67, 0);
    int lim44 = this->numberBuiltOrInProgressItemsOfType(0x44, 0);
#else
    int lim67 = getUnitLimit(0x67, 0);
    int lim44 = getUnitLimit(0x44, 0);
#endif

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    if (item == sentinel) return;
    if (item == 0) return;

    for (;;) {
        if (item == 0) break;
        if (item->built() == 1) goto next;
        if (item->inProgress() == 1) goto next;
        if (lim67 > 0 && item->typeID() == 0x67) goto next;
        if (lim44 > 0 && item->typeID() == 0x44) goto next;

        item->setSkip(0);
        item->setBuildAttempts(0);
        item->setSkipCycles(0);
        item->setPermanentSkip(0);

next:
        item = item->next;
        if (item == sentinel) break;
    }
}
