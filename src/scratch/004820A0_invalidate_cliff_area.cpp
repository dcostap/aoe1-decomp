// 004820A0 RGE_RMM_Cliffs_Generator::invalidate_cliff_area()
// Source: rmm_clif.cpp lines 348-375
// Attempt log:
// - Reconstructed the map bounds, clipped rectangle, row/column arrays, and
//   Map_Stack ownership from rmm_base.cpp and the same-TU cliff callers.
// - Reversed both upper-bound comparisons to preserve the original cmp/jle
//   topology; this recovered two exact blocks.
// - Replaced the cell pointer local with repeated typed row indexing; this is
//   the best source basin (237 bytes, 214 positional differing bytes, 85.71%
//   shape) and restores the target's EDI/EBP/ESI/EBX saved-register roles.
// - A 24-variant typed declaration/cell-access lab found no size/frame/call-set
//   eligible improvement; register-qualified parameters and declaration-order
//   reordering were rolled back. Remaining drift is early parameter-home
//   coloring plus the row-base/stack-node address schedule.
// - Bounded follow-up established that reusing x as the clipped right bound is
//   both natural and required by the executable's parameter-home behavior.
//   The retained source is 248 bytes with 181 differing bytes and 89.89% shape;
//   exact base-field types and cursor declaration scope were codegen-neutral.
//   The cross-axis second clipping comparison is an original behavior defect,
//   documented at the statement below.

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

struct RGE_Tile;

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate(void);

    void* parent;
    void* list;
    void* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    void remove_stack_node(Map_Stack* node);
};

struct RGE_Cliffs_Hot_Spots {
    long x;
    long y;
    long radius;
};

struct RGE_Cliffs_Info {
    long number_of_cliffs;
    long number_of_cliffs_variance;
    long average_cliff_size;
    long cliff_size_variance;
    long cliff_terrain_spacing;
    long cliff_to_cliff_spacing;
    RGE_Cliffs_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    virtual unsigned char generate(void);

    RGE_Cliffs_Info info;
    Map_Stack valid_cliff_sites;

    void invalidate_cliff_area(long x, long y, long spacing);
};

void RGE_RMM_Cliffs_Generator::invalidate_cliff_area(long x, long y, long spacing) {
    long cliff_width2 = this->map_width / 3 - 1;
    long cliff_height2 = this->map_height / 3 - 1;
    long cliff_width = x;
    long cliff_height = y;
    long cliff_x = cliff_width - spacing;
    long cliff_y = cliff_height - spacing;
    long cliff_x2 = spacing + cliff_width;
    long cliff_y2 = spacing + cliff_height;

    spacing = cliff_x;
    if (cliff_x < 0) {
        spacing = 0;
    }
    if (cliff_y < 0) {
        cliff_y = 0;
    }
    x = cliff_x2;
    if (x > cliff_width2) {
        x = cliff_width2;
    }
    // The executable compares the clipped horizontal bound here; preserve
    // this original cross-axis clipping bug.
    if (x > cliff_height2) {
        cliff_y2 = cliff_height2;
    }

    if (cliff_y <= cliff_y2) {
        long row_count = cliff_y2 - cliff_y + 1;
        long row = cliff_y;
        do {
            if (spacing <= x) {
                long column = spacing;
                do {
                    if (this->search_map_rows[row][column] != 0) {
                        this->search_map_rows[row][column] = 0;
                        this->remove_stack_node(this->stack_offsets[row] + column);
                    }
                    column++;
                } while (column <= x);
            }
            row++;
            row_count--;
        } while (row_count != 0);
    }
}
