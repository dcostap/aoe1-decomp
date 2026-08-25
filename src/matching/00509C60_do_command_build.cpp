// VA: 00509C60 TRIBE_Command::do_command_build
// PDB: tcommand.cpp lines 256-331.
#include "../tcommand_context.h"

void TRIBE_Command::do_command_build(TRIBE_Command_Build* cmd)
{
    RGE_Static_Object* blockingObject;
    int placement;
    uchar placementResult;
    int count = cmd->count;
    RGE_Static_Object* obj;
    volatile TRIBE_Command* self_volatile = this;
    TRIBE_Command* self = (TRIBE_Command*)self_volatile;

    TRIBE_Player* player = (TRIBE_Player*)self->world->players[cmd->player_id];
    if (player == 0) {
        return;
    }
    if (cmd->obj_id == -1) {
        return;
    }

    TRIBE_Master_Building_Object* info =
        (TRIBE_Master_Building_Object*)player->master_objects[cmd->obj_id];
    if (info == 0) {
        return;
    }

    placementResult = ((RGE_Master_Static_Object*)info)->check_placement((RGE_Player*)player, cmd->x, cmd->y,
                                            &placement,
                                            1, 1, 1, 1, 1, 1);
    if (placementResult != 0) {
        if (count > 0) {
            obj = self->get_obj(*(RGE_Obj_Info*)(cmd + 1));
            if (obj != 0) {
                player->cancelBuild(placementResult, placement,
                                    cmd->obj_id, cmd->x, cmd->y, cmd->unique_id,
                                    obj->id);
            }
        }
        return;
    }

    if (!player->pay_obj_cost(cmd->obj_id, 1.0f, 0)) {
        if (count <= 0) {
            return;
        }
        obj = self->get_obj(*(RGE_Obj_Info*)(cmd + 1));
        if (obj == 0) {
            return;
        }
        player->cancelBuild(0, placement, cmd->obj_id,
                            cmd->x, cmd->y, cmd->unique_id, obj->id);
        return;
    }

    blockingObject = info->make_new_obj((RGE_Player*)player, cmd->x, cmd->y, 0,
                                        cmd->unique_id);
    if (count <= 0) {
        return;
    }

    RGE_Obj_Info* idp = (RGE_Obj_Info*)(cmd + 1);
    int n = count;
    do {
        obj = self->get_obj(*idp);
        if (obj != 0) {
            obj->removeAllFromPathingGroup();
            obj->do_command(blockingObject, cmd->x, cmd->y, 0.0f);
        }
        ++idp;
        --n;
    } while (n != 0);
}
