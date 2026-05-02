// RGE_Flic_Player::delta_fli
// VA: 0044A2A0 (232 bytes)
// Decodes delta-FLIC video frames

struct RGE_Flic_Player {
    char gap_00[0x90];
    int flic_buffer_delta;   // +0x90
    char gap_94[0x04];
    unsigned char* frame_buf; // +0x98
    char gap_9C[0x04];
    unsigned char* chunk_ptr; // +0xA0

    void delta_fli();
};

void RGE_Flic_Player::delta_fli() {
    unsigned char* chunk = chunk_ptr;
    int chunk_count = *(int*)chunk;
    chunk += 8;
    
    if (chunk_count <= 0) return;
    
    do {
        int line_count = (signed char)*chunk;
        chunk++;
        int line_offset = 0;
        
        if (line_count > 0) {
            int y = line_count;
            while (y != 0) {
                signed char opcode = (signed char)*chunk;
                line_offset += opcode;
                chunk++;
                
                if (opcode < 0) {
                    // Fill run: negative opcode = count, next byte = color
                    int count = -opcode;
                    unsigned char color = *chunk;
                    chunk++;
                    unsigned int fill_val = color | (color << 8) | (color << 16) | (color << 24);
                    unsigned char* dest = frame_buf + line_offset;
                    int ecx = count >> 2;
                    int rem = count & 3;
                    // rep stosd
                    while (ecx--) { *(unsigned int*)dest = fill_val; dest += 4; }
                    // rep stosb
                    while (rem--) { *dest = (unsigned char)fill_val; dest++; }
                } else {
                    // Copy run: positive opcode = count, copy that many bytes from chunk
                    int count = opcode;
                    unsigned char* dest = frame_buf + line_offset;
                    // rep movsd
                    int ecx = count >> 2;
                    int rem = count & 3;
                    while (ecx--) { *(unsigned int*)dest = *(unsigned int*)chunk; dest += 4; chunk += 4; }
                    while (rem--) { *dest = *chunk; dest++; chunk++; }
                }
                
                y--;
            }
        }
        
        flic_buffer_delta += frame_buf - (unsigned char*)0 + flic_buffer_delta; // approximate
        chunk_count--;
    } while (chunk_count != 0);
}
