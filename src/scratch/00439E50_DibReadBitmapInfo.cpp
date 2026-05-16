// VA: 00439E50 DibReadBitmapInfo
// Attempt log:
// initial natural DIB loader from packet/decompiler with local Win16 bitmap structs: same 544-byte size, but broad mismatch from prologue; rebuilt uses 0x4c frame and keeps file handle in ESI instead of original 0x50 frame with file handle EBX, zero in ESI, _llseek pointer in EDI.
// tried volatile off/pdib surface; pdib volatile failed compile, off volatile alone no improvement.
// tried local function-pointer aliases for _llseek/_lread plus zero local to encourage original EDI/ESI allocation; code shrank to 528 bytes and was worse, rolled back.
// tried explicit padding local and volatile padding local to force 0x50 frame; optimized away or worsened without fixing frame/register basin, rolled back.
// tried reordering locals to pdib/colorBytes/off/bc/bf/bi to mirror stack layout; no meaningful improvement.
// tried natural GlobalAlloc(GlobalLock(...)) and explicit colorBytes local; same broad family.
// left in scratch: behavior is understood, but source/local topology and register allocation are still wrong from function start; not accepted_drift-safe.

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef long LONG;
typedef void* HGLOBAL;

extern "C" LONG (__stdcall* const _llseek)(int, LONG, int);
extern "C" unsigned int (__stdcall* const _lread)(int, void*, unsigned int);
extern "C" HGLOBAL (__stdcall* const GlobalAlloc)(unsigned int, unsigned long);
extern "C" void* (__stdcall* const GlobalLock)(HGLOBAL);

#pragma pack(push, 1)
struct BITMAPFILEHEADER_X {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
};
struct BITMAPCOREHEADER_X {
    DWORD bcSize;
    WORD bcWidth;
    WORD bcHeight;
    WORD bcPlanes;
    WORD bcBitCount;
};
#pragma pack(pop)

struct BITMAPINFOHEADER_X {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
};

extern "C" BITMAPINFOHEADER_X* __cdecl DibReadBitmapInfo(int fh)
{
    BITMAPINFOHEADER_X* pdib;
    DWORD colorBytes;
    volatile DWORD off;
    BITMAPCOREHEADER_X bc;
    BITMAPFILEHEADER_X bf;
    BITMAPINFOHEADER_X bi;

    if (fh == -1) {
        return 0;
    }

    off = _llseek(fh, 0, 1);
    if (_lread(fh, &bf, 0x0e) != 0x0e) {
        return 0;
    }
    if (bf.bfType != 0x4d42) {
        bf.bfOffBits = 0;
        _llseek(fh, off, 0);
    }

    if (_lread(fh, &bi, 0x28) != 0x28) {
        return 0;
    }

    if (bi.biSize == 0x0c) {
        bc.bcSize = bi.biSize;
        bc.bcWidth = (WORD)bi.biWidth;
        bc.bcHeight = (WORD)(bi.biWidth >> 16);
        bc.bcPlanes = (WORD)bi.biHeight;
        bc.bcBitCount = (WORD)(bi.biHeight >> 16);

        bi.biSize = 0x28;
        bi.biWidth = bc.bcWidth;
        bi.biHeight = bc.bcHeight;
        bi.biPlanes = bc.bcPlanes;
        bi.biBitCount = bc.bcBitCount;
        bi.biCompression = 0;
        bi.biSizeImage = 0;
        bi.biXPelsPerMeter = 0;
        bi.biYPelsPerMeter = 0;
        bi.biClrUsed = 0;
        bi.biClrImportant = 0;
        _llseek(fh, -28, 1);
    }

    DWORD ncolors;
    if (bi.biClrUsed == 0 && bi.biBitCount <= 8) {
        ncolors = 1 << (BYTE)bi.biBitCount;
    } else {
        ncolors = bi.biClrUsed;
    }

    if (bi.biSizeImage == 0) {
        bi.biSizeImage = (((bi.biWidth * bi.biBitCount) + 31) >> 3 & 0x1ffffffc) * bi.biHeight;
    }

    if (bi.biClrUsed == 0 && bi.biBitCount <= 8) {
        bi.biClrUsed = 1 << (BYTE)bi.biBitCount;
    }

    colorBytes = ncolors * 4;
    pdib = (BITMAPINFOHEADER_X*)GlobalLock(GlobalAlloc(2, bi.biSize + colorBytes));
    if (pdib == 0) {
        return 0;
    }

    *pdib = bi;
    BYTE* bits = (BYTE*)pdib + pdib->biSize;
    if (ncolors != 0) {
        if (bi.biSize == 0x0c) {
            _lread(fh, bits, ncolors * 3);
            int i = ncolors - 1;
            if (i >= 0) {
                BYTE* src = bits + ncolors + i * 2 + 1;
                DWORD* dst = (DWORD*)(bits + i * 4);
                do {
                    BYTE b = src[-1];
                    BYTE g = src[0];
                    BYTE r = src[1];
                    *dst = ((DWORD)r << 16) | ((DWORD)g << 8) | b;
                    --dst;
                    src -= 3;
                    --ncolors;
                } while (ncolors != 0);
            }
        } else {
            _lread(fh, bits, colorBytes);
        }
    }
    if (bf.bfOffBits != 0) {
        _llseek(fh, bf.bfOffBits + off, 0);
    }
    return pdib;
}
