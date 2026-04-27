// 00508EC0 RGE_Task_List::load (handle-based)
// Source: task_lst.cpp lines 63-81
// Size: 155 bytes
//
// Attempt log:
// Probe 1: 155/155, 41% diff — register allocation codegen basin (ebx vs esi for this)
//   Same pattern as copy: push ebx vs movsx+push, shl vs lea
//   Left in scratch: codegen basin

#include "..\..\include\game_globals.h"

class RGE_Task;

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short task_type, int index);
    RGE_Task** list;        // +0x04
    short list_num;         // +0x08

    void delete_list();
    void load(int handle, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Sprite;
class RGE_Sound;

class RGE_Task {
public:
    short task_type;        // +0x00
    void load(int handle, RGE_Sprite** sprites, RGE_Sound** sounds);
};

extern void* __cdecl calloc(int, int);
extern int __cdecl rge_read(int handle, void* buf, int size);

void RGE_Task_List::load(int handle, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short local_task_type;

    if (this->list) {
        this->delete_list();
    }
    rge_read(handle, &this->list_num, 2);
    if (this->list_num > 0) {
        this->list = (RGE_Task**)calloc(this->list_num, 4);
        for (short i = 0; i < this->list_num; i++) {
            rge_read(handle, &local_task_type, 2);
            this->list[i] = this->create_task(local_task_type, i);
            this->list[i]->load(handle, sprites, sounds);
        }
    }
}
