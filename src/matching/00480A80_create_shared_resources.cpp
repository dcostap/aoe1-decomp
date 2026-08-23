// 00480A80 RGE_Random_Map_Module::create_shared_resources (rmm_base.cpp:211-234)
// Attempt 2: fix VC5 redefinition issue - use separate loop vars

#include <stdlib.h>

#ifndef RMM_BASE_SHARED_CONTEXT
struct Map_Stack {
    long x;                // +0x00
    long y;                // +0x04
    char gap_08[0x10];     // +0x08 to +0x17
};

class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module() {} // vtable ptr at +0x00

    RGE_Random_Map_Module* parent;          // +0x04
    void* list;                              // +0x08
    void* map;                               // +0x0C
    void** map_row_offset;                   // +0x10
    long map_width;                          // +0x14
    long map_height;                         // +0x18
    float schedule;                          // +0x1C

    unsigned char* search_map;               // +0x20
    unsigned char** search_map_rows;         // +0x24
    Map_Stack* stack_array;                  // +0x28
    Map_Stack** stack_offsets;               // +0x2C

    void create_shared_resources();
};
#endif

void RGE_Random_Map_Module::create_shared_resources() {
    int i;
    int y;
    int count;

    count = map_height;
    count *= map_width;
    // BINARY NOTE: Store each allocation before row-pointer publication.
    // The shipped code does not test allocation results.
    search_map = (unsigned char*)calloc(count, 1);
    search_map_rows = (unsigned char**)calloc(map_height, 4);

    for (i = 0; i < map_height; i++) {
        search_map_rows[i] = search_map + i * map_width;
    }

    count = map_height;
    count *= map_width;
    stack_array = (Map_Stack*)calloc(count, 0x18);
    stack_offsets = (Map_Stack**)calloc(map_height, 4);

    for (i = 0; i < map_height; i++) {
        stack_offsets[i] = &stack_array[i * map_width];
    }

    for (i = 0; i < map_height; i++) {
        for (y = 0; y < map_width; y++) {
            stack_offsets[i][y].x = y;
            stack_offsets[i][y].y = i;
        }
    }
}
