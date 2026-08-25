// VA: 0050A140 TRIBE_Command::do_command_explore
// PDB: tcommand.cpp lines 508-527.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
#include "../tcommand_context.h"

void TRIBE_Command::do_command_explore(TRIBE_Command_Explore* cmd)
{
    TRIBE_Command* self = this;
    RGE_Game_World* world = self->world;
    int player_id = cmd->unit_player_id;
    RGE_Obj_Info* ids = cmd->unit_ids;
    if (world->players[player_id] != 0) {
        int i = 0;
        if (cmd->numUnits > 0) {
            do {
                RGE_Static_Object* obj = self->get_obj(*ids);
                if (obj != 0) {
                    obj->removeAllFromPathingGroup();
                    obj->explore((int)cmd->targetXPosition,
                                 (int)cmd->targetYPosition, 1);
                }
                ++i;
                ++ids;
            } while (i < (int)cmd->numUnits);
        }
    }
}
