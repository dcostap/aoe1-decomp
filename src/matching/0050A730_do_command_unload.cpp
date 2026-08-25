// VA: 0050A730 TRIBE_Command::do_command_unload
// PDB: tcommand.cpp lines 820-846.

#include "../tcommand_context.h"

void TRIBE_Command::do_command_unload(TRIBE_Command_Unload* cmd)
{
    TRIBE_Command* v_this = this;
    RGE_Obj_Info* v_ids = cmd->unit_ids;
    for (int v_count = (int)cmd->unit_num; v_count > 0; v_count--) {
        RGE_Static_Object* obj = v_this->get_obj(*v_ids);
        if (obj) {
            obj->removeAllFromPathingGroup();
            RGE_Player* owner = obj->owner;
            owner->processAIOrder(
                owner->id, obj->id, 0x2D1, obj->id, owner->id,
                cmd->location_x, cmd->location_y, 0, 1.0f, 1, 0, 100);
        }
        v_ids++;
    }
}
