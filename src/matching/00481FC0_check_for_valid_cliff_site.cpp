// Reconstructed from the rmm_clif.cpp line bands and original control flow.
// Attempt log:
// - natural direction normalization and row-table ownership reached the exact size/CFG basin.
// - the exact VC5 basin retains reference-address aliases, reads width before height, and stores width before height.
// - variant lab confirmed the final source shape as an exact default-flag match.

#ifdef RMM_CLIF_SHARED_CONTEXT
#include "../../include/rmm_clif_context.h"
#else
class RGE_Random_Map_Module {
public:
    virtual unsigned char generate(void);

    void* parent;
    void* list;
    void* map;
    void* map_row_offset;
    int map_width;
    int map_height;
    char gap_1c[4];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    void* stack_array;
    void* stack_offsets;
};

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    virtual unsigned char generate(void);

protected:
    unsigned char check_for_valid_cliff_site(long direction, long& y,
                                              long& valid_height, long index);
};
#endif

unsigned char RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site(
    long direction, long& y, long& valid_height, long index) {
    long* height_pointer = &valid_height;
    long* width_pointer = &y;
    long width = *width_pointer;
    long height = *height_pointer;

    if (direction > 3) {
        unsigned long count = ((unsigned long)direction - 1) / 3;
        do {
            direction -= 3;
            count--;
        } while (count != 0);
    }

    if (direction < 0) {
        direction = ((unsigned long)(2 - direction) / 3) * 3 + direction;
    }

    switch (direction) {
    case 0:
        if (height <= 0)
            goto invalid;
        height--;
        break;
    case 1:
        if (width >= this->map_width / 3 - 1)
            goto invalid;
        width++;
        break;
    case 2:
        if (height >= this->map_height / 3 - 1)
            goto invalid;
        height++;
        break;
    case 3:
        if (width <= 0)
            goto invalid;
        width--;
        break;
    }

    if ((unsigned char)this->search_map_rows[height][width] == index) {
        *width_pointer = width;
        *height_pointer = height;
        return 1;
    }

invalid:
    return 0;
}
