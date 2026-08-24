extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" __declspec(dllimport) unsigned long __stdcall GetSysColor(int index);
#ifndef AOE1_PANEL_CONTEXT_H

struct PanelNode {
    void* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanelSystem {
public:
    char gap_00[0x10];
    PanelNode* panelListValue;
    char gap_14[0xAB8];
    int saved_colors;
    unsigned long save_back_color;
    unsigned long save_text_color;

    int setup(void);
};

#endif
int TPanelSystem::setup(void) {
    panelListValue = (PanelNode*)calloc(1, 0x0C);
    if (panelListValue == 0) {
        return 0;
    }
    panelListValue->panel = 0;
    panelListValue->prev_node = panelListValue;
    panelListValue->next_node = panelListValue;
    save_back_color = GetSysColor(5);
    save_text_color = GetSysColor(8);
    saved_colors = 1;
    return 1;
}
