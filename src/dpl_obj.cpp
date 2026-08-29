
#include "../include/dpl_obj.h"
#include "../include/ani_obj.h"
#include "../include/asp_list.h"
#include "../include/color.h"
#include "../include/map.h"
#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/stat_obj.h"
#include "../include/world.h"
#include "../include/game_globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma intrinsic(memcpy)

extern float DAT_00570418;
extern FILE* DDlogf;

RGE_Doppleganger_Object::RGE_Doppleganger_Object(
    RGE_Master_Doppleganger_Object* master, RGE_Player* player, float x,
    float y, float z, int doSetup, RGE_Static_Object* doppled)
    : RGE_Animated_Object(master, player, x, y, z, 0)
{
    this->doppled_object = 0;
    this->draw_color = 0;
    this->doppled_master_obj = 0;
    this->doppled_player = 0;
    this->MapAddress = 0;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    this->map_draw_level = 0;
    this->map_color = 0;
    this->doppledObjectID = -1;

    if (doSetup != 0) {
        this->setup(master, player, x, y, z);
    }

    this->doppled_object = doppled;
    if (this->doppled_object != 0) {
        this->doppled_master_obj = this->doppled_object->master_obj;
        this->doppled_player = this->doppled_object->owner->id;
        this->doppledObjectID = this->doppled_object->id;
        this->sprite = this->doppled_object->sprite;
        this->sprite_list->use_sprite_list(
            this->doppled_object->sprite_list->copy_sprite_list());
        this->facet = this->doppled_object->facet;
        this->draw_color = this->doppled_object->owner->color_table;
        this->map_draw_level = this->doppled_object->master_obj->map_draw_level;
        if (this->map_draw_level == 3) {
            this->map_color = this->doppled_object->master_obj->map_color;
        } else {
            this->map_color = this->doppled_object->owner->color_table->map_color;
        }
        if (this->doppled_object->object_state >= 7) {
            this->doppled_object = 0;
            this->doppledObjectID = -1;
        }
    } else {
        this->doppledObjectID = -1;
        this->doppled_master_obj = 0;
        this->doppled_player = 0;
        this->destroy_obj();
    }
    this->validate();
}

RGE_Doppleganger_Object::RGE_Doppleganger_Object(
    int handle, RGE_Game_World* world, int param_3)
    : RGE_Animated_Object(handle, world, 0)
{
    int value;

    this->doppled_object = 0;
    this->draw_color = 0;
    this->doppled_master_obj = 0;
    this->doppled_player = 0;
    this->MapAddress = 0;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    this->map_draw_level = 0;
    this->map_color = 0;
    this->doppledObjectID = -1;

    if (param_3 != 0) {
        this->setup(handle, world);
    }

    rge_read(handle, &value, 4);
    this->doppled_object = (RGE_Static_Object*)(size_t)value;
    this->doppledObjectID = -1;
    rge_read(handle, &this->map_draw_level, 1);
    rge_read(handle, &this->map_color, 4);
    rge_read(handle, &value, 4);
    this->doppled_master_obj = (RGE_Master_Static_Object*)(size_t)value;
    rge_read(handle, &this->doppled_player, 4);

    if (save_game_version >= 7.06f) {
        rge_read(handle, &this->CantSeeBits, 4);
    }
}

void RGE_Doppleganger_Object::recycle_in_to_game(
    RGE_Master_Static_Object* param_1,
    RGE_Player* param_2,
    float param_3,
    float param_4,
    float param_5,
    RGE_Static_Object* param_6)
{
    this->doppled_object = 0;
    this->draw_color = 0;
    this->doppled_master_obj = 0;
    this->doppled_player = 0;
    this->MapAddress = 0;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    this->map_draw_level = 0;
    this->map_color = 0;
    this->doppledObjectID = -1;

    RGE_Animated_Object::recycle_in_to_game(param_1, param_2, param_3,
                                            param_4, param_5);

    this->type = 0x19;

    this->doppled_object = param_6;

    if (param_6 != 0) {
        this->doppled_master_obj = param_6->master_obj;
        this->doppled_player = param_6->owner->id;
        this->doppledObjectID = param_6->id;
        this->sprite = param_6->sprite;

        RGE_Active_Sprite_Node* newNode =
            param_6->sprite_list->copy_sprite_list();
        this->sprite_list->use_sprite_list(newNode);

        RGE_Static_Object* obj = this->doppled_object;
        this->facet = obj->facet;
        this->draw_color = obj->owner->color_table;

        unsigned char ml = obj->master_obj->map_draw_level;
        this->map_draw_level = ml;

        if (ml == 3) {
            this->map_color = obj->master_obj->map_color;
        } else {
            this->map_color = obj->owner->color_table->map_color;
        }

        int row = (int)(long)param_4;
        int col = (int)(long)param_3;
        unsigned long* mapAddr = unified_map_offsets[row] + col;

        this->LastMapValue = 0;
        this->CantSeeBits = 0;
        this->MapAddress = mapAddr;

        if (obj->object_state >= 7) {
            this->doppled_object = 0;
            this->doppledObjectID = -1;
            this->validate();
            return;
        }
    } else {
        this->doppledObjectID = -1;
        this->doppled_master_obj = 0;
        this->doppled_player = 0;
        this->destroy_obj();
    }

    this->validate();
}

int RGE_Doppleganger_Object::setup(
    RGE_Master_Doppleganger_Object* master, RGE_Player* player, float x,
    float y, float z)
{
    this->RGE_Animated_Object::setup(master, player, x, y, z);
    this->type = 0x19;
    int y_i = (int)y;
    int x_i = (int)x;
    this->MapAddress = unified_map_offsets[y_i] + x_i;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    return 1;
}

int RGE_Doppleganger_Object::setup(int param_1, RGE_Game_World* param_2)
{
    RGE_Animated_Object::setup(param_1, param_2);
    int x = (int)(long)(this->world_y);
    this->type = 0x19;
    int y = (int)(long)(this->world_x);
    this->MapAddress = unified_map_offsets[x] + y;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    return 1;
}

void RGE_Doppleganger_Object::rehook()
{
    RGE_Player* player;
    int player_index;

    RGE_Static_Object::rehook();

    if ((long)this->doppled_object >= 0) {
        this->doppled_object =
            this->get_object_pointer((long)this->doppled_object);
        if (this->doppled_object == 0) {
            goto second_part;
        }
        this->doppledObjectID = this->doppled_object->id;
        this->draw_color = this->doppled_object->owner->color_table;
    } else {
        player_index = -1 - (long)this->doppled_object;
        this->doppled_object = 0;
        this->doppledObjectID = -1;
        this->draw_color =
            this->owner->world->players[player_index]->color_table;
    }

second_part:
    if ((long)this->doppled_master_obj >= 0) {
        player = this->owner->world->players[this->doppled_player];
        if ((long)this->doppled_master_obj < player->master_object_num) {
            this->doppled_master_obj =
                player->master_objects[(long)this->doppled_master_obj];
            return;
        }
    }

    this->doppled_master_obj = 0;
    this->destroy_obj();
}

unsigned char RGE_Doppleganger_Object::update()
{
    unsigned char result = RGE_Animated_Object::update();

    if (this->doppled_object == 0) {
        this->doppledObjectID = -1;
    } else if (this->doppled_object->object_state >= 7) {
        this->doppled_object = 0;
        this->doppledObjectID = -1;
    }

    unsigned long uVar1 = *this->MapAddress;
    if (uVar1 != this->LastMapValue) {
        if ((this->owner->mutualVisibleMask & uVar1) != 0 &&
            this->object_state < 3) {
            if (DDlogf != 0) {
                fprintf(DDlogf, "DIE DOP (@%d) id=%d own=%d\n",
                    this->owner->world->world_time,
                    this->id,
                    this->owner->id);
            }
            this->destroy_obj();
        }

        unsigned long uVar4 = this->owner->nonMutualVisibleMask & uVar1;
        if (uVar4 != 0) {
            unsigned long* puVar5 = this->owner->RemoveVisibleBits;
            do {
                if ((uVar4 & 1) == 1) {
                    this->CantSeeBits |= *puVar5;
                }
                puVar5++;
                uVar4 >>= 1;
            } while (uVar4 != 0);
        }
        this->LastMapValue = uVar1;
    }

    return result;
}

void RGE_Doppleganger_Object::save(int file)
{
    int handle = file;

    RGE_Animated_Object::save(file);

    if (this->doppled_object != NULL) {
        file = this->doppled_object->id;
    } else {
        file = -1 - this->doppled_player;
    }
    rge_write(handle, &file, 4);
    rge_write(handle, &this->map_draw_level, 1);
    rge_write(handle, &this->map_color, 4);

    if (this->doppled_master_obj != NULL) {
        file = this->doppled_master_obj->id;
    } else {
        file = -1;
    }
    rge_write(handle, &file, 4);
    rge_write(handle, &this->doppled_player, 4);

    if (save_game_version >= DAT_00570418) {
        rge_write(handle, &this->CantSeeBits, 4);
    }
}

void RGE_Doppleganger_Object::validate()
{
    int row = (int)this->world_y;
    int col = (int)this->world_x;
    RGE_Object_Node* entry =
        this->owner->world->map->map_row_offset[row][col].objects.list;

    if (entry != 0) {
        unsigned char checkVal = 2;

        do {
            RGE_Doppleganger_Object* obj =
                (RGE_Doppleganger_Object*)entry->node;
            if (obj != 0 &&
                obj->type == 0x19 &&
                obj->id != this->id &&
                obj->doppledObjectID == this->doppledObjectID &&
                obj->object_state == checkVal) {

                short s = this->owner->id;
                if (obj->owner->id == s) {
                    obj->destroy_obj();
                } else {
                    obj->CantSeeBits |= 1 << s;
                    this->CantSeeBits |= 1 << obj->owner->id;
                }
            }
            entry = entry->next;
        } while (entry != 0);
    }
}

RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(
    RGE_Player* player, int count)
{
    this->Objects = (RGE_Static_Object**)calloc(count, 4);
    this->Map_Addresses = (unsigned long**)calloc(count, 4);
    this->Last_Map_Value = (unsigned long*)calloc(count, 4);
    this->Object_ids = (int*)calloc(count, 4);
    this->allocated_size = count;
    this->active_size = 0;
    this->owner = player;
    if (DDlogf == 0) {
        DDlogf = fopen("c:\\aoedoppl.txt", "w");
    }
}

RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator()
{
    if (this->Objects != 0) {
        free(this->Objects);
    }
    if (this->Map_Addresses != 0) {
        free(this->Map_Addresses);
    }
    if (this->Last_Map_Value != 0) {
        free(this->Last_Map_Value);
    }
    if (this->Object_ids != 0) {
        free(this->Object_ids);
    }
    if (DDlogf != 0) {
        fclose(DDlogf);
        DDlogf = 0;
    }
}

int RGE_Doppleganger_Creator::add_doppleganger_check(
    RGE_Static_Object* obj, unsigned long* map_addr)
{
    if (DDlogf) {
        fprintf(DDlogf, "ADC (@%d) p=%d  id=%d\n",
            this->owner->world->world_time,
            (int)this->owner->id,
            obj->id);
    }

    if (this->active_size >= this->allocated_size) {
        this->expand_allocations(30);
    }

    if (obj->owner->id != this->owner->id) {
        return 0;
    }

    int count = this->active_size;
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            if (this->Objects[i] == obj) {
                return 0;
            }
        }
    }

    this->Objects[this->active_size] = obj;
    this->Map_Addresses[this->active_size] = map_addr;
    this->Last_Map_Value[this->active_size] = *map_addr;
    this->Object_ids[this->active_size] = obj->id;
    this->active_size++;

    return 1;
}

int RGE_Doppleganger_Creator::remove_doppleganger_check(
    RGE_Static_Object* obj)
{
    if (DDlogf) {
        fprintf(DDlogf, "RDC (@%d)  p=%d  id=%d\n",
            owner->world->world_time, owner->id, obj->id);
    }

    if (active_size <= 0)
        return 0;

    for (int i = 0; i < active_size; i++) {
        if (Objects[i] == obj) {
            active_size--;
            if (i < active_size) {
                Objects[i] = Objects[active_size];
                Map_Addresses[i] = Map_Addresses[active_size];
                Last_Map_Value[i] = Last_Map_Value[active_size];
                Object_ids[i] = Object_ids[active_size];
            }
            Objects[active_size] = 0;
            Map_Addresses[active_size] = 0;
            Last_Map_Value[active_size] = 0;
            Object_ids[active_size] = 0;
            return 1;
        }
    }

    return 0;
}

void RGE_Doppleganger_Creator::perform_doppleganger_checks()
{
    unsigned long map_value;
    int i;
    RGE_Static_Object* remove_me = 0;

    if (this->active_size > 0) {
        for (i = 0; i < this->active_size; i++) {
            map_value = *this->Map_Addresses[i];
            if (map_value != this->Last_Map_Value[i]) {
                if (this->Objects[i] != 0 &&
                    this->owner->world->object(this->Object_ids[i]) ==
                        this->Objects[i]) {
                    unsigned long mask =
                        ((this->Last_Map_Value[i] ^ map_value) >> 1) &
                        (this->Last_Map_Value[i] >> 1) & 0x7fff;
                    for (int player_id = 1; mask != 0;
                         player_id++, mask >>= 1) {
                        if ((mask & 1) == 1) {
                            int owner_id = (int)this->owner->id;
                            if (player_id != owner_id) {
                                if (DDlogf) {
                                    fprintf(DDlogf,
                                        "NEW DOP (@%d) by p=%d for p=%d of id=%d (x=%d, y=%d)\n",
                                        this->owner->world->world_time,
                                        owner_id,
                                        player_id,
                                        this->Objects[i]->id,
                                        (long)this->Objects[i]->world_x,
                                        (long)this->Objects[i]->world_y);
                                }
                                RGE_Player* player =
                                    this->owner->world->players[player_id];
                                ((RGE_Master_Doppleganger_Object*)
                                    player->master_objects[0xf3])->make_new_obj(
                                        player,
                                        this->Objects[i]->world_x,
                                        this->Objects[i]->world_y,
                                        this->Objects[i]->world_z,
                                        this->Objects[i]);
                            }
                        }
                    }
                } else {
                    remove_me = this->Objects[i];
                    if (DDlogf) {
                        fprintf(DDlogf,
                            "*** REMOVE CHECK (@%d) by p=%d id=%d\n",
                            this->owner->world->world_time,
                            (int)this->owner->id,
                            this->Object_ids[i]);
                    }
                }
                this->Last_Map_Value[i] = map_value;
            }
        }
        if (remove_me != 0) {
            this->remove_doppleganger_check(remove_me);
        }
    }

    return;
}

void RGE_Doppleganger_Creator::expand_allocations(int grow_size)
{
    if (DDlogf != 0) {
        fprintf(DDlogf, "RESIZE (@%d) p=%d  grow=%d\n",
            this->owner->world->world_time,
            (int)this->owner->id,
            grow_size);
    }

    this->allocated_size += grow_size;

    void* r0 = calloc(this->allocated_size, 4);
    void* r1 = calloc(this->allocated_size, 4);
    void* r2 = calloc(this->allocated_size, 4);
    void* r3 = calloc(this->allocated_size, 4);

    memcpy(r0, this->Objects, this->active_size * 4);
    memcpy(r1, this->Map_Addresses, this->active_size * 4);
    memcpy(r2, this->Last_Map_Value, this->active_size * 4);
    memcpy(r3, this->Object_ids, this->active_size * 4);

    free(this->Objects);
    free(this->Map_Addresses);
    free(this->Last_Map_Value);
    free(this->Object_ids);

    this->Objects = (RGE_Static_Object**)r0;
    this->Map_Addresses = (unsigned long**)r1;
    this->Last_Map_Value = (unsigned long*)r2;
    this->Object_ids = (int*)r3;
}
