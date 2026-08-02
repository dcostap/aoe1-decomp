// VA: 005359E0 RGE_View::pick
// Source: view.cpp lines 2272-2300
// Size: 151 bytes, __thiscall, ret 18h (6 params)
// Default flags: /nologo /c /O2 /Oy
// No inline asm/hacks.
//
// Previous history summary:
// - Attempts 1-10: named locals eliminated sub esp,10h; local int array restored size but
//   register allocation differed. memset/struct versions changed zeroing/register basin.
// - 2026-05-19 pass: tried register pi, named zero, explicit mask, store-order swaps,
//   register key, uchar signatures, memset, using pi for call args, /Ob0. No exact.
// - 2026-05-20 pass: width matrix for key/param2, object-first local, explicit mask,
//   /O2 without /Oy, /Ox, /Oa, /Og, /O1, void* result. Best positional probe still broad.
// - 2026-05-21 pass: object-first local, manual branch mask, register object/info,
//   uchar signatures, named zero, memset, alternate pointer order, member view_function
//   surface, direct uchar result masking. Best retained source casts view_function return
//   to unsigned char before comparisons: exact size 151B, 62.9139% positional / 58.2781%
//   edit, first mismatch +4.
//
// Current Luna retry (bounded probes):
// - baseline rebuilt after claim: exact size 151B, 65.5629% positional /
//   60.26% edit, first mismatch +4; current source is the retained prior best.
// - probe 1: restored the binary-proven Pick_Info/tagPOINT layout and natural
//   member view_function surface; it regressed to 169B and was rolled back.
// - probe 2: byte formals/direct uchar result kept size 151B but worsened to
//   91.3907% positional; the mode copy was optimized away. Rolled forward only
//   as the next focused condition-lifetime probe.
// - probe 3: consuming the mask condition from the mode local was codegen
//   duplicate; restored baseline.
// - probe 4: typed Pick_Info forced EBX/+22B and was rolled back.
// - probe 5: typed object formal was a codegen duplicate. Probe 6 removed the
//   early info alias; that was also a duplicate of the baseline.
// - probe 6: removing the info alias was a codegen duplicate. Probe 7 direct
//   member-call context corrected the conceptual relocation but regressed to
//   154B/83.1169%; rolled back for the final focused basin probes.
// - probe 7: register-qualified key/object hints were a codegen duplicate.
// - probe 8: direct branchless mask emitted setne/neg, regressed to 153B /
//   86.9281%; rolled back. Best retained state is the pre-claim 151B basin.
//
// Previous Boss retry (10 honest probes):
// 1: Revalidated retained baseline: exact size 151, 62.9139% positional / 58.2781% edit.
// 2: Rewrote object mask as `masked=obj; if (key=='(') masked=0;`: much worse (92% edit),
//    branch/spill family.
// 3: Added pinfo alias and named zero local: no improvement from baseline.
// 4: Modeled RGE_Pick_Info struct with typed fields: worsened badly; compiler emitted larger
//    typed/narrow stores and different frame.
// 5: Declared view_function as returning unsigned char: removed return mask but reg topology
//    regressed to older 88.7417% positional / 62.9139% edit family.
// 6: key as unsigned char formal: first mismatch moved to +7 but positional/edit worsened.
// 7: key and param_2 as unsigned char: same broad mismatch, worse edit.
// 8: Removed `(unsigned char)` cast on view_function return: regressed to older 88.7417%
//    positional family.
// 9: Tried equivalent mask spellings `key == '(' ? 0 : obj`, `-((uchar)key!='(')&obj`, and
//    `(uchar)(key-0x28) != 0 ? obj : 0`; all unchanged or worse.
// 10: Flag probe `/O2` without `/Oy`: no improvement, flag removed.
// 11: Named POINT-style locals instead of locals[4]: .text too short (144B), rejected.
// 2026-05-26 Boss retry: 11 more probes. Tried register result, explicit key byte local,
// obj as int, named zero, removing return mask, unsigned-char view_function/direct uchar
// result, for-loop zeroing, arithmetic mask spellings, unsigned/signed-char key formals,
// register pi, and pointer-increment zeroing. Best remains retained baseline: exact size
// 151B, 62.9139% positional / 58.2781% edit, first mismatch +4. Unsigned-char key got
// first 7 bytes to match but worsened the rest; for-loop zeroing made EAX=key but lost
// the EDI save/zeroing basin.
// GIVEUP: no accepted_drift proposal. Remaining mismatch is broad register/prologue/call setup
// topology (original EAX=key, ESI=obj then info, DL byte-mask, EDX result/zero, EDI=info;
// rebuilt keeps key in EDX/EAX, object/result/info in different registers and uses different
// zeroing/call-arg LEA registers), not localized harmless drift.

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

    int result = ((unsigned char)key != '(') ? (int)obj : 0;

    locals[3] = mouse_x;
    locals[1] = mouse_x;
    locals[2] = mouse_y;
    locals[0] = mouse_y;

    int* pi = (int*)info;
    pi[0] = 0;
    pi[1] = 0;
    pi[2] = 0;
    pi[3] = 0;
    pi[4] = 0;

    int ret = (unsigned char)view_function(key, param_2,
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
