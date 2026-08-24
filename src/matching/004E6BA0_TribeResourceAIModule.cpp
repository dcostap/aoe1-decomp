// 004E6BA0 TribeResourceAIModule::TribeResourceAIModule
// Source: tairesmd.cpp lines 38-40
// Size: 117 bytes, EH-framed
//
// Attempt log:
// Probe 1: fixed AIModule base size (gap_04[0xEC] for sizeof 0xF0), /GX
// Probe 2: init-list for md=0 to change store order vs vtable

#include "../../include/tairesmd_context.h"

void rge_read(int handle, void* buffer, int size);

TribeResourceAIModule::TribeResourceAIModule(int param_1, int param_2)
    : AIModule("ResAI", 0x3EF, param_1, 0)
    , md(0)
{
    rge_read(param_2, &this->numberResourcesValue, 4);
}
