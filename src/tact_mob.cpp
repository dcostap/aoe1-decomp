#include <stdio.h>
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

extern "C" int __cdecl debug_rand(char*, int);
extern float save_game_version;

// Authentic source module for C:\\msdev\\work\\age1_x1\\tact_mob.cpp.
// Normal owners follow the PDB source-line and address order below. The nearby
// 004D0E90 vector-deleting destructor is compiler generated, not handwritten.
//
// The module uses the canonical tribal master-object build-time field.
// 004D0DD0  lines 31-41   matching
// 004D0EB0  lines 48-54   accepted_drift
// 004D0EF0  lines 60-65   matching
// 004D0F70  lines 69-76   matching
// 004D0FC0  lines 79-116  accepted_drift
// 004D10E0  lines 120-123 matching
// 004D10F0  lines 126-167 scratch (canonical owner available)
// 004D12B0  lines 171-233 matching
// 004D1550  lines 237-251 matching
// 004D15F0  lines 255-268 scratch (candidate exact)

// VA 004D0DD0; PDB tact_mob.cpp:31-41; matching.
// /GX is part of the constructor's original exception-handling frame.
TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1)
{
    this->action_type = 0x66;
    rge_read(param_1, &this->obj_id, 2);
    rge_read(param_1, &this->work_done, 4);
    rge_read(param_1, &this->unique_id, 4);

    if (save_game_version >= 7.23f) {
        rge_read(param_1, &this->pre_paid, 1);
    } else {
        this->pre_paid = 0;
    }
}

// VA 004D0EB0; PDB tact_mob.cpp:48-54; accepted drift.
// The constructor preserves the base state and all four shipped field values.
// VC5 selects a dword load for obj_id where the original uses a word load.
TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object* obj,
                                             short obj_id,
                                             int unique_id,
                                             unsigned char pre_paid)
    : RGE_Action(obj, 1)
{
    this->pre_paid = pre_paid;
    this->unique_id = unique_id;
    this->action_type = 0x66;
    this->obj_id = obj_id;
    this->work_done = 0;
}

// VA 004D0EF0; PDB tact_mob.cpp:60-65; matching.
TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj() {
    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->obj->owner);
    player->logMessage(
        (char*)"WT: %ld: MkObjDestructor: obj_id=%d, obj->id=%d, unique_id=%d",
        player->world->world_time, (int)this->obj_id,
        (int)this->obj->id, this->unique_id);
}

// VA 004D0F70; PDB tact_mob.cpp:69-76; matching.
void TRIBE_Action_Make_Obj::save(int handle) {
    RGE_Action::save(handle);
    rge_write(handle, &this->obj_id, 2);
    rge_write(handle, &this->work_done, 4);
    rge_write(handle, &this->unique_id, 4);
    rge_write(handle, &this->pre_paid, 1);
}

// VA 004D0FC0; PDB tact_mob.cpp:79-116; accepted drift.
// The VC5 build uses a different register for obj_id and loads this->obj
// earlier. The calls, cleanup, branches, and memory effects are unchanged.
void TRIBE_Action_Make_Obj::first_in_stack(uchar param_1)
{
    if (param_1 == 0) return;

    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->obj->owner);

    if (this->obj_id < 0) {
        player->logMessage((char*)"Canceling Train #1a:  obj_id=%d, obj->id=%d",
                           (int)this->obj_id, (int)this->obj->id,
                           this->unique_id);
    } else {
        RGE_Action_Object* objp = this->obj;

        if (player->master_objects[this->obj_id] == 0) {
            player->logMessage((char*)"Canceling Train #1b:  obj_id=%d, obj->id=%d",
                               (int)this->obj_id, (int)objp->id,
                               this->unique_id);
        } else {
            if (!this->pre_paid) {
                uchar paid = player->pay_obj_cost(this->obj_id, 1.0f, 0);
                if (paid == 0) {
                    player->logMessage((char*)"Canceling Train #1c:  obj_id=%d, obj->id=%d",
                                       (int)this->obj_id, (int)objp->id,
                                       this->unique_id);
                    player->cancelTrain(0, (int)this->obj_id,
                                        (int)objp->id, this->unique_id);
                    objp->notify((int)objp->id, (int)objp->id,
                                 0x1F9, (long)0x26B, (long)0, (long)0);
                    this->set_state(1);
                    return;
                }
            }
            this->set_state(6);
            return;
        }
    }

    player->cancelTrain(0, (int)this->obj_id, (int)this->obj->id,
                        this->unique_id);
}

// VA 004D10E0; PDB tact_mob.cpp:120-123; matching.
void TRIBE_Action_Make_Obj::set_state(uchar v) { this->state = v; }

// VA 004D10F0; PDB tact_mob.cpp:126-167; scratch (canonical owner available).
// The canonical member names retain the x87 work-rate and completion order.
unsigned char TRIBE_Action_Make_Obj::update()
{
    switch (this->state) {
    case 1:
        return 1;
    case 6:
        int needed;
        if (rge_base_game->quick_build != 0) {
            this->work_done = 1000.0f;
        } else {
            RGE_Master_Action_Object* master =
                static_cast<RGE_Master_Action_Object*>(this->obj->master_obj);
            this->work_done = master->work_rate *
                this->obj->owner->world->world_time_delta_seconds + this->work_done;
        }
        needed = static_cast<TRIBE_Master_Combat_Object*>(
                     this->obj->owner->master_objects[this->obj_id])
                     ->build_pts_required;
        if ((float)needed <= this->work_done) {
            this->set_state(1);
            RGE_Static_Object* newObject;
            if (!this->place_obj(&newObject)) {
                TRIBE_Player* player =
                    static_cast<TRIBE_Player*>(this->obj->owner);
                player->reimburse_obj_cost(this->obj_id);
                rge_base_game->notification(0x68, player->id,
                                             this->obj_id, 0, 0);
                player->logMessage(
                    (char*)"Canceling Train #2:  obj_id=%d, obj->id=%d",
                    (int)this->obj_id, (int)this->obj->id, this->unique_id);
                player->cancelTrain(0, (int)this->obj_id,
                                    (int)this->obj->id, this->unique_id);
                this->obj->notify((int)this->obj->id, (int)this->obj->id,
                                  0x1F9, (long)0x26B, (long)0, (long)0);
                return 1;
            } else {
                TRIBE_Player* player =
                    static_cast<TRIBE_Player*>(this->obj->owner);
                rge_base_game->notification(0x66, player->id,
                                             (int)this->obj_id,
                                             (long)this->obj->world_x,
                                             (long)this->obj->world_y);
                player->registerTrain((int)this->obj_id, (int)this->obj->id,
                                      this->unique_id, (int)newObject->id);
                this->obj->notify((int)this->obj->id, (int)this->obj->id,
                                  0x1FA, (long)0x26B, (long)0, (long)0);
                return 1;
            }
        }
        break;
    }
    return 0;
}

// VA 004D12B0; PDB tact_mob.cpp:171-233; matching.
// BINARY NOTE: The retry loops use the shipped side-selection and radius
// formulas. The protected access also publishes the created object before
// the saved-register pops in the original body.
static char s_tact_mob_cpp[] = "C:\\msdev\\work\\age1_x1\\tact_mob.cpp";

unsigned char TRIBE_Action_Make_Obj::place_obj(RGE_Static_Object** out)
{
    short expand = 0;
    RGE_Master_Static_Object* proto =
        this->obj->owner->master_objects[this->obj_id];
    RGE_Master_Static_Object* master = this->obj->master_obj;
    float rx;
    float ry;
    float r2x;
    float r2y;
    rx = master->radius_x + proto->radius_x - DAT_00575190;
    r2x = rx + rx;
    ry = master->radius_y + proto->radius_y - DAT_00575190;
    r2y = ry + ry;
    short tries;
    while (expand < 3) {
        tries = 0;
        do {
            short dir;
            if (tries < 40) {
                dir = (short)((debug_rand(s_tact_mob_cpp, 0xc0) * 2) / 0x7fff);
            } else {
                dir = (short)(((debug_rand(s_tact_mob_cpp, 0xc2) * 2) / 0x7fff) + 2);
            }
            switch (dir) {
            case 0:
                this->target_y = this->obj->world_y + ry;
                this->target_x = this->obj->world_x +
                    ((float)debug_rand(s_tact_mob_cpp, 0xc7) * r2x * DAT_00575198 - rx);
                break;
            case 1:
                this->target_x = this->obj->world_x - rx;
                this->target_y = this->obj->world_y +
                    ((float)debug_rand(s_tact_mob_cpp, 0xcb) * r2y * DAT_00575198 - ry);
                break;
            case 2:
                this->target_x = this->obj->world_x + rx;
                this->target_y = this->obj->world_y +
                    ((float)debug_rand(s_tact_mob_cpp, 0xcf) * r2y * DAT_00575198 - ry);
                break;
            case 3:
                this->target_y = this->obj->world_y - ry;
                this->target_x = this->obj->world_x +
                    ((float)debug_rand(s_tact_mob_cpp, 0xd3) * r2x * DAT_00575198 - rx);
                break;
            }
            if (proto->check_placement(
                    this->obj->owner, this->target_x, this->target_y, 0,
                    1, 1, 1, 0, 0, 1)) {
                ++tries;
            } else {
                *out = proto->make_new_obj(this->obj->owner, this->target_x,
                                           this->target_y, this->obj->world_z);
                return 1;
            }
        } while (tries < 60);
        rx = rx + (proto->radius_x + proto->radius_x);
        ry = ry + (proto->radius_y + proto->radius_y);
        r2x = r2x + (proto->radius_x * 4.0f);
        r2y = r2y + (proto->radius_y * 4.0f);
        ++expand;
    }
    return 0;
}

// VA 004D1550; PDB tact_mob.cpp:237-251; matching.
int TRIBE_Action_Make_Obj::stop() {
    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->obj->owner);
    player->logMessage(
        (char*)"Stopping Train #8:  obj_id=%d, obj->id=%d, unique_id=%d",
        (int)this->obj_id, (int)this->obj->id, this->unique_id);

    if (this->state != 1) {
        this->set_state(1);
        if (!this->pre_paid) {
            player->reimburse_obj_cost(this->obj_id);
        }
    }

    rge_base_game->notification(0x67, player->id, (int)this->obj_id,
                                0, 0);
    this->obj->notify((int)this->obj->id, (int)this->obj->id,
                      0x1F9, (long)0x26B, (long)0, (long)0);

    return 1;
}

// VA 004D15F0; PDB tact_mob.cpp:255-268; scratch (candidate exact).
// The master-object lookup and terminator store preserve the original order.
void TRIBE_Action_Make_Obj::get_info(short& param_1, short& param_2, char* param_3, short param_4) {
    param_1 = this->obj_id;

    if (this->state == 1) {
        param_2 = 100;
    } else {
        short divisor = static_cast<TRIBE_Master_Combat_Object*>(
                            this->obj->owner->master_objects[this->obj_id])
                            ->build_pts_required;
        int pc = (int)((this->work_done * DAT_005751a0) /
                       (float)divisor);
        param_2 = (short)pc;
    }

    if (param_3 != 0) {
        RGE_Master_Static_Object* info =
            this->obj->owner->master_objects[this->obj_id];
        strncpy(param_3, info->name, (unsigned int)param_4);
        param_3[param_4 - 1] = 0;
    }
}
