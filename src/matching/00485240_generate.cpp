// VA: 00485240 RGE_RMM_Land_Generator::generate
// PDB: rmm_land.cpp lines 33-51 (133 bytes, 53 asm lines)
// Default flags. No inline asm/hacks.
// MATCHED 2026-05-19: use int fill with only low byte assigned to avoid movsx/xor
// before VC5's inline memset; spelling area as height*width makes VC5 emit
// load width then imul height.

extern "C" void* memset(void* dst, int val, unsigned int size);

class RGE_Map {
public:
    void set_terrain(void* a1, void* a2, int a3, int a4, short w, short h, unsigned char terrain, unsigned char flag1, unsigned char flag2);
    void clean_terrain(int a1, int a2, int w, int h, unsigned char terrain);
};

class RGE_Random_Map_Module {
public:
    void clear_stack();
};

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
public:
    char gap_00[0x0C];
    void* rmm_map;
    char gap_10[4];
    int width;
    int height;
    char gap_1C[4];
    void* fill_buf;
    char gap_24[0x144C - 0x24];
    unsigned char fill_value;
    char fill_pad[3];
    unsigned char land_terrain;
    char gap_1451[0x1454 - 0x1451];
    int int_fill;
    int int_terrain;

    unsigned char generate();
    unsigned char base_land_generate();
};

unsigned char RGE_RMM_Land_Generator::generate() {
    this->clear_stack();

    int area = this->height;
    int fill;
    *(char*)&fill = this->fill_value;
    void* buf = this->fill_buf;
    area *= this->width;
    memset(buf, fill, area);

    (*(RGE_Map**)&this->rmm_map)->set_terrain(
        0, 0, 0, 0,
        this->width - 1,
        this->height - 1,
        this->land_terrain,
        1,
        0);

    this->base_land_generate();

    (*(RGE_Map**)&this->rmm_map)->clean_terrain(
        0, 0,
        this->width,
        this->height,
        this->land_terrain);

    return 1;
}
