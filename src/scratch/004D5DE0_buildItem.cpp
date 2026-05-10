// VA: 004D5DE0 TribeBuildAIModule::buildItem
// PDB: taibldmd.cpp:1759-1773
// left in scratch: behavior/calls/layout modeled; remaining drift is the same list-loop branch shape
// seen in 00500320 (`cmp sentinel; je fail; test; jne body`) versus original backedge to loop-top test.
// 2026-05-10 StarryZephyr pass: rechecked baseline, then tried a straightforward do/while sentinel-only loop
// with explicit initial null guard. It reduced positional diff slightly but worsened edit diff and moved the
// found/fail tails earlier with padding; restored baseline because it retains closer edit alignment and original
// null-at-top loop intent.

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

BuildItem* TribeBuildAIModule::buildItem(int type, int category1, int category2) {
    BuildItem* item = this->first;
    BuildItem* sentinel = (BuildItem*)&this->list;
    if (item != sentinel) {
        int cat2 = category2;
        int cat1 = category1;
        goto check_item;
        do {
            if (!item->built() && !item->inProgress() && item->typeID() == type) {
                if (item->buildCategory() == cat1 || item->buildCategory() == cat2) {
                    return item;
                }
            }
            item = item->next;
            if (item == sentinel) {
                return 0;
            }
check_item:
            ;
        } while (item != 0);
    }
    return 0;
}
