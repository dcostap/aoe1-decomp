// 00487010 RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator
// Source: rmm_shal.cpp lines 34-38, size 59 bytes.

#include "..\..\include\rmm_shal_context.h"

RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator(
    RGE_Map* in_map, RGE_Random_Map_Module* parent_module,
    RGE_Shallows_Info* in_info)
    : RGE_Random_Map_Module(in_map, parent_module, 1)
{
    this->schedule = 1.1f;
    this->info = *in_info;
}
