// ACCEPTED_DRIFT: reviewed 2026-05-26 by orchestrator. Exact size; nonzero diff is localized to the mirrored-transform block where rebuilt reuses the just-stored index value in EAX instead of reloading it through the output reference into ESI. Store order, final index value, return value, branch predicates, and alias-visible field loads remain equivalent; trailing NOPs only compensate the shorter encoding.
// VA: 004C00E0 RGE_Sprite::get_facetindex
// PDB source: sprite.cpp
// Attempt log:
// v0 direct decompiler-shaped source: unsigned char mirror local spills to stack.
// v1 unsigned int mirror avoids spill but adds xor eax,eax and wrong tail ordering/size.
// v2 direct member tests: fixed prologue, remaining branch/register/tail shape.
// v3 compare operand/order probes fixed cmp edx,esi / cmp edx,eax and late mirror/nonmirror tail order; best result 12.43% edit diff, first mismatch only branch displacement at +0x28 because rebuilt mirrored-transform block is 4 bytes shorter.
// Tried: unsigned-char mirror local (stack spill), unsigned-int/int/long mirror (xor eax or size miss), direct member tests (best), pointer-param and local output-pointer aliases, ref aliases, volatile output reloads (bad: changes AL/EDX mirror register from offset 1), split/combined arithmetic for (half-facet)+facet_num, self-assign/add-zero/never-if reload blockers, vc5-small flag preset and /Od. No exact.
// Give-up: remaining best drift is localized to mirrored-transform block: VC5 optimizes away original store/reload through output reference (`mov esi,[edx]`) and computes in EAX, making the block 4 bytes shorter; subsequent mirrored/nonmirrored tails are behaviorally equivalent but shifted. Leaving in scratch, not proposing accepted_drift without review.

#include "..\..\include\sprite_context.h"

unsigned char RGE_Sprite::get_facetindex(long facet, long frame, long& index) {
    if (this->mirror_flag != 0 && this->facet_num == 2) {
        index = frame;
        return (unsigned char)facet;
    }

    if (this->mirror_flag != 0 && (facet > (long)(unsigned int)this->mirror_flag || facet < ((int)this->facet_num >> 2))) {
        int i = (int)this->facet_num >> 1;
        if (facet > i) {
            i = i - facet;
            i = i + (int)this->facet_num;
        } else {
            i = i - facet;
        }
        index = i;
        int tmp = index;
        index = (tmp - ((int)this->facet_num >> 2)) * (int)this->frame_num + frame;
        return 1;
    }

    if (this->mirror_flag != 0) {
        index = (facet - ((int)this->facet_num >> 2)) * (int)this->frame_num + frame;
        return 0;
    }

    index = (int)this->frame_num * facet + frame;
    return 0;
}
