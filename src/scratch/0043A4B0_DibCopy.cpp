// tried direct GlobalAlloc/GlobalLock/memcpy form; VC5 kept inlining memcpy into rep movs
// tried forcing memcpy out with pragma/prototype; mismatch stayed at the copy helper basin
// remaining gap: imported memcpy call vs intrinsic expansion, and the load order around the size expression
#pragma function(memcpy)
extern "C" void* __cdecl memcpy(void* dest, const void* src, unsigned long count);

class tagBITMAPINFOHEADER {
public:
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
