// first pass: delegate to the random-map module ctor, set the inherited scale,
// and copy the 0x50e-long land block through the canonical land surface
// if this misses, the remaining mismatch is likely only the bulk-copy shape versus the original rep movsd basin

#include <string.h>
#include "../../include/rmm_land_context.h"

RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(RGE_Map* map, RGE_Random_Map_Module* module, RGE_Land_Info* info)
    : RGE_Random_Map_Module(map, module, 1) {
    this->schedule = 1.0f;
    memcpy(&this->info, info, 0x50E * sizeof(long));
}
