// RGE_Action_Transport::work
// VA: 004071A0
// PDB: act_tran.cpp:346-386
// No EH framing. Ret 10h.

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
    unsigned char subActionValue;
    char gap_3D[3];

    int work(void* param_1, float param_2, float param_3, float param_4);
};

// __ftol is an intrinsic
extern int __cdecl __ftol(float);

extern unsigned char _lookupZone(void* obj, int x, int y);
extern float _dist_to_pos(void* obj, float x, float y, float z);
extern int _withinRange(void* obj, int zone, float range);
extern void _set_state(void* action, int new_state);

// Constants
extern float _float_two;  // 2.0f
extern double _double_zero;  // 0.0

int RGE_Action_Transport::work(void* param_1, float param_2, float param_3, float param_4)
{
    float dist;

    this->timer = 1.0f;

    int y_int = __ftol(param_3);
    int x_int = __ftol(param_2);
    int zone = (int)_lookupZone(this->obj, x_int, y_int);

    float wz = *(float*)((char*)this->obj + 0x40);
    dist = _dist_to_pos(this->obj, param_2, param_3, wz);

    if (zone != -1) {
        if (_withinRange(this->obj, zone, 2.0f) == 1 && dist <= 2.0f) {
            this->target_y = param_3;
            this->target_x = param_2;
            this->target_z = param_4;
            _set_state(this, 6);
            return 1;
        }
    }

    if (param_2 >= 0.0 && param_3 >= 0.0) {
        this->target_x = param_2;
        this->target_y = param_3;
        this->target_z = param_4;
        if (param_1 != this->obj) {
            _set_state(this, 0x0B);
            return 1;
        }
        _set_state(this, 4);
    }
    return 1;
}
