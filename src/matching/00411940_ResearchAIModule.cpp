// 00411940 ResearchAIModule::~ResearchAIModule
// Source: airchmod.cpp lines 80-83
// Size: 105 bytes, 26 asm lines

// MATCHED: use the natural destructor body only. Let VC5 emit the derived vtable
// restore, member TechnologyItem destructor, and AIModule base destructor. Manual
// vtable stores or explicit member destructor calls force extra EDI/save and/or
// duplicate destructor calls, shifting EH state slots.
// Field offsets fixed: removed explicit `void* vtable_ptr` from AIModule (let
// virtual ~AIModule() add it implicitly), giving AIModule size 0xF0 and techTree
// at +0xF4.

#include "../../include/airchmod_context.h"

ResearchAIModule::~ResearchAIModule() {
    if (this->techTreeLengthValue > 0) {
        this->removeOldTechTree();
    }
}
