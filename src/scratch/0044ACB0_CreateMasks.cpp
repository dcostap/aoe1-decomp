// PointMaker::CreateMasks
// VA: 0044ACB0 - Creates distance-based mask patterns
//
// Attempt log:
// - Restored the binary-proven four mask-pointer fields at +0xFA8..+0xFB4 and
//   the natural 4x4/5x5/6x6/7x7 distance-mask ownership.
// - A local ptr2 plus four dword copies is required for the correct frame and
//   copy semantics; direct byte writes and compact/partial ptr2 layouts were
//   rejected by the frame/copy evidence.
// - Full natural byte initializers reproduce the correct prologue, frame, call
//   set, mask values, and most local-store topology.  Remaining drift is the
//   VC5 scheduling of late zero/interior stores and the Mask_2x2 copy hunk;
//   best retained source is the direct typed dword-copy form below.

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
    
    char ptr2[16] = {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0};
    char ptr3[25] = {0,0,0,0,0,0,1,1,1,0,0,1,2,1,0,0,1,1,1,0,0,0,0,0,0};
    char ptr4[36] = {
        0,0,0,0,0,0,0,1,1,1,1,0,0,1,2,2,1,0,0,1,2,2,1,0,0,1,1,1,1,0,
        0,0,0,0,0,0
    };
    char ptr5[49] = {
        0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,2,2,2,1,0,0,1,2,3,2,1,0,0,
        1,2,2,2,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0
    };
    
    // Copy 2x2 pattern to mask.
    *(int*)(Mask_2x2 + 0) = *(int*)(ptr2 + 0);
    *(int*)(Mask_2x2 + 4) = *(int*)(ptr2 + 4);
    *(int*)(Mask_2x2 + 8) = *(int*)(ptr2 + 8);
    *(int*)(Mask_2x2 + 12) = *(int*)(ptr2 + 12);
    
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
