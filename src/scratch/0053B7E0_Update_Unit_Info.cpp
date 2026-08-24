// vis_unit.cpp target: Visible_Unit_Manager::Update_Unit_Info
// initial reconstruction from packet/decompiler for per-player visible unit bitmask update.
// Attempt log:
// - Baseline had exact size/frame but modeled growth cleanup as operator_delete; changing to cdecl free aligned both direct calls.
// - Reversed the mask XOR operands without codegen movement; mutating the incoming old_mask home was binary-backed but entered a smaller/wrong basin when assigned to new_mask and restored only the old-mask-home family.
// - Typed memcpy recovered the original rep movsd/rep movsb copy (and is retained); direct short list_size arithmetic improved the best positional diff to 306 bytes, though the frame remains 0x14 versus 0x10.
// - Hoisting the new-list/old-list pointers was diagnostic only and was rolled back.
// - This session tested a named mask delta, ordered object-base arithmetic,
//   top-tested versus guarded do-loop control flow, and function-scope offset
//   locals; none improved the canonical 306-byte frontier. Pointer scheduling
//   diagnostics matched the original frame locally but were rolled back because
//   they did not describe source behavior.
// - Typed VUR_Ptrs[9] owner storage is required by the caller object layout;
//   the direct typed form recovers the 0x10 frame.
// - Same-TU AddResource uses the period stdlib/string header context; retaining
//   those headers and the proven polymorphic static-object boundary changed no
//   bytes, but keeps the ownership model source-plausible.
// - A top-tested player loop plus direct typed owner-array indexing is the
//   simplest baseline. It gives a 0x10 frame and a 409-byte strict diff.
// - Widened capacity, owner-slot aliases, split mask statements, and a guarded
//   do-loop did not improve the clean frontier and were rolled back.
// - A typed moving current_refs alias is period-plausible and matches the
//   observed moving refs ownership. It improves the strict diff to 284 bytes,
//   with a 0x10 frame and 39.01% exact-block coverage, but is not exact.
// - Scoping current_refs inside the guard, pointer-difference owner indexes,
//   owner-array references, and function-scope player indexes all worsened it.
// - The original repair stores use the moving refs pointer plus a local offset;
//   the typed alias improves the owner schedule but does not recover that
//   source form. Raw offset forms are rejected as compiler-steering scaffolding.
// Left in scratch: prologue allocation and owner repair scheduling remain.

#include <stdlib.h>
#include <string.h>

#if !defined(VIS_UNIT_TU_CONTEXT)
#define RGE_MCO_OBJ_SHARED_CONTEXT 1
#include "../../include/m_co_obj_context.h"
#undef RGE_MCO_OBJ_SHARED_CONTEXT
struct VisibleUnitRec {
    int object_id;
    unsigned char distance;
    unsigned char player;
    unsigned char pos_x;
    unsigned char pos_y;
};

struct VisibleUnitPtr {
    VisibleUnitRec* unit_list;
    short list_size;
    short used;
};

extern RGE_Static_Object** VIS_UNIT_objectsValue;

class Visible_Unit_Manager {
public:
    VisibleUnitPtr** PlayerDataPtrs;
    void* Return_Buffer[5];
    int Player_Count;
    int Category_Count;
    void* distanceTable;

    void Update_Unit_Info(int object_id, int player, int x, int y, int category, unsigned long old_mask, unsigned long new_mask, VisibleUnitRec** refs);
};
#endif

void Visible_Unit_Manager::Update_Unit_Info(int object_id, int player, int x, int y, int category, unsigned long old_mask, unsigned long new_mask, VisibleUnitRec** refs) {
    unsigned long mask = (new_mask ^ old_mask) & 0xffff;
    VisibleUnitRec** current_refs = refs;
    if (category < this->Category_Count) {
        int p = 0;
        if (this->Player_Count > 0) {
            while (p < this->Player_Count) {
                if (mask == 0) {
                    return;
                }
                if ((mask & 1) == 1) {
                    VisibleUnitPtr* bucket = &this->PlayerDataPtrs[p][category];
                    if ((new_mask & 1) == 1) {
                        short size = bucket->list_size;
                        if (bucket->used == size) {
                            VisibleUnitRec* newList = (VisibleUnitRec*)calloc(size + size, 8);
                            memcpy(newList, bucket->unit_list, size * 8);
                            free(bucket->unit_list);
                            bucket->unit_list = newList;
                            bucket->list_size = (short)(size + size);
                            int i = 0;
                            if (bucket->used > 0) {
                                VisibleUnitRec* r = newList;
                                do {
                                    RGE_Combat_Object* obj =
                                        (RGE_Combat_Object*)VIS_UNIT_objectsValue[r->object_id];
                                    if (obj != 0) {
                                        obj->VUR_Ptrs[p] = r;
                                    }
                                    i++;
                                    r++;
                                } while (i < bucket->used);
                            }
                        }
                        int used = bucket->used;
                        VisibleUnitRec* rec = bucket->unit_list + used;
                        rec->distance = 0;
                        rec->object_id = object_id;
                        rec->player = (unsigned char)player;
                        rec->pos_x = (unsigned char)x;
                        rec->pos_y = (unsigned char)y;
                        bucket->used++;
                        *current_refs = rec;
                    } else {
                        VisibleUnitRec* rec = *current_refs;
                        VisibleUnitRec* last = bucket->unit_list + bucket->used - 1;
                        if (last != rec) {
                            *rec = *last;
                            RGE_Combat_Object* obj =
                                (RGE_Combat_Object*)VIS_UNIT_objectsValue[rec->object_id];
                            if (obj != 0) {
                                obj->VUR_Ptrs[p] = rec;
                            }
                        }
                        *current_refs = 0;
                        bucket->used--;
                    }
                }
                current_refs++;
                new_mask >>= 1;
                mask >>= 1;
                p++;
            }
        }
    }
}
