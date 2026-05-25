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
// ACCEPTED_DRIFT DENIED: best remaining diff is broad register/topology drift (first
// mismatch +7/+8 or +0 in link families), not localized harmless drift; leave in scratch.

extern "C" void __cdecl free(void* block);

struct RGE_Time_Entry {
    float time;                    // +0x00
    unsigned char command;         // +0x04
    unsigned char gap_05[0x27];    // 0x05-0x2B
    RGE_Time_Entry* next;          // +0x2C
};

struct RGE_Timeline {
    void* vtable;                  // +0x00
    void* world;                   // +0x04
    RGE_Time_Entry* time_list;     // +0x08
    short list_num;                // +0x0C
    short avail_id;                // +0x0E
    float old_time;                // +0x10

    void sub(RGE_Time_Entry* entry);
};

void RGE_Timeline::sub(RGE_Time_Entry* entry) {
    RGE_Time_Entry* p;
    RGE_Time_Entry* prev;

    p = this->time_list;
    if (p == 0) return;

    prev = 0;
    if (p == 0) return;

    while (p != entry) {
        prev = p;
        p = p->next;
        if (p == 0) return;
    }

    if (prev == 0)
        this->time_list = p->next;
    else
        prev->next = p->next;

    if (p->command == 1) {
        entry = this->time_list;
        if (entry != 0) {
            while (entry->next != 0)
                entry = entry->next;
        }
    }
    this->sub(entry);
    free(p);
    this->list_num--;
}
