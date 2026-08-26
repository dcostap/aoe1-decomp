#ifndef PNL_DROP_CONTEXT
#ifndef PNL_DROP_CONTEXT
class TPanel {
public:
    virtual void refresh_values(int a, int b);

    virtual void set_tab_order(TPanel* a, TPanel* b);
};
#endif

class TDropDownPanel : public TPanel {
public:
    char gap_04[0xF0];
    TPanel* val_panel;

    virtual void set_tab_order(TPanel* a, TPanel* b);
};
#endif

void TDropDownPanel::set_tab_order(TPanel* a, TPanel* b) {
    TPanel::set_tab_order(a, b);
    if (this->val_panel != 0) {
        this->val_panel->refresh_values(0, 0);
    }
}
