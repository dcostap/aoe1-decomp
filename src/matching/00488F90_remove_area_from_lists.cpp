// 00488F90 RGE_RMM_Terrain_Generator::remove_area_from_lists (154B)
// rmm_terr.cpp:279-300
// void __thiscall remove_area_from_lists(long param_1, long param_2, long param_3)

class RGE_RMM_Terrain_Generator {
public:
    // Inherits from RGE_Random_Map_Module (0x30 bytes base)
    char pad_00[0x14];
    long map_width;                 // +0x14
    long map_height;                // +0x18
    char pad_1C[0x2C - 0x1C];
    void** stack_arrays;            // +0x2C

    void remove_area_from_lists(long p1, long p2, long p3);
    void remove_stack_node(void* node);
};

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
                remove_stack_node((void*)((char*)stack_arrays[y] + base));
                base += 24;
                count--;
            } while (count != 0);
        }
    }
}
