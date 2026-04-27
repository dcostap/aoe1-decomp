// getdxver.cpp:342-389, 160 bytes
// Best: 66.9% (107/160 bytes diff)
//
// attempt 1: natural Windows API version check
//   78.1%: stack 0x8 vs 0xC (need 3 locals = 12 bytes, VC5 alloc 8), register basin
// attempt 2: no verInfo init, reshape comparisons - same 78.1%
// attempt 3: add dummy local (lpDummy) for correct stack 0xC - 66.9%
//   First 21 bytes match: sub esp,0C / lea eax,[esp+4] / push esi / push edi / push eax
//   Blocker: register basin - verSize in esi (need edi), pv in edi (need esi)
//   This cascades through operator new, GetFileVersionInfoA, VerQueryValueA calls
//   Also: comparison shape differs (mine: jbe/jne early return; orig: jne+jae+cmp eax,eax trick)
// attempts 4-8: various source shape changes (nested ifs, Ghidra-style bools, local reorder, scope changes)
//   - 65-74% range, no improvement over 66.9% baseline
// attempt 9: unsigned char* for pv - compile error (C2556)
// attempt 10: two-step lpDummy assignment - 73.1% (worse, broke first 21 bytes)
//
// BLOCKER: VC5 register allocation basin. After push esi/push edi, VC5 consistently
// picks esi for the first live value (verSize) and edi for operator new result.
// Original uses edi for verSize and esi for operator new result.
// Core logic correct: GetFileVersionInfoSizeA -> operator new -> GetFileVersionInfoA
// -> VerQueryValueA -> version comparison (0x40005, 0x1062F) -> return 1/0.

extern unsigned int __stdcall GetFileVersionInfoSizeA( const char*, unsigned int* );
extern int __stdcall GetFileVersionInfoA( const char*, unsigned int, unsigned int, void* );
extern int __stdcall VerQueryValueA( void*, const char*, void**, unsigned int* );
extern unsigned int __stdcall GetLastError( void );
extern void* operator new( unsigned int );

int IsDPlay501a() {
    void* verInfo;
    unsigned int verSize;
    unsigned int verInfoLen;
    unsigned int lpDummy;

    verSize = GetFileVersionInfoSizeA( "dplayx.dll", &lpDummy );
    if (verSize == 0) {
        GetLastError();
        return 0;
    }
    void* pv = operator new(verSize);
    if (pv != 0) {
        if (GetFileVersionInfoA( "dplayx.dll", 0, verSize, pv )) {
            if (VerQueryValueA( pv, "\\", &verInfo, &verInfoLen )) {
                unsigned int* p = (unsigned int*)verInfo;
                if (p[2] > 0x40005) {
                    return 1;
                }
                if (p[2] == 0x40005 && p[3] >= 0x1062F) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
