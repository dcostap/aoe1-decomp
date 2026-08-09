// RGE_Flic_Player::byte_run
// VA: 0044A3E0 (217 bytes)
// Decodes byte-run compressed FLIC frames
// Attempt log:
// - Baseline CRT fill/copy candidate was structurally close but used the wrong
//   row ownership/lifetime and saved EBX as this (195 differing bytes).
// - Restored canonical fields, loaded chunk before the guard, reset the row
//   offset per row, shared the run local, and put the fill arm first.  This
//   recovered the original branch topology and a 0xC frame, but not the final
//   register basin (163 differing bytes, rebuilt body 208 vs 217 bytes).
// - Manual-loop, destination-local, alias, and declaration-scope variants were
//   tested and either regressed or produced duplicate codegen.  Best source is
//   retained here; remaining drift is the original ESI/EBX coloring and
//   line-offset spill/layout around the rep-string paths.
// Fresh exact pass (2026-08-09):
// - Same-TU full-class context, long/int width changes, signed-char opcode,
//   declaration-order, and register-qualified locals were neutral or worse.
// - Byte mutation in the negative arm is binary-supported by the observed
//   `neg al`; direct member access plus that form gives the best current 217-byte
//   reconstruction (160 differing bytes), but the ESI/EBX basin remains open.

#include <string.h>

struct RGE_Flic_Player {
    char gap_00[0x90];
    long drawarea_width;        // +0x90
    long flic_width;            // +0x94
    unsigned char* window_buffer; // +0x98
    char gap_9C[0x04];
    char* chunk;                // +0xA0
    char gap_A4[0x04];
    long y1;                     // +0xA8
    char gap_AC[0x0C];
    long flic_size_y;            // +0xB8

    void byte_run();
};

void RGE_Flic_Player::byte_run() {
    char* chunk = this->chunk;
    int count = this->y1 + this->flic_size_y - 1;
    if (count < 0) return;
    count++;

    chunk++;
    int line_offset;
    unsigned char* dst;

    do {
        line_offset = 0;
        do {
            unsigned char opcode = (unsigned char)*chunk;
            chunk++;
            int copy_count;
            
            if ((signed char)opcode >= 0) {
                copy_count = (signed char)opcode;
                dst = this->window_buffer + line_offset;
                memset(dst, *chunk, copy_count);
                chunk++;
            } else {
                opcode = (unsigned char)-opcode;
                copy_count = (signed char)opcode;
                dst = this->window_buffer + line_offset;
                memcpy(dst, chunk, copy_count);
                chunk += copy_count;
            }
            line_offset += copy_count;
        } while (line_offset < this->flic_width);
        
        this->window_buffer += this->drawarea_width;
        count--;
    } while (count != 0);
}
