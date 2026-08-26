#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    char gap_00[0x60];
    void* tab_prev_panel;
    void* tab_next_panel;
    char gap_68[0x0C];
    int tab_stop;

    void set_tab_order(void* param1, void* param2);
};

#endif
void TPanel::set_tab_order(TPanel* param1, TPanel* param2) {
    tab_prev_panel = param1;
    tab_next_panel = param2;
    tab_stop = 1;
}
