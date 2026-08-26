// VA: 00442540 expand_allocations
// PDB source: dpl_obj.cpp
// Size: 315 bytes (correct)
// Attempt log:
// - Prior attempts across: extern vs intrinsic memcpy, variable scope/order, temp vars,
//   calloc argument patterns. All produce correct-size 315B but the register allocation
//   for calloc 1's "new_size" argument differs:
//     Original: mov edx,[ebx+4]; ... mov eax,edx; mov [ebx+4],edx; push eax
//     Rebuilt before the final probe: mov eax,[ebx+4]; ... push eax; mov [ebx+4],eax
// - Final source-shape probe: direct `allocated_size += grow_size` followed by
//   `calloc(this->allocated_size, 4)` restores the original store/push schedule and
//   matches all 315 bytes. This is the natural period source form.
// - Module closure: the original FPO owner is protected (`IAEXH`), so the
//   compiler-facing declaration keeps `expand_allocations` under `protected:`.

extern "C" void* __cdecl memcpy(void* dst, const void* src, int size);
#pragma intrinsic(memcpy)

#ifndef DPL_OBJ_SHARED_CONTEXT
#include "../../include/dpl_obj_context.h"
#endif

void RGE_Doppleganger_Creator::expand_allocations(int grow_size)
{
    if (DDlogf != 0) {
        fprintf(DDlogf, "RESIZE (@%d) p=%d  grow=%d\n",
            this->owner->world->world_time,
            (int)this->owner->id,
            grow_size);
    }

    this->allocated_size += grow_size;

    void* r0 = calloc(this->allocated_size, 4);
    void* r1 = calloc(this->allocated_size, 4);
    void* r2 = calloc(this->allocated_size, 4);
    void* r3 = calloc(this->allocated_size, 4);

    memcpy(r0, this->Objects, this->active_size * 4);
    memcpy(r1, this->Map_Addresses, this->active_size * 4);
    memcpy(r2, this->Last_Map_Value, this->active_size * 4);
    memcpy(r3, this->Object_ids, this->active_size * 4);

    free(this->Objects);
    free(this->Map_Addresses);
    free(this->Last_Map_Value);
    free(this->Object_ids);

    this->Objects = (RGE_Static_Object**)r0;
    this->Map_Addresses = (unsigned long**)r1;
    this->Last_Map_Value = (unsigned long*)r2;
    this->Object_ids = (int*)r3;
}
