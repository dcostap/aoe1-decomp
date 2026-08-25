// VA: 00509980 TRIBE_Command::do_command_make
// PDB: tcommand.cpp lines 143-205.
#include "../tcommand_context.h"

void TRIBE_Command::do_command_make(TRIBE_Command_Make* cmd)
{
    short progress;
    short work_target;
    short work_state;
    char work_name[100];
    TRIBE_Building_Object* building;

    building = (TRIBE_Building_Object*)this->world->object(cmd->unit_id);
    if (building != 0) {
        building->work_status(progress, work_target, work_state, work_name, 100);
        if (progress != 0x67 && progress != 0x66) {
            TRIBE_Action_Make_Obj* action = new TRIBE_Action_Make_Obj(building, cmd->train_id, cmd->unique_id, 0);
            if (action != 0) {
                building->add_action(action);
            }
            if (building->unitAI() != 0) {
                building->unitAI()->setCurrentAction(0x26c);
                building->unitAI()->setCurrentTarget(cmd->unique_id, -1, -1.0f, -1.0f, -1.0f);
                return;
            }
            return;
        }
        TRIBE_Player* player = (TRIBE_Player*)this->world->players[cmd->player_index];
        if (player != 0) {
            player->cancelTrain(0, cmd->train_id, cmd->unit_id, cmd->unique_id);
        }
    } else {
        TRIBE_Player* player = (TRIBE_Player*)this->world->players[cmd->player_index];
        if (player != 0) {
            player->cancelTrain(0, cmd->train_id, cmd->unit_id, cmd->unique_id);
        }
    }
}
