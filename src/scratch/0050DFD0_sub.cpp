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

extern "C" void __cdecl free(void* block);

struct RGE_Time_Entry {
    float time;                    // +0x00
    unsigned char command;         // +0x04
    unsigned char gap_05[0x27];    // 0x05-0x2B
    RGE_Time_Entry* next;          // +0x2C
};

class RGE_Timeline {
public:
    void* vtable;                  // +0x00
    void* world;                   // +0x04
    RGE_Time_Entry* time_list;     // +0x08
    short list_num;                // +0x0C
    short avail_id;                // +0x0E
    float old_time;                // +0x10

    void sub(RGE_Time_Entry* entry);
};

void RGE_Timeline::sub(RGE_Time_Entry* entry) {
    RGE_Time_Entry* p = this->time_list;
    RGE_Time_Entry** base = &this->time_list;
    if (p != 0) {
        RGE_Time_Entry** link = base;
        if (p != 0) {
            while (p != entry) {
                link = &p->next;
                p = p->next;
                if (p == 0) return;
            }
            *link = p->next;
            if (p->command == 1) {
                entry = *base;
                while (entry != 0)
                    entry = entry->next;
            }
            this->sub(entry);
            free(p);
            this->list_num--;
        }
    }
}
