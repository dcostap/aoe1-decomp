// 0043A660 DibMapToPalette
// Dib.cpp
// Attempt log:
// - Baseline established typed DIB ownership, palette lookup/remap, compression dispatch,
//   and the final palette-entry rewrite; the first build was missing the DIB resize path.
// - Replaced direct stdcall declarations with the IAT function-pointer surface and
//   corrected the packet ABI to four arguments (one handle is both bitmap/palette).
// - Added the binary-proven grow/shrink paths: GlobalHandle/GlobalUnlock,
//   GlobalReAlloc/GlobalLock, and the memmove/memcpy image preservation calls.
// - Restored the original positive null-test order, header color-count ownership, and
//   BI_BITFIELDS/non-BI bits offsets; the current frame/code shape is close but nonexact.
// - Kept the natural one-call transparent search and separate transparent/nontransparent
//   table branches after the executable showed that the raw nearest-index zero is not
//   replaced by zeroIndex on the nontransparent path.
// - Moved the binary-proven grow-branch memmove before compression dispatch; this
//   restores the original ordered 21-call surface and improves the structural diff.
// - Replaced the initial bits-address ternary with the explicit BI_BITFIELDS branch
//   used by the neighboring Dib.cpp donors; this improves the diff from 942 to 911.
// - Typed SizeImage as the packet-proven unsigned DWORD; VC5 emitted the same code,
//   so the source-backed type correction is retained without a metric change.
// - Reversed the palette-flags branch: the original takes the zero-index path
//   when flags are nonzero and reads the bottom-row byte otherwise; diff improved
//   from 911 to 910 bytes and the branch opcode now matches.
// - R3 tested the packet's dword HitEnd local. Moving its initialization into
//   the transparent-search block restored the 0x128 frame and improved shape,
//   but positional diff worsened; the clean BYTE/prologue form is retained.
// - R3 tested the exact Dib.cpp header context. It split the common memmove
//   into two calls and was rolled back; the custom IAT surface remains required.
// - R3 tested the one-state do/while transparent search suggested by the
//   HitEnd/zeroIndex branches. It shortened the function and worsened shape.
// - Focused probes confirmed that the DWORD image-size formula needs unsigned
//   width/bit-depth operands, while local-order and loop-state variants did not
//   improve the clean result.
// - The original table lookup uses the Windows COLORREF order: red low, green
//   middle, blue high. Keep that byte order even when compiler output is unchanged.
// - A later structural pass recovered the dword transparent-search state before
//   the byte translation table. This restored the 0x128 frame, the dword zero/one
//   stores at the table prefix, and the original 337-instruction count.
// - Narrowing the transparent palette index to BYTE restored the test-based
//   entry prologue, 21 ordered calls, and several early exact blocks.
// - The explicit nPalColors shift-or-header branch and branch-local GlobalHandle
//   cache are retained because their emitted stores and IAT loads match the
//   original topology better than the simpler forms.
// - Tested but rejected: a union or dword overlay for the final palette-entry
//   output, a positive transparent table branch with a do-while scan, declaration
//   pointer initialization, and four separate byte stores for the table prefix.
//   These changed the frame, block coverage, or code size in the wrong direction.
// BINARY NOTE: the shipped function has a 0x128 frame and a dword transparent-search
// state. The current source models both facts with a separate searchState local.
// BINARY NOTE: the grouped Dib.cpp context uses the period Win32
// BITMAPINFOHEADER, RGBQUAD, PALETTEENTRY, GDI, and Global* declarations.
// This removes same-name overlays that cannot coexist with the canonical SDK.
// Current structural frontier: 921 differing bytes (85.46% shape, 21/21 ordered
// calls, frame 0x128, code size 1025 vs 1017); remaining drift is mostly address
// formation, branch layout, and register topology.
// - Module probe: the canonical Win32 owner surface keeps the 0x128 frame and
//   21 ordered calls. The isolated check is 926 bytes / 1027 bytes; the grouped
//   wrapper is 879 bytes / 1026 bytes. The three prior exact anchors remain
//   exact in the grouped object.
// - Continuation probes tested DIB base pointer spellings, FAR and macro type
//   surfaces, local declaration order, color initialization order, and a
//   natural shared resize-copy tail. The pointer and declaration variants were
//   codegen duplicates. The copy-tail variant reached 910 differing bytes but
//   introduced a second memmove call and lost the 0x128/21-call structure, so
//   it was restored.

#include <windows.h>

#define DIB_RGB(r, g, b) ((DWORD)(BYTE)(r) | ((DWORD)(BYTE)(g) << 8) | ((DWORD)(BYTE)(b) << 16))
#include <string.h>

#pragma function(memcpy)
#pragma function(memmove)
static void __cdecl xlatRle4(BYTE*, unsigned long, BYTE*);
void __cdecl xlatRle8(BYTE*, int, BYTE*);
static void __cdecl xlatClut8(BYTE*, unsigned long, BYTE*);
void __cdecl xlatClut4(BYTE*, unsigned int, BYTE*);

void DibMapToPalette(BITMAPINFOHEADER* bih, void* hbm, int transparent, int zero) {
    BYTE* bits;
    int nDibColors=0;
    BYTE zeroIndex=0;
    DWORD sizeImage;
    int nPalColors;
    PALETTEENTRY pe;
    RGBQUAD* rgb;
    int zeroBlue;
    BYTE hitEnd=0;
    int searchState=0;
    BYTE table[256];
    int i;

    if (hbm != 0 && bih != 0) {
    rgb = (RGBQUAD*)((BYTE*)bih + bih->biSize);
    GetObjectA(hbm, 4, &nDibColors);
    if (bih->biClrUsed == 0 && bih->biBitCount <= 8)
        nPalColors = 1 << bih->biBitCount;
    else
        nPalColors = bih->biClrUsed;
    sizeImage = bih->biSizeImage;
    if (!sizeImage) sizeImage = ((((DWORD)bih->biWidth * (DWORD)bih->biBitCount + 31) >> 3) & 0x1ffffffc) * bih->biHeight;
    if (bih->biCompression == 3)
        bits = (BYTE*)bih + bih->biSize + 12;
    else
        bits = (BYTE*)bih + bih->biSize + nPalColors * 4;

    if (transparent) {
        if (zero)
            hitEnd = 0;
        else
            hitEnd = bits[((bih->biWidth + 3) & ~3) * (bih->biHeight - 1)];

        int r=rgb->rgbRed, g=rgb->rgbGreen;
        zeroBlue=rgb->rgbBlue;
        int dir=1;
        searchState=0;
        do {
            r += dir;
            g += dir;
            zeroBlue += dir;
            if (r>255 || g>255 || zeroBlue>255 || r<0 || g<0 || zeroBlue<0) {
                if (searchState)
                    break;
                dir = -1;
                zeroBlue=rgb->rgbBlue;
                g=rgb->rgbGreen;
                r=rgb->rgbRed;
                searchState=1;
            }
            zeroIndex = (BYTE)GetNearestPaletteIndex(hbm,
                DIB_RGB(r, g, zeroBlue));
        } while (zeroIndex == 0);
    }
    if (0 < nPalColors) {
        BYTE* p = (BYTE*)rgb + 2;
        for (i=0;i<nPalColors;i++, p += 4) {
        if (!transparent) {
            table[i] = (BYTE)GetNearestPaletteIndex(hbm,
                DIB_RGB(p[-2], p[-1], p[0]));
        } else if (i == (BYTE)hitEnd) {
            table[i] = 0;
        } else {
            BYTE v=(BYTE)GetNearestPaletteIndex(hbm,
                DIB_RGB(p[-2], p[-1], p[0]));
            table[i] = v;
            if (v == 0) table[i] = zeroIndex;
        }
        }
    }
    bih->biClrUsed = nDibColors;
    BYTE* oldBits = bits;
    if (nPalColors < nDibColors) {
        void* (__stdcall *getHandle)(const void*) = GlobalHandle;
        GlobalUnlock(getHandle(bih));
        GlobalLock(GlobalReAlloc(getHandle(bih),
            bih->biSize + nDibColors * 4 + sizeImage, 0));

        if (bih->biCompression == 3) {
            bits = (BYTE*)bih + bih->biSize + 12;
        }
        else
            bits = (BYTE*)bih + bih->biSize + bih->biClrUsed * 4;
        memmove(bits, oldBits, sizeImage);
        if (bih->biCompression == 3)
            bits = (BYTE*)bih + bih->biSize + 12;
        else
            bits = (BYTE*)bih + bih->biSize + bih->biClrUsed * 4;
    } else if (nPalColors > nDibColors) {
        if (bih->biCompression == 3) {
            bits = (BYTE*)bih + bih->biSize + 12;
        }
        else
            bits = (BYTE*)bih + bih->biSize + bih->biClrUsed * 4;
        memcpy(bits, oldBits, sizeImage);
        void* (__stdcall *getHandle)(const void*) = GlobalHandle;
        GlobalUnlock(getHandle(bih));
        GlobalLock(GlobalReAlloc(getHandle(bih),
            bih->biSize + nDibColors * 4 + sizeImage, 0));
        if (bih->biCompression == 3)
            bits = (BYTE*)bih + bih->biSize + 12;
        else
            bits = (BYTE*)bih + bih->biSize + bih->biClrUsed * 4;
    }
    switch (bih->biCompression) {
    case 0: if (bih->biBitCount==8) xlatClut8(bits,sizeImage,table); else xlatClut4(bits,sizeImage,table); break;
    case 1: xlatRle8(bits,sizeImage,table); break;
    case 2: xlatRle4(bits,sizeImage,table); break;
    }
    i=0;
    if (i < nDibColors) {
        BYTE* p = (BYTE*)rgb + 1;
        do {
            GetPaletteEntries(hbm,i,1,&pe);
            ++i;
            p[1]=pe.peRed;
            p[0]=pe.peGreen;
            p[-1]=pe.peBlue;
            p[2]=0;
            p += 4;
        } while (i < nDibColors);
    }
    }
}
