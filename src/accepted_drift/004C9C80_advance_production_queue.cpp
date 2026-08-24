// TRIBE_Building_Object::advance_production_queue
// VA: 004C9C80
// PDB: t_b_obj.cpp lines 1096-1115
// Default flags: /nologo /c /O2 /Oy
// Size: 149 bytes original, 149 bytes rebuilt
//
// Result: ACCEPTED_DRIFT proposed — 139/149 bytes matching (93.3%).
// Edit diff: 17 bytes (11.4%). Positional diff: 131 bytes (87.9%).
//
// Attempt log (6 attempts):
//
// Attempt 4 (best): Use do-while loop, proper field offsets, RGE_Base_Game extern.
// 17 bytes edit diff, all logic and control flow match exactly.
//
// Identified drift — 2 localized stable VC5 codegen differences:
//
// Issue 1 — push esi at loop entry vs function entry:
//   Original: push esi at +0x02 (right after mov eax,ecx); pop esi at +0x93
//   Rebuilt:  push esi at +0x46 (right before loop); pop esi at +0x76 (after loop)
//   Effect: VC5 saves esi only around the loop body instead of at function entry.
//   Benign — esi is preserved in both cases.
//   Cannot force from C++: short temp at function scope doesn't change VC5's
//   liveness window for esi allocation.
//
// Issue 2 — count>0 check encoding:
//   Original: mov dx,[eax+1CEh]; xor ecx,ecx; test dx,dx; jle (14 bytes)
//   Rebuilt:  cmp word [eax+1CEh],0; jle; push esi; xor ecx,ecx (13 bytes)
//   Effect: Different instruction sequence for the same if(count>0) check.
//   Same byte count range, same behavior.
//
// Branch displacements shift by 1 byte due to the push/pop position difference.
//
// Exact match quality: all field offsets verified, loop body matches exactly
// (mov si,[edx+ecx*4+4]; mov [edx+ecx*4],si; lea edx,[edx+ecx*4]; inc ecx;
//  mov [edx+2],si; movsx edx,...; cmp ecx,edx; jl), vtable call matches
// (mov rge_base_game; mov edx,[ecx]; call [edx+40h]).
//
// ACCEPTED_DRIFT 2026-05-19: approved localized push-esi/instruction-encoding drift.
// Rebuilt delays push esi to loop body; original saves at function entry. Count check
// uses cmp word vs mov+test encoding. Loop body, field offsets, vtable call, and
// all predicates/memory effects are identical.

#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::advance_production_queue()
{
    if (this->production_queue_count) {
        this->production_queue->unit_count--;
        this->production_queue_change_flag++;
        if (this->production_queue->unit_count <= 0) {
            this->production_queue_count--;
            if (this->production_queue_count > 0) {
                int i = 0;
                do {
                    this->production_queue[i].master_id =
                        this->production_queue[i + 1].master_id;
                    this->production_queue[i].unit_count =
                        this->production_queue[i + 1].unit_count;
                    i++;
                } while (i < this->production_queue_count);
            }
        }
        {
            RGE_Base_Game* game = rge_base_game;
            game->v16(
                0x7C,
                *(short*)((char*)this->some_ptr + 0x4A),
                0, 0, 0
            );
        }
    }
}
