// PointMaker::CreateMasks
// VA: 0044ACB0 - Creates distance-based mask patterns
//
// Attempt log:
// - Restored the binary-proven four mask-pointer fields at +0xFA8..+0xFB4 and
//   the natural 2x2/3x3/4x4/5x5 distance-mask ownership.
// - A local ptr2 plus four dword copies is required for the correct frame and
//   copy semantics; direct byte writes and compact/partial ptr2 layouts were
//   rejected by the frame/copy evidence.
// - Full natural byte initializers reproduce the correct prologue, frame, call
//   set, mask values, and most local-store topology.  Remaining drift is the
//   VC5 scheduling of late zero/interior stores and the Mask_2x2 copy hunk;
//   best retained source is the direct typed dword-copy form below.
// - Tried natural typed explicit assignments in the fractal donor's emitted
//   stack order with an early Mask_2x2 capture; size moved 34 bytes closer but
//   the first hunk moved earlier and the strict diff grew from 370 to 415.
//   Restored the aggregate initializer source.
// - Reasserting omitted border-zero stores moved the mismatch from 370 to 383
//   without moving the first structural hunk; restored the clean source.
// - Full ordered assignments and shared loop locals stayed in the same 370-byte
//   basin. Zero-initializing then filling interiors collapsed the body to 499.
// - A typed Mask_2x2 destination pointer reduced the body to 737 bytes and
//   improved resync similarity, but strict diff grew to 372; restored clean.
//   The remaining lead is VC5 ordering of late zero/interior stores.
// - Split each aggregate initializer into row-sized source lines, following
//   the original PDB's row-like line bands while keeping flat typed arrays.
//   This moved the first mismatch earlier and worsened the strict diff to 376;
//   restored the clean aggregate source.
// - Natural fixed-size memcpy calls for only the 3x3/4x4/5x5 arrays reached
//   97 differing bytes but left the 2x2 copy schedule wrong.  Using memcpy for
//   all four arrays reproduces VC5's direct 16-byte dword lowering and the
//   target's late-store schedule.  The authoritative check is an exact MATCH.

#include <string.h>

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
    Mask_2x2 = new char[16];
    Mask_3x3 = new char[25];
    Mask_4x4 = new char[36];
    Mask_5x5 = new char[49];
    
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
    
    // Copy the mask patterns.
    memcpy(Mask_2x2, ptr2, sizeof(ptr2));
    
    memcpy(Mask_3x3, ptr3, sizeof(ptr3));
    memcpy(Mask_4x4, ptr4, sizeof(ptr4));
    memcpy(Mask_5x5, ptr5, sizeof(ptr5));
}
