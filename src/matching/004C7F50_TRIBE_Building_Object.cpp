// VA: 004C7F50, TRIBE_Building_Object::TRIBE_Building_Object
// PDB source: t_b_obj.cpp:57-76
//
// Canonical reconstruction: this is the seven-argument load/new constructor.
// The base and production-queue ownership are named rather than represented by
// decompiler cursor arithmetic.  The executable stores the derived vftable
// after the queue initializers. This source uses a member-initializer list and
// leaves vptr lowering to VC5; an explicit store or __declspec(novtable) is
// not an acceptable source model.
//
// Attempt log:
// - Typed the complete Static/Moving/Action/Combat base chain, master task
//   fields, player vptr/creator ownership, tile-table pointer array, and the
//   production-queue members. This reaches the original 311-byte size, frame,
//   saved registers, calls, CFG, and all post-constructor bytes.
// - Adding the proven player vptr is a codegen duplicate; it is retained for
//   canonical layout.
// - Restored the donor-proven virtual int setup, virtual set_task, and
//   TRIBE_Combat_Object destructor declarations; each was codegen-identical.
// - A natural member-initializer list for unique_build_id and the queue fields
//   schedules the compiler-managed derived-vptr store after those fields and
//   reaches an exact 311-byte match. No manual vptr store is used.
//
// FLAGS: /nologo /c /O2 /Oy /GX
// Main-agent audit restored canonical master/player destructor ownership and
// retained natural compiler-managed vptr lowering.

#include "../../include/t_b_obj_context.h"

TRIBE_Building_Object::TRIBE_Building_Object(
    TRIBE_Master_Building_Object* master, RGE_Player* player,
    float x, float y, float z, int unique_id, int do_setup)
    : TRIBE_Combat_Object(master, player, x, y, z, 0),
      production_queue(0),
      production_queue_size(0),
      production_queue_count(0),
      production_queue_enabled(1),
      production_queue_actions(0),
      production_queue_change_flag(0),
      production_queue_auto_paused(0),
      production_queue_need_attr(-1),
      unique_build_id(unique_id),
      DoppleInstalled(0)
{
    if (do_setup != 0) {
        this->setup(master, player, x, y, z);
    }

    RGE_Master_Static_Object* master_object = this->master_obj;
    if (master_object->id == 0x114) {
        this->set_task(master_object->task_id);
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
