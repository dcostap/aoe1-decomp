// getdxver.cpp:342-389, 160 bytes
// Best: 65% (104/160 bytes diff)
//
// attempt 1-3: baseline, stack fix, 66.9%
// attempt 4-10: various source reshapes (65-74%)
// attempt 11: add GetLastError on GetFileVersionInfoA failure path -> 65%
//   Also reverted comparison to simple if form
//
// Remaining 65%: register swap (esi/edi) + comparison tree shape.
// VC5 register allocation basin. Left in scratch.
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
    if (void* pv = operator new(verSize)) {
        if (!GetFileVersionInfoA( "dplayx.dll", 0, verSize, pv )) {
            GetLastError();
            return 0;
        }
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
    return 0;
}
