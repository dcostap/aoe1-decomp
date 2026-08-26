// Pnl_drop.cpp target: TDropDownPanel::action
// natural button/list action forwarding; set_text is vtable slot 0xE8 and parent action notification is slot 0xB4.

#ifndef PNL_DROP_CONTEXT
class TPanel {
public:
    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0xB0];

    long action(TPanel* panel, long action, unsigned long param3, unsigned long param4);
};

class TParentPanel : public TPanel {
public:
    virtual long notify_action(TPanel* panel, long action, unsigned long param3, unsigned long param4);
};

class TTextPanel {
public:
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
#endif

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
