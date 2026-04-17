extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class TPanel {
public:
    char* panelName(void);
    void setPreviousPanel(TPanel* panel);
};

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanelSystem {
public:
    char gap_00[0x10];
    PanelNode* panelListValue;
    int numberActivePanelsValue;

    PanelNode* findPanelNode(char* name);
    void setCurrentPanel(TPanel* panel, int mode);
    int addPanel(TPanel* panel, int make_current, int mode);
};

int TPanelSystem::addPanel(TPanel* panel, int make_current, int mode) {
    PanelNode* node;

    node = findPanelNode(panel->panelName());
    if (node == 0) {
        node = (PanelNode*)calloc(1, 0x0C);
        if (node == 0) {
            return 0;
        }
        node->panel = panel;
        panel->setPreviousPanel(0);
        node->prev_node = panelListValue->prev_node;
        node->next_node = panelListValue;
        panelListValue->prev_node = node;
        node->prev_node->next_node = node;
        numberActivePanelsValue = numberActivePanelsValue + 1;
    }
    if (make_current != 0) {
        setCurrentPanel(panel, mode);
    }
    return 1;
}
