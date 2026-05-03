// 004C9230 TRIBE_Building_Object::lay_down_impassable_terrain (t_b_obj.cpp:704-744, 292B)
// Lays down impassable terrain under a building by modifying tile terrain types (values 0, 1, 6).
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt notes:
// - Logic, FPU operations, field offsets, loops, and tile access all match correctly
// - Remaining ~5.1% edit diff (15 bytes) is from the cascaded val check:
//   * Original: `sub edx, 0; je handler; dec; je handler; sub edx, 5; jne skip`
//   * Rebuilt: `je handler; dec; je handler; add edx, -5; test edx, edx; jne skip`
//   * VC5 optimized away the identity (`sub edx, 0`) and flipped `sub edx, 5` to `add edx, -5`
//   * VC5 also inserts `test edx, edx` before `jne` (same quirk as lay_down_passable_terrain)
//   * The 1-byte cascade size shift propagates through the case handlers and epilogue
//   * Total size stays 292 (trailing nop makes up the difference)
// - FPU eval order: x_start→x_end→y_start→y_end (matched by declaration order)
// - Terrain type map: 0→(b&0xF0)|0x10, 1→(b&0xEF)|0x0F, 6→(b&0xEE)|0x0E
// - Three-level indirection: building→obj→map (same as lay_down_passable_terrain)
// - Tile access: `*(tile_data + row*4) + col*24` at byte offset 5

extern "C" long __ftol();

struct GameMap {
    char gap_00[8];
    int width;          // +0x08
    int height;         // +0x0C
    char gap_10[0x8D8C - 0x10];
    unsigned char** tile_data;  // +0x8D8C
};

struct TRIBE_Building_Object {
    char base[0x08];
    void* terrain;      // +0x08
    void* building;     // +0x0C
    char gap_10[0x38 - 0x10];
    float x;            // +0x38
    float y;            // +0x3C

    void lay_down_impassable_terrain();
};

void TRIBE_Building_Object::lay_down_impassable_terrain() {
    void* building = *(void**)((char*)this + 0x0C);
    void* obj = *(void**)((char*)building + 0x3C);
    GameMap* map = *(GameMap**)((char*)obj + 0x28);

    if (*(short*)((char*)terrain + 0x174) > -1) {
        return;
    }

    short x_start = (short)(x - *(float*)((char*)terrain + 0x30));
    short x_end = (short)(*(float*)((char*)terrain + 0x30) + x - 10.0f);
    short y_start = (short)(y - *(float*)((char*)terrain + 0x34));
    short y_end_val = (short)(*(float*)((char*)terrain + 0x34) + y - 10.0f);

    if (x_start < 0) x_start = 0;
    if (y_start < 0) y_start = 0;

    if (x_end >= map->width) x_end = (short)(map->width - 1);
    if (y_end_val >= map->height) y_end_val = (short)(map->height - 1);

    if (y_start <= y_end_val) {
        int row_offset = (int)y_start * 4;
        int row_count = (int)y_end_val - (int)y_start + 1;

        do {
            if (x_start <= x_end) {
                int col_offset = (int)x_start * 24;
                int col_count = (int)x_end - (int)x_start + 1;

                do {
                    unsigned char* tile = *(unsigned char**)((char*)map->tile_data + row_offset) + col_offset;
                    unsigned char b = tile[5];

                    int val = (b & 0x1F) - 0;

                    if (val != 0) {
                        if (--val != 0) {
                            val -= 5;
                            if (val != 0) goto loop_continue;
                            tile[5] = (b & 0xEE) | 0x0E;
                            goto loop_continue;
                        }
                        tile[5] = (b & 0xEF) | 0x0F;
                        goto loop_continue;
                    }
                    tile[5] = (b & 0xF0) | 0x10;
                    loop_continue: ;

                    col_offset += 24;
                    col_count--;
                } while (col_count != 0);
            }
            row_offset += 4;
            row_count--;
        } while (row_count != 0);
    }
}
