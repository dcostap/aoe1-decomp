// VA: 0050DFD0 RGE_Timeline::sub(RGE_Time_Entry*) (100 B)
// PDB source: Timeline.cpp lines 499-530
// Attempt log:
// 1-11: Various approaches with RGE_Time_Entry** link all produced EBX save (push ebx at offset 0).
//        The EBX save is due to register pressure: link, entry, and &time_list occupy all 3
//        scratch registers (EAX, ECX, EDX), forcing EBX for the p->next unlink temp.
// 12-14: prev-based approach (track previous node, if/else unlink) eliminates EBX save.
//        First 7 bytes match original. Remaining mismatch is structural:
//        - No lea ecx,[edi+8] (prev approach doesn't need &time_list in register)
//        - xor eax,eax for prev=0 (vs mov eax,ecx for link init)
//        - if/else unlink (vs single *link = p->next)
//        - entry cached in ECX (vs reloaded from stack for command!=1 case)
//        - cmp byte [mem] (vs mov al,[mem]; cmp al,1)
//        - Different loop shape (prev=...; vs link = &...; )
//        - Command==1 traversal reads time_list via [edi+8] (vs [ecx])
// 15-18: int*, char*, void*, volatile-based link approaches all still produce EBX save.
// 19: Re-verified prev approach is the best without EBX.
// 20-22: Retried natural link-pointer variants (nested if, separate find local). They keep
//        the expected source topology but compile to a 96-byte .text body (too short for
//        configured 100-byte function) or earlier EBX-save family; no exact match.
// 23: Revisited simple link-pointer form. Best no-EBX family is 73% positional / 46% edit,
//     first mismatch +8: VC5 uses EAX for &time_list/link, ECX for param, and omits the
//     original duplicate entry null test + mov eax,ecx. Body/tail broadly shifted.
// 24: Swapped link initialization order (link=&time_list; p=*link); no codegen change.
// 25: `register` on link; no codegen change.
// 26: Declaring link before p; no codegen change.
// 27: Added local `this` alias before link setup; no codegen change.
// 28: Tried `char*` raw link pointer; no codegen change from simple link-pointer family.
// 29: Added separate `head` link to preserve original ECX=&time_list for command==1 scan;
//     this forces EBX save and shifts from byte 0.
// 30: Changed command==1 scan to reload `this->time_list`; still EBX-save family when
//     preserving a separate head/base pointer.
// 31: Tried integrated `for (; p != 0; p=p->next)` with found body inline; forces EBX save
//     and different early return layout.
// 32: Re-tested natural link-pointer topology with p=*link and nested positive guards; still
//     compiles to a 96-byte body (checker rejects configured 100B), omitting original LEA/dup-test.
// 33: Added `register` to entry with link initialized before p; no size/codegen change (96B).
// 34: Made link itself volatile; forces stack home plus EBX save, first mismatch at byte 0.
// 35: Used redundant `(int)p != 0` for the second guard; VC5 still folds it, 96B no-match.
// 36: Used volatile cast only for duplicate p null-test; preserves duplicate test but spills p
//     and forces EBX/save-stack family, first mismatch at byte 0.
// 37: Rolled back to prev-based no-EBX baseline because it remains the least bad compiler-facing
//     owner; exact source likely needs a hidden VC5 line/TU/liveness axis for link=&time_list.
// 38: Reset to decompiler/natural link-pointer source; reproduces link topology but saves EBX
//     immediately and remains broad drift (88% positional, 57% edit).
// 39: Added `register` parameter and swapped p/link declaration/init order; still EBX-save,
//     and even moves LEA before the head load.
// 40: Forced stack-slot-looking parameter compare with `*(RGE_Time_Entry**)&entry`; no codegen
//     improvement, still ECX-param/EDX-link/EBX-next family.
// 41: Retried exact natural `RGE_Time_Entry** link=&time_list; p=*link` topology with duplicate
//     null guard; still immediate EBX save at byte 0 (88% positional / 64% edit).
// 42: Raw `int link=(int)&time_list` and raw stores through `(RGE_Time_Entry**)link`; same EBX
//     save family as typed link.
// 43: do/break link loop with positive outer body; still byte-0 drift and broad layout mismatch.
// 44: Tried using `entry = *link` for the recursive argument after unlink to keep link/base live;
//     compile failed in one form or stayed in EBX-save family when repaired.
// 45: Added explicit unsigned-char command local in prev-based baseline to force `mov al; cmp al,1`;
//     did not improve, first mismatch remains +7 and broad prev-vs-link topology drift.
// 46: Volatile parameter/target variants either failed type constraints or forced stack/EBX saves.
// 47: `for`-header link walk and `while(1)`/continue link walk: both preserve behavior but choose
//     the same EBX-save register family and worse positional diff.
// 48: Swapped p/link declaration and initialization order; no useful change from link family.
// 49: Positive-wrapper prev form (`if (p) { if (p) ... }`) worsened first mismatch to +4.
// 50: Tested narrow per-function flags `/O1`, `/Od`, `/O2` without `/Oy`, `/Ox`; no exact basin.
//     `/Od` is completely wrong; `/O2` variants equal default; `/O1` not viable here.
// 51: Introduced late `target = entry` local after duplicate null guards to try forcing original
//     `mov edx,[esp+0Ch]`; still EBX-save link family.
// 52: Added separate `base=&time_list` plus late target to preserve ECX as head/link base; still
//     EBX-save family.
// 53: `register` late target did not affect allocation. Remaining issue is still not localized:
//     either prev-based no-EBX topology misses original link/LEA/duplicate-test shape, or natural
//     link topology matches source intent but saves EBX from byte 0.
// 54 (DS4-50DFD0): NEW topology: keep the param DIRECT (no early local), declare BOTH
//     `base = &time_list` (never updated; lives in ECX, read via *base at the walk) and
//     `link = base` (updated in loop; EAX). Duplicate `if (p != 0)` guard to reproduce the
//     test/test/mov/je shape. Loop body advances link BEFORE p (lea eax,[esi+2Ch] then
//     mov esi,[esi+2Ch]). Walk passes NULL (while entry != 0 -> entry = entry->next).
// 55 (DS4-50DFD0): Probe 1 result: still EBX-save family, code 92/100 (-8), diff 98%,
//     shape 79.55%. VC5 folded the duplicate `if (p != 0)` (single test; missing test+je),
//     ROTATED the loop (bottom `cmp esi,eax; jne body` + `je shared-epilogue` instead of
//     original `jne loop_top` with own pop/pop/ret), and kept the entry copy live across the
//     loop in EAX -> unlink temp needed EBX. Walk read DID go through the base register
//     ([edx] vs original [ecx]) so the two-link topology is confirmed right; command load
//     came out split (mov cl,[esi+4]; cmp cl,1) naturally; recursion+free relocations OK.
//     Next lead: the duplicate guard must be spelled so VC5 cannot fold it, e.g.
//     `if (p != 0 && (link = base, p != 0))` (exact Ghidra shape) inside the outer
//     `if (p != 0)`; the extra guard block before the loop head is expected to keep the
//     loop NON-rotated (backedge to top cmp), which then kills the EBX save (entry copy
//     dies at top cmp, edx reused for p->next) and produces the separate not-found pop/pop/ret.
// 56 (Luna-50DFD0 baseline): Re-established the two-link source; checker result remained
//     92/100 bytes, 98 strict diff, and EBX/rotated-loop family.
// 57: Comma-assignment duplicate guard `(link = base, p != 0)` was folded with no codegen change.
// 58: Moved base/link initialization into the short-circuit expression; no codegen change.
// 59: Explicit search/found/done gotos changed only neutral alignment bytes; no structural gain.
// 60: Register-qualified base/link did not alter the allocator or EBX save.
// 61: Swapped base/link declaration order; emitted code unchanged.
// 62: Const-qualified head-pointer variant required a cast and emitted the same code; rolled back.
// 63: Reversed the list compare operands; only neutral compare encoding drift, no metric gain.
// 64: Explicit top-tested search label/backedge emitted the same EBX-save family.
// 65: Restored declaration-only virtual destructor donor surface; no codegen change.
//     Bounded Luna-50DFD0 session exhausted at unchanged best 92/100 (98-byte strict diff).
// 66 (Luna50DFD0): Fresh canonical reset: use the proven polymorphic Timeline surface and
//     the natural do/while traversal so the null case falls through while the non-null path
//     takes the original top compare and `jne` backedge. The next check is the clean baseline.
// 67-73 (Luna50DFD0): Tested an explicit infinite loop, found-arm return, short-circuit
//     duplicate guard, scoped link, stable-base/moving-link pair, and direct-member first
//     guard. The infinite/found forms regressed to 92 B; the other forms were duplicate or
//     neutral at the 96 B polymorphic baseline (93 strict diff, 81.40% shape). The clean
//     source remains the natural polymorphic do/while. Remaining structural lead is the
//     original duplicate top guard plus ECX-head/EAX-link coloring; no new ABI evidence.
// 74 (Luna50DFD0b): Reconstructed the likely combined search predicate `p != 0 &&
//     p != entry` inside the outer non-null guard. It improved exact-block coverage to
//     55.81% but emitted 92 B/98 strict diff with the same EBX-save basin; restored clean.
// 75: A separate stable `base` head pointer, link-before-p initialization, reference head
//     alias, and register-qualified entry were each tested around that predicate. Results
//     stayed in the same EBX/ECX-link family (91-92 B, 96-98 strict diff); no source was kept.
// 76: A focused 27-variant lab over plausible declaration/search/head-use forms produced
//     no emitted code because the temporary template had closure/undeclared-base errors;
//     it provided no ranking evidence and was not promoted.
// 77: The short-circuit assignment form `p != 0 && (link = &time_list, p != 0)` also stayed
//     at 92 B/98 strict diff. Restored the canonical clean body afterward.
// 78 (Luna50DFD0b): Added the complete period-plausible RGE_Timeline declaration surface
//     from class metadata without changing the natural body. Codegen remained 96 B/93
//     strict diff; this is the current best source. Remaining blocker is the original
//     duplicate top guard plus ECX-head/EAX-link lifetime, with a recursive-call relocation
//     classified as internal+0x0 in the original versus the rebuilt sub symbol.

#include <stdlib.h>

class RGE_Game_World;
class RGE_Static_Object;

struct RGE_Time_Entry {
    float time;                    // +0x00
    unsigned char command;         // +0x04
    unsigned char gap_05[1];       // +0x05
    short obj_type;                // +0x06
    unsigned char player;          // +0x08
    unsigned char gap_09[3];       // +0x09
    float x;                       // +0x0C
    float y;                       // +0x10
    float z;                       // +0x14
    short task;                    // +0x18
    unsigned char gap_1A[2];       // +0x1A
    void* this_obj;                // +0x1C
    short this_obj_id;             // +0x20
    unsigned char gap_22[2];       // +0x22
    void* target_obj;              // +0x24
    short target_obj_id;           // +0x28
    unsigned char gap_2A[2];       // +0x2A
    RGE_Time_Entry* next;          // +0x2C
};

class RGE_Timeline {
public:
    RGE_Timeline(RGE_Game_World* world);
    RGE_Timeline(int handle, RGE_Game_World* world);
    virtual ~RGE_Timeline();
    RGE_Game_World* world;         // +0x04
    RGE_Time_Entry* time_list;     // +0x08
    short list_num;                // +0x0C
    short avail_id;                // +0x0E
    float old_time;                // +0x10

    RGE_Time_Entry* add(float time);
    RGE_Time_Entry* add_attack(float time, RGE_Static_Object* this_obj,
                                RGE_Static_Object* target_obj);
    RGE_Time_Entry* add_create(float time, short obj_type, unsigned char player,
                                float x, float y, float z);
    RGE_Time_Entry* add_delete(float time, RGE_Static_Object* this_obj);
    RGE_Time_Entry* add_move(float time, RGE_Static_Object* this_obj,
                             float x, float y, float z);
    short find_id(RGE_Static_Object* obj);
    void mock_update(float time);
    void save(int handle);
    void sub(RGE_Time_Entry* entry);
    void update();
};

void RGE_Timeline::sub(RGE_Time_Entry* entry) {
    RGE_Time_Entry* p = this->time_list;
    RGE_Time_Entry** link = &this->time_list;
    if (p != 0) {
        if (p != 0) {
            do {
                if (p == entry)
                    break;
                link = &p->next;
                p = p->next;
            } while (p != 0);

            if (p != 0) {
                *link = p->next;
                if (p->command == 1) {
                    entry = this->time_list;
                    while (entry != 0)
                        entry = entry->next;
                }
                this->sub(entry);
                free(p);
                this->list_num--;
            }
        }
    }
}
