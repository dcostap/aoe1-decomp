// TRIBE_Action_Make_Tech::first_in_stack
// VA: 004D23B0
// PDB: tact_tek.cpp:76-98
// No EH framing

#include "../../include/game_globals.h"
#include "../../include/tact_tek_context.h"

void TRIBE_Action_Make_Tech::first_in_stack(unsigned char param_1)
{
    if (!param_1) return;
    if (this->tech_id < 0) return;

    TRIBE_Player_Tech* pt = *(TRIBE_Player_Tech**)((char*)this->action_obj->obj_ptr + 0x220);

    unsigned char result = pt->start_research(this->tech_id, 1, &param_1);
    if (result == 1) {
        this->set_state(6);
        return;
    }

    // Vtable calls for non-match path
    ((TRIBE_Player*)this->action_obj->obj_ptr)->cancelResearch(
        (int)*(short*)&param_1,
        (int)this->tech_id,
        this->action_obj->player_id,
        this->unique_id);

    this->action_obj->notify(
        this->action_obj->player_id,
        this->action_obj->player_id,
        0x1F9, 0x26C, 0, 0);

    this->set_state(1);
}
