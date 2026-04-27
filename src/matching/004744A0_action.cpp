// Pnl_drop.cpp target: TDropDownPanel::action
// natural button/list action forwarding; set_text is vtable slot 0xE8 and parent action notification is slot 0xB4.

class TPanel {
public:
    virtual void vf00();
    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0xB0];

    long action(TPanel* panel, long action, unsigned long param3, unsigned long param4);
};

class TParentPanel : public TPanel {
public:
    virtual void pv04(); virtual void pv08(); virtual void pv0C();
    virtual void pv10(); virtual void pv14(); virtual void pv18(); virtual void pv1C();
    virtual void pv20(); virtual void pv24(); virtual void pv28(); virtual void pv2C();
    virtual void pv30(); virtual void pv34(); virtual void pv38(); virtual void pv3C();
    virtual void pv40(); virtual void pv44(); virtual void pv48(); virtual void pv4C();
    virtual void pv50(); virtual void pv54(); virtual void pv58(); virtual void pv5C();
    virtual void pv60(); virtual void pv64(); virtual void pv68(); virtual void pv6C();
    virtual void pv70(); virtual void pv74(); virtual void pv78(); virtual void pv7C();
    virtual void pv80(); virtual void pv84(); virtual void pv88(); virtual void pv8C();
    virtual void pv90(); virtual void pv94(); virtual void pv98(); virtual void pv9C();
    virtual void pvA0(); virtual void pvA4(); virtual void pvA8(); virtual void pvAC();
    virtual void pvB0();
    virtual long notify_action(TPanel* panel, long action, unsigned long param3, unsigned long param4);
};

class TTextPanel {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
    virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
    virtual void vfC0(); virtual void vfC4(); virtual void vfC8(); virtual void vfCC();
    virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
    virtual void vfE0(); virtual void vfE4();
    virtual void set_text(char* text);

    char* get_text(long line);
};

class TDropDownPanel : public TPanel {
public:
    TTextPanel* val_panel;
    TPanel* btn_panel;
    TTextPanel* list_panel;
    TPanel* scbar_panel;
    int mode;
    short val_num;

    virtual long action(TPanel* panel, long action, unsigned long param3, unsigned long param4);
    void set_mode(int mode);
};

long TDropDownPanel::action(TPanel* panel, long action_code, unsigned long line, unsigned long param4) {
    if (panel == this->btn_panel) {
        if (action_code == 2) {
            if (this->mode == 1) {
                this->set_mode(action_code);
            }
        }
    } else if (panel == (TPanel*)this->list_panel) {
        if (action_code == 3 || action_code == 2) {
            this->val_num = (short)line;
            this->val_panel->set_text(this->list_panel->get_text((short)line));
            this->set_mode(1);
            if (this->parent_panel) {
                ((TParentPanel*)this->parent_panel)->notify_action(this, 0, 0, 0);
            }
        }
    }

    return TPanel::action(panel, action_code, line, param4);
}
