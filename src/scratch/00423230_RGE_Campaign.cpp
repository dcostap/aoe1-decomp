// 00423230 RGE_Campaign::RGE_Campaign
// Source: campaign.cpp lines 22-54
// Size: 251 bytes, no EH
//
// Attempt log:
// - Baseline flat header + manual fallback copied behavior but used _open/_read/_close and
//   a different global-expression basin (226 differing bytes, 251-byte output).
// - Restored the observed open/read/close helper identities and typed
//   rge_base_game->prog_info ownership; the natural fast path then matched size and all
//   seven ordered calls (86 differing bytes with the manual fallback).
// - Replaced the manual FILE NOT FOUND loop with natural strcpy. VC5 emitted the observed
//   REP string copy and EBX=this/ESI=handle allocation, but saved EDI in the prologue and
//   shifted the cold block (253 bytes, 204 differing bytes).
// - Nested RGE_Campaign_Header, C-linkage helper declarations, six fallback spelling
//   variants, and the binary-proven 0x580498 literal did not change that emitted basin.
// - Restored the generated 255-byte field widths and explicit tail padding for the
//   canonical 0x20C campaign layout; VC5 emitted the same 253-byte basin.
// Left in scratch: the remaining drift is the branch-local EDI save/cold-block layout and
//   its source-line-sensitive scheduling; helper calls, field ownership, and behavior are
//   aligned, but exact matching is unresolved.
// Main-agent audit replaced the raw game singleton address with canonical
// polymorphic base-game ownership and retained the natural file-load path.
// Session sa-9f5987e6-campaign: clean-source reset restored the canonical records before
// testing new context only.  Ground-truth scenario-entry/base-game surfaces, complete
// campaign member declarations, explicit success/failure else forms, mutable/literal
// strcpy spellings, and period CRT header context all emitted the same 253-byte basin.
// The exact __open spelling changed the call identity and was rolled back.  Final clean
// source remains the natural typed constructor; the unresolved drift is still the
// branch-local EDI save/cold block (204 positional bytes, +2 code bytes).

#include <string.h>

struct RGE_Campaign_Header {
    long version;               // +0x00
    char name[255];             // +0x04
    unsigned char _pad_103;
    long scenario_num;          // +0x104
};

class RGE_Scenario_Offset;

class RGE_Campaign {
public:
    RGE_Campaign_Header campaign_header; // +0x00
    RGE_Scenario_Offset* scenario_offsets; // +0x108
    char filename[255];         // +0x10C
    unsigned char _pad_end;

    RGE_Campaign(char* param1);
};

class RGE_Prog_Info {
public:
    char _gap_00[0xD1C];
    char campaign_dir[256];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char _gap_04[0x08];
    RGE_Prog_Info* prog_info;
};

extern RGE_Base_Game* rge_base_game;

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl open(const char*, int);
extern "C" int __cdecl read(int, void*, int);
extern "C" int __cdecl close(int);
extern "C" void* __cdecl calloc(int, int);

RGE_Campaign::RGE_Campaign(char* param1)
{
    sprintf(this->filename, "%s%s", rge_base_game->prog_info->campaign_dir, param1);

    int handle = open(this->filename, 0x8000);
    if (handle >= 0) {
        read(handle, this, 0x108);
        if (this->campaign_header.scenario_num > 0) {
            this->scenario_offsets = (RGE_Scenario_Offset*)calloc(this->campaign_header.scenario_num, 0x208);
            read(handle, this->scenario_offsets, this->campaign_header.scenario_num * 0x208);
            close(handle);
        } else {
            this->scenario_offsets = 0;
            close(handle);
        }
        return;
    }

    strcpy(this->campaign_header.name, "FILE NOT FOUND");
    this->campaign_header.scenario_num = 0;
    this->campaign_header.version = 0;
    this->scenario_offsets = 0;
}
