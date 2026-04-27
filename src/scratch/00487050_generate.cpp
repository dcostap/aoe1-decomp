// VA: 00487050 generate
// rmm_shal.cpp lines 42-102

// 8 probes total:
//   1-2: temp vars used -> 400 bytes (debug_rand results stored to temps)
//   3:   inline debug_rand expressions -> 416 bytes (2 short, prolog diff)
//   4-8: various stack allocation tricks -> regressed or stayed at 416
//   left in scratch: 416 bytes vs 418 (99.5%). Prolog: push ecx vs sub esp,8 (2 bytes).
//   VC5 only allocates 4 bytes of stack for locals but original needs 8 (idx2 + limit).
//   Body code is functionally correct; the 2-byte prolog shift prevents byte-level comparison.

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
    int idx1, idx2;
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
