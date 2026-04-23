// first pass: walk the build-list from head->next, compare unique IDs, and return the matching item or null
// tried the natural linked-list walk, then a null+sentinel split, then a do/while form; VC5 kept drifting the early branch layout
// current near-miss is in the startup/loop-shape basin around the first null/sentinel tests and uniqueID call placement

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[4];
    int uniqueID_;

    int uniqueID() const;
};

class BuildItem : public BaseItem {
public:
    char gap_0C[0x60];
    BuildItem* next;
};

class BuildAIModule {
public:
    char gap_00[0xF0];
    BuildItem buildList;

    BuildItem* specificBuildListItem(int id);
};

BuildItem* BuildAIModule::specificBuildListItem(int id) {
    BuildItem* item = buildList.next;
    BuildItem* sentinel = &buildList;

    if (item == sentinel) {
        return 0;
    }
    if (item == 0) {
        return 0;
    }

    do {
        if (item->uniqueID() == id) {
            return item;
        }
        item = item->next;
    } while (item != 0 && item != sentinel);

    return 0;
}
