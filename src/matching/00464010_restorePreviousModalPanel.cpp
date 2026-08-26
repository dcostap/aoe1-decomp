#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual void set_focus_state(int focus);

    TPanel* previousModalPanel(void);
};

class TPanelSystem {
public:
    char gap_00[0x08];
    TPanel* modalPanelValue;

    void setMouseOwner(TPanel* owner);
    void setKeyboardOwner(TPanel* owner);
    int restorePreviousModalPanel(void);
};

#endif
int TPanelSystem::restorePreviousModalPanel(void) {
    TPanel* panel;

    if (modalPanelValue == 0) {
        return 0;
    }
    panel = modalPanelValue->previousModalPanel();
    if (panel == 0) {
        return 0;
    }
    panel->set_focus(1);
    setMouseOwner(panel);
    setKeyboardOwner(panel);
    modalPanelValue = panel;
    return 1;
}
