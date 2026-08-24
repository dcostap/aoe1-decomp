// VA: 0046E0B0 TPicture::Load
// Picture.cpp lines 126-197
//
// Attempt log:
// - baseline typed reconstruction matched size/frame/calls but used the wrong
//   late DIB-null block shape (251 differing bytes).
// - inverted the positive DIB guard, inlined the bitmap base plus DIB offset,
//   and used the compression==3 arm first; this reached 5 differing bytes.
// - the remaining five bytes are only VC5 register/address encodings in the
//   two DibCheckTrans argument expressions; direct typed and constructor-donor
//   pointer spellings emitted the same 5-byte result.
// - a four-case focused variant lab (raw/header/base/shifted pointer forms)
//   preserved size/frame/call-set but collapsed to the same code group.
// - tested the Ghidra-derived color-table ownership expressions for both
//   transparency scans; VC5 emitted the same five-byte register drift.
// - reused the natural typed bits pointer for both scan calls; emitted code
//   stayed unchanged.
// - used a typed DIB header alias for the scan addresses; emitted code stayed
//   unchanged.
// - scoped a natural typed transparency bitmap pointer to the allocation-
//   success access lifetime; emitted code stayed unchanged.
// - Allocator-inference probe: splitting the initial bitmap pointer from the
//   post-allocation scan pointer was byte-identical. VC5 coalesces both roles
//   before the remaining ECX/EDX transparency-address choice.
// - Reverse-traced C2's color.c assignment routine at 0x0042F660: the bitmap
//   split shifts later pseudo ids but preserves every assigned color.
// - One shared mutable biSize accumulator gets the desired ECX reuse in both
//   scan arms, but VC5 hoists biSize above the compression test and widens the
//   drift to 39 bytes. Branch-local offset and pointer accumulators collapse
//   to the current five-byte group. The next lead is expression-tree ordering
//   that keeps biSize as the ECX accumulator without moving its load.
// - Exact: assign one transparency pointer in the compression arms, then call
//   DibCheckTrans once after the join. VC5 tail-duplicates the call and return,
//   and coalesces each final address into ECX. This matches all 438 bytes.

#include <stdio.h>
#include <stdlib.h>
#include <io.h>

#ifndef PICTURE_CONTEXT_H
struct tagBITMAPINFOHEADER {
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
};

struct tagRGBQUAD {
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};

struct BITMAPINFO256 {
    tagBITMAPINFOHEADER bmiHeader;
    tagRGBQUAD bmiColors[256];
};

struct TRANSINFO;
#endif

extern unsigned char shape_file_first;
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
tagBITMAPINFOHEADER* __cdecl DibOpenFile(char* name);
int __cdecl RESFILE_Extract_to_File(unsigned long type, unsigned long id,
    char* name, FILE*& file);
void __cdecl DibMapToPalette(tagBITMAPINFOHEADER* dib, void* palette,
    int palette_id, int palette_flags);
void __cdecl DibCheckTrans(BITMAPINFO256* dib, TRANSINFO* info,
    unsigned char* bits);
#ifndef PICTURE_CONTEXT_H
void __cdecl DibFree(tagBITMAPINFOHEADER* dib);
#endif

#ifndef PICTURE_CONTEXT_H
class TPicture {
public:
    tagBITMAPINFOHEADER* Dib;
    BITMAPINFO256* BitmapInfo;
    unsigned char* Bits;
    TRANSINFO* TransInfo;
    int OwnMemory;
    long Width;
    long Height;
    short Orien;

    void Load(char* file_name, long resource_id, int palette_id,
        void* palette, int palette_flags);
};
#endif

void TPicture::Load(char* file_name, long resource_id, int palette_id,
    void* palette, int palette_flags) {
    BITMAPINFO256* bitmap;
    TRANSINFO* info;
    char temp_file_name[260];
    FILE* temp_file;

    debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Picture.cpp", 0x7f);
    this->TransInfo = 0;
    this->OwnMemory = 1;

    if (shape_file_first != 0) {
        this->Dib = DibOpenFile(file_name);
    }

    if (this->Dib == 0 && resource_id != -1) {
        if (RESFILE_Extract_to_File(0x62696e61, resource_id,
            temp_file_name, temp_file) != 0) {
            fclose(temp_file);
            this->Dib = DibOpenFile(temp_file_name);
            _unlink(temp_file_name);
        }
    }

    if (shape_file_first == 0 && this->Dib == 0) {
        this->Dib = DibOpenFile(file_name);
    }

    bitmap = (BITMAPINFO256*)this->Dib;
    if (bitmap != 0) {
        this->BitmapInfo = bitmap;
        unsigned char* bits;
        if (bitmap->bmiHeader.biCompression == 3) {
            bits = (unsigned char*)bitmap +
                bitmap->bmiHeader.biSize + 0xc;
        } else {
            bits = (unsigned char*)bitmap +
                bitmap->bmiHeader.biSize + bitmap->bmiHeader.biClrUsed * 4;
        }
        this->Bits = bits;
        this->Width = bitmap->bmiHeader.biWidth;
        this->Height = bitmap->bmiHeader.biHeight;
        if (this->Height < 0) {
            this->Orien = 1;
            this->Height = -this->Height;
        } else {
            this->Orien = -1;
        }

        if (palette != 0) {
            DibMapToPalette((tagBITMAPINFOHEADER*)bitmap, palette,
                palette_id, palette_flags);
        }
        if (palette_id == 0) {
            return;
        }

        info = (TRANSINFO*)malloc(0x18);
        this->TransInfo = info;
        if (info != 0) {
            bitmap = (BITMAPINFO256*)this->Dib;
            unsigned char* transparency_bits;
            if (bitmap->bmiHeader.biCompression == 3) {
                transparency_bits = (unsigned char*)bitmap +
                    bitmap->bmiHeader.biSize + 0xc;
            } else {
                transparency_bits = (unsigned char*)bitmap +
                    bitmap->bmiHeader.biSize +
                    bitmap->bmiHeader.biClrUsed * 4;
            }
            DibCheckTrans(bitmap, info, transparency_bits);
            return;
        }

        DibFree(this->Dib);
        this->Dib = 0;
        this->BitmapInfo = 0;
    } else {
        this->Dib = 0;
        this->BitmapInfo = 0;
        this->Bits = 0;
        this->TransInfo = 0;
    }

    this->OwnMemory = 0;
    this->Width = 0;
    this->Height = 0;
    this->Orien = 1;
}
