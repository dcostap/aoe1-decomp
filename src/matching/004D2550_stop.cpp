// TRIBE_Action_Make_Tech::stop
// VA: 004D2550
// PDB: tact_tek.cpp:138-147
// No EH framing

#include "../../include/game_globals.h"
#include "../../include/tact_tek_context.h"

int TRIBE_Action_Make_Tech::stop()
{
    this->set_state(1);

    static_cast<TRIBE_Player*>(this->action_obj->owner)->tech_tree->cancel_research(
        this->tech_id, 1);

    rge_base_game->notification(
        0x65, static_cast<TRIBE_Player*>(this->action_obj->owner)->id,
        this->tech_id, 0, 0);

    static_cast<TRIBE_Player*>(this->action_obj->owner)->cancelResearch(
        (int)this->tech_id, this->action_obj->player_id, -1, this->unique_id);

    this->action_obj->notify(
        this->action_obj->player_id, this->action_obj->player_id,
        0x1F9, 0x26C, 0, 0);

    return 1;
}
