// RGE_Action::save
// VA: 00407790
// PDB: action.cpp:172-213
// No EH framing

#include "../../include/action_context.h"
#include "../../include/game_globals.h"

void rge_write(int handle, void* buf, int size);

void RGE_Action::save(int param_1)
{
    // Two locals preserve the original 8-byte local window.
    int id_write;
    short short_write;

    rge_write(param_1, &this->action_type, 2);
    rge_write(param_1, &this->state, 1);

    if (!this->target_obj) {
        id_write = -1;
    } else {
        id_write = *(int*)((char*)this->target_obj + 4);
    }
    rge_write(param_1, &id_write, 4);

    if (!this->target_obj2) {
        id_write = -1;
    } else {
        id_write = *(int*)((char*)this->target_obj2 + 4);
    }
    rge_write(param_1, &id_write, 4);

    rge_write(param_1, &this->targetID, 4);
    rge_write(param_1, &this->target2ID, 4);
    rge_write(param_1, &this->target_x, 4);
    rge_write(param_1, &this->target_y, 4);
    rge_write(param_1, &this->target_z, 4);
    rge_write(param_1, &this->timer, 4);

    if (!this->task) {
        short_write = -1;
    } else {
        short_write = *(short*)((char*)this->task + 2);
    }
    rge_write(param_1, &short_write, 2);

    rge_write(param_1, &this->subActionValue, 1);

    this->sub_actions->save(param_1);

    if (!this->sprite) {
        short_write = -1;
    } else {
        short_write = *(short*)((char*)this->sprite + 0x72);
    }
    rge_write(param_1, &short_write, 2);
}
