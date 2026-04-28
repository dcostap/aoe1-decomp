// VA: 00487050 generate
// rmm_shal.cpp lines 42-102
//
// Attempts:
//   1-3: temp vars, inline debug_rand -> 400-416 bytes
//   4-8: stack alloc tricks -> stayed at 416
//   Fix: volatile/address-of for limit+idx2 -> 418 bytes (stack frame now matches)
//   Remaining: instruction scheduling (21 spans, 72.5%)
//   e.g. mov edi,ebp vs jge instruction reordering at offset 31
//   Deep codegen basin. Left in scratch.

class RGE_Random_Map_Module {
public:
    void* vtable_ptr;
    void* parent;
    void* list;
    void* map;
    void* map_row_offset;
    int map_width;
    int map_height;
    float schedule;
    void* search_map;
    void* search_map_rows;
    void* stack_array;
    void* stack_offsets;

    void clear_stack();
};

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module {
public:
    struct { long x, y; } shallows[99];
    int shallows_num;

    unsigned char generate();
    void make_tribe_connections(int a, int b);
};

extern int debug_rand(char*, int);

unsigned char RGE_RMM_Shallows_Generator::generate() {
    int i, j;
    int x, y;
    int idx1;
    int idx2;
    int limit;

    clear_stack();

    i = 0;
    if (this->shallows_num > 0) {
        do {
            j = i + 1;
            if (j < this->shallows_num) {
                int k = j;
                do {
                    make_tribe_connections(i, k);
                    k++;
                } while (k < this->shallows_num);
            }
            i = j;
        } while (j < this->shallows_num);
    }

    limit = 2;
    idx1 = this->shallows_num + 1;
    idx2 = this->shallows_num;
    this->shallows_num += 2;

    do {
        int found;

        // First random point
        do {
            x = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x45) * (this->map_width - 1) / 0x7FFF;
            y = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x46) * (this->map_height - 1) / 0x7FFF;
            found = 0;
            {
                unsigned char** row_ptrs = (unsigned char**)this->search_map;
                unsigned char terrain = row_ptrs[y][x * 24 + 5] & 0x1F;
                if (terrain != 1 && terrain != 0x16 && terrain != 4) {
                    this->shallows[idx1].x = x;
                    this->shallows[idx1].y = y;
                    found = 1;
                }
            }
        } while (!found);

        // Second random point
        do {
            x = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x54) * (this->map_width - 1) / 0x7FFF;
            y = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x55) * (this->map_height - 1) / 0x7FFF;
            found = 0;
            {
                unsigned char** row_ptrs = (unsigned char**)this->search_map;
                unsigned char terrain = row_ptrs[y][x * 24 + 5] & 0x1F;
                if (terrain != 1 && terrain != 0x16 && terrain != 4) {
                    this->shallows[idx2].x = x;
                    this->shallows[idx2].y = y;
                    found = 1;
                }
            }
        } while (!found);

        make_tribe_connections(idx1, idx2);
        limit--;
    } while (limit != 0);

    return 1;
}
