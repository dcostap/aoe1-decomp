class TPanel {
public:
    char* panelName(void);
};

struct PanelNode;

class TPanelSystem {
public:
    PanelNode* findPanelNode(char* name);
    int inSystem(TPanel* panel);
};

int TPanelSystem::inSystem(TPanel* panel) {
    if (panel != 0) {
        if (findPanelNode(panel->panelName()) != 0) {
            return 1;
        }
    }
    return 0;
}
