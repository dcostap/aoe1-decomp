// first pass: direct task-delete loop, free the array, then clear the list/count tail state
// the direct outer-if + short-index form landed the exact 94-byte basin after the early return version missed by layout
#include "..\..\include\game_types.h"

extern "C" void __cdecl free(void* block);

class RGE_Task {
public:
    ~RGE_Task();
};

class RGE_Task_List {
public:
    void* vtable_ptr;
    RGE_Task** list;
    short list_num;

    void delete_list();
};

void RGE_Task_List::delete_list() {
    short i = 0;

    if (list != 0) {
        if (list_num > 0) {
            do {
                RGE_Task* task = list[i];
                if (task != 0) {
                    delete task;
                    list[i] = 0;
                }
                ++i;
            } while (i < list_num);
        }

        free(list);
        list = 0;
    }

    list_num = 0;
}
