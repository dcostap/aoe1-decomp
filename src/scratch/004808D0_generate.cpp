// VA: 004808D0, RGE_Random_Map_Module::generate, 269 bytes
// Source: rmm_base.cpp lines 106-149
// FLAGS: default
//
// Attempt log:
// - v1: Direct field access for schedule, separate search variable. 240 bytes.
//   push ecx / pop ecx instead of sub esp, 8 / add esp, 8.
//   Get_schedule inlined by VC5 (reads this->schedule at +0x1C directly).
//   Different register allocation (edi=sorted, edx=current vs original ebx=sorted, edi=current).
// - v2: get_schedule as extern "C" __fastcall (no body to prevent inlining).
//   VC5 still inlines because it sees the function just returns this->schedule.
// - v3: get_schedule through function pointer. Indirect call, not matching direct call.
// - v4: Different control flow variants for sort comparison. Same 240 bytes.
//
// What works:
// - Linked list insertion sort (descending by schedule value)
// - FPU comparisons for schedule ordering
// - Logging + module execution iteration
// - Multiple return paths (return 0 on module failure, return 1 on success/empty)
// - The overall algorithm and control flow matches
//
// Remaining blockers (29 bytes short at 240 vs 269):
// 1. sub esp,8 vs push ecx: need 8 bytes of stack locals for temp float + saved this.
//    VC5 only allocates 4 bytes (push ecx) despite 2 float locals declared.
// 2. get_schedule inlined: original calls 004808C0 via direct call (4 × 5 bytes = 20 bytes).
//    VC5 inlines the field read from this->schedule at +0x1C. Cannot prevent even with
//    extern declaration (VC5 cross-TU analysis sees through it? Or infers from usage).
// 3. Register allocation: original uses ebx(sorted), edi(current), ebp(next), esi(this/search ptr)
//    with this saved to stack when esi is reused. My code doesn't overwrite esi so no save.
// 4. Calling conventions: Log and debug_rand use __cdecl/__fastcall. The string literals
//    at 585B80h, 585B48h, 585B0Ch and global at 62C4FCh are addresses not expressible
//    as C/C++ identifiers, requiring relocation masking.

#include <stddef.h>

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(const char* file, int line);

class RGE_Random_Map_Module;

class RGE_Random_Map_Module_List {
public:
    void* module;                        // +0x00
    RGE_Random_Map_Module_List* next;   // +0x04
};

extern "C" float __fastcall get_schedule(void* self);

class RGE_Random_Map_Module {
public:
    void* vtable_ptr;                   // +0x00
    char gap_04[4];                     // +0x04
    RGE_Random_Map_Module_List* list;   // +0x08

    uchar generate();
};

uchar RGE_Random_Map_Module::generate()
{
    RGE_Random_Map_Module_List* sorted;
    RGE_Random_Map_Module_List* current;
    RGE_Random_Map_Module_List* search;
    float temp;
    float temp2;

    sorted = 0;
    current = this->list;

    if (current != 0) {
        RGE_Random_Map_Module_List* next;

        do {
            next = current->next;

            if (sorted != 0) {
                temp = get_schedule(sorted->module);
                temp2 = get_schedule(current->module);

                if (temp > temp2) {
                    search = sorted;
                    while (search->next != 0) {
                        temp = get_schedule(current->module);
                        temp2 = get_schedule(search->next->module);
                        if (temp < temp2)
                            break;
                        search = search->next;
                    }
                    current->next = search->next;
                    search->next = current;
                } else {
                    current->next = sorted;
                    sorted = current;
                }
            } else {
                current->next = sorted;
                sorted = current;
            }

            current = next;
        } while (current != 0);
    }

    this->list = sorted;
    debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x8A);

    extern void* g_LogObj;
    extern void __fastcall Log(void* self, int, const char* msg, int val);
    Log(*(void**)0x62C4FC, 0, "RGE_RANDOM_MAP_MODULE::map start", 0);

    current = this->list;
    while (current != 0) {
        void* mod = current->module;
        uchar (*pfn)() = (uchar (*)())(*(void**)mod);
        if (pfn() == 0)
            return 0;

        debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x8F);
        Log(*(void**)0x62C4FC, 0, "RGE_RANDOM_MAP_MODULE::module completed with ret:", 0);
        current = current->next;
    }

    return 1;
}
