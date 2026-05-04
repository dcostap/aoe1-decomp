// tried direct GlobalAlloc/GlobalLock/memcpy form; VC5 kept inlining memcpy into rep movs
// tried forcing memcpy out with pragma/prototype; mismatch stayed at the copy helper basin
// tried <string.h>, plain extern memcpy(int/ulong), grouped expressions, temporary partial sums, dword-array field access, and named locals; the best basin uses plain extern memcpy plus volatile biSizeImage
// volatile biSizeImage fixed the first size calculation exactly; remaining 6-byte drift is only the second size calculation's register allocation before memcpy (rebuilt uses ecx/edx/eax instead of eax/ecx/edx)
// 2026-05-04: variant-lab sweeps over second memcpy size-expression order, cast-vs-field volatility surface, temp/register locals, and register aliases all collapsed back to the same 6-byte basin or got worse
// follow-up retry: macro/inline-helper forms, pointer aliases, staged locals, cast/shift spellings, raw-offset field loads, and memcpy decl tweaks
// all either reproduced the same 6-byte second-expression register-coloring drift or regressed earlier
// >10 attempts: leaving in scratch at the closest basin rather than churning wider context
extern void* memcpy(void* dst, const void* src, unsigned long n);

class tagBITMAPINFOHEADER {
public:
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    volatile unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
};

extern "C" __declspec(dllimport) void* __stdcall GlobalAlloc(unsigned int flags, unsigned long bytes);
extern "C" __declspec(dllimport) void* __stdcall GlobalLock(void* hMem);

tagBITMAPINFOHEADER* DibCopy(tagBITMAPINFOHEADER* dib) {
    tagBITMAPINFOHEADER* copy;

    if (dib == 0) {
        return 0;
    }

    copy = (tagBITMAPINFOHEADER*)GlobalLock(GlobalAlloc(2, dib->biSize + dib->biClrUsed * 4 + dib->biSizeImage));
    if (copy != 0) {
        memcpy(copy, dib, dib->biSize + dib->biClrUsed * 4 + dib->biSizeImage);
    }
    return copy;
}
