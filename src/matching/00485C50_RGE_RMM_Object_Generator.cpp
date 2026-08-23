// attempt 1: straightforward RMM object-generator ctor with base ctor, vptr setup, world store, and info copy/zero path
// blocker watch: the shape should stay a natural ctor; if VC5 drifts, first probes are memcpy vs manual dword copy and whether the 0x632 copy wants a local pointer walk
#include <string.h>
#include "..\..\include\rmm_obj_context.h"

RGE_RMM_Object_Generator::RGE_RMM_Object_Generator(RGE_Map* param_1, RGE_Random_Map_Module* param_2, RGE_Game_World* param_3, RGE_Object_Info* param_4, unsigned char param_5)
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->world = param_3;
    if (param_4 != 0) {
        memcpy(&this->info, param_4, sizeof(RGE_Object_Info));
    } else {
        *(long*)((char*)&this->info + 0x1290) = 0;
        *(long*)((char*)&this->info + 0x18C4) = 0;
    }
    this->schedule = 3.0f;
    this->add_terrain = param_5;
}
