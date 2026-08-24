extern "C" void __cdecl free(void* block);
#ifndef AOE1_PANEL_CONTEXT_H

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual void* scalar_deleting_destructor(unsigned int flags);
};
#endif

#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanelSystem {
public:
    TPanel* field_00;
    TPanel* field_04;
    TPanel* field_08;
    TPanel* currentPanelValue;
    PanelNode* panelListValue;
    int numberActivePanelsValue;

    PanelNode* findPanelNode(char* name);
    int destroyPanel(char* name);
};
#endif

#endif
int TPanelSystem::destroyPanel(char* name) {
    PanelNode* node;

    if (name == 0) {
        return 0;
    }
    node = findPanelNode(name);
    if (node == 0) {
        return 0;
    }
    numberActivePanelsValue = numberActivePanelsValue - 1;
    if (currentPanelValue == node->panel) {
        currentPanelValue = 0;
    }
    if (mouseOwnerValue == node->panel) {
        field_00 = 0;
    }
    if (keyboardOwnerValue == node->panel) {
        field_04 = 0;
    }
    if (modalPanelValue == node->panel) {
        field_08 = 0;
    }
    node->prev_node->next_node = node->next_node;
    node->next_node->prev_node = node->prev_node;
    if (node->panel != 0) {
        delete node->panel;
    }
    free(node);
    return 1;
}
