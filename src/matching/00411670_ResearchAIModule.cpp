// 00411670 ResearchAIModule::ResearchAIModule(void*, int)
// MATCH notes: exact match requires /GX, initializer-list zeroing for mainDecisionAI/numTechs
// around the TechnologyItem member ctor, and strcpy(dest, "") so VC5 emits the inline rep scan/copy.

#include "../../include/airchmod_context.h"

extern "C" char* __cdecl strcpy(char*, const char*);

ResearchAIModule::ResearchAIModule(void* ptr, int arg)
    : AIModule((char*)"Research AI", 0x3ee, arg, ptr),
      md(0),
      techTree(),
      techTreeLengthValue(0)
{
    TechnologyItem* head = &this->techTree;
    this->techTree.next = head;
    this->techTree.prev = head;
    strcpy(this->techTreeNameValue, "");
}
