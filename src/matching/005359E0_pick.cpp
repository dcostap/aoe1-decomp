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

// Luna5359E0 continuation (2026-08-02):
// - canonical ABI/member-call and stack-home probes exposed the real
//   RGE_Pick_Info/view_function surface but initially worsened structure.
// - a focused source-shape lab found the natural memset(param_5,0,20),
//   picked-object local passed by address, and low-byte mask basin.
// - final control-flow probe used one if/else-if assignment chain and the
//   live return code. Current best is 151B with 16 positional bytes / 10.5960%
//   strict diff, 10 edit bytes / 6.62%, exact frame/call set, and first mismatch
//   at +1B. Remaining drift is early parameter/local scheduling, not localized
//   harmless codegen. The attempted register hint was a duplicate and is not
//   retained.
//
// Luna5359E0b continuation:
// - baseline check retained the pinned canonical source (151B, 16 bytes).
// - named tagPOINT locals recovered the natural two-point layout and reduced the
//   drift to 4 bytes; using their x-field bases recovered the two call LEAs.
// - assigning the two point coordinates as x=param_3/y=param_4 reproduced the
//   original local-byte layout and produced an exact 151B match.
// - final source is ordinary typed C++: tagPOINT locals, memset for the proven
//   20-byte Pick_Info block, direct member call, and natural result dispatch.

#include <string.h>

#ifndef RGE_VIEW_SHARED_CONTEXT
struct tagPOINT {
    long x;
    long y;
};

struct RGE_Static_Object;
struct RGE_Tile;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

struct RGE_View {
    long view_function(unsigned char mode, unsigned char parm,
                       tagPOINT* mouse_pos, tagPOINT* start_mouse_pos,
                       void** picked, float* out_x, float* out_y,
                       short* out_scr_x, short* out_scr_y);
    unsigned char pick(unsigned char param_1, unsigned char param_2,
                       long x, long y,
                       RGE_Pick_Info* param_5, RGE_Static_Object* param_6);
};
#endif

unsigned char RGE_View::pick(unsigned char param_1, unsigned char param_2,
                              long x, long y,
                              RGE_Pick_Info* param_5,
                              RGE_Static_Object* param_6) {
    RGE_Static_Object* picked = ((unsigned char)param_1 != '(') ? param_6 : 0;
    tagPOINT start_mouse_pos;
    tagPOINT mouse_pos;

    mouse_pos.x = x;
    mouse_pos.y = y;
    start_mouse_pos.x = x;
    start_mouse_pos.y = y;

    memset(param_5, 0, 20);

    long ret = this->view_function(
        param_1, param_2, &mouse_pos,
        &start_mouse_pos, (void**)&picked,
        (float*)((char*)param_5 + 0),
        (float*)((char*)param_5 + 4),
        (short*)((char*)param_5 + 8),
        (short*)((char*)param_5 + 0xA));
    unsigned char code = (unsigned char)ret;
    if (code == 0x34) {
        param_5->object = picked;
    } else if (code == 0x33) {
        param_5->tile = (RGE_Tile*)picked;
    }
    return code;
}
