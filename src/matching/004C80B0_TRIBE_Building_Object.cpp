// VA: 004C80B0, TRIBE_Building_Object::TRIBE_Building_Object, 282 bytes
// Source: t_b_obj.cpp lines 93-103
// Status: MATCH
//
// Constructor for TRIBE_Building_Object. Accepts 6 params (this + 6 stack):
//   TRIBE_Master_Building_Object* mb, RGE_Player* player,
//   float f1, float f2, float f3, int flag
// Returns `ret 18h` (6 params × 4 = 0x18).
//
// Function flow:
// 1. SEH prologue: push -1 cookie, push __except_handler3, save/install FS:[0],
//    push ecx (save this as local)
// 2. Load params (param_3→eax, param_1→edx, param_4→ebp, param_5→edi)
// 3. Save regs (ebx, ebp, esi, edi), zero ebx
// 4. Call TRIBE_Combat_Object(this, mb, player, f1, f2, f3, 0)
// 5. SEH cookie = 0 (survived base ctor)
// 6. production_queue_need_attr = -1 (ax from or eax,-1)
// 7. unique_build_id = -1 (eax)
// 8. production_queue = 0, size=0, count=0, enabled=1, actions=0,
//    change_flag=0, auto_paused=0, DoppleInstalled=0
// 9. vftable = TRIBE_Building_Object vftable
// 10. If flag != 0: setup(mb, player, f1, f2, f3)
// 11. ftol(world_y) → row; ftol(world_x) → col
// 12. DoppleInstalled = owner->doppleganger_creator
//        ->add_doppleganger_check(this, &unified_map_offsets[row] + col*4)
// 13. PriorMap1-3 = 0, PriorTurn1-3 = 0
// 14. SEH epilogue: restore FS:[0] from saved local
// 15. return this
//
// Matching notes:
// - Default /O2 /Oy omitted the constructor EH chain; the donor-proven /GX
//   context emits the original VC5 FS:[0] registration and cleanup.
// - The root polymorphic base preserves the proven offset-zero vptr and the
//   named +0x0C owner, +0x38/+0x3C world coordinates, and +0x1C8 fields.
// - The initial body-assignment reconstruction was 282 bytes with exact
//   size/frame/call/CFG parity but a 33-byte implicit-vptr scheduling hunk.
// - A diagnostic split of the queue fields into a nonvirtual inline base made
//   the first mismatch earlier and grew the diff to 55 bytes; it was rolled
//   back. Moving the virtual declarations before the fields was codegen-neutral.
// - The period-plausible member-initializer-list form below schedules the
//   queue/state stores and compiler-managed derived vptr exactly like the
//   oracle, without an explicit vptr store or novtable workaround. It is an
//   exact 282-byte match.
// - Restored the donor-proven virtual int setup declaration; it is part of the
//   exact ABI surface. Typed player/master/global map ownership is retained.
// FLAGS: /nologo /c /O2 /Oy /GX
// Main-agent audit restored canonical master/player destructor ownership and
// retained natural compiler-managed vptr lowering.

#include <stddef.h>

#include "../../include/t_b_obj_context.h"

TRIBE_Building_Object::TRIBE_Building_Object(TRIBE_Master_Building_Object* mb, RGE_Player* player,
                                              float f1, float f2, float f3, int flag)
    : TRIBE_Combat_Object(mb, player, f1, f2, f3, 0),
      production_queue(0),
      production_queue_size(0),
      production_queue_count(0),
      production_queue_enabled(1),
      production_queue_actions(0),
      production_queue_change_flag(0),
      production_queue_auto_paused(0),
      production_queue_need_attr(-1),
      unique_build_id(-1),
      DoppleInstalled(0)
{
    if (flag != 0) {
        this->setup(mb, player, f1, f2, f3);
    }

    int row = (int)this->world_y;
    int col = (int)this->world_x;

    this->DoppleInstalled = this->owner->doppleganger_creator->add_doppleganger_check(
        this, unified_map_offsets[row] + col);

    this->PriorMap1 = 0;
    this->PriorMap2 = 0;
    this->PriorMap3 = 0;
    this->PriorTurn1 = 0;
    this->PriorTurn2 = 0;
    this->PriorTurn3 = 0;
}
