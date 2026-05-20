// VA: 005359E0 RGE_View::pick
// Source: view.cpp lines 2272-2300
// Size: 151 bytes, __thiscall, ret 18h (6 params)
// Default flags: /nologo /c /O2 /Oy
//
// Attempt log:
// Attempt 1-3: Named locals eliminated sub esp,10h (128 bytes short). Restored
//   int locals[4] array but register allocation differed per attempt.
// Attempt 4-6: Tried unsigned char key type → added masking (and eax,0FFh).
// Attempt 7: Baseline with array + result-first → 151 bytes, byte ops via (unsigned char)cast,
//   but key in EDX not EAX, obj in ECX not ESI, info in ESI not EDI.
// Attempt 8: Named struct fields + RGE_Pick_Info struct → eliminated sub esp,10h,
//   generated mov dword [mem],0 pattern (5 bytes each vs 3 bytes with xor reg,reg).
// Attempt 9: (unsigned char)key cast + result-first + local array → 151 bytes. Byte ops
//   correct (mov al,dl; sub al,28h; neg al; sbb eax,eax). Key in EDX, obj in ECX,
//   info in ESI (same as attempt 7).
// Attempt 10: memset(info,0,20) forces xor edx,edx + mov [ecx],edx pattern. Key in EAX!
//   But byte ops use CL instead of DL, local store order scrambled, memset uses ECX instead of EDI.
// Left in scratch: 10 attempts, all 151 bytes. Fundamental register-allocation differences:
//   (1) EDX/ECX/EAX/ESI/EDI register set differs from original throughout the entire function.
//   (2) Original: EAX=key, ESI=obj, DL=byte ops, EDX=result, EDI=info, EDX=zero.
//   (3) Best rebuilt: EAX/EDX=key, ECX=obj, CL/AL=byte ops, EAX=result, ESI=info, EDI=zero.
//   Same compiler, same source → different register allocation. Not fixable from C++.
//   Not proposing accepted_drift because positional diff is 82-90% — too broad.
// Retry 2026-05-19 assigned pass:
// Attempt 11: register pi forced EDI save/use and worsened scheduling; rolled back.
// Attempt 12: named zero local similarly forced EDI zeroing and broad drift; rolled back.
// Attempt 13: explicit mask expression `-(key!='(')&obj` used cmp/setne family; worse; rolled back.
// Attempt 14: swapped local store order to match apparent stack layout; worsened broad scheduling; rolled back.
// Attempt 15: register key local worsened to EDI-save basin; rolled back.
// Attempt 16: unsigned-char key/param surface moved first mismatch to +7 but worsened edit diff; rolled back.
// Attempt 17: memset(info,0,20) again forced EDI/and eax,0FFh basin; rolled back.
// Attempt 18: using pi for call args no improvement; rolled back.
// Attempt 19: /Ob0 flag probe no improvement; removed.
// GIVEUP: final default-flags validation 151/151, MISMATCH 134 positional bytes / 88.7417%, edit 95 bytes / 62.9139%, first mismatch +4. Register topology remains fundamentally different across whole function.
// Retry 2026-05-20 Boss pass: revalidated baseline (151B, 88.7417% positional, 62.9139% edit, first mismatch +4). Tried 17 additional probes: key/param_2 signature width matrix (int/uchar/char), object-first local, explicit mask expression, /O2 without /Oy, /Ox, /Oa, /Og, /O1, plus void* result variant under the width probes. Best positional probe was `int key, unsigned char param_2` at 63.5762% positional but edit stayed 62.2517% and register topology/call setup remained broad mismatch; most other probes worsened or were unchanged. Kept existing baseline scratch.

#include <stdlib.h>

extern int __stdcall view_function(int a, int b,
                                    int* c, int* d, int* e,
                                    int* f, int* g, short* h, short* i);

struct RGE_View {
    char _gap[4];
    unsigned char pick(int key, int param_2, int mouse_y, int mouse_x,
                       void* info, void* obj);
};

unsigned char RGE_View::pick(int key, int param_2, int mouse_y, int mouse_x,
                              void* info, void* obj) {
    int locals[4];

    // Byte-level comparison via unsigned char cast
    int result = ((unsigned char)key != '(') ? (int)obj : 0;

    // Local stores matching original intent
    locals[3] = mouse_x;
    locals[1] = mouse_x;
    locals[2] = mouse_y;
    locals[0] = mouse_y;

    // Zero info structure
    int* pi = (int*)info;
    pi[0] = 0;
    pi[1] = 0;
    pi[2] = 0;
    pi[3] = 0;
    pi[4] = 0;

    // Call view_function
    int ret = view_function(key, param_2,
                            &locals[2], &locals[0], &result,
                            (int*)((char*)info + 0),
                            (int*)((char*)info + 4),
                            (short*)((char*)info + 8),
                            (short*)((char*)info + 0xA));

    unsigned char ucode = (unsigned char)ret;
    if (ucode == 0x34) {
        *(int*)((char*)info + 0xC) = result;
    } else if (ucode == 0x33) {
        *(int*)((char*)info + 0x10) = result;
    }

    return ucode;
}
