// VA: 00439E50 DibReadBitmapInfo
// Exact reconstruction notes:
// - The period DIBUTILS source family matches the complete function.
// - Keep the unused hbi declaration from that source family.
// - Keep only windows.h. Extra CRT and memory headers change VC5 scheduling.
// - Native bitmap structures, FixBitmapInfo, aggregate assignment, and the
//   RGBTRIPLE-to-RGBQUAD loop recover the original frame and control flow.

#include <windows.h>

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
#define FixBitmapInfo(lpbi) \
    if ((lpbi)->biSizeImage == 0) \
        (lpbi)->biSizeImage = DibSizeImage(lpbi); \
    if ((lpbi)->biClrUsed == 0) \
        (lpbi)->biClrUsed = DibNumColors(lpbi)
#define GlobalAllocPtr(flags, cb) \
    (GlobalLock(GlobalAlloc((flags), (cb))))

typedef LPBITMAPINFOHEADER PDIB;

PDIB __cdecl DibReadBitmapInfo(HFILE fh)
{
    DWORD off;
    HANDLE hbi = NULL;
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

    FixBitmapInfo(&bi);

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
