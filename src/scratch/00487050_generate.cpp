// VA: 00487050 RGE_RMM_Shallows_Generator::generate
// PDB: rmm_shal.cpp:42-102
//
// Canonical ownership:
// - RGE_Random_Map_Module::map_row_offset is the map's row table (+0x10).
// - RGE_RMM_Shallows_Generator::info is RGE_Shallows_Info at +0x30.
// - Each map tile is 0x18 bytes.  terrain_type is the low five bits at +0x5.
//
// Attempts:
// - baseline: natural typed map-row and shallows-info reconstruction; 418 bytes,
//   exact frame and calls, 19 differing bytes.
// - layout: restored RGE_Tile's proven 0x18-byte map stride; 15 differing bytes.
// - control-flow: preserve the binary's found flag before the y store; 6 bytes differ.
// - liveness: top-declared i/j/k reduced the gap to 5 bytes; moving k's copy
//   before the guard reverted to the 6-byte basin.
// - context: top-declared random x/y locals retain the 5-byte basin.
// - final: calls, layout, frame, CFG, and all 418 bytes of size align. Remaining
//   drift is five scheduling bytes: mov edi,ebp before jge and cmp ebx,eax.

class RGE_Map;
class RGE_Random_Map_Module_List;
class Map_Stack;

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char border_type : 4;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char objects[12];
};

struct RGE_Shallows_Info_Line {
    long x;
    long y;
};

struct RGE_Shallows_Info {
    RGE_Shallows_Info_Line shallows[99];
    long shallows_num;
};

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate() = 0;

    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    void clear_stack();
};

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module {
public:
    virtual unsigned char generate();

    RGE_Shallows_Info info;

    void make_tribe_connections(long a, long b);
};

extern "C" int __cdecl debug_rand(char*, int);

unsigned char RGE_RMM_Shallows_Generator::generate() {
    this->clear_stack();

    long i, j, k;
    long x, y;
    i = 0;
    if (i < this->info.shallows_num) {
        do {
            j = i + 1;
            if (j < this->info.shallows_num) {
                k = j;
                do {
                    this->make_tribe_connections(i, k);
                    ++k;
                } while (k < this->info.shallows_num);
            }
            i = j;
        } while (j < this->info.shallows_num);
    }

    long count = 2;
    this->info.shallows_num += 2;
    long index1 = this->info.shallows_num - 1;
    long index2 = this->info.shallows_num - 2;

    do {
        int found = 0;
        do {
            x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x45) *
                 (this->map_width - 1)) / 0x7FFF;
            y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x46) *
                 (this->map_height - 1)) / 0x7FFF;
            if (this->map_row_offset[y][x].terrain_type != 1 &&
                this->map_row_offset[y][x].terrain_type != 0x16 &&
                this->map_row_offset[y][x].terrain_type != 4) {
                this->info.shallows[index1].x = x;
                found = 1;
                this->info.shallows[index1].y = y;
            }
        } while (!found);

        found = 0;
        do {
            x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x54) *
                 (this->map_width - 1)) / 0x7FFF;
            y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x55) *
                 (this->map_height - 1)) / 0x7FFF;
            if (this->map_row_offset[y][x].terrain_type != 1 &&
                this->map_row_offset[y][x].terrain_type != 0x16 &&
                this->map_row_offset[y][x].terrain_type != 4) {
                this->info.shallows[index2].x = x;
                found = 1;
                this->info.shallows[index2].y = y;
            }
        } while (!found);

        this->make_tribe_connections(index1, index2);
        --count;
    } while (count != 0);

    return 1;
}
