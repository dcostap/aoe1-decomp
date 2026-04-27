// 00508F60 RGE_Task_List::load (FILE*-based)
// Source: task_lst.cpp lines 86-107
// Size: 161 bytes
//
// Attempt log:
// Probe 1: 161/161, 40% diff — same register allocation codegen basin as copy/load
// Left in scratch: codegen basin

#include "..\..\include\game_globals.h"
#include <stdio.h>

class RGE_Task;

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short task_type, int index);
    RGE_Task** list;        // +0x04
    short list_num;         // +0x08

    void delete_list();
    void load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Sprite;
class RGE_Sound;

class RGE_Task {
public:
    short task_type;        // +0x00
    void load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds);
};

extern void* __cdecl calloc(int, int);

void RGE_Task_List::load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short local_task_type;

    if (this->list) {
        this->delete_list();
    }
    fscanf(file, "%hd", &this->list_num);
    if (this->list_num > 0) {
        this->list = (RGE_Task**)calloc(this->list_num, 4);
        for (short i = 0; i < this->list_num; i++) {
            fscanf(file, "%hd", &local_task_type);
            this->list[i] = this->create_task(local_task_type, i);
            this->list[i]->load(file, sprites, sounds);
        }
    }
}
