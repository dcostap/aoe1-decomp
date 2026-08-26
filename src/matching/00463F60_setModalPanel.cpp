#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:

    char gap_04[0x38];
    TPanel* curr_child;
    TPanel* parent_panel;
    char gap_44[0x30];
    int tab_stop;

    void setPreviousModalPanel(TPanel* panel);
    void set_curr_child(TPanel* panel);
};

class TPanelSystem {
public:
    char gap_00[0x08];
    TPanel* modalPanelValue;
    TPanel* currentPanelValue;
    char gap_10[0x08];
    void* field_18;

    void setModalPanel(TPanel* panel);
};

#endif
void TPanelSystem::setModalPanel(TPanel* panel) {
    // BINARY NOTE: Panel.cpp stores the saved child at TPanelSystem +0x18.
    // The modal gate reads the panel word at +0x74.
    if (modalPanelValue != 0 && panel != 0) {
        panel->setPreviousModalPanel(modalPanelValue);
    }
    if (modalPanelValue == 0) {
        TPanel* previous = (TPanel*)field_18;
        if (previous != 0 && previous->parent_panel != 0) {
            previous->parent_panel->set_curr_child(previous);
        }
    } else if (modalPanelValue->tab_stop == 0 && modalPanelValue->parent_panel != 0) {
        modalPanelValue->parent_panel->set_curr_child((TPanel*)field_18);
    }
    field_18 = 0;
    modalPanelValue = panel;
    if (panel != 0 && panel != currentPanelValue) {
        TPanel* parent;

        parent = panel->parent_panel;
        if (parent != 0) {
            field_18 = (void*)parent->curr_child;
            parent->set_curr_child(panel);
            return;
        }
        field_18 = 0;
        panel->set_focus(1);
    }
}
