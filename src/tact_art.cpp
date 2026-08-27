#include "../include/tact_art.h"
#include <stdlib.h>
#include <string.h>

extern double DAT_00574f08;
extern float DAT_00574f10;
extern float DAT_00574f14;

// PDB lines 36-38; VA 004CCBA0.
TRIBE_Action_Artifact::TRIBE_Action_Artifact(int id, RGE_Action_Object* object)
    : RGE_Action(id, object, 1) {
    this->field_04 = 0x6B;
}

// PDB lines 43-48; VA 004CCC00.
TRIBE_Action_Artifact::TRIBE_Action_Artifact(RGE_Action_Object* object,
                                               RGE_Task* task,
                                               RGE_Static_Object* target)
    : RGE_Action(object, 1) {
    this->action_type = 0x6B;
    this->task = task;
    this->target = target;
}

// PDB lines 53-60; VA 004CCC30.
TRIBE_Action_Artifact::TRIBE_Action_Artifact(RGE_Action_Object* file,
                                               RGE_Task* task,
                                               float x, float y, float z)
    : RGE_Action(file, 1) {
    this->task = task;
    this->action_type = 0x6B;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}

// PDB lines 64-74; VA 004CCC70.
void TRIBE_Action_Artifact::first_in_stack(unsigned char value) {
    if (value == 0) {
        return;
    }
    if (this->field_10 != 0) {
        this->set_state(5);
        return;
    }
    // The executable compares raw four-byte field representations.
    int field_20_bits;
    memcpy(&field_20_bits, &this->field_20, sizeof(field_20_bits));
    if (field_20_bits != 0xBF800000) {
        int field_24_bits;
        memcpy(&field_24_bits, &this->field_24, sizeof(field_24_bits));
        if (field_24_bits != 0xBF800000) {
            this->set_state(4);
            return;
        }
    }
    this->set_state(6);
}

// PDB lines 78-116; VA 004CCCB0.
void TRIBE_Action_Artifact::set_state(unsigned char new_state) {
    this->state = new_state;
    switch (new_state) {
    case 10:
        timer = 3.0f;
        break;
    case 4: {
        sub_actions->delete_list();
        RGE_Action_Move_To* move = new RGE_Action_Move_To(object, target_x, target_y, target_z, 0.0f,
            task->move_sprite);
        if (move != 0) {
            sub_actions->add_action(move);
            this->set_state(6);
        }
        break;
    }
    case 5: {
        sub_actions->delete_list();
        target_x = target_obj->world_x;
        target_y = target_obj->world_y;
        target_z = target_obj->world_z;
        target_obj = 0;
        RGE_Action_Move_To* move = new RGE_Action_Move_To(object, target_x, target_y, target_z, 0.0f,
            task->move_sprite);
        if (move != 0) {
            sub_actions->add_action(move);
            this->set_state(6);
        }
        break;
    }
    }
}

// PDB lines 120-164; VA 004CCDF0.
unsigned char TRIBE_Action_Artifact::update() {
    unsigned char val = action_list->update();
    if (val > 0 && val <= 3) {
        action_list->delete_list();
    }
    switch (state) {
    case 10: {
        RGE_Action_Object* obj = this->object;
        float speed = this->timer - obj->owner->world->world_time_delta_seconds;
        if (speed > DAT_00574f08) {
            this->timer = speed;
            return 0;
        }
        this->timer = speed;
        this->set_state(6);
        return 0;
    }

    case 6: {
        RGE_Player* owner = (RGE_Player*)check_ownership();
        if (owner != 0) {
            action_list->delete_list();
            object->change_ownership(owner);
            return 0;
        }
        this->set_state(10);
        return 0;
    }

    case 100:
        object->change_ownership(object->owner->world->master_players[0]);
        this->set_state(6);
        return 0;

    case 1:
        return 1;

    default:
        return 0;
    }
}

// PDB lines 168-224; VA 004CCF30.
RGE_Player* TRIBE_Action_Artifact::check_ownership() {
    RGE_Action_Object* obj = this->object;
    RGE_Master_Static_Object* master = obj->master_obj;

    short map_x = (short)(obj->world_x - DAT_00574f10 - master->radius_x);
    short map_y = (short)(obj->world_y - DAT_00574f10 - master->radius_y);
    short x0 = (short)(master->radius_x + obj->world_x - DAT_00574f14);
    short y0 = (short)(master->radius_y + obj->world_y - DAT_00574f14);

    RGE_Map* map = obj->owner->world->map;
    short player_num = obj->owner->world->player_num;
    unsigned char* player_list = (unsigned char*)calloc(player_num, 1);

    if (player_num > 0) {
        memset(player_list, 0, player_num);
    }

    if (map_x < 0) {
        map_x = 0;
    }
    if (map_y < 0) {
        map_y = 0;
    }
    if (x0 >= map->map_width) {
        x0 = (short)map->map_width - 1;
    }
    if (y0 >= map->map_height) {
        y0 = (short)map->map_height - 1;
    }

    for (short y = map_y; y <= y0; ++y) {
        for (short x = map_x; x <= x0; ++x) {
            RGE_Object_Node* node = map->map_row_offset[y][x].objects.list;
            while (node != 0) {
                RGE_Static_Object* entity = node->object;
                short type = entity->master_obj->object_group;
                if (type != 1 && type != 0x0B && type != 0x1E && entity->object_state == 2) {
                    ++player_list[entity->owner->id];
                }
                node = node->next;
            }
        }
    }

    short best_player = -1;
    short unique_owner = 0;
    for (short player = 1; player < player_num; ++player) {
        if (player_list[player] > 0) {
            ++unique_owner;
            best_player = player;
        }
    }

    free(player_list);

    if (unique_owner == 1 && best_player > 0) {
        RGE_Player* owner = this->object->owner;
        if (best_player != owner->id) {
            return owner->world->players[best_player];
        }
    }
    return 0;
}

// PDB lines 228-231; VA 004CD120.
int TRIBE_Action_Artifact::stop() {
    this->set_state(6);
    return 1;
}

// PDB lines 235-241; VA 004CD130.
int TRIBE_Action_Artifact::move_to(RGE_Static_Object* obj, float x, float y, float z) {
    this->move_x = x;
    this->move_y = y;
    this->move_z = z;
    this->set_state(4);
    return 1;
}

// PDB lines 245-259; VA 004CD160.
int TRIBE_Action_Artifact::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (param_1 != 0) {
        this->target = param_1;
        this->set_state(5);
        return 1;
    }

    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->set_state(4);
    return 1;
}

// PDB lines 263-265; VA 004CD1A0.
void TRIBE_Action_Artifact::reset_owner() {
    this->set_state(100);
}
