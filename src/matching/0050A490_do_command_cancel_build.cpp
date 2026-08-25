// VA: 0050A490 TRIBE_Command::do_command_cancel_build
// PDB: tcommand.cpp lines 671-683.
#include "../tcommand_context.h"

void TRIBE_Command::do_command_cancel_build(TRIBE_Command_Cancel_Build* cmd)
{
    RGE_Static_Object* object = this->world->object(cmd->unit_id);
    if (object != 0) {
        object->cancel_object();
    }
}
