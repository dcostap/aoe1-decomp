// VA: 00539030 RGE_View::get_tile_bounding_coords(int, int, int&, int&, int&, int&)
// Source: view.cpp lines 4862-4947
// Size: 147 bytes, __thiscall, ret 18h (6 params)
// Status: parked — 3-byte register allocation gap
// 10 probes: struct layout correct, control flow matches, all outputs correct
// Remaining: VC5 assigns `this->map` to edx instead of eax (prologue),
//   tile_type to eax instead of edx (forces recompute of tt*3 at 005390AB,
//   3-byte `lea ecx,[eax+eax*2]` not in original), pushing ret 18h past section boundary.
// Pure register allocation artifact — all 147 bytes of body generated but
// final ret 18h truncated (144 vs 147 bytes in .text section).

struct RGE_View {
    char _gap[0x104];
    void* map;            // +0x104
    int field_108;        // +0x108
    short tile_half_wid;  // +0x10C
    short tile_half_hgt;  // +0x10E
    short elev_hgt;       // +0x110

    void get_tile_bounding_coords(int x, int y, int& out_x1, int& out_y1, int& out_x2, int& out_y2);
};

void RGE_View::get_tile_bounding_coords(int x, int y, int& out_x1, int& out_y1, int& out_x2, int& out_y2) {
    char* row = *(char**)(*(char**)((char*)this->map + 0x8D8C) + y * 4);
    int x3 = x * 3;
    char* tile = row + x3 * 8;

    short sx = *(short*)(tile);
    int tt = *(unsigned char*)(tile + 4);
    out_x1 = sx;

    int tt3 = tt * 3 + 0;
    short tw = *(short*)((char*)this->map + 0x18 + (tt3 + 0) * 2);
    out_x2 = sx + tw - 1;

    short sy = *(short*)(tile + 2);
    out_y1 = sy - this->tile_half_hgt;

    this->tile_half_hgt = 0;
    this->tile_half_wid = 0;
    this->elev_hgt = 0;

    short th = *(short*)((char*)this->map + 0x1A + tt3 * 2);
    out_y2 = out_y1 + th - 1;
}
