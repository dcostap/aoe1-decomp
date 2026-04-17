extern "C" void __cdecl free(void* block);

struct PanelNode {
    void* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanelSystem {
public:
    char gap_00[0x14];
    int numberActivePanelsValue;

    PanelNode* findPanelNode(char* name);
    int removePanel(char* name);
};

int TPanelSystem::removePanel(char* name) {
    PanelNode* node;

    if (name == 0) {
        return 0;
    }
    node = findPanelNode(name);
    if (node == 0) {
        return 0;
    }
    numberActivePanelsValue = numberActivePanelsValue - 1;
    node->prev_node->next_node = node->next_node;
    node->next_node->prev_node = node->prev_node;
    free(node);
    return 1;
}
