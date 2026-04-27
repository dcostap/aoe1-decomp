// VA: 0044A2A0 RGE_Flic_Player::delta_fli
// flics.cpp
// 232 bytes
// First-pass skeleton/partial — needs proper implementation

struct RGE_Flic_Player {
    unsigned char* flic_buffer;
    int flic_handle;
    char flichead[0x84];
    void* drawarea;
    int drawarea_width;
    int flic_width;
    int window_buffer;
    int save_buffer;
    void* chunk;
    int x1;
    int y1;
    int x2;
    int y2;
    void delta_fli();
};

void RGE_Flic_Player::delta_fli() {
}
