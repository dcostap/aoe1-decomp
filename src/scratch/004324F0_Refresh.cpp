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
// Left in scratch: call boundaries, stack cleanup, zeroing, GUID data, and vcall are understood; remaining blocker is
// VC5 scheduling of the constant last argument (`push 1`) and dwSize store relative to GUID stores/vtable load.

struct DPSESSIONDESC2 {
    unsigned long a[20];
};

class TCommunications_Sessions {
public:
    void EraseInformation();
    int Refresh();
};

#define glpSERV (*(void**)0x62CF6C)

int TCommunications_Sessions::Refresh() {
    DPSESSIONDESC2 desc;
    unsigned long guid2;

    EraseInformation();

    guid2 = *(unsigned long*)0x62CF50;
    for (int i = 0; i < 20; i++) {
        desc.a[i] = 0;
    }

    desc.a[6] = *(unsigned long*)0x62CF48;
    unsigned long guid1 = *(unsigned long*)0x62CF4C;
    desc.a[9] = *(unsigned long*)0x62CF54;

    void* serv = glpSERV;
    desc.a[8] = guid2;
    desc.a[7] = guid1;
    desc.a[0] = 0x50;

    return ((int (__stdcall*)(void*, DPSESSIONDESC2*, unsigned long, void*, TCommunications_Sessions*, unsigned long))(*(void***)serv)[13])(
        serv,
        &desc,
        0,
        (void*)0x432560,
        this,
        1);
}
