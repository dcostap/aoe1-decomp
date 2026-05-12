// VA: 0050DFD0 RGE_Timeline::sub(RGE_Time_Entry*)
// PDB source: Timeline.cpp lines 499-530 (100 bytes, 43 asm lines)
// Default flags
//
// Blocker: VS5 register coloring basin. Multiple VC5 codegen families:
// 1. Baseline (96 bytes): pushes EBX (3-reg save), entry in EAX, second test
//    reloads time_list from [edx] instead of re-testing cur/esi. Body
//    matches well but 4 bytes short of 100-byte original.
// 2. Target/needle local (96 bytes): correct 2-reg save (ESI,EDI), entry in EDX,
//    pp in EAX, but loop comparison uses `cmp esi,[esp+0Ch]` (stack reload) and
//    walk loop spills through the entry stack slot (200%+ byte count in walk section).
// 3. Volatile entry (100+ bytes, 81% diff): recovers 100 bytes but with
//    parameter-reload loop and broad wrong-family body.
// No approach across ~90 cumulative attempts reaches exact match.
//
// Attempt log (current session):
// - Attempt 1: baseline restored, 96 bytes
// - Attempt 2: RGE_Time_Entry*& pp reference, same 96 bytes
// - Attempt 3: goto-based flow, same 96 bytes
// - Attempt 4: char* arithmetic for pp, same 96 bytes
// - Attempt 5: volatile entry param, 100 bytes but 81% positional diff
// - Attempt 6: target local (RGE_Time_Entry* target = entry), correct
//   2-reg prologue but stack-spill walk loop, 96 bytes
// - Attempt 7: scoped target local, same as 6 
// - Attempt 8: unlinked temp var, same as baseline (96 bytes, 3-reg)
// - Attempt 9: searchFor local, same as 6 (2-reg prologue, stack-spill walk)
// - Attempt 10: separate walk accumulator, same as 6
// - Attempt 11: entry = 0 instead of walk, 80 bytes (no walk loop at all)
// - Attempt 12+: tried various loop/walk permutations, stuck in same families

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
    RGE_Time_Entry* cur = this->time_list;
    if (cur == 0) return;
    RGE_Time_Entry** pp = &this->time_list;
    if (cur == 0) return;

    while (cur != entry) {
        pp = &cur->next;
        cur = cur->next;
        if (cur == 0) return;
    }

    *pp = cur->next;
    if (cur->command == 1) {
        entry = this->time_list;
        if (entry != 0) {
            do {
                entry = entry->next;
            } while (entry != 0);
        }
    }

    this->sub(entry);
    free(cur);
    --this->list_num;
}
