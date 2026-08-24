#ifndef PNL_DROP_CONTEXT
class TTextPanel {
public:
    int append_line(char* param_1, long param_2);
};
class TDropDownPanel {
public:
    virtual void dummy_vf();
    char gap_04[0xF8];
    TTextPanel* list_panel; // 0xFC

    int append_line(char* param_1, long param_2);
};
#endif

int TDropDownPanel::append_line(char* param_1, long param_2) {
    if (this->list_panel) {
        return this->list_panel->append_line(param_1, param_2);
    }
    return 0;
}
