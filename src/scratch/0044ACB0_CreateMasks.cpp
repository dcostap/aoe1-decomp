// PointMaker::CreateMasks
// VA: 0044ACB0 - Creates distance-based mask patterns

void* __cdecl operator_new(unsigned int size);

class PointMaker {
public:
    char gap_000[0xFA8];
    char* Mask_2x2;
    char* Mask_3x3;
    char* Mask_4x4;
    char* Mask_5x5;

    void CreateMasks();
};

void PointMaker::CreateMasks() {
    Mask_2x2 = (char*)operator_new(16);
    Mask_3x3 = (char*)operator_new(25);
    Mask_4x4 = (char*)operator_new(36);
    Mask_5x5 = (char*)operator_new(49);
    
    // 3x3 pattern (5x5 grid = 25 bytes)
    char ptr3[25];
    {
        int ii;
        for (ii = 0; ii < 10; ii++) ptr3[ii] = 0;
    }
    ptr3[10] = 1; ptr3[11] = 1; ptr3[12] = 1;
    ptr3[13] = 0; ptr3[14] = 0;
    ptr3[15] = 1; ptr3[16] = 2; ptr3[17] = 1;
    ptr3[18] = 0; ptr3[19] = 0;
    ptr3[20] = 1; ptr3[21] = 1; ptr3[22] = 1;
    ptr3[23] = 0; ptr3[24] = 0;
    
    // 4x4 pattern (6x6 grid = 36 bytes)
    char ptr4[36];
    {
        int ij;
        for (ij = 0; ij < 36; ij++) ptr4[ij] = 0;
    }
    ptr4[11] = 1; ptr4[12] = 1; ptr4[13] = 1; ptr4[14] = 1;
    ptr4[15] = 0; ptr4[16] = 0;
    ptr4[17] = 1; ptr4[18] = 2; ptr4[19] = 2; ptr4[20] = 1;
    ptr4[21] = 0; ptr4[22] = 0;
    ptr4[23] = 1; ptr4[24] = 2; ptr4[25] = 2; ptr4[26] = 1;
    ptr4[27] = 0; ptr4[28] = 0;
    ptr4[29] = 1; ptr4[30] = 1; ptr4[31] = 1; ptr4[32] = 1;
    ptr4[33] = 0; ptr4[34] = 0; ptr4[35] = 0;
    
    // 5x5 pattern (7x7 grid = 49 bytes)
    char ptr5[49];
    {
        int ik;
        for (ik = 0; ik < 49; ik++) ptr5[ik] = 0;
    }
    ptr5[11] = 1; ptr5[12] = 1; ptr5[13] = 1; ptr5[14] = 1; ptr5[15] = 1;
    ptr5[16] = 0; ptr5[17] = 0;
    ptr5[18] = 0; ptr5[19] = 0;
    ptr5[20] = 0; ptr5[21] = 0;
    ptr5[22] = 1; ptr5[23] = 2; ptr5[24] = 2; ptr5[25] = 2; ptr5[26] = 1;
    ptr5[27] = 0; ptr5[28] = 0;
    ptr5[29] = 1; ptr5[30] = 2; ptr5[31] = 3; ptr5[32] = 2; ptr5[33] = 1;
    ptr5[34] = 0; ptr5[35] = 0;
    ptr5[36] = 1; ptr5[37] = 2; ptr5[38] = 2; ptr5[39] = 2; ptr5[40] = 1;
    ptr5[41] = 0; ptr5[42] = 0;
    ptr5[43] = 1; ptr5[44] = 1; ptr5[45] = 1; ptr5[46] = 1; ptr5[47] = 1;
    ptr5[48] = 0;
    
    // Fill 2x2 mask (4x4 = 16 bytes)
    Mask_2x2[0] = 0;  Mask_2x2[1] = 0;  Mask_2x2[2] = 0;  Mask_2x2[3] = 0;
    Mask_2x2[4] = 0;  Mask_2x2[5] = 1;  Mask_2x2[6] = 1;  Mask_2x2[7] = 0;
    Mask_2x2[8] = 0;  Mask_2x2[9] = 1;  Mask_2x2[10] = 1; Mask_2x2[11] = 0;
    Mask_2x2[12] = 0; Mask_2x2[13] = 0; Mask_2x2[14] = 0; Mask_2x2[15] = 0;
    
    // Copy 3x3 pattern to mask
    {
        int i3;
        char* psrc3 = ptr3;
        char* pdst3 = Mask_3x3;
        for (i3 = 6; i3 != 0; i3--) {
            *(int*)pdst3 = *(int*)psrc3;
            psrc3 += 4;
            pdst3 += 4;
        }
        Mask_3x3[24] = ptr3[24];
    }
    
    // Copy 4x4 pattern to mask
    {
        int i4;
        char* psrc4 = ptr4;
        char* pdst4 = Mask_4x4;
        for (i4 = 9; i4 != 0; i4--) {
            *(int*)pdst4 = *(int*)psrc4;
            psrc4 += 4;
            pdst4 += 4;
        }
    }
    
    // Copy 5x5 pattern to mask
    {
        int i5;
        char* psrc5 = ptr5;
        char* pdst5 = Mask_5x5;
        for (i5 = 12; i5 != 0; i5--) {
            *(int*)pdst5 = *(int*)psrc5;
            psrc5 += 4;
            pdst5 += 4;
        }
        Mask_5x5[48] = ptr5[48];
    }
}
