// getdxver.cpp:342-389, 160 bytes
// Best: 65% (104/160 bytes diff)
//
// attempt 1-3: baseline, stack fix, 66.9%
// attempt 4-10: various source reshapes (65-74%)
// attempt 11: add GetLastError on GetFileVersionInfoA failure path -> 65%
//   Also reverted comparison to simple if form
// Fresh pass 2026-05-19:
// try 12: register verSize; no change, still ESI=size / EDI=buffer (opposite original).
// try 13: hoisted pv declaration/assignment; no change.
// try 14: volatile pv; badly worsened to 72.5% and first mismatch +2; rolled back.
// try 15: `if(verSize) ... else GetLastError` source; size collapsed to 144; rolled back.
// try 16: comparison as major/minor locals with equality-first nesting; worse edit/branch shape.
// try 17: De Morgan comparison; got p[3] preload but wrong jb/jne tree; rolled back.
// try 18: explicit <= failure inside equality arm; emitted sbb/inc boolean return; rolled back.
//
// Remaining 65%: register swap (esi/edi) + comparison tree shape.
// VC5 register allocation basin. Left in scratch.
// Core logic correct: GetFileVersionInfoSizeA -> operator new -> GetFileVersionInfoA
// -> VerQueryValueA -> version comparison (0x40005, 0x1062F) -> return 1/0.
// Retry 2026-05-20 assigned pass:
// try 19: declare GetLastError as dllimport to match original IAT indirect call; improved to 31.25% positional.
// try 20-24: local declaration order, inner pv declaration, register qualifiers, and positive verSize guard; no register swap fix.
// try 25-27: size-as-void, extra keep temp, and swapped declarations; size-as-void plus dllimport improved to 22.5% but still ESI=size/EDI=buffer opposite original.
// try 28-32: several comparison spellings; explicit orig-like goto compare gave best 20.625% positional / 15.0% edit but still broad ESI/EDI swap.
// try 33-34: using pv as temporary size and stack/cast size tests did not fix the register basin.
// GIVEUP: kept best source below. No accepted_drift: remaining mismatch includes persistent ESI/EDI role swap through allocation/version calls plus comparison/return layout, not a localized behavior-equivalent hunk.
// Retry 2026-05-21 Boss pass: revalidated best (160B, 20.625% positional / 15.0% edit, first mismatch +21). Tried register/decl-order variants for pv/verSize/lpDummy, unsigned-int vs void* size forms, several comparison spellings (natural >=, nested positive, fail-return, cmp-eax-style), and flags /G5 /Ob0 /Oa /O2-no-/Oy /O1. No source or flag changed the core ESI/EDI role swap; best comparison remains current explicit-goto form. Still not accepted_drift: register swap persists across allocation/version calls plus comparison/return layout drift.
// Retry 2026-05-24 assigned pass: 15 more probes. Tried uint verSize, pv declared/initialized inside allocation block, register/volatile size and pv, size copy temp, natural all-in-one source, nested comparison, pv declaration order/registers, cmp-eax-eax tail/goto variants, unsigned long declarations, and a typed VS_FIXEDFILEINFO-style struct. All competitive variants kept the same first mismatch +21 ESI/EDI role swap; natural comparison forms worsened. Best remains current 160B source at 20.625% positional / 15.0% edit. Not accepted_drift: persistent ESI/EDI role swap spans allocation/version calls and comparison/return layout, not a localized benign hunk.
// Retry 2026-05-26 Boss pass: 18 probes on VA 0044DEE0 only. Revalidated current best: 160B, 20.6250% positional / 15.0000% edit, first mismatch +21. Tried `unsigned int verSize`, declaration order changes, pv declared inside allocation block, register size/pv, size copy temp for both new/version call, char* pv, call-arg temp order, typed unsigned-int verInfo pointer, natural comparison form, and flag probes /G5 /Og /Oa /Ob0 /Oy- /O1 /Gr /Gz. No source/flag changed the core ESI/EDI role swap; natural comparison and /Oy- worsened, /O1 shrank. GIVEUP: not accepted_drift quality; remaining ESI/EDI role swap persists through allocation/version calls with comparison/return layout drift, not a localized benign hunk.

extern unsigned int __stdcall GetFileVersionInfoSizeA( const char*, unsigned int* );
extern int __stdcall GetFileVersionInfoA( const char*, unsigned int, unsigned int, void* );
extern int __stdcall VerQueryValueA( void*, const char*, void**, unsigned int* );
extern __declspec(dllimport) unsigned int __stdcall GetLastError( void );
extern void* operator new( unsigned int );

int IsDPlay501a() {
    void* pv;
    void* verInfo;
    void* verSize;
    unsigned int verInfoLen;
    unsigned int lpDummy;

    verSize = (void*)GetFileVersionInfoSizeA("dplayx.dll", &lpDummy);
    if (verSize == 0) {
        GetLastError();
        return 0;
    }
    pv = operator new((unsigned int)verSize);
    if (pv) {
        if (!GetFileVersionInfoA("dplayx.dll", 0, (unsigned int)verSize, pv)) {
            GetLastError();
            return 0;
        }
        if (VerQueryValueA(pv, "\\", &verInfo, &verInfoLen)) {
            unsigned int* p = (unsigned int*)verInfo;
            unsigned int a = p[2];
            unsigned int b = p[3];
            if (a != 0x40005) goto check;
            if (b >= 0x1062F) goto yes;
            a = a - a;
        check:
            if (a <= 0x40005) goto no;
        yes:
            return 1;
        no:
            ;
        }
    }
    return 0;
}
