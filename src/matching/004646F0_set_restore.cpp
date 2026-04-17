class TPanel {
public:
    char gap_00[0xF3];
    unsigned char need_restore;
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

    void set_restore(void);
};

void TPanelSystem::set_restore(void) {
    PanelNode* node;

    node = panelListValue->next_node;
    if (node != panelListValue) {
        do {
            if (node->panel != 0) {
                node->panel->need_restore = 1;
            }
            node = node->next_node;
        } while (node != panelListValue);
    }
}
