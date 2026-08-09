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
    struct Campaign_File_Work {
        int output_offset;
        char tempname[296];
    } work;
    int fd;
    int index;

    fd = __open(this->filename, 0x8301, 0x180);
    if (fd >= 0) {
        write(fd, this, 0x108);
        if (this->campaign_header.scenario_num > 0) {
            write(fd, this->scenario_offsets, this->campaign_header.scenario_num * 0x208);
            work.output_offset = this->campaign_header.scenario_num * 0x208 + 0x108;
            if (this->campaign_header.scenario_num > 0) {
                index = 0;
                do {
                    RGE_Scenario_Offset& entry = this->scenario_offsets[index];
                    sprintf(work.tempname, "%s%s",
                        rge_base_game->prog_info->scenario_dir,
                        entry.file_name);
                    int scenario_file = __open(work.tempname, 0x8000);
                    if (scenario_file >= 0) {
                        lseek(scenario_file, 0, 2);
                        int size = __tell(scenario_file);
                        void* buffer = calloc(size, 1);
                        lseek(scenario_file, 0, 0);
                        read(scenario_file, buffer, size);
                        write(fd, buffer, size);
                        entry.offset = work.output_offset;
                        work.output_offset += size;
                        entry.size = size;
                        free(buffer);
                        close(scenario_file);
                    }
                    ++index;
                } while (index < this->campaign_header.scenario_num);
            }
            lseek(fd, 0x108, 0);
            write(fd, this->scenario_offsets, this->campaign_header.scenario_num * 0x208);
        }
        close(fd);
    }
}
