// TRIBE_Action_Make_Tech::stop
// VA: 004D2550
// PDB: tact_tek.cpp:138-147
// No EH framing

#include "../../include/game_globals.h"
#include "../../include/tact_tek_context.h"

int TRIBE_Action_Make_Tech::stop()
{
    this->set_state(1);

    TRIBE_Player_Tech* pt = *(TRIBE_Player_Tech**)((char*)this->action_obj->obj_ptr + 0x220);
    pt->cancel_research(this->tech_id, 1);

    ((RGE_Base_Game*)rge_base_game)->notification(
        0x65, *(short*)((char*)this->action_obj->obj_ptr + 0x4A),
        this->tech_id, 0, 0);

    ((TRIBE_Player*)this->action_obj->obj_ptr)->cancelResearch((int)this->tech_id, this->action_obj->player_id, -1, this->unique_id);

    this->action_obj->notify(
        this->action_obj->player_id, this->action_obj->player_id,
        0x1F9, 0x26C, 0, 0);

    return 1;
}
