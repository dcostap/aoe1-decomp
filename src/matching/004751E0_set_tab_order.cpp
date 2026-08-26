#ifndef PNL_DROP_CONTEXT
class TPanel {
public:
    virtual void set_tab_order(TPanel* a, TPanel* b);
};

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
        // BINARY NOTE: VC5 places this overload at the shipped +0xC4 slot.
        this->val_panel->set_tab_order((TPanel**)0, (short)0);
    }
}
