struct PanelNode;

class TPanelSystem {
public:
    PanelNode* findPanelNode(char* name);
    int inSystem(char* name);
};

int TPanelSystem::inSystem(char* name) {
    return findPanelNode(name) != 0;
}
