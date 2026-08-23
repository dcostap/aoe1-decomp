#ifndef RMM_SHAL_CONTEXT_H
#define RMM_SHAL_CONTEXT_H

// PDB-backed declarations for the original rmm_shal.cpp owner sequence.

#include "rmm_obj_base_context.h"

struct RGE_Shallows_Info_Line {
    long x;
    long y;
};

struct RGE_Shallows_Info {
    RGE_Shallows_Info_Line shallows[99];
    long shallows_num;
};

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module {
protected:
    RGE_Shallows_Info info;

public:
    RGE_RMM_Shallows_Generator(RGE_Map* in_map,
        RGE_Random_Map_Module* parent_module, RGE_Shallows_Info* in_info);
    virtual uchar generate();
    void make_tribe_connections(long point1, long point2);
};

extern "C" int __cdecl debug_rand(char* file, int line);

#endif
