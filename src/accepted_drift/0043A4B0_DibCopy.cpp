// ACCEPTED_DRIFT: manually reviewed localized 6-byte drift in only the second
// Dib size calculation before memcpy. Both forms compute `biSize + biClrUsed*4 +
// biSizeImage` and pass the same dst/src/size to memcpy; allocation path is exact.
// tried direct GlobalAlloc/GlobalLock/memcpy form; VC5 kept inlining memcpy into rep movs
// tried forcing memcpy out with pragma/prototype; mismatch stayed at the copy helper basin
// tried <string.h>, plain extern memcpy(int/ulong), grouped expressions, temporary partial sums, dword-array field access, and named locals; the best basin uses plain extern memcpy plus volatile biSizeImage
// volatile biSizeImage fixed the first size calculation exactly; remaining 6-byte drift is only the second size calculation's register allocation before memcpy (rebuilt uses ecx/edx/eax instead of eax/ecx/edx)
// 2026-05-04: variant-lab sweeps over second memcpy size-expression order, cast-vs-field volatility surface, temp/register locals, and register aliases all collapsed back to the same 6-byte basin or got worse
// follow-up retry: macro/inline-helper forms, pointer aliases, staged locals, cast/shift spellings, raw-offset field loads, and memcpy decl tweaks
// all either reproduced the same 6-byte second-expression register-coloring drift or regressed earlier
// >10 attempts: leaving in scratch at the closest basin rather than churning wider context
// 2026 retry: staged size locals/colors-header-sizeImage/total forms regressed to 10-byte drift;
// restored closest direct memcpy expression with remaining 6-byte second-size register-coloring drift.
// 2026-05-09 GraniteCub: tried 16 focused variants: second-size expression reorder/shift/raw offsets,
// header/img temps, macro/helper, positive if/label tail, nonvolatile+volatile-cast surfaces,
// HGLOBAL temp, and memcpy return/calling-convention decl tweaks. Best remains 6-byte
// register-coloring drift in the second size calculation before memcpy; no exact match.
#include <windows.h>

extern void* memcpy(void* dst, const void* src, unsigned long n);

extern "C" __declspec(dllimport) void* __stdcall GlobalAlloc(unsigned int flags, unsigned long bytes);
extern "C" __declspec(dllimport) void* __stdcall GlobalLock(void* hMem);

BITMAPINFOHEADER* DibCopy(BITMAPINFOHEADER* dib) {
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
