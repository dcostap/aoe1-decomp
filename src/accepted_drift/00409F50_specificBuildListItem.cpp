// VA: 00409F50 specificBuildListItem (69B, aibldmod.cpp)
// PDB: protected BuildAIModule::specificBuildListItem(int) -> BuildItem*
// Recovery: use the canonical aibldmod.cpp BuildAIModule, BuildItem, and
// BaseItem surfaces.  The module wrapper includes this owner after 00409EE0.
// Exact-finish reversion checks kept the member call and this loop shape.
// BINARY NOTE: the original checks the sentinel before it loads the id.  It
// then uses one null-tested list walk and checks the sentinel after advancing.
#define AIBLDMOD_SHARED_CONTEXT 1
#include "../../include/aibldmod_context.h"

BuildItem* BuildAIModule::specificBuildListItem(int uniqueID)
{
    BuildItem* item = this->buildList.next;
    if (item == &this->buildList) return 0;

    int saveID = uniqueID;
    while (item != &this->buildList) {
        if (item == 0) return 0;
        if (item->uniqueID() == saveID) return item;
        item = item->next;
    }
    return 0;
}

#undef AIBLDMOD_SHARED_CONTEXT
