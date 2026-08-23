// attempt 1: sibling-style sentinel/null list walk with the three predicate helpers and a local count
// exact match landed with the natural while-loop shape and the sibling-style list sentinel layout

#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
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

    int numberUnbuiltItemsOfType(int param_1, int param_2);
};
#endif

int BuildAIModule::numberUnbuiltItemsOfType(int param_1, int param_2) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    int count = 0;

    while (item != sentinel && item != 0) {
        if (item->typeID() == param_1 && item->buildCategory() == param_2 && item->built() == 0) {
            ++count;
        }
        item = item->next;
    }

    return count;
}
