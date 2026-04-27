// 00423330 RGE_Campaign::RGE_Campaign (5-param ctor)
// Source: campaign.cpp lines 65-90
// Size: 321 bytes, no EH
//
// Attempt log:
// Probe 1: structural — codegen basin (same register allocation issue as other campaign.cpp functions)

#include "..\..\include\game_globals.h"

class RGE_Campaign {
public:
    int version;                // +0x00
    char name[256];             // +0x04
    int scenario_num;           // +0x104
    void* scenario_offsets;     // +0x108
    char filename[256];         // +0x10C

    RGE_Campaign(char* param1, char* param2, long count, char** names, char** filenames);
};

class RGE_Prog_Info {
public:
    char _gap_00[0xD1C];
    char campaign_dir[256];
};

extern int __cdecl sprintf(char*, const char*, ...);
extern void* __cdecl calloc(int, int);
extern int __cdecl strcpy(char*, const char*);

// Not matchable without resolving the register allocation basin (ebp/frame usage).
// Uses sprintf, string copy via rep movsd/rep movsb, loop over scenario_offsets entries.
RGE_Campaign::RGE_Campaign(char* param1, char* param2, long count, char** names, char** filenames)
{
    // Left in scratch: register allocation codegen basin
    // Same pattern as 00423230 ctor — VC5 allocates different callee-save registers
}
