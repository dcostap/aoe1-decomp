// VA: 004D5DE0 TribeBuildAIModule::buildItem
// PDB: taibldmd.cpp:1759-1773 (123 bytes, 53 asm lines)
// Default flags. No inline asm/hacks.
// === ACCEPTED_DRIFT ===
// Localized scheduling/control-flow drift only: category parameter loads are moved
// across a null check, and the bottom sentinel/null loop test is spelled as an
// equivalent two-test tail. Calls, comparisons, return values, stack cleanup, and
// memory effects are identical.

#ifndef TAIBLDMD_SHARED_CONTEXT
class BuildItem {
public:
    char gap_00[0x6C];
    BuildItem* next;

    int built();
    int inProgress();
    int typeID();
    int buildCategory();
};

class TribeBuildAIModule {
public:
    char gap_000[0x0F0];
    char list[0x6C];
    BuildItem* first;

    BuildItem* buildItem(int type, int category1, int category2);
};
#endif

BuildItem* TribeBuildAIModule::buildItem(int type, int category1, int category2) {
#ifdef TAIBLDMD_SHARED_CONTEXT
    BuildItem* item = this->buildList.next;
#else
    BuildItem* item = this->first;
#endif
    BuildItem* sentinel = (BuildItem*)((char*)this + 0xF0);

    if (item == sentinel)
        return 0;

    while (item != 0) {
        if (!item->built() && !item->inProgress() && item->typeID() == type) {
            if (item->buildCategory() == category1 || item->buildCategory() == category2) {
                return item;
            }
        }
        item = item->next;
        if (item == sentinel)
            return 0;
    }

    return 0;
}
