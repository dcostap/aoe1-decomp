#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode;

class TPanel {
public:
    virtual void stop_sound_system(void);
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

    void stop_sound_system(void);
};

#endif
void TPanelSystem::stop_sound_system(void) {
    PanelNode* node;

    node = panelListValue->next_node;
    while (node != 0 && node != panelListValue) {
        if (node->panel != 0) {
            node->panel->stop_sound_system();
        }
        node = node->next_node;
    }
}
