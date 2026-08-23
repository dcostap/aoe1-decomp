#include <stdlib.h>

#ifndef RMM_BASE_SHARED_CONTEXT
class RGE_Random_Map_Module {
public:
    char gap_00[0x20];
    void* search_map;
    void* search_map_rows;
    void* stack_array;
    void* stack_offsets;

    void destroy_shared_resources();
};
#endif

void RGE_Random_Map_Module::destroy_shared_resources() {
    if (search_map != 0) {
        free(search_map);
    }
    search_map = 0;
    if (search_map_rows != 0) {
        free(search_map_rows);
    }
    search_map_rows = 0;
    if (stack_array != 0) {
        free(stack_array);
    }
    stack_array = 0;
    if (stack_offsets != 0) {
        free(stack_offsets);
    }
    stack_offsets = 0;
}
