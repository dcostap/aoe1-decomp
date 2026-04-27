// 00423230 RGE_Campaign::RGE_Campaign
// Source: campaign.cpp lines 22-54
// Size: 251 bytes, no EH
//
// Attempt log:
// Probe 1: 42% diff — param load order, edi save in prologue, strcpy call vs inline
// Probe 2: 74% diff — register allocation (ebx vs esi for this), codegen basin
// Probe 3: tried me-> style with local temps, same result
// Left in scratch: register allocation codegen basin (ebx vs esi/edi for this).
//   VC5 chooses different callee-save registers based on source ordering.
//   The original's ebx=this pattern cannot be reproduced without full TU context.

#include "..\..\include\game_globals.h"

class RGE_Campaign {
public:
    int version;                // +0x00
    char name[256];             // +0x04
    int scenario_num;           // +0x104
    void* scenario_offsets;     // +0x108
    char filename[256];         // +0x10C

    RGE_Campaign(char* param1);
};

class RGE_Prog_Info {
public:
    char _gap_00[0xD1C];
    char campaign_dir[256];
};

extern int __cdecl sprintf(char*, const char*, ...);
extern int __cdecl _open(const char*, int);
extern int __cdecl _read(int, void*, int);
extern int __cdecl _close(int);
extern void* __cdecl calloc(int, int);

RGE_Campaign::RGE_Campaign(char* param1)
{
    int rgeBase = *(int*)0x62C574;
    RGE_Prog_Info* progInfo = *(RGE_Prog_Info**)(rgeBase + 0x0C);
    sprintf(this->filename, "%s%s", progInfo->campaign_dir, param1);

    int handle = _open(this->filename, 0x8000);
    if (handle >= 0) {
        _read(handle, this, 0x108);
        if (this->scenario_num > 0) {
            this->scenario_offsets = calloc(this->scenario_num, 0x208);
            _read(handle, this->scenario_offsets, this->scenario_num * 0x208);
            _close(handle);
        } else {
            this->scenario_offsets = 0;
            _close(handle);
        }
        return;
    }

    const char* err = "FILE NOT FOUND";
    char* dst = this->name;
    while (*err) *dst++ = *err++;
    *dst = 0;
    this->scenario_num = 0;
    this->version = 0;
    this->scenario_offsets = 0;
}
