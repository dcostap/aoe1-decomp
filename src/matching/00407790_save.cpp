// RGE_Action::save
// VA: 00407790
// PDB: action.cpp:172-213
// No EH framing

#include "../../include/game_globals.h"

class RGE_Action_List;
class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    char gap_06[2];
    void* obj;
    unsigned char state;
    char gap_0D[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    RGE_Action_List* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    void save(int param_1);
};

class RGE_Action_List {
public:
    void save(int handle);
};

void rge_write(int handle, void* buf, int size);

void RGE_Action::save(int param_1)
{
    // Two locals to force 8 bytes stack frame like orig push ecx + reused param slot
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
