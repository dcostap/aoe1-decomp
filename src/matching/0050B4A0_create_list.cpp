// VA: 0050B4A0 TRIBE_Dialog_List::create_list
// tdlg_lst.cpp lines 33-46

#include "../../include/tdlg_lst_context.h"

int TRIBE_Dialog_List::create_list() {
    switch (this->list_type) {
    case 100:
        return this->create_build_list();
    case 101:
        return this->create_train_list();
    case 102:
        return this->create_research_list();
    default:
        return RGE_Dialog_List::create_list();
    }
}
