// flics.cpp:349-361, 104 bytes
// RGE_Flic_Player::literal() - row-by-row blit using memcpy
// attempt 1: for-loop -> 92.3%, wrong member offsets (0xB4 vs 0xB8, 0x9C vs 0xA0)
// attempt 2: do-while with counter init before guard, reload flic_size_y each iteration
#include <string.h>

#ifndef FLICS_SHARED_CONTEXT
class RGE_Flic_Player {
public:
    char gap_00[0x90];
    int drawarea_width;     // +0x90
    int flic_width;         // +0x94
    unsigned char* window_buffer; // +0x98
    char gap_9C[4];
    unsigned char* chunk;   // +0xA0
    char gap_A4[0x10];
    int flic_size_x;        // +0xB4
    int flic_size_y;        // +0xB8

    void literal();
};
#endif

void RGE_Flic_Player::literal() {
    int i = 0;
    if (this->flic_size_y <= 0) {
        return;
    }
    do {
        memcpy(this->window_buffer, this->chunk, this->flic_size_x);
        this->window_buffer += this->drawarea_width;
        this->chunk += this->flic_width;
        i++;
    } while (i < this->flic_size_y);
}
