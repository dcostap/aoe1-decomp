#include "../tcommand_context.h"

void TRIBE_Command::do_command_tribe_create(RGE_Command_Create* cmd)
{
    int player_offset = (unsigned int)cmd->player_id * 4;
    int category_offset = (int)cmd->obj_category * 4;

    if (this->world->players[cmd->player_id]->master_objects[cmd->obj_category]->movement_type == 1) {
        cmd->location_z = 4.0f;
    }

    RGE_Static_Object* obj = this->world->players[cmd->player_id]->master_objects[cmd->obj_category]->make_new_obj(
        this->world->players[cmd->player_id],
        cmd->location_x,
        cmd->location_y,
        cmd->location_z);

    if (obj->master_obj->master_type == 0x50) {
        ((TRIBE_Building_Object*)obj)->build(10000.0f);
    }
}
