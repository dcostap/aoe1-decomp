// RGE_Action_Transport::set_state
// VA: 00406E50
// PDB: act_tran.cpp:96-133
// EH-framed, needs /GX

#include "../../include/game_globals.h"

class RGE_Action_Transport {
public:
    void* vtable_ptr;
    short action_type;
    char gap_06[2];
    void* obj;              // +0x08
    unsigned char state;    // +0x0C
    char gap_0D[3];
    void* target_obj;       // +0x10
    void* target_obj2;      // +0x14
    int targetID;           // +0x18
    int target2ID;          // +0x1C
    float target_x;         // +0x20
    float target_y;         // +0x24
    float target_z;         // +0x28
    float timer;            // +0x2C
    void* task;             // +0x30
    void* sub_actions;      // +0x34
    void* sprite;           // +0x38

    void set_state(unsigned char param_1);
};

extern void _delete_list(void* list);
extern void* _operator_new(int size);
extern void _setSubAction(void* action, unsigned char val);
extern void _add_action(void* list, void* action);
extern void _setSubAction(void* action, unsigned char val);
extern void _ctor_move_to(void* _this, void* obj, float x, float y, float z, float extra, void* sprite);

void RGE_Action_Transport::set_state(unsigned char param_1)
{
    _delete_list(this->sub_actions);
    this->state = param_1;

    if (param_1 == 2) {
        void* obj_f8 = *(void**)((char*)this->obj + 8);
        void* spr = *(void**)((char*)obj_f8 + 0x18);
        (*(void (__fastcall**)(void*, int, void*))((char*)*(void**)this->obj + 0x38))(this->obj, 0, spr);
        return;
    }

    if (param_1 == 4 || param_1 == 0x0B) {
        void* move_to;
        int eh_flag;

        if (this->task) {
            move_to = _operator_new(0x44);
            eh_flag = 0;
            if (move_to) {
                void* spr = *(void**)((char*)this->task + 0x34);
                _ctor_move_to(move_to, this->obj, this->target_x, this->target_y, this->target_z, 0.3f, spr);
            }
        } else {
            move_to = _operator_new(0x44);
            eh_flag = 1;
            if (move_to) {
                void* obj_f8 = *(void**)((char*)this->obj + 8);
                void* spr = *(void**)((char*)obj_f8 + 0x18);
                _ctor_move_to(move_to, this->obj, this->target_x, this->target_y, this->target_z, 0.3f, spr);
            }
        }

        if (!move_to) {
            (*(void (__fastcall**)(void*, int, int))((char*)*(void**)this + 0x5C))(this, 0, 2);
            return;
        }

        _add_action(this->sub_actions, move_to);
        _setSubAction(move_to, 1);
    }
}
