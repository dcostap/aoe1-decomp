#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode;

class TPanel {
public:
    virtual void stop_sound_system(void);

    char gap_04[0x54];
    PanelNode* first_child_node;
};

struct PanelNode {
    TPanel* panel;
    char gap_04[0x04];
    PanelNode* next_node;
};

#endif
void TPanel::stop_sound_system(void) {
    PanelNode* node;

    node = first_child_node;
    while (node != 0) {
        node->panel->stop_sound_system();
        node = node->next_node;
    }
}
