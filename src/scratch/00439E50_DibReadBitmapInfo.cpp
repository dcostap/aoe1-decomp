// VA: 00439E50 DibReadBitmapInfo
// Attempt log:
// - initial natural DIB loader from packet/decompiler with local Win16 bitmap
//   structs had the right 544-byte size but broad prologue/register drift.
// - restored the period DIBUTILS source family: ordered `off/size/i/nNumColors`
//   locals, native BITMAPFILEHEADER/BITMAPINFOHEADER/BITMAPCOREHEADER types,
//   aggregate `*pdib = bi`, and the RGBTRIPLE-to-RGBQUAD conversion loop.
// - this is the canonical source reconstruction to test before any focused
//   frame/register probes; no raw stack offsets or register forcing retained.
// - split/nested color-count guards and exact historical WIDTHBYTES macro
//   variants did not close the localized post-read scheduling gap; a focused
//   27-variant lab found no exact output. The best diagnostic volatile reread
//   moved structure but worsened positional bytes and was rolled back.
// - left in scratch: frame/saved-register and call topology match, but the
//   original keeps a second bit-count reload and different late RGB-table
//   branch/register schedule beginning at 00439F40.

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define BFT_BITMAP 0x4d42
#define WIDTHBYTES(i) ((unsigned)((i + 31) & (~31)) / 8)
#define DibNumColors(lpbi) \
    ((lpbi)->biClrUsed == 0 && (lpbi)->biBitCount <= 8 ? \
        (int)(1 << (int)(lpbi)->biBitCount) : (int)(lpbi)->biClrUsed)
#define DibColors(lpbi) \
    ((RGBQUAD FAR *)((LPBYTE)(lpbi) + (int)(lpbi)->biSize))
#define DibWidthBytesN(lpbi, n) \
    (UINT)WIDTHBYTES((UINT)(lpbi)->biWidth * (UINT)(n))
#define DibWidthBytes(lpbi) DibWidthBytesN(lpbi, (lpbi)->biBitCount)
#define DibSizeImage(lpbi) \
    ((lpbi)->biSizeImage == 0 ? \
        ((DWORD)(UINT)DibWidthBytes(lpbi) * \
            (DWORD)(UINT)(lpbi)->biHeight) : (lpbi)->biSizeImage)
#define GlobalAllocPtr(flags, cb) \
    (GlobalLock(GlobalAlloc((flags), (cb))))

typedef LPBITMAPINFOHEADER PDIB;

PDIB __cdecl DibReadBitmapInfo(HFILE fh)
{
    DWORD off;
    int size;
    int i;
    int nNumColors;

    RGBQUAD FAR *pRgb;
    BITMAPINFOHEADER bi;
    BITMAPCOREHEADER bc;
    BITMAPFILEHEADER bf;
    PDIB pdib;

    if (fh == -1)
        return NULL;

    off = _llseek(fh, 0L, SEEK_CUR);

    if (sizeof(bf) != _lread(fh, (LPSTR)&bf, sizeof(bf)))
        return FALSE;

    if (bf.bfType != BFT_BITMAP)
    {
        bf.bfOffBits = 0L;
        _llseek(fh, off, SEEK_SET);
    }

    if (sizeof(bi) != _lread(fh, (LPSTR)&bi, sizeof(bi)))
        return FALSE;

    switch (size = (int)bi.biSize)
    {
        default:
        case sizeof(BITMAPINFOHEADER):
            break;

        case sizeof(BITMAPCOREHEADER):
            bc = *(BITMAPCOREHEADER*)&bi;
            bi.biSize = sizeof(BITMAPINFOHEADER);
            bi.biWidth = (DWORD)bc.bcWidth;
            bi.biHeight = (DWORD)bc.bcHeight;
            bi.biPlanes = (UINT)bc.bcPlanes;
            bi.biBitCount = (UINT)bc.bcBitCount;
            bi.biCompression = BI_RGB;
            bi.biSizeImage = 0;
            bi.biXPelsPerMeter = 0;
            bi.biYPelsPerMeter = 0;
            bi.biClrUsed = 0;
            bi.biClrImportant = 0;

            _llseek(fh, (LONG)sizeof(BITMAPCOREHEADER) -
                sizeof(BITMAPINFOHEADER), SEEK_CUR);
            break;
    }

    nNumColors = DibNumColors(&bi);

    if (bi.biSizeImage == 0)
        bi.biSizeImage = DibSizeImage(&bi);
    if (bi.biClrUsed == 0)
        bi.biClrUsed = DibNumColors(&bi);

    pdib = (PDIB)GlobalAllocPtr(GMEM_MOVEABLE,
        (LONG)bi.biSize + nNumColors * sizeof(RGBQUAD));

    if (!pdib)
        return NULL;

    *pdib = bi;

    pRgb = DibColors(pdib);

    if (nNumColors)
    {
        if (size == sizeof(BITMAPCOREHEADER))
        {
            _lread(fh, (LPVOID)pRgb,
                nNumColors * sizeof(RGBTRIPLE));

            for (i = nNumColors - 1; i >= 0; i--)
            {
                RGBQUAD rgb;

                rgb.rgbRed = ((RGBTRIPLE FAR *)pRgb)[i].rgbtRed;
                rgb.rgbBlue = ((RGBTRIPLE FAR *)pRgb)[i].rgbtBlue;
                rgb.rgbGreen = ((RGBTRIPLE FAR *)pRgb)[i].rgbtGreen;
                rgb.rgbReserved = (BYTE)0;

                pRgb[i] = rgb;
            }
        }
        else
        {
            _lread(fh, (LPVOID)pRgb,
                nNumColors * sizeof(RGBQUAD));
        }
    }

    if (bf.bfOffBits != 0L)
        _llseek(fh, off + bf.bfOffBits, SEEK_SET);

    return pdib;
}
