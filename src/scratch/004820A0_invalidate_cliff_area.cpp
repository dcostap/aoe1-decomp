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
// - A fresh source-order probe moved the natural x=cliff_x2 assignment before
//   the negative-bound guards, matching the oracle's unconditional x-home
//   store before the first test. This is the best current basin (246 rebuilt
//   bytes, 177 positional differing bytes, 91.01% shape); it improves the
//   prior clean source by four bytes without changing calls or layout.
// - Mutating y as the outer countdown, endpoint declaration/addition reorder,
//   direct x/y endpoint expressions, and equivalent first-clip spellings were
//   neutral or farther. Keeping a separate right-endpoint local through the
//   loop removed the required frame and was rolled back. The retained source
//   therefore keeps typed named ownership and only the binary-supported
//   x-home scheduling change.
// - Bounded follow-up probes kept the clean repeated-row source as canonical.
//   Reusing x as the clipped right bound is the metric-best diagnostic (248
//   rebuilt bytes, 181 differing bytes, 89.89% shape) but remains nonexact and
//   was rolled back; exact base-field types and cursor declaration scope were
//   codegen-neutral. That earlier clean checkpoint remains useful history; the
//   current source is the later 246-byte basin described above, still with one
//   ordered remove_stack_node call and structural drift in the entry schedule.
// - Fresh direct-parameter/declaration-order probes and a 12-variant
//   input/loop lab did not move the entry register basin. The binary-proven
//   x-home assignment with the clipped-x second comparison remains the best
//   behavior-faithful reconstruction; later column/right-lifetime probes were
//   duplicate or farther and are not retained.
// - This session tested compound endpoint updates, spacing-first endpoint
//   seeds, removal of parameter-home mutations, grouped coordinate endpoints,
//   same-TU <string.h> context, a retained right-endpoint local, and split
//   bound decrements. None improved the current 246-byte basin; the clean
//   typed source was restored before final validation.

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
    long cliff_x = x - spacing;
    long cliff_y = y - spacing;
    long cliff_x2 = spacing + x;
    long cliff_y2 = spacing + y;

    spacing = cliff_x;
    x = cliff_x2;
    if (cliff_x < 0) {
        spacing = 0;
    }
    if (cliff_y < 0) {
        cliff_y = 0;
    }
    if (cliff_x2 > cliff_width2) {
        x = cliff_width2;
    }
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
