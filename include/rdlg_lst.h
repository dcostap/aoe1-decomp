#ifndef AOE1_RDLG_LST_H
#define AOE1_RDLG_LST_H

// This header owns RGE_Dialog_List and its list record.
#include "dlg_list.h"

class TScreenPanel;

struct rdlg_list_info {
    char text[100];
    short id;
};

typedef char rdlg_list_info_size_check[
    (sizeof(rdlg_list_info) == 0x66) ? 1 : -1];

int __cdecl rdlg_list_compare(const void*, const void*);

class RGE_Dialog_List : public TListDialog {
public:
    RGE_Dialog_List(char*);
    virtual ~RGE_Dialog_List();
    virtual short get_list_id();
    int setup(TScreenPanel*, char*, long, int, char*);

    int list_type;
    short list_size;
    short list_line;
    rdlg_list_info* list_info;
    char** list_text;

protected:
    virtual int create_list();
    int create_object_list();
    void sort_list();
    void calc_list_line();
    virtual short get_cur_id();
};

typedef char rdlg_dialog_list_size_check[
    (sizeof(RGE_Dialog_List) == 0x4BC) ? 1 : -1];

#endif
