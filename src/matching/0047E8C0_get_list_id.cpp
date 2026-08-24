#ifndef RDLG_LST_TU_CONTEXT
struct RGE_Dialog_List_Info {
    char gap_00[0x64];
    short id;
};

class RGE_Dialog_List {
public:
    char gap_00[0x4A0];
    short selected_index;
    char gap_4A2[0x0E];
    RGE_Dialog_List_Info* list_info;

    virtual short get_list_id(void);
};
#endif

short RGE_Dialog_List::get_list_id(void) {
    short index = this->selected_index;

    if (index == -1) {
        return index;
    }
    return this->list_info[index].id;
}
