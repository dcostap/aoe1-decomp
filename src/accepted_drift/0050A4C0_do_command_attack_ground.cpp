// VA: 0050A4C0 TRIBE_Command::do_command_attack_ground
// PDB: tcommand.cpp lines 688-703.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
#include "../tcommand_context.h"

void TRIBE_Command::do_command_attack_ground(TRIBE_Command_Attack_Ground* packet)
{
    RGE_Obj_Info* ids = (RGE_Obj_Info*)(packet + 1);
    unsigned int count = (unsigned int)packet->unit_num;
    if ((int)count <= 0) {
        return;
    }
    do {
        RGE_Static_Object* object = this->get_obj(*ids);
        if (object != 0) {
            object->attack(packet->location_x, packet->location_y, 0.0f, 1);
        }
        ++ids;
        --count;
    } while (count != 0);
}
