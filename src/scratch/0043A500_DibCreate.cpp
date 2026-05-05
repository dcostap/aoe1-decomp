// VA: 0043A500 DibCreate | Dib.cpp:1605-1659
// first natural pass compiles at original size but uses different parameter/register allocation (width in EBX vs original bits in EBX); needs source/parameter expression reshaping before useful diff.

typedef void* HGLOBAL;
extern "C" __declspec(dllimport) HGLOBAL __stdcall GlobalAlloc(unsigned int flags, unsigned int bytes);
extern "C" __declspec(dllimport) void* __stdcall GlobalLock(HGLOBAL hMem);

struct tagBITMAPINFOHEADER {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
};

tagBITMAPINFOHEADER* __cdecl DibCreate(int bits, int width, int height)
{
    int line_size;
    int total_size;
    tagBITMAPINFOHEADER* info;
    unsigned int* pal;
    int i;

    line_size = (((width * bits + ((width * bits >> 31) & 7)) >> 3) + 3) & ~3;
    total_size = line_size * height;
    info = (tagBITMAPINFOHEADER*)GlobalLock(GlobalAlloc(0x42, total_size + 0x428));
    if (info == 0) {
        return 0;
    }

    info->biSize = 0x28;
    info->biWidth = width;
    info->biHeight = height;
    info->biPlanes = 1;
    info->biBitCount = (unsigned short)bits;
    info->biCompression = 0;
    info->biSizeImage = total_size;
    info->biXPelsPerMeter = 0;
    info->biYPelsPerMeter = 0;
    info->biClrUsed = 0;
    info->biClrImportant = 0;
    if (bits == 4) {
        info->biClrUsed = 0x10;
    } else if (bits == 8) {
        info->biClrUsed = 0x100;
    }

    pal = (unsigned int*)(info + 1);
    i = 0;
    while (i < (int)((info->biClrUsed + (((int)info->biClrUsed >> 31) & 0xf)) >> 4)) {
        *pal++ = 0;
        *pal++ = 0x800000;
        *pal++ = 0x8000;
        *pal++ = 0x808000;
        *pal++ = 0x80;
        *pal++ = 0x800080;
        *pal++ = 0x8080;
        *pal++ = 0xc0c0c0;
        *pal++ = 0x808080;
        *pal++ = 0xff0000;
        *pal++ = 0xff00;
        *pal++ = 0xffff00;
        *pal++ = 0xff;
        *pal++ = 0xff00ff;
        *pal++ = 0xffff;
        *pal++ = 0xffffff;
        i++;
    }
    return info;
}
