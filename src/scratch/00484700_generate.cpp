// 00484700 RGE_RMM_Elevation_Generator::generate
// PDB: rmm_elev.cpp lines 29-59
// Attempt log:
// - baseline: natural generator loops over the base map tile rows, copies each
//   elevation-info line by value, then cleans the generated map rectangle.
// - do-while/indexed row loops reached the exact 191-byte boundary and matched
//   the outer CFG; direct row-byte addressing is retained as the canonical map
//   ownership model.
// - a narrow volatile line-pointer probe reproduced the stack cursor and late
//   call topology, but it was compiler steering rather than observed behavior
//   and was not retained in the canonical source.
// - named byte/address temporaries, cursor aggregates, and alternate info
//   pointer types did not recover the remaining inner tile scheduling. The
//   remaining mismatch is the 2-byte-short inner body: original reads/masks the
//   tile byte, then loads/shifts base elevation, while VC5 schedules the base
//   load first for the current natural bitfield/raw-address spellings.

struct RGE_Map;
struct RGE_Random_Map_Module_List;
struct Map_Stack;

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char elevation : 3;
    unsigned char border_type : 4;
    unsigned char border_shape : 4;
    char objects[12];
};

struct RGE_Elevation_Hot_Spot {
    char bytes[0x10];
};

struct RGE_Elevation_Info_Line {
    long elevation_size;
    long elevation;
    long clumps;
    long spacing;
    long base_elevation;
    long base_terrain_type;
};

struct RGE_Elevation_Info {
    RGE_Elevation_Info_Line elevation[99];
    long elevation_num;
    RGE_Elevation_Hot_Spot hot_spots[99];
    long hot_spot_num;
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

class RGE_Map {
public:
    void clean_elevation(long x, long y, long width, long height, unsigned char elevation);
};

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:
    virtual unsigned char generate();
    RGE_Elevation_Info info;

    void generate_modifiers();
    unsigned char base_elevation_generate(RGE_Elevation_Info_Line line);
};

unsigned char RGE_RMM_Elevation_Generator::generate() {
    this->clear_stack();

    if (this->info.elevation_num > 0) {
        long row = 0;
        if (row < this->map_height) {
            do {
                long col = 0;
                if (col < this->map_width) {
                    long offset = 0;
                    do {
                        ((RGE_Tile*)((char*)this->map_row_offset[row] + offset))->elevation =
                            (unsigned char)this->info.elevation[0].base_elevation;
                        ++col;
                        offset += 0x18;
                    } while (col < this->map_width);
                }
                ++row;
            } while (row < this->map_height);
        }
    }

    this->generate_modifiers();

    long i = 0;
    if (this->info.elevation_num > 0) {
        RGE_Elevation_Info_Line* line = this->info.elevation;
        do {
            this->base_elevation_generate(*line);
            this->map->clean_elevation(0, 0, this->map_width - 1,
                this->map_height - 1, 8);
            ++i;
            ++line;
        } while (i < this->info.elevation_num);
    }

    return 1;
}
