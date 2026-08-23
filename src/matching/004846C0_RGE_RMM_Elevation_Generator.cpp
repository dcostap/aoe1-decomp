// first pass: delegate to the random-map module ctor, then copy the 0x3e0-byte elevation block and set the scalar field
// if this misses, the remaining mismatch is likely only the bulk-copy shape versus the original rep movsd basin

#include <string.h>
#include "..\..\include\rmm_elev_context.h"

RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator(RGE_Map* map, RGE_Random_Map_Module* module, RGE_Elevation_Info* info)
    : RGE_Random_Map_Module(map, module, 1) {
    memcpy(&this->info, info, 0x3E0 * sizeof(long));
    this->schedule = 1.5f;
}
