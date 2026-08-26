#ifndef AOE1_PANEL_CONTEXT_H
class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:

    char gap_04[0x58];
    PanelNode* last_child_node;
    char gap_60[0x18];
    int have_focus;

    long handle_char(long key, short ch);
};

#endif
long TPanel::handle_char(long key, short ch) {
    PanelNode* node;
    long result;

    if (have_focus == 0) {
        return 0;
    }
    node = last_child_node;
    while (node != 0) {
        result = node->panel->handle_char(key, ch);
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }
    return char_action(key, ch);
}
