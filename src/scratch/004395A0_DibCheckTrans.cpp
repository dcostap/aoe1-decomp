// VA: 004395A0 DibCheckTrans | Dib.cpp:634-714
// Attempt log:
// - baseline: replaced the decompiler cursor model with typed Win32
//   BITMAPINFO256 plus TRANSINFO/TRANSENTRY ownership; call set, frame, and
//   scan behavior are understood.
// - tried direct bits indexing, width signedness, TU malloc declarations,
//   declaration scope, and typed entry/stride cursors; the clean natural
//   candidate remains the most stable source basin.
// - left in scratch: original saves raw bitmap width in EBX, carries the scan
//   base/entry-offset/register topology differently, and remains non-exact.

#include <windows.h>
#include <stdlib.h>

struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};

struct TRANSENTRY {
    long allTrans;
    long solid;
    long first;
    long last;
};

struct TRANSINFO {
    long anyTrans;
    char gap_04[0x10];
    TRANSENTRY* entries;
};

extern void __cdecl GetDibDim(BITMAPINFO256*, long*, long*, long*);

int __cdecl DibCheckTrans(BITMAPINFO256* dib, TRANSINFO* info,
    unsigned char* bits)
{
    long width;
    long height;
    long orientation;
    long raw_width;

    GetDibDim(dib, &width, &height, &orientation);
    raw_width = dib->bmiHeader.biWidth;
    info->entries = (TRANSENTRY*)malloc(height << 4);
    if (info->entries == 0)
        return 1;

    long tw = 0;
    long y = 0;
    if (height > 0) {
        do {
            long row;
            int all_trans = 1;
            long first = raw_width;

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

            info->entries[y].allTrans = all_trans;
            info->entries[y].solid = solid;
            info->entries[y].first = first;
            info->entries[y].last = last;
            ++y;
        } while (y < height);
    }

    info->anyTrans = tw;
    if (tw == 0)
        free(info->entries);
    return tw;
}
