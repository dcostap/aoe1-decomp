#ifndef AOE1_TTSK_LST_H
#define AOE1_TTSK_LST_H

// Compiler-facing declarations for C:\\msdev\\work\\age1_x1\\ttsk_lst.cpp.

#include "task_lst.h"

class TRIBE_Task_List : public RGE_Task_List {
public:
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*,
                                      float, float, float);
    virtual int is_attack_task(RGE_Task*);
};

typedef char tribe_task_list_size_check[
    (sizeof(TRIBE_Task_List) == 0x0C) ? 1 : -1];

#endif
