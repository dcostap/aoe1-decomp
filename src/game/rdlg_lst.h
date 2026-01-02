#pragma once
#include "../common.h"

class RGE_Dialog_List : public TListDialog {
public:
    int list_type;                           // 0x4AC
    short list_size;                         // 0x4B0
    short list_line;                         // 0x4B2
    rdlg_list_info* list_info;               // 0x4B4
    char** list_text;                        // 0x4B8

    RGE_Dialog_List(char* param_1);
    virtual int setup(TScreenPanel* param_1, char* param_2, long param_3, int param_4, char* param_5);
    virtual ~RGE_Dialog_List();
    virtual short get_list_id();
    virtual int create_list();
    virtual int create_object_list();
    virtual void sort_list();
    virtual void calc_list_line();
    virtual short get_cur_id();
};

static_assert(sizeof(RGE_Dialog_List) == 0x4BC, "RGE_Dialog_List Size Mismatch");
static_assert(offsetof(RGE_Dialog_List, list_text) == 0x4B8, "RGE_Dialog_List Offset Mismatch");

