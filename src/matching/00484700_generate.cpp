// 00484700 RGE_RMM_Elevation_Generator::generate
// PDB: rmm_elev.cpp lines 29-59
// MATCHED (orch-w16): inner tile-elevation write must spell the value as
//   (unsigned char)(base_elevation * 32) with mask & 0x1F. VC5 then emits the
//   original read-first schedule
//     mov cl,[edx+edi+5]; and cl,1Fh; lea esi,[edx+edi+5]; mov dl,[ebx+40h]; shl dl,5; or cl,dl; mov [esi],cl
//   while every `base << 5` spelling (bitfield elevation write, raw (uchar)base << 5,
//   (unsigned char)(base << 5)) makes VC5 schedule the base load first into cl and read
//   the tile byte via the CSE'd address register (2-byte-short inner body, diff 141).
// Attempt log:
// - baseline: natural generator loops over the base map tile rows, copies each
//   elevation-info line by value, then cleans the generated map rectangle.
// - do-while/indexed row loops reached the exact 191-byte boundary and matched
//   the outer CFG; direct row-byte addressing is retained as the canonical map
//   ownership model.
// - moving the second-loop counter before its guard and using a binary-observed
//   narrow volatile line pointer reproduced the stack cursor and all late call
//   block topology; the volatile is local to the proven stack-home cursor.
// - named byte/address temporaries, cursor aggregates, and alternate info
//   pointer types did not recover the remaining inner tile scheduling. The
//   remaining mismatch is the 2-byte-short inner body: original reads/masks the
//   tile byte, then loads/shifts base elevation, while VC5 schedules the base
//   load first for the current natural bitfield/raw-address spellings.
// - variant-lab sweep over write spellings: bitfield write, raw `|` expressions in
//   both operand orders, terrain_type bitfield reads, named byte/pointer temps,
//   volatile RMW, and `(unsigned char)(base << 5)` all stayed in the value-first
//   basin (diff 130-141). Only `* 32` (cast after the 32-bit product) flipped VC5
//   into the read-first basin: EXACT (0.0000%). `& 31` and `& 0x1F` both exact;
//   operand order irrelevant.

#include "..\..\include\rmm_elev_context.h"

unsigned char RGE_RMM_Elevation_Generator::generate() {
    this->clear_stack();

    if (this->info.elevation_num > 0) {
        long row = 0;
        if (row < this->map_height) {
            do {
                long col = 0;
                if (col < this->map_width) {
                    long offset = 0;
                    do {
                        *((unsigned char*)this->map_row_offset[row] + offset + 5) =
                            (*((unsigned char*)this->map_row_offset[row] + offset + 5) & 0x1F) |
                            (unsigned char)(this->info.elevation[0].base_elevation * 32);
                        ++col;
                        offset += 0x18;
                    } while (col < this->map_width);
                }
                ++row;
            } while (row < this->map_height);
        }
    }

    this->generate_modifiers();

    long i = 0;
    if (this->info.elevation_num > 0) {
        RGE_Elevation_Info_Line* volatile line = this->info.elevation;
        do {
            this->base_elevation_generate(*line);
            this->map->clean_elevation(0, 0, this->map_width - 1,
                this->map_height - 1, 8);
            ++i;
            ++line;
        } while (i < this->info.elevation_num);
    }

    return 1;
}
