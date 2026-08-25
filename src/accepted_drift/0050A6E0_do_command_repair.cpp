// VA: 0050A6E0 TRIBE_Command::do_command_repair
// PDB: tcommand.cpp lines 795-815.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
#include "../tcommand_context.h"

void TRIBE_Command::do_command_repair(TRIBE_Command_Repair* packet)
{
    int target_id = packet->target.id;
    unsigned char unit_count = packet->unit_num;
    RGE_Obj_Info* ids = (RGE_Obj_Info*)(packet + 1);
    RGE_Static_Object* target = this->get_obj(target_id);

    if ((int)unit_count > 0) {
        do {
            RGE_Static_Object* object = this->get_obj(ids->id);
            if (object != 0) {
                ((TRIBE_Combat_Object*)object)->do_repair(target);
            }
            ++ids;
            --unit_count;
        } while (unit_count != 0);
    }
}
