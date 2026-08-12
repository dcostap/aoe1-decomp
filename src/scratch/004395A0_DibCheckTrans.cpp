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

#include <windows.h>
#include <stdlib.h>

struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};

struct LINEINFO {
    int AllTrans;
    int MidSolid;
    long StartX;
    long EndX;
};

struct TRANSINFO {
    int AnyTrans;
    long x;
    long y;
    long w;
    long h;
    LINEINFO* LineInfo;
};

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
