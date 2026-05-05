// 00484C80 RGE_RMM_Elevation_Generator::remove_area_from_lists
// HollowSnowdrop pass: natural clipped rectangle loop reaches exact size 128/128 and correct prologue/call shape. Best diff 71.1% positional / 47.7% edit. Remaining drift starts after computing end/start bounds: rebuilt stores start_y early and uses slightly different stack-param slots; parameter-slot reuse/source-shape issue.

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

    for (; start_y <= end; start_y++) {
        if (start_x <= end) {
            long offset = start_x * 0x18;
            long count = end - start_x + 1;
            do {
                this->remove_stack_node(this->stacks[start_y] + offset);
                offset += 0x18;
                count--;
            } while (count != 0);
        }
    }
}
