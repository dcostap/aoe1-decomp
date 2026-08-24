#ifndef PNL_DROP_CONTEXT
class TTextPanel {
public:
    int insert_line(long param_1, long param_2, long param_3);
};
class TDropDownPanel {
public:
    virtual void dummy_vf();
    char gap_04[0xF8];
    TTextPanel* list_panel; // 0xFC

    int insert_line(long param_1, long param_2, long param_3);
};
#endif

int TDropDownPanel::insert_line(long param_1, long param_2, long param_3) {
    if (this->list_panel) {
        return this->list_panel->insert_line(param_1, param_2, param_3);
    }
    return 0;
}
