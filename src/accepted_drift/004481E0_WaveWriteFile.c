// VA: 004481E0 _WaveWriteFile
// PDB source: Dsutil.c, lines 952-983
// Status: accepted_drift
// Remaining diff: 72.5% positional (pure register allocation variance)
//
// After 15+ probes, the remaining mismatch is entirely VC5 register allocation:
// - cBytes: original uses ecx (pre-loaded before prologue, reloaded from stack
//   at loop bottom), rebuilt uses eax (same reload pattern)
// - hmmio: original keeps in ebp (callee-saved), rebuilt reloads from stack each
//   iteration via ecx
// - lpSrc: original reloads from stack into ecx each iteration, rebuilt keeps in
//   ebp (callee-saved)
// - cur/end: register swap between eax/ecx/edx pairs
//
// The code structure, control flow, stack cleanup, field offsets, calling
// convention, parameter layout, and behavior are identical. Only which register
// holds which value differs — a compiler-internal heuristic.

typedef void* HMMIO;
typedef int MMRESULT;

struct MMIOINFO {
    unsigned int dwFlags;        // +0x00
    unsigned int pad04[6];       // +0x04 to +0x1B
    unsigned char* pchNext;      // +0x1C
    unsigned int pad20[1];       // +0x20
    unsigned char* pchEndWrite;  // +0x24
};

extern MMRESULT __cdecl mmioAdvance(HMMIO, struct MMIOINFO*, unsigned int);

void __cdecl WaveWriteFile(HMMIO hmmio, unsigned int cBytes, const unsigned char* lpSrc, unsigned int pad, unsigned int* pdwWritten, struct MMIOINFO* lpmmio) {
    unsigned int i = 0;
    *pdwWritten = 0;
    if (cBytes <= 0) return;
    do {
        if (lpmmio->pchNext == lpmmio->pchEndWrite) {
            lpmmio->dwFlags = lpmmio->dwFlags | 0x10000000;
            if (mmioAdvance(hmmio, lpmmio, 1) != 0) {
                return;
            }
        }
        *lpmmio->pchNext = lpSrc[i];
        lpmmio->pchNext = lpmmio->pchNext + 1;
        i = i + 1;
        *pdwWritten = *pdwWritten + 1;
    } while (i < cBytes);
}
