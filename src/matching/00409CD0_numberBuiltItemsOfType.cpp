// attempt 1: straightforward list walk matching the sentinel/null checks and three helper predicates
// result: the first mismatch was the BuildItem field layout; restoring the 0x6c/0x74/0x84 offsets landed exact
// attempt 2: keep the loop natural and use the real helper calls for type/category/built

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
    int built_;

    int buildCategory() const;
    int built() const;
};

class BuildAIModule {
public:
    char gap_0[0xF0];
    BuildItem buildList;

    int numberBuiltItemsOfType(int param_1, int param_2);
};

int BuildAIModule::numberBuiltItemsOfType(int param_1, int param_2) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    int count = 0;

    while (item != sentinel && item != 0) {
        if (item->typeID() == param_1 && item->buildCategory() == param_2 && item->built() == 1) {
            ++count;
        }
        item = item->next;
    }

    return count;
}
