// VA: 004C0960 RGE_Sprite::get_frame (514B)
// PDB source: sprite.cpp, lines 711-759
// EH frame (/GX)
// Attempt log:
// - Replaced the old field-only scaffold with the natural lazy-shape load,
//   bounding-box fast path, and transparent draw-list aggregation recovered
//   from the executable.  Baseline: exact frame/prologue/calls, 533-byte
//   rebuild versus 514 bytes, 157 strict differing bytes.
// - Count-guard, shared-return, positive-gate, and short-count variants did
//   not improve the structural basin; direct typed list access preserved the
//   same code while the explicit unsigned transparent > 0 spelling improved
//   block/edit diagnostics by one byte.
// - Final clean source retains named RGE_Picture_List ownership and natural
//   member calls.  Remaining drift is the outer draw-list guard spelling and
//   late argument evaluation/block layout; no call-set or frame mismatch.
// - Continuation: <= 0 and negated-positive outer count guards compiled to a
//   direct memory compare or a larger structural basin; neither reproduced
//   the original test-AX/jle sequence.
// - Shared-result/goto and single-break-loop return forms did not retain the
//   original shared epilogue; receiver/offset locals were codegen-neutral.
// - A split raw record cursor/count variant was worse (275-byte diff), so it
//   was discarded.  Restored final natural typed source: 157-byte diff,
//   exact frame/call set, with the remaining guard, tail, and argument-order
//   drift documented for the next worker.
// Worker pass sprite-sa-0aea9221-0960: retested the binary-looking outer
// `draw_list_num <= 0` spelling; it moved to a 237-byte structural basin.
// Restored the natural typed `< 1` source; next lead is a source/context form
// that preserves the test-AX/jle guard without disturbing the EH tail.
// TU-group pass (tu-sprite-C0960): nonzero and reversed-operand inner count
// guards stayed in the 157-byte basin. Restored the natural typed EH source;
// the test-AX/jle guard and typed entry scheduling remain unresolved.
// Shard E pass: outer `draw_list_num <= 0` plus a natural for loop reproduced
// the oracle test-AX/jle gate and exact frame/call set. Repeated direct
// `draw_list[i]` member expressions improved the typed entry basin to 92 bytes.
// Binary parameter-home evidence corrected the child call to scale `frame`
// and pass `facet`; the current natural candidate reaches 90-byte diff,
// 94.74% shape, and 93.29% exact-block coverage. Remaining drift is the
// shared zero-return/tail layout; no call-set or frame mismatch remains.
// Revisit pass (sa-bb41bd2f-r1): 20 focused probes covered result locals and
// parameter reuse, positive and negative box/output guards, explicit labels,
// for/while/do-while loops, and stdio context. All natural forms either
// reproduced the 90-byte basin or moved farther. The original has a separate
// success block (`mov eax,1`) before EH cleanup; the clean source still emits
// that constant in the cleanup epilogue. No call, frame, width, or ownership
// issue remains. Next lead: recover the original source CFG or TU context that
// forces the success value before the shared EH tail.
// Accepted-drift review: the first 444 bytes and all nine calls match. The
// rebuild duplicates the zero-return epilogue and sets the success value inside
// its other epilogue. Both paths restore the same EH chain and return the same
// value. The success path writes the same four outputs in the same order. No
// call, object access, or output access occurs in the changed epilogue code.
// Exact translation-unit finish: the real earlier sprite.cpp owner at 004BFFE0
// selects the original shared EH tail. The unchanged natural body then matches
// all 514 bytes and nine calls. Target-only compilation emits the reviewed
// duplicated-return drift.

#include "../../include/sprite_context.h"

extern void __cdecl addstring(char** dst, char* base, char* ext);
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern "C" void __cdecl free(void* block);

int RGE_Sprite::get_frame(short& min_x, short& min_y, short& max_x,
                          short& max_y, long frame, long facet)
{
    char* fname;

    if (this->shape == 0) {
        if (this->loaded != 0) {
            fname = 0;
            addstring(&fname, this->pict_name, ".shp");
            unsigned long start =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x2d2);
            TShape* shape = new TShape(fname, this->resource_id);
            this->shape = shape;
            unsigned long stop =
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\sprite.cpp", 0x2d4);
            rge_base_game->add_to_timing(0x0b, stop - start);
            free(fname);
        } else {
            return 0;
        }
    }

    if (((this->box_x1 == 0) && (this->box_x2 == 0)) ||
        ((this->box_y1 == 0) && (this->box_y2 == 0))) {
        min_x = 0;
        min_y = 0;
        max_x = 0;
        max_y = 0;

        if ((this->draw_list_num <= 0) || (this->draw_list == 0)) {
            this->get_frame_min_max(min_x, min_y, max_x, max_y,
                                    frame, facet, 0, 0);
        } else {
            for (int i = 0; i < this->draw_list_num; ++i) {
                if (this->transparent_picking_flag > 0) {
                    this->draw_list[i].sprite->get_frame_min_max(
                        min_x, min_y, max_x, max_y,
                        (this->draw_list[i].sprite->facet_num * frame) /
                            this->facet_num,
                        facet,
                        this->draw_list[i].offset_x,
                        this->draw_list[i].offset_y);
                }
            }
        }

        if (((min_x == 0) && (max_x == 0)) ||
            ((min_y == 0) && (max_y == 0))) {
            return 0;
        }
    } else {
        min_x = this->box_x1;
        min_y = this->box_y1;
        max_x = this->box_x2;
        max_y = this->box_y2;
    }

    return 1;
}
