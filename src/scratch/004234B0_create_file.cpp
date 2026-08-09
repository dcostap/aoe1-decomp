// 004234B0 RGE_Campaign::create_file
// Source: campaign.cpp lines 104-169
// Size: 466 bytes, no EH, sub esp, 0x13C stack frame
//
// Attempt log:
// - Baseline reconstructs the period file pipeline with the canonical campaign and
//   scenario-entry records; local stack objects mirror the proven 300-byte tempname,
//   output offset, and entry-index ownership.
// - Reloading campaign_header.scenario_num directly (rather than keeping a count local)
//   recovered the original EBP/ESI/EDI prologue, all 16 ordered CRT calls, and 466-byte
//   effective output; the same-TU C-linkage period file API surface is aligned.
// - The best natural packed-entry cursor is 137 positional bytes away: remaining drift
//   is the 4-byte local-frame delta, two SIB base/index choices, and late offset/size
//   store scheduling. Direct typed/raw field variants and a focused local-shape lab did
//   not improve it; a 304-byte tempname diagnostic fixed the frame but changed the
//   binary-proven open-failure compare, so it was rolled back and no variant was promoted.
// Left in scratch: behavior and canonical layout are reconstructed; exact matching is
// paused at the documented stack/local and late packed-record codegen gap.
// Main-agent audit replaced raw singleton/frame/record plumbing with canonical
// base-game ownership, a typed work aggregate, and indexed scenario entries.
// Session sa-9f5987e6-campaign-file: after the clean-source reset, a separate named
// output_offset/current_offset plus direct typed scenario_offsets[current_offset] rereads
// restored the original 0x13C frame and 466-byte size.  The binary-supported tempname
// stack overlap is expressed by using the named tempname base (not tempname+4), and the
// inner open guard is spelled > -1 to preserve cmp -1/jle.  This natural candidate is
// 35 bytes away with all 16 calls, frame, size, and CFG aligned.  The remaining localized
// store-order drift is after entry.offset: the original reloads scenario_offsets, adds
// output_offset, stores entry.size, then writes back output_offset; VC5 currently adds
// and spills output_offset before the second member reload/store.  Keep this source in
// scratch; next lead is a natural statement/lifetime form for that proven order, not raw
// record cursors or register-forcing scaffolding.

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
    char _gap_00[0xC17];
    char scenario_dir[256];
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
extern "C" int __cdecl __open(const char*, int, ...);
extern "C" int __cdecl write(int, void*, int);
extern "C" int __cdecl lseek(int, int, int);
extern "C" int __cdecl __tell(int);
extern "C" int __cdecl read(int, void*, int);
extern "C" void* __cdecl calloc(int, int);
extern "C" void __cdecl free(void*);
extern "C" int __cdecl close(int);

void RGE_Campaign::create_file()
{
    int fd;
    int output_offset;
    int current_offset;
    char tempname[300];

    fd = __open(this->filename, 0x8301, 0x180);
    if (fd >= 0) {
        write(fd, this, 0x108);
        if (this->campaign_header.scenario_num > 0) {
            write(fd, this->scenario_offsets, this->campaign_header.scenario_num * 0x208);
            current_offset = 0;
            output_offset = this->campaign_header.scenario_num * 0x208 + 0x108;
            if (this->campaign_header.scenario_num > 0) {
                do {
                    sprintf(tempname, "%s%s",
                        rge_base_game->prog_info->scenario_dir,
                        this->scenario_offsets[current_offset].file_name);
                    int scenario_file = __open(tempname, 0x8000);
                    if (scenario_file > -1) {
                        lseek(scenario_file, 0, 2);
                        int size = __tell(scenario_file);
                        void* buffer = calloc(size, 1);
                        lseek(scenario_file, 0, 0);
                        read(scenario_file, buffer, size);
                        write(fd, buffer, size);
                        this->scenario_offsets[current_offset].offset = output_offset;
                        output_offset += size;
                        this->scenario_offsets[current_offset].size = size;
                        free(buffer);
                        close(scenario_file);
                    }
                    ++current_offset;
                } while (current_offset < this->campaign_header.scenario_num);
            }
            lseek(fd, 0x108, 0);
            write(fd, this->scenario_offsets, this->campaign_header.scenario_num * 0x208);
        }
        close(fd);
    }
}
