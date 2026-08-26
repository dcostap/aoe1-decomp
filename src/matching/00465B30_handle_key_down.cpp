#ifndef AOE1_PANEL_CONTEXT_H
class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:

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

#endif
long TPanel::handle_key_down(long key, short ch, int a3, int a4, int a5) {
    PanelNode* node;
    long result;
    TPanel* target;

    if (have_focus == 0) {
        return 0;
    }

    node = last_child_node;
    while (node != 0) {
        result = node->panel->handle_key_down(key, ch, a3, a4, a5);
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }

    result = key_down_action(key, ch, a3, a4, a5);
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
