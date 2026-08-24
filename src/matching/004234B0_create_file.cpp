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
// - Swapping the natural entry.size assignment before output_offset += size made VC5
//   schedule the proven pointer reload/add/store/spill sequence exactly; this is a
//   period-plausible statement order and produced an exact 466-byte match.
// Exact candidate: typed ownership, natural file pipeline, and all 16 ordered calls
// match; no raw cursor or compiler-steering scaffolding remains.
// Main-agent audit replaced raw singleton/frame/record plumbing with canonical
// base-game ownership, a typed work aggregate, and indexed scenario entries.
// Session sa-9f5987e6-campaign-file: after the clean-source reset, a separate named
// output_offset/current_offset plus direct typed scenario_offsets[current_offset] rereads
// restored the original 0x13C frame and 466-byte size.  The binary-supported tempname
// stack overlap is expressed by using the named tempname base (not tempname+4), and the
// inner open guard is spelled > -1 to preserve cmp -1/jle.  This was the 35-byte-away
// clean-source checkpoint before the final natural statement-order probe; its late
// store-order note is retained as historical evidence and superseded by the exact
// candidate above.

#include "../../include/campaign_context.h"

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
                        this->scenario_offsets[current_offset].size = size;
                        output_offset += size;
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
