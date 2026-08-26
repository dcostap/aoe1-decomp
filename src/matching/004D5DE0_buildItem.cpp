// VA: 004D5DE0 TribeBuildAIModule::buildItem
// PDB: taibldmd.cpp:1759-1773 (123 bytes, 53 asm lines)
// Default flags. No inline asm/hacks.
// BINARY NOTE: the reduced natural source matches 123/123
// bytes with the correct owner, boundary, relocations, and five direct calls.
// The required change is the combined sentinel/null loop condition. A
// walkback to the prior split checks returned 46 differing bytes. Typed
// BuildItem ownership replaced the raw sentinel expression without codegen
// change.
// Context gate: PROVED PDB module taibldmd.cpp, lines 1759-1773, with this
// owner immediately after unskipBuildList at 004D5D40. The address sequence is
// 004D5DE0-004D5E5A. Exact anchors are the list read at 004D5DE3, sentinel LEA
// at 004D5DEA, and direct calls at 004D5E02-004D5E30. PROVED owner:
// TribeBuildAIModule::buildItem(int, int, int). LIKELY context is the real
// taibldmd.cpp class surface. UNKNOWN: no remaining source-shape blocker.
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
    BuildItem buildList;

    BuildItem* buildItem(int type, int category1, int category2);
};
#endif

BuildItem* TribeBuildAIModule::buildItem(int type, int category1, int category2) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (!item->built() && !item->inProgress() && item->typeID() == type) {
            if (item->buildCategory() == category1 || item->buildCategory() == category2) {
                return item;
            }
        }
        item = item->next;
    }

    return 0;
}
