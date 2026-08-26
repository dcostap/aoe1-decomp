#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode;

class TPanel {
public:
    virtual void handle_reactivate(void);

    char gap_04[0x54];
    PanelNode* first_child_node;
};

struct PanelNode {
    TPanel* panel;
    char gap_04[0x04];
    PanelNode* next_node;
};

#endif
void TPanel::handle_reactivate(void) {
    PanelNode* node;

    node = first_child_node;
    while (node != 0) {
        node->panel->handle_reactivate();
        node = node->next_node;
    }
}
