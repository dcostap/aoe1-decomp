#include "../include/tact_tek.h"
#include "../include/act_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/basegame.h"
#include "../include/tplayer.h"
#include "../include/tech.h"
#include "../include/world.h"
#include "../include/rge_base_game_global.h"
#include <string.h>

void __cdecl rge_read(int handle, void* buffer, int count);
void __cdecl rge_write(int handle, void* buffer, int count);

TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(int infile, RGE_Action_Object* obj_in)
    : RGE_Action(infile, obj_in, 1) {
    this->action_type = 0x67;
    rge_read(infile, &this->tech_id, 2);
    rge_read(infile, &this->unique_id, 4);
}

TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(RGE_Action_Object* obj_in, short id, int uID)
    : RGE_Action(obj_in, 1) {
    this->unique_id = uID;
    this->action_type = 0x67;
    this->tech_id = id;
}

TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech() {
    if (this->state != 1) {
        static_cast<TRIBE_Player*>(this->obj->owner)->tech_tree->cancel_research(this->tech_id, 0);

        if (rge_base_game->world->game_state == 0) {
            rge_base_game->notification(0x65, static_cast<TRIBE_Player*>(this->obj->owner)->id, this->tech_id, 0, 0);

            static_cast<TRIBE_Player*>(this->obj->owner)->cancelResearch(
                (int)this->tech_id, this->obj->id, -1, this->unique_id);

            this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x26C, 0, 0);
        }
    }
}

void TRIBE_Action_Make_Tech::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->tech_id, 2);
    rge_write(outfile, &this->unique_id, 4);
}

void TRIBE_Action_Make_Tech::first_in_stack(unsigned char first_time) {
    if (first_time == 0 || this->tech_id < 0) {
        return;
    }

    unsigned char result =
        static_cast<TRIBE_Player*>(this->obj->owner)->tech_tree->start_research(
            this->tech_id, 1, reinterpret_cast<short*>(&first_time));
    if (result == 1) {
        this->set_state(6);
        return;
    }

    static_cast<TRIBE_Player*>(this->obj->owner)->cancelResearch((int)*(short*)&first_time, (int)this->tech_id,
                                                                 this->obj->id, this->unique_id);

    this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x26C, 0, 0);

    this->set_state(1);
}

void TRIBE_Action_Make_Tech::set_state(unsigned char new_state) {
    this->state = new_state;
}

unsigned char TRIBE_Action_Make_Tech::update() {
    float work;
    TRIBE_Player_Tech* player_tech;
    RGE_Action_Object* action_object;

    switch ((int)this->state) {
    case 1:
        goto success_initial;
    case 6:
        break;
    default:
        goto fail;
    }

    if (rge_base_game->quick_build != 0) {
        work = 1000.0f;
    } else {
        work = this->obj->owner->world->world_time_delta_seconds *
            static_cast<RGE_Master_Action_Object*>(this->obj->master_obj)->work_rate;
    }

    player_tech = static_cast<TRIBE_Player*>(this->obj->owner)->tech_tree;
    if (player_tech->research(this->tech_id, work) == 0) {
        this->set_state(1);
        action_object = this->obj;
        rge_base_game->notification(0x64, static_cast<TRIBE_Player*>(action_object->owner)->id, this->tech_id,
                                    (int)action_object->world_x, (int)action_object->world_y);
        static_cast<TRIBE_Player*>(this->obj->owner)->registerResearch((int)this->tech_id, this->obj->id, this->unique_id);
        this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x26C, 0, 0);
        return 1;
    }

fail:
    return 0;

success_initial:
    return 1;
}

int TRIBE_Action_Make_Tech::stop() {
    this->set_state(1);

    static_cast<TRIBE_Player*>(this->obj->owner)->tech_tree->cancel_research(this->tech_id, 1);

    rge_base_game->notification(0x65, static_cast<TRIBE_Player*>(this->obj->owner)->id, this->tech_id, 0, 0);

    static_cast<TRIBE_Player*>(this->obj->owner)->cancelResearch((int)this->tech_id, this->obj->id, -1, this->unique_id);

    this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x26C, 0, 0);

    return 1;
}

void TRIBE_Action_Make_Tech::get_info(short& id, short& progress, char* name, short name_size) {
    id = this->tech_id;
    if (this->state == 1) {
        progress = 100;
    } else {
        progress = static_cast<TRIBE_Player*>(this->obj->owner)
                       ->tech_tree->get_progress(this->tech_id);
    }

    if (name != 0) {
        strncpy(name, static_cast<TRIBE_Player*>(this->obj->owner) ->tech_tree->get_name(this->tech_id), name_size);
        name[name_size - 1] = 0;
    }
}
