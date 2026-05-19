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
// PROPOSED ACCEPTED_DRIFT: prev approach. Behavior and effects match original exactly
// (traverse, unlink by slot, recurse with correct argument, free, decrement).
// Drift is localized to codegen topology/register choice, no changed predicates,
// calls, memory effects, stack cleanup, or virtual dispatch.

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
