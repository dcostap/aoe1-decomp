// VA: 00439A10 DibOpenFile
// Attempt log:
// - baseline: typed Win32 OFSTRUCT/BITMAPINFOHEADER loader with resource
//   fallback and GlobalReAlloc/GlobalLock ownership.
// - scoped the new lock result so the old bitmap remains available for the
//   failure cleanup; kept the image-byte count separate from total allocation.
// - the original retains a redundant post-resource fh == -1 guard; expressing
//   it as a separate ordinary condition restored the complete CFG and bytes.

#include <windows.h>

extern BITMAPINFOHEADER* __cdecl DibReadBitmapInfo(HFILE file);

BITMAPINFOHEADER* __cdecl DibOpenFile(char* name)
{
    int fh;
    OFSTRUCT of;
    BITMAPINFOHEADER* dib;
    DWORD dwBits;

    fh = OpenFile(name, &of, OF_READ);
    if (fh == -1) {
        HRSRC resource = FindResourceA(GetModuleHandleA(0), name,
            MAKEINTRESOURCEA(2));
        if (resource != 0) {
            resource = LoadResource(GetModuleHandleA(0), resource);
            return (BITMAPINFOHEADER*)LockResource(resource);
        }
    }
    if (fh == -1)
        return 0;

    dib = DibReadBitmapInfo(fh);
    if (dib == 0)
        return 0;

    dwBits = dib->biSizeImage;
    DWORD colors = dib->biClrUsed;
    if (colors == 0 && dib->biBitCount <= 8)
        colors = 1 << dib->biBitCount;

    DWORD total_size = dwBits;
    total_size += colors * 4;
    total_size += dib->biSize;
    GlobalUnlock(GlobalHandle(dib));
    BITMAPINFOHEADER* new_dib = (BITMAPINFOHEADER*)GlobalLock(GlobalReAlloc(
        GlobalHandle(dib), total_size, 0));
    if (new_dib == 0) {
        GlobalUnlock(GlobalHandle(dib));
        GlobalFree(GlobalHandle(dib));
        dib = 0;
    } else {
        dib = new_dib;
    }

    if (dib != 0) {
        colors = dib->biClrUsed;
        if (colors == 0 && dib->biBitCount <= 8)
            colors = 1 << dib->biBitCount;
        _hread(fh, (char*)dib + dib->biSize + colors * 4, dwBits);
    }
    _lclose(fh);
    return dib;
}
