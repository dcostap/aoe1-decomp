#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
class BuildItem {
public:
    char gap_00[0x6C];
    BuildItem* next;

    int typeID();
    int buildCategory();
};

class BuildAIModule {
public:
    char gap_00[0x15C];
    BuildItem* buildList;

    int numberItemsOfType(int typeID, int buildCategory);
};
#endif

#ifdef AIBLDMOD_SHARED_CONTEXT
int BuildAIModule::numberItemsOfType(int typeID, int buildCategory) {
    BuildItem* cur = this->buildList.next;
    int count = 0;
    BuildItem* sentinel = &this->buildList;
    while (cur != sentinel && cur != 0) {
        if (cur->typeID() == typeID && cur->buildCategory() == buildCategory) {
            count++;
        }
        cur = cur->next;
    }
    return count;
}
#else
int BuildAIModule::numberItemsOfType(int typeID, int buildCategory) {
    BuildItem* cur = buildList;
    int count = 0;
    void* sentinel = (void*)((char*)this + 0xF0);
    while (cur != (BuildItem*)sentinel && cur != 0) {
        if (cur->typeID() == typeID && cur->buildCategory() == buildCategory) {
            count++;
        }
        cur = cur->next;
    }
    return count;
}
#endif
