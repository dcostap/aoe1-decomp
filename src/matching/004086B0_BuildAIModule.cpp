// VA: 004086B0 BuildAIModule::BuildAIModule
// PDB source: aibldmod.cpp
// Attempt log:
// - Context gate proved aibldmod.cpp lines 34-42, BuildAIModule ownership,
//   address sequence 004086B0-004087E8, and anchors 0040E2D0/00408190.
// - Grouped baseline differed by 247 bytes and escaped the boundary twice.
// - Exact transition: the canonical member-initializer list owns BuildItem,
//   scalar zeroing, ManagedArray zeroing, and the derived vptr store.
// - Walkback: removing only the shared explicit BuildItem call left 225
//   differing bytes; removing the shared duplicate stores and manual vptr
//   reached grouped MATCH.
// BINARY NOTE: grouped output matches 313 bytes with both direct calls,
// boundaries, and relocations exact. The same canonical declarations compile
// the standalone source and the authentic grouped wrapper.

#ifndef AIBLDMOD_SHARED_CONTEXT
#define AIBLDMOD_STANDALONE_CONTEXT 1
#define AIBLDMOD_SHARED_CONTEXT 1
#endif
#include "../../include/aibldmod_context.h"
#ifdef AIBLDMOD_STANDALONE_CONTEXT
#undef AIBLDMOD_SHARED_CONTEXT
#undef AIBLDMOD_STANDALONE_CONTEXT
#endif

BuildAIModule::BuildAIModule(void* param_1, int param_2)
    : AIModule("Build AI", 0x3E9, param_2, param_1),
      buildList(), buildListLengthValue(0), numberItemsIntoBuildListValue(0)
{
    this->buildList.next = &this->buildList;
    this->buildList.prev = &this->buildList;
    strcpy(this->buildListNameValue, "");
    strcpy(this->lastBuildItemRequestedValue, "None");
    strcpy(this->currentBuildItemRequestedValue, "None");
    strcpy(this->nextBuildItemRequestedValue, "None");
}
