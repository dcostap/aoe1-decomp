
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

extern FILE* DDlogf;

RGE_Doppleganger_Object::RGE_Doppleganger_Object(
    RGE_Master_Doppleganger_Object* tobj, RGE_Player* obj_owner, float x,
    float y, float z, int do_setup, RGE_Static_Object* obj_to_dopple)
    : RGE_Animated_Object(tobj, obj_owner, x, y, z, 0) {
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

    if (do_setup != 0) {
        this->setup(tobj, obj_owner, x, y, z);
    }

    this->doppled_object = obj_to_dopple;
    if (this->doppled_object != 0) {
        this->doppled_master_obj = this->doppled_object->master_obj;
        this->doppled_player = this->doppled_object->owner->id;
        this->doppledObjectID = this->doppled_object->id;
        this->sprite = this->doppled_object->sprite;
        this->sprite_list->use_sprite_list(this->doppled_object->sprite_list->copy_sprite_list());
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

RGE_Doppleganger_Object::RGE_Doppleganger_Object(int infile, RGE_Game_World* gworld, int do_setup) : RGE_Animated_Object(infile, gworld, 0) {
    int long_val;

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

    if (do_setup != 0) {
        this->setup(infile, gworld);
    }

    rge_read(infile, &long_val, 4);
    this->doppled_object = (RGE_Static_Object*)(size_t)long_val;
    this->doppledObjectID = -1;
    rge_read(infile, &this->map_draw_level, 1);
    rge_read(infile, &this->map_color, 4);
    rge_read(infile, &long_val, 4);
    this->doppled_master_obj = (RGE_Master_Static_Object*)(size_t)long_val;
    rge_read(infile, &this->doppled_player, 4);

    if (save_game_version >= 7.06f) {
        rge_read(infile, &this->CantSeeBits, 4);
    }
}

void RGE_Doppleganger_Object::recycle_in_to_game(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner, float x, float y, float z, RGE_Static_Object* obj_to_dopple) {
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

    RGE_Animated_Object::recycle_in_to_game(tobj, obj_owner, x, y, z);

    this->type = 0x19;

    this->doppled_object = obj_to_dopple;

    if (obj_to_dopple != 0) {
        this->doppled_master_obj = obj_to_dopple->master_obj;
        this->doppled_player = obj_to_dopple->owner->id;
        this->doppledObjectID = obj_to_dopple->id;
        this->sprite = obj_to_dopple->sprite;

        RGE_Active_Sprite_Node* new_node =
            obj_to_dopple->sprite_list->copy_sprite_list();
        this->sprite_list->use_sprite_list(new_node);

        RGE_Static_Object* obj = this->doppled_object;
        this->facet = obj->facet;
        this->draw_color = obj->owner->color_table;

        unsigned char map_draw_level = obj->master_obj->map_draw_level;
        this->map_draw_level = map_draw_level;

        if (map_draw_level == 3) {
            this->map_color = obj->master_obj->map_color;
        } else {
            this->map_color = obj->owner->color_table->map_color;
        }

        int row = (int)(long)y;
        int col = (int)(long)x;
        unsigned long* map_addr = unified_map_offsets[row] + col;

        this->LastMapValue = 0;
        this->CantSeeBits = 0;
        this->MapAddress = map_addr;

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

int RGE_Doppleganger_Object::setup(RGE_Master_Doppleganger_Object* tobj, RGE_Player* obj_owner, float x, float y, float z) {
    this->RGE_Animated_Object::setup(tobj, obj_owner, x, y, z);
    this->type = 0x19;
    int y_i = (int)y;
    int x_i = (int)x;
    this->MapAddress = unified_map_offsets[y_i] + x_i;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    return 1;
}

int RGE_Doppleganger_Object::setup(int infile, RGE_Game_World* gworld) {
    RGE_Animated_Object::setup(infile, gworld);
    int x = (int)(long)(this->world_y);
    this->type = 0x19;
    int y = (int)(long)(this->world_x);
    this->MapAddress = unified_map_offsets[x] + y;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    return 1;
}

void RGE_Doppleganger_Object::rehook() {
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

unsigned char RGE_Doppleganger_Object::update() {
    unsigned char result = RGE_Animated_Object::update();

    if (this->doppled_object == 0) {
        this->doppledObjectID = -1;
    } else if (this->doppled_object->object_state >= 7) {
        this->doppled_object = 0;
        this->doppledObjectID = -1;
    }

    unsigned long map_value = *this->MapAddress;
    if (map_value != this->LastMapValue) {
        if ((this->owner->mutualVisibleMask & map_value) != 0 && this->object_state < 3) {
            if (DDlogf != 0) {
                fprintf(DDlogf, "DIE DOP (@%d) id=%d own=%d\n", this->owner->world->world_time, this->id, this->owner->id);
            }
            this->destroy_obj();
        }

        unsigned long non_mutual_visible_mask =
            this->owner->nonMutualVisibleMask & map_value;
        if (non_mutual_visible_mask != 0) {
            unsigned long* remove_visible_bits = this->owner->RemoveVisibleBits;
            do {
                if ((non_mutual_visible_mask & 1) == 1) {
                    this->CantSeeBits |= *remove_visible_bits;
                }
                remove_visible_bits++;
                non_mutual_visible_mask >>= 1;
            } while (non_mutual_visible_mask != 0);
        }
        this->LastMapValue = map_value;
    }

    return result;
}

void RGE_Doppleganger_Object::save(int file) {
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

    if (save_game_version >= g_doppleganger_save_version_7_06) {
        rge_write(handle, &this->CantSeeBits, 4);
    }
}

void RGE_Doppleganger_Object::validate() {
    int row = (int)this->world_y;
    int col = (int)this->world_x;
    RGE_Object_Node* entry =
        this->owner->world->map->map_row_offset[row][col].objects.list;

    if (entry != 0) {
        unsigned char check_value = 2;

        do {
            RGE_Doppleganger_Object* obj =
                (RGE_Doppleganger_Object*)entry->node;
            if (obj != 0 && obj->type == 0x19 && obj->id != this->id && obj->doppledObjectID == this->doppledObjectID &&
                obj->object_state == check_value) {

                short owner_id = this->owner->id;
                if (obj->owner->id == owner_id) {
                    obj->destroy_obj();
                } else {
                    obj->CantSeeBits |= 1 << owner_id;
                    this->CantSeeBits |= 1 << obj->owner->id;
                }
            }
            entry = entry->next;
        } while (entry != 0);
    }
}

RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(RGE_Player* player, int initial_size) {
    this->Objects = (RGE_Static_Object**)calloc(initial_size, 4);
    this->Map_Addresses = (unsigned long**)calloc(initial_size, 4);
    this->Last_Map_Value = (unsigned long*)calloc(initial_size, 4);
    this->Object_ids = (int*)calloc(initial_size, 4);
    this->allocated_size = initial_size;
    this->active_size = 0;
    this->owner = player;
    if (DDlogf == 0) {
        DDlogf = fopen("c:\\aoedoppl.txt", "w");
    }
}

RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator() {
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

int RGE_Doppleganger_Creator::add_doppleganger_check(RGE_Static_Object* theObj, unsigned long* UMV_addr) {
    if (DDlogf) {
        fprintf(DDlogf, "ADC (@%d) p=%d  id=%d\n", this->owner->world->world_time, (int)this->owner->id, theObj->id);
    }

    if (this->active_size >= this->allocated_size) {
        this->expand_allocations(30);
    }

    if (theObj->owner->id != this->owner->id) {
        return 0;
    }

    int count = this->active_size;
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            if (this->Objects[i] == theObj) {
                return 0;
            }
        }
    }

    this->Objects[this->active_size] = theObj;
    this->Map_Addresses[this->active_size] = UMV_addr;
    this->Last_Map_Value[this->active_size] = *UMV_addr;
    this->Object_ids[this->active_size] = theObj->id;
    this->active_size++;

    return 1;
}

int RGE_Doppleganger_Creator::remove_doppleganger_check(RGE_Static_Object* theObj) {
    if (DDlogf) {
        fprintf(DDlogf, "RDC (@%d)  p=%d  id=%d\n", owner->world->world_time, owner->id, theObj->id);
    }

    if (active_size <= 0)
        return 0;

    for (int i = 0; i < active_size; i++) {
        if (Objects[i] == theObj) {
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

void RGE_Doppleganger_Creator::perform_doppleganger_checks() {
    unsigned long Unified_Map_Value;
    int i;
    RGE_Static_Object* remove_me = 0;

    if (this->active_size > 0) {
        for (i = 0; i < this->active_size; i++) {
            Unified_Map_Value = *this->Map_Addresses[i];
            if (Unified_Map_Value != this->Last_Map_Value[i]) {
                if (this->Objects[i] != 0 && this->owner->world->object(this->Object_ids[i]) == this->Objects[i]) {
                    unsigned long mask =
                        ((this->Last_Map_Value[i] ^ Unified_Map_Value) >> 1) &
                        (this->Last_Map_Value[i] >> 1) & 0x7fff;
                    for (int player_id = 1; mask != 0; player_id++, mask >>= 1) {
                        if ((mask & 1) == 1) {
                            int owner_id = (int)this->owner->id;
                            if (player_id != owner_id) {
                                if (DDlogf) {
                                    fprintf(DDlogf, "NEW DOP (@%d) by p=%d for p=%d of id=%d (x=%d, y=%d)\n",
                                            this->owner->world->world_time, owner_id, player_id, this->Objects[i]->id,
                                            (long)this->Objects[i]->world_x, (long)this->Objects[i]->world_y);
                                }
                                RGE_Player* player =
                                    this->owner->world->players[player_id];
                                ((RGE_Master_Doppleganger_Object*)
                                    player->master_objects[0xf3])->make_new_obj(player, this->Objects[i]->world_x,
                                                                                this->Objects[i]->world_y, this->Objects[i]->world_z, this->Objects[i]);
                            }
                        }
                    }
                } else {
                    remove_me = this->Objects[i];
                    if (DDlogf) {
                        fprintf(DDlogf, "*** REMOVE CHECK (@%d) by p=%d id=%d\n", this->owner->world->world_time,
                                (int)this->owner->id, this->Object_ids[i]);
                    }
                }
                this->Last_Map_Value[i] = Unified_Map_Value;
            }
        }
        if (remove_me != 0) {
            this->remove_doppleganger_check(remove_me);
        }
    }

    return;
}

void RGE_Doppleganger_Creator::expand_allocations(int grow_size) {
    if (DDlogf != 0) {
        fprintf(DDlogf, "RESIZE (@%d) p=%d  grow=%d\n", this->owner->world->world_time, (int)this->owner->id, grow_size);
    }

    this->allocated_size += grow_size;

    void* new_objects = calloc(this->allocated_size, 4);
    void* new_map_addresses = calloc(this->allocated_size, 4);
    void* TLast_Map_Value = calloc(this->allocated_size, 4);
    void* TObject_ids = calloc(this->allocated_size, 4);

    memcpy(new_objects, this->Objects, this->active_size * 4);
    memcpy(new_map_addresses, this->Map_Addresses, this->active_size * 4);
    memcpy(TLast_Map_Value, this->Last_Map_Value, this->active_size * 4);
    memcpy(TObject_ids, this->Object_ids, this->active_size * 4);

    free(this->Objects);
    free(this->Map_Addresses);
    free(this->Last_Map_Value);
    free(this->Object_ids);

    this->Objects = (RGE_Static_Object**)new_objects;
    this->Map_Addresses = (unsigned long**)new_map_addresses;
    this->Last_Map_Value = (unsigned long*)TLast_Map_Value;
    this->Object_ids = (int*)TObject_ids;
}
