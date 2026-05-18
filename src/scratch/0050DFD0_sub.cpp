// VA: 0050DFD0 RGE_Timeline::sub(RGE_Time_Entry*) (100 B)
// PDB source: Timeline.cpp lines 499-530
// Attempt log:
// 1: Started from existing scratch; it was behavior-wrong for command==1 (passed last entry, original traverses to null) and freed the parameter rather than the found node in some shapes.
// 2: Rewrote to Ghidra/original behavior: find entry via link pointer, unlink found node, if command==1 traverse time_list by next until null and recurse with null, otherwise recurse with original entry, free found node, decrement list_num.
// 3: Natural structured form compiled exact size but broad: VC5 saved EBX and used this=ESI/cur=EAX; original saves only ESI/EDI and uses this=EDI/cur=ESI.
// 4: Added explicit self/local shape and goto search/found labels; got this=EDI and cur=ESI, exact size 100, but compiler still saves EBX for the unlink next pointer and chooses slightly different early return/loop layout.
// 5: Tried raw cast for `*link = p->next`; no register change.
// 6: Tried volatile target to force stack parameter compare; worsened layout and introduced stack homes, rolled back.
// 7: Tried /O1 /Oy: size-short 84, rolled flag back.
// 8: Kept best exact-size behavior-equivalent source. Current diff is due register/save and block-layout choices, not changed calls, memory effects, stack cleanup, or predicates.
// ACCEPTED_DRIFT_PROPOSAL: Small 100-byte function; rebuilt preserves behavior and public effects (unlink, recursive sub argument including command==1 null behavior, free found node, decrement count). Mismatch is localized codegen topology/register allocation: extra EBX save/use for `next`, different loop/early-return layout. Needs Boss review before moving.

extern "C" void __cdecl free(void* block);

class RGE_Time_Entry {
public:
    float time;
    unsigned char command;
    char gap_05[0x27];
    RGE_Time_Entry* next;
};

class RGE_Timeline {
public:
    void* vtable_ptr;
    void* world;
    RGE_Time_Entry* time_list;
    short list_num;
    short avail_id;
    float old_time;

    void sub(RGE_Time_Entry* entry);
};

void RGE_Timeline::sub(RGE_Time_Entry* entry) {
    RGE_Time_Entry* p;
    RGE_Time_Entry** link;

    p = this->time_list;
    link = &this->time_list;
    if (p == 0) goto done;
    if (p == 0) goto done;

search:
    if (p == entry) goto found;
    link = &p->next;
    p = p->next;
    if (p != 0) goto search;
    return;

found:
    *link = (RGE_Time_Entry*)*((int*)((char*)p + 0x2c));
    if (p->command != 1) {
        entry = entry;
    } else {
        entry = this->time_list;
        if (entry != 0) {
again:
            entry = entry->next;
            if (entry != 0) goto again;
        }
    }
    this->sub(entry);
    free(p);
    this->list_num--;
done:
    return;
}
