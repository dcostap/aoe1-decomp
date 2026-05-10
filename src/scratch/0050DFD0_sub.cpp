// VA: 0050DFD0 RGE_Timeline::sub(RGE_Time_Entry*)
// PDB source: Timeline.cpp lines 499-530 (100 bytes, 43 asm lines)
// Default flags
//
// __thiscall: this in ecx, 1 stack param. ret 4 cleanup.
// Unlinks a timeline entry, recursively removes a related entry/null tail for command==1,
// frees the removed node, and decrements list_num.
//
// Attempt log:
// - Earlier scratch attempts used a too-large RGE_Time_Entry layout with next at +0x30;
//   original uses next at +0x2C. Fixed the local node layout to command at +4 and next at +0x2C.
// - Natural decompiler-shaped pp/cur source now emits correct +0x2C accesses and compact behavior,
//   but VC5 still compiles only a 96-byte .text section, so check_function cannot compare the
//   configured 100-byte function.
// - Tried natural nested loop, no-second-null-test, explicit-empty-if, goto-found/goto-scan,
//   raw int/char pprev, head pointer/reference variants, and explicit next temp; all stayed in the
//   96-byte family with an extra `push ebx` and pp/head-slot coloring as edx/ecx rather than original
//   ecx/eax, or otherwise did not recover the original duplicate-null-test basin.
// - Tried volatile parameter comparison forms. Direct volatile compare recovers original-style two-register
//   prologue and uses `mov edx,[esp+0Ch]`/`mov eax,ecx`-like coloring, but it reloads the parameter in
//   the loop and grows to a broad 112-byte wrong-family body. Volatile target locals collapse back to
//   96 bytes or use ecx as target/next with shifted branches.
// - Tried assigning/reloading the parameter through volatile, entry-left compare order, late target temp,
//   and label-order variants; no exact. No per-function flags kept.
// Left in scratch: behavior is understood, next offset is corrected, but source remains stuck between
// a compact 96-byte ebx/pp-coloring family and a larger volatile-parameter family. No accepted_drift
// suggestion because the current best is wrong-size/broad register-coloring drift, not localized.

extern "C" void __cdecl free(void* block);

class RGE_Time_Entry {
public:
    float time;                 // +0x00
    unsigned char command;      // +0x04
    char gap_05[0x27];          // +0x05..+0x2B
    RGE_Time_Entry* next;       // +0x2C
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
    RGE_Time_Entry** pp;
    RGE_Time_Entry* cur;

    cur = this->time_list;
    if (cur == 0) {
        return;
    }
    pp = &this->time_list;
    if (cur == 0) {
        return;
    }

    while (cur != entry) {
        pp = &cur->next;
        cur = cur->next;
        if (cur == 0) {
            return;
        }
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
