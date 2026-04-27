// attempt 1: direct scenario table walk with calloc(count, 4), out-param store, and per-entry getstring copies
// attempt 2: switch to the decompiler-style iVar shape and direct *param_1 access; the first exact-match clue was a 4-byte code-size overshoot, so this is a small basin probe
// attempt 3 rolled back: a local source pointer pulled the whole function into the wrong register basin, so keep the decompiler-style shape and only track the remaining LEA-byte drift
#include <stdlib.h>

class RGE_Scenario_Offset {
public:
    char gap_00[8];
    char name[255];
};

class RGE_Campaign_Header {
public:
    long version;
    char name[255];
    unsigned char _pad_0[1];
    long scenario_num;
};

class RGE_Campaign {
public:
    RGE_Campaign_Header campaign_header;
    RGE_Scenario_Offset* scenario_offsets;

    long scenario_info(char*** param_1);
};

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl getstring(char** param_1, char* param_2);

long RGE_Campaign::scenario_info(char*** param_1) {
    char** ppcVar1;
    int iVar2;
    int iVar3;

    ppcVar1 = (char**)calloc((unsigned int)this->campaign_header.scenario_num, 4);
    iVar3 = 0;
    *param_1 = ppcVar1;
    if (0 < this->campaign_header.scenario_num) {
        iVar2 = 0;
        do {
            getstring(*param_1 + iVar3, this->scenario_offsets->name + iVar2);
            iVar3 = iVar3 + 1;
            iVar2 = iVar2 + 0x208;
        } while (iVar3 < this->campaign_header.scenario_num);
    }
    return this->campaign_header.scenario_num;
}
