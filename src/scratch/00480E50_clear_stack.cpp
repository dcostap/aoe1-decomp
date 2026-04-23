// tried the straightforward nested-loop zeroing shape first
// tried pointer-temp and late-init variants; mismatch stayed in the inner-loop register basin
// remaining drift is the `add eax,18h` / `inc edx` ordering and the associated register assignment

class Map_Stack;

class RGE_Random_Map_Module {
public:
    char gap_00[0x14];
    long map_width;
    long map_height;
    char gap_1C[0x10];
    Map_Stack** stack_offsets;

    void clear_stack(void);
};

void RGE_Random_Map_Module::clear_stack(void) {
    int y;
    int offset;
    int x;

    y = 0;
    if (0 < this->map_height) {
        do {
            x = 0;
            if (0 < this->map_width) {
                offset = 0;
                do {
                    offset += 0x18;
                    ++x;
                    *(int*)((char*)this->stack_offsets[y] + offset - 8) = 0;
                    *(int*)((char*)this->stack_offsets[y] + offset - 4) = 0;
                } while (x < this->map_width);
            }
            ++y;
        } while (y < this->map_height);
    }
}
