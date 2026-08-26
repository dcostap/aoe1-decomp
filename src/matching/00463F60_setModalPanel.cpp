#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:

    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0x30];
    int have_focus;

    void setPreviousModalPanel(TPanel* panel);
    void set_curr_child(TPanel* panel);
};

class TPanelSystem {
public:
    char gap_00[0x08];
    TPanel* modalPanelValue;
    TPanel* currentPanelValue;
    char gap_10[0x08];
    TPanel* prevCurrentChildValue;

    void setModalPanel(TPanel* panel);
};

#endif
void TPanelSystem::setModalPanel(TPanel* panel) {
    if (modalPanelValue != 0 && panel != 0) {
        panel->setPreviousModalPanel(modalPanelValue);
    }
    if (modalPanelValue == 0) {
        if (prevCurrentChildValue != 0 && prevCurrentChildValue->parent_panel != 0) {
            prevCurrentChildValue->parent_panel->set_curr_child(prevCurrentChildValue);
        }
    } else if (modalPanelValue->have_focus == 0 && modalPanelValue->parent_panel != 0) {
        modalPanelValue->parent_panel->set_curr_child(prevCurrentChildValue);
    }
    prevCurrentChildValue = 0;
    modalPanelValue = panel;
    if (panel != 0 && panel != currentPanelValue) {
        TPanel* parent;

        parent = panel->parent_panel;
        if (parent != 0) {
            prevCurrentChildValue = *(TPanel**)((char*)parent + 0x3C);
            parent->set_curr_child(panel);
            return;
        }
        prevCurrentChildValue = 0;
        panel->set_focus(1);
    }
}
