extern "C" __declspec(dllimport) int __stdcall UpdateWindow(void* hwnd);
extern void* AppWnd;

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:

    void setPreviousPanel(TPanel* panel);
};

class TPanelSystem {
public:
    char gap_00[0x0C];
    TPanel* currentPanelValue;

    void setCurrentPanelModal(void);
    void setCurrentPanel(TPanel* panel, int mode);
};

#endif
void TPanelSystem::setCurrentPanel(TPanel* panel, int mode) {
    panel->setPreviousPanel(currentPanelValue);
    if (currentPanelValue != 0) {
        currentPanelValue->set_focus(0);
    }
    currentPanelValue = panel;
    panel->set_focus(1);
    currentPanelValue->set_redraw(TPanel::RedrawImmediate);
    UpdateWindow(AppWnd);
    if (mode != 0) {
        setCurrentPanelModal();
    }
}
