// attempt 1: register usage differs, rebuilt uses lea edx instead of add eax
// attempt 2: better reg usage but loop counter in edi, table in ebx
// attempt 3: hoist table load, counter in ebx now
// attempt 4: do/while loop, same reg alloc
// left in scratch: VC5 picks different registers (ebx counter, ebx/edx for FPU addr)
// original uses esi for counter, edi for table base, edx for FPU addr
// behavior fully correct, size matches (82 bytes), benign codegen drift

class TRIBE_Player {
public:
    char gap_00[0x24];
    void* obj_table;
    char gap_28[0x28];
    float* resource_cost_table;

    void reimburse_obj_cost(short obj_idx);
};

void TRIBE_Player::reimburse_obj_cost(short obj_idx) {
    void* obj_ptr = ((void**)obj_table)[obj_idx];
    if (*(unsigned char*)((char*)obj_ptr + 4) < 0x46) return;
    float* table = resource_cost_table;
    void* p = (char*)obj_ptr + 0x148;
    int i = 3;
    do {
        short res_id = *(short*)p;
        short amount = *(short*)((char*)p + 2);
        unsigned char flag = *(unsigned char*)((char*)p + 4);
        if (res_id >= 0 && flag != 0) {
            table[res_id] += (float)amount;
        }
        p = (char*)p + 6;
        i--;
    } while (i != 0);
}
