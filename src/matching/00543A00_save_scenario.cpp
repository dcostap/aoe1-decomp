// 00543A00 RGE_Game_World::save_scenario (World.cpp:2186-2305)
// Attempt log:
// try 1: packet-grounded reconstruction derived the .scn path and serialized
// player object lists. A helper-factored form was 832 bytes, not 1017 bytes.
// try 2: separate expansion for both object lists reached 976 bytes.
// try 3: diagnostic extra writes reached comparison but caused broad drift.
// The rebuilt prologue saved EBX and missed the original EBP=this schedule.
// try 4: modeled the filename copy through the byte before the first dot.
// The final path uses the base-game program-info pointer plus 0xc17.
// try 5: modeled the TRIAL selection between 1.10 and 1.11.
// try 6: modeled the +0x68 world value, Scenario, Map, and player-count writes.
// try 7: modeled pre-save virtual +0x64 and post-save virtual +0x6c loops.
// try 8: counted both +0x28 and +0x2c lists, excluding master type 0x19.
// try 9: modeled x/y/z, object id, master id, state, and angle or facet.
// probes 10-15: restored real World, Scenario, Map, Player, object-node,
// static-object, and master ownership. Removed the per-player alias.
// probe 16: binary evidence proved the fourth dword is static-object id +0x04,
// not the object-node next pointer.
// Source audit: donor-backed method names replaced generated virtual slots.
// All serialized ownership remains typed and named.
// Result: MATCH (1017/1017 bytes, 0.0000%), default flags.

#include "../../include/world_scenario_context.h"

typedef unsigned char byte;

byte RGE_Game_World::save_scenario(char* name)
{
    char scenario_name[300];
    char kill_name[300];
    int scenario_player_num = (short)this->player_num;
    int i;
    float obj_angle;
    int count;
    char* p = name;
    int n = 0;

    do {
        kill_name[n++] = *p++;
    } while (*p != '.');
    kill_name[n] = 0;

    sprintf(scenario_name, "%s%s.scn", rge_base_game->save_prog_info->scenario_dir, kill_name);
    unlink(scenario_name);
    sprintf(scenario_name, "%s%s", rge_base_game->save_prog_info->scenario_dir, name);
    int fd = rge_open(scenario_name, 0x8301, 0x180);
    if (fd != -1) {
        rge_write_error = 0;
        if (rge_base_game->check_prog_argument("TRIAL") == 1) {
            rge_write_uncompressed(fd, "1.10", 4);
        } else {
            rge_write_uncompressed(fd, "1.11", 4);
        }
        rge_base_game->write_scenario_header(fd);
        rge_write(fd, &this->next_object_id, 4);
        this->scenario->save(fd);
        this->map->scenario_save(fd);
        rge_write(fd, &scenario_player_num, 4);

        for (i = 1; i < (short)this->player_num; ++i) {
            this->players[i]->scenario_save(fd);
        }

        for (i = 0; i < (short)this->player_num; ++i) {
            count = 0;
            RGE_Object_Node* o = this->players[i]->objects->list;
            while (o) {
                if (o->object->master_obj->master_type != 0x19) ++count;
                o = o->next;
            }
            o = this->players[i]->sleeping_objects->list;
            while (o) {
                if (o->object->master_obj->master_type != 0x19) ++count;
                o = o->next;
            }
            rge_write(fd, &count, 4);

            o = this->players[i]->objects->list;
            while (o) {
                if (o->object->master_obj->master_type != 0x19) {
                    rge_write(fd, &o->object->world_x, 4);
                    rge_write(fd, &o->object->world_y, 4);
                    rge_write(fd, &o->object->world_z, 4);
                    rge_write(fd, &o->object->id, 4);
                    rge_write(fd, &o->object->master_obj->id, 2);
                    rge_write(fd, &o->object->object_state, 1);
                    if (o->object->master_obj->master_type > 0x1e &&
                        o->object->master_obj->master_type < 0x5a) {
                        obj_angle = o->object->angle;
                    } else {
                        obj_angle = (float)o->object->facet;
                    }
                    rge_write(fd, &obj_angle, 4);
                }
                o = o->next;
            }

            o = this->players[i]->sleeping_objects->list;
            while (o) {
                if (o->object->master_obj->master_type != 0x19) {
                    rge_write(fd, &o->object->world_x, 4);
                    rge_write(fd, &o->object->world_y, 4);
                    rge_write(fd, &o->object->world_z, 4);
                    rge_write(fd, &o->object->id, 4);
                    rge_write(fd, &o->object->master_obj->id, 2);
                    rge_write(fd, &o->object->object_state, 1);
                    if (o->object->master_obj->master_type > 0x1e &&
                        o->object->master_obj->master_type < 0x5a) {
                        obj_angle = o->object->angle;
                    } else {
                        obj_angle = (float)o->object->facet;
                    }
                    rge_write(fd, &obj_angle, 4);
                }
                o = o->next;
            }
        }

        rge_write(fd, &scenario_player_num, 4);
        for (i = 1; i < (short)this->player_num; ++i) {
            this->players[i]->scenario_postsave(fd);
        }
        rge_close(fd);
        if (rge_write_error) {
            unlink(scenario_name);
            return 0;
        }
        return 1;
    }
    return 0;
}
