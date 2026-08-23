#include <string.h>

#ifndef FLICS_SHARED_CONTEXT
class RGE_Flic_Player {
public:
    unsigned char* flic_buffer;
    int flic_handle;
    char flichead[0x84];
    void* drawarea;
    long drawarea_width;
    long flic_width;
    unsigned char* window_buffer;
    unsigned char* save_buffer;
    char* chunk;
    long x1;
    long y1;
    long x2;
    long y2;
    long flic_size_x;
    long flic_size_y;

    void black();
};
#endif

void RGE_Flic_Player::black() {
    long i;
    unsigned char* p;

    i = 0;
    if (this->flic_size_y > 0) {
        do {
            p = this->window_buffer;
            memset(p, 0, this->flic_size_x);
            this->window_buffer = this->window_buffer + this->drawarea_width;
            i = i + 1;
        } while (i < this->flic_size_y);
    }
}
