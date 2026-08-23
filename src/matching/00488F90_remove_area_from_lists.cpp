#include "../../include/rmm_terr_context.h"

void RGE_RMM_Terrain_Generator::remove_area_from_lists(long p1, long p2, long p3)
{
    long xmin = p1 - p3;
    long ymin = p2 - p3;
    long xmax = p1 + p3;
    long ymax = p2 + p3;

    if (xmin < 0) xmin = 0;
    if (ymin < 0) ymin = 0;

    if (xmax >= map_width) {
        xmax = map_width - 1;
    }
    if (ymax >= map_height) {
        ymax = map_height - 1;
    }

    for (long y = ymin; y <= ymax; y++) {
        if (xmin <= xmax) {
                long base = xmin * 3;
            long count = xmax - xmin;
            base <<= 3;
            count++;
            do {
                remove_stack_node((Map_Stack*)((char*)stack_arrays[y] + base));
                base += 24;
                count--;
            } while (count != 0);
        }
    }
}
