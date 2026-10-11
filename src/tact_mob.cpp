#include "../include/tact_mob.h"
#include "../include/act_obj.h"
#include "../include/stat_obj.h"
#include "../include/m_co_obj.h"
#include "../include/tm_co_ob.h"
#include "../include/world.h"
#include "../include/player.h"
#include "../include/tplayer.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/game_globals.h"
#include "../include/rge_fio.h"
#include <string.h>

TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(int infile, RGE_Action_Object* obj_in) : RGE_Action(infile, obj_in, 1) {
    this->action_type = TRIBE_ACTION_TYPE_MAKE_OBJECT;
    rge_read(infile, &this->obj_id, 2);
    rge_read(infile, &this->work_done, 4);
    rge_read(infile, &this->unique_id, 4);

    if (save_game_version >= 7.23f) {
        rge_read(infile, &this->pre_paid, 1);
    } else {
        this->pre_paid = 0;
    }
}

TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object* obj_in, short id, int uniqueID, unsigned char paid) :
    RGE_Action(obj_in, 1), unique_id(uniqueID) {
    this->action_type = TRIBE_ACTION_TYPE_MAKE_OBJECT;
    this->obj_id = id;
    this->work_done = 0.0f;
    this->pre_paid = paid;
}

//! @bug The destructor never calls cancelTrain, so the AI keeps inProgress = 1.
//! Building death deletes this action through delete_list(), with no stop() call.
//! ~TRIBE_Action_Make_Tech cancels its research. This one leaves the item stuck.
TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj() {
    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->obj->owner);
    player->logMessage(
        "WT: %ld: MkObjDestructor: obj_id=%d, obj->id=%d, unique_id=%d", player->world->world_time, (int) this->obj_id,
        (int) this->obj->id, this->unique_id
    );
}

void TRIBE_Action_Make_Obj::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->obj_id, 2);
    rge_write(outfile, &this->work_done, 4);
    rge_write(outfile, &this->unique_id, 4);
    rge_write(outfile, &this->pre_paid, 1);
}

void TRIBE_Action_Make_Obj::first_in_stack(uchar first_time) {
    if (first_time == 0)
        return;

    if (this->obj_id < 0) {
        static_cast<TRIBE_Player*>(this->obj->owner)
            ->logMessage(
                "Canceling Train #1a:  obj_id=%d, obj->id=%d, uniqueID=%d.", (int) this->obj_id, (int) this->obj->id,
                this->unique_id
            );
    } else {
        if (static_cast<TRIBE_Player*>(this->obj->owner)->master_objects[this->obj_id] == 0) {
            static_cast<TRIBE_Player*>(this->obj->owner)
                ->logMessage(
                    "Canceling Train #1b:  obj_id=%d, obj->id=%d, uniqueID=%d.", (int) this->obj_id,
                    (int) this->obj->id, this->unique_id
                );
        } else {
            if (!this->pre_paid) {
                if (static_cast<TRIBE_Player*>(this->obj->owner)->pay_obj_cost(this->obj_id, 1.0f, 0) == 0) {
                    static_cast<TRIBE_Player*>(this->obj->owner)
                        ->logMessage(
                            "Canceling Train #1c:  obj_id=%d, obj->id=%d, uniqueID=%d.", (int) this->obj_id,
                            (int) this->obj->id, this->unique_id
                        );
                    static_cast<TRIBE_Player*>(this->obj->owner)
                        ->cancelTrain(0, (int) this->obj_id, (int) this->obj->id, this->unique_id);
                    this->obj->notify(
                        (int) this->obj->id, (int) this->obj->id, UNIT_AI_NOTIFY_ACTION_FAILED,
                        (long) UNIT_AI_ACTION_TRAIN, (long) 0, (long) 0
                    );
                    this->set_state(1);
                    return;
                }
            }
            this->set_state(6);
            return;
        }
    }

    static_cast<TRIBE_Player*>(this->obj->owner)
        ->cancelTrain(0, (int) this->obj_id, (int) this->obj->id, this->unique_id);
}

void TRIBE_Action_Make_Obj::set_state(uchar new_state) {
    this->state = new_state;
}

// The canonical member names retain the x87 work-rate and completion order.
unsigned char TRIBE_Action_Make_Obj::update() {
    switch (this->state) {
        case 1:
            return RGE_ACTION_UPDATE_REMOVE;
        case 6:
            if (rge_base_game->quick_build != 0) {
                this->work_done = 1000.0f;
            } else {
                RGE_Master_Action_Object* master = static_cast<RGE_Master_Action_Object*>(this->obj->master_obj);
                this->work_done =
                    master->work_rate * this->obj->owner->world->world_time_delta_seconds + this->work_done;
            }
            RGE_Action_Object* needed_obj = this->obj;
            TRIBE_Player* needed_player = static_cast<TRIBE_Player*>(needed_obj->owner);
            int needed = static_cast<TRIBE_Master_Combat_Object*>(needed_player->master_objects[this->obj_id])
                             ->build_pts_required;
            if ((float) needed <= this->work_done) {
                this->set_state(1);
                RGE_Static_Object* newObject;
                if (!this->place_obj(&newObject)) {
                    static_cast<TRIBE_Player*>(this->obj->owner)->reimburse_obj_cost(this->obj_id);
                    rge_base_game->notification(
                        GAME_NOTIFY_NO_ROOM_FOR_UNIT, static_cast<TRIBE_Player*>(this->obj->owner)->id, this->obj_id, 0,
                        0
                    );
                    static_cast<TRIBE_Player*>(this->obj->owner)
                        ->logMessage(
                            "Canceling Train #2:  obj_id=%d, obj->id=%d", (int) this->obj_id, (int) this->obj->id,
                            this->unique_id
                        );
                    static_cast<TRIBE_Player*>(this->obj->owner)
                        ->cancelTrain(0, (int) this->obj_id, (int) this->obj->id, this->unique_id);
                    this->obj->notify(
                        (int) this->obj->id, (int) this->obj->id, UNIT_AI_NOTIFY_ACTION_FAILED,
                        (long) UNIT_AI_ACTION_TRAIN, (long) 0, (long) 0
                    );
                    return RGE_ACTION_UPDATE_REMOVE;
                } else {
                    rge_base_game->notification(
                        GAME_NOTIFY_UNIT_TRAINED, static_cast<TRIBE_Player*>(this->obj->owner)->id, (int) this->obj_id,
                        (long) this->obj->world_x, (long) this->obj->world_y
                    );
                    static_cast<TRIBE_Player*>(this->obj->owner)
                        ->registerTrain((int) this->obj_id, (int) this->obj->id, this->unique_id, (int) newObject->id);
                    this->obj->notify(
                        (int) this->obj->id, (int) this->obj->id, UNIT_AI_NOTIFY_ACTION_COMPLETED,
                        (long) UNIT_AI_ACTION_TRAIN, (long) 0, (long) 0
                    );
                    return RGE_ACTION_UPDATE_REMOVE;
                }
            }
            break;
    }
    return RGE_ACTION_UPDATE_CONTINUE;
}

// The retry loops use the shipped side-selection and radius
// formulas. The protected access also publishes the created object before
// the saved-register pops in the original body. The success arm rereads
// owner->master_objects[obj_id] for make_new_obj. Reusing proto adds a
// four-byte vtable spill and changes the frame from 0x18 to 0x1C.
static char s_tact_mob_cpp[] = "C:\\msdev\\work\\age1_x1\\tact_mob.cpp";

unsigned char TRIBE_Action_Make_Obj::place_obj(RGE_Static_Object** rObj) {
    short index = 0;
    RGE_Master_Static_Object* proto = this->obj->owner->master_objects[this->obj_id];
    RGE_Master_Static_Object* master = this->obj->master_obj;
    float radius_x;
    float radius_y;
    float radius_2x;
    float radius_2y;
    radius_x = master->radius_x + proto->radius_x - g_make_obj_radius_adjustment;
    radius_2x = radius_x + radius_x;
    radius_y = master->radius_y + proto->radius_y - g_make_obj_radius_adjustment;
    radius_2y = radius_y + radius_y;
    short tries;
    while (index < 3) {
        tries = 0;
        do {
            short dir;
            if (tries < 40) {
                dir = (short) ((debug_rand(s_tact_mob_cpp, 192) * 2) / 0x7fff);
            } else {
                dir = (short) (((debug_rand(s_tact_mob_cpp, 194) * 2) / 0x7fff) + 2);
            }
            switch (dir) {
                case 0:
                    this->target_y = this->obj->world_y + radius_y;
                    this->target_x =
                        this->obj->world_x
                        + ((float) debug_rand(s_tact_mob_cpp, 199) * radius_2x * g_make_obj_random_scale - radius_x);
                    break;
                case 1:
                    this->target_x = this->obj->world_x - radius_x;
                    this->target_y =
                        this->obj->world_y
                        + ((float) debug_rand(s_tact_mob_cpp, 203) * radius_2y * g_make_obj_random_scale - radius_y);
                    break;
                case 2:
                    this->target_x = this->obj->world_x + radius_x;
                    this->target_y =
                        this->obj->world_y
                        + ((float) debug_rand(s_tact_mob_cpp, 207) * radius_2y * g_make_obj_random_scale - radius_y);
                    break;
                case 3:
                    this->target_y = this->obj->world_y - radius_y;
                    this->target_x =
                        this->obj->world_x
                        + ((float) debug_rand(s_tact_mob_cpp, 211) * radius_2x * g_make_obj_random_scale - radius_x);
                    break;
            }
            if (proto->check_placement(this->obj->owner, this->target_x, this->target_y, 0, 1, 1, 1, 0, 0, 1)) {
                ++tries;
            } else {
                *rObj = this->obj->owner->master_objects[this->obj_id]->make_new_obj(
                    this->obj->owner, this->target_x, this->target_y, this->obj->world_z
                );
                return 1;
            }
        } while (tries < 60);
        radius_x = radius_x + (proto->radius_x + proto->radius_x);
        radius_y = radius_y + (proto->radius_y + proto->radius_y);
        radius_2x = radius_2x + (proto->radius_x * 4.0f);
        radius_2y = radius_2y + (proto->radius_y * 4.0f);
        ++index;
    }
    return 0;
}

// The original reloads obj->owner for each later call instead
// of carrying one player alias across calls.
int TRIBE_Action_Make_Obj::stop() {
    static_cast<TRIBE_Player*>(this->obj->owner)
        ->logMessage(
            "Stopping Train #8:  obj_id=%d, obj->id=%d, unique_id=%d", (int) this->obj_id, (int) this->obj->id,
            this->unique_id
        );

    if (this->state != 1) {
        this->set_state(1);
        if (!this->pre_paid) {
            static_cast<TRIBE_Player*>(this->obj->owner)->reimburse_obj_cost(this->obj_id);
        }
    }

    rge_base_game->notification(
        GAME_NOTIFY_TRAINING_STOPPED, static_cast<TRIBE_Player*>(this->obj->owner)->id, (int) this->obj_id, 0, 0
    );
    this->obj->notify(
        (int) this->obj->id, (int) this->obj->id, UNIT_AI_NOTIFY_ACTION_FAILED, (long) UNIT_AI_ACTION_TRAIN, (long) 0,
        (long) 0
    );

    return 1;
}

// The master-object lookup and terminator store preserve the original order.
void TRIBE_Action_Make_Obj::get_info(short& id, short& progress, char* name, short name_size) {
    id = this->obj_id;

    if (this->state == 1) {
        progress = 100;
    } else {
        short divisor = static_cast<TRIBE_Master_Combat_Object*>(this->obj->owner->master_objects[this->obj_id])
                            ->build_pts_required;
        int pc = (int) ((this->work_done * g_make_obj_progress_percent) / (float) divisor);
        progress = (short) pc;
    }

    if (name != 0) {
        RGE_Master_Static_Object* info = this->obj->owner->master_objects[this->obj_id];
        strncpy(name, info->name, (unsigned int) name_size);
        name[name_size - 1] = 0;
    }
}
