// RGE_Action::copy_obj
// VA: 00407B00
// PDB: action.cpp:393-432
// No EH framing
// Use extern __cdecl function pointers for clean dispatch

#include "../../include/game_globals.h"

class RGE_Action_List;

class RGE_Action {
public:
    char gap_04[4];
    void* obj;                    // +0x08
    unsigned char state;          // +0x0C
    char pad_0D[3];
    void* target_obj;             // +0x10
    void* target_obj2;            // +0x14
    int targetID;                 // +0x18
    int target2ID;                // +0x1C
    float target_x;               // +0x20
    float target_y;               // +0x24
    float target_z;               // +0x28
    float timer;                  // +0x2C
    void* task;                   // +0x30
    RGE_Action_List* sub_actions; // +0x34
    void* sprite;                 // +0x38

    void copy_obj(void* param_1);
};

struct RGE_Action_List {
    char gap_00[4];
};

// Extern thunks — __cdecl wrapper functions that do the __thiscall dispatch.
// These provide a call stub that matches the original's indirect call.
extern void __cdecl _call_vfn_act44(void*, void*, void*, void*);
extern void __cdecl _call_vfn_list18(void*, void*, void*, void*);
extern void __cdecl _call_vfn_obj38(void*, void*);

void RGE_Action::copy_obj(void* param_1)
{
    void* new_sprite = 0;

    if (this->task && *(void**)((char*)param_1 + 0xD8)) {
        void* tasks = *(void**)((char*)param_1 + 0xD8);
        int num = *(short*)((char*)tasks + 8);
        int i = num - 1;

        while (i >= 0) {
            void* t = *(void**)((char*)tasks + 4 + i * 4);
            if (*(short*)((char*)t + 6) == *(short*)((char*)this->task + 6))
                break;
            i--;
        }

        if (i >= 0) {
            void* t = *(void**)((char*)tasks + 4 + i * 4);
            void* obj_target = *(void**)((char*)this->obj + 0x10);

            if (obj_target == *(void**)((char*)t + 0x34))
                new_sprite = *(void**)((char*)t + 0x34);
            else if (obj_target == *(void**)((char*)t + 0x38))
                new_sprite = *(void**)((char*)t + 0x38);
            else if (obj_target == *(void**)((char*)t + 0x3C))
                new_sprite = *(void**)((char*)t + 0x3C);
            else if (obj_target == *(void**)((char*)t + 0x40))
                new_sprite = *(void**)((char*)t + 0x40);

            if (new_sprite) {
                _call_vfn_obj38(this->obj, new_sprite);
            }

            _call_vfn_act44(this, param_1, this->task, t);
            _call_vfn_list18(this->sub_actions, param_1, this->task, t);
            this->task = t;
            return;
        }
    }

    _call_vfn_act44(this, param_1, 0, 0);
    _call_vfn_list18(this->sub_actions, param_1, 0, 0);
}
