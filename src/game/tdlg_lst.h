#pragma once
#include "../common.h"

class TRIBE_Dialog_List : public RGE_Dialog_List {
public:

    TRIBE_Dialog_List(char* param_1);
    virtual ~TRIBE_Dialog_List();
    virtual int create_list();
    virtual int create_build_list();
    virtual int create_train_list();
    virtual int create_research_list();
    virtual short get_cur_id();
};

static_assert(sizeof(TRIBE_Dialog_List) == 0x4BC, "TRIBE_Dialog_List Size Mismatch");

