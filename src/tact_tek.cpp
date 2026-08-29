#include "../include/tact_tek.h"
#include "../include/act_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/basegame.h"
#include "../include/tplayer.h"
#include "../include/tech.h"
#include "../include/world.h"
#include "../include/rge_base_game_global.h"
#include <string.h>

extern "C" {
void __cdecl rge_read(int handle, void* buffer, int count);
void __cdecl rge_write(int handle, void* buffer, int count);
}

//

TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(int file, RGE_Action_Object* object)
    : RGE_Action(file, object, 1) {
    this->action_type = 0x67;
    rge_read(file, &this->tech_id, 2);
    rge_read(file, &this->unique_id, 4);
}

// The constructor preserves the original base construction and field values.
TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(RGE_Action_Object* object,
                                               short tech_id_value,
                                               int unique_id_value)
    : RGE_Action(object, 1) {
    this->unique_id = unique_id_value;
    this->action_type = 0x67;
    this->tech_id = tech_id_value;
}

TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech() {
    if (this->state != 1) {
        TRIBE_Player* player = static_cast<TRIBE_Player*>(this->obj->owner);
        TRIBE_Player_Tech* player_tech = player->tech_tree;
        player_tech->cancel_research(this->tech_id, 0);

        if (rge_base_game->world->game_state == 0) {
            rge_base_game->notification(
                0x65,
                player->id,
                this->tech_id,
                0,
                0);

            player->cancelResearch(
                (int)this->tech_id,
                this->obj->id,
                -1,
                this->unique_id);

            this->obj->notify(
                this->obj->id,
                this->obj->id,
                0x1F9,
                0x26C,
                0,
                0);
        }
    }
}

void TRIBE_Action_Make_Tech::save(int file) {
    RGE_Action::save(file);
    rge_write(file, &this->tech_id, 2);
    rge_write(file, &this->unique_id, 4);
}

void TRIBE_Action_Make_Tech::first_in_stack(unsigned char value) {
    if (value == 0 || this->tech_id < 0) {
        return;
    }

    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->obj->owner);
    TRIBE_Player_Tech* player_tech = player->tech_tree;
    unsigned char result = player_tech->start_research(
        this->tech_id, 1, reinterpret_cast<short*>(&value));
    if (result == 1) {
        this->set_state(6);
        return;
    }

    player->cancelResearch(
        (int)*(short*)&value,
        (int)this->tech_id,
        this->obj->id,
        this->unique_id);

    this->obj->notify(
        this->obj->id,
        this->obj->id,
        0x1F9,
        0x26C,
        0,
        0);

    this->set_state(1);
}

void TRIBE_Action_Make_Tech::set_state(unsigned char new_state) {
    this->state = new_state;
}

unsigned char TRIBE_Action_Make_Tech::update() {
    if (this->state == 1) {
        return 1;
    }
    if (this->state != 6) {
        return 0;
    }

    float work;
    if (rge_base_game->quick_build == 0) {
        work = this->obj->owner->world->world_time_delta_seconds *
            static_cast<RGE_Master_Action_Object*>(
                this->obj->master_obj)->work_rate;
    } else {
        work = 1000.0f;
    }

    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->obj->owner);
    TRIBE_Player_Tech* player_tech = player->tech_tree;
    if (player_tech->research(this->tech_id, work) != 0) {
        return 0;
    }

    this->set_state(1);
    RGE_Action_Object* action_object = this->obj;
    rge_base_game->notification(
        0x64,
        player->id,
        this->tech_id,
        (int)action_object->world_y,
        (int)action_object->world_x);

    player->registerResearch(
        (int)this->tech_id,
        action_object->id,
        this->unique_id);

    action_object->notify(
        action_object->id,
        action_object->id,
        0x1FA,
        0x26C,
        0,
        0);

    return 1;
}

int TRIBE_Action_Make_Tech::stop() {
    this->set_state(1);

    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->obj->owner);
    player->tech_tree->cancel_research(this->tech_id, 1);

    rge_base_game->notification(
        0x65,
        player->id,
        this->tech_id,
        0,
        0);

    player->cancelResearch(
        (int)this->tech_id,
        this->obj->id,
        -1,
        this->unique_id);

    this->obj->notify(
        this->obj->id,
        this->obj->id,
        0x1F9,
        0x26C,
        0,
        0);

    return 1;
}

// The final terminator store is behavior-equivalent despite VC5 SIB ordering.
void TRIBE_Action_Make_Tech::get_info(short& tech_id_out,
                                       short& progress_out,
                                       char* name_out,
                                       short max_length) {
    register TRIBE_Action_Make_Tech* self = this;
    char* destination = name_out;

    tech_id_out = self->tech_id;
    if (self->state == 1) {
        progress_out = 100;
    } else {
        TRIBE_Player* player = static_cast<TRIBE_Player*>(self->obj->owner);
        progress_out = player->tech_tree->get_progress(self->tech_id);
    }

    if (destination != 0) {
        int length = max_length;
        TRIBE_Player* player = static_cast<TRIBE_Player*>(self->obj->owner);
        strncpy(destination, player->tech_tree->get_name(self->tech_id), length);
        destination[length - 1] = 0;
    }
}
