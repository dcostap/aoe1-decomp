// VA: 004324F0 TCommunications_Sessions::Refresh()
// PDB source: com_sess.cpp lines 161-186 (103 bytes, 32 asm lines)
// Default flags. No inline asm/hacks.
//
// Behavior: erase existing session info, zero a DPSESSIONDESC2-sized local (0x50 bytes), copy ApplicationGUID
// fields into its guidApplication, set dwSize to 0x50, and call glpSERV->EnumSessions(&desc, 0,
// EnumSessionCallback, this, 1).
//
// Attempt log:
// - Existing scratch zeroed with a for loop and assigned all GUID fields naturally. It produced correct prologue,
//   EraseInformation call, rep stosd, vcall/cleanup, but VC5 moved `push 1` into the memset setup and scheduled
//   GUID stores differently (baseline 75.7282% positional, 46.6019% edit).
// - Tried typed COM interface method call with extern glpSERV: still early `push 1`, worse vtable/global load shape.
// - Best improvement: preload GUID dword at 0x62CF50 into a local before zeroing. This matches the original early
//   `mov edx,[62CF50h]` before `rep stosd` and improves to 103/103 bytes, positional 37.8641%, edit 37.8641%.
// - Local `one = 1` result argument and saving call result in a local do not delay the immediate `push 1`; VC5 still
//   pushes it immediately after the first GUID store.
// - Typed COM method with absolute glpSERV changes global/vtable register use and is worse.
// - /Ob0: no effect. /O1: wrong 95-byte text. Removed custom flag file.
// - `memset(&desc,0,sizeof(desc))` with the preloaded GUID collapses to the same rep-stos family as the for loop.
// - SpruceGlow tries 1-4/6-10: one-local, volatile one, comma dwSize second-arg, funcptr local, raw stack typedef,
//   volatile/no serv local, pd alias, callback local did not improve the earlier scheduling family.
// - SpruceGlow try 5: splitting ApplicationGUID loads into g0/g1/g3 locals before stores fixed the GUID-store and
//   `push 1` scheduling, leaving only dwSize store before vtable load (edit diff 16, first mismatch 80).
// - SpruceGlow tries 11-14: comma side effects for dwSize in first/second/third arg and typedef call variants did not
//   move the dwSize store to the original location.
// - SpruceGlow try 15 MATCH: keep `void** vt = *(void***)serv;` before assigning `desc.a[0] = 0x50`, then call through
//   `vt[13]`. This forces the vtable load before the dwSize store while preserving the later argument push order.
// Result: MATCH locally with `python tools/check_function.py --va 004324F0`.

#ifndef COM_SESS_TU_CONTEXT
struct DPSESSIONDESC2 {
    unsigned long a[20];
};

class TCommunications_Sessions {
public:
    void EraseInformation();
    int Refresh();
};
#endif

#define glpSERV (*(void**)0x62CF6C)

int TCommunications_Sessions::Refresh() {
    DPSESSIONDESC2 desc;
    unsigned long g2;

    EraseInformation();

    g2 = *(unsigned long*)0x62CF50;
    for (int i = 0; i < 20; i++) {
        desc.a[i] = 0;
    }

    unsigned long g0 = *(unsigned long*)0x62CF48;
    unsigned long g1 = *(unsigned long*)0x62CF4C;
    desc.a[6] = g0;
    unsigned long g3 = *(unsigned long*)0x62CF54;
    desc.a[9] = g3;

    void* serv = glpSERV;
    desc.a[8] = g2;
    desc.a[7] = g1;
    void** vt = *(void***)serv;
    desc.a[0] = 0x50;

    return ((int (__stdcall*)(void*, DPSESSIONDESC2*, unsigned long, void*, TCommunications_Sessions*, unsigned long))vt[13])(
        serv,
        &desc,
        0,
        (void*)0x432560,
        this,
        1);
}

#undef glpSERV
