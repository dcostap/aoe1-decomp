#pragma once
#include "common.h"

// ----------------------------------------------------------------
// rdlg_list_info
// Size: 0x66
struct rdlg_list_info {
    char text[100]; // 0x0
    short id; // 0x64
};

class RGE_Dialog_List : public TListDialog {
public:
    int list_type;                           // 0x4AC
    short list_size;                         // 0x4B0
    short list_line;                         // 0x4B2
    rdlg_list_info* list_info;               // 0x4B4
    char** list_text;                        // 0x4B8

    virtual short get_list_id();                            // vt0[76]+0x130=0x47E8C0
    virtual int create_list();                              // vt0[78]+0x138=0x47E8F0
    virtual short get_cur_id();                             // vt0[79]+0x13C=0x47EB60
    RGE_Dialog_List(char* param_1);
    int setup(TScreenPanel* param_1, char* param_2, long param_3, int param_4, char* param_5);
    ~RGE_Dialog_List();
    int create_object_list();
    void sort_list();
    void calc_list_line();
};

static_assert(sizeof(RGE_Dialog_List) == 0x4BC, "RGE_Dialog_List Size Mismatch");

