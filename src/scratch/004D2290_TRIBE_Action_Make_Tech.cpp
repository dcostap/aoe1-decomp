// TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech destructor
// VA: 004D2290
// PDB: tact_tek.cpp:49-64
// EH-framed, needs /GX
// FLAGS: config/flags/004D2290_TRIBE_Action_Make_Tech.rsp
// added /GX rsp after extract showed EH-framed original; current source now extracts full size but has broad register/layout drift
// likely next fixes mirror matched siblings: accurate RGE_Action_Object layout, no fake extra vptr padding, and typed RGE_Base_Game member-call surface
// applied sibling object layout and typed RGE_Base_Game notify; edit diff improved, but EH prolog still has extra EDI save and destructor tail/register topology remains broad

#include "../../include/game_globals.h"
#include "../../include/tact_tek_context.h"

TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech()
{
    if (this->status != 1) {
        TRIBE_Player_Tech* pt = *(TRIBE_Player_Tech**)((char*)this->action_obj->obj_ptr + 0x220);
        pt->cancel_research(this->tech_id, 0);

        // Check game state
        unsigned char game_state = *(unsigned char*)(*(int*)((char*)rge_base_game + 0x3F4) + 0x1D);
        if (game_state == 0) {
            ((RGE_Base_Game*)rge_base_game)->notification(
                0x65, *(short*)((char*)this->action_obj->obj_ptr + 0x4A),
                this->tech_id, 0, 0);

            ((TRIBE_Player*)this->action_obj->obj_ptr)->cancelResearch((int)this->tech_id, this->action_obj->player_id, -1, this->unique_id);

            this->action_obj->notify(
                this->action_obj->player_id, this->action_obj->player_id,
                0x1F9, 0x26C, 0, 0);
        }
    }
}
