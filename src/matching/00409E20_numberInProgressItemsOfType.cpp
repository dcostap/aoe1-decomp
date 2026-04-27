// attempt 1: sibling-style sentinel/null list walk with the three predicate helpers and a local count
// exact match landed with the natural while-loop shape and the sibling-style list sentinel layout

class BaseItem {
public:
    void* vtable_ptr;
    int typeID_;
    char pad_08[0x6C - 0x8];

    int typeID() const;
};

class BuildItem : public BaseItem {
public:
    BuildItem* next;
    BuildItem* prev;
    int buildCategory_;
    char pad_7C[0x84 - 0x7C];
    int inProgress_;

    int buildCategory() const;
    int inProgress() const;
};

class BuildAIModule {
public:
    char gap_0[0xF0];
    BuildItem buildList;

    int numberInProgressItemsOfType(int param_1, int param_2);
};

int BuildAIModule::numberInProgressItemsOfType(int param_1, int param_2) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    int count = 0;

    while (item != sentinel && item != 0) {
        if (item->typeID() == param_1 && item->buildCategory() == param_2 && item->inProgress() == 1) {
            ++count;
        }
        item = item->next;
    }

    return count;
}
