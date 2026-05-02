// RGE_Flic_Player::byte_run
// VA: 0044A3E0 (217 bytes)
// Decodes byte-run compressed FLIC frames

#include <string.h>

struct RGE_Flic_Player {
    char gap_00[0x90];
    int flic_buffer_delta;      // +0x90
    int flic_width;             // +0x94
    unsigned char* frame_buf;   // +0x98
    char gap_9C[0x04];
    unsigned char* chunk_ptr;   // +0xA0
    char gap_A4[0x04];
    int x1;                      // +0xA8
    char gap_AC[0x0C];
    int y1;                      // +0xB8

    void byte_run();
};

void RGE_Flic_Player::byte_run() {
    int count = x1 + y1 - 1;
    if (count < 0) return;
    count++;
    
    unsigned char* chunk = chunk_ptr + 1;
    int line_offset = 0;
    
    do {
        do {
            signed char opcode = (signed char)*chunk;
            chunk++;
            
            if (opcode >= 0) {
                // Fill run
                int copy_count = opcode;
                unsigned char fill_val = *chunk;
                chunk++;
                memset(frame_buf + line_offset, fill_val, copy_count);
                line_offset += copy_count;
            } else {
                // Copy run
                int copy_count = -opcode;
                memcpy(frame_buf + line_offset, chunk, copy_count);
                chunk += copy_count;
                line_offset += copy_count;
            }
        } while (line_offset < flic_width);
        
        frame_buf += flic_buffer_delta;
        count--;
    } while (count != 0);
}
