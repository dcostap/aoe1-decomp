#ifndef AOE1_TDLG_LST_H
#define AOE1_TDLG_LST_H

// RGE_Dialog_List and its panel hierarchy belong to their canonical modules.
#include "rdlg_lst.h"

class TRIBE_Dialog_List : public RGE_Dialog_List {
public:
    TRIBE_Dialog_List(char*);
    virtual ~TRIBE_Dialog_List();

protected:
    virtual int create_list();
    int create_build_list();
    int create_train_list();
    int create_research_list();
    virtual short get_cur_id();
};

typedef char tdlg_lst_dialog_size_check[
    (sizeof(TRIBE_Dialog_List) == 0x4BC) ? 1 : -1];

#endif
