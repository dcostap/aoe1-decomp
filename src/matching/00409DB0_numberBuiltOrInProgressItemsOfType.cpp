// target: VA 00409DB0 BuildAIModule::numberBuiltOrInProgressItemsOfType(int,int)
// first pass: walk the intrusive build list and count matching built/in-progress entries

#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
class BuildItem {
public:
    virtual ~BuildItem();
    int typeID_;
    char gap_04[0x64];
    BuildItem* next; // +0x6C
    BuildItem* prev; // +0x70
    int buildCategory_; // +0x74
    int numberValue_; // +0x78
    int priorityValue_; // +0x7C
    int progressValue_; // +0x80
    int built_; // +0x84

    int typeID() const;
    int buildCategory() const;
    int built() const;
    int inProgress() const;
};

class BuildAIModule {
public:
    char gap_00[0xF0];
    BuildItem buildList; // +0xF0

    int numberBuiltOrInProgressItemsOfType(int type_id, int build_category);
};
#endif

int BuildAIModule::numberBuiltOrInProgressItemsOfType(int type_id, int build_category) {
    int count = 0;
    BuildItem* item = this->buildList.next;
    BuildItem* end = &this->buildList;

    while (item != end && item != 0) {
        if (item->typeID() == type_id && item->buildCategory() == build_category && (item->built() == 1 || item->inProgress() == 1)) {
            ++count;
        }
        item = item->next;
    }

    return count;
}
