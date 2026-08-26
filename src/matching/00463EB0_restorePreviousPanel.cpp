extern "C" __declspec(dllimport) int __stdcall UpdateWindow(void* hwnd);
extern void* AppWnd;

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:

    TPanel* previousPanel(void);
    void setPreviousPanel(TPanel* panel);
    char* panelName(void);
};

class TPanelSystem {
public:
    char gap_00[0x0C];
    TPanel* currentPanelValue;

    int destroyPanel(char* name);
    int restorePreviousPanel(int destroy_current);
};

#endif
int TPanelSystem::restorePreviousPanel(int destroy_current) {
    TPanel* previous;
    TPanel* current;

    if (currentPanelValue == 0) {
        return 0;
    }
    previous = currentPanelValue->previousPanel();
    if (previous == 0) {
        return 0;
    }
    current = currentPanelValue;
    if (destroy_current == 0) {
        previous->setPreviousPanel(current);
    } else {
        if (previous->previousPanel() == current) {
            previous->setPreviousPanel(0);
        }
        destroyPanel(current->panelName());
    }
    currentPanelValue = previous;
    previous->set_focus(1);
    currentPanelValue->set_redraw(TPanel::RedrawImmediate);
    UpdateWindow(AppWnd);
    return 1;
}
