extern "C" void __cdecl free(void* block);

class TPanel {
public:
    virtual void* scalar_deleting_destructor(unsigned int flags);
};

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
    if (field_00 == node->panel) {
        field_00 = 0;
    }
    if (field_04 == node->panel) {
        field_04 = 0;
    }
    if (field_08 == node->panel) {
        field_08 = 0;
    }
    node->prev_node->next_node = node->next_node;
    node->next_node->prev_node = node->prev_node;
    if (node->panel != 0) {
        node->panel->scalar_deleting_destructor(1);
    }
    free(node);
    return 1;
}
