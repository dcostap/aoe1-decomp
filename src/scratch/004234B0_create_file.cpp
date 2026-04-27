// 004234B0 RGE_Campaign::create_file
// Source: campaign.cpp lines 104-169
// Size: 466 bytes, no EH, sub esp, 0x13C stack frame
//
// Attempt log:
// Probe 1: structural — large stack frame (0x13C bytes of locals), complex I/O loop
//   Same register allocation basin as other campaign.cpp functions

#include "..\..\include\game_globals.h"

class RGE_Campaign {
public:
    int version;                // +0x00
    char name[256];             // +0x04
    int scenario_num;           // +0x104
    void* scenario_offsets;     // +0x108
    char filename[256];         // +0x10C

    void create_file();
};

class RGE_Prog_Info {
public:
    char _gap_00[0xC17];
    char scenario_dir[256];     // +0xC17
    char campaign_dir[256];     // +0xD1C
};

extern int __cdecl sprintf(char*, const char*, ...);
extern int __cdecl _open(const char*, int);
extern int __cdecl _read(int, void*, int);
extern int __cdecl _write(int, void*, int);
extern int __cdecl _close(int);
extern int __cdecl _lseek(int, int, int);
extern int __cdecl _tell(int);
extern void* __cdecl calloc(int, int);
extern void __cdecl free(void*);

// Not matchable — 466-byte function with large stack frame, complex loop,
// register allocation basin matching other campaign.cpp functions.
// Opens campaign file, writes header + scenario_offsets, then loops through
// each scenario file to concatenate them into the campaign file.
void RGE_Campaign::create_file()
{
    // Left in scratch: register allocation codegen basin
}
