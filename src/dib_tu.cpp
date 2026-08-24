// Authentic PDB-ordered wrapper for C:\\msdev\\work\\age1_x1\\Dib.cpp.
//
// The owner order follows the source-line bands in the Dib.cpp packet. The
// earlier matching and accepted-drift owners establish the Win32 and DIB
// context used by the later owners. Three later matching owners remain
// blocked because their standalone declarations conflict with that context;
// they stay listed in the proposal and are not replaced by aliases or dummy
// wrappers.

#include "../include/dib_context.h"
#include "accepted_drift/00438820_DibBlt.cpp"
#include "scratch/00438AA0_TransDibBlt.cpp"
#include "matching/00438E80_ClipDibBlt.cpp"
#include "matching/00439060_GetDibDim.cpp"
#include "scratch/004390A0_TileDibBlt.cpp"
#include "accepted_drift/004395A0_DibCheckTrans.cpp"
#include "matching/00439700_GetPaletteFromDib.cpp"
#include "matching/00439750_ReadPalette.cpp"
#include "matching/00439A10_DibOpenFile.cpp"
#include "matching/00439B50_ReadDibBits.cpp"
#include "matching/00439BE0_DibWriteClipped.cpp"
#include "matching/00439CC0_DibWriteFile.cpp"
#include "matching/00439D80_DibCreatePalette.cpp"
#include "matching/00439E50_DibReadBitmapInfo.cpp"
#include "matching/0043A070_DibFromBitmap.cpp"
#include "matching/0043A330_DibSetUsage.cpp"
#include "scratch/0043A420_DibDraw.cpp"
#include "accepted_drift/0043A4B0_DibCopy.cpp"
#include "matching/0043A500_DibCreate.cpp"
#include "matching/0043AA60_xlatClut8.cpp"
#include "accepted_drift/0043AA90_xlatClut4.cpp"
#include "accepted_drift/0043AAD0_xlatRle8.cpp"
#include "matching/0043AB40_xlatRle4.cpp"
#include "scratch/0043AB50_memmove.cpp"
#include "scratch/0043A660_DibMapToPalette.cpp"

// Blocked in the complete context: these standalone owners redeclare symbols
// already established by the earlier Dib.cpp sources or by windows.h.
// 0043AB80 CreateIdentityPalette, 0043ACB0 CopyPalette, and 0043AD40 DibFree
// remain preserved exact-source references in the proposal's blocked list.
