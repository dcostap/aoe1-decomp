#pragma once
#include "common.h"

class TRIBE_Dialog_List : public RGE_Dialog_List {
public:

    virtual int create_list();                              // vt0[78]+0x138=0x50B4A0
    virtual short get_cur_id();                             // vt0[79]+0x13C=0x50B820
    TRIBE_Dialog_List(char* param_1);
    ~TRIBE_Dialog_List();
    int create_build_list();
    int create_train_list();
    int create_research_list();
};

static_assert(sizeof(TRIBE_Dialog_List) == 0x4BC, "TRIBE_Dialog_List Size Mismatch");

