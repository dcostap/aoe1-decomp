class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:
    char gap_00[0x58];
    PanelNode* first_child_node;
    PanelNode* last_child_node;

    void add_panel_node(PanelNode* node, PanelNode* sibling, int after);
};

void TPanel::add_panel_node(PanelNode* node, PanelNode* sibling, int after) {
    if (sibling == 0) {
        sibling = first_child_node;
        if (sibling == 0) {
            node->prev_node = sibling;
            node->next_node = sibling;
            goto done;
        }
        while (sibling->next_node != 0) {
            sibling = sibling->next_node;
        }
        sibling->next_node = node;
        node->prev_node = sibling;
        node->next_node = 0;
        goto done;
    }
    if (after != 0) {
        node->prev_node = sibling;
        node->next_node = sibling->next_node;
        sibling->next_node = node;
        if (node->next_node != 0) {
            node->next_node->prev_node = node;
        }
    } else {
        node->prev_node = sibling->prev_node;
        node->next_node = sibling;
        sibling->prev_node = node;
        if (node->prev_node != 0) {
            node->prev_node->next_node = node;
        }
    }
done:
    if (node->prev_node == 0) {
        first_child_node = node;
    }
    if (node->next_node == 0) {
        last_child_node = node;
    }
}
