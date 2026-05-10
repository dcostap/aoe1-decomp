// 00484C80 RGE_RMM_Elevation_Generator::remove_area_from_lists
// MATCHED: keep natural start/end locals, then intentionally assign the clipped end and row
// back into incoming parameter slots (`x = end; radius = start_y;`). VC5 then reuses the
// original stack parameter homes: x slot stores the right/bottom bound and radius slot stores
// the outer-loop row. Keeping separate start_y/end locals stores too early and shifts the loop.

class RGE_RMM_Elevation_Generator {
public:
    char gap_00[0x14];
    int size;
    char gap_18[0x2C - 0x18];
    char** stacks;

    void remove_stack_node(void* node);
    void remove_area_from_lists(long x, long y, long radius);
};

void RGE_RMM_Elevation_Generator::remove_area_from_lists(long x, long y, long radius) {
    long start_x = x - radius;
    long start_y = y - radius;
    long end = x + radius;

    if (start_x < 0) {
        start_x = 0;
    }
    if (start_y < 0) {
        start_y = 0;
    }
    if (end >= this->size) {
        end = this->size - 1;
    }

    x = end;
    radius = start_y;
    for (; radius <= x; radius++) {
        if (start_x <= x) {
            long offset = start_x * 0x18;
            long count = x - start_x + 1;
            do {
                this->remove_stack_node(this->stacks[radius] + offset);
                offset += 0x18;
                count--;
            } while (count != 0);
        }
    }
}
