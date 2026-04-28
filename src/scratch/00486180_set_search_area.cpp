// 00486180 RGE_RMM_Object_Generator::set_search_area
// Source: rmm_obj.cpp lines 206-226. 134 bytes. __thiscall, ret 10h.
//
// Attempt log:
// - probe 1-3: natural C++ with for/do-while loops → 81% diff
//   Core issue: VC5 schedule/register allocation differs from original.
//   Original reads param_1 then param_3 then param_2 (left-to-right for
//   start_x = param_1-param_3). Rebuilt reads param_3 first.
//   Original regs: esi=this, edi=start_x, ecx=start_y, edx=end_x, ebp=end_y
//   Rebuilt regs:  edi=start_x, eax=start_y, esi=end_x, edx=end_y, ecx=this
//   Cascade of register choices → different instruction encoding throughout.
// - variant lab: 3 end_y-order variants all → same 112-byte asm.
//   text_size 112 vs expected 134 → missing ~22 bytes of instructions.
//
// LEFT IN SCRATCH: fundamental VC5 register allocation/scheduling
// differences in param read order. Cannot be forced from pure C++.

class RGE_RMM_Object_Generator {
public:
    char gap_00[0x14];
    long map_width;                      // +0x14
    long map_height;                     // +0x18
    char gap_1C[0x08];
    unsigned char** search_map_rows;     // +0x24

    void set_search_area(long param_1, long param_2, long param_3, unsigned char param_4);
};

void RGE_RMM_Object_Generator::set_search_area(
    long param_1, long param_2, long param_3, unsigned char param_4
) {
    long start_x = param_1 - param_3;
    long start_y = param_2 - param_3;
    long end_x = param_1 + param_3;
    long end_y = param_3 + param_2;

    if (start_x < 0) start_x = 0;
    if (start_y < 0) start_y = 0;
    if (end_x >= this->map_width) end_x = this->map_width - 1;
    if (end_y >= this->map_height) end_y = this->map_height - 1;

    unsigned char** rows = this->search_map_rows;
    unsigned char fill = param_4;

    for (long y = start_y; y <= end_y; y++) {
        if (start_x > end_x) continue;
        long x = start_x;
        do {
            x++;
            rows[y][x - 1] = fill;
        } while (x <= end_x);
    }
}
