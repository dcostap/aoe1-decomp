// 004BE850 TSpan_List_Manager::ScrollSpansVertically
// Source: spanlist.cpp lines 1617-1710
// attempt log:
// attempt 1: natural decompiler-shaped vertical scroll; close overall but stack slots for lower/upper bounds reversed.
// attempt 2: parameter-slot mutation got bound slots right but VC5 emitted branchy abs and shifted the function.
// attempt 3: <stdlib.h>/abs with mutation produced cdq abs but moved param load before callee-save pushes.
// attempt 4: extern abs behaved the same intrinsic/prologue way as <stdlib.h>.
// attempt 5: reverted to local bounds plus abs(dy); best parity so far, edit diff ~48B, behavior-shaped.
// attempt 6: parameter mutation plus manual branch abs fixed bound slots but left 5B abs expansion and shifted later code.
// attempt 7: explicit sign local (scroll >> 31) emitted sar/mov/xor/sub family and changed free-loop register allocation.
// attempt 8: <stdlib.h> vs extern abs made no difference in the best local-bound shape.
// attempt 9: swapping clear_first/clear_last declaration order made no codegen difference.
// attempt 10: spelling the first walk as a for-loop made no codegen difference.
// current pass: assigning the lower range to clear_first and upper range to
// use_regions matches the original parameter homes and aligns the first 0xC4
// bytes; direct late reuse of use_regions, end_index delays, and register
// declarations did not remove the remaining 4-byte late branch drift.
// - The standard stdlib context was neutral. Computing the negative-direction
//   bounds directly from Num_Lines (rather than through clear_last) aligned the
//   complete 394-byte structure; final-loop/operand/home variants were neutral.
// - Remaining drift is exactly the final two bound reload encodings (4 bytes):
//   original loads clear_first then clear_last, rebuilt reverses those loads.
// - This pass tested named final bounds, direct parameter homes, direct and
//   guarded loop forms, increment spelling, line-bound reuse, and a focused
//   natural-shape lab; every form stayed at 4 bytes.
// - Same-TU AddLine_Align confirms the period typed public span-node base,
//   inherited manager surface, and stdlib context. The full typed base here
//   is retained; it emits the pinned 394-byte result without raw ownership.
// - Reusing the existing line local in the final clear loop while preserving
//   clear_first and clear_last emitted identical code (4-byte diff, first +013C); restored clean source.
// left in scratch: remaining drift is codegen/source-shape around preserving original dy while mutating bound params,
// plus VC5 abs lowering/register allocation; no inline asm used.

extern "C" int __cdecl abs(int);

#ifndef SPANLIST_SHARED_CONTEXT
struct VSpan_Node;

// Main-agent audit confirmed canonical span-list ownership and retained the
// corrected lower/upper bound semantics and natural vertical scroll.
#include <stdlib.h>

class TSpan_Node_List {
public:
    char gap_00[0x3C];
    int FreeThread(VSpan_Node* first, VSpan_Node* second);
};

class TSpan_List_Manager : public TSpan_Node_List {
public:
    VSpan_Node** Line_Head_Ptrs; // +0x3C
    VSpan_Node** Line_Tail_Ptrs; // +0x40
    int* LeftMostPx;             // +0x44
    int* RightMostPx;            // +0x48
    int* Span_Count;             // +0x4C
    int Num_Lines;               // +0x50
    int Num_Pixels;              // +0x54
    int Min_Span_Px;             // +0x58
    int Max_Span_Px;             // +0x5C
    int Min_Line;                // +0x60
    int Max_Line;                // +0x64

    void ResetAll();
    void ScrollSpansVertically(int dy, int use_regions);
};
#endif

void TSpan_List_Manager::ScrollSpansVertically(int dy, int use_regions)
{
    int line;
    int src_line;
    int step;
    int clear_first;
    int clear_last;

    if (dy == 0) {
        return;
    }

    if (use_regions != 0) {
        clear_first = this->Min_Line;
        use_regions = this->Max_Line;
    } else {
        clear_first = 0;
        use_regions = this->Num_Lines - 1;
    }

    if (abs(dy) > use_regions - clear_first) {
        this->ResetAll();
        return;
    }

    line = 0;
    src_line = dy;
    while (line < this->Num_Lines) {
        if (this->Line_Head_Ptrs[line] != 0) {
            if (src_line < clear_first || src_line > use_regions) {
#ifdef SPANLIST_SHARED_CONTEXT
                this->VSList.FreeThread(this->Line_Head_Ptrs[line], this->Line_Tail_Ptrs[line]);
#else
                this->FreeThread(this->Line_Head_Ptrs[line], this->Line_Tail_Ptrs[line]);
#endif
                this->Line_Head_Ptrs[line] = 0;
                this->Line_Tail_Ptrs[line] = 0;
                this->Span_Count[line] = 0;
                this->LeftMostPx[line] = 0;
                this->RightMostPx[line] = 0;
            }
        }
        line++;
        src_line++;
    }

    if (dy > 0) {
        src_line = this->Num_Lines - dy - 1;
        line = 0;
        step = -1;
        clear_first = 0;
        clear_last = dy - 1;
    } else {
        src_line = dy;
        step = 1;
        clear_first = this->Num_Lines - dy;
        line = this->Num_Lines - 1;
        clear_last = this->Num_Lines;
    }

    line += step;
    if (src_line != line) {
        do {
            this->Line_Head_Ptrs[src_line + dy] = this->Line_Head_Ptrs[src_line];
            this->Line_Tail_Ptrs[src_line + dy] = this->Line_Tail_Ptrs[src_line];
            this->Span_Count[src_line + dy] = this->Span_Count[src_line];
            this->LeftMostPx[src_line + dy] = this->LeftMostPx[src_line];
            this->RightMostPx[src_line + dy] = this->RightMostPx[src_line];
            src_line += step;
        } while (src_line != line);
    }

    if (clear_first <= clear_last) {
        for (; clear_first <= clear_last; clear_first++) {
            this->Line_Head_Ptrs[clear_first] = 0;
            this->Line_Tail_Ptrs[clear_first] = 0;
            this->Span_Count[clear_first] = 0;
            this->LeftMostPx[clear_first] = 0;
            this->RightMostPx[clear_first] = 0;
        }
    }
}
