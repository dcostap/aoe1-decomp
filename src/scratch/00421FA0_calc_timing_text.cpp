// VA: 00421FA0 RGE_Base_Game::calc_timing_text (144 B)
// PDB source: basegame.cpp
// Packet-grounded: divide timing counters by frame_count, sprintf

extern int sprintf(char* buf, const char* fmt, ...);

struct Shim_21FA0 {
    char pad0[0x504];
    int frame_count;           // +0x504
    char pad508[0x52C - 0x508];
    int fps;                   // +0x52C
    char buf[256];             // +0x404 timing text buffer
};

void RGE_Base_Game_calc_timing_text(Shim_21FA0* self)
{
    int divisor;
    int ecx_base;
    
    divisor = self->frame_count;
    if (divisor == 0)
        divisor = 1;
    
    ecx_base = (int)self + 0x404;
    
    sprintf(
        (char*)self + 0x404,
        "fps=%lu, rend=%lu, view=%lu, map=%lu, scr=%lu, draw=%lu, prog=%lu, ui=%lu, sfx=%lu, misc=%lu",
        self->fps / divisor,
        *(int*)(ecx_base + 0x1A8) / divisor,    // +0x5AC timing[2]
        *(int*)(ecx_base + 0x2C8) / divisor,    // +0x6CC timing[6]
        *(int*)(ecx_base + 0x268) / divisor,    // +0x66C timing[7]
        *(int*)(ecx_base + 0x148) / divisor,    // +0x54C timing[3]
        *(int*)(ecx_base + 0x188) / divisor,    // +0x58C timing[1]
        *(int*)(ecx_base + 0x208) / divisor,    // +0x60C timing[10]
        *(int*)(ecx_base + 0x1E8) / divisor,    // +0x5EC timing[14]
        *(int*)(ecx_base + 0x168) / divisor,    // +0x56C timing[4]
        *(int*)(ecx_base + 0x118) / divisor     // +0x51C timing[0]
    );
}
