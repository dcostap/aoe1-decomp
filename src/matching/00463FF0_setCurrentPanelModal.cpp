class TPanel {
public:
    void setPreviousModalPanel(TPanel* panel);
};

class TPanelSystem {
public:
    char gap_00[0x08];
    TPanel* modalPanelValue;
    TPanel* currentPanelValue;

    void setCurrentPanelModal(void);
};

void TPanelSystem::setCurrentPanelModal(void) {
    TPanel* modal;

    modal = modalPanelValue;
    if (modal != 0 && modal != currentPanelValue) {
        currentPanelValue->setPreviousModalPanel(modal);
    }
    modalPanelValue = currentPanelValue;
}
