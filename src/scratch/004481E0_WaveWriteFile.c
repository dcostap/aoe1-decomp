// WaveWriteFile from Dsutil.c:952-983
// 102 bytes, loop over input bytes, flush via mmioAdvance when buffer full
//
// tried 6-param unsigned int* cur/end -> dword stores, inc by 4 (wrong)
// tried unsigned char* cur/end -> byte stores+inc ok, but ebp for cBytes (88%)
// tried 5-param (no pad) -> lpBytesWritten offset shifted (88%)
// tried counter late init (after guard) -> eax for cBytes, first mismatch offset 1 (73.5%)
// tried cBytes<=0 for jbe -> got jbe, still eax (72.5%)
// tried pad at end -> worse (75.5%)
// tried const pad -> no change (72.5%)
// tried int cBytes -> worse (73.5%)
// tried *lpBytesWritten=i (via reg store) -> ebp for cBytes again (88%)
// tried /Oy- -> no change (72.5%)
// tried stdlib.h include -> no change (72.5%)
// remaining: VC5 uses eax for cBytes instead of ecx, cascades to different reg alloc throughout
typedef void* HMMIO;
typedef int MMRESULT;

struct mmioInfoStub {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int dw0C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned char* cur;   // 0x1C
    unsigned int pad20;
    unsigned char* end;   // 0x24
};

extern MMRESULT __cdecl mmioAdvance(HMMIO, struct mmioInfoStub*, unsigned int);

void WaveWriteFile(HMMIO hmmio, unsigned int cBytes, const unsigned char* lpSrc, unsigned int pad, unsigned int* lpBytesWritten, struct mmioInfoStub* lpmmioinfo) {
    unsigned int i;
    *lpBytesWritten = 0;
    if (cBytes <= 0) return;
    i = 0;
    do {
        if (lpmmioinfo->cur == lpmmioinfo->end) {
            lpmmioinfo->dw00 = lpmmioinfo->dw00 | 0x10000000;
            if (mmioAdvance(hmmio, lpmmioinfo, 1) != 0) {
                return;
            }
        }
        *lpmmioinfo->cur = lpSrc[i];
        lpmmioinfo->cur = lpmmioinfo->cur + 1;
        i = i + 1;
        *lpBytesWritten = *lpBytesWritten + 1;
    } while (i < cBytes);
}
