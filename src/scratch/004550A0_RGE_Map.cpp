// VA: 004550A0 RGE_Map::RGE_Map
// Attempt log:
// try 1: packet-grounded constructor: vptr/global fields, tile-size table calls,
// scalar zeroing, 32-entry terrain/object-info initialization loops, final load helpers. Compiled too short (736B vs 902B).
// try 2: diagnostic-only padding branch reached byte compare, then removed. Diagnostic compare was broad mismatch (80.7095% positional / 107.3171% edit); prologue had extra stack/local pressure and wrong register allocation.
// try 3: verified key behavioral facts from packet: vptr 0x570678, rge_base_game +0x3f4 copied to +8dc0, 19 set_tile_size calls, two final helper calls 00457F80/00458350, and zeroing of map/object tables.
// Blockers: exact source/topology for the two nested table-zeroing loops, avoiding VC5 stack locals while keeping EBP as late loop counter, and exact parameter/register reuse around the long set_tile_size sequence.
// GIVEUP: broad constructor layout mismatch remains; no accepted_drift proposal and no inline asm used.

extern void* rge_base_game;

struct TileSizeEntry { short width; short height; short y_delta; };

class RGE_Map {
public:
    void* vfptr;
    char* field_04;
    int map_width;
    int map_height;
    int field_10;
    int field_14;
    TileSizeEntry tilesizes[256]; // +18
    char gap_618[0x8d90 - 0x618];
    short field_8d90;
    short gap_8d92;
    short field_8d94;
    short mapWidthArg;   // +8d96
    short mapHeightArg;  // +8d98
    short halfHeight;    // +8d9a
    short halfWidth;     // +8d9c
    short tileSizeArg;   // +8d9e
    short field_8da0;
    short field_8da2;
    short field_8da4;
    short field_8da6;
    short field_8da8;
    short field_8daa;
    char field_8dac;
    char gap_8dad[3];
    int field_8db0;
    int field_8db4;
    char field_8db8;
    char field_8db9;
    char gap_8dba[2];
    int field_8dbc;
    int field_8dc0;
    int field_8dc4;
    int field_8dc8;
    int field_8dcc;

    RGE_Map(char* a1, char* a2, char* a3, short w, short h, short tile, void** sounds);
    void set_tile_size(unsigned char index, short width, short height, short y_delta);
    void sub_457F80(char* a, void** sounds);
    void sub_458350(char* a, void** sounds);
};

RGE_Map::RGE_Map(char* a1, char* a2, char* a3, short w, short h, short tile, void** sounds)
{
    int zero = 0;
    this->vfptr = (void*)0x00570678;
    this->field_8dc4 = zero;
    this->field_8dbc = zero;
    this->field_8dc0 = *(int*)((char*)rge_base_game + 0x3f4);
    this->mapWidthArg = w;
    this->halfWidth = (short)(((int)w - ((int)w >> 31)) >> 1);
    this->mapHeightArg = h;
    this->halfHeight = (short)(((int)h - ((int)h >> 31)) >> 1);
    this->tileSizeArg = tile;
    this->map_width = zero;
    this->map_height = zero;
    this->field_10 = zero;
    this->field_14 = zero;

    set_tile_size(0, w, h, 0);
    set_tile_size(1, w, tile, -100);
    set_tile_size(2, w, (short)(tile + h), 100);
    set_tile_size(3, w, h, -100);
    set_tile_size(4, w, h, -100);
    set_tile_size(5, w, tile, -100);
    set_tile_size(6, w, (short)(tile + h), 100);
    set_tile_size(7, w, tile, -100);
    set_tile_size(8, w, (short)(tile + h), 100);
    set_tile_size(9, w, tile, -100);
    set_tile_size(10, w, (short)(tile + h), 100);
    set_tile_size(11, w, h, -100);
    set_tile_size(12, w, h, -100);
    set_tile_size(13, w, tile, -100);
    set_tile_size(14, w, (short)(tile + h), 100);
    set_tile_size(15, w, h, 100);
    set_tile_size(16, w, h, 100);
    set_tile_size(17, this->halfWidth, h, 0);
    set_tile_size(18, this->halfWidth, h, 0);

    this->field_8da0 = 0;
    this->field_8da2 = 0;
    this->field_8d90 = 0;
    this->field_8d94 = 0;
    this->field_8da4 = 0;
    this->field_8da6 = 0;
    this->field_8da8 = 0;
    this->field_8daa = 0;
    this->field_8dac = 0;
    this->field_8db8 = 0;
    this->field_8db9 = 1;

    char* p = (char*)this + 0x146;
    int count = 0x20;
    do {
        *(short*)(p + 0xda) = 0;
        *(short*)(p + 0) = 0;
        *(short*)(p + 2) = 0;
        short* q = (short*)(p + 0x44);
        int n = 0x1e;
        do {
            *(short*)((char*)q - 0x3c) = 0;
            *q = 0;
            q++;
        } while (--n != 0);
        for (int k = 0; k < 0x10; ++k) {
            *(int*)(p + 4 + k * 4) = 0;
        }
        *(int*)(p + 0x66) = 0;
        *(int*)(p + 0x6a) = 0;
        p += 0x198;
    } while (--count != 0);

    int* r = (int*)((char*)this + 0x8810);
    int c = 0x10;
    do {
        *(r - 1) = 0;
        *r = 0;
        r = (int*)((char*)r - 0x5a0);
    } while (--c != 0);

    sub_457F80(a2, sounds);
    sub_458350(a1, sounds);
    this->field_04 = 0;
    this->field_8db0 = 0;
    *(int*)((char*)this + 0x8d8c) = 0;
    this->field_8db4 = 0;
    this->field_8dc8 = 0;
    this->field_8dcc = 0;
}
