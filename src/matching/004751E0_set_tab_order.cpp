class TPanel {
public:
    virtual int vf00(void);
    virtual int vf04(void);
    virtual int vf08(void);
    virtual int vf0C(void);
    virtual int vf10(void);
    virtual int vf14(void);
    virtual int vf18(void);
    virtual int vf1C(void);
    virtual int vf20(void);
    virtual int vf24(void);
    virtual int vf28(void);
    virtual int vf2C(void);
    virtual int vf30(void);
    virtual int vf34(void);
    virtual int vf38(void);
    virtual int vf3C(void);
    virtual int vf40(void);
    virtual int vf44(void);
    virtual int vf48(void);
    virtual int vf4C(void);
    virtual int vf50(void);
    virtual int vf54(void);
    virtual int vf58(void);
    virtual int vf5C(void);
    virtual int vf60(void);
    virtual int vf64(void);
    virtual int vf68(void);
    virtual int vf6C(void);
    virtual int vf70(void);
    virtual int vf74(void);
    virtual int vf78(void);
    virtual int vf7C(void);
    virtual int vf80(void);
    virtual int vf84(void);
    virtual int vf88(void);
    virtual int vf8C(void);
    virtual int vf90(void);
    virtual int vf94(void);
    virtual int vf98(void);
    virtual int vf9C(void);
    virtual int vfA0(void);
    virtual int vfA4(void);
    virtual int vfA8(void);
    virtual int vfAC(void);
    virtual int vfB0(void);
    virtual int vfB4(void);
    virtual int vfB8(void);
    virtual int vfBC(void);
    virtual int vfC0(void);
    virtual void refresh_values(int a, int b);

    virtual void set_tab_order(TPanel* a, TPanel* b);
};

class TDropDownPanel : public TPanel {
public:
    char gap_04[0xF0];
    TPanel* val_panel;

    virtual void set_tab_order(TPanel* a, TPanel* b);
};

void TDropDownPanel::set_tab_order(TPanel* a, TPanel* b) {
    TPanel::set_tab_order(a, b);
    if (this->val_panel != 0) {
        this->val_panel->refresh_values(0, 0);
    }
}
