#ifndef AOE1_PANEL_CONTEXT_H
class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:
    char gap_00[0x3C];
    TPanel* curr_child;
    char gap_40[0x18];
    PanelNode* first_child_node;
    PanelNode* last_child_node;

    void remove_panel_node(PanelNode* node);
};

#endif
void TPanel::remove_panel_node(PanelNode* node) {
    if (node == first_child_node) {
        first_child_node = node->next_node;
    }
    if (node == last_child_node) {
        last_child_node = node->prev_node;
    }
    if (node->prev_node != 0) {
        node->prev_node->next_node = node->next_node;
    }
    if (node->next_node != 0) {
        node->next_node->prev_node = node->prev_node;
    }
    node->prev_node = 0;
    node->next_node = 0;
    if (curr_child == node->panel) {
        curr_child = 0;
    }
}
