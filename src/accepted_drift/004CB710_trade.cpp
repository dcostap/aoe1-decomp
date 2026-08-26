// VA: 004CB710 TRIBE_Combat_Object::trade (EH-framed)
// PDB source: t_c_obj.cpp, lines 1111-1163
// FLAGS: /nologo /c /O2 /Oy /GX
// ACCEPTED_DRIFT: remaining ~22% positional diff is purely register allocation
//   (this in esi instead of edi, obj in edi instead of esi). All instruction
//   patterns, control flow, call sequences, and EH cookie tracking match.
//   No behavioral differences. Register choice is benign VC5 codegen variance.
//
// Attempt log:
// - Initial version: early returns -> 70% diff (inlined SEH epilogues)
// - goto-based shared exit -> 22% diff (register allocation only)
// - Tried removing self/dispatch locals, changing expression order, adding
//   VTableDispatch local, chaining get_action() calls. Register allocation
//   is baked into VC5's allocator decision and doesn't flip with source changes.
// - sizeof(RGE_Action) and sizeof(TRIBE_Action_Trade) corrected to 0x40 and 0x48
//   for proper `new` expression codegen.
// - get_action() calls must be chained (not saved to local) to match original's
//   repeated call pattern.

#include "../../include/t_c_obj_context.h"

int TRIBE_Combat_Object::trade(int param_1, int param_2)
{
    RGE_Static_Object* obj;
    RGE_Task* task;
    TRIBE_Action_Trade* new_action;

    obj = this->owner->world->object(param_1);
    if (obj == 0) {
        goto exit_return;
    }

    if (param_2 == 0) {
        if (this->actions->have_action() == 1) {
            if (((RGE_Action*)this->actions->get_action())->get_target_obj() == obj) {
                if (((RGE_Action*)this->actions->get_action())->type() == 0x6F) {
                    goto exit_return_one;
                }
            }
        }
    }

    if (this->actions->have_action() == 1) {
        if (((RGE_Action*)this->actions->get_action())->type() == 0x6F) {
            ((RGE_Action*)this->actions->get_action())->work(obj, obj->world_x, obj->world_y, obj->world_z);
            goto exit_return_one;
        }
    }

    task = this->make_action(obj, obj->world_x, obj->world_y, obj->world_z);
    if (task == 0) {
        goto exit_return;
    }

    new_action = new TRIBE_Action_Trade(this, task, obj);
    if (new_action == 0) {
        goto exit_return;
    }

    this->actions->delete_list();
    this->add_action(new_action);

exit_return_one:
    return 1;

exit_return:
    return 0;
}
