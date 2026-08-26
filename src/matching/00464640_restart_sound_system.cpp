#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode;

class TPanel {
public:
    virtual int restart_sound_system(void);
};

struct PanelNode {
    TPanel* panel;
    char gap_04[0x04];
    PanelNode* next_node;
};

class TPanelSystem {
public:
    char gap_00[0x10];
    PanelNode* panelListValue;

    int restart_sound_system(void);
};

#endif
int TPanelSystem::restart_sound_system(void) {
    PanelNode* node;
    int ok;

    ok = 1;
    node = panelListValue->next_node;
    while (node != 0 && node != panelListValue) {
        if (node->panel != 0 && node->panel->restart_sound_system() == 0) {
            ok = 0;
        }
        node = node->next_node;
    }
    return ok;
}
