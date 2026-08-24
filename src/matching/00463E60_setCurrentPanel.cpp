 #ifndef AOE1_PANEL_CONTEXT_H
#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode;

class TPanel {
public:
    void release_mouse(void);
};
#endif

#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode {
    TPanel* panel;
};
#endif

#ifndef AOE1_PANEL_CONTEXT_H
class TPanelSystem {
public:
    TPanel* mouseOwnerValue;
    TPanel* keyboardOwnerValue;
    TPanel* modalPanelValue;

    PanelNode* findPanelNode(char* name);
    void setCurrentPanel(TPanel* panel, int mode);
    int setCurrentPanel(char* name, int mode);
};
#endif

#endif
int TPanelSystem::setCurrentPanel(char* name, int mode) {
    PanelNode* node;

    node = findPanelNode(name);
    if (node != 0) {
        if (mouseOwnerValue != 0) {
            mouseOwnerValue->release_mouse();
        }
        modalPanelValue = 0;
        keyboardOwnerValue = 0;
        setCurrentPanel(node->panel, mode);
        return 1;
    }
    return 0;
}
