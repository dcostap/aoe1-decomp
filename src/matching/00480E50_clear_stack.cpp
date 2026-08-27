// BINARY NOTE: The PDB proves a 0x18-byte Map_Stack and Map_Stack** rows.
// Direct indexed ownership preserves the original index and cursor update order.
// Reversing the old raw-cursor updates did not change their emitted order.

#ifndef RMM_BASE_SHARED_CONTEXT
struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Random_Map_Module {
protected:
    char gap_00[0x14];
    long map_width;
    long map_height;
    char gap_1C[0x10];
    Map_Stack** stack_offsets;

    void clear_stack(void);
};
#endif

void RGE_Random_Map_Module::clear_stack(void) {
    int y;
    int x;

    for (y = 0; y < this->map_height; ++y) {
        for (x = 0; x < this->map_width; ++x) {
            this->stack_offsets[y][x].next = 0;
            this->stack_offsets[y][x].prev = 0;
        }
    }
}
