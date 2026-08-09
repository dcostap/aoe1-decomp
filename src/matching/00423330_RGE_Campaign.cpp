// 00423330 RGE_Campaign::RGE_Campaign (5-param ctor)
// Source: campaign.cpp lines 65-90
// Size: 321 bytes, no EH
//
// Attempt log:
// - Baseline reconstruction uses the canonical packed campaign/header and scenario-entry
//   layout shared with the neighboring campaign.cpp methods.
// - Reversed the two input-array roles after packet evidence showed the fifth parameter
//   supplies entry name and the fourth supplies entry file_name; this aligned all calls,
//   CFG, size, and bytes except two LEA SIB index/base bytes.
// - Delayed the zero-based byte-offset declaration until after the campaign-name copy and
//   placed the positive allocation arm before the zero arm; this reproduced the original
//   staged callee-save/parameter-home topology.
// - Ground-truth 255-byte fields, int/long local-width variants, explicit zero-indexed
//   entry subscripting, short-lived pointer aliases, and a focused four-way address lab
//   did not change the remaining two bytes. Best source remains the natural typed form.
// Left in scratch: exact output is 2 bytes away (only the two paired entry LEAs encode
// [ebx+ecx] instead of the original [ecx+ebx]); behavior, calls, CFG, size, and layout
// are aligned. Further work lead is same-TU declaration/context or a proven source form
// that selects the original SIB base/index ordering, not broad register tuning.
// Main-agent audit replaced raw singleton/version addresses and cross-record
// byte indexing with canonical globals and typed scenario-entry indexing.
// A later same-TU clean reset and validation found the unchanged canonical
// source exact in the current pinned build context: 321/321 bytes with all
// calls and relocations identical. The prior two-byte SIB note is retained as
// historical compiler-context evidence, not a current blocker.

#include <string.h>

class RGE_Scenario_Offset {
public:
    long size;
    long offset;
    char name[255];
    char file_name[255];
    unsigned char _pad_end[2];
};

struct RGE_Campaign_Header {
    long version;
    char name[255];
    unsigned char _pad_103;
    long scenario_num;
};

class RGE_Campaign {
public:
    RGE_Campaign_Header campaign_header;
    RGE_Scenario_Offset* scenario_offsets;
    char filename[255];
    unsigned char _pad_end;

    RGE_Campaign(char* param1, char* param2, long count, char** names, char** filenames);
    void create_file();
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
extern long campaign_version;

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" void* __cdecl calloc(int, int);

RGE_Campaign::RGE_Campaign(char* param1, char* param2, long count, char** names, char** filenames)
{
    sprintf(this->filename, "%s%s", rge_base_game->prog_info->campaign_dir, param1);

    this->campaign_header.version = campaign_version;
    strcpy(this->campaign_header.name, param2);
    this->campaign_header.scenario_num = count;

    if (count > 0) {
        this->scenario_offsets = (RGE_Scenario_Offset*)calloc(count, 0x208);
        for (long i = 0; i < count; ++i) {
            strcpy(this->scenario_offsets[i].name, filenames[i]);
            strcpy(this->scenario_offsets[i].file_name, names[i]);
        }
    } else {
        this->scenario_offsets = 0;
    }

    this->create_file();
}
