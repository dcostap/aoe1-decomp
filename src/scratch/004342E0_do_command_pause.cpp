// VA: 004342E0 RGE_Command::do_command_pause (59B, 27 asm lines)
// PDB source: Command.cpp lines 447-461
// Declare counter inside if block for conditional ebx save;
// id pointer before the if for unconditional esi setup
// BINARY NOTE: The packet stores its first object ID at byte offset +2.
// Keep the packed local view instead of the aligned shared declaration.

#ifndef COMMAND_TU_CONTEXT
// Standalone checks use the same reviewed surface as Command_tu.cpp.
#include "../../include/command_tu_context.h"
#endif

void RGE_Command::do_command_pause(RGE_Command_Pause* pause) {
#pragma pack(push, 1)
    struct RGE_Command_Pause_Packed {
        unsigned char command;
        unsigned char unit_num;
        RGE_Obj_Info object_ids[1];
    };
#pragma pack(pop)
    RGE_Command_Pause_Packed* packet = (RGE_Command_Pause_Packed*)pause;
    int count = packet->unit_num;
    RGE_Obj_Info* id = packet->object_ids;
    if (count > 0) {
        int cnt = count;
        do {
            RGE_Static_Object* obj = this->get_obj(*id);
            if (obj != 0) {
                obj->pause();
            }
            id++;
            cnt--;
        } while (cnt != 0);
    }
}
