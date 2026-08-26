// VA: 00509E10 TRIBE_Command::do_command_build_wall
// PDB: tcommand.cpp lines 337-450.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
// BINARY NOTE: The idp alias reproduces the original 500-byte grouped owner.
#include <stdlib.h>
#include "../tcommand_context.h"

void TRIBE_Command::do_command_build_wall(TRIBE_Command_Build_Wall* cmd)
{
    int count = cmd->count;
    RGE_Obj_Info* ids = (RGE_Obj_Info*)(cmd + 1);
    TRIBE_Player* player = (TRIBE_Player*)this->world->players[cmd->player_id];
    if (player == 0) return;
    if (cmd->obj_id == -1) return;
    TRIBE_Master_Building_Object* info =
        (TRIBE_Master_Building_Object*)player->master_objects[cmd->obj_id];
    if (info == 0) return;

    RGE_Static_Object* foundation = 0;
    int dy = abs((int)cmd->y2 - (int)cmd->y1);
    int dx = abs((int)cmd->x2 - (int)cmd->x1);

    if (dy == dx) {
        this->place_line_of_walls(player, info, cmd->unique_id,
                                  cmd->x1, cmd->y1, cmd->x2, cmd->y2,
                                  &foundation);
    } else if (dy >= dx) {
        this->place_line_of_walls(player, info, cmd->unique_id,
                                  cmd->x1, cmd->y1, cmd->x1, cmd->y2,
                                  &foundation);
        uchar x2 = cmd->x2;
        if (cmd->x1 < x2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      (int)cmd->x1 + 1, cmd->y2,
                                      cmd->x2, cmd->y2, &foundation);
        } else if (cmd->x1 > x2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      (int)cmd->x1 - 1, cmd->y2,
                                      cmd->x2, cmd->y2, &foundation);
        }
    } else {
        this->place_line_of_walls(player, info, cmd->unique_id,
                                  cmd->x1, cmd->y1, cmd->x2, cmd->y1,
                                  &foundation);
        uchar y2 = cmd->y2;
        if (cmd->y1 < y2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      cmd->x2, (int)cmd->y1 + 1,
                                      cmd->x2, cmd->y2, &foundation);
        } else if (cmd->y1 > y2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      cmd->x2, (int)cmd->y1 - 1,
                                      cmd->x2, cmd->y2, &foundation);
        }
    }

    if (foundation != 0 && count > 0) {
        int n = count;
        RGE_Obj_Info* idp = ids;
        do {
            RGE_Static_Object* obj = this->get_obj(*idp);
            if (obj != 0) {
                obj->removeAllFromPathingGroup();
                obj->do_command(foundation, foundation->world_x,
                                foundation->world_y, 0.0f);
            }
            ++idp;
            --n;
        } while (n != 0);
    }
}
