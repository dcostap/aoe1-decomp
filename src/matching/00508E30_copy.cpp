// 00508E30 RGE_Task_List::copy
// Source: task_lst.cpp lines 42-58
// Size: 129 bytes
//
// Attempt log:
// Probe 1: short i, virtual create_task → 129 bytes, 43% diff, 16-bit compare correct
//   Codegen drift: push ebx vs movsx+push, shl vs lea, reg allocation
// Probe 2: int i → 128/129, 32-bit compare
// Left in scratch: codegen basin (ebx vs esi for this, short-to-int promotion for virtual call)

#include "..\..\include\game_globals.h"

class RGE_Task;

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short task_type, short index);
    RGE_Task** list;        // +0x04
    short list_num;         // +0x08

    void delete_list();
    void copy(RGE_Task_List* src);
};

class RGE_Task {
public:
    short task_type;        // +0x00
    void copy(RGE_Task* src);
};

extern void* __cdecl calloc(int num, int size);

void RGE_Task_List::copy(RGE_Task_List* src)
{
    if (this->list) {
        this->delete_list();
    }
    this->list_num = src->list_num;
    if (this->list_num > 0) {
        this->list = (RGE_Task**)calloc(this->list_num, 4);
        for (short i = 0; i < this->list_num; i++) {
            this->list[i] = this->create_task(src->list[i]->task_type, i);
            this->list[i]->copy(src->list[i]);
        }
    }
}
