 #ifndef AOE1_PANEL_CONTEXT_H
#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode;

class TPanelSystem {
public:
    PanelNode* findPanelNode(char* name);
    int inSystem(char* name);
};
#endif

#endif
int TPanelSystem::inSystem(char* name) {
    return findPanelNode(name) != 0;
}
