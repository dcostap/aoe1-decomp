// 00423690 RGE_Campaign::open_scenario
// Source: campaign.cpp lines 175-193
// Size: 118 bytes, no EH
//
// Attempt log:
// Probe 1: 112/118 bytes — 6 bytes short, codegen basin (register allocation)
// Probe 2: same

#include "..\..\include\game_globals.h"

class RGE_Campaign {
public:
    int version;                // +0x00
    char name[256];             // +0x04
    int scenario_num;           // +0x104
    void* scenario_offsets;     // +0x108
    char filename[256];         // +0x10C

    int open_scenario(long index);
};

extern int __cdecl _open(const char*, int);
extern int __cdecl _lseek(int, int, int);
extern int __cdecl rge_fake_open(int, int);

int RGE_Campaign::open_scenario(long index)
{
    if (index >= 0 && index < this->scenario_num) {
        int handle = _open(this->filename, 0x8000);
        if (handle >= 0) {
            char* entry = (char*)this->scenario_offsets + index * 0x208;
            _lseek(handle, *(int*)(entry + 4), 0);
            rge_fake_open(handle, *(int*)entry);
            return handle;
        }
    }
    return -1;
}
