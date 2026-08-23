// attempt 1: sibling-style sentinel/null list scan with the param-driven early return cases
// exact match landed with the natural three-arm return shape and the sibling-style list sentinel layout

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

    BuildItem* anyBuildListItem(int param_1, int param_2, int param_3);
};
#endif

BuildItem* BuildAIModule::anyBuildListItem(int param_1, int param_2, int param_3) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (item->typeID() == param_1) {
            if (param_2 == 0) {
                return item;
            }
            if (param_2 == 1) {
                if (item->built() == param_3) {
                    return item;
                }
            }
        }
        item = item->next;
    }

    return 0;
}
