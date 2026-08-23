#ifndef DIB_CONTEXT_H
#define DIB_CONTEXT_H

#include <windows.h>

// BINARY NOTE: Dib.cpp uses a 256-entry RGBQUAD tail after the Win32
// BITMAPINFOHEADER. The complete surface is 0x428 bytes.
#define DIB_BITMAP_INFO_256_DEFINED
struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};

// BINARY NOTE: These names describe one 0x10-byte transparency line. The
// shipped code uses the same offsets with both the DIB and blit vocabularies.
struct LINEINFO {
    union { int AllTrans; int skip; };
    union { int MidSolid; int copy; };
    union { long StartX; long first; };
    union { long EndX; long last; };
};

struct TRANSINFO {
    int AnyTrans;
    long x;
    long y;
    long w;
    long h;
    LINEINFO* LineInfo;
};

typedef unsigned char uchar;

extern long SrcXTbl[];

typedef char dib_bitmap_info_256_size_check[(sizeof(BITMAPINFO256) == 0x428) ? 1 : -1];
typedef char dib_line_info_size_check[(sizeof(LINEINFO) == 0x10) ? 1 : -1];
typedef char dib_trans_info_line_offset_check[(sizeof(TRANSINFO) == 0x18) ? 1 : -1];

#endif
