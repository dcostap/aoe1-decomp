// 0045BE80 TMousePointer::set_game_facet
//
// BLOCKER: best source has exact registers, size, and all body bytes except a
// four-byte scheduling shift around the first ESI save/shape_info load. Original:
//   mov eax,[ecx+58h]; mov [ecx+8Ch],edx; shl edx,5; mov eax,[eax+1Ch]; push esi; add eax,edx
// Rebuilt best:
//   mov eax,[ecx+58h]; push esi; mov eax,[eax+1Ch]; mov [ecx+8Ch],edx; shl edx,5; add eax,edx
// The rest of the stores/subtractions/epilogue match exactly.
//
// Attempt log:
// 1. Prior typed/local f source exact size/body mostly matches, but uses EAX for facet and saves ESI early.
// 2. Direct raw pointer expression using facet parameter: got EDX facet, but saved EDI/ESI early.
// 3. Direct facet with game_facet store before info calculation: optimized back to EAX facet.
// 4. Offset temp + shape temp: same EAX facet/early ESI.
// 5. Mutating incoming facet parameter after store: same EAX facet.
// 6. Shape_Info base local, then store, then add scaled facet: best; EDX facet correct, only push/load shape_info four bytes early.
// 7. Uninitialized info + shape local: regressed to EAX facet.
// 8. Explicit hotspot_y local and commuted bottom expression: no change from best.
// 9. variant_lab over combined/nested guards, five info/store/order shapes, direct/local/commuted bottom, and vc5-small flags: no exact. Only five asm families; best remains base-before shape with edit diff 8.
// 10. Follow-up tried store-before-info, raw shape pointer, int base, mutating facet, direct array, and repeated direct array accesses; all regressed to EAX-facet/ESI-base or extra saved-register families.
// 11. Tried block-scoped bottom temp, volatile/nonvolatile hotspot_y temp, raw bottom field load, and split shape_info statements; best-family variants kept the same 4-byte schedule drift, volatile temp was worse.
// 12. Flag probes /Ob0, /Og, /Ot no effect; /Oa regressed, /Os and /O1 were wrong-size. No per-function flag kept.
// ACCEPTED_DRIFT: reviewed by Boss. Behavior and all non-scheduling bytes are
// correct. Remaining drift is a localized independent-instruction scheduling shift:
// rebuilt saves esi and loads shape_info before storing game_facet/shifting facet,
// while original stores game_facet and shifts first. The same values are used, all
// later stores/subtractions match, and size/epilogue are intact (no truncation).

#include "../../include/mouseptr_context.h"

void TMousePointer::set_game_facet(int facet) {
    if (facet >= 0 && facet < this->Num_Cursors) {
        Shape_Info* info = this->Cursor_Shape->shape_info;
        this->game_facet = facet;
        info = (Shape_Info*)((char*)info + (facet << 5));
        this->gWidth = info->Width;
        this->gHeight = info->Height;
        this->g_top = info->Hotspot_Y;
        this->g_left = info->Hotspot_X;
        this->g_right = this->gWidth - info->Hotspot_X;
        this->g_bottom = this->gHeight - info->Hotspot_Y;
    }
}
