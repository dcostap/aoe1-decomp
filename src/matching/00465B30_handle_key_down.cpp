class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual long vf58(long a1, short a2, int a3, int a4, int a5);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual long vfAC(long a1, short a2, int a3, int a4, int a5);

    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0x18];
    PanelNode* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    char gap_68[0x0C];
    int tab_stop;
    int have_focus;

    void set_curr_child(TPanel* child);
    long handle_key_down(long key, short ch, int a3, int a4, int a5);
};

long TPanel::handle_key_down(long key, short ch, int a3, int a4, int a5) {
    PanelNode* node;
    long result;
    TPanel* target;

    if (have_focus == 0) {
        return 0;
    }

    node = last_child_node;
    while (node != 0) {
        result = node->panel->vf58(key, ch, a3, a4, a5);
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }

    result = vfAC(key, ch, a3, a4, a5);
    if (result != 0) {
        return result;
    }

    if (a3 == 0 && a4 == 0 && key == 9 && tab_stop != 0 && parent_panel != 0) {
        if (a5 != 0) {
            target = tab_prev_panel;
        } else {
            target = tab_next_panel;
        }
        if (target != 0) {
            parent_panel->set_curr_child(target);
            return 1;
        }
    }

    return 0;
}
