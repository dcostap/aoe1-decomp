#ifndef AOE1_PANEL_CONTEXT_H
class PanelNode;
class TPanel;

class TPanelSystem {
public:
    TPanel* mouseOwnerValue;
    TPanel* keyboardOwnerValue;
    TPanel* modalPanelValue;
    TPanel* currentPanelValue;
    PanelNode* panelListValue;
    void* field_14;
    void* field_18;
    void* palette[10];
    char palette_file[10][260];
    int palette_use_count[10];
    int field_A94[10];
    int prevCurrentChildValue;
    int ImeEnabled;
    int field_AC4;
    int InputEnabled;
    int saved_colors;
    unsigned long save_back_color;
    unsigned long save_text_color;

    int setup(void);
    TPanelSystem(void);
};

#endif
TPanelSystem::TPanelSystem(void) {
    int* counts;
    char (*files)[260];
    int i;

    ImeEnabled = 1;
    InputEnabled = 1;
    mouseOwnerValue = 0;
    keyboardOwnerValue = 0;
    modalPanelValue = 0;
    currentPanelValue = 0;
    panelListValue = 0;
    field_14 = 0;
    field_18 = 0;
    prevCurrentChildValue = 0;
    field_AC4 = 0;
    saved_colors = 0;
    counts = palette_use_count;
    files = palette_file;
    i = 10;
    do {
        counts[-660] = 0;
        (*files)[0] = 0;
        *counts = 0;
        counts[10] = 0;
        counts++;
        files++;
        i--;
    } while (i != 0);
    setup();
}
