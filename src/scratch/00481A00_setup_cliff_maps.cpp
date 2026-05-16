// 00481A00 RGE_RMM_Cliffs_Generator::setup_cliff_maps()
// Source: rmm_clif.cpp lines 60-173
// Attempt log:
// - Initial reconstruction from packet/decompiler.
// - Initial compile used a helper div3(), causing calls instead of original VC5 magic multiply; inlined source divisions by 3 fixed the prologue magic-divide family.
// - Modeled key offsets: source row pointers +0x10, map width/height +0x14/+0x18, cliff map +0x20, valid row map +0x24, stack_nodes +0x2C, spacing +0x40, hot spots +0x4C, hot_spot_num +0x4EC, valid_cliff_sites +0x4F0.
// - Best current check is same-size 706B mismatch, positional 80.8782%, edit 19.8300%, first mismatch offset 35. The edit diff suggests similar broad structure but shifted/register-different: width/height locals allocated to ESI/EBX differently, local slot ordering differs, and nested 3x3 scan / invalidation / final isolation-prune loops remain register/layout drift. Not accepted_drift-safe.

class RGE_RMM_Cliffs_Generator {
public:
    char gap0[0x10];
    int terrain_rows;       // +10 row pointers for source terrain?
    int map_width;          // +14
    int map_height;         // +18
    char gap1C[4];
    unsigned char* cliff_map; // +20
    unsigned char** valid_rows; // +24
    char gap28[4];
    void** stack_nodes;     // +2c
    char gap30[0x40-0x30];
    int cliff_terrain_spacing; // +40
    char gap44[8];
    int hot_spots[3 * 80]; // +4c approx x,y,r
    char gap4EC[0x4EC-0x4C-3*80*4];
    int hot_spot_num;       // +4ec
    char valid_cliff_sites; // +4f0

    void clear_stack();
    void init_stack(void*);
    void push_stack(void*, int, int, float, float);
    void randomize_stack(void*);
    void remove_stack_node(void*);
    void invalidate_cliff_area(int, int, int);
    void setup_cliff_maps();
};

void RGE_RMM_Cliffs_Generator::setup_cliff_maps()
{
    int cliff_width = this->map_width / 3;
    int terrain_height = this->map_height / 3;
    int terrain_width = cliff_width;
    int terrain_height_m1 = terrain_height - 1;
    int cliff_width_m1 = cliff_width - 1;

    this->clear_stack();
    this->init_stack(&this->valid_cliff_sites);

    unsigned int total = this->map_height * this->map_width;
    unsigned char* p = this->cliff_map;
    while (total--) *p++ = 1;

    int row = 0;
    if (terrain_height > 0) {
        int row_offset = 0;
        do {
            int col = 0;
            if (cliff_width > 0) {
                int col_offset = 0;
                do {
                    int area = -1;
                    unsigned char ok = 1;
                    unsigned char water_area = 0;
                    int* srcrow = (int*)(this->terrain_rows + row_offset);
                    int rr = 3;
                    do {
                        int cc = 3;
                        unsigned char* tile = (unsigned char*)(*srcrow + col_offset + 5);
                        do {
                            unsigned char v = *tile;
                            unsigned char low = v & 0x1f;
                            if (low == 0 || low == 6) {
                                unsigned char a = v >> 5;
                                if (area < 0) area = a;
                                else if (area != a) ok = 0;
                            } else {
                                ok = 0;
                                if (low == 1 || low == 4 || low == 0x16) water_area = 1;
                            }
                            tile += 0x18;
                        } while (--cc != 0);
                        srcrow++;
                    } while (--rr != 0);

                    if (ok) {
                        unsigned char* cell = this->valid_rows[row] + col;
                        if (*cell != 0) {
                            *cell = (unsigned char)(area + 1);
                            this->push_stack(&this->valid_cliff_sites, col, row, 0.0f, 0.0f);
                        }
                    } else {
                        if (water_area) this->invalidate_cliff_area(col, row, this->cliff_terrain_spacing);
                        this->valid_rows[row][col] = 0;
                    }
                    col++;
                    col_offset += 0x48;
                } while (col < cliff_width);
            }
            row++;
            row_offset += 0x0c;
        } while (row < terrain_height);
    }

    int h = 0;
    if (this->hot_spot_num > 0) {
        int* hs = &this->hot_spots[1];
        do {
            this->invalidate_cliff_area(hs[-1] / 3, hs[0] / 3, hs[1] / 3 + 2);
            h++;
            hs += 3;
        } while (h < this->hot_spot_num);
    }

    int y = 0;
    if (terrain_height > 0) {
        do {
            int x = 0;
            if (cliff_width > 0) {
                int stack_off = 0;
                do {
                    unsigned char* cell = this->valid_rows[y] + x;
                    if (*cell != 0 &&
                        (y <= 0 || this->valid_rows[y - 1][x] == 0) &&
                        (x <= 0 || cell[-1] == 0) &&
                        (y >= terrain_height_m1 || this->valid_rows[y + 1][x] == 0) &&
                        (x >= cliff_width_m1 || cell[1] == 0)) {
                        *cell = 0;
                        this->remove_stack_node((char*)this->stack_nodes[y] + stack_off);
                    }
                    x++;
                    stack_off += 0x18;
                } while (x < cliff_width);
            }
            y++;
        } while (y < terrain_height);
    }

    this->randomize_stack(&this->valid_cliff_sites);
}
