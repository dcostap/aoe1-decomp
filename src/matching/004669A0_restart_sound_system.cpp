#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode;

class TPanel {
public:
    virtual int restart_sound_system(void);

    char gap_04[0x54];
    PanelNode* first_child_node;
};

struct PanelNode {
    TPanel* panel;
    char gap_04[0x04];
    PanelNode* next_node;
};

#endif
int TPanel::restart_sound_system(void) {
    PanelNode* node;
    int ok;

    node = first_child_node;
    ok = 1;
    while (node != 0) {
        if (node->panel->restart_sound_system() == 0) {
            ok = 0;
        }
        node = node->next_node;
    }
    return ok;
}
