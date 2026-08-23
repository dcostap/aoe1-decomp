// VA: 004395A0 DibCheckTrans | Dib.cpp:634-714
// Attempt log:
// - baseline: replaced the decompiler cursor model with typed Win32
//   BITMAPINFO256 plus TRANSINFO/TRANSENTRY ownership; call set, frame, and
//   scan behavior are understood.
// - tried direct bits indexing, width signedness, TU malloc declarations,
//   declaration scope, and typed entry/stride cursors; the clean natural
//   candidate remains the most stable source basin.
// - corrected local ABI evidence shows GetDibDim takes long references and
//   canonical LINEINFO/TRANSINFO fields are the right ownership model, but
//   those changes alone did not move the 333-byte basin.
// - PDB local-order evidence (tw, orientation, y, height, width, raw_width)
//   plus function-scope tw/y and the natural scan-pointer source produced the
//   best current 219-byte emitted basin; this is retained as the clean source.
// - direct bits[row+x], an explicit LINEINFO byte-offset cursor, and widening
//   all_trans changed structure or worsened the match and were rolled back.
// - binary branch layout shows the nonzero scan case is inline and the zero
//   case is the jump arm; changing the first scan predicate to nonzero-first
//   improved the natural source basin from 219 to 197 bytes and made the scan
//   blocks exact. Declaration-order and register-keyword probes did not help.
// - left in scratch: the oracle saves raw bitmap width in EBX, uses a direct
//   EAX scan base with ECX index, and has a different remaining register/
//   entry-offset topology; calls, frame, size, and scan behavior are aligned.
// - tried reading the proven bitmap width before GetDibDim to extend its
//   lifetime; VC5 changed the setup and scan coloring and worsened diff 197
//   to 324, so it was rolled back. The post-call width read remains canonical.
// - new claim probes: raw_width declaration initialization/int type, an int
//   orientation cast, scan declaration order, int height, and long all_trans
//   were codegen duplicates. Direct bits[row+x] with the corrected branch
//   widened the frame to 0x1c; initializing tw/y widened it to 0x18.
// - restored the natural typed candidate; remaining gap is the original EBX
//   save and EAX/ECX scan register topology despite exact calls/frame/size.
// - current claim probes tested raw_width register/int/order/initialization
//   forms, scan update forms, inner declaration order, function-scope flags,
//   LineInfo cursors, and period DIB header context; all returned the same
//   197-byte basin or worsened structure.
// - an ambient declaration sweep of 512 VC5 front-end states produced one
//   emitted group and no exact result; the natural source remains clean.
// - revisit probes tested typed direct indexing, scan-pointer scope and spelling,
//   raw-width aliases and declaration order, narrow index types, sizeof allocation,
//   and typed LINEINFO pointer induction; none improved the 197-byte basin.
// - final local evidence still shows exact calls, frame, size, and scan CFG, but
//   the oracle's EBX width save, EAX scan base, ECX index, and EBP line cursor
//   remain unrecovered without forbidden cursor or register-steering source.
// - revisit claim: the local dossier and type records reconfirmed BITMAPINFO256
//   size 0x428, LINEINFO size 0x10, TRANSINFO::LineInfo at +0x14, and the
//   long-reference GetDibDim ABI. The unchanged typed source rebuilt at 345
//   bytes with the 0x14 frame and all 3 ordered calls, but still differed by
//   197 bytes. The first hunk remains the prologue and register/save topology;
//   no policy-valid natural edit improved it. Keep this clean source paused
//   until period source or new translation-unit evidence becomes available.
// - Accepted drift: GetDibDim receives the same three writable stack
//   addresses. Allocation size, row orientation, scan limits, transparency
//   detection, LINEINFO store order, cleanup, faults, and returns match. No
//   call occurs inside a scan loop. Remaining drift is private register and
//   cursor placement.

#include <windows.h>
#include <stdlib.h>
#include "../../include/dib_context.h"

extern void __cdecl GetDibDim(BITMAPINFO256*, long&, long&, long&);

int __cdecl DibCheckTrans(BITMAPINFO256* dib, TRANSINFO* info,
    unsigned char* bits)
{
    long tw;
    long orientation;
    long y;
    long height;
    long width;
    long raw_width;

    GetDibDim(dib, width, height, orientation);
    raw_width = dib->bmiHeader.biWidth;
    info->LineInfo = (LINEINFO*)malloc(height << 4);
    if (info->LineInfo == 0)
        return 1;

    tw = 0;
    y = 0;
    if (height > 0) {
        do {
            int all_trans = 1;
            long first = raw_width;
            long row;

            if (orientation == 1)
                row = width * y;
            else
                row = (height - y - 1) * width;

            unsigned char* scan = bits + row;
            long x = 0;
            if (raw_width > 0) {
                do {
                    if (scan[x] != 0) {
                        if (all_trans) {
                            all_trans = 0;
                            first = x;
                        }
                    } else if (tw == 0) {
                        tw = 1;
                    }
                    ++x;
                } while (x < raw_width);
            }

            long last = first;
            if (!all_trans) {
                x = first + 1;
                while (x < raw_width) {
                    if (scan[x] != 0)
                        last = x;
                    ++x;
                }
            }

            int solid = 1;
            if (!all_trans) {
                x = first;
                while (x <= last) {
                    if (scan[x] == 0) {
                        solid = 0;
                        break;
                    }
                    ++x;
                }
            }

            info->LineInfo[y].AllTrans = all_trans;
            info->LineInfo[y].MidSolid = solid;
            info->LineInfo[y].StartX = first;
            info->LineInfo[y].EndX = last;
            ++y;
        } while (y < height);
    }

    info->AnyTrans = tw;
    if (tw == 0)
        free(info->LineInfo);
    return tw;
}
