struct PanelNode;
class TPanel;

class TPanelSystem {
public:
    PanelNode* findPanelNode(char* name);
    TPanel* panel(char* name);
};

struct PanelNode {
    TPanel* panel;
};

TPanel* TPanelSystem::panel(char* name) {
    PanelNode* node;

    node = findPanelNode(name);
    if (node != 0) {
        return node->panel;
    }
    return 0;
}
